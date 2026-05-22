#include <stdio.h>

#define N 5

// Philosopher states
#define THINKING 0
#define HUNGRY 1
#define EATING 2

int state[N];

// Function to test whether philosopher can eat
void test(int i)
{
    if (state[i] == HUNGRY &&
        state[(i + 4) % N] != EATING &&
        state[(i + 1) % N] != EATING)
    {
        state[i] = EATING;

        printf("\nPhilosopher %d takes fork %d and %d",
               i + 1, (i + 4) % N + 1, i + 1);

        printf("\nPhilosopher %d is Eating\n", i + 1);
    }
}

// Function to pick up forks
void take_fork(int i)
{
    state[i] = HUNGRY;

    printf("\nPhilosopher %d is Hungry\n", i + 1);

    test(i);

    if (state[i] != EATING)
    {
        printf("Philosopher %d is Waiting\n", i + 1);
    }
}

// Function to put down forks
void put_fork(int i)
{
    state[i] = THINKING;

    printf("\nPhilosopher %d putting fork %d and %d down",
           i + 1, (i + 4) % N + 1, i + 1);

    printf("\nPhilosopher %d is Thinking\n", i + 1);

    // Check neighboring philosophers
    test((i + 4) % N);
    test((i + 1) % N);
}

int main()
{
    int i;

    // Initially all philosophers are thinking
    for (i = 0; i < N; i++)
    {
        state[i] = THINKING;
    }

    // Simulate philosophers picking forks
    for (i = 0; i < N; i++)
    {
        take_fork(i);
    }

    // Simulate philosophers putting forks down
    for (i = 0; i < N; i++)
    {
        put_fork(i);
    }

    return 0;
}
