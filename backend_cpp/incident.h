#ifndef INCIDENT_H
#define INCIDENT_H

#include <iostream>
#include <string>
using namespace std;

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

    // Display function
    void display() {
        cout << "ID: " << id 
             << ", Type: " << type 
             << ", Location: " << location 
             << ", Severity: " << severity 
             << ", Citizen: " << citizenName 
             << ", Status: " << status << endl;
    }
};

#endif
