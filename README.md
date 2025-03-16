# Raffle Ticket System - Recursion

## Author:
Zakaria Elkhodary  
Date: 11/19/2024  

## Description:
This program implements a **raffle ticket system** with a menu-driven interface. It allows users to enter their names into a raffle, place orders, track the queue, and randomly select a winner using **recursion**. The program ensures proper input validation, making it user-friendly and robust.

## Features:
- **Raffle Entry:** Users can input their names, which are validated for correct format.
- **Queue Management:** The program tracks the number of people in line and displays all participants.
- **Order Processing:** Users can place orders if they are in the queue.
- **Raffle Drawing:** A random winner is selected using recursion.
- **Input Validation:** Ensures correct menu selection, valid names, and numeric input handling.

## Technologies Used:
- **C++** (Standard Library)
- `cstdlib`, `ctime` for random number generation
- `limits` for input handling
- Custom class **`raffleTicket`** (assumed to handle raffle operations)

## How to Run:
1. Compile the program using a C++ compiler:
