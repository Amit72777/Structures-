/* Creat a structuew type 'Person' wiht name salay and age as its attributes.
Declare and initialize 2 variables for this. Print the name of first person
and age of the other . */
#include <stdio.h>
#include <string.h>
int main()
{
    struct person // create a sturcture
    {
        char name[25];
        float salary;
        int age;
    };

    struct person x, y; // decleaare a sturcture variable
                        // assing a value

    x.age = 18;
    x.salary = 2100;

    strcpy(x.name, "Amit");
    strcpy(y.name, "Rohit");
    y.age = 34;

    y.salary = 1800;
    // print a variable
    printf(" %s \n %d ", x.name, y.age);

    return 0;
}

/*
Ouput:-
Amit
34
*/