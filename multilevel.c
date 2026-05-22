#include <stdio.h>

int main() {

    int ns, nu, i;

    // ns = number of system processes
    // nu = number of user processes

    printf("Enter number of System Processes: ");
    scanf("%d", &ns);

    int sbt[ns], swt[ns], stat[ns];

    printf("\nEnter Burst Time for System Processes:\n");

    for(i = 0; i < ns; i++) {
        printf("System Process P%d: ", i + 1);
        scanf("%d", &sbt[i]);
    }

    printf("\nEnter number of User Processes: ");
    scanf("%d", &nu);

    int ubt[nu], uwt[nu], utat[nu];

    printf("\nEnter Burst Time for User Processes:\n");

    for(i = 0; i < nu; i++) {
        printf("User Process P%d: ", i + 1);
        scanf("%d", &ubt[i]);
    }

    // FCFS for System Processes
    swt[0] = 0;

    for(i = 1; i < ns; i++) {
        swt[i] = swt[i - 1] + sbt[i - 1];
    }

    for(i = 0; i < ns; i++) {
        stat[i] = swt[i] + sbt[i];
    }

    // FCFS for User Processes
    uwt[0] = stat[ns - 1];

    for(i = 1; i < nu; i++) {
        uwt[i] = uwt[i - 1] + ubt[i - 1];
    }

    for(i = 0; i < nu; i++) {
        utat[i] = uwt[i] + ubt[i];
    }

    // Display System Processes
    printf("\n===== System Processes =====\n");

    printf("Process\tBurst Time\tWaiting Time\tTurn Around Time\n");

    for(i = 0; i < ns; i++) {

        printf("P%d\t%d\t\t%d\t\t%d\n",
               i + 1, sbt[i], swt[i], stat[i]);
    }

    // Display User Processes
    printf("\n===== User Processes =====\n");

    printf("Process\tBurst Time\tWaiting Time\tTurn Around Time\n");

    for(i = 0; i < nu; i++) {

        printf("P%d\t%d\t\t%d\t\t%d\n",
               i + 1, ubt[i], uwt[i], utat[i]);
    }

    return 0;
}
