#include<stdio.h>
#include "employee.h"
#include "crud.h"
#define _CRT_SECURE_NO_WARNINGS

#define MAX 100

void AddEmployee(struct Employee* data, int* numOfEmpl) {
	if (*numOfEmpl < MAX
		) {
		struct Employee emp;
		AcceptEmployeeData(&emp);
		if (emp.Empno >= 1000 && emp.Empno <= 9999) {
			data[*numOfEmpl] = emp; //if data entered is correct add to database array.
			(*numOfEmpl)++;
			printf("Employee added successfully to company !");
		}
		else {
			printf("Employee not added. ID must be between 1000 and 9999.\n");
		}
	}
	else {
		printf("Database is full and cannot add more employees at this moment....");
	}
}

void UpdateEmployee(struct Employee* database, int numOfEmpl) {
	int empno;
	int found = 0;
	printf("Enter Employee Number to update: ");
	scanf("%d", &empno);

	for (int i = 0; i < numOfEmpl; i++) {
		if (database[i].Empno == empno) {
			printf("Employee Details Before Update is as follows:\n");
			DisplayEmployeeData(&database[i]);
			printf("Beggining procedure to update employees...");
			AcceptEmployeeData(&database[i]);
			found = 1;
			printf("----Employee details updated successfully----\n");
			break;
		}
	}
	if (!found) {
		printf("Employee with ID %d not found.\n", empno);
	}
}

void DeleteEmployee(struct Employee* database, int* numOfEmpl) {
	int empno;
	int found = 0;

	printf("Enter Employee Number to delete: ");
	scanf("%d", &empno);

	for (int i = 0; i < numOfEmpl; i++) {
		if (database[i].Empno == empno) {
			for (int j = i; j < (*numOfEmpl - 1); j++) {
				database[j] = database[j + 1];
			}
			(*numOfEmpl)--;
			printf("Employee with ID %d deleted successfully. You can add the new employee if you wish...\n", empno);
			found = 1;
			break;
		}
	}
	if (!found) {
		printf("Employee with ID %d not found. Please enter the correct Employee number\n", empno);
	}
}

void DisplayAllEmployees(const struct Employee* database, int numOfEmpl) {
	printf("\nEmployee Data:\n");
	for (int i = 0; i < numOfEmpl; i++) {
		DisplayEmployeeData(&database[i]);
	}
}