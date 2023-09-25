#include <stdio.h>
#include <string.h>
#include "employee.h"
#include "crud.h"
#define _CRT_SECURE_NO_WARNINGS

#define MAX_EMPLOYEES 100


void printDashes(int count) {
    for (int i = 0; i < count; i++) {
        printf("-");
    }
    printf("\n");
}

int main() {
    struct Employee database[MAX_EMPLOYEES];
    int numEmployees = 0;
    int choice;
    int totalEmployees = 0; // stores total number of employees
    printf("\n");
    printDashes(60);
    printf("EMPLOYEE MANAGEMENT SYSTEM\n");
    printDashes(60);
    printf("THE FUNCTIONALITIES THAT PROGRAM CAN PERFORM ARE AS FOLLOWS:\n");
    printDashes(60);
    printf("Please select the option for the required Functionality\n\n");
    printf("Enter the total number of employees: ");
    scanf("%d", &totalEmployees);

    while (choice != 6) {
        printf("\nEmployee Management System Menu:\n");
        printf("1. Add a new Employee\n");
        printf("2. Update the added Employee Details\n");
        printf("3. Delete the added Employee\n");
        printf("4. Display All Employees entered\n");
        printf("5. Display Total Number of Employees entered\n");
        printf("6. Exit Program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            if (numEmployees < totalEmployees) {
                AddEmployee(database, &numEmployees);
            }
            else {
                printf("\n---------------------------------------\n");
                printf("\nDatabase is full. Cannot add more employees.\n");
                printf("\n---------------------------------------\n");
            }
            break;
        case 2:
            UpdateEmployee(database, numEmployees);
            break;
        case 3:
            DeleteEmployee(database, &numEmployees);
            break;
        case 4:
            DisplayAllEmployees(database, numEmployees);
            break;
        case 5:
            printf("Total Number of Employees: %d\n", numEmployees); // Display total employees
            break;
        case 6:
            printf("Exiting the Code. Thanks for your time!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }
}
