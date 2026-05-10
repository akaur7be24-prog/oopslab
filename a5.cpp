// ================== LAB ASSIGNMENT 5 ==================
#include <iostream>
using namespace std;

// ================== Q1 ==================
// Base & Derived class
class Base {
public:
void showBase() {
cout << "This is Base class\n";
}
};

class Derived1 : public Base {
public:
void showDerived() {
cout << "This is Derived class\n";
}
};

// ================== Q2 ==================
// Protected access specifier
class Base2 {
protected:
int x;
};

class Derived2 : public Base2 {
public:
void setData() {
x = 10;
cout << "Protected x = " << x << endl;
}
};

// ================== Q3 ==================
// Public, Protected, Private inheritance demo
class Base3 {
public:
int a = 1;
protected:
int b = 2;
private:
int c = 3;
};

class Derived3 : public Base3 {
public:
void show() {
cout << "Public a = " << a << endl;
cout << "Protected b = " << b << endl;
}
};

// ================== Q4 ==================
// Types of inheritance

// Single
class A {
public:
void showA() { cout << "A\n"; }
};
class B : public A {
public:
void showB() { cout << "B\n"; }
};

// Multilevel
class C : public B {
public:
void showC() { cout << "C\n"; }
};

// Multiple
class D {
public:
void showD() { cout << "D\n"; }
};
class E : public C, public D {
public:
void showE() { cout << "E\n"; }
};

// Hierarchical
class F : public A {
public:
void showF() { cout << "F\n"; }
};

// ================== Q5 ==================
// Constructor & Destructor in inheritance
class Parent {
public:
Parent() { cout << "Parent Constructor\n"; }
~Parent() { cout << "Parent Destructor\n"; }
};

class Child : public Parent {
public:
Child() { cout << "Child Constructor\n"; }
~Child() { cout << "Child Destructor\n"; }
};

// ================== Q6 ==================
// Book ? Textbook
class Book {
protected:
string title;
float price;

public:
void getBook() {
cout << "Enter title & price: ";
cin >> title >> price;
}
};

class Textbook : public Book {
string subject;

public:
void getTextbook() {
getBook();
cout << "Enter subject: ";
cin >> subject;
}

void display() {
    cout << title << " " << price << " " << subject << endl;
}

};

// ================== Q7 ==================
// Car Dashboard (Multiple Inheritance)
class Speedometer {
protected:
int speed;
};

class FuelGauge {
protected:
int fuel;
};

class Thermometer {
protected:
int temp;
};

class Dashboard : public Speedometer, public FuelGauge, public Thermometer {
public:
void setData() {
cout << "Enter speed, fuel, temp: ";
cin >> speed >> fuel >> temp;
}

void display() {
    cout << "Speed: " << speed << ", Fuel: " << fuel << ", Temp: " << temp << endl;
}

};

// ================== Q8 ==================
// Library Users (Hierarchical)
class LibraryUser {
protected:
string name;

public:
void getUser() {
cout << "Enter name: ";
cin >> name;
}
};

class Student : public LibraryUser {
int grade;

public:
void getStudent() {
getUser();
cout << "Enter grade: ";
cin >> grade;
}

void show() {
    cout << "Student: " << name << ", Grade: " << grade << endl;
}

};

class Teacher : public LibraryUser {
string dept;

public:
void getTeacher() {
getUser();
cout << "Enter dept: ";
cin >> dept;
}

void show() {
    cout << "Teacher: " << name << ", Dept: " << dept << endl;
}

};

// ================== Q9 ==================
// Logistics (Multilevel)
class Vehicle {
protected:
string model;
};

class Truck : public Vehicle {
protected:
int capacity;
};

class RefrigeratedTruck : public Truck {
int tempControl;

public:
void setData() {
cout << "Enter model, capacity, temp: ";
cin >> model >> capacity >> tempControl;
}

void display() {
    cout << model << " " << capacity << " " << tempControl << endl;
}

};

// ================== Q10 ==================
// Hybrid Inheritance (Teaching Assistant)

class Person {
protected:
string name;
};

class Staff : public Person {
protected:
int empId;
};

class Student2 : public Person {
protected:
int roll;
};

class TeachingAssistant : public Staff, public Student2 {
public:
void setData() {
cout << "Enter name, empId, roll: ";
cin >> Staff::name >> empId >> roll;
}

void display() {
    cout << "Name: " << Staff::name 
         << ", EmpID: " << empId 
         << ", Roll: " << roll << endl;
}

};

// ================== MAIN ==================
int main() {

// Q1
cout << "Q1\n";
Derived1 d1;
d1.showBase();
d1.showDerived();

cout << "\n";

// Q2
cout << "Q2\n";
Derived2 d2;
d2.setData();

cout << "\n";

// Q3
cout << "Q3\n";
Derived3 d3;
d3.show();

cout << "\n";

// Q4
cout << "Q4\n";
E obj;
obj.showA();
obj.showB();
obj.showC();
obj.showD();
obj.showE();

cout << "\n";

// Q5
cout << "Q5\n";
Child c;

cout << "\n";

// Q6
cout << "Q6\n";
Textbook t;
t.getTextbook();
t.display();

cout << "\n";

// Q7
cout << "Q7\n";
Dashboard db;
db.setData();
db.display();

cout << "\n";

// Q8
cout << "Q8\n";
Student s;
s.getStudent();
s.show();

Teacher t1;
t1.getTeacher();
t1.show();

cout << "\n";

// Q9
cout << "Q9\n";
RefrigeratedTruck rt;
rt.setData();
rt.display();

cout << "\n";

// Q10
cout << "Q10\n";
TeachingAssistant ta;
ta.setData();
ta.display();

return 0;

}
