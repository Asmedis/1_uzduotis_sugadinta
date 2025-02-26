// Creator: Martynas Masionis, VU, 2025 
// This file contains a class for an employee that tracks the name, position, salary, and id of the employee. 
// The main function tests all the methods of the class.

#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

class employee
{
    private:
        //---Constructor variables---
        string name;
        string position;
        int salary;
        int id;

        //---Static variables---
        static int idCounter;

    public:
        //---Initialization---
        employee (string name)
        {
            setDefault(name);
        }
        
        employee (string name, string position, int salary)
        { 
            setDefault(name);
            this -> position = position;
            this -> salary = salary;
        }

        //---Destructor---
        ~employee ()
        {
        }

        //---Getters---
        string getName ()
        {
            return name;
        }

        string getPosition ()
        {
            return position;
        }

        int getSalary ()
        {
            return salary;
        }

        int getId ()
        {
            return id;
        }

    private:
        //---Setters---
        void setDefault(string name)
        {
            this -> name = name;
            this -> position = "";
            this -> salary = 0;
            setId(idCounter);
        }

    public:
        void setName (string name)
        {
            this -> name = name;
        }

        void setPosition (string position)
        {
            this -> position = position;
        }

        void setSalary (int salary)
        {
            if (salary < 0)
            {
                throw invalid_argument("Salary cannot be negative!");
            }
            else{
                this -> salary = salary;
            }
        }

    private:
        void setId (int id)
        {
            this -> id = id;
            idCounter++;
        }

        //---Debugging---
        public:
        string toString()
        {
            stringstream output;
            output << "Nm:" << name << " Pos:" << position << " Sal:" << salary << " ID:" << id << endl;
            return output.str();
        }

};
//---Initialization of static variables---
int employee::idCounter = 0;

int main ()
{
    employee* array[5];

    //---Testing---
    array[0] = new employee("Joe Rogan", "Manager", 1200);
    array[1] = new employee("Will Smith", "Assistant Manager", 1000);
    array[2] = new employee("Elon Musk", "Cashier", 800);
    array[3] = new employee("Gitanas Naudeda", "Cashier", 800);
    array[4] = new employee("Michael Jordan");

    //--Initialization--
    assert(array[0] -> getName() == "Joe Rogan");
    assert(array[0] -> getPosition() == "Manager");
    assert(array[0] -> getSalary() == 1200);
    assert(array[0] -> getId() == 0);

    assert(array[4] -> getName() == "Michael Jordan");
    assert(array[4] -> getPosition() == "");
    assert(array[4] -> getSalary() == 0);
    assert(array[4] -> getId() == 4);

    //--Setters--
    array[0] -> setName("Joe Biden");
    array[0] -> setPosition("Ice cream man");
    array[0] -> setSalary(200000);

    assert(array[0] -> getName() == "Joe Biden");
    assert(array[0] -> getPosition() == "Ice cream man");
    assert(array[0] -> getSalary() == 200000);

    array[0] -> setSalary(0);
    assert(array[0]->getSalary() == 0);

    //--toString--
    assert(array[0]->toString() == "Nm:Joe Biden Pos:Ice cream man Sal:0 ID:0\n");

    //--Destructor--
    for(int i = 5; i > 0; i--)
    {
        delete array[i];
    }
    
    return 0;
}