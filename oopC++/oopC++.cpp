#include <iostream>
using namespace std;
/*
Object Oriented Programming Principles or Pillars
1-Encapsulation -> Everything allow us Bundling of data.
2-Abstraction
3-Inheritance
4-Polymorphysm
*/ 
//AbstractEmployee -> Abastraction
//a class is an example of Encapsulation
class AbstractEmployee {
    virtual void AskForPromotion() = 0;
};
//a class is an example of Encapsulation
//Employee is a subclass of AbtractEmployee Parent class -> Inheritance
class Employee: AbstractEmployee {
//modifier -> Encapsulation
protected: 
    string Name;
//modifier -> Encapsulation
private:
    string Company;
    int Age;
//modifier -> Encapsulation
public:
    //setters
    void setName(string name) {
        Name = name;
    }
    void setCompany(string company) {
        Company = company;
    }
    void setAge(int age) {
        if(age>=18)
        Age = age;
    }
    //getters
    string getName() {
        return Name;
    }
    string getCompany() {
        return Company;
    }
    int getAge() {
        return Age;
    }

    //constructor
    /*
    Main Rules
    1-Constructors have the same name as the class itself
    2-Constructors don’t have return type
    3-Constructors must be placed in public section of class.
    Another indications
    1-A constructor is automatically called when an object is created.
    2-If we do not specify a constructor, C++ compiler generates a default constructor for object (expects no parameters and has an empty body).
    */
    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }

    //print employee information method
    void information() {
        cout << "Name: " << Name << endl;
        cout << "Company: " << Company << endl;
        cout << "Age: " << Age << endl;
    }

    //ask for promotion method
    void AskForPromotion() {
        if (Age > 25)
            cout << "Promotion: " << Name << " got promoted!" << endl;
        else
            cout << "Message: " << Name << ", sorry NO promotion for you!" << endl;
    }

    //Polymorphism
    virtual void work() {
        cout << Name << " is checking email, task backlog, performing tasks..." << endl;
    }
};

//Developer is a subclass of Employee and a sub-subclass of AbstractEmployee
class Developer: public Employee {
//modifier
public:
    string ProgramLanguage;
    
    //constructor
    Developer(string name, string company, int age, string programLanguage): Employee(name, company, age) {
        ProgramLanguage = programLanguage;
    }

    //fixbug method
    void fixBug() {
        cout << "Task: " << Name << " fixed bug using " << ProgramLanguage << endl;
    }

    //Polymorphism
    void work() {
        cout << "Job: " << Name << " is writing " <<ProgramLanguage << " code" << endl;
    }

};

class Teacher: public Employee {
public:
    string Subject;
    
    //constructor
    Teacher(string name, string company, int age, string subject): Employee(name, company, age) {
        Subject = subject;
    }

    //prepareLesson method
    void prepareLesson() {
        cout << "Task: " << Name << " prepared " << Subject << " lessons " << endl;
    }

    //Polymorphism
    void work() {
        cout << "Job: " << Name << " is teaching " << Subject << endl;
    }
};

//main class
int main()
{   
    //objects of Developer class and Teacher class
    Developer d = Developer("Manuel", "X-Engineers", 32, "C++");
    Teacher t = Teacher("Astryd", "Cool School", 25, "English");
    //Pointers or reference
    Employee* e1 = &d; // e1 will have reference of developer class
    Employee* e2 = &t; // e2 will have reference of teacher class
    //Call methods
    d.information();
    e1->work(); // call developer work() method using pointer   
    d.fixBug();
    d.AskForPromotion();
    t.information();
    e2->work(); //call teacher work() method using pointer
    t.prepareLesson();
    t.AskForPromotion();

    system("pause");
}