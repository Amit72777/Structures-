/* crete a structure type 'book' with name, price and number of pages as its 
attributes */
#include<stdio.h>
#include<string.h>
int main()
{
    struct book
    {
        char name[20];
        float price;
        int pages;
    } navbodh ;

    // struct book navbodh ;
strcpy(navbodh.name," Python");
    navbodh.price = 480.0;
    navbodh.pages = 343;

    printf(" %s \n %f \n %d",navbodh.name,navbodh.price,navbodh.pages);


    
    return 0;
}