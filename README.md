**RideFinder** : A Ride-hailing system
This C program simulates a ride-sharing system. It allows users to add drivers and passengers, request rides, calculate fares, cancel rides, and complete rides. The program manages the availability of drivers and the status of passengers, ensuring that rides are assigned, canceled, and completed correctly.

Features
1. Driver Management
  - Add drivers with details such as name, car details, and location.
  - Display the list of all drivers with their current status and location.
2. Passenger Management
  - Add passengers with details such as name, initial location, and destination.
  - Display the list of all passengers with their ride status.
3. Ride Requests
  - Request a ride for a passenger by finding the nearest available driver.
  - Automatically cancel rides if the nearest driver is more than 4 km away.
4. Fare Calculation
  - Calculate the fare for a completed ride based on the distance traveled.
5. Ride Cancellation and Completion
  - Cancel an ongoing ride and make the driver available again.
  - Complete a ride, calculate the fare, and make the driver available for new rides.
6. Display Options
  - View the list of drivers and their availability status.
  - View the list of passengers and their ride status.

Instructions to run the Ride-Hailing System C program successfully, follow the steps below :

Prerequisites : 
  - A C compiler (e.g., GCC)
  - A command-line interface (CLI) or integrated development environment (IDE) that supports C programming

Steps to Execute : 

1. Compile the Code.
2. Run the Program.
3. Program Execution Flow : 
  Follow the prompts in the program
  i. Add Drivers:
    - The program will prompt you to enter driver details.
    - Enter the driver's name, car details, and location coordinates (x y).
    - After adding a driver, you can choose to add another driver or proceed to the next step.
  ii. Add Passengers:
    - The program will prompt you to enter passenger details.
    - Enter the passenger's name, initial location coordinates (x y), and destination coordinates (x y).
    - After adding a passenger, you can choose to add another passenger or proceed to the main menu.
  iii. Main Menu:
  The main menu provides various options:
    - Request a Ride: Enter the index of the passenger who wants to request a ride. The program will find the nearest available driver and assign the ride.
    - Calculate Ride Fare: If a ride is assigned and not canceled, the program will calculate and display the fare based on the distance traveled.
    - Cancel a Ride: Cancel an ongoing ride, making the driver available again.
    - Complete a Ride: Complete the ongoing ride, calculate the fare, and make the driver available again.
    - Display Drivers List: Display a list of all drivers with their current status and location.
    - Display Passengers List: Display a list of all passengers with their ride status.
  iv. Exit: Exit the program.
