#include <iostream>
using namespace std;

// ================== Q1 ==================
// Constructor overloading (0, 1, 2 parameters)

class Rectangle {
int length, breadth;

public:
// Default constructor
Rectangle() {
length = 0;
breadth = 0;
}

// One parameter constructor
Rectangle(int x) {
    length = breadth = x;
}

// Two parameter constructor
Rectangle(int l, int b) {
    length = l;
    breadth = b;
}

void area() {
    cout << "Area = " << length * breadth << endl;
}

};

// ================== Q2 ==================
// Array of objects + default args + destructor

class Rect2 {
int l, b;

public:
// Constructor with default arguments
Rect2(int x = 0, int y = 0) {
l = x;
b = y;
}

void area() {
    cout << "Area = " << l * b << endl;
}

// Destructor
~Rect2() {
    cout << "Destructor called\n";
}

};

// ================== Q3 ==================
// Destructor rules demo

class Demo {
public:
Demo() {
cout << "Constructor called\n";
}

~Demo() {   // Destructor (no return type, no parameters)
    cout << "Destructor called\n";
}

};

// ================== Q4 ==================
// Dynamic memory allocation

class Sample {
public:
int x;

void show() {
    cout << "Value = " << x << endl;
}

};

// ================== MAIN ==================
int main() {


// Q1
cout << "Q1: Constructor Overloading\n";

Rectangle r1;        // 0 parameter
Rectangle r2(5);     // 1 parameter
Rectangle r3(4, 6);  // 2 parameter

r1.area();
r2.area();
r3.area();

cout << "\n";


// Q2
cout << "Q2: Array of Objects + Destructor\n";

Rect2 arr[3] = { Rect2(), Rect2(5), Rect2(3,4) };

for(int i = 0; i < 3; i++) {
    arr[i].area();
}

cout << "\n";


// Q3
cout << "Q3: Destructor Rules\n";

Demo d;  // constructor + destructor auto call

cout << "\n";


// Q4
cout << "Q4: Dynamic Memory Allocation\n";

// Integer
int *p = new int;
*p = 10;
cout << "Integer: " << *p << endl;
delete p;

// Float
float *f = new float;
*f = 5.5;
cout << "Float: " << *f << endl;
delete f;

// Array
int *arr2 = new int[3];
for(int i = 0; i < 3; i++) {
    arr2[i] = i + 1;
    cout << arr2[i] << " ";
}
cout << endl;
delete[] arr2;

// Object
Sample *obj = new Sample;
obj->x = 99;
obj->show();
delete obj;

// Array of objects
Sample *objArr = new Sample[2];
objArr[0].x = 1;
objArr[1].x = 2;

objArr[0].show();
objArr[1].show();

delete[] objArr;

return 0;


}
