#include <stdio.h>
#include <stdlib.h>
void FCFS(int exe[], int n)
{
    int i;
    int wt[n];
    wt[0] = 0;
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + exe[i - 1];
    }
    printf("\nWaiting time of each procsess in FCFS is \n");
    for (int i = 0; i < n; i++)
        printf("P%d ->%d  ", i + 1, wt[i]);

    printf("\nTurnaround time of each procsess in FCFS is \n");
    for (int i = 0; i < n; i++)
        printf("P%d ->%d  ", i + 1, wt[i] + exe[i]);
}
void SJF(int exe[], int n)
{
    int i, b, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (exe[i] > exe[j])
            {
                b = exe[i];
                exe[i] = exe[j];
                exe[j] = b;
            }
        }
    }
    int wt[n];
    wt[0] = 0;
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + exe[i - 1];
    }
    printf("\nWaiting time of each procsess in SJF is \n");
    for (int i = 0; i < n; i++)
        printf("P%d ->%d  ", i + 1, wt[i]);
    printf("Turnaround time of each procsess in SJF is \n");
    for (int i = 0; i < n; i++)
        printf("P%d ->%d  ", i + 1, wt[i] + exe[i]);
}
int main()
{
    int n, i, choice;
    while (1)
    {
        printf("\nEnter the total no. of processes that are scheduled\n");
        scanf("%d", &n);
        int wt[n], exe[n];
        wt[0] = 0;
        printf("Enter the execution time of each processes\n");
        for (i = 0; i < n; i++)
        {
            scanf("%d", &exe[i]);
        }
        printf("Enter the type of schedule:\n1.FCFS\n2.SJF\n\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            FCFS(exe, n);
            break;
        case 2:
            SJF(exe, n);
            break;
        default:
            printf("You entered invalid schedule\n");
            exit(0);
        }
    }

    return 0;
}
