#include<stdio.h>
int main()
{
 int a =5, b =10, c =6;
 a = b++; 
printf("\n%d %d %d", a, b, c);
c = --a ;
printf("\n%d %d %d", a, b, c);
b = --c  * c--;
 printf("\n%d %d %d", a, b, c);
}