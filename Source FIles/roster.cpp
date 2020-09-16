#include "roster.h"

Roster::~Roster() {
	for (int i = 0; i < maxStudents; i++) {
		delete classRosterArray[i];
	}

	cout << "Roster removed." << endl;
}

Student Roster::retrieveStudent(int ix) {
	return (*classRosterArray[ix]);
}


// Variable "arrayLength" increments by 1 every time this function is called (and decrements by 1 every time "remove" is called) to keep track of how many students are in the array;
// Alternatively, can check for studentID values of "NULL" (i.e. if studentID == NULL, then it's safe to replace that value with a new student).
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int daysInCourse[maxCourseDays] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	if (arrayLength < maxStudents) {
		classRosterArray[arrayLength] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
		arrayLength++;
		cout << "New student successfully added." << endl;
	}
	else {
		// Only triggered if more than 5 student instances are passed to the method.
		cout << "Student could not be added because the roster is full." << endl;
	}
}

// Instead of completely deleting one section of the array, this implementation preserves all 5 spots in the array;
// Existing values past the "deleted" student are pushed forward 1 space and the last slot is replaced by the default student values (studentID == "NULL").
void Roster::remove(string studentID) {
	// Boolean placed to allow us to generate  an exception message if no student is found.
	// Alternatively, can determine this based on whether or not selectedIX has a value.
	bool studentFound = false;
	int selectedIX;
	for (int i = 0; i < maxStudents; i++) {
		string currentID = (*classRosterArray[i]).getStudentID();
		if (currentID == studentID) {
			selectedIX = i;
			studentFound = true;
		}
	}
	if (!studentFound) {
		cout << "Student " << studentID << " does not exist." << endl;
	}
	else {
		if (selectedIX < (maxStudents - 1)) {
			for (int i = selectedIX; i < (maxStudents - 1); i++) {
				classRosterArray[i] = classRosterArray[i + 1];
			}
		}
		classRosterArray[maxStudents - 1] = new Student();
		arrayLength--;
		cout << "Student " << studentID << " has been removed." << endl;
	}

}

void Roster::printAverageDaysInCourse(string studentID) {
	// Boolean placed to allow us to generate  an exception message if no student is found.
	// Alternatively, can move code around to base this decision off of the value of sum (assuming a sum of 0 is impossible).
	bool studentFound = false;
	for (int i = 0; i < maxStudents; i++) {
		string currentID = (*classRosterArray[i]).getStudentID();
		if (currentID == studentID) {
			studentFound = true;
			const int* daysInCourse = (*classRosterArray[i]).getDaysInCourse();
			int sum = 0;
			for (int n = 0; n < maxCourseDays; n++) {
				sum += daysInCourse[n];
			}
			int avg = sum / maxCourseDays;
			cout << "Student " << studentID << "'s average number of days in the three courses is " << avg << endl;
		}
	}
	if (!studentFound) {
		cout << "Student " << studentID << " does not exist." << endl;
	}
}

// Again, setw() used to allow a tabular format when displaying output.
void Roster::printAll() {
	cout << setw(6) << "ID" << setw(12) << "First Name" << setw(12) << "Last Name" << setw(26) << "Email Address" << setw(6) << "Age";
	cout << setw(16) << "Days In Course" << setw(16) << "Degree Program" << endl;
	for (int i = 0; i < maxStudents; i++) {
		string currentID = (*classRosterArray[i]).getStudentID();
		if (currentID != "NULL") {
			(*classRosterArray[i]).printStudentID();
			(*classRosterArray[i]).printFirstName();
			(*classRosterArray[i]).printLastName();
			(*classRosterArray[i]).printEmailAddress();
			(*classRosterArray[i]).printAge();
			(*classRosterArray[i]).printDaysInCourse();
			(*classRosterArray[i]).printDegreeProgram();
			cout << endl;
		}

	}
}

// Email is considered invalid if it: (1) has no "@", (2) has no ".", and (3) has a space (" ").
// Used a list for invalid emails since I can just iterate through it without worrying about indexes.
void Roster::printInvalidEmails() {
	list<string> invalidEmails = {};
	for (int i = 0; i < maxStudents; i++) {
		string currentEmail = (*classRosterArray[i]).getEmailAddress();
		if (currentEmail.find('@') == -1) {
			invalidEmails.push_back(currentEmail);
		}
		else if (currentEmail.find('.') == -1) {
			invalidEmails.push_back(currentEmail);
		}
		else if (currentEmail.find(' ') != -1) {
			invalidEmails.push_back(currentEmail);
		}
	}
	if (!invalidEmails.empty()) {
		cout << "Invalid email addresses found are:" << endl;
		for (auto email : invalidEmails) {
			cout << email << endl;
		}
	}
	else {
		cout << "No invalid email addresses found." << endl;
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	string degreeProgramString = degreeProgramToString(degreeProgram);
	cout << "Students in Degree Program " << degreeProgramString << endl;
	cout << setw(6) << "ID" << setw(12) << "First Name" << setw(12) << "Last Name" << setw(26) << "Email Address" << setw(6) << "Age";
	cout << setw(16) << "Days In Course" << endl;
	for (int i = 0; i < maxStudents; i++) {
		string currentID = (*classRosterArray[i]).getStudentID();
		if (currentID != "NULL") {
			DegreeProgram currentDegreeProgram = (*classRosterArray[i]).getDegreeProgram();
			if (currentDegreeProgram == degreeProgram) {
				(*classRosterArray[i]).printStudentID();
				(*classRosterArray[i]).printFirstName();
				(*classRosterArray[i]).printLastName();
				(*classRosterArray[i]).printEmailAddress();
				(*classRosterArray[i]).printAge();
				(*classRosterArray[i]).printDaysInCourse();
				cout << endl;
			}
		}
	}
}
