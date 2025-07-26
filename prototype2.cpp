//#include <bits/stdc++.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <limits>

using namespace std;

void mainMenu() {
    int choice;

    Admin HR;
    Employee emp;
    Client clnt;

    while (true) {
        cout << "\n========= Main Menu =========\n";
        cout << "1. HR Login\n";
        cout << "2. Employee Login\n";
        cout << "3. Client Login\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Flush input
            cout << "\n Invalid input! Please enter a valid number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                HR.HRMenu();
                break;
            case 2:
                emp.EmployeeMenu();
                break;
            case 3:
                clnt.ClientMenu();
                break;
            case 4:
                cout << "\n Exiting program!\n";
                return;
            default:
                cout << "\n Please enter a valid option (1-4).\n";
        }
    }
}

class Admin{

    char adminID[10];
    char adminName[20];
    char adminPassword[15];
    char adminContactNo[15];

public:

    Admin(){
        strcpy(adminID, "ADMIN00");
        strcpy(adminName, "Bhagwan");
        strcpy(adminPassword, "ADMIN@HRMS");
        strcpy(adminContactNo, "0000000000");
        // cLientConstructor();
    }

    string getAdminID(){
        string str = string(adminID);
        return str;
    }

    string getAdminName(){
        string str = string(adminName);
        return str;
    }

    string getAdminPassword(){
        string str = string(adminPassword);
        return str;
    }    

    string getAdminContactNo(){
        string str = string(adminContactNo);
        return str;
    }

    void HRMenu(){}

    void viewAdminProfile(){}

    void addNewAdmin(){}

    void showAllAdmins(){}

    void showAllEmployee(){}

    void addEmployee(){}

    void deleteEmployee(){}

    void updateEmployee(){}

    void approveLeave(){}

    void assignProjectToEmployee(){}

    void appoveSubmission(){}

    void viewAssignedprojects(){}

    void generateSalarySlip(){}

    void showAllClients(){}
        
    void generateQuotationforProject(){}

    void viewSalaryForEmployee(){}

};

class Employee{

    char empID[10];
    char empName[20];
    char empPassword[15];
    char empContactNo[15];

public:

    Employee(){
        strcpy(empID, "EMP000");
        strcpy(empName, "Employee");
        strcpy(empPassword, "employee@HRMS");
        strcpy(empContactNo, "0000000000");
        // employeeConstructor();
    }

    string getEmployeeID(){
        string str = string(empID);
        return str;
    }

    string getEmployeeName(){
        string str = string(empName);
        return str;
    }

    string getEmployeePassword(){
        string str = string(empPassword);
        return str;
    }

    string getEmployeeContactNo(){
        string str = string(empContactNo);
        return str;
    }    
   
    void EmployeeMenu(){}

    void viewProfile(){}

    void viewAssignedProjects(){}

    void ApplyforLeave(){}

    void submitWork(){}

    void generateSalarySlip(){}

    void discussProjecttoHR(){}

};

class Client{

    char clientID[10];
    char clientName[20];
    char clientPassword[15];
    char clientContactNo[15];

public:

    Client(){
        strcpy(clientID, "CLNT00");
        strcpy(clientName, "Bhagwan");
        strcpy(clientPassword, "client@HRMS");
        strcpy(clientContactNo, "0000000000");
        // cLientConstructor();
    }

    string getClientID(){
        string str = string(clientID);
        return str;
    }    

    string getClientName(){
        string str = string(clientName);
        return str;
    }

    string getClientPassword(){
        string str = string(clientPassword);
        return str;
    }    
 
    string getClientContactNo(){
        string str = string(clientContactNo);
        return str;
    }
    
    void ClientMenu(){}

    void viewMyProject(){}

};

int main(){
    // 1st Page
    mainMenu();

    return 0;
}

/*
BinaryFiles are : ADMIN, EMPLOYEE, PROJECTS, 
*/