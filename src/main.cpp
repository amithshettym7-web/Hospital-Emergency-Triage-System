#include <iostream>
#include <limits>
#include "MinHeap.h"

using namespace std;

int main()
{
    MinHeap hospital;

    int choice;

    do
    {
        cout << "\n====================================\n";
        cout << " HOSPITAL EMERGENCY TRIAGE SYSTEM\n";
        cout << "====================================\n";

        cout << "1. Register Patient\n";
        cout << "2. Display Waiting Patients\n";
        cout << "3. Call Next Patient\n";
        cout << "4. Search Patient\n";
        cout << "5. Update Patient Priority\n";
        cout << "6. Display Next Patient\n";
        cout << "7. Exit\n";

        cout << "\nEnter your choice: ";

        if (!(cin >> choice))
        {
            cout << "Invalid input!\n";

            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            continue;
        }

        switch (choice)
        {
            case 1:
            {
                Patient p;

                cout << "Enter Patient ID: ";
                cin >> p.id;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Enter Patient Name: ";
                getline(cin, p.name);

                cout << "Enter Medical Condition: ";
                getline(cin, p.condition);

                cout << "Enter Priority (1-5): ";
                cin >> p.priority;

                if (p.priority < 1 || p.priority > 5)
                {
                    cout << "Priority must be between 1 and 5.\n";
                    break;
                }

                if (hospital.insertPatient(p))
                    cout << "\nPatient Registered Successfully!\n";
                else
                    cout << "\nRegistration Failed! Duplicate ID or heap full.\n";

                break;
            }

            case 2:
                hospital.displayPatients();
                break;

            case 3:
            {
                Patient p;

                if (hospital.removeNextPatient(p))
                {
                    cout << "\nPatient Called!\n";
                    cout << "Name: " << p.name << endl;
                    cout << "Condition: " << p.condition << endl;
                }
                else
                {
                    cout << "\nNo patients waiting!\n";
                }

                break;
            }

            case 4:
            {
                int id;

                cout << "Enter Patient ID: ";
                cin >> id;

                if (!hospital.searchPatient(id))
                    cout << "\nPatient Not Found!\n";

                break;
            }

            case 5:
            {
                int id, priority;

                cout << "Enter Patient ID: ";
                cin >> id;

                cout << "Enter New Priority (1-5): ";
                cin >> priority;

                if (priority < 1 || priority > 5)
                {
                    cout << "Invalid priority!\n";
                    break;
                }

                if (hospital.updatePriority(id, priority))
                    cout << "\nPriority Updated Successfully!\n";
                else
                    cout << "\nPatient Not Found!\n";

                break;
            }

            case 6:
                if (!hospital.displayNextPatient())
                    cout << "\nNo patients waiting!\n";

                break;

            case 7:
                cout << "\nThank you for using the system!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while (choice != 7);

    return 0;
}