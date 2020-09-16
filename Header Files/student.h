#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "degree.h"

// Nameless namespace used for max course days (3) to prevent magic numbers in code.
namespace {
	const int maxCourseDays = 3;
}

class Student {
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[maxCourseDays];
	DegreeProgram degreeProgram;
public:
	Student();

	Student(string newStudentID, string newFirstName, string newLastName, string newEmailAddress, int newAge, int newDaysInCourse[maxCourseDays], DegreeProgram newDegreeProgram);

	string getStudentID();

	string getFirstName();

	string getLastName();

	string getEmailAddress();

	int getAge();

	const int* getDaysInCourse();

	DegreeProgram getDegreeProgram();

	void setStudentID(string newStudentID);

	void setFirstName(string newFirstName);

	void setLastName(string newLastName);

	void setemailAddress(string newEmailAddress);

	void setAge(int newAge);

	void setDaysInCourse(int newDaysInCourse[maxCourseDays]);

	void setDegreeProgram(DegreeProgram newDegreeProgram);

	void printStudentID();

	void printFirstName();

	void printLastName();

	void printEmailAddress();

	void printAge();

	void printDaysInCourse();

	void printDegreeProgram();
};

#endif