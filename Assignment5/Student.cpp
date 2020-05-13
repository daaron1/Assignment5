#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Student.h"
using namespace std;

Student::Student(){
}

Student::Student(int id, string n, string s, string m, double g, int a)
{
  studentID = id;
  name = n;
  standing = s;
  major = m;
  gpa = g;
  advisorID = a;
}

int Student::getID()
{
  return studentID;
}

string Student::getName()
{
  return name;
}
string Student::getStanding()
{
  return standing;
}
string Student::getMajor()
{
  return major;
}
double Student::getGPA()
{
  return gpa;
}
int Student::getAdvisorID()
{
  return advisorID;
}

void Student::setAdvisorID(int i)
{
  advisorID = i;
}
