//Program for Employee Management System
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <cstring>
#include <cstdio>
#include <unistd.h>
#include <ios>
#include <limits>
using namespace std;

class Person{//this class have required variables 
protected:

char name[30];
    char id[5];
    char designation[10];
    int age;
    int ctc;
    int experience;
};

class reqfunctions : protected Person

{//this class have required functions

protected:

    void waitForEnter()
    {
        cout << "\n\n\n Press enter to go back \n\n";
        cin.get();
        cin.get();
    }

    /////////////////////////////////////////////////////////////////////////////////////

    void listEmployees()
    {
        system("cls");
      
        FILE *file;
        file = fopen("data.txt", "r");
        cout << "\n\t      List of Employees\n";
        cout << "\n----------------------------------------------";
        cout << "\n NAME        |     ID     |     DESIGNATION\n";
        cout << "----------------------------------------------";

        while (fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0], &designation[0], &age, &ctc, &experience) != EOF)
            cout << "\n"
                 << name << "\t\t" << id << "\t\t" << designation;
        fclose(file);
        waitForEnter();
    }

    ///////////////////////////////////////////////////////////////////////////////////

    void showDetails()
    {
        system("cls");
       
        FILE *file;
        char checkId[5];
        cout << "\n\nEnter Employee ID: ";
        cin >> checkId;
        file = fopen("data.txt", "r");
        while (fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0], &designation[0], &age, &ctc, &experience) != EOF)
            if (strcmp(checkId, id) == 0)
            {
                cout << "\n---------------------";
                cout << "\nName: " << name;
                cout << "\n---------------------";
                cout << "\nId: " << id;
                cout << "\n---------------------";
                cout << "\nDesignation: " << designation;
                cout << "\n---------------------";
                cout << "\nAge: " << age;
                cout << "\n---------------------";
                cout << "\nCTC: " << ctc;
                cout << "\n---------------------";
                cout << "\nExperience: " << experience;
                cout << "\n---------------------";
            }
        fclose(file);
        waitForEnter();
    }

    ////////////////////////////////////////////////////////////////////////////////////

    void editExisting()
    {
        system("cls");
       
        char checkId[5];
        cout << "\nEnter employee id: ";
        cin >> checkId;
        char newDesignation[10];
        cout << "\n-----------------------------";
        cout << "\nEnter new designation: ";
        cin >> newDesignation;
        int newCtc;
        cout << "------------------------------";
        cout << "\nEnter new CTC: ";
        cin >> newCtc;
        FILE *file, *tempfile;
        file = fopen("data.txt", "r");
        tempfile = fopen("temp.txt", "w");
        while (fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0], &designation[0], &age, &ctc, &experience) != EOF)
        {
            if (strcmp(checkId, id) == 0)
                fprintf(tempfile, "%s %s %s %d %d %d \n", name, id, newDesignation, age, newCtc, experience);
            else
                fprintf(tempfile, "%s %s %s %d %d %d \n", name, id, designation, age, ctc, experience);
        }
        fclose(file);
        fclose(tempfile);
        int isRemoved = remove("data.txt");
        int isRenamed = rename("temp.txt", "data.txt");
        waitForEnter();
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////

    void addNewEmployee()
    { // adding records
        system("cls");
       
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n----------------------------------------";
        cout << "\n Enter First Name of Employee: ";
        cin >> name;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n----------------------------------------";
        cout << "\n Enter Employee ID [max 4 digits]: ";
        cin >> id;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n----------------------------------------";
        cout << "\n Enter Designation: ";
        cin >> designation;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n----------------------------------------";
        cout << "\n Enter Employee Age: ";
        cin >> age;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n----------------------------------------";
        cout << "\n Enter Employee CTC: ";
        cin >> ctc;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n----------------------------------------";
        cout << "\n Enter Employee Experience: ";
        cin >> experience;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n----------------------------------------";

        char ch;
        cout << "\nEnter 'y' to save above information\n";
        cin >> ch;
        if (ch == 'y')
        {
            FILE *file;
            file = fopen("data.txt", "a");
            fprintf(file, "%s %s %s %d %d %d \n", name, id, designation, age, ctc, experience);
            fclose(file);
            cout << "\nNew Employee has been added to database\n";
        }
        else
            addNewEmployee();
        waitForEnter();
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void deleteEmployeeDetails()
    { // removing records
        system("cls");
       
        char checkId[5];
        cout << "\n----------------------------------";
        cout << "\nEnter Employee Id To Remove: ";
        cin >> checkId;
        char ch;
        cout << "----------------------------------";
        cout << "\n\n\n\n\nCONFIRMATION\nEnter 'y' To Confirm Deletion \n";
        cin >> ch;
        if (ch == 'y')
        {
            FILE *file, *tempfile;
            file = fopen("data.txt", "r");
            tempfile = fopen("temp.txt", "w");
            while (fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0], &designation[0], &age, &ctc, &experience) != EOF)
                if (strcmp(checkId, id) != 0)
                    fprintf(tempfile, "%s %s %s %d %d %d \n", name, id, designation, age, ctc, experience);
            fclose(file);
            fclose(tempfile);
            int isRemoved = remove("data.txt");
            int isRenamed = rename("temp.txt", "data.txt");
            cout << "\nRemoved Successfully\n";
            waitForEnter();
        }
        else
            deleteEmployeeDetails();
    }
    /////////////////////////////////////////////////////////////////////////////////

    void options()
    {

        while (true)
        {
            system("cls");
           

            cout << "\n\t\t\t>>>>>>>>>  EMPLOYEE MANAGEMENT SYSTEM BY N&K <<<<<<<<<";
            cout << "\n";
            cout << "\n\t\t\t------------------------------------------------";
            cout << "\n\t\t\tENTER   1:   To View List of Employees";
            cout << "\n\t\t\t------------------------------------------------";
            cout << "\n\t\t\tENTER   2:   To View Employee Details";
            cout << "\n\t\t\t------------------------------------------------";
            cout << "\n\t\t\tENTER   3:   To Modify Existing Employee Details";
            cout << "\n\t\t\t------------------------------------------------";
            cout << "\n\t\t\tENTER   4:   To Add New Employee Details";
            cout << "\n\t\t\t------------------------------------------------";
            cout << "\n\t\t\tENTER   5:   To Remove an Employee Details";
            cout << "\n\t\t\t------------------------------------------------";
            cout << "\n\t\t\tENTER   0:   To Exit     ";
            cout << "\n\t\t\t------------------------------------------------";
            cout << "\n\n\t\t\t   Please Enter Your Choice: ";

            int choice;
            cin >> choice;

            switch (choice)
            {
                ////////////////////////////////////////////////////////////////
            case 0:
                system("CLS");

                cout << "\n\n///////////////////////////////// By Nishant & Karan ////////////////////////////////////////\n\n ";
                return;
                ///////////////////////////////////////////////////////////////
            case 1:
                listEmployees();
                break;
                //////////////////////////////////////////////////////////////
            case 2:
                showDetails();
                break;
                ////////////////////////////////////////////////////////////
            case 3:
                editExisting();
                break;
                ///////////////////////////////////////////////////////////
            case 4:
                addNewEmployee();
                break;
                /////////////////////////////////////////////////////////
            case 5:
                deleteEmployeeDetails();
                break;
                //////////////////////////////////////////////////////////
            default:
                cout << "\n Sorry! I don't understand that! \n";
                break;
            }
        }
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////

};

class Access : protected reqfunctions 

{//This class is used to get Access

public:
 
    void login()
    {
        string pass = "";
        char ch;
        cout << "\n\n\n\n\t\t\t\t\tEMPLOYEE MANAGEMENT SYSTEM";
        cout << "\n\n\n\n\n\t\t\t\t\tEnter Your Password :";
        ch = _getch();
        while (ch != 13)
        { // character 13 is enter
            pass.push_back(ch);
            cout << '*';
            ch = _getch();
        }

        if (pass == "nishant123")
        {
            cout << "\n\n\n\t\t\t\t\tLOADING \n\t\t\t\t\t";
            for (int a = 1; a < 8; a++)
            {
                cout << "...";
            }
            system("CLS");
           
            cout << "\n\n\n\t\t\t\t\tAccess Granted!! \n\n\n";

            system("PAUSE");
            system("CLS");
            
            options();
        }

        else
        {
            cout << "\nAccess Aborted...\n";
            login();
        }
    }

    /////////////////////////////////////////////////////////////////////////////////

};

int main()

{

    Access obj;
    obj.login();
    return 0;

}
