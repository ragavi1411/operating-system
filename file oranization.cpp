#include <stdio.h>
#include <stdlib.h>

struct Employee
{
    int empId;
    char empName[50];
    float empSalary;
};

int main()
{
    FILE *filePtr;
    struct Employee emp;
    int choice;

    filePtr = fopen("employee.dat", "rb+");

    if(filePtr == NULL)
        filePtr = fopen("employee.dat", "wb+");

    do
    {
        printf("\n1. Add Employee");
        printf("\n2. Display Employee");
        printf("\n3. Update Employee");
        printf("\n4. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter Employee ID: ");
                scanf("%d", &emp.empId);

                printf("Enter Employee Name: ");
                scanf("%s", emp.empName);

                printf("Enter Employee Salary: ");
                scanf("%f", &emp.empSalary);

                fseek(filePtr, (emp.empId-1)*sizeof(struct Employee), SEEK_SET);
                fwrite(&emp, sizeof(struct Employee), 1, filePtr);

                printf("Employee Added Successfully\n");
                break;

            case 2:
                printf("Enter Employee ID: ");
                scanf("%d", &emp.empId);

                fseek(filePtr, (emp.empId-1)*sizeof(struct Employee), SEEK_SET);
                fread(&emp, sizeof(struct Employee), 1, filePtr);

                printf("\nID : %d", emp.empId);
                printf("\nName : %s", emp.empName);
                printf("\nSalary : %.2f\n", emp.empSalary);
                break;

            case 3:
                printf("Enter Employee ID: ");
                scanf("%d", &emp.empId);

                fseek(filePtr, (emp.empId-1)*sizeof(struct Employee), SEEK_SET);
                fread(&emp, sizeof(struct Employee), 1, filePtr);

                printf("Enter New Name: ");
                scanf("%s", emp.empName);

                printf("Enter New Salary: ");
                scanf("%f", &emp.empSalary);

                fseek(filePtr, (emp.empId-1)*sizeof(struct Employee), SEEK_SET);
                fwrite(&emp, sizeof(struct Employee), 1, filePtr);

                printf("Employee Updated Successfully\n");
                break;

            case 4:
                break;

            default:
                printf("Invalid Choice\n");
        }

    } while(choice != 4);

    fclose(filePtr);
    return 0;
}
