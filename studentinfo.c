/* Creat a structure to specify data on students wiht these attributes : rollnumber ,
name , department , course , year of joining . Create 2 structure variable . Now creATE
a fuctin to cheak if two students have teh same Department .Pass the two structure
variable as input to this fuction .  */
#include <stdio.h>
#include <string.h>

struct studentinfo // declaaring a structure in global 
{
    char Name[20];
    int rollNo;
    char Course[20];
    char department[10];
    int yearofjoin;
};

int checkdepartment(struct studentinfo p, struct studentinfo s) // fuctio n defination 
{
    if (strcmp(p.department, s.department) == 0)
        printf(" Both student  are same department ");
    else
        printf(" both student are different department ");

    return 0;
}

int main()
{

    struct studentinfo s1, s2;

    s1.rollNo = 17;
    s1.yearofjoin = 2023;
    strcpy(s1.Name, "Amit");
    strcpy(s1.Course, "Computerscience");
    strcpy(s1.department, "B.tech");

    s2.rollNo = 24;
    s2.yearofjoin = 2022;
    strcpy(s2.Name, "Nitesh");
    strcpy(s2.department, "B.tech");
    strcpy(s2.Course, "Minning");

    checkdepartment(s1, s2);  // fucntion calling 

    return 0;
}