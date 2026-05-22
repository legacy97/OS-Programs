#include <stdio.h>

struct Process {
    int id;
    float execution;
    float deadline;
};

int main() {

    int n;
    float utilization = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    // Input process details
    for (int i = 0; i < n; i++) {

        p[i].id = i + 1;

        printf("\nProcess P%d\n", i + 1);

        printf("Enter Execution Time (Ci): ");
        scanf("%f", &p[i].execution);

        printf("Enter Deadline (Di): ");
        scanf("%f", &p[i].deadline);

        // EDF utilization calculation
        utilization += (p[i].execution / p[i].deadline);
    }

    printf("\n===== Earliest Deadline First Scheduling =====\n");

    printf("CPU Utilization = %.4f\n", utilization);

    // EDF condition
    if (utilization <= 1.0) {

        printf("\nCondition Satisfied:\n");

        :contentReference[oaicite:0]{index=0}

        printf("\nProcesses CAN be scheduled using EDF.\n");
    }
    else {

        printf("\nCondition Failed:\n");

        :contentReference[oaicite:1]{index=1}

        printf("\nProcesses CANNOT be guaranteed using EDF.\n");
    }

    return 0;
}
