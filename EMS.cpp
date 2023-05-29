//Program for Employee Management System
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <cstring>
#include <cstdio>
#include <unistd.h>
#include <ios>
#include <limits>
#include <ctime>
#include <iomanip>

using namespace std;

class ReqVariables{//this class have required variables 
protected:

char name[30];
    char id[5];
    char designation[10];
    int age;
    int ctc;
    int experience;
};

class Reqfunctions : protected ReqVariables

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

    // Validate employee id
    while (strlen(checkId) != 4)
    {
        cout << "Invalid employee id. Please enter a 4-character id: ";
        cin >> checkId;
    }

    file = fopen("data.txt", "r");

    char name[100], id[5], designation[11];
    int age, ctc, experience;
    bool found = false;

    while (fscanf(file, "%s %s %s %d %d %d", name, id, designation, &age, &ctc, &experience) != EOF)
    {
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
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nEmployee with ID " << checkId << " not found.\n";
    }

    fclose(file);
    waitForEnter();
}

    ////////////////////////////////////////////////////////////////////////////////////

   
void editExisting() {
  system("cls");

  char checkId[5]; // Increase size to accommodate null character
  std::cout << "\nEnter employee id: ";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear any remaining newline characters
  std::cin.getline(checkId, 5);

  // Validate employee id
  while (strlen(checkId) != 4) {
    std::cout << "Invalid employee id. Please enter a 4-character id: ";
    std::cin.getline(checkId, 5);
  }

  char newDesignation[11]; // Increase size to accommodate null character
  std::cout << "\n-----------------------------";
  std::cout << "\nEnter new designation: ";
  std::cin.getline(newDesignation, 11);

  // Validate new designation
  while (strlen(newDesignation) > 10) {
    std::cout << "Invalid designation. Please enter a designation up to 10 characters long: ";
    std::cin.getline(newDesignation, 11);
  }

  int newCtc;
  std::cout << "------------------------------";
  std::cout << "\nEnter new CTC: ";
  while (!(std::cin >> newCtc) || newCtc < 0) {
    std::cout << "Invalid CTC. Please enter a valid numeric value: ";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  FILE* file, * tempfile;
  file = fopen("data.txt", "r");
  tempfile = fopen("temp.txt", "w");

  char name[100], id[5], designation[11];
  int age, ctc, experience;

  while (fscanf(file, "%s %s %s %d %d %d", name, id, designation, &age, &ctc, &experience) != EOF) {
    if (strcmp(checkId, id) == 0) {
      fprintf(tempfile, "%s %s %s %d %d %d\n", name, id, newDesignation, age, newCtc, experience);
    } else {
      fprintf(tempfile, "%s %s %s %d %d %d\n", name, id, designation, age, ctc, experience);
    }
  }

  fclose(file);
  fclose(tempfile);

  int isRemoved = remove("data.txt");
  int isRenamed = rename("temp.txt", "data.txt");
  waitForEnter();
}


    ///////////////////////////////////////////////////////////////////////////////////////////////////////////

    void addNewEmployee()
{
    system("cls");

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\n----------------------------------------";
    cout << "\n Enter First Name of Employee: ";
    cin.getline(name, 100);

    // Validate name
    while (strlen(name) == 0) {
        cout << "Invalid name. Please enter a valid name: ";
        cin.getline(name, 100);
    }

    cout << "\n----------------------------------------";
    cout << "\n Enter Employee ID [max 4 digits]: ";
    int id;
    while (!(cin >> id) || id < 0 || id > 9999) {
        cout << "Invalid ID. Please enter a valid 4-digit ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\n----------------------------------------";
    cout << "\n Enter Designation: ";
    cin.getline(designation, 11);

    // Validate designation
    while (strlen(designation) == 0) {
        cout << "Invalid designation. Please enter a valid designation: ";
        cin.getline(designation, 11);
    }

    cout << "\n----------------------------------------";
    cout << "\n Enter Employee Age: ";
    int age;
    while (!(cin >> age) || age < 0) {
        cout << "Invalid age. Please enter a valid non-negative numeric value: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "\n----------------------------------------";
    cout << "\n Enter Employee CTC: ";
    int ctc;
    while (!(cin >> ctc) || ctc < 0) {
        cout << "Invalid CTC. Please enter a valid non-negative numeric value: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "\n----------------------------------------";
    cout << "\n Enter Employee Experience: ";
    int experience;
    while (!(cin >> experience) || experience < 0) {
        cout << "Invalid experience. Please enter a valid non-negative numeric value: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\n----------------------------------------";

    char ch;
    cout << "\nEnter 'y' to save the above information\n";
    cin >> ch;
    if (ch == 'y')
    {
        FILE* file;
        file = fopen("data.txt", "a");
        fprintf(file, "%s %04d %s %d %d %d \n", name, id, designation, age, ctc, experience);
        fclose(file);
        cout << "\nNew Employee has been added to the database\n";
    }
    else
        options();
    waitForEnter();
}


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   void deleteEmployeeDetails()
{
    system("cls");

    char checkId[5];
    cout << "\n----------------------------------";
    cout << "\nEnter Employee Id To Remove: ";
    cin >> checkId;

    // Validate employee id
    while (strlen(checkId) != 4)
    {
        cout << "Invalid employee id. Please enter a 4-character id: ";
        cin >> checkId;
    }

    char ch;
    cout << "----------------------------------";
    cout << "\n\n\n\n\nCONFIRMATION\nEnter 'y' To Confirm Deletion \n";
    cin >> ch;

    if (ch == 'y')
    {
        FILE *file, *tempfile;
        file = fopen("data.txt", "r");
        tempfile = fopen("temp.txt", "w");

        char name[100], id[5], designation[11];
        int age, ctc, experience;

        while (fscanf(file, "%s %s %s %d %d %d", name, id, designation, &age, &ctc, &experience) != EOF)
        {
            if (strcmp(checkId, id) != 0)
                fprintf(tempfile, "%s %s %s %d %d %d \n", name, id, designation, age, ctc, experience);
        }

        fclose(file);
        fclose(tempfile);

        int isRemoved = remove("data.txt");
        int isRenamed = rename("temp.txt", "data.txt");

        cout << "\nRemoved Successfully\n";
        waitForEnter();
    }
    else
        options();
}
/////////////////////////////////////////////////////////////////////////////////

void loadingScreen() {
    for (int i = 0; i <= 1; i++) {
        system("cls");
        cout << "Loading.";
        sleep(1);
        system("cls");

        cout << "Loading..";
        sleep(1);
        system("cls");

        cout << "Loading...";
        sleep(1);
        system("cls");

        cout << "Loading....";
        sleep(1);
        system("cls");

    }
}

    /////////////////////////////////////////////////////////////////////////////////

void options()
{
    while (true)
    {
        system("cls");

        // Get the current time
        std::time_t currentTime = std::time(0);
        char* timeStr = std::ctime(&currentTime);

        std::cout << "\n\t\t\t>>>>>>>>>  EMPLOYEE MANAGEMENT SYSTEM BY N&K <<<<<<<<<";
        std::cout << "\n";
        std::cout << "\n\t\t\t------------------------------------------------";
        std::cout << "\n\t\t\tTime: " << std::setw(20) << std::left << timeStr; // Left-align the time
        std::cout << "\n\t\t\t------------------------------------------------";
        std::cout << "\n\t\t\tENTER   1:   To View List of Employees";
        std::cout << "\n\t\t\t------------------------------------------------";
        std::cout << "\n\t\t\tENTER   2:   To View Employee Details";
        std::cout << "\n\t\t\t------------------------------------------------";
        std::cout << "\n\t\t\tENTER   3:   To Modify Existing Employee Details";
        std::cout << "\n\t\t\t------------------------------------------------";
        std::cout << "\n\t\t\tENTER   4:   To Add New Employee Details";
        std::cout << "\n\t\t\t------------------------------------------------";
        std::cout << "\n\t\t\tENTER   5:   To Remove an Employee Details";
        std::cout << "\n\t\t\t------------------------------------------------";
        std::cout << "\n\t\t\tENTER   0:   To Exit     ";
        std::cout << "\n\t\t\t------------------------------------------------";
        std::cout << std::setw(56) << std::right << "By Nishant & Karan"; // Right-align the trademark
        std::cout << "\n\n\t\t\t   Please Enter Your Choice: ";

        int choice;
        std::cin >> choice;

        // Validate the choice
        while (choice < 0 || choice > 5)
        {
            std::cout << "Invalid choice. Please enter a valid option: ";
            std::cin >> choice;
        }

        switch (choice)
        {
            ////////////////////////////////////////////////////////////////
            case 0:
                system("CLS");
                std::cout << "\n\n///////////////////////////////// By Nishant & Karan ////////////////////////////////////////\n\n ";
                return;
            ///////////////////////////////////////////////////////////////
            case 1:
            loadingScreen();
                listEmployees();
                break;
            //////////////////////////////////////////////////////////////
            case 2:
            loadingScreen();
                showDetails();
                break;
            ////////////////////////////////////////////////////////////
            case 3:
            loadingScreen();
                editExisting();
                break;
            ///////////////////////////////////////////////////////////
            case 4:
            loadingScreen();
                addNewEmployee();
                break;
            /////////////////////////////////////////////////////////
            case 5:
            loadingScreen();
                deleteEmployeeDetails();
                break;
            //////////////////////////////////////////////////////////
            default:
                std::cout << "\n Sorry! I don't understand that! \n";
                break;
        }
    }
}

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////

};

class Access : protected Reqfunctions

{//This class is used to get Access

public:
 
    void login()
    {
    system("cls");
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
            loadingScreen();
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
