#ifndef RAFFLETICKET_H
#define RAFFLETICKET_H

#include <string>

// Node structure to hold each person's name and ticket number.
struct Node {
    std::string name;
    int ticketNumber;
    Node* next;
    
    Node(const std::string& name, int ticketNumber)
        : name(name), ticketNumber(ticketNumber), next(nullptr) {}
};

// This is the raffleTicket class to manage the line of raffle participants.
class raffleTicket {
private:
    Node* front;
    Node* rear;

    // This Function is the Recursive function to count names on the waiting list.
    int countNamesRecursive(Node* node);

    // This Function is the Recursive helper to find the winner by ticket number.
    void drawRaffleWinnerRecursive(Node* node, int ticket);

public:
    raffleTicket();
    ~raffleTicket();

    // This Function is to add a name.
    void addName(const std::string& name);

    // This Function is to check if the ticket number is valid.
    bool isTicketValid(int ticket);

    // This Function is to check if the queue is empty.
    bool isEmpty();

    // This Function is to count the number of names on the waiting list.
    int countNames();

    // This Function is to place an order from the front of the waiting list.
    void placeOrder();

    // This Function is to draw the raffle winner based on the ticket number.
    void drawRaffleWinner(int ticket);

    // This Function is to display the current waiting list.
    void displayLine();

    // This Function is to randomly pick a raffle winner.
    void drawRaffleWinnerRandom();
};

#endif // RAFFLETICKET_H
