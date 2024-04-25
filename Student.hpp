#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Student{
string id;
string name;
double gpa;

public:
	Student();
double getGpa() const;
string getName() const;
Student(string id1, string name1, double gpa1);
static vector<Student> read(string path = "students.txt");
bool operator<(const Student& other) const;
friend ostream& operator<<(ostream& o, const Student& s);
};

#endif