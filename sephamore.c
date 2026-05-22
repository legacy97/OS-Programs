#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0;
int empty = 3, x = 0;

// Wait operation
int wait(int s) {
    return (--s);
}

// Signal operation
int signal(int s) {
    return (++s);
}

// Producer function
void producer() {

    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);

    x++;

    printf("\nProducer produces item %d", x);

    mutex = signal(mutex);
}

// Consumer function
void consumer() {

    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);

    printf("\nConsumer consumes item %d", x);

    x--;

    mutex = signal(mutex);
}

int main() {

    int n, choice;

    printf("\n1. Producer");
    printf("\n2. Consumer");
    printf("\n3. Exit");

    while(1) {

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:

                if((mutex == 1) && (empty != 0)) {
                    producer();
                }
                else {
                    printf("\nBuffer is Full!");
                }

                break;

            case 2:

                if((mutex == 1) && (full != 0)) {
                    consumer();
                }
                else {
                    printf("\nBuffer is Empty!");
                }

                break;

            case 3:
                exit(0);

            default:
                printf("\nInvalid choice!");
        }
    }

    return 0;
}
