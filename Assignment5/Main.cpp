#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Student.h"
#include "Faculty.h"

using namespace std;

template <class T>
class Node
{
  public:
      T key;
      Node * Left;
      Node * Right;
      Node * Parent;
      Node(T keyParam)
      {
        this->key = keyParam;
        this->Left = NULL;
        this->Right = NULL;
        this->Parent = NULL;
      }


};

template <class T>
class BST
{
    public:

        BST<T>()
        {
          this->root = NULL;
        }
//------------------------------------------------------
        void printInOrderStudent()
        {
          printInOrderStudent(this->root);
        }

        void printInOrderStudent(Node<T>* root)
        {
            if (root == NULL)
                return;
            else
            {
                printInOrderStudent(root->Left);
                cout<<endl;
                cout<<"____________________________________________________"<<endl;
                cout<<"NAME: "<< root->key.getName()<<endl;
                cout<<"----------------------------------------------------"<<endl;
                cout <<"STUDENT ID: ...."<< root->key.getID() << endl;
                cout <<"STANDING: ......"<< root->key.getName() << endl;
                cout <<"MAJOR: ........."<< root->key.getMajor() << endl;
                cout <<"GPA: ..........."<< root->key.getName() << endl;
                cout <<"ADVISOR'S ID: .."<< root->key.getAdvisorID() << endl;
                cout<<"____________________________________________________"<<endl;
                cout<<endl;
                cout<<endl;
                printInOrderStudent(root->Right);
            }
        }
//------------------------------------------------------

        void printInOrderFaculty()
        {
          printInOrderFaculty(this->root);
        }

        void printInOrderFaculty(Node<T>* root)
        {
            if (root == NULL)
                return;
            else
            {
                printInOrderFaculty(root->Left);
                cout<<endl;
                cout<<"____________________________________________________"<<endl;
                cout<<"NAME: "<< root->key.getName()<<endl;
                cout<<"----------------------------------------------------"<<endl;
                cout <<"FACULTY ID: ......."<< root->key.getID() << endl;
                cout <<"DEPARTMENT: ......."<< root->key.getDepartment() << endl;
                cout <<"POSITION: ........."<< root->key.getPosition() << endl;
                cout <<"ADVISEES: [";
                root->key.getAdvisees();
                cout<<"]"<< endl;
                cout<<"____________________________________________________"<<endl;
                cout<<endl;
                cout<<endl;
                printInOrderFaculty(root->Right);
            }
}
//------------------------------------------------------



        Node<T>* search(int id)
        {
            return search(this->root, id);
        }

        Node<T>* search(Node<T>* node,int id)
        {
            Node<T>* result = NULL;
            if (node==NULL)
            {
              return NULL;
            }

            else
            {
                result = search(node->Left,id);
                if(result!=NULL)
                {
                  return result;
                }

                if((node->key.getID()) == id)
                {
                  return node;
                }
                result = search(node->Right,id);
                if(result!=NULL)
                {
                  return result;
                }

            }
            return NULL;
        }


//------------------------------------------------------

        Node<T>* searchMin(Node<T>* node)
        {
            while(node->Left!=NULL)
            {
                node = node->Left;
            }
            return node;
        }
//------------------------------------------------------

        Node<T>* Delete(int val)
        {
            return Delete(this->root, val);
        }

        Node<T>* Delete(Node<T>* node,int val)
        {
        	if(node==NULL)
          {
            return NULL;
          }
        	else if(val < node->key.getID())
        	{
        		node->Left= Delete(node->Left,val);
        	}
        	else if(val > node->key.getID())
        	{
        		node->Right= Delete(node->Right, val);
        	}

        	else
        	{

        		if(root->Right==NULL && node->Left==NULL)
        		{
        			delete node;
        			node = NULL;
        			return node;
        		}

        		else if(node->Left==NULL)
        		{
        			Node<T>* current = node;
        			node = node->Right;
        			delete current;
        			return node;
        		}
        		else if(node->Right == NULL)
        		{
        			Node<T>* current = node;
        			node = node ->Left;
        			delete current;
        			return node;
        		}

        		else
        		{
        			Node<T>* current = searchMin(root->Right);
        			node->key = current->key;
        			node->Right=Delete(node->Right,current->key.getID());
        		}
        	}
        	return root;

        }

//------------------------------------------------------
        void insert(T key)
        {
          Node<T>* newnode = new Node<T>(key);
          if(this->root == NULL)
          {
             this->root = newnode;
             return;
          }

          Node<T>* x = this->root;
          Node<T>* p = NULL;
          while (x != NULL)
          {
              if (key < x->key)
              {
                  if(x->Left == NULL)
                  {
                      x->Left = newnode;
                      break;
                  }
                  else
                  {
                      x = x->Left;
                  }
              }

              else
              {
                  if(x->Right == NULL)
                  {
                      x->Right = newnode;
                      break;
                  }
                  else
                  {
                        x = x->Right;
                  }
                }
          }
        }
//------------------------------------------------------

        void insertPerson(T key)
        {
          Node<T>* newnode = new Node<T>(key);
          if(this->root == NULL)
          {
             this->root = newnode;
             return;
          }

          Node<T>* x = this->root;
          Node<T>* p = NULL;
          while (x != NULL)
          {
              if (key.getID() < x->key.getID())
              {
                  if(x->Left == NULL)
                  {
                      x->Left = newnode;
                      break;
                  }
                  else
                  {
                      x = x->Left;
                  }
              }

              else
              {
                  if(x->Right == NULL)
                  {
                      x->Right = newnode;
                      break;
                  }
                  else
                  {
                        x = x->Right;
                  }
                }
          }
        }

//------------------------------------------------------




        Node<T> *root;

};



int main(int argc, char const *argv[])
{



//------------------------------------------------------



  int userIn = 0;

  BST<Student>* studentDB = new BST<Student>();
  BST<Faculty>* facultyDB = new BST<Faculty>();

  std::list<int> l = { 1,2,3};

  Student s1 = Student(1,"1","1","1",1,123);
  Student s2 = Student(2,"1","1","1",1,1);
  Student s3 = Student(3,"1","1","1",1,1);
  Student s4 = Student(4,"1","1","1",1,1);

  Faculty f1 = Faculty(123,"1","1","1",l);
  Faculty f2 = Faculty(2,"1","1","1");
  Faculty f3 = Faculty(3,"1","1","1");
  Faculty f4 = Faculty(4,"1","1","1");

  facultyDB->insertPerson(f1);
  facultyDB->insertPerson(f2);
  facultyDB->insertPerson(f3);
  facultyDB->insertPerson(f4);

  studentDB->insertPerson(s1);
  studentDB->insertPerson(s2);
  studentDB->insertPerson(s3);
  studentDB->insertPerson(s4);



  while(userIn!=13)
  {

    cout<<endl;
    cout<<endl;
    cout<<"--------------≈≈≈THE DATABASE≈≈---------------"<<endl;
    cout<<"MENU:  *enter number to select"<<endl;
    cout<<"----------------------------------------------"<<endl;
    cout<<"[1]   Print all students and student info."<<endl;
    cout<<"[2]   Print all faculty and student info."<<endl;
    cout<<"[3]   Find student and display info."<<endl;
    cout<<"[4]   Find a faculty member and display info."<<endl;
    cout<<"[5]   Print info of student's faculty advisor"<<endl;
    cout<<"[6]   Print info of faculty's advisees"<<endl;
    cout<<"[7]   Add new student"<<endl;
    cout<<"[8]   Delete student"<<endl;
    cout<<"[9]   Add new faculty member"<<endl;
    cout<<"[10]  Delete faculty member"<<endl;
    cout<<"[11]  Change student's faculty advisor"<<endl;
    cout<<"[12]  Remove advisee from faculty member"<<endl;
    cout<<"[13]  EXIT"<<endl;
    cout<<"----------------------------------------------"<<endl;
    cout<<"ENTER COMMAND: ";
    cin>>userIn;

//-----
    if(userIn==1)
    {
      cout<<endl;
      cout<<"DISPLAYING STUDENTS.........."<<endl;
      studentDB->printInOrderStudent();
      cout<<"ALL STUDENTS DISPLAYED......."<<endl;
    }
//-----
    else if(userIn==2)
    {
      cout<<endl;
      cout<<"DISPLAYING FACULTY.........."<<endl;
      facultyDB->printInOrderFaculty();
      cout<<"ALL FACULTY DISPLAYED......."<<endl;
    }
//-----
    else if(userIn==3)
    {
      int userID = 0;
      cout<<endl;
      cout<<"[--STUDENT SEARCH--]"<<endl;
      cout<<"ENTER STUDENT ID:  ";
      cin>>userID;

      Node<Student>* s = studentDB->search(userID);
      if(s==NULL)
      {
        cout << "ERROR: Sudent not found!"<<endl;
      }
      else
      {
        cout<<endl;
        cout<<"DISPLAYING STUDENT INFO............."<<endl;
        cout<<"____________________________________________________"<<endl;
        cout<<"NAME: "<< s->key.getName()<<endl;
        cout<<"----------------------------------------------------"<<endl;
        cout <<"STUDENT ID: ...."<< s->key.getID() << endl;
        cout <<"STANDING: ......"<< s->key.getName() << endl;
        cout <<"MAJOR: ........."<< s->key.getMajor() << endl;
        cout <<"GPA: ..........."<< s->key.getName() << endl;
        cout <<"ADVISOR'S ID: .."<< s->key.getName() << endl;
        cout<<"____________________________________________________"<<endl;
        cout<<endl;
        cout<<endl;
      }

    }

//-----

    else if(userIn==4)
    {
      int userID = 0;
      cout<<endl;
      cout<<"[--FACULTY SEARCH--]"<<endl;
      cout<<"ENTER FACULTY ID:  ";
      cin>>userID;

      Node<Faculty>* f = facultyDB->search(userID);
      if(f==NULL)
      {
        cout << "ERROR: Faculty member not found!"<<endl;
      }
      else
      {
        cout<<endl;
        cout<<"____________________________________________________"<<endl;
        cout<<"NAME: "<< f->key.getName()<<endl;
        cout<<"----------------------------------------------------"<<endl;
        cout <<"FACULTY ID: ......."<< f->key.getID() << endl;
        cout <<"DEPARTMENT: ......."<< f->key.getDepartment() << endl;
        cout <<"POSITION: ........."<< f->key.getPosition() << endl;
        cout <<"ADVISEES: [";
        f->key.getAdvisees();
        cout<<"]"<< endl;
        cout<<"____________________________________________________"<<endl;
        cout<<endl;
        cout<<endl;
      }
    }


//-----


    else if(userIn==5)
    {
      int userID = 0;
      cout<<endl;
      cout<<"[--SEARCH FOR STUDENT'S ADVISOR--]"<<endl;
      cout<<"ENTER STUDENT ID:  ";
      cin>>userID;

      Node<Student>* s = studentDB->search(userID);

      if(s==NULL)
      {
        cout << "ERROR: student not found!"<<endl;
      }
      else
      {
        Node<Faculty>* f = facultyDB->search(s->key.getAdvisorID());
        if(f==NULL)
        {
          cout << "ERROR: Faculty member not found!"<<endl;
        }
        else
        {
            cout<<endl;
            cout<<"DISPLAYING STUDENT'S ADVISOR INFO............."<<endl;
            cout<<"____________________________________________________"<<endl;
            cout<<"NAME: "<< f->key.getName()<<endl;
            cout<<"----------------------------------------------------"<<endl;
            cout <<"FACULTY ID: ......."<< f->key.getID() << endl;
            cout <<"DEPARTMENT: ......."<< f->key.getDepartment() << endl;
            cout <<"POSITION: ........."<< f->key.getPosition() << endl;
            cout <<"ADVISEES: [";
            f->key.getAdvisees();
            cout<<"]"<< endl;
            cout<<"____________________________________________________"<<endl;
            cout<<endl;
            cout<<endl;
        }
      }
    }


//-----
    else if(userIn==6)
    {
      int userFacultyID;
      std::list<int> adviseeIDs;

      cout<<endl;
      cout<<"[----SHOW FACULTY ADVISEE INFO.----]"<<endl;

      cout<<"ENTER FACULTY ID#:  ";
      cin>>userFacultyID;
      cout<<endl;

      Node<Faculty>* f = facultyDB->search(userFacultyID);
      if(f==NULL)
      {
        cout << "ERROR: Faculty member not found!"<<endl;
      }
      else
      {
        adviseeIDs=f->key.adviseID;

        cout<<"SHOWING " <<f->key.getName()<<"'s ADVISEE INFO: ";

        for (list<int>::const_iterator i = adviseeIDs.begin(); i != adviseeIDs.end(); ++i)
        {
          Node<Student>* s = studentDB->search(*i);
          if(s==NULL)
          {
            cout << "ERROR: Sudent not found!"<<endl;
          }
          else
          {
            cout<<endl;
            cout<<"____________________________________________________"<<endl;
            cout<<"NAME: "<< s->key.getName()<<endl;
            cout<<"----------------------------------------------------"<<endl;
            cout <<"STUDENT ID: ...."<< s->key.getID() << endl;
            cout <<"STANDING: ......"<< s->key.getName() << endl;
            cout <<"MAJOR: ........."<< s->key.getMajor() << endl;
            cout <<"GPA: ..........."<< s->key.getName() << endl;
            cout <<"ADVISOR'S ID: .."<< s->key.getName() << endl;
            cout<<"____________________________________________________"<<endl;
            cout<<endl;
            cout<<endl;
          }
        }
        cout<<"ALL ADVISEES DISPLAYED............."<<endl;
        cout<<endl;
      }

    }
//-----
    else if(userIn==7)
    {
      int userStudentID;
      string userName;
      string userStanding;
      string userMajor;
      double userGPA;
      int userAdvisorID;

      cout<<endl;
      cout<<"[--------ADD NEW STUDENT---------]"<<endl;
      cout<<"ENTER STUDENT NAME:  ";
      cin>>userName;
      cout<<endl;

      cout<<"ENTER STUDENT ID#:  ";
      cin>>userStudentID;
      cout<<endl;

      cout<<"ENTER STANDING:  ";
      cin>>userStanding;
      cout<<endl;

      cout<<"ENTER STUDENT'S MAJOR:  ";
      cin>>userMajor;
      cout<<endl;

      cout<<"ENTER GPA:  ";
      cin>>userGPA;
      cout<<endl;

      cout<<"ENTER ADVISOR ID#:  ";
      cin>>userAdvisorID;
      cout<<endl;
      Student s = Student(userStudentID,userName,userStanding,userMajor,userGPA,userAdvisorID);
      studentDB->insertPerson(s);

      cout<<"STUDENT '"<<userName<<"' ADDED!"<<endl;

    }
//-----
    else if(userIn==8)
    {
      int userStudentID;

      cout<<endl;
      cout<<"[--------DELETE STUDENT---------]"<<endl;
      cout<<"ENTER STUDENT ID#:  ";
      cin>>userStudentID;
      Node<Student>* s = studentDB->search(userStudentID);
      if(s==NULL)
      {
        cout << "ERROR: student not found!"<<endl;
      }
      else
      {
        cout<<"..............."<<endl;
        cout<<"DELETING STUDENT: "<< s->key.getName()<<endl;
        studentDB->Delete(userStudentID);
        cout<<"[-------------------------------]"<<endl;
      }
    }

//-----
    else if(userIn==9)
    {
      int userFacultyID;
      string userName;
      string userPosition;
      string userDepartment;
      char cont = 'y';
      std::list<int> adviseeIDs;

      cout<<endl;
      cout<<"[--------ADD NEW FACULTY MEMBER---------]"<<endl;
      cout<<"ENTER FACULTY NAME:  ";
      cin>>userName;
      cout<<endl;

      cout<<"ENTER FACULTY ID#:  ";
      cin>>userFacultyID;
      cout<<endl;

      cout<<"ENTER POSITION:  ";
      cin>>userPosition;
      cout<<endl;

      cout<<"ENTER FACULTY'S DEPARTMENT:  ";
      cin>>userDepartment;
      cout<<endl;

      while(cont=='y')
      {
        cout<<"ENTER ADVISEE ID NUMBERS:  ";
        int userAdviseeID;
        cin>>userAdviseeID;
        cout<<endl;

        adviseeIDs.push_front(userAdviseeID);

        cout<<"Add another advisee? *y to continue, n to exit* "<<endl;

        cin>>cont;
        if(cont=='n')
        {
          break;
        }
      }

      Faculty f = Faculty(userFacultyID,userName,userPosition,userDepartment,adviseeIDs);
      facultyDB->insertPerson(f);

      cout<<"FACULTY MEMBER '"<<userName<<"' ADDED!"<<endl;
    }
//-----
    else if(userIn==10)
    {
      int userFacultyID;

      cout<<endl;
      cout<<"[--------DELETE FACULTY---------]"<<endl;
      cout<<"ENTER FACULTY ID#:  ";
      cin>>userFacultyID;
      Node<Faculty>* f = facultyDB->search(userFacultyID);
      if(f==NULL)
      {
        cout << "ERROR: Faculty member not found!"<<endl;
      }
      else
      {
        cout<<"..............."<<endl;
        cout<<"DELETING FACULTY: "<< f->key.getName()<<endl;
        facultyDB->Delete(userFacultyID);
        cout<<"[------------------------------]"<<endl;
      }
    }
//-----
    else if(userIn==11)
    {
      int userID;
      int userFacultyID;

      cout<<endl;
      cout<<"[-----CHANGE STUDENT'S ADVISOR------]"<<endl;
      cout<<"ENTER STUDENT ID#:  ";
      cin>>userID;

      Node<Student>* s = studentDB->search(userID);
      cout<<"ENTER NEW ADVISOR'S ID#:  ";
      cin>>userFacultyID;
      s->key.setAdvisorID(userFacultyID);
      cout<<"..............."<<endl;
      cout<<"ADVISOR ID# CHANGED TO: "<< s->key.getAdvisorID()<<endl;
    }
//-----
    else if(userIn==12)
    {
      int userFacultyID;
      char cont = 'y';
      std::list<int> adviseeIDs;


      cout<<endl;
      cout<<"[-------DELETE FACULTY ADVISEES------]"<<endl;

      cout<<"ENTER FACULTY ID#:  ";
      cin>>userFacultyID;
      cout<<endl;

      Node<Faculty>* f = facultyDB->search(userFacultyID);
      if(f==NULL)
      {
        cout << "ERROR: Faculty member not found!"<<endl;
      }
      else
      {
        adviseeIDs=f->key.adviseID;

        cout<<f->key.getName()<<"'s advisees: ";
        f->key.getAdvisees();
        cout<<endl;

        while(cont=='y')
        {
          cout<<"ENTER ADVISEE ID TO DELETE:  ";
          int userAdviseeID;
          cin>>userAdviseeID;
          cout<<endl;

          adviseeIDs.remove(userAdviseeID);
          f->key.setAdvisees(adviseeIDs);
          cout<<"..............."<<endl;

          cout<<"DELETING ADVISEE: "<< userAdviseeID<<endl;

          cout<<"Delete another advisee? *y to continue, n to exit* "<<endl;

          cin>>cont;
          if(cont=='n')
          {
            cout<<"UPDATED ADVISEE LIST:";
            f->key.getAdvisees();
            cout<<endl;
            break;
          }
        }
      }
    }
  }
}
