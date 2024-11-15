#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <string>

using namespace std;

struct Employee
{
    int id;
    string name;
    double salary;
};

void displayEmpolyee(const Employee &emp)
{
    cout << "ID : " << emp.id << endl;
    cout << "Name : " << emp.name << endl;
    cout << "Salary : $" << emp.salary << endl;
}

int main()
{

    vector<Employee> emps = {
        {101, "Sagar", 100000},
        {102, "hitesh", 80000},
        {103, "Amit", 70000},
        {104, "Aman", 85000},
        {105, "Harkirat", 90000},

    };

    sort(emps.begin(), emps.end(), [](const Employee &e1, const Employee &e2)
         { return e1.salary > e2.salary; });

    cout << "Employess Sorted by Salary : " << endl;
    for_each(emps.begin(), emps.end(), displayEmpolyee);

    vector<Employee> highEarner;

    copy_if(emps.begin(), emps.end(), back_inserter(highEarner), [](const Employee &e)
            { return e.salary > 70000; });

    cout<< "High Earners : " << endl;
    for_each(emps.begin(), emps.end(), displayEmpolyee);

    double totalSalary = accumulate(emps.begin(), emps.end(), 0.0, [](double sum , const Employee& e ){
        return sum + e.salary;
    });

    double averageSalary = totalSalary / emps.size();
    cout << "averageSalary : " << averageSalary << endl; 

    auto highestPaid = max_element(emps.begin(), emps.end() , [](const Employee& e1 , const Employee& e2){
        return e1.salary < e2.salary;
    });

    return 0;
}