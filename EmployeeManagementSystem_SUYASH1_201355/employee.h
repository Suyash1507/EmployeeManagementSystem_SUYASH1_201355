#pragma once

struct Date {
    int dd, mm, yy;
};
struct Employee {
    int Empno;
    char EmpName[50];
    struct Date hiredate;
    float BasicSalary;
    float NetSalary;
};

void AcceptEmployeeData(struct Employee* emp);
void CalculateNetPay(struct Employee* emp);
void DisplayEmployeeData(const struct Employee* emp);






