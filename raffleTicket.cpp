#include "raffleTicket.h"
#include <cstdlib>
#include <ctime>
#include <iomanip> 
#include <iostream>  

// The Constructor. 
raffleTicket::raffleTicket() : front(nullptr), rear(nullptr) {}

// The Destructor.  
raffleTicket::~raffleTicket() {
    Node* current = front;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

// This Function is to add a name to the queue with a unique ticket number.
void raffleTicket::addName(const std::string& name) {
    int ticketNumber = rand() % 500 + 1;  // Get a random ticket number between 1 and 500.
    Node* newNode = new Node(name, ticketNumber);

    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    std::cout << "Added " << name << " with raffle ticket #" << ticketNumber << ".\n";
}

// This Function is to check if a raffle ticket is in the queue. 
bool raffleTicket::isTicketValid(int ticket) {
    Node* current = front;
    while (current != nullptr) {
        if (current->ticketNumber == ticket) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// This Function is to check if the queue is empty.
bool raffleTicket::isEmpty() {
    return front == nullptr;
}

// This Function is to count the number of names in the queue using recursion.
int raffleTicket::countNames() {
    return countNamesRecursive(front);
}

// This Function is the Recursive helper function for counting names.
int raffleTicket::countNamesRecursive(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return 1 + countNamesRecursive(node->next);
}

// This Function is to allow the front of the line to place an order.
void raffleTicket::placeOrder() {
    if (front == nullptr) {
        std::cout << "No one is on the waiting list to place an order.\n";
        return;
    }

    Node* orderNode = front;
    std::cout << orderNode->name << " is placing an order.\n";
    front = front->next;
    delete orderNode;
}

// This Function is to draw a raffle winner using recursion.
void raffleTicket::drawRaffleWinner(int ticket) {
    drawRaffleWinnerRecursive(front, ticket);
}

// This Function is the Recursive helper function to locate the person with the ticket number.
void raffleTicket::drawRaffleWinnerRecursive(Node* node, int ticket) {
    if (node == nullptr) {
        std::cout << "No one with ticket number " << ticket << " is on the waiting list.\n";
        return;
    }
    if (node->ticketNumber == ticket) {
        std::cout << "The raffle winner is " << node->name << " ticket #" << ticket << ".\n";
        return;
    }
    drawRaffleWinnerRecursive(node->next, ticket);  
}

// This Function will display the current waiting list with ticket numbers and positions.
void raffleTicket::displayLine() {
    Node* current = front;
    int position = 1;
    if (current == nullptr) {
        std::cout << "The waiting list is empty.\n";
    } else {
        std::cout << "Current waiting list:\n";
                                                      // Format columns for alignment.
        while (current != nullptr) {
            std::cout << "Position: " << std::setw(3) << position 
                      << ", Name: " << std::setw(20) << current->name
                      << ", Ticket: " << std::setw(3) << current->ticketNumber << "\n";
            current = current->next;
            position++;
        }
    }
}

// This Function will randomly pick a raffle winner from the queue.
void raffleTicket::drawRaffleWinnerRandom() {
    if (front == nullptr) {
        std::cout << "No one is in the raffle yet.\n";
        return;
    }

    // Count the number of entries.
    int count = countNames();
    int randomIndex = rand() % count;

    Node* current = front;
    for (int i = 0; i < randomIndex; ++i) {
        current = current->next;
    }

    std::cout << "The raffle winner is " << current->name << " with ticket #" << current->ticketNumber << ".\n";
}
 