#include<stdio.h>
int main()
{
    struct student
    {
        int roll_no;
        char name[50];
        int fees;
        char dob[12];
    };
    
    int n, i;
    printf("\nEnter the number of students: ");
    scanf("%d", &n);
    
    struct student stud[n];
    
    for(i = 0; i < n; i++)
    {
        printf("\nStudent Information %d",i+1);
        printf("\nEnter the roll number: ");
        scanf("%d", &stud[i].roll_no);
        
        printf("Enter the name: ");
        scanf(" %[^\n]", stud[i].name);  // Note space before %[^\n] to ignore newline left by previous scanf
        
        printf("Enter the fees: ");
        scanf("%d", &stud[i].fees);
        
        printf("Enter the DOB (dd-mm-yyyy): ");
        scanf(" %[^\n]", stud[i].dob);  // Used to safely read a string with spaces
    }
    
    // Displaying student details
    for(i = 0; i < n; i++)
    {
        printf("\n*******DETAILS OF STUDENT %d*******", i + 1);
        printf("\nRoll Number = %d", stud[i].roll_no);
        printf("\nName = %s", stud[i].name);
        printf("\nFees = %d", stud[i].fees);
        printf("\nDOB = %s\n", stud[i].dob);
    }
    
    return 0;
}
