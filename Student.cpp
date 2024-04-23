#include "Student.hpp"

class Student{
string id;
string name;
double gpa;

public:
Student(){//default constructor
    id = "", name="";
    gpa = 0.0;
}
Student(string id1, string name1, double gpa1){
    id = id1;
    name = name1;
    gpa = gpa1;
}
};
bool operator<(const Student& first,const Student& second){

}