#include<stdio.h>
void swap_var(int *x,int *y)
{
    printf("\n\nThe values before swapping : ");
    printf("x = %d and y = %d",*x,*y);
    int temp=*x;
    *x=*y;
    *y=temp;
    printf("\nThe values after swapping : ");
    printf("x = %d and y = %d",*x,*y);

}
int main(void)
{
    int a, b;
    printf("\nEnter number 1 : ");
    scanf("%d",&a);
    printf("\nEnter number 2 : ");
    scanf("%d",&b);
    printf("\nThe value of a and b before swapping : ");
    printf("a = %d and b = %d",a,b);
    swap_var(&a,&b);
    printf("\n\nThe value of x and y after swapping : ");
    printf("a = %d and b = %d",a,b);
}