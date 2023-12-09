#include <stdio.h>

typedef struct process
{
    int id;
    int arrival_time;
    int bust_time;
    int et;
    int tat;
    int wt;
} process ;

int main()
{
    int n;
    printf("Enter the number of process : ");
    scanf("%d", &n);
    process arr[n],temp ;

    for (int i = 0; i < n; i++)
    {
        arr[i].id = i;
        printf("Enter the %d process arrival time is :", i);
        scanf("%d", &arr[i].arrival_time);
        printf("Enter the %d Process  bust time of is ", i);
        scanf("%d", &arr[i].bust_time);
    }

    int m, x = n - 1, a = n, i = 0,time=0;
    // acodring to bubble sort we arraang asending odern in arival time 

    do
    {
        m = 0;
        for (i = 0; i < x; i++)
        {
            if (arr[i].arrival_time > arr[i + 1].arrival_time)
            {

                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp ;

                m++;
            }
        
        }

        i++, a--;
        x--;

    } while (m != 0);

// we perfor operation in aribal time  
    for(int k=0;k<n;k++)
    {
        if(time >= arr[k].arrival_time)
        {
        arr[k].et = time + arr[k].bust_time;
        arr[k].tat= arr[k].et -arr[k].arrival_time;
        arr[k].wt = arr[k].tat - arr[k].bust_time;
        time = arr[k].et;
        }
        else 
        time ++ ,k--;
    }


    for (int j = 0; j < n; j++)
        printf("\n P%d\t %d \t %d \t %d \t %d \t %d ", arr[j].id, arr[j].arrival_time, arr[j].bust_time , arr[j].et , arr[j].tat,arr[j].wt);

    return 0;
}