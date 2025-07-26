#include <bits/stdc++.h>
#include <conio.h>

//Header File from MAIN Folder
#include "HRMSheader.h"

using namespace std;

/* OPERATIONAL FUNCTIONS */
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

/* CLASSES */
class Admin{

    char adminType[6]; // HR & ADMIN
    char adminID[10];
    char adminName[20];
    char adminPassword[13];
    char adminContactNo[11];

public:
/* Acessing Data Members from Public Functions */
    string getAdminType(){
        string str = string(adminType);
        return str;
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

/* ConsTructor */
    Admin(){
        strcpy(adminID, "AoHRMS00");
        strcpy(adminName, "AdminofHRMS");
        strcpy(adminPassword, "Admin@HRMS");
        strcpy(adminContactNo, "1234");
        strcpy(adminType, "ADMIN");
        addAdmin();
    }
    
/* PUBLIC FUNCTIONS */     
    void addAdmin(){
        fstream fileOperator;
        fileOperator.open("ADMIN_testing.dat", ios::out | ios::binary);

        fileOperator.write((char*)this, sizeof(*this));
        // cout << "Size of Admin at WRITTING: " << sizeof(*this) << endl;

        fileOperator.close();
    }

    void adminDetailsReadingfromFile(){
        fstream f;

        f.open("ADMIN_testing.dat", ios::in | ios::binary);

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

    bool authenticateAdmin(){
        fstream fileOperator;
        fileOperator.open("ADMIN_testing.dat", ios::in | ios::binary);

        bool userFound = false;
        bool passAuth = false;

        string userName;
        cout<<"\nEnter Admin ID :";
        getline(cin, userName);


        while(fileOperator.read((char*)this, sizeof(*this)))
        {
            if(userName == getAdminID()){
                userFound = true;
                break;
            }
        }

        fileOperator.close();

        if(userFound){
            string password;
            password = getSafePassword();

            fileOperator.open("ADMIN_testing.dat", ios::in | ios::binary);

            while(fileOperator.read((char*)this, sizeof(*this)))
                {
                if(password == getAdminPassword()){
                    // cout<<"\nPASSWORD MATCHED FROM FILE\n";
                        passAuth = true;
                        break;
                    }
                }
            
                    fileOperator.close();

                if(passAuth){

                cout << "\n \033[1;32mAuthenticated\033[0m" << endl;
                return true;
                }

                else{
                    cout<<"\n\033[1;31mIncorrect Password\033[0m";

                    return false;
                }
        }
        else{
            cout << "\n \033[1;31mAdmin Not Found\033[0m" << endl;
            return false;
        }
        
    }

    bool adminLogin(){
        bool isAuthenticated;

        isAuthenticated = authenticateAdmin();
    
        return isAuthenticated;
    }

    void show_user()
    {
        fstream f;
        system("clear");
        cout << "\n================================ All user details =========================================\n\n";
        f.open("ADMIN_testing.dat", ios::in | ios::binary);
        int serial = 1;

        cout << "--------------------------------------------------------------------------------------\n";
        cout << "| " << left << setw(5) << "S.No"
            << "| " << setw(20) << "Name"
            << "| " << setw(20) << "Username"
            << "| " << setw(15) << "Password"
            << "| " << setw(15) << "Mobile Number"
            << "|" << endl;
        cout << "--------------------------------------------------------------------------------------\n";

        while (f.read((char*)this, sizeof(*this)))
        {
            user_output(serial++);
        }
        f.close();
    }

    void user_output(int serial)
    {
        cout << "| " << left << setw(5) << serial
            << "| " << setw(20) << adminName
            << "| " << setw(20) << adminID
            << "| " << setw(15) << ""  // Password hidden
            << "| " << setw(15) << adminContactNo
            << "|" << endl;

        cout << "--------------------------------------------------------------------------------------\n";
    }

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

int main(){

    Admin HR;

    HR.show_user();

    // bool isAdminAuthenticated = HR.adminLogin();

    // if(isAdminAuthenticated){
    //     // HR.adminMenu();
    //     cout<<"WELCOME "<<HR.getAdminName()<<endl;
    //     Sleep(2);
    // }else{
    //     //cout<<"\n \033[1;31mNeed Admin Credentials for Admin LOGIN\033[0m \n";
    //     cout<<"\nNeed Admin Credentials for ADMIN login!!\n";
    // }

    
    return 0;
}