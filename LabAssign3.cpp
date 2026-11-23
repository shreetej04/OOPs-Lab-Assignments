/*
Create employee bio-data using following classes: i) Personal record ii) Professional record ii) Academic record. Assume appropriate data members and member function to accept required data & print bio-data. Create bio-data using multiple inheritance using C++. Use a virtual base class to avoid ambiguity.
*/

#include <iostream>
#include <string>
using namespace std;

// Base Class
class Person
{
protected:
    string name, dob, gender;

public:
    void accept()
    {
        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Date of Birth: ";
        getline(cin, dob);

        cout << "Enter Gender: ";
        getline(cin, gender);
    }

    void display()
    {
        cout << "\nName: " << name;
        cout << "\nDate of Birth: " << dob;
        cout << "\nGender: " << gender;
    }
};

// Derived Class 1
class PersonalRecord : virtual public Person
{
};

// Derived Class 2
class ProfessionalRecord : virtual public Person
{
protected:
    string designation;
    float salary;

public:
    void accept()
    {
        cout << "Enter Designation: ";
        getline(cin, designation);

        cout << "Enter Salary: ";
        cin >> salary;
    }

    void display()
    {
        cout << "\nDesignation: " << designation;
        cout << "\nSalary: " << salary;
    }
};

// Multiple Inheritance
class AcademicRecord : public PersonalRecord,
                       public ProfessionalRecord
{
protected:
    string degree;
    float marks;

public:
    void accept()
    {
        Person::accept();
        ProfessionalRecord::accept();

        cin.ignore();

        cout << "Enter Degree: ";
        getline(cin, degree);

        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display()
    {
        Person::display();
        ProfessionalRecord::display();

        cout << "\nDegree: " << degree;
        cout << "\nMarks: " << marks << "%";
    }
};

// Employee Class
class Employee : public AcademicRecord
{
public:
    void show()
    {
        cout << "\n\n----- EMPLOYEE BIO-DATA -----\n";
        display();
        cout << "\n-----------------------------\n";
    }
};

int main()
{
    Employee e;

    cout << "Enter Employee Details:\n\n";

    e.accept();

    e.show();

    return 0;
}
/*
Enter Employee Details:

Enter Name: Rahul Patil
Enter Date of Birth: 12/05/2004
Enter Gender: Male
Enter Designation: Software Engineer
Enter Salary: 35000
Enter Degree: B.Tech Computer
Enter Marks: 85

----- EMPLOYEE BIO-DATA -----

Name: Rahul Patil
Date of Birth: 12/05/2004
Gender: Male
Designation: Software Engineer
Salary: 35000
Degree: B.Tech Computer
Marks: 85%

-----------------------------
*/
