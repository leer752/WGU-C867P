#ifndef DEGREE_H
#define DEGREE_H

#include <iostream>
#include <string>
using namespace std;

enum class DegreeProgram { SECURITY, NETWORK, SOFTWARE };

DegreeProgram stringToDegreeProgram(string degreeProgramString);
string degreeProgramToString(DegreeProgram degreeProgram);

#endif