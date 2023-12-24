
#include <stdio.h>
#include<stdlib.h>
typedef struct process
{
    int id;
    int arrival_time;
    int bust_time;
    int tat;
    int wt;
    int et;
    int done;
    int ream;
} process;

int main()
{

    int n;
    printf("Enter the number of process : ");
    scanf("%d", &n);
    process arr[n], temp;
    int b[n];

    for (int i = 0; i < n; i++)
    {
        arr[i].id = i;
        arr[i].done = 0;
        printf("Enter the %d process arrival time is :", i);
        scanf("%d", &arr[i].arrival_time);
        printf("Enter the %d Process  bust time of is ", i);
        scanf("%d", &arr[i].bust_time);
        arr[i].ream = arr[i].bust_time;
    }
    int  time = 0 , lo; // tu for ideal
                                    // smallest = arr[0].bust_time;

    int complete = 0;
    int smallest;

    while (complete != n)
    {

        int com = 0;
        smallest = rand();
        for (int i = 0; i < n; i++)
        {
            if (smallest > arr[i].ream && time >= arr[i].arrival_time && arr[i].done != 1)
            {
                smallest = arr[i].ream;
                lo = i;
                com++;
            }
        }
        printf("\n%d\n", smallest);

        for (int k = 0; k < n; k++)
        {
            if (arr[k].ream == 0 && arr[k].done != 1)
            {
                arr[k].tat = time - arr[k].arrival_time;
                arr[k].wt = arr[k].tat - arr[k].bust_time;
                arr[k].et = time;
                arr[k].done = 1;
                complete++;
            }
        }

        if (com == 0)
        {
            time++;
            continue;
        }

        if (time >= arr[lo].arrival_time && arr[lo].done != 1)
        {
            arr[lo].ream--;
            time++;
        }
    }

    printf("\n\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\n \t\t\t the Shortest Remaing time first Sheduling \t\n");
    printf("\n\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\n process Id   Arrivalt time   Bust time     Exit Time    TrunaroundTime  Waiting time \n");
    for (int j = 0; j < n; j++)
        printf("\n P%d\t\t  %d \t\t %d \t\t %d \t\t %d \t\t %d  ", arr[j].id, arr[j].arrival_time, arr[j].bust_time, arr[j].et, arr[j].tat, arr[j].wt);

    return 0;
}
