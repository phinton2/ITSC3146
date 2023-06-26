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

pthread_mutex_t data_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t console_mutex = PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t space_available = PTHREAD_COND_INITIALIZER;
pthread_cond_t order_available = PTHREAD_COND_INITIALIZER;

void* takeOrders(void* arg)
{
    int item;
    int index = 0;

    for (int i = 0; i < MAX; ++i) {
        pthread_mutex_lock(&data_mutex); // Lock shared data access

        while (num_new_orders == N) {
            // Wait for space in the buffer
            pthread_cond_wait(&space_available, &data_mutex);
        }

        pthread_mutex_lock(&console_mutex); // Lock console access

        // Get user input
        cout << "Enter a menu item number between 1 and 50: ";
        cin >> item;

        // Print new order's details
        cout << "Got new order! Order number is " << order_num << " and item number: " << item << std::endl;

        pthread_mutex_unlock(&console_mutex); // Unlock console access

        // Put new order into new orders buffer and update the number of new orders
        new_orders[index].order_num = order_num;
        new_orders[index].item_num = item;
        ++num_new_orders;

        // Update order number
        ++order_num;

        // If the end of the new orders buffer is reached, wrap back around
        if (index == N - 1)
            index = 0;
        else
            ++index;

        pthread_cond_signal(&order_available); // Signal that new orders are available
        pthread_mutex_unlock(&data_mutex); // Unlock shared data access
    }

    pthread_exit(NULL);
}

void* processOrders(void* arg)
{
    int item;
    int index = 0;
    int o_num;

    for (int i = 0; i < MAX; ++i) {
        pthread_mutex_lock(&data_mutex); // Lock shared data access

        while (num_new_orders == 0) {
            // Wait for new orders to be available
            pthread_cond_wait(&order_available, &data_mutex);
        }

        o_num = new_orders[index].order_num;
        item = new_orders[index].item_num;
        --num_new_orders;

        pthread_mutex_unlock(&data_mutex); // Unlock shared data access

        pthread_mutex_lock(&console_mutex); // Lock console access

        // Print retrieved order's details
        cout << "Processing order number " << o_num << " with item number: " << item << std::endl;

        pthread_mutex_unlock(&console_mutex); // Unlock console access

        // Suspend self for 1 second
        sleep(1);

        // If the end of the new orders buffer is reached, wrap back around
        if (index == N - 1)
            index = 0;
        else
            ++index;

        pthread_cond_signal(&space_available); // Signal that space is available in the buffer
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