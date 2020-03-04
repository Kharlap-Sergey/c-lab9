#include <stdio.h>

struct person
{
    int age;
    char name[20];
};

int main(void)
{
    struct person kate = { 31, "Kate" };
    char name[20] = "nika";
    //name = "pasha";
    char *p = name;

    puts(p);
    printf("name = %s \t age = %p \n", name, *p);
    //kate.name = "Milana";
   
    return 0;
}