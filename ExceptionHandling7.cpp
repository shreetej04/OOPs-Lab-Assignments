
/*
OOPS LAB ASSIGNMENT 7
Title: User-Defined Exception Handling

Problem Statement:
Create a C++ program using exception handling to
check the following conditions:

1. Age must be between 18 and 55.
2. Monthly income must be between Rs. 50,000
   and Rs. 1,00,000.
3. City must be Pune, Mumbai, Bangalore or Chennai.
4. User must own a 4-wheeler.

If any condition is not satisfied, throw an
exception and display an appropriate message.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int age, choice;
    float income;
    string city, vehicle;

    do
    {
        cout << "\n----- MAIN MENU -----";
        cout << "\n1. Check Eligibility";
        cout << "\n2. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "\nEnter age: ";
            cin >> age;

            cout << "Enter monthly income: ";
            cin >> income;

            cout << "Enter city: ";
            cin >> city;

            cout << "Do you have a 4-wheeler? (Yes/No): ";
            cin >> vehicle;

            try
            {
                if (age < 18 || age > 55)
                    throw age;

                if (income < 50000 || income > 100000)
                    throw income;

                if (city != "Pune" && city != "Mumbai" &&
                    city != "Bangalore" && city != "Chennai")
                    throw string("City");

                if (vehicle != "Yes" && vehicle != "yes")
                    throw string("Vehicle");

                cout << "\nDetails are valid!";
                cout << "\nAge: " << age;
                cout << "\nIncome: " << income;
                cout << "\nCity: " << city;
                cout << "\nVehicle: " << vehicle;
                cout << "\nUser profile verified successfully!";
            }

            catch (int)
            {
                cout << "\nException: Age must be between 18 and 55.";
            }

            catch (float)
            {
                cout << "\nException: Income must be between "
                     << "50000 and 100000.";
            }

            catch (string s)
            {
                if (s == "City")
                    cout << "\nException: Invalid City.";
                else
                    cout << "\nException: User must have a 4-wheeler.";
            }
        }

        else if (choice == 2)
        {
            cout << "\nExiting Program.";
        }

        else
        {
            cout << "\nInvalid Choice!";
        }

    } while (choice != 2);

    return 0;
}

/*
OUTPUT:

----- MAIN MENU -----
1. Check Eligibility
2. Exit
Enter choice: 1

Enter age: 21
Enter monthly income: 60000
Enter city: Pune
Do you have a 4-wheeler? (Yes/No): Yes

Details are valid!
Age: 21
Income: 60000
City: Pune
Vehicle: Yes
User profile verified successfully!

----- MAIN MENU -----
1. Check Eligibility
2. Exit
Enter choice: 1

Enter age: 21
Enter monthly income: 200000
Enter city: Pune
Do you have a 4-wheeler? (Yes/No): Yes

Exception: Income must be between 50000 and 100000.

----- MAIN MENU -----
1. Check Eligibility
2. Exit
Enter choice: 2

Exiting Program.
*/
