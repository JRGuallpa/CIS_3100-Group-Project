#include <iostream>
#include <iomanip>

using namespace std;

// Function declarations
int getDays();
void getTime(int& departureHour, int& arrivalHour, int days);
double getRoundTripAirfare();
double getCarRentals();
double getMilesDriven();
double getParkingFees(int day); // Add parameter
double getTaxiFees(int day);    // Add parameter
double getRegistrationFees();
double getHotelExpenses();
double getMealExpenses(int departureHour, int arrivalHour);

// Function for calculating vehicle expenses
double calculateVehicleExpense(double milesDriven);

// Function for validating time
bool isValidTime(int hour);

int main() {
    // Function calls to get user input
    int totalDays = getDays();

    int departureHour, arrivalHour;
    getTime(departureHour, arrivalHour, totalDays);

    double roundTripAirfare = getRoundTripAirfare();
    double carRentals = getCarRentals();
    double milesDriven = getMilesDriven();
    double registrationFees = getRegistrationFees();
    double hotelExpenses = getHotelExpenses();

    // Variables for meal expenses
    double totalMealExpenses = getMealExpenses(departureHour, arrivalHour); // Call once for the entire trip
    double totalParkingFees = 0.0;
    double totalTaxiFees = 0.0;

    for (int day = 1; day <= totalDays; ++day) {
        totalParkingFees += getParkingFees(day);
        totalTaxiFees += getTaxiFees(day);
    }

    // Calculate total expenses
    double totalExpenses = roundTripAirfare + carRentals + calculateVehicleExpense(milesDriven) +
                           totalParkingFees + totalTaxiFees + registrationFees + hotelExpenses * totalDays + totalMealExpenses;

    // Company allowances 
    double allowableExpenses = totalDays * 6.0 + totalDays * 10.0 + totalDays * 90.0 + (departureHour < 700 ? 9.0 : 0.0)
                               + (departureHour < 1200 ? 12.0 : 0.0) + (departureHour < 1800 ? 16.0 : 0.0) + (arrivalHour > 800 ? 9.0 : 0.0)
                               + (arrivalHour > 1300 ? 12.0 : 0.0) + (arrivalHour > 1900 ? 16.0 : 0.0);
                                // 6 for parking; 10 for taxis, 90 for hotels, 9 for breakfast, 12 for lunch, 16 for dinner
                                // breakfast, lunch, dinner are double for return and departure flight
                                // under assumption that parking fee and taxi fees accumulate  
    // Calculate excess and savings
    double excess = max(0.0, totalExpenses - allowableExpenses);
    double savings = max(0.0, allowableExpenses - totalExpenses);

    // Display results
    cout << fixed << setprecision(2);
    cout << "Total Expenses Accured: $" << totalExpenses << endl;
    cout << "Maximum Allowable Expenses to be Reimbursed : $" << allowableExpenses << endl;
    cout << "Excess to be Reimbursed by businessperson: $" << excess << endl;
    cout << "Amount Saved by businessperson: $" << savings << endl;

    return 0;
}








// Implement the other functions based on the provided structure and guidelines.

// Example implementation for one function
int getDays() {
    int days;
    do {
        cout << "Enter the total number of days spent on the trip: ";
        cin >> days;

        if (days < 1) {
            cout << "Please enter a valid number of days." << endl;
        }
    } while (days < 1);

    return days;
}

// Implement the rest of the functions...
void getTime(int& departureHour, int& arrivalHour, int days) {
    do {
        cout << "Enter the time of departure on the first day (24-hour format, e.g., 0400 for 4:00 AM): ";
        cin >> departureHour;
    } while (!isValidTime(departureHour));

    if (days == 1) {
        do {
            cout << "Enter the time of arrival back home on the last day (24-hour format, e.g., 2000 for 8:00 PM): ";
            cin >> arrivalHour;
            if (arrivalHour < departureHour) {
                cout << "Error: Arrival time cannot be before departure time." << endl;
            }
        } while (!isValidTime(arrivalHour) || arrivalHour < departureHour);
    } else {
        do {
            cout << "Enter the time of arrival back home on the last day (24-hour format, e.g., 2000 for 8:00 PM): ";
            cin >> arrivalHour;
        } while (!isValidTime(arrivalHour));
    }
}

// Function to check if the time is valid
bool isValidTime(int hour) {
    // Check if the hour is between 0 and 23 for the hour part
    // and between 0 and 59 for the minute part
    int hourPart = hour / 100; // Extract the hour part
    int minutePart = hour % 100; // Extract the minute part

    return (hour >= 0 && hour <= 2359) &&
           (hourPart >= 0 && hourPart <= 23) &&
           (minutePart >= 0 && minutePart <= 59);
}

// Function to get the amount of round-trip airfare
double getRoundTripAirfare() {
    double airfare;
    do {
        cout << "Enter the amount of round-trip airfare: $";
        cin >> airfare;

        if (airfare < 0) {
            cout << "Please enter a valid amount." << endl;
        }
    } while (airfare < 0);

    return airfare;
}

// Function to get the amount of car rentals
double getCarRentals() {
    double carRentals;
    do {
        cout << "Enter the amount of car rentals total cost (enter 0 if not applicable): $";
        cin >> carRentals;

        if (carRentals < 0) {
            cout << "Please enter a valid amount." << endl;
        }
    } while (carRentals < 0);

    return carRentals;
}

// Function to get the miles driven in a private vehicle
double getMilesDriven() {
    double miles;
    do {
        cout << "Enter the miles driven (enter 0 if not applicable): ";
        cin >> miles;

        if (miles < 0) {
            cout << "Please enter a valid number of miles." << endl;
        }
    } while (miles < 0);

    return miles;
}

// Function to calculate vehicle expenses
double calculateVehicleExpense(double milesDriven) {
    return milesDriven * 0.27;
}

// Function to get parking fees for a specific day
double getParkingFees(int day) {
    double fees;
    do {
        cout << "Enter parking fees for day " << day << " (enter 0 if not applicable): $";
        cin >> fees;

        if (fees < 0) {
            cout << "Please enter a valid amount." << endl;
        }
    } while (fees < 0);

    return fees;
}

// Function to get taxi fees for a specific day
double getTaxiFees(int day) {
    double fees;
    do {
        cout << "Enter taxi fees for day " << day << " (enter 0 if not applicable): $";
        cin >> fees;

        if (fees < 0) {
            cout << "Please enter a valid amount." << endl;
        }
    } while (fees < 0);

    return fees;
}

// Function to get conference or seminar registration fees
double getRegistrationFees() {
    double fees;
    do {
        cout << "Enter conference or seminar registration fees (enter 0 if not applicable): $";
        cin >> fees;

        if (fees < 0) {
            cout << "Please enter a valid amount." << endl;
        }
    } while (fees < 0);

    return fees;
}

// Function to get hotel expenses
double getHotelExpenses() {
    double expenses;
    do {
        cout << "Enter average nightly hotel expenses(enter 0 if not applicable): $";
        cin >> expenses;

        if (expenses < 0) {
            cout << "Please enter a valid amount." << endl;
        }
    } while (expenses < 0);

    return expenses;
}

// Function to get meal expenses
double getMealExpenses(int departureHour, int arrivalHour) {
    double totalMealExpenses = 0.0;

    if (departureHour < 700) { // Before 7 a.m.
        double breakfast;
        do {
            cout << "Enter breakfast expenses for departure (enter 0 if not applicable): $";
            cin >> breakfast;

            if (breakfast < 0) {
                cout << "Please enter a valid amount." << endl;
            }
        } while (breakfast < 0);

        totalMealExpenses += breakfast;
    }

    if (departureHour < 1200) { // Before 12 p.m.
        double lunch;
        do {
            cout << "Enter lunch expenses for departure (enter 0 if not applicable): $";
            cin >> lunch;

            if (lunch < 0) {
                cout << "Please enter a valid amount." << endl;
            }
        } while (lunch < 0);

        totalMealExpenses += lunch;
    }

    if (departureHour < 1800) { // Before 6 p.m.
        double dinner;
        do {
            cout << "Enter dinner expenses for departure (enter 0 if not applicable): $";
            cin >> dinner;

            if (dinner < 0) {
                cout << "Please enter a valid amount." << endl;
            }
        } while (dinner < 0);

        totalMealExpenses += dinner;
    }

    if (arrivalHour > 800) { // After 8 a.m.
        double breakfast;
        do {
            cout << "Enter breakfast expenses for arrival/return (enter 0 if not applicable): $";
            cin >> breakfast;

            if (breakfast < 0) {
                cout << "Please enter a valid amount." << endl;
            }
        } while (breakfast < 0);

        totalMealExpenses += breakfast;
    }

    if (arrivalHour > 1300) { // After 1 p.m.
        double lunch;
        do {
            cout << "Enter lunch expenses for arrival/return (enter 0 if not applicable): $";
            cin >> lunch;

            if (lunch < 0) {
                cout << "Please enter a valid amount." << endl;
            }
        } while (lunch < 0);

        totalMealExpenses += lunch;
    }

    if (arrivalHour > 1900) { // After 7 p.m.
        double dinner;
        do {
            cout << "Enter dinner expenses for arrival/return (enter 0 if not applicable): $";
            cin >> dinner;

            if (dinner < 0) {
                cout << "Please enter a valid amount." << endl;
            }
        } while (dinner < 0);

        totalMealExpenses += dinner;
    }

    return totalMealExpenses;
}
