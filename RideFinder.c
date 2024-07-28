/*
You are tasked with implementing a basic ride-hailing system in C. The system should handle drivers and passengers, allowing the following functionalities:

    1. Add Drivers: Add new drivers with their name, car details, and location. Each driver has an availability status (available or not).
    2. Add Passengers: Add new passengers with their name, initial location, and destination location. Each passenger has a ride cancelled status.
    3. Request a Ride: Allow a passenger to request a ride. The system should find the nearest available driver. If the distance between the driver and the passenger is greater than 4 km, the ride should be automatically cancelled.
    4. Calculate Ride Fare: After a ride is assigned and completed, calculate the fare based on the distance travelled. The fare calculation should include a base fare and a per-kilometre charge.
    5. Cancel a Ride: Allow a passenger to cancel their ride, which makes the driver available again.
    6. Complete a Ride: Complete the ride, calculate the fare, and make the driver available again.
    7. Display Drivers and Passengers: Display the list of all drivers and passengers with their details.

Your code should implement the following:

Data Structures: Use structures to store details of drivers and passengers. The Location structure should store coordinates for locations, the Driver structure should store driver details and availability, and the Passenger structure should store passenger details and ride cancellation status.

Functions:
1. findNearestDriver(): Determine the nearest available driver to a passenger’s initial location.
2. calculateRideFare(): Compute the fare based on the distance travelled.
3. shouldCancelRide(): Determine if a ride should be automatically cancelled based on distance.
4. displayDrivers(): Display details of all drivers.
5. displayPassengers(): Display details of all passengers.

Main Menu: Provide a menu for the user to choose from the following options:
    - Request a ride.
    - Calculate the fare of the assigned ride.
    - Cancel the assigned ride.
    - Complete the assigned ride.
    - Display the list of drivers.
    - Display the list of passengers.
    - Exit the program.

Requirements:
    - Ensure that once a ride is cancelled, the driver becomes available for new ride requests.
    - Ensure that fare calculation is performed only if the ride is valid and not cancelled.
    - Implement error handling for invalid indices and choices.
    - Provide an option to add multiple drivers and passengers with a confirmation prompt for adding more.
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

struct Location
{
    float x;
    float y;
};

struct Driver
{
    char name[50];
    char carDetails[50];
    int availability;
    struct Location location;
};

struct Passenger
{
    char name[50];
    struct Location initialLocation;
    struct Location destinationLocation;
    int rideCancelled;
};

int findNearestDriver(struct Driver drivers[], int numDrivers, struct Location passengerLocation)
{
    int nearestDriverIndex = -1;
    float minDistance = INFINITY;

    for (int i = 0; i < numDrivers; ++i)
    {
        if (drivers[i].availability)
        {
            float distance = sqrt(pow(passengerLocation.x - drivers[i].location.x, 2) + pow(passengerLocation.y - drivers[i].location.y, 2));
            if (distance < minDistance)
            {
                minDistance = distance;
                nearestDriverIndex = i;
            }
        }
    }

    return nearestDriverIndex;
}

float calculateRideFare(float distance)
{
    float baseFare = 5.0;
    float farePerKm = 2.0;
    return baseFare + farePerKm * distance;
}

int shouldCancelRide(struct Driver driver, struct Passenger passenger)
{
    float distance = sqrt(pow(passenger.initialLocation.x - driver.location.x, 2) + pow(passenger.initialLocation.y - driver.location.y, 2));
    return (distance > 4.0);
}

void displayDrivers(struct Driver drivers[], int numDrivers)
{
    printf("\nDrivers List:\n");
    for (int i = 0; i < numDrivers; ++i)
    {
        printf("Index: %d, Name: %s, Car: %s, Location: (%.2f, %.2f), Availability: %s\n",
               i, drivers[i].name, drivers[i].carDetails, drivers[i].location.x, drivers[i].location.y,
               drivers[i].availability ? "Available" : "Not Available");
    }
}

void displayPassengers(struct Passenger passengers[], int numPassengers)
{
    printf("\nPassengers List:\n");
    for (int i = 0; i < numPassengers; ++i)
    {
        printf("Index: %d, Name: %s, Initial Location: (%.2f, %.2f), Destination: (%.2f, %.2f), Ride Cancelled: %s\n",
               i, passengers[i].name, passengers[i].initialLocation.x, passengers[i].initialLocation.y,
               passengers[i].destinationLocation.x, passengers[i].destinationLocation.y,
               passengers[i].rideCancelled ? "Yes" : "No");
    }
}

int main()
{
    const int MAX_DRIVERS = 10;
    struct Driver drivers[MAX_DRIVERS];
    int numDrivers = 0;

    const int MAX_PASSENGERS = 10;
    struct Passenger passengers[MAX_PASSENGERS];
    int numPassengers = 0;

    int choice;
    int rideAssignedPassengerIndex = -1;
    int rideAssignedDriverIndex = -1;

    // Step 1: Add Drivers
    printf("\nStep 1: Add Drivers\n");
    while (numDrivers < MAX_DRIVERS)
    {
        printf("\nEnter Driver Name: ");
        scanf("%s", drivers[numDrivers].name);
        printf("Enter Car Details: ");
        scanf("%s", drivers[numDrivers].carDetails);
        printf("Enter Driver Location (x y): ");
        scanf("%f %f", &drivers[numDrivers].location.x, &drivers[numDrivers].location.y);
        drivers[numDrivers].availability = 1;
        numDrivers++;
        printf("Driver added successfully! (Total Drivers: %d)\n", numDrivers);

        printf("\nDo you want to add another driver? (1 for Yes, 0 for No): ");
        int addAnotherDriver;
        scanf("%d", &addAnotherDriver);
        if (!addAnotherDriver)
        {
            break;
        }
    }

    // Step 2: Add Passengers
    printf("\nStep 2: Add Passengers\n");
    while (numPassengers < MAX_PASSENGERS)
    {
        printf("\nEnter Passenger Name: ");
        scanf("%s", passengers[numPassengers].name);
        printf("Enter Initial Location (x y): ");
        scanf("%f %f", &passengers[numPassengers].initialLocation.x, &passengers[numPassengers].initialLocation.y);
        printf("Enter Destination Location (x y): ");
        scanf("%f %f", &passengers[numPassengers].destinationLocation.x, &passengers[numPassengers].destinationLocation.y);
        passengers[numPassengers].rideCancelled = 0;
        numPassengers++;
        printf("Passenger added successfully! (Total Passengers: %d)\n", numPassengers);

        printf("\nDo you want to add another passenger? (1 for Yes, 0 for No): ");
        int addAnotherPassenger;
        scanf("%d", &addAnotherPassenger);
        if (!addAnotherPassenger)
        {
            break;
        }
    }

    // Main Menu
    do
    {
        printf("\nMain Menu\n");
        printf("1. Request a Ride\n");
        printf("2. Calculate Ride Fare\n");
        printf("3. Cancel a Ride\n");
        printf("4. Complete a Ride\n");
        printf("5. Display Drivers List\n");
        printf("6. Display Passengers List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (numPassengers > 0 && numDrivers > 0)
            {
                printf("Enter Passenger Index: ");
                int passengerIndex;
                scanf("%d", &passengerIndex);

                if (passengerIndex >= 0 && passengerIndex < numPassengers)
                {
                    passengers[passengerIndex].rideCancelled = 0;  // Reset ride cancelled status

                    printf("Finding nearest driver...\n");
                    int nearestDriverIndex = findNearestDriver(drivers, numDrivers, passengers[passengerIndex].initialLocation);

                    if (nearestDriverIndex != -1)
                    {
                        if (shouldCancelRide(drivers[nearestDriverIndex], passengers[passengerIndex]))
                        {
                            printf("Ride automatically cancelled. Distance between driver and passenger is more than 4 km.\n");
                            passengers[passengerIndex].rideCancelled = 1;
                        }
                        else
                        {
                            printf("Nearest Driver found! Assigning ride...\n");
                            drivers[nearestDriverIndex].availability = 0;
                            rideAssignedPassengerIndex = passengerIndex;
                            rideAssignedDriverIndex = nearestDriverIndex;
                            printf("Ride assigned to %s. Driver location: (%.2f, %.2f)\n", drivers[nearestDriverIndex].name, drivers[nearestDriverIndex].location.x, drivers[nearestDriverIndex].location.y);
                        }
                    }
                    else
                    {
                        printf("No available drivers at the moment. Please try again later.\n");
                    }
                }
                else
                {
                    printf("Invalid passenger index!\n");
                }
            }
            else
            {
                printf("Not enough passengers or drivers to request a ride.\n");
            }
            break;

        case 2:
            if (rideAssignedPassengerIndex != -1 && rideAssignedDriverIndex != -1 && !passengers[rideAssignedPassengerIndex].rideCancelled)
            {
                float distanceTravelled = sqrt(pow(passengers[rideAssignedPassengerIndex].destinationLocation.x - passengers[rideAssignedPassengerIndex].initialLocation.x, 2) +
                                               pow(passengers[rideAssignedPassengerIndex].destinationLocation.y - passengers[rideAssignedPassengerIndex].initialLocation.y, 2));
                float fare = calculateRideFare(distanceTravelled);
                printf("Distance Travelled: %.2f km\n", distanceTravelled);
                printf("Ride Fare: $%.2f\n", fare);
            }
            else
            {
                printf("No valid ride to calculate fare for.\n");
            }
            break;

        case 3:
            if (rideAssignedPassengerIndex != -1 && rideAssignedDriverIndex != -1)
            {
                passengers[rideAssignedPassengerIndex].rideCancelled = 1;
                drivers[rideAssignedDriverIndex].availability = 1;
                rideAssignedPassengerIndex = -1;
                rideAssignedDriverIndex = -1;
                printf("Ride canceled successfully!\n");
            }
            else
            {
                printf("No ride to cancel.\n");
            }
            break;

        case 4:
            if (rideAssignedPassengerIndex != -1 && rideAssignedDriverIndex != -1 && !passengers[rideAssignedPassengerIndex].rideCancelled)
            {
                drivers[rideAssignedDriverIndex].availability = 1;
                printf("Ride completed successfully! Driver is now available.\n");

                float distanceTravelled = sqrt(pow(passengers[rideAssignedPassengerIndex].destinationLocation.x - passengers[rideAssignedPassengerIndex].initialLocation.x, 2) +
                                               pow(passengers[rideAssignedPassengerIndex].destinationLocation.y - passengers[rideAssignedPassengerIndex].initialLocation.y, 2));
                float fare = calculateRideFare(distanceTravelled);
                printf("Distance Travelled: %.2f km\n", distanceTravelled);
                printf("Ride Fare: $%.2f\n", fare);

                rideAssignedPassengerIndex = -1;
                rideAssignedDriverIndex = -1;
            }
            else
            {
                printf("No valid ride to complete.\n");
            }
            break;

        case 5:
            displayDrivers(drivers, numDrivers);
            break;

        case 6:
            displayPassengers(passengers, numPassengers);
            break;

        case 7:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}
