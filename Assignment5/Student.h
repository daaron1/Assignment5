#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Student
{
  public:
    Student();
    Student(int id, string n, string s, string m, double g, int a);

    int getID();
    string getName();
    string getStanding();
    string getMajor();
    double getGPA();
    int getAdvisorID();
    void setAdvisorID(int i);

    int studentID;
    string name;
    string standing;
    string major;
    double gpa;
    int advisorID;
};
