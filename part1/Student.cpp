#include "Student.hpp"
#include<iostream>
using namespace std;
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

ostream& operator<<(ostream& o, const Student& s)
{
    o << s.name << '\n' << s.id << '\n' << s.gpa << '\n';
    return o;
}
Student* Student::read(int& size, string path)
{
    ifstream f(path);
    f >> size;
    Student* students = new Student[size];
    for (int i = 0; i < size; i++)
    {
        string name, id;
        double gpa;
        f >> name >> id >> gpa;
        students[i] = Student(id, name, gpa);
    }
    f.close();
    return students;
}