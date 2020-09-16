#ifndef ROSTER_H
#define ROSTER_H

#include <iostream>
#include <iomanip>
#include <list>
#include <string>
using namespace std;

#include "student.h"

// Nameless namespace used for max students (5) to prevent magic numbers in code.
namespace {
	const int maxStudents = 5;
}

class Roster {
private:
	Student* classRosterArray[maxStudents];
	unsigned int arrayLength = 0;

public: 
	Student retrieveStudent(int ix);

	~Roster();

	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, 
		int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

	void remove(string studentID);

	void printAll();

	void printAverageDaysInCourse(string studentID);

	void printInvalidEmails();

	void printByDegreeProgram(DegreeProgram degreeProgram);
};

#endif
