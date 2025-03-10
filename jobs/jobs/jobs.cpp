// jobs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int askInt(string question, int min, int max) {
    bool valid = false;
    int option;
    while (!valid) {
        cout << "Please enter " << question << " (" << min << "-" << max << ")";
        if (cin >> option) {
            valid = option >= min && option <= max;
        }// this if the user enter a str
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return option;
}

int askYesOrNo(string question) {
    bool valid =  false;
    string option;
    while (!valid) {
        cout << "Please enter " << question;
        cin >> option;
        transform(option.begin(), option.end(), option.begin(), ::toupper);
            
    }
    return option;
}

float askFloat(string question, float min, float max) {
    bool valid = false;
    float option;
    while (!valid) {
        cout << "Please enter " << question << " (" << min << "-" << max << ")";
        if (cin >> option) {
            valid = option >= min && option <= max;
        }// this if the user enter a str
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return option;
}

// ask the user to choose option 
int mainMenu() {
   int option;
  
    cout << "========== Main Menu ==========\n";
    cout << "1. Help\n";
    cout << "2. Job Estimator\n";
    cout << "3. Exit\n";
    cout << "===============================\n";
    option = askInt("choice", 1, 3);
     return option;
}
 
// ask the user to choose option 
float paintMenu() {
    int option;

    cout << "========== Choose paint option  ==========\n";
    cout << "1. Economy (£0.55 per square metre)\n";
    cout << "2. Standard (£2.00 per square metre)\n";
    cout << "3. Luxury (£2.75 per square metre)\n";
    cout << "===============================\n";
    option = askInt("choice", 1, 3);

    float costs[3] = { 0.55, 2.00, 2.75 };
    return costs[option - 1];
}

// Main entry
int main()
{
    bool running = true;
    string name;
    string date;
    float height;
    float length;
    float area;
    float paintCost;

    while (running) {
        int option = mainMenu();
        switch (option)
        {
        case 1:
            cout << "help";
            break;
        case 2:
            cout << "please enter your name: ";
            cin >> name; 
            cout << "please enter date: ";
            cin >> date;
            height = askFloat("height (m)", 2, 6);
            length = askFloat("length (m)", 1, 25);

            // calculate area 
            area = height * length;
            paintCost = paintMenu();
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
