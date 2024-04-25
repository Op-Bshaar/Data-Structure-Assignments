#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
using namespace std;

class Student{
string id;
string name;
double gpa;

public:
Student(){}
double getGpa() const;
string getName() const;
Student(string id1, string name1, double gpa1){}
bool operator<(const Student& other) const;
};

#endif