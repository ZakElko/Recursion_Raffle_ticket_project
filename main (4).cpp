/******************************************************************************
Zakaria Elkhdoary
CISC187 Chapter 20 Recursion
11/19/24
*******************************************************************************/ 
#include "raffleTicket.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

// Function to validate that the menu selection is between 1 and 6.
bool isValidMenuChoice(int selection) {
    return (selection >= 1 && selection <= 6);
}

// Function to validate that the input name only contains alphabetic characters and spaces.
bool isValidName(const std::string& name) {
    if (name.empty()) {
        return false;
    }
    for (char ch : name) {
        if (!isalpha(ch) && ch != ' ') {
            return false;
        }
    }
    return true;
}

// Function to validate if the input is a number.
bool isValidNumber(const std::string& input) {
    for (char ch : input) {
        if (!isdigit(ch)) {
            return false;
        }
    }
    return true;
}

// Function to display the menu.
void displayMenu() {
    std::cout << "----------------------------------------------";
    std::cout << "\n Enter a number from the list below:\n";
    std::cout << "----------------------------------------------\n";
    std::cout << "1. Enter 1, type your name, and I will put your name into the raffle!\n";
    std::cout << "2. Enter 2 to place an order.\n";
    std::cout << "3. Enter 3 and I will provide a count of the people in line.\n";
    std::cout << "4. Enter 4 and I will draw a winner from the raffle!\n";
    std::cout << "5. Enter 5 and i will display all the people currently in line.\n";
    std::cout << "6. Enter 6 to Exit the program. \n";
    std::cout << "\n Enter any number 1-6: ";
}

int main() {
    srand(static_cast<unsigned>(time(0))); // Random number generation.
    raffleTicket obj1;
    int selection;

    do {
        displayMenu();

        std::string input;
        std::cin >> input;

        // Validate menu selection to ensure it is a number between 1 and 6.
        if (!isValidNumber(input) || !isValidMenuChoice(selection = std::stoi(input))) {
            std::cout << "Invalid entry. Please enter a number between 1 and 6 from the menu.\n";
            std::cin.clear();  
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
            continue;
        }

        switch (selection) {
            case 1: {
                std::string name;
                std::cout << "Please enter your name:";
                std::cin.ignore();  
                std::getline(std::cin, name);

                // Validate the input name.
                if (!isValidName(name)) {
                    std::cout << "Sorry pal, names only contain alphabetic characters please try again...\n";
                } else {
                    obj1.addName(name);
                }
                break;
            }
            case 2:
                if (obj1.isEmpty()) {
                    std::cout << "No one is on the waiting list to place an order yet!\n";
                } else {
                    obj1.placeOrder();
                }
                break;
            case 3: {
                if (obj1.isEmpty()) {
                    std::cout << "No one is on the waiting list yet!\n";
                } else {
                    int count = obj1.countNames();
                    std::cout << "There are/is " << count << " people/person in line.\n";
                }
                break;
            }
            case 4: {
                std::cout << "The raffle winner is!!!!\n";
                obj1.drawRaffleWinnerRandom(); // Randomly draw a winner.
                break;
            }
            case 5:
                if (obj1.isEmpty()) {
                    std::cout << "Sorry, No one is on the waiting list please add your name.\n";
                } else {
                    obj1.displayLine();
                }
                break;
            case 6:
                std::cout << "Sea ya later gator.\n";
                break;
            default:
                std::cout << "Not a valid entry my friend. Please try again.\n";
        }
    } while (selection != 6);

    return 0;
}
 