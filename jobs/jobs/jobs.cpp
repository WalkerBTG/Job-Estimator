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

string askYesOrNo(string question) {
    bool valid =  false;
    string option;
    while (!valid) {
        cout << "Please enter " << question;
        cin >> option;
        transform(option.begin(), option.end(), option.begin(), ::toupper);
        if (option == "YES" || option == "NO") {
            valid = true;
        }


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
    cout << "1. Economy (\x9C 0.55 per square metre)\n";
    cout << "2. Standard (\x9C 2.00 per square metre)\n";
    cout << "3. Luxury (\x9C 2.75 per square metre)\n";
    cout << "===============================\n";
    option = askInt("choice", 1, 3);

    float costs[3] = { 0.55, 2.00, 2.75 };
    return costs[option - 1];
}

void displayQuote(string name, string date, float area, float paintCost, float undercoatCost) {
    cout << "Estimate\n";
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++\n";
    cout << "Customer name :\t" << name << "\n";
    cout << "Estimate date :\t" << date << "\n";
    cout << "Wall area :\t" << area << "\n";
    cout << "Wall cost :\t\x9C" << paintCost << "\n";
    cout << "Undercoat cost :\t\x9C" << undercoatCost << "\n";
    cout << "=================\n";

    float total = paintCost + undercoatCost;
    cout << "Grand total :\t\x9C" << total <<  "\n";
    
    cout << "=================\n";
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
    float undercoatCost = 0;
    string undercoat;

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
            paintCost = paintMenu() * area;

            // ask about under coat 
            undercoat = askYesOrNo("would you like undercoat? ");
            if (undercoat == "YES") {
                int tins = askInt("how many tins?", 1, 100);
                undercoatCost = tins * 8.99;
            }

            displayQuote(name, date, area, paintCost, undercoatCost);
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
