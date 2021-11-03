#include <iostream>
#include <fstream>
#include <string>
using namespace std;


const string DB_FILE_NAME = "usersDB.txt";
const double MIN_BALANCE = 100; // KES 100
const double MAX_WITHDRAWAL = 100000; // KES 100000


bool login(string username, string password){
    string uName, uPassword;

    cout<< "Enter username: "; cin>> uName;
    cout<< "Enter password: "; cin>> uPassword;

    ifstream read(DB_FILE_NAME);
    getline(read, uName);
    getline(read, uPassword);

    if(uName==username && uPassword==password){
        return true;
    }
    return false;
}

void registerCustomer() {
    string username, password, email;
    int balance;

    cout<< "Enter username: "; cin >> username;
    cout<< "Enter username: "; cin >> email;
    cout<< "Enter password: "; cin >> password;
    cout<< "Enter Initial balance: "; cin >> balance;

    // save this data
    ofstream dbFile;
    dbFile.open(DB_FILE_NAME);
    if (!dbFile.is_open()) {
        cout << "File can't be opened!";
    } else {
        dbFile << username;
        dbFile << email;
        dbFile << password;
        if (balance >= MIN_BALANCE) {
            dbFile << balance;
        }
        dbFile.close();
        cout << "New customer successfully registered!";
    }
}

void deposit(double amount) {
    double balance = 0.0; // get actual balance of customer
    // update balance
    balance =+ amount;
    // save the balance
}

void withdraw(double amount) {
    double balance = 0.0; // get actual balance of customer
    double remaining =  balance - amount;

    if (amount > balance || remaining < MIN_BALANCE) {
        cout << "Can't withdraw...";
    } else {
        balance -= amount;
        // save
    }
}

void accountStatus() {
    // display customer account info
}

void changePasswordTo(string newPassword) {
    string password; // get the old pass
    password = newPassword;
    // save
}

int main(){
    int choice;
    cout<< "1: Register\n2: Login\n Your choice"; cin>>choice;
    if(choice == 1){
        string username, password;

        cout<< " select a username: "; cin>> username;
        cout<< "select a password: "; cin>> password;

        ofstream file;
        file.open("data\\"+username+".txt");
        file << username<<endl<<password;
        file.close();

        main();
    }
    else if(choice==2){
        bool status = login();
        if(!status){
            cout<<"false login"<<endl;
            system("PAUSE");
            return 0;
        } else{
            cout<<"successfully logged in "<<endl;
            system("PAUSE");
            return 1;
        }


    }
    return 0;
}
