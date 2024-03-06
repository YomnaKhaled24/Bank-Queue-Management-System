#ifndef BANK_H
#define BANK_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <queue>
#include <list>

#include <Customers.h>
#include <Tellers.h>

using namespace std;

class Bank
{
    priority_queue<Customers> all_customers;

    list<Tellers> tellers{Tellers(),Tellers(),Tellers()};

    queue<Customers> finished_customers;

    priority_queue<Customers, vector<Customers>, greater<Customers>> waiting_customers;

    int counter_time = 0;


    public:
        Bank() {}

        void inputCustomers()
        {
            int cust_num, arrival_time, priority, service_time;

            ifstream Infile("testcase4.txt");

            if (!Infile.is_open()) {

                cerr << "Error opening the file.\n";
                return;
                }

            string header;
            getline(Infile, header);

            while(Infile >> cust_num >> arrival_time >> priority >> service_time)
            {
                all_customers.push(Customers(cust_num , arrival_time , priority , service_time));
                //cout << cust_num << "  "<< arrival_time << "  "<< priority <<"  "<< AssignServiceTime() << endl;
            }

            Infile.close();

        }

        void DisplayAllCustomers()
        {
            //priority_queue<Customers, vector<Customers>, greater<Customers>> tempQueue = waiting_customers;

            //priority_queue<Customers> tempQueue = all_customers;
             queue<Customers> tempQueue = finished_customers;


            Customers::DisplayHeader();

            while (!tempQueue.empty())
            {

                //Customers currentCustomer = tempQueue.top();
                Customers currentCustomer = tempQueue.front();


                currentCustomer.DisplayData();

                tempQueue.pop();
            }

        }

        void servicingCustomers()
        {
            int max_finishing_time = 0;


            while(!all_customers.empty() || !waiting_customers.empty())
            {

            //cout << "all_customers size: " << all_customers.size() << endl;
            //cout << "waiting_customers size: " << waiting_customers.size() << endl;

                Customers currentCustomer ;
                Customers nextWaitingCustomer ;

                int waiting_status = 0;

                if( !waiting_customers.empty())
                {
                    nextWaitingCustomer = all_customers.top();
                    if(!all_customers.empty() && nextWaitingCustomer.getArrivalTime() <= counter_time)
                    {
                        //nextWaitingCustomer = all_customers.top();
                        waiting_customers.push(nextWaitingCustomer);
                        all_customers.pop();
                    }

                    currentCustomer = waiting_customers.top();
                    waiting_status = 1;

                }
                else
                {
                    currentCustomer = all_customers.top();
                }

                int served = 0;


                /*if(currentCustomer.getArrivalTime() > counter_time)
                {
                    continue;
                }*/

                if( currentCustomer.getArrivalTime() <= counter_time )
                {


                    for ( Tellers& teller : tellers)
                    {
                        teller.checkStaus(counter_time);

                        if(teller.getTellerStatus() == 0)
                        {
                            currentCustomer.setTellerId(teller.getTellerId());
                            currentCustomer.setWaitingTime(counter_time - currentCustomer.getArrivalTime());
                            currentCustomer.setFinishingTime(counter_time + currentCustomer.getServiceTime());
                            currentCustomer.setTotalTime((currentCustomer.getFinishingTime()) - (currentCustomer.getArrivalTime()));


                            teller.setTellerStatus(1);
                            teller.setServicesTime((teller.getServicesTime()) + (currentCustomer.getServiceTime()));
                            teller.setFinishCustomerServiceTime(currentCustomer.getFinishingTime());
                            teller.setCustomerNumbers(teller.getCustomerNumbers() + 1);


                            served = 1;


                            //currentCustomer.DisplayData();

                        }
                        if(served == 1)
                        {
                            break;
                        }

                    }

                  if(served == 1)
                  {

                    if(currentCustomer.getFinishingTime() > max_finishing_time)
                    {
                        max_finishing_time = currentCustomer.getFinishingTime();
                    }


                    finished_customers.push(currentCustomer);
                    //cout<<"finish add "<<finished_customers.size()<<endl;

                    if(waiting_status == 1)
                    {
                        waiting_customers.pop();
                        //cout<<"waiting remove "<<waiting_customers.size()<<endl;
                    }
                    else
                    {
                        all_customers.pop();
                        //cout<<"all remove "<<all_customers.size()<<endl;
                    }

                }
                else
                {
                    if(waiting_status == 0)
                    {
                        waiting_customers.push(currentCustomer);

                        //cout<<"waiting add "<<waiting_customers.size()<<endl;

                        //DisplayAllCustomers();

                        all_customers.pop();
                        //cout<<"all remove "<<all_customers.size()<<endl;
                    }
                }


                }

 //cout<<"//////////////////////////////////////////////////////"<<endl;
                counter_time++;
            }

            //Customers& lastCustomer = finished_customers.back();

            if(max_finishing_time != counter_time)
            {
                counter_time = max_finishing_time;
            }

            //cout << counter_time<<endl;
        }

        void TimeAnalysis()
        {
            cout<<endl<<"Statistical Analysis : " << endl << endl;

            queue<Customers> tempQueue = finished_customers;


            int all_waiting_time=0;

            int all_services_time=0;

           while (!tempQueue.empty())
            {
                Customers& currentCustomer = tempQueue.front();

                all_waiting_time += currentCustomer.getWaitingTime();

                all_services_time += currentCustomer.getServiceTime();

                tempQueue.pop();
            }


            double average_waiting_time = static_cast<double>(all_waiting_time) / finished_customers.size() ;
            double average_services_time = static_cast<double>(all_services_time) / finished_customers.size() ;

            cout<< "Average Waiting Time is " << fixed << setprecision(2) << average_waiting_time << endl << endl;
            cout<< "Average Services Time is " << fixed << setprecision(2) << average_services_time << endl;



            for ( Tellers& teller : tellers)
            {
                cout<<endl;

                double Utilization_Rate = (static_cast<double>(teller.getServicesTime()) / counter_time )* 100.0;

                //cout << counter_time << endl;
                cout<<"Teller " << teller.getTellerId() << " served " << teller.getCustomerNumbers() <<
                " customers and worked for " << teller.getServicesTime() << " units of time " <<
                ",So the utilization rate is "<< fixed << setprecision(2) << Utilization_Rate << "%." <<endl;

            }
        }


    protected:

    private:

       /* int AssignServiceTime()
        {
            srand(time(0));

            return ((rand() % 20) + 1);
        }*/
};

#endif // BANK_H
