#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

#include <Bank.h>
#include <Customers.h>
#include <Tellers.h>

using namespace std;


int main()
{

    Bank bank;

    bank.inputCustomers();

    bank.servicingCustomers();

    bank.DisplayAllCustomers();

    bank.TimeAnalysis();

        /*priority_queue<Customers, vector<Customers>, greater<Customers>> waiting_customers;

    waiting_customers.push(Customers(1,0,0,6));
    waiting_customers.push(Customers(2,0,0,6));
    waiting_customers.push(Customers(3,0,1,6));
    waiting_customers.push(Customers(4,0,0,6));
    waiting_customers.push(Customers(5,0,1,6));

    while (!waiting_customers.empty()) {
        Customers currentCustomer = waiting_customers.top();
        currentCustomer.DisplayData();
        waiting_customers.pop();
    }*/


/*
    int arr[6] = { 10, 2, 4, 8, 6, 9 };

    // defining priority queue
    priority_queue<int> pq;

    // printing array
    cout << "Array: ";
    for (auto i : arr) {
        cout << i << ' ';
    }
    cout << endl;
    // pushing array sequentially one by one
    for (int i = 0; i < 6; i++) {
        pq.push(arr[i]);
    }

    pq.push(11);
    // printing priority queue
    cout << "Priority Queue: ";
    while (!pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop();
    }*/




    //inputCustomers();

    /*cout << "Hello world!" << endl;

    Customers c1(1,5,0);
    Customers c2(2,10,1);

        vector<Customers> customerArray = {
        {1, 10, 2},
        {2, 15, 1},
        {3, 20, 3}
    };

    // Display header only once
    Customers::DisplayHeader();

    // Display each customer's information
    for ( auto& customer : customerArray) {
        customer.DisplayData();
    }
*/

/*
vector<Tellers> tellerArray = {
        {},
        {},
        {},
        {},
        {},
        {}

    };


for ( auto& teller : tellerArray) {
        cout<< teller.getTellerId()<< endl;
    }
*/
    return 0;
}
