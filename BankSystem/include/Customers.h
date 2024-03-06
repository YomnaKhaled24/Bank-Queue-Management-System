#ifndef CUSTOMERS_H
#define CUSTOMERS_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

class Customers
{
    int custumer_number;
    int arrival_time_minutes;
    int priority;
    int service_time_minutes;
    int waiting_time_minutes;
    int finishing_time_minutes;
    int total_time;
    int teller_id;


    public:

        Customers() {}
        Customers(int custumer_number, int arrival_time_minutes ,int priority, int service_time_minutes)
        {
            this->custumer_number = custumer_number;
            this->arrival_time_minutes = arrival_time_minutes;
            this->priority = priority;
            this->service_time_minutes = service_time_minutes;

            this->waiting_time_minutes = 0 ;
            this->finishing_time_minutes = -1;
            this->total_time = -1;

            this->teller_id = -1;
        }



        void setWaitingTime(int time)
        {
            this->waiting_time_minutes = time ;
        }

        int getWaitingTime()
        {
            return waiting_time_minutes ;
        }

        void setFinishingTime(int time)
        {
            this->finishing_time_minutes = time ;
        }

        int getFinishingTime()
        {
            return finishing_time_minutes ;
        }

        void setTotalTime(int time)
        {
            this->total_time = time ;
        }

        void setTellerId(int id)
        {
            this->teller_id = id;
        }

        int getArrivalTime()
        {
            return arrival_time_minutes ;
        }

        int getServiceTime()
        {
            return service_time_minutes ;
        }


         bool operator<(const Customers& other) const
         {

            if (arrival_time_minutes != other.arrival_time_minutes)
            {
                return arrival_time_minutes > other.arrival_time_minutes;
            }
            else
            {
                return priority < other.priority;
            }

        }

        bool operator>(const Customers& other) const
        {
            return priority < other.priority;
        }

        static void DisplayHeader()
        {
             int columnWidth = 16  ;

             cout << setfill('-') << setw(columnWidth * 8 + 1) << "-" << "\n";
             cout << setfill(' ');

             cout << left << setw(columnWidth) << "| Customer Num"
                  << setw(columnWidth) << "| Arrival Time"
                  << setw(columnWidth) << "| Priority"
                  << setw(columnWidth) << "| Service Time"
                  << setw(columnWidth) << "| Teller Id"
                  << setw(columnWidth) << "| Waiting Time"
                  << setw(columnWidth) << "| Finishing Time"
                  << setw(columnWidth) << "| Total Time" << "|\n";


            cout << setfill('-') << setw(columnWidth * 8 + 1) << "-" << "\n";
            cout << setfill(' ');
        }
        void DisplayData()
        {

            int columnWidth = 16;

            cout << left << setw(columnWidth) << "| " + to_string(custumer_number)
                  << setw(columnWidth) << "| " + to_string(arrival_time_minutes)
                  << setw(columnWidth) << "| " + to_string(priority)
                  << setw(columnWidth) << "| " + to_string(service_time_minutes)
                  << setw(columnWidth) << "| " + to_string(teller_id)
                  << setw(columnWidth) << "| " + to_string(waiting_time_minutes)
                  << setw(columnWidth) << "| " + to_string(finishing_time_minutes)
                  << setw(columnWidth) << "| " + to_string(total_time) << "|\n";

            cout << setfill('-') << setw(columnWidth * 8 + 1) << "-" << "\n";
            cout << setfill(' ');
        }

    protected:

    private:
};

#endif // CUSTOMERS_H
