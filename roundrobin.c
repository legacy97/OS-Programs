#include <stdio.h>

int main() {
    int n, tq, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], rt[n], wt[n], tat[n];
    int time = 0, remain;

    // Input burst times
    printf("\nEnter Burst Time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);

        rt[i] = bt[i]; // Remaining time
    }

    // Input time quantum
    printf("\nEnter Time Quantum: ");
    scanf("%d", &tq);

    remain = n;

    // Round Robin Scheduling
    while(remain != 0) {

        for(i = 0; i < n; i++) {

            if(rt[i] > 0) {

                if(rt[i] <= tq) {
                    time += rt[i];

                    wt[i] = time - bt[i];
                    rt[i] = 0;

                    remain--;
                }
                else {
                    rt[i] -= tq;
                    time += tq;
                }
            }
        }
    }

    // Calculate Turn Around Time
    for(i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    // Display Results
    float avg_wt = 0, avg_tat = 0;

    printf("\nProcess\tBurst Time\tWaiting Time\tTurn Around Time\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n",
               i + 1, bt[i], wt[i], tat[i]);

        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turn Around Time = %.2f\n", avg_tat / n);

    return 0;
}
