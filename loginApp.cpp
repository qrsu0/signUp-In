#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct user {
	string username;
	string name;
	string password;
	int age;
};
void signup();
void signin();

int main() {
	signup();
    signin();
}

void signup() {
	user newuser;
	ofstream account("account.txt", ios::app);
	cout << "Create a username: ";
	cin >> newuser.username;
	cout << "\nWrite down your name: ";
	getline(cin >> ws, newuser.name);
	cout << "\nWhats your age: ";
	cin >> newuser.age;
	cout << "\nWrite down a pssowrd: ";
	getline(cin >> ws, newuser.password);
	
	// Store the username and password together
	account << newuser.username << " " << newuser.password << " "
		<< newuser.name << " " << newuser.age << endl;
	account.close();
	
	
}
void signin() {
    user olduser;
    ifstream accountlogin("account.txt");
    if (!accountlogin) {
        cout << "Error opening file." << endl;
        return;
    }
    cout << "Enter your username: ";
    cin >> olduser.username;
    cout << "Enter your password: ";
    cin >> olduser.password;

    string combinedInput = olduser.username + " " + olduser.password;
    string line;
    bool found = false;

    while (getline(accountlogin, line)) {
        if (line.find(combinedInput) == 0) { // Check if line starts with combinedInput
            found = true;
            cout << "Login successful!" << endl;
            break;
        }
    }
    if (!found) {
        cout << "Username or password incorrect." << endl;
    }
    accountlogin.close();
}