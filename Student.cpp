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

ostream& operator<<(ostream& o, const Student& s)
{
    o << s.name << '\n' << s.id << '\n' << s.gpa << '\n';
    return o;
}
vector<Student> Student::read(string path)
{
    vector<Student> students;
    ifstream f(path);
    int count;
    f >> count;
    for (int i = 0; i < count; i++)
    {
        string id, name;
        double gpa;
        f >> name >> id >> gpa;
        students.push_back(Student(id, name, gpa));
    }
    return students;
}