#include "student.h"

// Default constructor for Student to allow a custom NULL student value.
Student::Student() {
	studentID = "NULL";
	firstName = "ABC";
	lastName = "XYZ";
	emailAddress = "default@default.com";
	age = 0;
	for (int i = 0; i < maxCourseDays; i++)
	{
		daysInCourse[i] = 0;
	}
	degreeProgram = DegreeProgram::SOFTWARE;
}


// Defined constructor for Student with custom values.
Student::Student(string newStudentID, string newFirstName, string newLastName, string newEmailAddress, int newAge, int newDaysInCourse[maxCourseDays], DegreeProgram newDegreeProgram)
{
	studentID = newStudentID;
	firstName = newFirstName;
	lastName = newLastName;
	emailAddress = newEmailAddress;
	age = newAge;
	for (int i = 0; i < maxCourseDays; i++)
	{
		daysInCourse[i] = newDaysInCourse[i];
	}
	degreeProgram = newDegreeProgram;
}

// Accessors for Student.
string Student::getStudentID()
{
	return studentID;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getEmailAddress()
{
	return emailAddress;
}

int Student::getAge()
{
	return age;
}

const int* Student::getDaysInCourse()
{
	return daysInCourse;
}

DegreeProgram Student::getDegreeProgram()
{
	return degreeProgram;
}


// Mutators for Student.
void Student::setStudentID(string newStudentID)
{
	studentID = newStudentID;
}

void Student::setFirstName(string newFirstName)
{
	firstName = newFirstName;
}

void Student::setLastName(string newLastName)
{
	lastName = newLastName;
}

void Student::setemailAddress(string newEmailAddress)
{
	emailAddress = newEmailAddress;
}

void Student::setAge(int newAge)
{
	age = newAge;
}

void Student::setDaysInCourse(int newDaysInCourse[maxCourseDays])
{
	for (int i = 0; i < maxCourseDays; i++)
	{
		daysInCourse[i] = newDaysInCourse[i];
	}
}

void Student::setDegreeProgram(DegreeProgram newDegreeProgram)
{
	degreeProgram = newDegreeProgram;
}


// Print methods for Student values; setw() used to allow a tabular format when printing out all values.
// Numbers for setw() decided based on the longest value for each element (i.e. email address length of 26 based on "Erickson_1990@gmailcom".
void Student::printStudentID()
{
	cout << setw(6) << studentID;
}

void Student::printFirstName()
{
	cout << setw(12) << firstName;
}

void Student::printLastName()
{
	cout << setw(12) << lastName;
}

void Student::printEmailAddress()
{
	cout << setw(26) << emailAddress;
}

void Student::printAge()
{
	cout << setw(6) << age;
}

void Student::printDaysInCourse()
{
	string daysInCourseString;
	for (int i = 0; i < maxCourseDays; i++) {
		if (i != (maxCourseDays - 1)) {
			daysInCourseString += (to_string(daysInCourse[i]) + ", ");
		}
		else {
			daysInCourseString += to_string(daysInCourse[i]);
		}
	}
	cout << setw(16) << daysInCourseString;
}

void Student::printDegreeProgram()
{
	string degreeProgramString = degreeProgramToString(degreeProgram);
	cout << setw(16) << degreeProgramString;
}
