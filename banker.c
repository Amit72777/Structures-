#include <stdio.h>
struct process
{
    int pr_id;
    int aval[3];
    int max[3];
    int alloc[3];
    int need[3];
    int done;
};
int main()
{
    int n;
    printf("Enter the number of resource :");
    scanf("%d", &n);
    int a= n+1;
    struct process arr[a];
    int complete = 0 ;

    for (int i = 0; i < n; i++)
    {
        arr[i].pr_id = i;

        for (int j = 0; j < 3; j++)
        {
            printf("enter the  process %d allocation %d is ", i, j);
            scanf("%d", &arr[i].alloc[j]);
        }
        for (int j = 0; j < 3; j++)
        {
            printf("enter the  process %d max  %d is ", i, j);
            scanf("%d", &arr[i].max[j]);
            arr[i].need[j] = arr[i].max[j] - arr[i].alloc[j];
        }

        arr[i].done = 0;
    }

    for (int j = 0; j < 3; j++)
    {
        printf("enter the  available resoucre  ");
        scanf("%d", &arr[0].aval[j]);
    }

    int tu= 0;
    while (complete != n )
    {
        int i = 0;

        while (i < n)
        {
            if (arr[tu].aval[0] >= arr[i].need[0] && arr[tu].aval[1] >= arr[i].need[1] && arr[tu].aval[2] >= arr[i].need[2] && arr[i].done != 1)
            {
                for (int j = 0; j < 3; j++)
                {
                    arr[tu+1].aval[j] = arr[tu].aval[j] + arr[i].alloc[j];
                }
                arr[i].done = 1;
                complete+=1;
                tu+=1;
            }
            i++;
        }
    }

    printf(" \n \t\t\t\tThe output table is \n ");
    printf("\n ====================================================================\n");
    for (int i = 0; i < n; i++)

    {
        printf("\n p%d\t ", arr[i].pr_id);

        for (int j = 0; j < 3; j++)
        {
            printf(" \t %d ", arr[i].alloc[j]);
        }
        for (int j = 0; j < 3; j++)
        {
            printf(" \t %d", arr[i].max[j]);
        }

        for (int j = 0; j < 3; j++)
        {
            printf(" \t %d", arr[i].need[j]);
        }
    }

    printf("\n");
    for (int i = 0; i < n+1 ; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" \t %d", arr[i].aval[j]);
        }

        printf("\n");
    }
    return 0;
}
