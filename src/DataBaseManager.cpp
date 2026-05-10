#include "../include/DatabaseManager.h"
#include "../include/Student.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
DatabaseManager::~DatabaseManager()
{
    for (Student* student : studentRoster) 
    {
        delete student; 
    }
    studentRoster.clear();
}

void DatabaseManager::loadStudents(const string& filepath) 
{
    ifstream file(filepath);
    if (!file.is_open()) {
        cout << "Error: Could not open " << filepath << "!" << endl;
        return;
    }

    string line;
    // Read the file line by line
    while (getline(file, line)) {
        if (line.empty()) continue; // Skip empty lines

        stringstream ss(line);
        string id, name, typeStr, gpaStr, extraParam;

        // Parse the line based on your guideline format: ID | Name | Type | GPA | ExtraParam
        // We use getline with the '|' delimiter to split the string
        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, typeStr, '|');
        getline(ss, gpaStr, '|');
        getline(ss, extraParam, '|');

        double gpa = 0.0;
        if (!gpaStr.empty()) {
            gpa = stod(gpaStr); // Convert string to double
        }
        if (typeStr == "Regular") {
            studentRoster.push_back(new RegularStudent(id, name, "student@nu.edu.pk", gpa));
        }
        else if (typeStr == "Scholarship") {
            studentRoster.push_back(new ScholarshipStudent(id, name, "student@nu.edu.pk", gpa));
        }
        else if (typeStr == "Exchange") {
            studentRoster.push_back(new ExchangeStudent(id, name, "student@nu.edu.pk"));
        }
    }

    file.close();
    cout << "Database: Loaded " << studentRoster.size() << " students successfully.\n";
}