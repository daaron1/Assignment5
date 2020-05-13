#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
using namespace std;

class Faculty
{
  public:
    Faculty();
    Faculty(int id, string n, string p, string d, std::list<int> l);
    Faculty(int id, string n, string p, string d);


    void addAdvisee(int id);

    int getID();
    string getName();
    string getPosition();
    string getDepartment();
    int getAdvisees();
    void setAdvisees(std::list<int> l);

    int facultyID;
    string name;
    string position;
    string department;
    std::list<int> adviseID;

};
