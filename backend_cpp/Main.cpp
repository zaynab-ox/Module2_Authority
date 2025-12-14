
#include <iostream>
#include <string>
using namespace std;

// Simple Incident class
class Incident {
public:
    int id;
    string type;
    string location;
    int severity;
    string citizenName;
    string status;

    Incident(int i, string t, string l, int s, string c, string st) {
        id = i;
        type = t;
        location = l;
        severity = s;
        citizenName = c;
        status = st;
    }

    void display() {
        cout << "ID: " << id 
             << ", Type: " << type 
             << ", Location: " << location 
             << ", Severity: " << severity 
             << ", Citizen: " << citizenName 
             << ", Status: " << status << endl;
    }
};

// IncidentManager class
class IncidentManager {
public:
    Incident* incidents[100];
    int count;

    IncidentManager() {
        count = 0;
    }

    void addIncident(Incident* inc) {
        incidents[count] = inc;
        count++;
        cout << "Incident added successfully!" << endl;
    }

    void showAllIncidents() {
        if(count == 0) {
            cout << "No incidents available!" << endl;
            return;
        }
        cout << "\nAll Incidents (sorted by severity):\n";
        sortBySeverity();
        for (int i = 0; i < count; i++) {
            incidents[i]->display();
        }
    }

    void showHighSeverity() {
        bool found = false;
        cout << "\nHigh Severity Incidents (4 & 5):\n";
        sortBySeverity();
        for (int i = 0; i < count; i++) {
            if (incidents[i]->severity >= 4) {
                incidents[i]->display();
                found = true;
            }
        }
        if(!found) cout << "No high severity incidents found!" << endl;
    }

    void updateStatus(int id, string newStatus) {
        for (int i = 0; i < count; i++) {
            if (incidents[i]->id == id) {
                incidents[i]->status = newStatus;
                cout << "Status updated successfully!" << endl;
                return;
            }
        }
        cout << "Incident ID not found!" << endl;
    }

private:
    void sortBySeverity() {
        // Simple bubble sort descending by severity
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {
                if (incidents[j]->severity < incidents[j+1]->severity) {
                    Incident* temp = incidents[j];
                    incidents[j] = incidents[j+1];
                    incidents[j+1] = temp;
                }
            }
        }
    }
};

int main() {
    IncidentManager manager;
    int choice;

    while(true) {
        cout << "\n===== Authority Module Menu =====\n";
        cout << "1. Add Incident\n";
        cout << "2. View All Incidents (Sorted by Severity)\n";
        cout << "3. View High Severity Incidents\n";
        cout << "4. Update Incident Status\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if(choice == 1) {
            int id, severity;
            string type, location, citizenName, status;
            cout << "Enter Incident ID: "; cin >> id; cin.ignore();
            cout << "Enter Type: "; getline(cin, type);
            cout << "Enter Location: "; getline(cin, location);
            cout << "Enter Severity (1-5): "; cin >> severity; cin.ignore();
            cout << "Enter Citizen Name: "; getline(cin, citizenName);
            cout << "Enter Status (Pending/InProgress/Resolved): "; getline(cin, status);

            manager.addIncident(new Incident(id, type, location, severity, citizenName, status));

        } else if(choice == 2) {
            manager.showAllIncidents();

        } else if(choice == 3) {
            manager.showHighSeverity();

        } else if(choice == 4) {
            int id;
            string newStatus;
            cout << "Enter Incident ID to update: "; cin >> id; cin.ignore();
            cout << "Enter New Status (Pending/InProgress/Resolved): "; getline(cin, newStatus);
            manager.updateStatus(id, newStatus);

        } else if(choice == 5) {
            cout << "Exiting program. Goodbye!" << endl;
            break;

        } else {
            cout << "Invalid choice! Try again." << endl;
        }
    }

    return 0;
}