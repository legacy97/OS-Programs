#include <stdio.h>

int main() {

    int n, i, j;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], pr[n], wt[n], tat[n], p[n];

    // Input burst time and priority
    printf("\nEnter Burst Time and Priority for each process:\n");

    for(i = 0; i < n; i++) {

        p[i] = i + 1;

        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);

        printf("P%d Priority: ", i + 1);
        scanf("%d", &pr[i]);
    }

    // Sort according to priority
    for(i = 0; i < n - 1; i++) {

        for(j = i + 1; j < n; j++) {

            if(pr[i] > pr[j]) {

                // Swap priority
                int temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                // Swap burst time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap process number
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Calculate Waiting Time
    wt[0] = 0;

    for(i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Calculate Turn Around Time
    float avg_wt = 0, avg_tat = 0;

    for(i = 0; i < n; i++) {

        tat[i] = wt[i] + bt[i];

        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    // Display Results
    printf("\nProcess\tPriority\tBurst Time\tWaiting Time\tTurn Around Time\n");

    for(i = 0; i < n; i++) {

        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n",
               p[i], pr[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turn Around Time = %.2f\n", avg_tat / n);

    return 0;
}
