#include <stdio.h>
#include <stdlib.h>

struct input
{
    int x;
    int y;
};

struct input add(struct input , struct input);

struct input sub(struct input , struct input);

struct input mult(struct input , struct input);

struct input divn(struct input , struct input);

struct input getnum();

int main()
{
    struct input n1 , n2 , sum , diff , mul , divi ;

    printf("Enter two numbers to performs addition, subtraction, multiplication, and division, and displays the results.\n");
    n1 = getnum();
    n2 = getnum();

    sum = add(n1,n2);
    diff=sub(n1,n2);
    mul=mult(n1,n2);
    divi=divn(n1,n2);

    printf("sum is: %d\n",sum);
    printf("sub is: %d\n",diff);
    printf("mult is: %d\n",mul);
    printf("div is: %d\n",divi);
    return 0;
}

struct input getnum()
{
    struct input temp;
   printf("enter number number: ");
   scanf("%d",&temp.x);


   return temp;
};

struct input add(struct input n1, struct input n2)
{
    struct input result;

    result.x = n1.x+n2.x;

    return result;
};


struct input sub(struct input n1, struct input n2)
{
struct input result;
    result.x = n1.x-n2.x;

    return result;
};

struct input mult(struct input n1 , struct input n2)
{
struct input result;
     result.x = (n1.x)*(n2.x);

    return result;
};


struct input divn(struct input n1 , struct input n2)
{
struct input result;
     result.x = n1.x/n2.x;


    return result;
};
