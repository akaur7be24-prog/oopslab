#include <iostream>
using namespace std;

// ================== Q1 ==================
// Structure for Student
struct Student {
string name;
int rollNo;
string degree;
string hostel;
float cgpa;

void addDetails() {
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Roll No: ";
    cin >> rollNo;
    cout << "Enter Degree: ";
    cin >> degree;
    cout << "Enter Hostel: ";
    cin >> hostel;
    cout << "Enter CGPA: ";
    cin >> cgpa;
}

void updateDetails() {
    cout << "Updating Name: ";
    cin >> name;
}

void updateCGPA() {
    cout << "Enter new CGPA: ";
    cin >> cgpa;
}

void updateHostel() {
    cout << "Enter new Hostel: ";
    cin >> hostel;
}

void displayDetails() {
    cout << "Name: " << name << endl;
    cout << "Roll No: " << rollNo << endl;
    cout << "Degree: " << degree << endl;
    cout << "Hostel: " << hostel << endl;
    cout << "CGPA: " << cgpa << endl;
}


};

// ================== Q2 ==================
// Private & Public access
class Student2 {
private:
string name;
float cgpa;

public:
void setData(string n, float c) {
name = n;
cgpa = c;
}


void display() {
    cout << "Name: " << name << ", CGPA: " << cgpa << endl;
}


};

// ================== Q3 ==================
// Calling private function using public function
class Demo {
private:
void privateFunction() {
cout << "Private Function Called\n";
}

public:
void publicFunction() {
privateFunction(); // calling private inside public
}
};

// ================== Q4 ==================
class Rectangle {
int width, height;

public:
void getData() {
cout << "Enter width and height: ";
cin >> width >> height;
}


void calculateArea() {
    cout << "Area = " << width * height << endl;
}


};

// ================== Q5 ==================
class Complex {
float real, imag;

public:
void setComplex(float r, float i) {
real = r;
imag = i;
}


void displayComplex() {
    cout << real << " + " << imag << "i" << endl;
}

Complex sum(Complex c) {
    Complex temp;
    temp.real = real + c.real;
    temp.imag = imag + c.imag;
    return temp;
}


};

// ================== Q6 ==================
// Scope Resolution
class Test {
public:
void show();
};

void Test::show() {
cout << "Function defined outside class\n";
}

int x = 100; // global

void scopeExample() {
int x = 50; // local
cout << "Local x = " << x << endl;
cout << "Global x = " << ::x << endl; // scope resolution
}

// ================== Q7 ==================
// Namespace example
namespace A {
int value = 10;
void show() {
cout << "Namespace A value: " << value << endl;
}
}

namespace B {
int value = 20;
void show() {
cout << "Namespace B value: " << value << endl;
}
}

// ================== MAIN ==================
int main() {


// Q1
cout << "Q1: Structure Example\n";
Student s;
s.addDetails();
s.displayDetails();

cout << "\n";

// Q2
cout << "Q2: Private & Public\n";
Student2 s2;
s2.setData("Rashi", 8.5);
s2.display();

cout << "\n";

// Q3
cout << "Q3: Private Function Call\n";
Demo d;
d.publicFunction();

cout << "\n";

// Q4
cout << "Q4: Rectangle Area\n";
Rectangle r;
r.getData();
r.calculateArea();

cout << "\n";

// Q5
cout << "Q5: Complex Number\n";
Complex c1, c2, result;

c1.setComplex(2, 3);
c2.setComplex(4, 5);

result = c1.sum(c2);

cout << "Sum = ";
result.displayComplex();

cout << "\n";

// Q6
cout << "Q6: Scope Resolution\n";
Test t;
t.show();
scopeExample();

cout << "\n";

// Q7
cout << "Q7: Namespace\n";
A::show();
B::show();

return 0;


}
