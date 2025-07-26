#include <bits/stdc++.h>
#include <conio.h>

//Header File from MAIN Folder
#include "HRMSheader.h"

using namespace std;

/* OPERATIONAL FUNCTIONS */

void FirstMenu(){

    Admin Thekedar;
    Project_Client bhagwan;
    Employee karmchari;

    int choice;

    while (true) {
        cout << "\n========= Main Menu =========\n";
        cout << "1. HR Login\n";
        cout << "2. Employee Login\n";
        cout << "3. Client Login\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        // Input Validation
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            cout << "\nInvalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                Thekedar.AdminMenu();
                break;
            case 2:
                karmchari.employeeMenu();
                break;
            case 3:
                bhagwan.clientMenu();
                break;
            case 4:
                cout << "\nExiting program. Dhanyavaad 🙏\n";
                return;
            default:
                cout << "\nPlease enter a valid option (1-4).\n";
        }
    }
}

string getSafePassword(){
    string password;
    char ch;
    cout<<"Enter Password : ";
    while(true){
        ch = getch();
        if(ch == 13){
            break;
        }
        else if(ch == 8){
            if (!password.empty()) {
                password.pop_back();
                cout<<"\b \b";
            }
        }
        else{
        password += ch;
        cout<<"*";
        }
    }
    return password;
    // cout<<"\ngetSafePassword CALLED OUT";
}

/*  CLASSES  */
class Admin{

    char adminType[6]; // HR & ADMIN
    char adminID[10];
    char adminName[20];
    char adminPassword[13];
    char adminContactNo[11];

public:
/* Acessing Data Members from Public Functions */
    string getAdminID(){
        string str = string(adminID);
        return str;
    }
    string getAdminType(){
        string str = string(adminType);
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

/* ConsTructor */
    Admin(){
        strcpy(adminID, "AoHRMS00");
        strcpy(adminName, "AdminofHRMS");
        strcpy(adminPassword, "Admin@HRMS");
        strcpy(adminContactNo, "0000000000");
        strcpy(adminType, "ADMIN");
        addAdmin();
    }

    void AdminMenu(){}
    
    void addAdmin(){
        fstream fileOperator;
        fileOperator.open("ADMIN.dat", ios::app | ios::binary);

        fileOperator.write((char*)this, sizeof(*this));
        // cout << "Size of Admin at WRITTING: " << sizeof(*this) << endl;

        fileOperator.close();
    }

    void adminDetailsReadingfromFile(){
        fstream f;

        f.open("ADMIN.dat", ios::in | ios::binary);

        f.read((char*)this, sizeof(*this));
        showAdminDetailsOnScreen();
        // this->showAdminDetailsOnScreen();
        // cout << "Size of Admin at READING: " << sizeof(*this) << endl;

        f.close();
    }

    void showAdminDetailsOnScreen(){
        cout<<"ADMIN ID : "<<adminID<<endl;
        cout<<"\tTYPE \t\t: "<<adminType<<endl;
        cout<<"\tUserName \t: "<<adminName<<endl;
        cout<<"\tPassWord \t: "<<adminPassword<<endl;
        cout<<"\tContact no. \t: "<<adminContactNo<<endl;
    }

    void addAdminToFile(){
        string str = getSafePassword();
        cout<<str;
    }
};

class Employee{

    char empID[10];
    char empName[20];
    char empContactNo[11];
    char empPassword[10];
    char empAddress[20];
    char empType[9];

public:

    string getEmpID(){
        string str = string(empID);
        return str;
    }

    Employee(){
        strcpy(empID, "EoHRMS000");
        strcpy(empName, "EmployeeofHRMS");
        strcpy(empPassword, "Emp@HRMS");
        strcpy(empContactNo, "0000000000");
        strcpy(empType, "SENIOR");
        addEmployee();
    }

    void employeeMenu();

    void addEmployee(){
        fstream fileOperator;
        fileOperator.open("EMPLOYEE.dat", ios::app | ios::binary);
        fileOperator.write((char*)this, sizeof(*this));
        fileOperator.close();
    }

    void deleteEmployee(){

        Admin ADMIN;

        fstream fileOperator;
        
        string empID, password;
        bool isEmpFound = false;
        
        fileOperator.open("EMPLOYEE.dat", ios::in | ios::binary);

        cout<<"ENTER empID to delete Employee : ";

        getline(cin,empID);

        while(fileOperator.read((char*)this, sizeof(*this))){
            if(empID == getEmpID()){
                isEmpFound = true;
            }
        }
          fileOperator.close();

       if(isEmpFound){    
                cout<<"\nARE YOU SURE YOU WANT TO DELETE this Employee\n";
                password = getSafePassword();
                if(password == ADMIN.getAdminPassword()){
                    //Change ADMIN. to this->
                    string ID = getEmpID();
                    deleteEmployeeByEmpID(ID);
                    cout<<"\nEmployee DELETED\n";
                }else{
                    cout<<"\nWrong ADMIN PassWord\n";
                }
        }
        else{
            cout<<"No Employee Matches";
        }
    }

    void deleteEmployeeByEmpID(string ID){

        fstream f_read, f_write;
        f_read.open("EMPLOYEE.dat", ios::in | ios::binary );
        f_write.open("temp_data.dat", ios::out | ios::binary );
        while(f_read.read((char*)this, sizeof(*this))){
            if(ID != getEmpID()){
                f_write.write((char*)this, sizeof(*this));
            }
        }

        f_write.close();
        f_read.close();

        remove("EMPLOYEE.dat");        
        rename("temp_data.dat", "EMPLOYEE.dat");

    }

    void updateEmployee(){
        string empID, empName;
        fstream f_empFind;
        bool empFound = false;
        f_empFind.open("EMPLOYEE.dat", ios::in | ios::binary);

        cout<<"Enter EmployeeID :";
        getline(cin, empID);

        while(f_empFind.read((char*)this, sizeof(*this))){
            if(empID == getEmpID()){
                empFound = true;
            }
        }

        if(empFound){
            updateEmployeeFunction(empID);
        }else{
            cout<<"Employee Not Found!";
        }

        f_empFind.close(); 
    }

    void updateEmployeeFunction(string ID){
        fstream f;
        f.open("EMPLOYEE.dat", ios::in | ios::out | ios::binary);

        while(f.read((char*)this, sizeof(*this))){
            
        }

        f.close();
    }
};

class Project_Client{
    public:

    void clientMenu(){}

};

class Counter{
    
    int adminCount;
    int employeeCount;
    int projectCount;
    int clientCount;
    int billCount;
    // int noticeCount;
    // int brandCount;
    // int salarySlipCount;

public:

    int getAdminCount(){
        return adminCount;
    }
    int getEmployeeCount(){
        return employeeCount;
    }
    int getProjectCount(){
        return projectCount;
    }
    int getClientCount(){
        return clientCount;
    }
    int getbBillCount(){
        return billCount;
    }
    // int getNoticeCount(){
    //     return noticeCount;
    // }
    // int getBrandCount(){
    //     return brandCount;
    // }
    // int getSalarySlip(){
    //     return salarySlipCount;
    // }

    void adminCountUpdate(){
        fstream f;

    }
};

class Leave{};

class PayRoll{};

// class Performance{};

// class NoticeBoard{};

// class Attendance{};

int main(){

    FirstMenu();

    return 0;
}