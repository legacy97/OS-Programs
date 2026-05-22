#include <stdio.h>

int main() {
    int n, m;

    // n = number of processes
    // m = number of resource types
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int alloc[n][m], request[n][m], avail[m];
    int finish[n], safeSeq[n];

    // Input Allocation Matrix
    printf("\nEnter Allocation Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    // Input Request Matrix
    printf("\nEnter Request Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &request[i][j]);
        }
    }

    // Input Available Resources
    printf("\nEnter Available Resources:\n");
    for (int j = 0; j < m; j++) {
        scanf("%d", &avail[j]);
    }

    // Initialize finish array
    for (int i = 0; i < n; i++) {
        finish[i] = 0;
    }

    int count = 0;

    while (count < n) {
        int found = 0;

        for (int i = 0; i < n; i++) {

            if (finish[i] == 0) {

                int j;

                // Check if request <= available
                for (j = 0; j < m; j++) {
                    if (request[i][j] > avail[j])
                        break;
                }

                // If all resources can be allocated
                if (j == m) {

                    // Release allocated resources
                    for (int k = 0; k < m; k++) {
                        avail[k] += alloc[i][k];
                    }

                    finish[i] = 1;
                    safeSeq[count++] = i;
                    found = 1;
                }
            }
        }

        // No process can proceed
        if (found == 0)
            break;
    }

    // Check for deadlock
    int deadlock = 0;

    for (int i = 0; i < n; i++) {
        if (finish[i] == 0) {
            deadlock = 1;
            printf("\nProcess P%d is deadlocked.\n", i);
        }
    }

    if (deadlock == 0) {
        printf("\nNo Deadlock Detected.\n");
        printf("Safe Sequence: ");

        for (int i = 0; i < n; i++) {
            printf("P%d ", safeSeq[i]);
        }

        printf("\n");
    }

    return 0;
}
