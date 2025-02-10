// jobs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
// ask the user to a number 5
int mainMenu() {
   int option;
  
    cout << "========== Main Menu ==========\n";
    cout << "1. Help\n";
    cout << "2. Job Estimator\n";
    cout << "3. Exit\n";
    cout << "===============================\n";
    bool valid = false;
    while (!valid) {
        cout << "Please enter option 1,2 or 3 to exit :";
        if (cin >> option){
            valid = option >= 1 && option <= 3;
        }// this if the user enter a str
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
           
    }
     return option;
}
// Main entry
int main()
{
    bool running = true;
    string name;
    while (running) {
        int option = mainMenu();
        switch (option)
        {
        case 1:
            cout << "help";
            break;
        case 2:
            cout << "please enter your name";
            cin >> name; 
            break;
        case 3:
            running = false;
            break;



        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
