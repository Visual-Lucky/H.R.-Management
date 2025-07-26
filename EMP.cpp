#include <bits/stdc++.h>
#include<conio.h>

using namespace std;

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

class Employee{

    char empID[10];
    char empName[20];
    char empPassword[20];
    char empContactNo[20];
    // char empAddress[20];
    // char empType[9];

public:

    string getEmpID(){
        string str = string(empID);
        return str;
    }

    string getEmpName(){
        string str = string(empName);
        return str;
    }

    string getEmpPassword(){
        string str = string(empPassword);
        return str;
    }

    string getEmpContactNo(){
        string str = string(empContactNo);
        return str;
    }    
    
    Employee(){
        strcpy(empID, "EoHRMS000");
        strcpy(empName, "EmployeeofHRMS");
        strcpy(empPassword, "emp@HRMS");
        strcpy(empContactNo, "0000000000");
        // strcpy(empType, "SENIOR");
        //addEmployeeByConstructor();
    }

    void addEmployeeByConstructor(){
        fstream fileOperator;
        fileOperator.open("EMPLOYEE.dat", ios::app | ios::binary);
        fileOperator.write((char*)this, sizeof(*this));
        fileOperator.close();
    }

    void fillEmployeeDetails(){
        cout<<"Enter Name : ";
        cin.getline(empName, 20);
        cout<<"Enter Password : ";
        cin.getline(empPassword, 20);
        cout<<"Enter ContactNo : ";
        cin.getline(empContactNo, 20);
    }

    void addEmployeetoFile(){

        fstream f;
        f.open("EMPLOYEE.dat", ios::app | ios::binary);

        fillEmployeeDetails();
        f.write((char*)this, sizeof(*this));
        
        f.close();
    }   

    void employeeMenu();

    void deleteEmployee(){

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
           deleteEmployeeByEmpID(empID);
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

        int counter = 0;
        while(f_empFind.read((char*)this, sizeof(*this))){
            counter++;
            if(empID == getEmpID()){
                empFound = true;
                break;
            }
        }

        if(empFound){
            updateEmployeeFunction(counter);
        }else{
            cout<<"Employee Not Found!";
        }

        f_empFind.close(); 
    }

    void updateEmployeeFunction(int counter){

        fstream f;

        f.open("EMPLOYEE.dat", ios::out | ios::binary);
        
        f.seekp((counter-1) - sizeof(this));
            takingEmployeeInput();
        f.write((char*)this, sizeof(*this));
        
        // f.seekp();
        f.close();
    }

    void takingEmployeeInput(){
        cout<<"Enter Employee Name : ";
        cin.getline(empName, 19);
        cout<<"Enter Employee Contact No :";
        cin.getline(empContactNo, 10);
    }

    void updateEmployeePassword(){
        string oldPassword = getSafePassword();
        fstream f;
        // int counter = 0;
        bool passAuthenticated = false;
        f.open("EMPLOYEE.dat", ios::in | ios::binary);
        while(f.read((char*)this, sizeof(*this))){
            // counter++;
            if(oldPassword == getEmpPassword()){
                passAuthenticated = true;
                break;
            }
        }
        f.close();

        if(passAuthenticated){
            cout<<"Enter New Password : ";
            cin.getline(empPassword, 9);
            // setNewPassword(empPassword, );
            cout<<"Password Updated Successfully!\n";
        }else{
            cout<<"Incorrect Password!";
        }


    }

    void showAllEmployee(){
        fstream f;
        f.open("EMPLOYEE.dat", ios::in | ios::binary);
        system("cls");
        printEmployeeHeader();
        while(f.read((char*)this, sizeof(*this))){
            printEmployee();
        }

        f.close(); 
    }
    void printEmployee(){

    cout << "| " << left << setw(20) << empID
         << "| " << setw(20) << empName
         << "| " << setw(20) << empPassword
         << "| " << setw(20) << empContactNo
         << "|" << endl;

    cout << "---------------------------------------------------------------------------------------------\n";
    }

    void printEmployeeHeader(){
        cout << "-----------------------------------------------------------------------------------------\n";
    cout << "| " << left << setw(20) << "Emp ID"
         << "| " << setw(20) << "Emp Name"
         << "| " << setw(20) << "Emp Password"
         << "| " << setw(20) << "Emp ContactNo"
         << "|" << endl;
    cout << "--------------------------------------------------------------------------------------------\n";
    }

};

int main(){

    Employee emp;

    int choice;
    cout<<"1. View All Employee"<<endl;
    cout<<"2. Add Employee"<<endl;
    cout<<"3. Delete Employee"<<endl;
    cout<<"4. Update Employee"<<endl;
    cout<<"5. Update Password"<<endl;
    cout<<"6. Exit"<<endl;

    cin>>choice;
    cin.ignore();

    switch (choice)
    {
    case 1: emp.showAllEmployee();
        break;
    
    case 2: emp.addEmployeetoFile();
        break;
       
    case 3: emp.deleteEmployee();
        break;
        
    case 4: emp.updateEmployee();
        break;
        
    case 5: emp.updateEmployeePassword();
        break;    

    case 6: return 0;
        break;

    default:
        break;
    }

    return 0;
}