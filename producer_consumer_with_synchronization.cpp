// Paydreanne Hinton

#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <cstdlib>

using namespace std;

#define MAX 10
#define N 4

// Data structure to respresent a simplified Order
// that has an order number and an item number.
struct Order
{
    int order_num;
    int item_num;
};

Order new_orders[N];    // array of elements of type Order to be used as a shared buffer
int num_new_orders = 0; // count of number of new (i.e., unprocessed) orders
int order_num = 0;  // global variable used to generate unique order numbers

// TODO: Define and initialize necessary mutex and condition variables here

pthread_mutex_t data_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t console_mutex = PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t space_available = PTHREAD_COND_INITIALIZER;
pthread_cond_t order_available = PTHREAD_COND_INITIALIZER;

void* takeOrders(void* arg)
{
    int item;
    int index = 0;

    for (int i = 0; i < MAX; ++i) {
        pthread_mutex_lock(&data_mutex); // pthread locks shared data access

        while (num_new_orders == N) { 
            // will wait for buffer space to open up
            pthread_cond_wait(&space_available, &data_mutex);
        }

        pthread_mutex_lock(&console_mutex); // locks console access

        // Get user input
        cout << "Enter a menu item number between 1 and 50: ";
        cin >> item;

        // Print new order's details
        cout << "Got new order! Order number is " << order_num << " and item number: " << item << std::endl;

        pthread_mutex_unlock(&console_mutex); // unlocks console access

        new_orders[index].order_num = order_num; // new order number changes to current order number
        new_orders[index].item_num = item; // new order number's item number changes to current item
        ++num_new_orders; // number of new orders updates

        // Update order number
        ++order_num;

        // If the end of the new orders buffer is reached, wrap back around
        if (index == N - 1)
            index = 0;
        else
            ++index;

        pthread_cond_signal(&order_available); // pthread signals new orders
        pthread_mutex_unlock(&data_mutex); // pthread unlocks shared data access
    }

    pthread_exit(NULL);
}

void* processOrders(void* arg)
{
    int item;
    int index = 0;
    int o_num;

    for (int i = 0; i < MAX; ++i) {
        pthread_mutex_lock(&data_mutex); // locks shared data access

        while (num_new_orders == 0) {
            // will wait for buffer space to open up again
            pthread_cond_wait(&order_available, &data_mutex);
        }

        o_num = new_orders[index].order_num;
        item = new_orders[index].item_num;
        --num_new_orders;

        pthread_mutex_unlock(&data_mutex); // pthread unlocks the shared data access

        pthread_mutex_lock(&console_mutex); // locks console access

        // Print retrieved order's details
        cout << "Processing order number " << o_num << " with item number: " << item << std::endl;

        pthread_mutex_unlock(&console_mutex); // unlocks console access

        // Suspend self for 1 second
        sleep(1);

        // If the end of the new orders buffer is reached, wrap back around
        if (index == N - 1)
            index = 0;
        else
            ++index;

        pthread_cond_signal(&space_available); // signals that buffer space is open
    }

    pthread_exit(NULL);
}

int main()
{
    pthread_t id1, id2;
    pthread_create(&id1, NULL, processOrders, NULL);
    pthread_create(&id2, NULL, takeOrders, NULL);

    pthread_join(id1, NULL); // Wait

    // Print goodbye message
    cout << "Phew! Done with orders for today!" << endl;
    pthread_exit(NULL);
}

/*
1) https://www.ibm.com/docs/en/i/7.3?topic=ssw_ibm_i_73/apis/users_78.html
2) https://www.youtube.com/watch?v=eQOaaDA92SI&pp=ygUecHRocmVhZCB3YWl0IHN5bmNocm9uaXphdGlvbiBj
3) https://www.youtube.com/watch?v=nlHIuG3RQ0g&pp=ygUecHRocmVhZCB3YWl0IHN5bmNocm9uaXphdGlvbiBj
4) https://www.youtube.com/watch?v=GXXE42bkqQk&pp=ygUecHRocmVhZCB3YWl0IHN5bmNocm9uaXphdGlvbiBjv
*/
