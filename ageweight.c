// #include <stdio.h>
// int main()
// {
//     struct person
//     {
//         int age;
//         float weight;
//     };

//     struct person t;
//     t.age = 34;
//     t.weight = 34.34;

//     struct person *s = &t;

//     printf("%d", s->age);
//     printf(" \n%f ",(*s).weight);

//     return 0;
// }

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
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i].pr_id = i;

        for (int j = 0; j < 3; j++)
        {
            printf("Enter the process %d allocation %d: ", i, j);
            scanf("%d", &arr[i].alloc[j]);
        }

        for (int j = 0; j < 3; j++)
        {
            printf("Enter the process %d max %d: ", i, j);
            scanf("%d", &arr[i].max[j]);
            arr[i].need[j] = arr[i].max[j] - arr[i].alloc[j];
        }

        arr[i].done = 0;
    }

    for (int j = 0; j < 3; j++)
    {
        printf("Enter the available resource %d: ", j);
        scanf("%d", &arr[0].aval[j]);
    }

    int i = 0;
    int processesExecuted = 0;

    while (processesExecuted < n)
    {
        if (arr[i].done != 1 && arr[i].aval[0] >= arr[i].need[0] && arr[i].aval[1] >= arr[i].need[1] && arr[i].aval[2] >= arr[i].need[2])
        {
            for (int j = 0; j < 3; j++)
            {
                arr[i].aval[j] += arr[i].alloc[j];
            }
            arr[i].done = 1;
            processesExecuted++;
            i = 0; // Reset to check from the beginning
        }
        else
        {
            i = (i + 1) % n;
        }
    }

    printf("\n\t\t\t\tThe output table is\n");
    printf("\n====================================================================\n");

    for (int i = 0; i < n; i++)
    {
        printf("\np%d\t", arr[i].pr_id);

        for (int j = 0; j < 3; j++)
        {
            printf("\t%d", arr[i].alloc[j]);
        }
        for (int j = 0; j < 3; j++)
        {
            printf("\t%d", arr[i].max[j]);
        }

        for (int j = 0; j < 3; j++)
        {
            printf("\t%d", arr[i].aval[j]);
        }

        for (int j = 0; j < 3; j++)
        {
            printf("\t%d", arr[i].need[j]);
        }
        printf("\n");
    }

    return 0;
}
