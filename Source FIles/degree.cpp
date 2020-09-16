#include "degree.h"

// degree.cpp created in order to define functions for converting Degree Program to strings and vice versa.
DegreeProgram stringToDegreeProgram(string degreeProgramString)
{
    if (degreeProgramString == "SECURITY") {
        return DegreeProgram::SECURITY;
    }
    else if (degreeProgramString == "NETWORK") {
        return DegreeProgram::NETWORK;
    }
    else {
        return DegreeProgram::SOFTWARE;
    }
}

string degreeProgramToString(DegreeProgram degreeProgram)
{
    if (degreeProgram == DegreeProgram::SECURITY) {
        return "SECURITY";
    }
    else if (degreeProgram == DegreeProgram::NETWORK) {
        return "NETWORK";
    }
    else {
        return "SOFTWARE";
    }
}
