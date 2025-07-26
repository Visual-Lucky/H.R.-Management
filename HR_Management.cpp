#include <windows.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <conio.h> 
#include <cstdlib>  
#include <limits>
#include <ctime> 
#include <string>

//mera Header
#include "HRMSheader.h"

using namespace std;

void whatSuperAdminMANIPULATES();
void whatAdminDOES();
void whatEmployeeDOES();
void whatClientDOES();

class SuperAdmin {

    char Name[20];
    char Password[20];
    char SpecialWord[20];

public:

    ~SuperAdmin(){}

    SuperAdmin() {
        strcpy(Name, "Lucky");
        strcpy(Password, "L&b@1234");
        strcpy(SpecialWord, "GEETA");
    }

    string getName() { return string(Name); }
    string getPassword() { return string(Password); }
    string getSpecialWord() { return string(SpecialWord); }

    void SuperAdminDetails(){
        cout<<"NAME         : "<<getName()<<endl;
        cout<<"PASSWORD     : ********"<<endl;
        cout<<"SPECIAL WORD : "<<getSpecialWord()<<endl;
    }

    bool AuthenticateSuperAdmin() {

        string name, password, specialword;

        cout << "Enter Name: ";
        getline(cin, name);
        if (name != getName()) {
            cout << "\n\033[1;31mName doesn't match\033[0m\n";
            return false;
        }

        password = getSafePassword();
        if (password != getPassword()) {
            cout << "\n\033[1;31mPassword doesn't match\033[0m\n";
            return false;
        }

        specialword = getEnterSpecialWord();
        if (specialword != getSpecialWord()) {
            cout << "\n\033[1;31mSpecial Word doesn't match\033[0m\n";
            return false;
        }

        cout << "\n\033[1;32mAuthentication Successful\033[0m\n";
        return true;
    }

    void SuperMenu() {
        cout << "Welcome to the SuperAdmin Menu (Coming Soon!)\n";
    }

};

class Company {

    string companyName;
    string companyAddress;
    string companyContact;
    string companyEmail;

public:

    ~Company(){}

    Company() {
        companyName = "Shree Geeta Infotech";
        companyAddress = "286, Ajmer-Road, Bhilwara, Rajasthan[311001]";
        companyContact = "+91-7849998407";
        companyEmail = "info@shreeGEETAinfotech.in";
    }

    string getCompanyName(){return companyName;}
    string getCompanyAddress(){return companyAddress;}
    string getCompanyContact(){return companyContact;}
    string getCompanyEmail(){return companyEmail;}

    void displayCompanyInfo() {
        cout << "\n\033[1;34m============================================\033[0m\n";
        cout << "\033[1;33m            ✦ Company Information ✦        \033[0m\n";
        cout << "\033[1;34m============================================\033[0m\n";

        cout << "\033[1;36mName     :\033[0m "    << companyName    << endl;
        cout << "\033[1;36mAddress  :\033[0m "    << companyAddress << endl;
        cout << "\033[1;36mContact  :\033[0m "    << companyContact << endl;
        cout << "\033[1;36mEmail    :\033[0m "    << companyEmail   << endl;

        cout << "\033[1;34m============================================\033[0m\n";
    }
    
};

class Employee {

    char empID[10];
    char empName[20];
    char empPassword[20];
    char empContactNo[20];
    char empType[10]; 
    char empEmail[30];
    char empAddress[50];
    char empDOB[12];
    char empGender[10];
    char empDepartment[20];
    char empJoinDate[12];
    char empStatus[10];
    int  daysPresent = 0;
    char lastSalaryMonth[15];

public:

    string getEmpID() { return string(empID); }
    string getEmpName() { return string(empName); }
    string getEmpPassword() { return string(empPassword); }
    string getEmpContactNo() { return string(empContactNo); }
    string getEmpType(){ return string(empType);}
    string getEmpEmail(){ return string(empEmail);}
    string getEmpAddress(){ return string(empAddress);}
    string getEmpDOB(){ return string(empDOB);}
    string getEmpGender(){ return string(empGender);}
    string getEmpDepartment(){ return string(empDepartment);}
    string getEmpJoinDate(){ return string(empJoinDate);}
    string getEmpStatus(){ return string(empStatus);}

    //SHIVA
    ~Employee(){}

    //BRAHMA
    Employee() {
        strcpy(empID, "SGIe000");
        strcpy(empName, "employeeSGI");
        strcpy(empPassword, "emp@SGI");
        strcpy(empContactNo, "0000000000");
        strcpy(empEmail, "employee@sgi.ac.in");
        strcpy(empAddress, "H.No.286,Block-15,Labour Colony,Bhilwara[311001]");
        strcpy(empDOB, "05-01-2003");
        strcpy(empGender, "MALE");
        strcpy(empDepartment, "UI-UX");
        strcpy(empJoinDate, "26-07-2025");
        strcpy(empStatus, "ACTIVE");
        strcpy(empType, "SENIOR");
        strcpy(lastSalaryMonth, "");
    }

    //VISHNU

    void generateAllMonthlySalaries() {
        Employee emp;
        fstream fin("EMPLOYEE.dat", ios::in | ios::out | ios::binary);

        while (fin.read((char*)&emp, sizeof(emp))) {
            emp.autoGenerateMonthlySalary();
            int pos = fin.tellg() - static_cast<int>(sizeof(emp));
            fin.seekp(pos);
            fin.write((char*)&emp, sizeof(emp));
        }

        fin.close();
    }

    void autoGenerateMonthlySalary() {
    // Get current system month like "July2025"
        time_t t = time(0);
        tm *now = localtime(&t);
        char currentMonth[15];
        strftime(currentMonth, 15, "%B%Y", now); // e.g., "July2025"

        if (strcmp(currentMonth, lastSalaryMonth) == 0) {
            return; // Already generated for this month
        }

        // Define base salary per type
        int basePay = 0;
        if (strcmp(empType, "INTERN") == 0) basePay = 15000;
        else if (strcmp(empType, "JUNIOR") == 0) basePay = 25000;
        else if (strcmp(empType, "SENIOR") == 0) basePay = 40000;

        // Assume 26 working days
        int totalDays = 26;
        float perDay = basePay / (float)totalDays;
        float earned = daysPresent * perDay;

        // Save to SALARY.dat
        ofstream fout("SALARY.dat", ios::binary | ios::app);
        fout << "\nEmpID: " << empID
            << "\nMonth: " << currentMonth
            << "\nDays Present: " << daysPresent
            << "\nTotal Salary: ₹" << fixed << setprecision(2) << earned << "\n\n";
        fout.close();

        // Reset attendance and update month
        daysPresent = 0;
        strcpy(lastSalaryMonth, currentMonth);

        cout << "\nMonthly salary generated for: " << currentMonth
            << "\nAmount: ₹" << fixed << setprecision(2) << earned << "\n";
}

    void addEmployeeConstructorsValuetoFile(){
        fstream fileOperator;
        fileOperator.open("EMPLOYEE.dat", ios::out | ios::binary);
        fileOperator.write((char*)this, sizeof(*this));
        fileOperator.close();
    }

    void EmployeeMenu(){
        
        Employee emp;
        int choice;

        while (true) {
            system("cls"); 
            cout << "\n========== Employee Management Menu ==========\n";
            cout << "1. View All Employees\n";
            cout << "2. Add Employee\n";
            cout << "3. Delete Employee\n";
            cout << "4. Update Employee\n";
            cout << "5. Update Password\n";
            cout << "6. Full Fledged Employee Details\n";
            cout << "7. Logout\n";
            cout << "Enter Your Choice: ";
            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a number.\n";
                Sleep(2000);
                continue;
            }
                cin.ignore();

            switch (choice) {

                case 1: system("cls"); 
                    emp.showAllEmployee();
                    cout<<"Redirecting to EMPLOYEE Menu in 10 Seconds"; 
                    Sleep(10000);
                    break;

                case 2: system("cls");  
                    emp.addEmployeetoFile(); 
                    cout<<"Redirecting to EMPLOYEE Menu in 5 Seconds"; 
                    Sleep(5000);
                    break;

                case 3: system("cls");
                    emp.deleteEmployee(); 
                    cout<<"Redirecting to EMPLOYEE Menu in 5 Seconds"; 
                    Sleep(5000);
                    break;

                case 4: system("cls");
                    emp.updateEmployee(); 
                    cout<<"Redirecting to EMPLOYEE Menu in 5 Seconds"; 
                    Sleep(5000);
                    break;

                case 5: system("cls");
                    emp.updateEmployeePassword(); 
                    cout<<"Redirecting to EMPLOYEE Menu in 5 Seconds"; 
                    Sleep(5000);
                    break;

                case 6: system("cls");
                    emp.allEmployeesFullDetails(); 
                    cout<<"Redirecting to EMPLOYEE Menu in 10 Seconds"; 
                    Sleep(10000);
                    break;

                case 7: cout<<"\nTQ for Coming!\n";
                    return;
                default: cout << "Invalid Choice!\n"; 
                cout<<"Retrying in 3 Seconds"; 
                    Sleep(3000);
                    break;
            }
        }

    }

    bool authenticateEmployee() {
        fstream fileOperator;
        fileOperator.open("EMPLOYEE.dat", ios::in | ios::binary);

        if (!fileOperator) {
            cout << "\n\033[1;31mError opening EMPLOYEE.dat file\033[0m\n";
            return false;
        }

        string userID;
        cout << "\nEnter Employee ID : ";
        getline(cin, userID);

        bool authenticated = false;

        while (fileOperator.read((char*)this, sizeof(*this))) {
            if (userID == getEmpID()) {
                string password = getSafePassword();  // Masked password input
                if (password == getEmpPassword()) {
                    cout << "\n\033[1;32mAuthentication Successful\033[0m\n";
                    authenticated = true;
                } else {
                    cout << "\n\033[1;31mIncorrect Password\033[0m\n";
                }
                break; // ID matched, no need to keep looping
            }
        }

        fileOperator.close();

        if (!authenticated && userID != getEmpID()) {
            cout << "\n\033[1;31mEmployee Not Found\033[0m\n";
        }

        return authenticated;
    }

    void displayEmployeeProfile() {
        cout << "\n=====================================\n";
        cout << "         EMPLOYEE PROFILE\n";
        cout << "=====================================\n";
        cout << left << setw(18) << "Employee ID"    << ": " << empID << endl;
        cout << left << setw(18) << "Name"           << ": " << empName << endl;
        cout << left << setw(18) << "Type"           << ": " << empType << endl;
        cout << left << setw(18) << "Contact No"     << ": " << empContactNo << endl;
        cout << left << setw(18) << "Email"          << ": " << empEmail << endl;
        cout << left << setw(18) << "Address"        << ": " << empAddress << endl;
        cout << left << setw(18) << "Date of Birth"  << ": " << empDOB << endl;
        cout << left << setw(18) << "Gender"         << ": " << empGender << endl;
        cout << left << setw(18) << "Department"     << ": " << empDepartment << endl;
        cout << left << setw(18) << "Join Date"      << ": " << empJoinDate << endl;
        cout << left << setw(18) << "Status"         << ": " << empStatus << endl;
        cout << left << setw(18) << "PassWord"       << ": " << calculatePassLength() << endl;
        cout << "=====================================\n";
    }

    void addEmployeetoFile() {

        fstream f;
        f.open("EMPLOYEE.dat", ios::app | ios::binary);

        takeEmployeeDetails();

        // Auto-generate empID with 3-digit number
        int count = 1;
        Employee temp;
        fstream fCount("EMPLOYEE.dat", ios::in | ios::binary);
        while (fCount.read((char*)&temp, sizeof(temp))) {
            count++;
        }
        fCount.close();

        ostringstream oss;
        oss << "SGIe" << setw(3) << setfill('0') << count;
        string newID = oss.str();
        strcpy(empID, newID.c_str());

        f.write((char*)this, sizeof(*this));
        f.close();

        cout << "Employee Added Successfully with ID: " << empID << endl;
    }

    void takeEmployeeDetails() {

        //cin.ignore();

        cout << "Enter Name            : ";
        cin.getline(empName, 20);

        cout << "Enter Password        : ";
        cin.getline(empPassword, 20);

        cout << "Enter Contact No      : ";
        cin.getline(empContactNo, 20);

        cout << "Enter Email           : ";
        cin.getline(empEmail, 30);

        cout << "Enter Address         : ";
        cin.getline(empAddress, 50);

        cout << "Enter DOB (DD-MM-YYYY): ";
        cin.getline(empDOB, 12);

        cout << "Enter Gender          : ";
        cin.getline(empGender, 10);

        cout << "Enter Department      : ";
        cin.getline(empDepartment, 20);

        cout << "Enter Join Date (DD-MM-YYYY)   : ";
        cin.getline(empJoinDate, 12);

        cout << "Enter Status (e.g., Active/Inactive): ";
        cin.getline(empStatus, 10);

        cout << "Enter Type (e.g., Senior/Junior/Intern): ";
        cin.getline(empType, 15); 

    }

    void deleteEmployee() {

        fstream fileOperator;
        string idToDelete;
        bool isEmpFound = false;

        cout << "Enter Employee ID to delete: ";
        getline(cin, idToDelete);

        fileOperator.open("EMPLOYEE.dat", ios::in | ios::binary);
        while (fileOperator.read((char*)this, sizeof(*this))) {
            if (idToDelete == getEmpID()) {
                isEmpFound = true;
                break;
            }
        }
        fileOperator.close();

        if (isEmpFound)
            deleteEmployeeByEmpID(idToDelete);
        else
            cout << "No Employee Matches.\n";
    }

    void deleteEmployeeByEmpID(string ID) {
        fstream f_read, f_write;
        f_read.open("EMPLOYEE.dat", ios::in | ios::binary);
        f_write.open("temp_data.dat", ios::out | ios::binary);

        while (f_read.read((char*)this, sizeof(*this))) {
            if (ID != getEmpID()) {
                f_write.write((char*)this, sizeof(*this));
            }
        }

        f_read.close();
        f_write.close();
        remove("EMPLOYEE.dat");
        rename("temp_data.dat", "EMPLOYEE.dat");
        cout << "Employee Deleted Successfully.\n";
    }

    void updateEmployee() {
        
        string empIDInput;
        fstream f_empFind;

        bool empFound = false;
        int counter = 0;

        //cin.ignore();
        cout << "Enter Employee ID to update: ";
        getline(cin, empIDInput);

        Employee temp;

        f_empFind.open("EMPLOYEE.dat", ios::in | ios::binary);
        while (f_empFind.read((char*)&temp, sizeof(temp))) {
            counter++;
            if (empIDInput == temp.getEmpID()) {
                empFound = true;
                break;
            }
        }
        f_empFind.close();

        if (empFound) {
            updateEmployeeFunction(counter);
        } else {
            cout << "Employee Not Found.\n";
        }
    }

    void updateEmployeeFunction(int counter) {

        fstream f;
        f.open("EMPLOYEE.dat", ios::in | ios::out | ios::binary);
        f.seekp((counter - 1) * sizeof(Employee), ios::beg);

        takingEmployeeInputforUpdation();

        f.write((char*)this, sizeof(*this));
        f.close();
        cout << "Employee Updated Successfully.\n";
    }

    void takingEmployeeInputforUpdation() {

        cout << "Enter New Name         : ";
        cin.getline(empName, 20);

        cout << "Enter New Password     : ";
        cin.getline(empPassword, 20);

        cout << "Enter New Contact No   : ";
        cin.getline(empContactNo, 20);

        cout << "Enter New Email        : ";
        cin.getline(empEmail, 30);

        cout << "Enter New Address      : ";
        cin.getline(empAddress, 50);

        cout << "Enter New Date of Birth (DD-MM-YYYY): ";
        cin.getline(empDOB, 12);

        cout << "Enter New Gender       : ";
        cin.getline(empGender, 10);

        cout << "Enter New Department   : ";
        cin.getline(empDepartment, 20);

        // cout << "Enter New Join Date (DD-MM-YYYY)   : ";
        // cin.getline(empJoinDate, 12);

        cout << "Enter New Status (Active/Inactive): ";
        cin.getline(empStatus, 10);

        cout << "Enter New Employee Type(eg. Senior, Junior) : ";
        cin.getline(empType, 10);

    }

    void updateEmployeePassword() {

        string oldPassword = getSafePassword();
        fstream f;
        bool passAuthenticated = false;
        int counter = 0;

        Employee emp;

        f.open("EMPLOYEE.dat", ios::in | ios::binary);
        while (f.read((char*)&emp, sizeof(emp))) {
            counter++;
            if (oldPassword == emp.getEmpPassword()) {
                passAuthenticated = true;
                break;
            }
        }
        f.close();

        if (passAuthenticated) {
            cout << "\nEnter New Password: ";
            //cin.ignore();
            cin.getline(empPassword, 20); 

            // Update file
            f.open("EMPLOYEE.dat", ios::in | ios::out | ios::binary);
            f.seekp((counter - 1) * sizeof(*this), ios::beg);
            f.write((char*)this, sizeof(*this)); 
            f.close();

            cout << "Password Updated Successfully!\n";
        } else {
            cout << "\nIncorrect Password!\n";
        }
    }

    void showAllEmployee() {
        fstream f;
        f.open("EMPLOYEE.dat", ios::in | ios::binary);
        system("cls");
        printEmployeeHeader();
        while (f.read((char*)this, sizeof(*this))) {
            printEmployees();
        }
        f.close();
    }

    void printEmployeeHeader() {

        cout << "\n"
            << "-----------------------------------------------------------------------------------------\n"
            << "| " << left << setw(10) << "Emp ID"
            << "| " << left << setw(20) << "Name"
            << "| " << left << setw(20) << "Department"
            << "| " << left << setw(15) << "Contact No"
            << "| " << left << setw(10) << "Status"
            << "|\n"
            << "-----------------------------------------------------------------------------------------\n";
    }

    void printEmployees() {

        cout << "| " << left << setw(10) << empID
            << "| " << left << setw(20) << empName
            << "| " << left << setw(20) << empDepartment
            << "| " << left << setw(15) << empContactNo
            << "| " << left << setw(10) << empStatus
            << "|\n"
            << "-----------------------------------------------------------------------------------------\n";
    }

    void allEmployeesFullDetails(){
        fstream f;
        f.open("EMPLOYEE.dat", ios::in | ios::binary);
        system("cls");
        printFullEmployeeHeader();
        while (f.read((char*)this, sizeof(*this))) {
            printFullEmployee();
        }
        f.close();
    }

    void printFullEmployeeHeader() {

        cout << "\n"
            << "----------------------------------------------------------------------------------------------------\n"
            << "| " << left << setw(8)  << "Emp ID"
            << "| " << setw(12) << "Name"
            << "| " << setw(8)  << "Pwd"
            << "| " << setw(12) << "Contact"
            << "| " << setw(18) << "Email"
            << "| " << setw(10) << "DOB"
            << "| " << setw(4)  << "Gen"
            << "| " << setw(10) << "Dept"
            << "| " << setw(10) << "JoinDate"
            << "| " << setw(8)  << "Status"
            << "|\n"
            << "----------------------------------------------------------------------------------------------------\n";
    }

    void printFullEmployee() {
        cout << "| " << left << setw(8)  << empID
            << "| " << setw(12) << empName
            << "| " << setw(8)  << calculatePassLength()
            << "| " << setw(12) << empContactNo
            << "| " << setw(18) << empEmail
            << "| " << setw(10) << empDOB
            << "| " << setw(4)  << empGender
            << "| " << setw(10) << empDepartment
            << "| " << setw(10) << empJoinDate
            << "| " << setw(8)  << empStatus
            << "|\n"
            << "----------------------------------------------------------------------------------------------------\n";
    }

    string calculatePassLength(){ 
        int length = 0;
        while (empPassword[length] != '\0') {
            length++;
        }
         return string(length, '*'); 
    }

    void viewClientDetails(){
        fstream f;
        string empid = getEmpID();
        
    }
};

class Admin{

    char adminID[10];
    char adminName[20];
    char adminPassword[20];
    char adminContactNo[20];
    char adminEmail[30];
    char adminAddress[50];
    char adminDOB[12];
    char adminGender[10];
    char adminRole[20];
    char adminJoinDate[12];
    char adminStatus[10];

public:
    string getAdminID() { return string(adminID); }
    string getAdminName() { return string(adminName); }
    string getAdminPassword() { return string(adminPassword); }
    string getAdminContactNo() { return string(adminContactNo); }
    string getAdminEmail(){ return string(adminEmail);}
    string getAdminAddress(){ return string(adminAddress);}
    string getAdminDOB(){ return string(adminDOB);}
    string getAdminGender(){ return string(adminGender);}
    string getAdminRole(){ return string(adminRole);}
    string getAdminJoinDate(){ return string(adminJoinDate);}
    string getAdminStatus(){ return string(adminStatus);}

    //SHIVA
    ~Admin(){}

    //BRAHMA
    Admin() {
        strcpy(adminID, "SGIa00");
        strcpy(adminName, "adminofSGI");
        strcpy(adminPassword, "admin@SGI");
        strcpy(adminContactNo, "0000000000");
        strcpy(adminEmail, "Admin@SGI.ac.in");
        strcpy(adminAddress, "S-15/286, Labour Colony, Bhilwara[311001]");
        strcpy(adminDOB, "03-01-2005");
        strcpy(adminGender, "FEMALE");
        strcpy(adminRole, "SENIOR DEV.");
        strcpy(adminJoinDate, "26-07-2025");
        strcpy(adminStatus, "ACTIVE");
    }

    //VISHNU
    void addAdminConstructorsValuetoFile(){
        fstream fileOperator;
        fileOperator.open("ADMIN.dat", ios::out | ios::binary);
        fileOperator.write((char*)this, sizeof(*this));
        fileOperator.close();
    }

    void AdminMenu(){
        
        Admin HR;
        int choice;

        while (true) {
            system("cls"); 
            cout << "\n========== ADMIN Management Menu ==========\n";
            cout << "1. View All Admin\n";
            cout << "2. Add Admin\n";
            cout << "3. Delete Admin\n";
            cout << "4. Update Admin\n";
            cout << "5. Update Password\n";
            cout << "6. Show Full-Fledeged Admin Details\n";
            cout << "7. Exit\n";
            cout << "Enter Your Choice: ";
            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a number.\n";
                Sleep(2000);
                continue;
            }
                cin.ignore();

            switch (choice) {

                case 1: system("cls"); 
                    HR.showAllAdmin();
                    cout<<"Redirecting to ADMIN Menu in 10 Seconds"; 
                    Sleep(10000);
                    break;

                case 2: system("cls");  
                    HR.addAdminToFile(); 
                    cout<<"Redirecting to ADMIN Menu in 5 Seconds"; 
                    Sleep(5000);
                    break;
                    
                case 3: system("cls");
                    HR.deleteAdmin(); 
                    cout<<"Redirecting to ADMIN Menu in 5 Seconds"; 
                    Sleep(5000);
                    break;

                case 4: system("cls");
                    HR.updateAdmin(); 
                    cout<<"Redirecting to ADMIN Menu in 5 Seconds"; 
                    Sleep(5000);
                    break;

                case 5: system("cls");
                    HR.updateAdminPassword(); 
                    cout<<"Redirecting to ADMIN Menu in 5 Seconds"; 
                    Sleep(5000);
                    break;

                case 6: system("cls");
                    HR.showFullFledgedAdminDetails();
                    cout<<"Redirecting to ADMIN Menu in 10 Seconds"; 
                    Sleep(10000);  
                    break;

                case 7: cout<<"TQ for Coming!";
                    return;

                default: cout << "Invalid Choice!\n"; 
                cout<<"Redirecting to ADMIN Menu in 5 Seconds"; 
                    Sleep(5000);
                    break;
            }
        }

    }

    void viewAdminProfile() {
        // system("cls");

        cout << "\n====================== Admin Profile ======================\n";
        cout << "Admin ID        : " << adminID << "\n";
        cout << "Name            : " << adminName << "\n";
        cout << "Contact No      : " << adminContactNo << "\n";
        cout << "Email           : " << adminEmail << "\n";
        cout << "Address         : " << adminAddress << "\n";
        cout << "Date of Birth   : " << adminDOB << "\n";
        cout << "Gender          : " << adminGender << "\n";
        cout << "Role/Department : " << adminRole << "\n";
        cout << "Joining Date    : " << adminJoinDate << "\n";
        cout << "Status          : " << adminStatus << "\n";
        cout << "Password        : " << calculatePassLength() << "\n";
        cout << "===========================================================\n";
    }

    bool authenticateAdmin() {
        fstream fileOperator;
        fileOperator.open("ADMIN.dat", ios::in | ios::binary);

        if (!fileOperator) {
            cout << "\n\033[1;31mError: Could not open ADMIN.dat file\033[0m \n";
            return false;
        }

        string userID;
        cout << "\nEnter ADMIN ID : ";
        getline(cin, userID);

        bool authenticated = false;

        while (fileOperator.read((char*)this, sizeof(*this))) {
            if (userID == getAdminID()) {
                string password = getSafePassword();
                if (password == getAdminPassword()) {
                    cout << "\n\033[1;32mAuthentication Successful\033[0m\n";
                    authenticated = true;
                } else {
                    cout << "\n\033[1;31mIncorrect Password\033[0m\n";
                }
                break;
            }
        }

        fileOperator.close();

        if (!authenticated && userID != getAdminID()) {
            cout << "\n\033[1;31mAdmin Not Found\033[0m\n";
        }

        return authenticated;
    }

    void addAdminToFile() {

        fillAdminDetails(); 

        fstream f("ADMIN.dat", ios::in | ios::binary);
        int lastID = 0;
        Admin HR;

        if (f) {
            f.seekg(0, ios::end);
            int size = f.tellg();
            if (size >= sizeof(Admin)) {
                f.seekg(-sizeof(Admin), ios::end);
                f.read((char*)&HR, sizeof(Admin));

                // Extract number from ID like "SGIa05"
                string lastStr = HR.adminID;
                lastID = stoi(lastStr.substr(4));  // Get '05' -> 5
            }
            f.close();
        }

        // Step 3: Generate new ID
        stringstream ss;
        if(getAdminRole() == "Human Resources" || getAdminRole() == "H.R." || getAdminRole() == "HR" || getAdminRole() == "hr" || getAdminRole() == "human resources"){
            ss << "SGIh" << setw(2) << setfill('0') << (lastID + 1);
        }
        else{
            ss << "SGIa" << setw(2) << setfill('0') << (lastID + 1);
        }
        strcpy(adminID, ss.str().c_str());

        // Step 4: Write new admin to file
        fstream out("ADMIN.dat", ios::app | ios::binary);
        out.write((char*)this, sizeof(*this));
        out.close();

        cout << "Admin Added Successfully with ID: " << adminID << endl;
    }

    void fillAdminDetails() {
        cout<<"Enter New Admin Details\n";
        cout << "Enter Name: "; cin.getline(adminName, 20);
        cout << "Enter Password: "; cin.getline(adminPassword, 20);
        cout << "Enter Contact No: "; cin.getline(adminContactNo, 20);
        cout << "Enter Email: "; cin.getline(adminEmail, 30);
        cout << "Enter Address: "; cin.getline(adminAddress, 50);
        cout << "Enter DOB (DD-MM-YYYY): "; cin.getline(adminDOB, 12);
        cout << "Enter Gender: "; cin.getline(adminGender, 10);
        cout << "Enter Role: "; cin.getline(adminRole, 20);
        cout << "Enter Joining Date: "; cin.getline(adminJoinDate, 12);
        strcpy(adminStatus, "Active"); 
    }

    void showAllAdmin(){
        fstream f;
        f.open("ADMIN.dat", ios::in | ios::binary);
        system("cls");
        printAdminHeader();
        while (f.read((char*)this, sizeof(*this))) {
            printAdmin();
        }
        f.close();
    }

    void printAdminHeader() {
        string l1(100, '-');
        cout<<l1<<endl;
        cout << "| " << left << setw(10) << "Admin ID"
            << "| " << setw(20) << "Name"
            << "| " << setw(15) << "Role"
            << "| " << setw(10) << "Contact No"
            << "| " << setw(20) << "Email"
            << "| " << setw(10) << "Status"
            << "|\n";
        string l2(100, '-');
        cout<<l2<<endl;
    }

    void printAdmin() {
        cout << "| " << left << setw(10) << adminID
            << "| " << setw(20) << adminName
            << "| " << setw(15) << adminRole
            << "| " << setw(10) << adminContactNo
            << "| " << setw(20) << adminEmail
            << "| " << setw(10) << adminStatus
            << "|\n";
        string line(100, '-');
        cout<<line<<endl;
    }

    void showFullFledgedAdminDetails(){
        fstream f;
        f.open("ADMIN.dat", ios::in | ios::binary);
        system("cls");
        printAdminHeaderFull();
        while (f.read((char*)this, sizeof(*this))) {
            printAdminFull();
        }
        f.close();
    }

    void printAdminHeaderFull() {
        cout << "----------------------------------------------------------------------------------------------------\n";
        cout << "| " << left << setw(6) << "ID"
            << "| " << setw(20) << "Name"
            << "| " << setw(12) << "Password"
            << "| " << setw(10) << "Contact"
            << "| " << setw(15) << "Email"
            << "| " << setw(12) << "DOB"
            << "| " << setw(5) << "Gender"
            << "| " << setw(10) << "Role"
            << "| " << setw(10) << "Status"
            << "|\n";
        cout << "----------------------------------------------------------------------------------------------------\n";
    }

    void printAdminFull() {
        cout << "| " << left << setw(6) << adminID
            << "| " << setw(20) << adminName
            << "| " << setw(12) << calculatePassLength()
            << "| " << setw(10) << adminContactNo
            << "| " << setw(15) << adminEmail
            << "| " << setw(12) << adminDOB
            << "| " << setw(5) << adminGender
            << "| " << setw(10) << adminRole
            << "| " << setw(10) << adminStatus
            << "|\n";
        cout << "--------------------------------------------------------------------------------------------------------------------------\n";
    }

    string calculatePassLength(){ 
        int length = 0;
        while (adminPassword[length] != '\0') {
            length++;
        }
         return string(length, '*'); 
    }    

    void deleteAdmin() {
        fstream fileOperator;
        string idToDelete;
        bool isEmpFound = false;

        cout << "Enter Admin ID to delete: ";
        getline(cin, idToDelete);

        fileOperator.open("ADMIN.dat", ios::in | ios::binary);
        while (fileOperator.read((char*)this, sizeof(*this))) {
            if (idToDelete == getAdminID()) {
                isEmpFound = true;
                break;
            }
        }
        fileOperator.close();

        if (isEmpFound)
            deleteAdminByAdminID(idToDelete);
        else
            cout << "No Admin Matches.\n";
    }

    void deleteAdminByAdminID(string idToDelete){
        fstream f_read, f_write;
        f_read.open("ADMIN.dat", ios::in | ios::binary);
        f_write.open("temp_data.dat", ios::out | ios::binary);

        while (f_read.read((char*)this, sizeof(*this))) {
            if (idToDelete != getAdminID()) {
                f_write.write((char*)this, sizeof(*this));
            }
        }

        f_read.close();
        f_write.close();
        remove("ADMIN.dat");
        rename("temp_data.dat", "ADMIN.dat");
        cout << "ADMIN Deleted Successfully.\n";
    }

    void updateAdmin() {
        string adminIDInput;
        fstream f_empFind;
        bool empFound = false;
        int counter = 0;

        cout << "Enter Employee ID to update: ";
        getline(cin, adminIDInput);

        f_empFind.open("ADMIN.dat", ios::in | ios::binary);
        while (f_empFind.read((char*)this, sizeof(*this))) {
            counter++;
            if (adminIDInput == getAdminID()) {
                empFound = true;
                break;
            }
        }
        f_empFind.close();

        if (empFound) {
            updateAdminFunction(counter);
        } else {
            cout << "Admin Not Found.\n";
        }
    }

    void updateAdminFunction(int counter){
        fstream f;
        f.open("ADMIN.dat", ios::in | ios::out | ios::binary);
        f.seekp((counter - 1) * sizeof(*this), ios::beg);
        takingAdminInputforUpdation();
        f.write((char*)this, sizeof(*this));
        f.close();
        cout << "ADMIN Updated Successfully.\n";
    }

    void takingAdminInputforUpdation() {
        system("cls"); 
        cout << "\n====================== Update Admin Profile ======================\n";

        //cin.ignore(); 
        cout << "Enter Name             : ";
        cin.getline(adminName, sizeof(adminName));

        cout << "Enter Contact No       : ";
        cin.getline(adminContactNo, sizeof(adminContactNo));

        cout << "Enter Email            : ";
        cin.getline(adminEmail, sizeof(adminEmail));

        cout << "Enter Address          : ";
        cin.getline(adminAddress, sizeof(adminAddress));

        cout << "Enter Date of Birth    : ";
        cin.getline(adminDOB, sizeof(adminDOB));  // Format: DD/MM/YYYY

        cout << "Enter Gender           : ";
        cin.getline(adminGender, sizeof(adminGender));  // Eg: Male/Female/Other

        cout << "Enter Department/Role  : ";
        cin.getline(adminRole, sizeof(adminRole));

        // cout << "Enter Joining Date     : ";
        // cin.getline(adminJoinDate, sizeof(adminJoinDate));  // Format: DD/MM/YYYY

        cout << "Enter Status (Active/Inactive): ";
        cin.getline(adminStatus, sizeof(adminStatus));

        cout << "=================================================================\n";
        cout << "Admin data saved successfully!\n";
    }

    void updateAdminPassword(){
        string oldPassword = getSafePassword();
        // cin.ignore();
        fstream f;
        bool passAuthenticated = false;
        int counter = 0;

        f.open("ADMIN.dat", ios::in | ios::binary);
        while (f.read((char*)this, sizeof(*this))) {
            counter++;
            if (oldPassword == getAdminPassword()) {
                passAuthenticated = true;
                break;
            }
        }
        f.close();

        if (passAuthenticated) {
            cout << "\nEnter New Password: ";
            cin.getline(adminPassword, 19);

            f.open("ADMIN.dat", ios::in | ios::out | ios::binary);
            f.seekp((counter - 1) * sizeof(*this), ios::beg);
            f.write((char*)this, sizeof(*this));
            f.close();
            cout << "Password Updated Successfully!\n";
        } else {
            cout << "\nIncorrect Password!\n";
        }
    }

    void resetAnyAdminPassword(){
    
        Admin HR;
        string ADMNid;

        bool isAdminFound = false;
        
        cout<<"Enter ADMIN ID to RESET password :";
        getline(cin, ADMNid);

        fstream f;
        f.open("ADMIN.dat", ios::in | ios::out | ios::binary);

        while(f.read((char*)&HR, sizeof(HR))){
            if(getAdminID() == ADMNid){
                isAdminFound = true;
               break; 
            }
        }
        f.close();

        if(isAdminFound){
            char Password[20];
            cout << "Enter New PassWord :";
            cin.get(Password, 20);
            strcpy(adminPassword, Password); 
            cout<<"\n\nPASSWORD UPDATED SUCCESSFULLY!\n";

        }else{
            cout<<"\nPlease Enter a Valid Admin ID!\n";
        }
    }

};

class Client {

    char projectID[15];
    char clientID[15];
    char clientName[30];
    char clientCompany[30];
    char clientContact[15];
    char clientEmail[40];
    char clientAddress[100];
    char clientPassword[20];
    string clientQuerytoAdmin;
    string adminResponse;

public:

    //SHIVA
    ~Client(){}

    //BRAHMA
    Client(){
        strcpy(clientID, "SGIc00");
        strcpy(clientName, "Client");
        strcpy(clientCompany, "Red Moon Industries");
        strcpy(clientContact, "6378268957");
        strcpy(clientEmail, "client@RedMoon.ac.in");
        strcpy(clientAddress, "H.No. 619, Sector 3, Biliya, Bhilwara");
        strcpy(clientPassword, "client@SGI");
    }
 
    //VISHNU
    string getClientID(){return string(clientID);}
    string getClientName(){return string(clientName);}
    string getClientCompany(){return string(clientCompany);}
    string getClientContact(){return string(clientContact);}
    string getClientAddress(){return string(clientAddress);}
    string getClientPassword(){return string(clientPassword);}
    string getClientEmailAddress(){return string(clientEmail);}
    string getClientQuery(){return  clientQuerytoAdmin;}
    string getAdminResponse(){return  adminResponse;}

    void addClientConstructorsValuetoFile(){
        Client client;
        fstream f;
        f.open("CLIENT.dat", ios::binary | ios::out);
        f.write((char*)&client, sizeof(client));
        f.close();
    }

    void ClientMenu() {
        Client client;
        Company company;
        int choice;
        while (true) {
            system("cls");
            cout << "\n================ CLIENT DASHBOARD ================\n";
            cout << "1. View Company Info\n";
            cout << "2. View My Project Status\n";
            cout << "3. Raise a Complaint or Query\n";
            cout << "4. View Contact Person (HR)\n";
            cout << "5. Logout\n";
            cout << "Enter your choice: ";

            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a valid number.\n";
                Sleep(2000);
                continue;
            }

            switch (choice) {
                case 1: system("cls"); 
                    company.displayCompanyInfo();
                    cout<<"Redirecting to CLIENT Menu in 10 Seconds"; 
                    Sleep(10000);

                case 2:
                    cout << "\n[Project Status Feature Coming Soon...]\n";
                    cout<<"Redirecting to CLIENT Menu in 10 Seconds"; 
                    Sleep(10000);
                    break;

                case 3:
                    cout << "\n[Complaint Registered Successfully! We'll get back soon.]\n";
                    cout<<"Redirecting to CLIENT Menu in 10 Seconds"; 
                    Sleep(10000);
                    break;

                case 4:
                    cout << "\n[Assigned HR Contact: Mr. Sharma - 99999XXXXX | hr@company.com]\n";
                    cout<<"Redirecting to CLIENT Menu in 10 Seconds"; 
                    Sleep(10000);
                    break;

                case 5:
                    cout << "\nLogging Out...\n";
                    Sleep(1500);
                    return;

                default:
                    cout << "\nInvalid choice! Please select a valid option.\n";
                    cout << "Retrying in 2 seconds.\n";
                    Sleep(2000);
            }
        }
    }

    bool authenticateClient(){
        fstream fileOperator;
        fileOperator.open("CLIENT.dat", ios::in | ios::binary);

        if (!fileOperator) {
            cout << "\n\033[1;31mError opening CLIENT.dat file\033[0m\n";
            return false;
        }

        string userID;
        cout << "\nEnter Client ID : ";
        getline(cin, userID);

        bool authenticated = false;

        while (fileOperator.read((char*)this, sizeof(*this))) {
            if (userID == getClientID()) {
                string password = getSafePassword(); 
                if (password == getClientPassword()) {
                    cout << "\n\033[1;32mAuthentication Successful\033[0m\n";
                    authenticated = true;
                } else {
                    cout << "\n\033[1;31mIncorrect Password\033[0m\n";
                }
                break;
            }
        }

        fileOperator.close();

        if (!authenticated && userID != getClientID()) {
            cout << "\n\033[1;31mClient Not Found\033[0m\n";
        }

        return authenticated;
    }

    void fillClientDetails() {
        system("cls"); 
        cout << "==========================================" << endl;
        cout << "           CLIENT REGISTRATION            " << endl;
        cout << "==========================================" << endl;

        //cin.ignore(); 

        cout << "\nEnter Client Name       : ";
        cin.getline(clientName, 30);

        cout << "Enter Company Name      : ";
        cin.getline(clientCompany, 30);

        cout << "Enter Contact Number    : ";
        cin.getline(clientContact, 15);

        cout << "Enter Email Address     : ";
        cin.getline(clientEmail, 40);

        cout << "Enter Full Address      : ";
        cin.getline(clientAddress, 100);

        cout << "\nClient details recorded successfully!" << endl;
        cout << "==========================================" << endl;
    }

    void generateClientID() {
        int count = 1;
        Client temp;
        fstream fCount("CLIENT.dat", ios::in | ios::binary);
        while (fCount.read((char*)&temp, sizeof(temp))) {
            count++;
        }
        fCount.close();

        ostringstream oss;
        oss << "SGIc" << setw(2) << setfill('0') << count; // CLT01, CLT02,...
        string newID = oss.str();
        strcpy(clientID, newID.c_str());
    }

    void addClientToFile() {
        fstream f("CLIENT.dat", ios::app | ios::binary);
        fillClientDetails();
        generateClientID();
        f.write((char*)this, sizeof(*this));
        f.close();
        cout << "\n Client Added Successfully with ID: " << clientID << endl;
    }

    void updateClientPassword() {

        string oldPassword = getSafePassword(); 
        fstream file;
        bool isAuthenticated = false;
        int recordIndex = 0;

        // Authenticate current password
        file.open("CLIENT.dat", ios::in | ios::binary);
        while (file.read((char*)this, sizeof(*this))) {
            recordIndex++;
            if (oldPassword == getClientPassword()) {
                isAuthenticated = true;
                break;
            }
        }
        file.close();

        //allow password change
        if (isAuthenticated) {
            char newPassword[20], confirmPassword[20];
            cout << "\nEnter New Password     : ";
            cin.ignore();
            cin.getline(newPassword, 20);
            cout << "Confirm New Password   : ";
            cin.getline(confirmPassword, 20);

            if (strcmp(newPassword, confirmPassword) != 0) {
                cout << "\nPasswords do not match. Please try again.\n";
                return;
            }

            strcpy(clientPassword, newPassword);

            file.open("CLIENT.dat", ios::in | ios::out | ios::binary);
            file.seekp((recordIndex - 1) * sizeof(*this), ios::beg);
            file.write((char*)this, sizeof(*this));
            file.close();

            cout << "\nPassword updated successfully!\n";
        } else {
            cout << "\nIncorrect current password. Try again.\n";
        }
    }

    void showAllClients() {
        ifstream file("CLIENT.dat", ios::binary);
        if (!file) {
            cout << "Error: CLIENT.dat file not found.\n";
            return;
        }

        Client temp;
        int count = 0;

        cout << "\n====================================================================================================================" << endl;
        cout << left << setw(5)  << "No."
            << "|" << setw(15) << "Client ID"
            << "|" << setw(25) << "Name"
            << "|" << setw(25) << "Company"
            << "|" << setw(18) << "Contact"
            << "|" << setw(30) << "Email"
            << "|" << setw(30) << "Address" << endl;
        cout << "====================================================================================================================" << endl;

        while (file.read((char*)&temp, sizeof(temp))) {
            cout << left << setw(5)  << ++count
                << "|" << setw(15) << temp.clientID
                << "|" << setw(25) << temp.clientName
                << "|" << setw(25) << temp.clientCompany
                << "|" << setw(18) << temp.clientContact
                << "|" << setw(30) << temp.clientEmail
                << "|" << setw(30) << temp.clientAddress << endl;
        }

        if (count == 0)
            cout << "No clients found.\n";

        cout << "====================================================================================================================\n" << endl;

        file.close();
    }

    void showClientProfile() {
        cout << "\n==========================================" << endl;
        cout << "              CLIENT PROFILE              " << endl;
        cout << "==========================================" << endl;
        cout << "Client ID       : " << clientID << endl;
        cout << "Name            : " << clientName << endl;
        cout << "Company         : " << clientCompany << endl;
        cout << "Contact Number  : " << clientContact << endl;
        cout << "Email           : " << clientEmail << endl;
        cout << "Address         : " << clientAddress << endl;
        cout << "==========================================\n" << endl;
    }

    void raiseQueryFromClient(){
        cout << "Drop Your Query :";
        getline(cin, clientQuerytoAdmin);
        cout << "Your Query Sent To Admin!";
    }

    void checkClientQuery(){
        Client client;
        string query, response;
        query = client.getClientQuery();
        cout << "Client Query is : "<<query<<endl;
        cout << "Drop Response :";
        getline(cin, response);
        client.adminResponse = response;

    }
};

class Project {

    char clientID[15];
    char projectID[10];       
    char projectName[50];
    char assignedEmpID[10];
    char startDate[15];
    char endDate[15];
    char status[30];
    char description[100];
    char projectPhase[20];

public:

    //SHIVA 
    ~Project(){}

    //BRAHMA
    Project(){
        strcpy(projectPhase, "DEVLOPING");
    }

    //VISHNU
    string getClientID(){return string(clientID);}
    string getProjectName(){ return string(projectName); }
    string getProjectDescripton(){ return string(description);}
    string getProjectID(){ return string(projectID); }
    string getAssignedEmployeeID(){ return string(assignedEmpID); }
    string getProjectStatus(){ return string(status);}
    string getProjectEndDate(){ return string(endDate);}
    string getProjectStartDate(){ return string(startDate);}

    void autoGenerateProjectID(){
        ifstream fin("PROJECT.dat", ios::binary);
        int count = 0;

        if (fin) {
            Project temp;
            while (fin.read((char*)&temp, sizeof(temp))) {
                count++;
            }
            fin.close();
        }

        sprintf(projectID, "SGIP%03d", count + 1); //PROJ001
    }

    void saveToFile(){
        ofstream fout("PROJECT.dat", ios::binary | ios::app);
        fout.write((char*)this, sizeof(*this));
        setData();
        fout.close();
        cout << "\nProject saved successfully.\n";
    }

    bool findClientForAttachProject(string clientID){
        Client client;
        fstream f;
        bool clientFound = false;
        f.open("CLIENT.dat", ios::in | ios::binary);
        while(f.read((char*)&client, sizeof(client))){
            if(clientID == client.getClientID()){
                clientFound = true;
                break;
            }
        }
        f.close();

        if(clientFound){
            return true;
        }
        else{
            return false;
        }
    }

    void setData() {

        Project proj;
        Client client;
        cout << "\n==========================================" << endl;
        cout << "            NEW PROJECT ENTRY             " << endl;
        cout << "==========================================" << endl;

        cout << "\nEnter Associated Client ID : ";
        cin.getline(clientID, 15);
        
        bool clientFound = findClientForAttachProject(getClientID());
        
        if(clientFound){
            autoGenerateProjectID(); 

            cout << "Generated Project ID       : " << projectID << endl;

            cout << "\nEnter Project Name         : ";
            cin.getline(projectName, 50);

            cout << "Enter Assigned Employee ID : ";
            cin.getline(assignedEmpID, 10);

            // string currentDate = getCurrentDate_DDMMYYYY();
            // strcpy(startDate, currentDate);
            cout << "Enter Start Date (DD-MM-YYYY)  : ";
            cin.getline(startDate, 15);
        
            cout << "Enter End Date (DD-MM-YYYY)  : ";
            cin.getline(endDate, 15);

            // cout << "Enter Project Status        : ";
            // cin.getline(status, 20);
            strcpy(status, "Pending");

            cout << "Enter Project Description   : ";
            cin.getline(description, 100);

            cout << "==========================================\n" << endl;

        }else{
            cout<<"\nNeed Valid Client for Project Attachement!";
        }
        
    }

    void displayData() {
        cout << "------------------------------------------" << endl;
        cout << "Project ID         : " << projectID << endl;
        cout << "Project Name       : " << projectName << endl;
        cout << "Assigned Employee  : " << assignedEmpID << endl;
        cout << "Start Date         : " << startDate << endl;
        cout << "End Date           : " << endDate << endl;
        cout << "Project Status     : " << status << endl;
        cout << "Description        : " << description << endl;
        cout << "Project Phase      : " << projectPhase << endl;
        cout << "------------------------------------------\n";
    }

    void showAllProjects() {
        ifstream fin("PROJECT.dat", ios::binary);
        if (!fin) {
            cout << "\nNo project data found.\n";
            return;
        }

        Project p;
        int count = 0;

        cout << "\n==========================================" << endl;
        cout << "              ALL PROJECTS                " << endl;
        cout << "==========================================\n";

        while (fin.read((char*)&p, sizeof(p))) {
            cout << "\nProject #" << ++count;
            p.displayData();
        }

        if (count == 0)
            cout << "No records to display.\n";

        cout << "==========================================\n" << endl;

        fin.close();
    }

    void viewCompletedProjects(){

        Project proj;
        fstream f;
        int completedProjects = 0;
        bool isNotCompleted = false;
        f.open("PROJECT.dat", ios::in | ios::binary);
        while(f.read((char*)&proj, sizeof(proj))){
            if(getProjectStatus() == "Completed" || getProjectStatus() == "completed"){
                displayData();
                completedProjects++;
                isNotCompleted = true;
            }
        }
        cout<<"\nThere are "<<completedProjects<<" Completed Projects.\n";
        f.close();
    }

    void viewPendindProjects(){
        fstream f;
        Project proj;
        bool isAssignedProj = false;
        int projectCounter = 0;
        f.open("PROJECT.dat", ios::in | ios::binary);
        while(f.read((char*)&proj, sizeof(proj))){
            if(getProjectStatus() == "Pending"){
                displayData();
                projectCounter++;
                isAssignedProj = true;
            }
        }
        f.close();

        if(isAssignedProj){
            cout << "There are "<<projectCounter<<" Projects Pending from ";
        }else{
            cout<<"No Projects are Pending!";
        }
    }

    void viewAssignedProjectsforClint(string clientId){
        fstream f;
        bool projFound = false;
        f.open("PROJECT.dat", ios::in | ios::binary);

        while(f.read((char*)this, sizeof(*this))){
            if(getClientID() == clientId){
                displayData();
                projFound = true;
            }
        }
        f.close();
        if(!projFound){
            cout << "There was no Project Associated with Your ID."<<clientId<<endl;
            cout << "\n";
        }
    }

    void projSubmissionfromEmployee(){
        Employee emp;
        Project proj;
        fstream f;

        bool isSubmittedBeforeTime = false;
        bool isAssigned = false;

        f.open("PROJECT.dat", ios::in | ios::binary);

        while(f.read((char*)&proj, sizeof(proj))){
            if(emp.getEmpID() == proj.getAssignedEmployeeID()){
                isAssigned = true;
                if(isBeforeOrOnDeadline_DDMMYYYY(getCurrentDate_DDMMYYYY(),getProjectEndDate())){
                    strcpy(status, "Submit Request By Employee");
                    isSubmittedBeforeTime = true;
                }
            }
        }
        f.close();

        if(isAssigned && !isSubmittedBeforeTime){
            cout << "You Are Trying to Sumbit Project after Deadline\n";
            cout << "Contact to Project Manager";
        }
        else if(isAssigned && isSubmittedBeforeTime){
            cout<<"Submission Before Deadline\nWait for Approval from Admin/HR\n";
        }
     
    }

    tm convertToTm_DDMMYYYY(const string& dateStr) {
        tm tmStruct = {};
        std::istringstream ss(dateStr);
        ss >> std::get_time(&tmStruct, "%d-%m-%Y");  // Day-Month-Year format
        return tmStruct;
    }

    bool isBeforeOrOnDeadline_DDMMYYYY(const string& current, const string& end) {
        tm tm_current = convertToTm_DDMMYYYY(current);
        tm tm_end = convertToTm_DDMMYYYY(end);

        time_t t_current = mktime(&tm_current);
        time_t t_end = mktime(&tm_end);

        return difftime(t_current, t_end) <= 0;
    }

    void approveSubmissionfromEmployeeToAdmin(){

        Project p;
        fstream f;
        bool approvedFromHR = false;

        string ProjID, projName, projDes;
        f.open("PROJECT.dat", ios::in | ios::binary);
            while(f.read((char*)&p, sizeof(p))){
                if(getProjectStatus() == "Submit Request By Employee"){
                    ProjID = getProjectID();
                    projName = getProjectName();
                    projDes = getProjectDescripton();
                    strcpy(status, "Approved BY HR");
                    approvedFromHR = true;
                }
            }
        f.close();

        if(!approvedFromHR){
            cout<<"\nNo Approval Requests from Employee!\n";
        }
        else{
            cout << "\nProject ID : "<<ProjID;
            cout << "\nProject Name : "<<projName;
            cout << "\nProject Description : "<<projDes;
            cout << "\nProject Approved from You\n";
        }

        
    }
    
};

class Leave {

    char leaveID[10];      // Auto-generated: LEAVE001...
    char empID[10];        // From Employee
    char leaveType[20];    // Sick, Casual, Paid, etc.
    char startDate[15];
    char endDate[15];
    char reason[100];
    char status[20];       // Pending by default

public:

    //BRAHMA
    // Leave(){
    //     strcpy(leaveType, "Casual");
    //     strcpy(status, "Pending");
    // }

    //SHIVA
    ~Leave(){}

    //VISHNU
    // string getLeaveStatus(){ return string(status);}
    string getEmpId(){ return string(empID);}
    string getLeaveID(){ return string(leaveID);}

    void autoGenerateLeaveID() {
        ifstream fin("LEAVE.dat", ios::binary);
        int newID = 1;

        if (fin) {
            Leave temp;
            fin.seekg(0, ios::end);
            int size = fin.tellg();

            if (size >= sizeof(Leave)) {
                fin.seekg(-sizeof(Leave), ios::end); // Move to last record
                fin.read((char*)&temp, sizeof(temp));

                // Extract number from leaveID (LEAVE001 → 1)
                int lastID;
                sscanf(temp.leaveID, "LEAVE%d", &lastID);
                newID = lastID + 1;
            }

            fin.close();
        }

        sprintf(leaveID, "LEAVE%03d", newID);
    }
    
    void displayLeave() {
        cout << "\n---------------------------------------------" << endl;
        cout << "Leave ID       : " << leaveID << endl;
        cout << "Employee ID    : " << empID << endl;
        cout << "Leave Type     : " << leaveType << endl;
        cout << "Start Date     : " << startDate << endl;
        cout << "End Date       : " << endDate << endl;
        cout << "Reason         : " << reason << endl;
        cout << "Current Status : " << status << endl;
        cout << "---------------------------------------------" << endl;
    }
    
    void saveToFile(){
        ofstream fout("LEAVE.dat", ios::binary | ios::app);
        fout.write((char*)this, sizeof(*this));
        fout.close();
        cout << "\nLeave request prepared successfully.\n";
    }

    void applyLeave() {

        Employee emp;
        autoGenerateLeaveID();

        cout << "\n=============================================" << endl;
        cout << "              APPLY FOR LEAVE                " << endl;
        cout << "=============================================" << endl;
        cout << "Generated Leave ID        : " << leaveID << endl;

        
        cout << "Enter Employee ID         : ";
        cin.getline(empID, 10);

        cout << "Enter Leave Type          : ";
        cin.getline(leaveType, 20);

        cout << "Enter Start Date (DD-MM-YYYY): ";
        cin.getline(startDate, 15);

        cout << "Enter End Date (DD-MM-YYYY)  : ";
        cin.getline(endDate, 15);

        cout << "Enter Reason               : ";
        cin.getline(reason, 100);

        strcpy(status, "Pending");

        saveToFile();
    }

    void setLeaveStatus(const char* newStatus) {
        strcpy(status, newStatus);
    }

    const char* getLeaveStatus() const {
        return status;
    }

    void approveLeave() {
        // fstream fin("LEAVE.dat", ios::in | ios::binary);
        // Leave l;
        // int counter = 0;
        // bool isLeavesPending = false;

        // // First pass: Display pending leaves
        // while (fin.read((char*)&l, sizeof(l))) {
        //     if (strcmp(l.getLeaveStatus(), "Pending") == 0) {
        //         l.displayLeave(); // Assuming this is defined
        //         counter++;
        //         isLeavesPending = true;
        //     }
        // }
        // fin.close();

        // if (!isLeavesPending) {
        //     cout << "\nNo Pending Leaves\n";
        //     return;
        // }

        // cout << "\nThere are " << counter << " Leave(s) Pending...\n";
        // cout << "Enter Employee ID to approve leave: ";
        // string confirmempID;
        // getline(cin, confirmempID);

        // fstream file("LEAVE.dat", ios::in | ios::out | ios::binary);
        // while (file.read((char*)&l, sizeof(l))) {
        //     if (l.getEmpId() == confirmempID && strcmp(l.getLeaveStatus(), "Pending") == 0) {
        //         l.setLeaveStatus("Approved by HR");

        //         int pos = file.tellg() - static_cast<int>(sizeof(l));
        //         file.seekp(pos);
        //         file.write((char*)&l, sizeof(l));

        //         cout << "\nLeave Approved for Employee ID: " << confirmempID << "\n";
        //         file.close();
        //         return;
        //     }
        // }
        // file.close();

        // cout << "\nLeave not found for ID: " << confirmempID << "\n";
    }

    void LeaveStatus() {
        fstream f("LEAVE.dat", ios::in | ios::binary);
        Leave l;
        bool isLeaveFound = false;

        while (f.read((char*)&l, sizeof(l))) {
            if (this->getEmpId() == l.getEmpId()) {
                cout << "\nYour Leave Status: " << l.getLeaveStatus() << endl;
                isLeaveFound = true;
                break;
            }
        }

        f.close();

        if (!isLeaveFound) {
            cout << "\nNo Leave Request Found\n";
        }
    }

};

class Salary {

    char adminID[10];
    char empID[10];
    char empType[10];              // Intern / Junior / Senior
    char adminType[10];
    char salaryMonth[15];          // e.g., "July2025"
    float basicPay;
    int totalWorkingDays;
    int daysPresent;
    int leavesTaken;
    int allowedPaidLeaves;
    float deductionPerDay;
    float netSalary;

public:

    ~Salary(){}

    string getEmpID(){return string(empID);}
    string getSalaryMonth(){return string(salaryMonth);}

    void inputSalary() {

        cout << "\n\033[1;34m=== Enter Employee Details for SALARY ===\033[0m\n";

        cout << "Enter Employee ID: ";
        cin.getline(empID, 10);

        cout << "Enter Employee Type (Intern / Junior / Senior): ";
        cin.getline(empType, 10);

        cout << "Enter Salary Month (e.g. July2025): ";
        cin.getline(salaryMonth, 15);

        cout << "Enter Base Monthly Pay: ";
        while (!(cin >> basicPay)) {
            cout << "Invalid input. Enter numeric value: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cout << "Enter Total Working Days: ";
        while (!(cin >> totalWorkingDays)) {
            cout << "Invalid input. Enter numeric value: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cout << "Enter Days Present: ";
        while (!(cin >> daysPresent)) {
            cout << "Invalid input. Enter numeric value: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cout << "Enter Allowed Paid Leaves: ";
        while (!(cin >> allowedPaidLeaves)) {
            cout << "Invalid input. Enter numeric value: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cout << "Enter Leaves Taken: ";
        while (!(cin >> leavesTaken)) {
            cout << "Invalid input. Enter numeric value: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cout << "Enter Deduction per Extra Leave Day: ";
        while (!(cin >> deductionPerDay)) {
            cout << "Invalid input. Enter numeric value: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        // cin.ignore(); 

        calculateSalary();
    }

    void calculateSalary(){

        float multiplier = 1.0;

        if (strcmp(empType, "Intern") == 0)
            multiplier = 0.6;
        else if (strcmp(empType, "Senior") == 0)
            multiplier = 1.5;
        else if (strcmp(empType, "Junior") == 0)
            multiplier = 1.0;

        float adjustedPay = basicPay * multiplier;
        float perDay = adjustedPay / totalWorkingDays;
        float earned = perDay * daysPresent;

        int extraLeaves = leavesTaken - allowedPaidLeaves;
        
        float deduction;

        if(extraLeaves > 0){
            deduction = extraLeaves * deductionPerDay;
        }else{
            deduction = 0;
        }

        netSalary = earned - deduction;

        saveToFile();

    }

    void saveToFile(){
        ofstream fout("SALARY.dat", ios::binary | ios::app);
        fout.write((char*)this, sizeof(*this));
        fout.close();
        cout << "Salary saved successfully!\n";
    }

    void displaySalary() {

        cout << "\n\033[1;32m====================================\033[0m\n";
        cout <<   "\033[1;33m          EMPLOYEE SALARY SLIP       \033[0m\n";
        cout <<   "\033[1;32m====================================\033[0m\n";

        cout << "\033[1;36mEmp ID            : \033[0m" << empID << endl;
        cout << "\033[1;36mEmployee Type     : \033[0m" << empType << endl;
        cout << "\033[1;36mSalary Month      : \033[0m" << salaryMonth << endl;

        cout << "\033[1;36mBasic Pay         : ₹\033[0m" << basicPay << endl;

        cout << "\033[1;36mAdjusted Pay      : ₹\033[0m" << basicPay << " × "
            << (strcmp(empType, "Intern") == 0 ? "0.6" :
                strcmp(empType, "Senior") == 0 ? "1.5" : "1.0") << " = ₹"
            << fixed << setprecision(2)
            << basicPay * (strcmp(empType, "Intern") == 0 ? 0.6 :
                            strcmp(empType, "Senior") == 0 ? 1.5 : 1.0)
            << endl;

        cout << "\033[1;36mWorking Days      : \033[0m" << daysPresent << " / " << totalWorkingDays << endl;
        cout << "\033[1;36mLeaves Taken      : \033[0m" << leavesTaken 
            << " (Allowed: " << allowedPaidLeaves << ")\n";

        cout << "\033[1;32m------------------------------------\033[0m\n";
        cout << "\033[1;35mNet Salary        : ₹" << fixed << setprecision(2) << netSalary << "\033[0m\n";
        cout << "\033[1;32m====================================\033[0m\n";
    }

    void editSalary(const char* id, const char* month){
        
        Salary s;
        fstream file("SALARY.dat", ios::binary | ios::in | ios::out);
        bool found = false;

        while(file.read((char*)&s, sizeof(s))) {
            if(strcmp(s.empID, id) == 0 && strcmp(s.salaryMonth, month) == 0) {
                found = true;
                cout << "\nOld Data:\n";
                s.displaySalary();

                cout << "\nEnter updated details:\n";
                s.inputSalary();

                int pos = -1 * (int)sizeof(s);
                file.seekp(pos, ios::cur);
                file.write((char*)&s, sizeof(s));
                cout << "Record updated successfully!\n";
                break;
            }
        }

        file.close();
        if (!found) cout << " Record not found!\n";
    }

   void viewMonthlyReport(const string& month) {
        Salary s;
        ifstream fin("SALARY.dat", ios::binary);
        bool found = false;

        cout << "\n\033[1;36m========== Monthly Salary Report: " << month << " ==========\033[0m\n";

        while (fin.read((char*)&s, sizeof(s))) {
            if (s.getSalaryMonth() == month) {
                cout << "\033[1;33m--------------------------------------------\033[0m\n";
                s.displaySalary();
                found = true;
            }
        }

        fin.close();

        if (!found) {
            cout << "\033[1;31mNo salary records found for the month: " << month << "\033[0m\n";
        } else {
            cout << "\033[1;32mEnd of report.\033[0m\n";
        }
    }

};

void allConstructorsSavingToFile(){

    Admin HR;
    Employee emp;
    Client client;

    emp.addEmployeeConstructorsValuetoFile();
    HR.addAdminConstructorsValuetoFile();
    client.addClientConstructorsValuetoFile();
}

void CorruptFileRemover(){
    fstream f;
}

void MAINMENU(){

    cout << "\n\t\t\t\t1. Login as Admin";
    cout << "\n\t\t\t\t2. Login as Employee";
    cout << "\n\t\t\t\t3. Login as Client";
    cout << "\n\t\t\t\t4. Login as Super Admin";
    cout << "\n\t\t\t\t5. Exit\n\n\n";

    cout << setfill('-') << setw(100) << "-" << endl;
    cout << setfill(' ');

    cout << "\t      Enter Your Choice: \n";
    cout << setfill('-') << setw(100) << "-" << endl;
    cout << setfill(' ') << endl;
}

void authenticateUSER() {

    Admin HR;
    Employee emp;
    Client client;
    SuperAdmin superAdmin;
    Company company;  

    int choice;

    while (true) {
        system("cls");
        CompanyHeader();
        ProjectHeader();
        MAINMENU();
        gotoxy(32, 18);
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input! Please enter a valid number.\n";
            Sleep(2000);
            continue;
        }
        cin.ignore(); 

        switch (choice) {
            case 1: {
                system("cls");
                CompanyHeader();
                ProjectHeader();
                if (HR.authenticateAdmin()) {
                    Sleep(1500);
                    whatAdminDOES();
                } else {
                    cout << "\nAccess Denied: Admin credentials required!\n";
                    Sleep(1500);
                }
                cout << "\nRedirecting to Main Menu";
                loadingBar("", 5);
                break;
            }

            case 2: {
                system("cls");
                CompanyHeader();
                ProjectHeader();
                if (emp.authenticateEmployee()) {
                    Sleep(1500);
                    emp.autoGenerateMonthlySalary();
                    whatEmployeeDOES();
                } else {
                    cout << "\nAccess Denied: Employee credentials required!\n";
                    Sleep(1500);
                }
                cout << "\nRedirecting to Main Menu";
                loadingBar("", 5);
                break;
            }

            case 3: {
                system("cls");
                CompanyHeader();
                ProjectHeader();
                if (client.authenticateClient()) {
                    Sleep(1500);
                    whatClientDOES();
                } else {
                    cout << "\nAccess Denied: Clients credentials required!\n";
                    Sleep(1500);
                }
                cout << "\nRedirecting to Main Menu.";
                loadingBar("", 5);
                break;
            }

            case 4: {
                system("cls");
                CompanyHeader();
                ProjectHeader();
                if (superAdmin.AuthenticateSuperAdmin()) {
                    Sleep(1500);
                    whatSuperAdminMANIPULATES();
                } else {
                    cout << "\nAccess Denied: Super-Credentials required!\n";
                    Sleep(1500);
                }
                cout << "\nRedirecting to Main Menu.";
                loadingBar("", 5);
                break;
            }

            case 5:
                cout << "\nThank you for visiting " << company.getCompanyName() << ". Have a great day!\n";
                return;

            default:
                cout << "\nInvalid choice! Please select from the menu.\n";
                cout << "\nRedirecting to Main Menu";
                loadingBar("", 3);
                break;
        }
    }
}

void whatAdminDOES(){

    Company company;
    Client client;
    Salary salary;
    Employee emp;
    Project proj;
    Leave leave;
    Admin HR;

    int choice;

    while (true) {
        system("cls"); 
        ProjectHeader();
        header("HUMAN RESOURCES DASHBOARD");

        cout << "  ADMIN RELATED WORKS                   \t\tPROJECT RELATED WORKS\n";
        cout << "  ----------------------                \t\t-----------------------\n";
        cout << "  1. View your Profile                  \t\t13. Assign Project to Employee\n";
        cout << "  2. View History                       \t\t14. Approve Submission from Employee\n";
        cout << "  3. View All Admins                    \t\t15. View Completed Projects\n";
        cout << "  4. Update Password                    \t\t16. View Pending Projects\n";

        cout << "\n  EMPLOYEE RELATED WORKS                \t\tCLIENT RELATED WORKS\n";
        cout << "  ------------------------              \t\t-----------------------\n";
        cout << "  5. View All Employees                 \t\t17. Queries from Clients\n";
        cout << "  6. Add Employee                       \t\t18. View All Clients\n";
        cout << "  7. Delete Employee\n";
        cout << "  8. Update Employee                    \t\t   EMPLOYEE LEAVE MANAGEMENT   \n";
        cout << "  9. Full Employee Details              \t\t19. Approve Leave for Employee\n";

        cout << "\n  EMPLOYEE SALARY RELATED WORKS        \t\t\tQUOTATION & HISTORY\n";
        cout << "  ------------------------------         \t\t----------------------\n";
        cout << " 10. Generate Salary for Employee        \t\t20. View Project History\n";
        cout << " 11. Generate Salary Slip for Employee   \t\t21. Generate Quotation for Project\n";
        cout << " 12. Monthly Salary Report.\n";

        cout << "\n 22. Logout!\t\t\t\t\t\033[1;33mEnter Your Choice :\033[0m";



        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number.\n";
            Sleep(2000);
            continue;
        }
            cin.ignore();

        switch (choice) {

            case 1: {
                system("cls");
                ProjectHeader();
                HR.viewAdminProfile();
                cout<<"Redirecting to ADMIN Menu";
                loadingBar("", 10); 
            }break;
                
            case 2: {
                system("cls");
                ProjectHeader();
                cout<<"In Building Phase";
                //HR.AdminHistory();
                cout<<"Redirecting to ADMIN Menu";
                loadingBar("", 10); 
            }break;

            case 3: {
                system("cls");
                ProjectHeader();
                HR.showAllAdmin();
                cout<<"Redirecting to ADMIN Menu";
                loadingBar("", 10); 
            }break;

            case 4: {
                system("cls");
                ProjectHeader();
                HR.updateAdminPassword();
                cout<<"Redirecting to ADMIN Menu";
                loadingBar("", 4); 
            }break;

            case 5: {
                system("cls");
                ProjectHeader();
                emp.showAllEmployee();
                cout<<"Redirecting to ADMIN Menu";
                loadingBar("", 10); 
            }break;

            case 6: {
                system("cls");
                ProjectHeader();
                emp.addEmployeetoFile();
                cout<<"Redirecting to ADMIN Menu";
                loadingBar("", 4); 
            }break;

            case 7: {
                system("cls");
                ProjectHeader();
                emp.deleteEmployee();
                cout<<"Redirecting to ADMIN Menu";
                loadingBar("", 5); 
            }break;

            case 8: {
                system("cls");
                ProjectHeader();
                emp.updateEmployee();
                cout<<"Redirecting to ADMIN Menu";
                loadingBar("", 7); 
            }break;

            case 9: {
                system("cls");
                ProjectHeader();
                emp.allEmployeesFullDetails();
                cout<<"Redirecting to ADMIN Menu";
                loadingBar("", 10); 
            }break;


            case 10: {
                system("cls");
                ProjectHeader();
                emp.generateAllMonthlySalaries();
                // salary.inputSalary();
                cout<<"Redirecting to ADMIN Menu";
                loadingBar("", 7); 
            }break;
            
            case 11: {
                system("cls");
                ProjectHeader();
                salary.displaySalary();
                cout<<"Redirecting to ADMIN Menu";
                loadingBar("", 7); 
            }break;

            case 12: {
                system("cls");
                ProjectHeader();
                string month;
                cout<<"Enter Month and Year for Monthly Report(eg. May2025) :";
                getline(cin, month);
                salary.viewMonthlyReport(month);
                cout<<"Redirecting to ADMIN Menu";
                loadingBar("", 7); 
            }break;

            case 13: {
                system("cls");
                ProjectHeader();
                proj.saveToFile();
                cout<<"Redirecting to ADMIN Menu";
                loadingBar("", 6); 
            }break;

            case 14: {
                system("cls");
                ProjectHeader();
                proj.approveSubmissionfromEmployeeToAdmin();
                cout<<"Redirecting to ADMIN Menu";
                loadingBar("", 5); 
            }break;

            case 15: {
                system("cls");
                ProjectHeader();
                proj.viewCompletedProjects();
                cout<<"Redirecting to ADMIN Menu";
                loadingBar("", 10); 
            }break;


            case 16: {
                system("cls");
                ProjectHeader();
                proj.viewPendindProjects();
                cout<<"Redirecting to ADMIN Menu";
                loadingBar("", 5); 
            }break;

            case 17: {
                system("cls");
                ProjectHeader();
                client.checkClientQuery();
                cout<<"Redirecting to ADMIN Menu";
                loadingBar("", 10); 
            }break;
            
            case 18: {
                system("cls");
                ProjectHeader();
                client.showAllClients();
                cout<<"Redirecting to ADMIN Menu";
                loadingBar("", 10); 
            }break;
            

            case 19: {
                system("cls");
                ProjectHeader();
                leave.approveLeave();
                cout<<"Redirecting to ADMIN Menu";
                loadingBar("", 10); 
            }break;

            case 20: {
                system("cls");
                ProjectHeader();
                proj.showAllProjects();
                cout<<"Redirecting to ADMIN Menu";
                loadingBar("", 10); 
            }break;

            case 21: {
                system("cls");
                ProjectHeader();
                cout<<"Generate Quotation for Project is in Progress\n";
                cout<<"We are Sorry for this Inconvenience!\n";
                cout<<"Redirecting to ADMIN Menu";
                loadingBar("", 5); 
            }break;

            case 22: {cout<<"\nLogged-OUT\n";
            //    loadingBar("", 3);
                return;
            }break;

            default: {
                cout << "Invalid Choice!\n"; 
                cout<<"Redirecting to ADMIN Menu"; 
                loadingBar("", 3);
            }break;
        }
    }
}

void whatEmployeeDOES(){

    Company company;
    Client client;
    Salary salary;
    Employee emp;
    Project proj;
    Leave leave;
    Admin HR;

    int choice;

    while (true) {
        system("cls"); 
        ProjectHeader();

        header("   EMPLOYEE DASHBOARD");

        cout << "  PERSONAL DETAILS                           \t\tPROJECT DETAILS\n";
        cout << "  ----------------                           \t\t------------------------\n";
        cout << "  1. View My Profile                         \t\t6. View My Assigned Projects\n";
        cout << "  2. Change Password                         \t\t7. Submit Project Work\n";
        cout << "  3. View My Work History                    \t\t8. View Submitted Projects\n";
        

        cout << "\n  LEAVE MANAGEMENT                         \t\tSALARY DETAILS\n";
        cout << "  ------------------                         \t\t------------------\n";
        cout << "  4. Apply for Leave                         \t\t9. View My Salary Details\n";
        cout << "  5. View Leave Status                       \t\t10. View Salary Slip\n";


        cout << "\n 11. Logout!\t\t\t\t\033[1;33mEnter Your Choice :\033[0m";


        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number.\n";
            Sleep(2000);
            continue;
        }
            cin.ignore();

        switch (choice) {

            case 1: {
                system("cls");
                ProjectHeader();
                emp.displayEmployeeProfile();
                cout<<"Redirecting to EMPLOYEE Menu";
                loadingBar("", 8); 
            }break;

            case 2: {
                system("cls");
                ProjectHeader();
                emp.updateEmployeePassword();
                cout<<"Redirecting to EMPLOYEE Menu";
                loadingBar("", 5); 
            }break;

             case 3: {
                system("cls");
                cout<<"\nWORK HISTORY FEATURE APPEAR IN PHASE II\n";
                cout<<"Redirecting to EMPLOYEE Menu";
                loadingBar("", 3); 
            }break;

            case 4: {
                system("cls");
                ProjectHeader();
                leave.applyLeave();
                cout<<"Redirecting to EMPLOYEE Menu";
                loadingBar("", 5); 
            }break;

            case 5: {
                system("cls");
                ProjectHeader();
                leave.LeaveStatus();
                cout<<"Redirecting to EMPLOYEE Menu";
                loadingBar("", 5); 
            }break;

            case 6: {
                system("cls");
                ProjectHeader();
                proj.projSubmissionfromEmployee();
                cout<<"Redirecting to EMPLOYEE Menu";
                loadingBar("", 6); 
            }break;

            case 11: {cout<<"\nLoggedout!\n";
            //    loadingBar("", 3);
                return;
            }break;

            default: {
                cout << "Invalid Choice!\n"; 
                cout<<"Redirecting to EMPLOYEE Menu"; 
                loadingBar("", 3);
            }break;
        }
    }

}

void whatClientDOES(){

    Company company;
    Client client;
    Salary salary;
    Employee emp;
    Project proj;
    Leave leave;
    Admin HR;

    int choice;   

    while (true) {
        system("cls");
        ProjectHeader();
        header("CLIENT DASHBOARD");

        cout << "  PERSONAL INFORMATION                     \t\tPROJECT TRACKING\n";
        cout << "  ----------------------                   \t\t----------------\n";
        cout << "  1. View My Profile                       \t\t3. View Assigned Project.\n";
        cout << "  2. Change Password                       \t\t4. View Company Profile.\n";

        cout << "\n  COMMUNICATION & SUPPORT\n";
        cout << "  ------------------------\n";
        cout << "  5. Contact Project Manager\n";
        cout << "  6. Raise a Complaint or Query\n";

        cout << "\n  7. Logout!\t\t\t\t\033[1;33mEnter Your Choice :\033[0m";


        // case 8. raiseQueryFromClient
        if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a number.\n";
                Sleep(2000);
                continue;
            }
                cin.ignore();

            switch (choice) {

                case 1: {
                    system("cls");
                    ProjectHeader();
                    client.showClientProfile();
                    cout<<"Redirecting to CLIENT Menu";
                    loadingBar("", 10); 
                }break;

                case 2: {
                    system("cls");
                    ProjectHeader();
                    client.updateClientPassword();
                    cout<<"Redirecting to CLIENT Menu";
                    loadingBar("", 5); 
                }break;

                case 3: {
                    system("cls");
                    ProjectHeader();
                    string ID = client.getClientID();
                    proj.viewAssignedProjectsforClint(ID);
                    cout<<"Redirecting to CLIENT Menu";
                    loadingBar("", 6); 
                }break;

                case 4: {
                    system("cls");
                    ProjectHeader();
                    company.displayCompanyInfo();
                    cout<<"Redirecting to CLIENT Menu";
                    loadingBar("", 10); 
                }break;

                case 5: {
                    system("cls");
                    ProjectHeader();
                    HR.printAdmin();
                    cout<<"Redirecting to CLIENT Menu";
                    loadingBar("", 10); 
                }break;

                case 6: {
                    system("cls");
                    ProjectHeader();
                    client.raiseQueryFromClient();
                    cout<<"Redirecting to CLIENT Menu";
                    loadingBar("", 6); 
                }break;

                case 7: {cout<<"\nLoggedout!\n";
                //    loadingBar("", 3);
                    return;
                }break;

                default: {
                    cout << "Invalid Choice!\n"; 
                    cout<<"Redirecting to CLIENT Menu"; 
                    loadingBar("", 3);
                }break;
        

        }
    }
}

void whatSuperAdminMANIPULATES(){

    SuperAdmin SA;
    Company company;
    Client client;
    Salary salary;
    Employee emp;
    Project proj;
    Leave leave;
    Admin HR;

    int choice;

    while(true){

        system("cls"); 
        ProjectHeader();
        header("SUPER-ADMIN DASHBOARD");

        cout << "  HIGH LEVEL CONTROLS                      \t\tSECURITY & AUTHENTICATION\n";
        cout << "  -------------------                      \t\t-------------------------\n";
        cout << "  1. View Full Admin Details               \t\t5. Reset Any Admin Password\n";
        cout << "  2. Add New Admin                         \t\t6. View/Edit SuperAdmin Info\n";
        cout << "  3. Remove Admin                          \t\t\n";
        cout << "  4. Update Admin\n";
        cout << "\n 7. Logout!\t\t\t\t\t\033[1;33mEnter Your Choice :\033[0m";

        if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a number.\n";
                Sleep(2000);
                continue;
            } cin.ignore();

        switch (choice)
        {
            case 1:{
                system("cls");
                ProjectHeader();
                HR.showFullFledgedAdminDetails();
                cout<<"Redirecting to SUPER Menu"; 
                loadingBar("", 10);
            }break;

            case 2:{
                system("cls");
                ProjectHeader();
                HR.addAdminToFile();
                cout<<"Redirecting to SUPER Menu"; 
                loadingBar("", 6);
            }break;

            case 3:{
                system("cls");
                ProjectHeader();
                HR.deleteAdmin();
                cout<<"Redirecting to SUPER Menu"; 
                loadingBar("", 5);
            }break;

            case 4:{
                system("cls");
                ProjectHeader();
                HR.updateAdmin();
                cout<<"Redirecting to SUPER Menu"; 
                loadingBar("", 6);
            }break;

            case 5:{
                system("cls");
                ProjectHeader();
                HR.resetAnyAdminPassword();
                cout<<"Redirecting to SUPER Menu"; 
                loadingBar("", 6);
            }break;

            case 6:{
                system("cls");
                ProjectHeader();
                SA.SuperAdminDetails();
                cout<<"Redirecting to SUPER Menu"; 
                loadingBar("", 6);
            }break;

            case 7:{
                cout<<"\nLoggedout!\n";
                return;
                }break;

            default:{
                cout << "Invalid Choice!\n"; 
                cout<<"Redirecting to SUPER Menu"; 
                loadingBar("", 3);
            }break;

        }
    }

}

int main() {

    // allConstructorsSavingToFile();
    authenticateUSER();
    
    return 0;
}