#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "roster.h"

// Nameless namespace used for constants, aka student data table.
namespace {
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Lee,Rhodes,brhod26@wgu.edu,22,30,45,38,SOFTWARE"
	};
}

// Prints out the introduction: course title, programming language, student ID, and student name.
void printIntro() {
	cout << "Course Title: Scripting and Programming, Applications C867" << endl;
	cout << "Programming Language: C++" << endl;
	cout << "WGU Student ID: 001443578" << endl;
	cout << "Name: Lee Rhodes" << endl;
}

// Splits one of the student data strings into 9 tokens which represent all of the data that makes up one Student object; 
// Passed back as a vector to allow index accessing & multiple value return.
vector<string> parseStudentData(int ix) {
	string delimiter = ",";
	string studentDataToken;
	vector<string> parsedStudentData;

	string currentStudent = studentData[ix];
		
	int maxTokens = 9;
	for (int n = 0; n < maxTokens; n++) {
		size_t pos = currentStudent.find(delimiter);
		studentDataToken = currentStudent.substr(0, pos);

		parsedStudentData.push_back(studentDataToken);

		currentStudent.erase(0, pos + delimiter.length());
	}

	return parsedStudentData;
}

// cin.ignore() used to put pauses inbetween method executions.
int main() {
	printIntro();
	
	cout << endl << "Creating roster...";
	cin.ignore();

	Roster classRoster;

	for (int i = 0; i < maxStudents; i++) {
		vector<string> parsedStudentData = parseStudentData(i);
		// Only area where I decided to keep magic numbers since it's only in one place.
		// Magic numbers are just increments of the parsedStudentData vector;
		// Alternative could be FOR looping through parsedStudentData and assigning each value to a named variable (i.e. studentID = parsedStudentData[0]).
		classRoster.add(parsedStudentData[0], parsedStudentData[1], parsedStudentData[2], parsedStudentData[3], stoi(parsedStudentData[4]),
			stoi(parsedStudentData[5]), stoi(parsedStudentData[6]), stoi(parsedStudentData[7]), stringToDegreeProgram(parsedStudentData[8]));
	}

	cout << endl << "Printing all student data...";
	cin.ignore();
	classRoster.printAll();

	cout << endl << "Printing all invalid emails...";
	cin.ignore();
	classRoster.printInvalidEmails();


	cout << endl << "Printing each student's average days in courses...";
	cin.ignore();
	for (int i = 0; i < maxStudents; i++) {
		Student currentStudent = classRoster.retrieveStudent(i);
		string currentStudentID = currentStudent.getStudentID();
		classRoster.printAverageDaysInCourse(currentStudentID);
	}


	cout << endl << "Printing students in degree program SOFTWARE...";
	cin.ignore();
	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
	
	cout << endl << "Removing student with ID 'A3'...";
	cin.ignore();
	classRoster.remove("A3");

	cout << endl << "Printing all student data...";
	cin.ignore();
	classRoster.printAll();

	// Will generate an "error" since student A3 no longer exists.
	cout << endl << "Removing student with ID 'A3'...";
	cin.ignore();
	classRoster.remove("A3");

	cout << endl << "Program complete!";
	cin.ignore();
}