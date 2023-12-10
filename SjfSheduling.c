#include <stdio.h>
typedef struct process
{
    int id;
    int arrival_time;
    int bust_time;
    int tat;
    int wt;
    int et;
    int done;
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
    }

    int tat, time = 0, x = n - 1, i,tu;
    int m;
    do
    {
        m = 0;
        for (i = 0; i < x; i++)
        {
            if (arr[i].bust_time > arr[i + 1].bust_time)
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                m++;
            }
        }
        x--;
    } while (m != 0);

    int complete = 0;

    while (complete != n)
    {

        for ( i = 0; i < n;)
        {
            tu = 1;
            if (time >= arr[i].arrival_time && arr[i].done != 1)
            {
                arr[i].et = time + arr[i].bust_time;
                arr[i].tat = arr[i].et - arr[i].arrival_time;
                arr[i].wt = arr[i].tat - arr[i].bust_time;
                time = arr[i].et;
                complete++;
                arr[i].done = 1;
                tu =0;
            }
            if(tu == 0 ) i =0;
            else i++;
           //  else break;
            // }
        }
    }

    x = n-1;
    do
    {
        m = 0;
        for (i = 0; i < x; i++)
        {
            if (arr[i].id > arr[i + 1].id)
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                m++;
            }
        }
        x--;
    } while (m != 0);

    for (int j = 0; j < n; j++)
        printf("\n P%d\t %d \t %d \t %d \t %d \t %d  ", arr[j].id, arr[j].arrival_time, arr[j].bust_time, arr[j].et, arr[j].tat, arr[j].wt);

    return 0;
}

