/* A record contains name of cricketer, his age,, number of test matches that
he has played and the average runs that he has scored in each test match. Create
an aray of structure to hold records of 20 such cricketer and then write a
programm to read these records */
#include <stdio.h>
#include <string.h>
int main()
{
    typedef struct cricketer
    {
        char name[20];
        int age;
        int Nomatch;
        float average;

    } cricketer;

    cricketer arr[20];

    for (int i = 0; i < 3; i++)
    {
        char s[20];

        puts("Enter the name");
        scanf("%s", arr[i].name);

      //  strcpy(arr[i].name, s);

        printf("Enter the age of cricketer :");
        scanf("%d", &arr[i].age);
        printf(" Enter the number of match:");
        scanf("%d", &arr[i].Nomatch);
        printf(" Enter the average of match:");
        scanf("%f", &arr[i].average);
    }

    for (int i = 0; i < 3; i++)
    {
        printf("\n the name %s \n", arr[i].name);
        printf(" \n the age of cricketer : %d\n ", arr[i].age);
        printf(" \n the Number of match: %d \n", arr[i].Nomatch);
        printf(" The average run of match : %f \n\n", arr[i].average);
    }

    return 0;
}