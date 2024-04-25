#include "Student.hpp"

Student::Student(){//default constructor
    id = "", name="";
    gpa = 0.0;
}
Student::Student(string id1, string name1, double gpa1){
    id = id1;
    name = name1;
    gpa = gpa1;
}
bool Student::operator<(const Student& other) const
{
    return name < other.name;
}
double Student::getGpa() const
{
    return gpa;
}
string Student::getName() const
{
    return name;
}