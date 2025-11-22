#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Ticket {
    int ticketID;
    string passengerName;
    string destination;
    string date;
    float price;
};

class E_Ticket_System {
private:
    Ticket tickets[100];
    int count;

public:
    E_Ticket_System() {
        count = 0;
    }

    void bookTicket() {
        if (count >= 100) {
            cout << "Sorry, no more tickets can be booked.\n";
            return;
        }

        Ticket t;
        t.ticketID = count + 1;
        cout << "Enter Passenger Name: ";
        cin.ignore();
        getline(cin, t.passengerName);
        cout << "Enter Destination: ";
        getline(cin, t.destination);
        cout << "Enter Date (DD/MM/YYYY): ";
        cin >> t.date;
        cout << "Enter Price: ";
        cin >> t.price;

        tickets[count] = t;
        count++;

        cout << "\nTicket booked successfully!\n";
        cout << "Ticket ID: " << t.ticketID << endl;
    }

    void viewTickets() {
        if (count == 0) {
            cout << "No tickets booked yet.\n";
            return;
        }

        cout << "\n--- All Booked Tickets ---\n";
        cout << left << setw(5) << "ID" 
             << setw(20) << "Passenger" 
             << setw(15) << "Destination" 
             << setw(12) << "Date" 
             << setw(8) << "Price" << endl;

        for (int i = 0; i < count; i++) {
            cout << left << setw(5) << tickets[i].ticketID 
                 << setw(20) << tickets[i].passengerName 
                 << setw(15) << tickets[i].destination 
                 << setw(12) << tickets[i].date 
                 << setw(8) << tickets[i].price << endl;
        }
    }

    void searchTicket() {
        int id;
        cout << "Enter Ticket ID to search: ";
        cin >> id;

        bool found = false;
        for (int i = 0; i < count; i++) {
            if (tickets[i].ticketID == id) {
                cout << "\nTicket Found:\n";
                cout << "Passenger: " << tickets[i].passengerName << endl;
                cout << "Destination: " << tickets[i].destination << endl;
                cout << "Date: " << tickets[i].date << endl;
                cout << "Price: " << tickets[i].price << endl;
                found = true;
                break;
            }
        }

        if (!found)
            cout << "Ticket ID not found.\n";
    }

    void cancelTicket() {
        int id;
        cout << "Enter Ticket ID to cancel: ";
        cin >> id;

        for (int i = 0; i < count; i++) {
            if (tickets[i].ticketID == id) {
                for (int j = i; j < count - 1; j++) {
                    tickets[j] = tickets[j + 1];
                }
                count--;
                cout << "Ticket with ID " << id << " has been canceled.\n";
                return;
            }
        }

        cout << "Ticket ID not found.\n";
    }

    void menu() {
        int choice;
        do {
            cout << "\n===== E-Ticket Reservation System =====\n";
            cout << "1. Book Ticket\n";
            cout << "2. View All Tickets\n";
            cout << "3. Search Ticket\n";
            cout << "4. Cancel Ticket\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: bookTicket(); break;
                case 2: viewTickets(); break;
                case 3: searchTicket(); break;
                case 4: cancelTicket(); break;
                case 5: cout << "Thank you for using the system!\n"; break;
                default: cout << "Invalid choice, try again.\n"; break;
            }
        } while (choice != 5);
    }
};

int main() {
    E_Ticket_System system;
    system.menu();
    return 0;
}

    
         

  
               
