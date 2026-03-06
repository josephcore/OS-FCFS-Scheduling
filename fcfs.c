#include <stdio.h>

int main() {
    int n, i;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    char pid[n][10];
    int at[n], bt[n], wt[n], tat[n], ct[n];

    for(i = 0; i < n; i++) {
        scanf("%s %d %d", pid[i], &at[i], &bt[i]);
    }

    int time = 0;

    for(i = 0; i < n; i++) {

        if(time < at[i]) {
            time = at[i];
        }

        wt[i] = time - at[i];
        ct[i] = time + bt[i];
        tat[i] = ct[i] - at[i];

        time = ct[i];
    }

    float avg_wt = 0, avg_tat = 0;

    printf("\nWaiting Time:\n");
    for(i = 0; i < n; i++) {
        printf("%s %d\n", pid[i], wt[i]);
        avg_wt += wt[i];
    }

    printf("\nTurnaround Time:\n");
    for(i = 0; i < n; i++) {
        printf("%s %d\n", pid[i], tat[i]);
        avg_tat += tat[i];
    }

    avg_wt = avg_wt / n;
    avg_tat = avg_tat / n;

    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);

    return 0;
}