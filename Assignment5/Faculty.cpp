#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <list>
#include <iterator>
#include "Faculty.h"
using namespace std;

Faculty::Faculty(){
}

Faculty::Faculty(int id, string n, string p, string d, std::list<int> l)
{
  facultyID= id;
  name= n;
  position = p;
  department = d;
  adviseID = l;
}

Faculty::Faculty(int id, string n, string p, string d)
{
  facultyID= id;
  name= n;
  position = p;
  department = d;
}

int Faculty::getID()
{
  return facultyID;
}

string Faculty::getName()
{
  return name;
}
string Faculty::getDepartment()
{
  return department;
}
string Faculty::getPosition()
{
  return position;
}

int Faculty::getAdvisees()
{
  for (list<int>::const_iterator i = adviseID.begin(); i != adviseID.end(); ++i)
  {
    cout << *i << ",";
  }
  return 0;

}

void Faculty::setAdvisees(std::list<int> l)
{
  adviseID = l;
}
