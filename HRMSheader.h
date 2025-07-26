#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime> 
#include <string>

using namespace std;

string getCurrentDateTime();
string getCurrentDate();
string getCurrentTime();

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void loadingBar(string message, int count) {
    cout << message;
    for (int i = 1; i < count; i++) {
        cout << ".";
        Sleep(1000);  // 200 milliseconds = 0.2 seconds
    }
    cout << "\n";
    //TO CALL ->loadingBar("Loading", 5);
}

void header(string dashboard){

    string result(37, ' '), oneLiner(102, '-');
    // cout<<oneLiner<<endl;
    cout<<result<<dashboard<<endl;
    cout<<oneLiner<<endl;
    // TO CALL -> header("HEADING");
}

string getSafePassword() {
    string password;
    char ch;
    cout << "Enter Password: ";
    while (true) {
        ch = getch();
        if (ch == 13) break; 
        else if (ch == 8) {
            if (!password.empty()) {
                password.pop_back();
                cout << "\b \b";
            }
        } else {
            password += ch;
            cout << "*";
        }
    }
    return password;
}

string getEnterSpecialWord() {
    string specialword;
    char ch;
    cout << "\nDrop Magical Word : ";
    while (true) {
        ch = getch();
        if (ch == 13) break; 
        else if (ch == 8) {
            if (!specialword.empty()) {
                specialword.pop_back();
                cout << "\b \b";
            }
        } else {
            specialword += ch;
            cout << "*";
        }
    }
    return specialword;
}

void ProjectHeader() {
    cout << setfill('-') << setw(100) << "-" << endl;
    cout << setfill(' ') << setw(32) << " " << "HUMAN RESOURCE MANAGEMENT SYSTEM" << endl;
    cout << setfill('-') << setw(100) << "-" << endl;
    cout << setfill(' ');
}

void CompanyHeader(){
    cout << setfill('-') << setw(100) << "-" << endl;
    cout << setfill(' ') << setw(36) << " " << "Shree Geeta Infotech" << endl;
    cout << setw(25) << " " << "286, Ajmer-Road, Bhilwara, Rajasthan [311001]" << endl;
    cout << setw(20) << " " << "Contact: +91-7849998407  |  Email: info@shreeGEETAinfotech.in" << endl;
    cout << setfill('-') << setw(100) << "-" << endl;
    cout << "DATE : " << getCurrentDate() << "\t\t\t\t\t\t\t\t     TIME : " << getCurrentTime() << endl;
    // cout << setfill('-') << setw(100) << "-" << endl;
}

string getCurrentDateTime() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", ltm);

    return string(buffer);
}

string getCurrentDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", ltm);
    return string(buffer);
}

string getCurrentTime() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%H:%M:%S", ltm);
    return string(buffer);
}

string getCurrentDate_DDMMYYYY() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%d-%m-%Y", ltm);
    return string(buffer);
}

// void lineGenerator() {
//     cout << setfill('-') << setw(100) << "-" << endl;
//     cout << setfill(' '); // RESET to space after drawing line
// }