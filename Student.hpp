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
Student(string id1, string name1, double gpa1){}
friend bool operator<(const string& first,const string& second);
};
bool operator<(const string& first,const string& second);

#endif