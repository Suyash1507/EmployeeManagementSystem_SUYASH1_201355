#pragma once

#include "employee.h"

void AddEmployee(struct Employee* database, int* numEmployees);
void UpdateEmployee(struct Employee* database, int numEmployees);
void DeleteEmployee(struct Employee* database, int* numEmployees);
void DisplayAllEmployees(const struct Employee* database, int numEmployees);
