#ifndef TELLERS_H
#define TELLERS_H


class Tellers
{
    static int counter_id;
    int teller_id;
    int teler_status;
    int services_time;
    int finish_customer_service_time;
    int customer_numbers;


    public:

        Tellers()
        {
            this->teller_id = counter_id;

            this->teler_status = 0;

            this->services_time = 0;

            this->finish_customer_service_time = 0;

            this->customer_numbers = 0;

            counter_id++;
        }

        int getTellerId()
        {
            return teller_id;
        }

        void setTellerStatus(int status)
        {
            this->teler_status = status;

        }

        int getTellerStatus()
        {
            return teler_status;
        }

        void setCustomerNumbers(int number)
        {
            this->customer_numbers = number;

        }

        int getCustomerNumbers()
        {
            return customer_numbers;
        }

        void setServicesTime(int time)
        {
            this->services_time = time;
        }

        int getServicesTime()
        {
            return services_time;
        }

        void setFinishCustomerServiceTime(int time)
        {
            this->finish_customer_service_time = time;
        }

        void checkStaus(int counter)
        {
            if (counter >= finish_customer_service_time)
            {
                this->teler_status = 0;

                this->finish_customer_service_time = 0;
            }
        }
    protected:

    private:
};

int Tellers::counter_id = 1;

#endif // TELLERS_H
