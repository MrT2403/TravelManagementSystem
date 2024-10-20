Customer Management and Booking System
This is a C++ console-based application that provides functionalities for managing customer data, cab bookings, and hotel reservations. The system supports two types of users: admin and user. Admins have extended privileges, such as viewing and searching customer details.

- Features
User Roles:
Admin:
Can register customers and view all customer data.
Can search for customers by ID or name.
User:
Can enter their own details (stored for future reference).
Can book cabs and hotels.

- Functional Modules:
Customer Management
Register new customers.
Validate mobile numbers (10-digit format).
Save customer data to old-customers.txt.
Admin access to all registered customer details.
Search customer details by ID or name.

Cab Booking
Rent a Standard Cab (15 USD per KM).
Rent a Luxury Cab (25 USD per KM).
Calculate and display the total fare based on travel distance.

Hotel Booking
Choose from 3 hotel options: Avendra, ChoiceYou, ElephanBay.
Select a package: Standard, Premium, or Luxury.
Display booking confirmation with total cost.

- Installation & Usage
Prerequisites
A C++ compiler (e.g., g++ or Visual Studio)
Windows OS (as it uses windows.h for clearing the console and pauses)

Clone the Repository
git clone https://github.com/your-username/Customer-Management-System.git
cd Customer-Management-System

Compile the Code
g++ main.cpp -o main

Run the Program
./main
Program Flow
Login Prompt:

Enter name and role (admin or user).
If the role is invalid, the program exits.

- Main Menu Options:
Customer Information: Add customer details.
Cab Booking: Book a cab by specifying the type and travel distance.
Hotel Booking: Choose a hotel and select a package.
Exit: Exit the application.
(Admin only) View and search customer data.
