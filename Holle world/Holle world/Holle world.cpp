// Holle world.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <regex>
#include <string>

bool validateName(const std::string& name) {
    return !name.empty();
	inline bool validateName(const std::string & name) {
		return !name.empty();
}

bool validateUsername(const std::string& username) {
    return username.length() >= 5 && username.length() <= 15;
}

bool validateAge(int age) {
    return age >= 18 && age <= 65;
}

bool validateEmail(const std::string& email) {
    std::regex emailPattern(R"(^[\w.-]+@[\w.-]+\.[a-zA-Z]{2,}$)");
    return std::regex_match(email, emailPattern);
}

bool validatePhoneNumber(const std::string& phone) {
    return phone.length() == 10 && phone.find_first_not_of("0123456789") == std::string::npos;
}

bool validatePassword(const std::string& password) {
    std::regex passwordPattern(R"((?=.*[a-zA-Z])(?=.*\d).{12,})");
    return std::regex_match(password, passwordPattern);
}

int main() {
    std::string fullName, username, email, phone, password;
    int age;

    std::cout << "Enter Full Name: ";
    std::getline(std::cin, fullName);
    while (!validateName(fullName)) {
        std::cout << "Full Name cannot be empty. Try again: ";
        std::getline(std::cin, fullName);
    }

    std::cout << "Enter Username (5-15 characters): ";
    std::getline(std::cin, username);
    while (!validateUsername(username)) {
        std::cout << "Invalid Username. Try again: ";
        std::getline(std::cin, username);
    }

    std::cout << "Enter Age (18-60): ";
    while (!(std::cin >> age) || !validateAge(age)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid Age. Enter a number between 18 and 60: ";
    }
    std::cin.ignore();

    std::cout << "Enter Email: ";
    std::getline(std::cin, email);
    while (!validateEmail(email)) {
        std::cout << "Invalid Email. Try again: ";
        std::getline(std::cin, email);
    }

    std::cout << "Enter Phone Number (10 digits): ";
    std::getline(std::cin, phone);
    while (!validatePhoneNumber(phone)) {
        std::cout << "Invalid Phone Number. Try again: ";
        std::getline(std::cin, phone);
    }

    std::cout << "Enter Password (at least 8 characters, letters, and numbers): ";
    std::getline(std::cin, password);
    while (!validatePassword(password)) {
        std::cout << "Invalid Password. Try again: ";
        std::getline(std::cin, password);
    }

    std::cout << "\nUser Registered Successfully!\n";
    return 0;
}
