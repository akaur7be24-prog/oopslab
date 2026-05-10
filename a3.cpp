#include <iostream>
using namespace std;

// ================== Q1 ==================
// Pointer to object & this pointer
class Demo {
public:
int x;

void setData(int x) {
    this->x = x; // this pointer
}

void show() {
    cout << "Value = " << x << endl;
}


};

// ================== Q2 ==================
// Swap private values using friend function
class A {
private:
int val;

public:
A(int v) { val = v; }

friend void swapValues(A &, A &);

void display() {
    cout << val << endl;
}


};

void swapValues(A &a1, A &a2) {
int temp = a1.val;
a1.val = a2.val;
a2.val = temp;
}

// ================== Q3 ==================
// Add objects of two classes using friend
class B;

class A2 {
int x;

public:
A2(int a) { x = a; }
friend int add(A2, B);
};

class B {
int y;

public:
B(int b) { y = b; }
friend int add(A2, B);
};

int add(A2 a, B b) {
return a.x + b.y;
}

// ================== Q4 ==================
// Friend class example
class First {
private:
int data;

public:
First(int d) { data = d; }

friend class Second;

};

class Second {
public:
void show(First f) {
cout << "Accessing private data: " << f.data << endl;
}
};

// ================== Q5 ==================
// Array of objects (Rectangle area)
class Rectangle {
int l, b;

public:
void setData(int x, int y) {
l = x;
b = y;
}

void area() {
    cout << "Area = " << l * b << endl;
}


};

// ================== Q6 ==================
// Inline function cube
inline int cube(int x) {
return x * x * x;
}

// ================== Q7 ==================
// Pass object & return object

class Number {
public:
int val;

Number(int v = 0) { val = v; }

};

// Pass by value
Number addValue(Number n) {
n.val += 10;
return n;
}

// Pass by address
Number addAddress(Number *n) {
n->val += 20;
return *n;
}

// ================== MAIN ==================
int main() {

// Q1
cout << "Q1: Pointer to Object & this pointer\n";
Demo d;
Demo *ptr = &d;

ptr->setData(10); // arrow operator
d.show();         // dot operator

cout << "\n";


// Q2
cout << "Q2: Swap using Friend Function\n";
A a1(5), a2(10);

cout << "Before Swap: ";
a1.display();
a2.display();

swapValues(a1, a2);

cout << "After Swap: ";
a1.display();
a2.display();

cout << "\n";


// Q3
cout << "Q3: Add two class objects\n";
A2 obj1(3);
B obj2(7);

cout << "Sum = " << add(obj1, obj2) << endl;

cout << "\n";


// Q4
cout << "Q4: Friend Class\n";
First f(100);
Second s;
s.show(f);

cout << "\n";


// Q5
cout << "Q5: Array of Objects\n";
Rectangle r[3];

r[0].setData(2, 3);
r[1].setData(4, 5);
r[2].setData(6, 7);

for(int i = 0; i < 3; i++) {
    r[i].area();
}

cout << "\n";


// Q6
cout << "Q6: Inline Function (Cube)\n";
int num = 3;
cout << "Cube = " << cube(num) << endl;

cout << "\n";


// Q7
cout << "Q7: Pass Object & Return Object\n";

Number n1(10);

// Pass by value
Number result1 = addValue(n1);
cout << "After pass by value: " << result1.val << endl;

// Pass by address
Number result2 = addAddress(&n1);
cout << "After pass by address: " << result2.val << endl;

return 0;

}
