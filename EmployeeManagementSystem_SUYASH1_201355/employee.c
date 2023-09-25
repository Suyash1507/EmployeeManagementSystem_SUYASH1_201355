#include<stdio.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#include <ctype.h>
#include "employee.h"

void AcceptEmployeeData(struct Employee* emp) {
	char tempName[50];
	printf("Enter the employee number(should be between 1000 to 9999): ");
	while (1) {
		if (scanf("%d", &emp->Empno) != 1 || emp->Empno < 1000 || emp->Empno > 9999) {
			printf("Invalid Input !! Please try again....\n");
			printf("Enter a Employee number between 1000 and 9999: ");
			while (getchar() != '\n'); // clears the input buffer
		}
		else {
			break; // this break the loop if there is a valid input.
		}
	}
	printf("Please enter the employee name: ");
	while (1) {
		if (scanf(" %s", tempName) != 1 || !IsAlphabetic(tempName)) {
			printf("Invalid Input !! Please try again....\n");
			printf("Enter a Employee name that consist of only alphabets: ");
			while (getchar() != '\n');
		}
		else {
			strcpy(emp->EmpName, tempName);
			break;
		}
	}
	printf("Enter Hire Date. Please enter in the format mentioned in brackets (dd mm yy): ");
	while (1) {
		if (scanf("%d %d %d", &emp->hiredate.dd, &emp->hiredate.mm, &emp->hiredate.yy) != 3 ||
			!IsValidDate(emp->hiredate.dd, emp->hiredate.mm, emp->hiredate.yy)) {
			printf("Invalid Input !! Please try again....\n");
			printf("Enter the hire date again in the format(dd mm yy): ");
			while (getchar() != '\n');
		}
		else {
			break;
		}
	}
	printf("Enter Basic Salary: ");
	scanf("%f", &emp->BasicSalary);
	CalculateNetPay(emp);
}

int IsAlphabetic(const char* str) {
	// Function to check if a string contains only alphabetic characters
	for (int i = 0; str[i] != '\0'; i++) {
		if (!isalpha(str[i])) {
			return 0;
		}
	}
	return 1;
}

int IsValidDate(int dd, int mm, int yy) {
	
	if (yy >= 0 && mm >= 1 && mm <= 12) {
		int daysInMonth; 
		if (mm == 2) {
			daysInMonth = (yy % 4 == 0 && yy % 100 != 0) || (yy % 400 == 0) ? 29 : 28;
		}
		else if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
			daysInMonth = 30;
		}
		else {
			daysInMonth = 31;
		}
		return (dd >= 1 && dd <= daysInMonth);
	}
	return 0; 
}


void CalculateNetPay(struct Employee* emp) {
	float DA = 0.4 * emp->BasicSalary;
	float TA = 0.1 * emp->BasicSalary;
	float PF = 0.05 * emp->BasicSalary;
	emp->NetSalary = emp->BasicSalary + DA + TA - PF;
}

void DisplayEmployeeData(const struct Employee* emp) {
	printf("\n------------------------------------------------------------\n");
	printf("Employee number: %d\n", emp->Empno);
	printf("Employee name:   %-30s\n", emp->EmpName);
	printf("Hire date:       %02d/%02d/%02d\n", emp->hiredate.dd, emp->hiredate.mm, emp->hiredate.yy);
	printf("Basic Salary:    %.2f\n", emp->BasicSalary);
	printf("Net Salary:      %.2f\n", emp->NetSalary);
	printf("------------------------------------------------------------\n");
}
