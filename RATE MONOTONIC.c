#include <stdio.h>

#define MAX_TASKS 10

typedef struct {
    int id;
    int execution_time;
    int period;
    int remaining_time;
    int next_arrival;
    int deadline;
} Task;

int main() {
    int n, simulation_time;
    Task tasks[MAX_TASKS];

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        tasks[i].id = i + 1;

        printf("\nTask %d\n", i + 1);

        printf("Execution Time: ");
        scanf("%d", &tasks[i].execution_time);

        printf("Period: ");
        scanf("%d", &tasks[i].period);

        tasks[i].remaining_time = 0;
        tasks[i].next_arrival = 0;
        tasks[i].deadline = tasks[i].period;
    }

    printf("\nEnter simulation time: ");
    scanf("%d", &simulation_time);

    printf("\n--- Rate Monotonic Scheduling ---\n");

    for (int time = 0; time < simulation_time; time++) {

        /* Release tasks at their period */
        for (int i = 0; i < n; i++) {
            if (time == tasks[i].next_arrival) {

                /* Check missed deadline */
                if (tasks[i].remaining_time > 0) {
                    printf("Time %d: Task %d MISSED deadline!\n",
                           time, tasks[i].id);
                }

                tasks[i].remaining_time = tasks[i].execution_time;
                tasks[i].deadline = time + tasks[i].period;
                tasks[i].next_arrival += tasks[i].period;
            }
        }

        /* Select highest priority task
           (smallest period = highest priority) */
        int selected = -1;

        for (int i = 0; i < n; i++) {
            if (tasks[i].remaining_time > 0) {

                if (selected == -1 ||
                    tasks[i].period < tasks[selected].period) {
                    selected = i;
                }
            }
        }

        /* Execute selected task */
        if (selected != -1) {
            printf("Time %2d -> Task %d executing\n",
                   time, tasks[selected].id);

            tasks[selected].remaining_time--;
        } else {
            printf("Time %2d -> CPU Idle\n", time);
        }
    }

    printf("\nSimulation Completed.\n");

    return 0;
}
