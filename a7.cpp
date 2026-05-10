#include <iostream>
#include <cmath>
using namespace std;

// ================== Q1 ==================
// Polygon ? Rectangle, Triangle (Runtime Polymorphism)

class Polygon {
protected:
int w, h;

public:
void set_value(int a, int b) {
w = a; h = b;
}

virtual int area() {
    return 0;
}

};

class Rectangle : public Polygon {
public:
int area() {
return w * h;
}
};

class Triangle : public Polygon {
public:
int area() {
return (w * h) / 2;
}
};

// ================== Q2 ==================
// Shape class (virtual functions)

class Shape {
public:
virtual void area() {}
virtual void display() {}
};

class Circle : public Shape {
float r;
public:
Circle(float x) { r = x; }
void area() {
cout << "Circle Area = " << 3.14 * r * r << endl;
}
void display() {
cout << "Circle\n";
}
};

class Rect : public Shape {
float l, b;
public:
Rect(float x, float y) { l = x; b = y; }
void area() {
cout << "Rectangle Area = " << l * b << endl;
}
void display() {
cout << "Rectangle\n";
}
};

// ================== Q3 ==================
// Area using overloading

class TriangleType {
public:
void area(int a) {
cout << "Equilateral Area = " << (sqrt(3)/4)*a*a << endl;
}

void area(int base, int height) {
    cout << "Right Triangle Area = " << (base*height)/2 << endl;
}

};

// ================== Q4 ==================
// Abstract class Student

class Student {
public:
virtual void show() = 0;
};

class Engineering : public Student {
public:
void show() {
cout << "Engineering Student\n";
}
};

class Medicine : public Student {
public:
void show() {
cout << "Medical Student\n";
}
};

// ================== Q5 ==================
// Time + operator overloading

class Time {
int h, m, s;

public:
Time(int a=0,int b=0,int c=0) {
h=a; m=b; s=c;
}

Time operator+(Time t) {
    return Time(h+t.h, m+t.m, s+t.s);
}

void show() {
    cout << h << ":" << m << ":" << s << endl;
}

};

// ================== Q6 ==================
class String {
string str;

public:
String(string s="") { str = s; }

bool operator==(String s) {
    return str == s.str;
}

String operator+(String s) {
    return String(str + s.str);
}

void display() {
    cout << str << endl;
}

};

// ================== Q7 ==================
class Matrix {
int a[2][2];

public:
void input() {
for(int i=0;i<2;i++)
for(int j=0;j<2;j++)
cin >> a[i][j];
}

void display() {
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

friend Matrix operator*(Matrix m1, Matrix m2);

};

Matrix operator*(Matrix m1, Matrix m2) {
Matrix res;
for(int i=0;i<2;i++)
for(int j=0;j<2;j++) {
res.a[i][j]=0;
for(int k=0;k<2;k++)
res.a[i][j]+=m1.a[i][k]*m2.a[k][j];
}
return res;
}

// ================== Q9 ==================
class Input {
int x;
public:
void operator()(int a) {
x = a;
cout << "Stored: " << x << endl;
}
};

// ================== Q10 ==================
class Data {
int x;
public:
friend istream& operator>>(istream &in, Data &d) {
in >> d.x;
return in;
}

friend ostream& operator<<(ostream &out, Data d) {
    out << d.x;
    return out;
}

};

// ================== Q11 ==================
class Test {
float x;
public:
Test(float f) { x = f; }
void display() { cout << x << endl; }
};

// ================== Q12 ==================
class Test2 {
float x;
public:
Test2(float a) { x = a; }
operator float() {
return x;
}
};

// ================== Q13 ==================
class Polar {
float r, angle;
public:
Polar(float a, float b) { r=a; angle=b; }
float getR() { return r; }
float getAngle() { return angle; }
};

class Cartesian {
float x, y;
public:
Cartesian(Polar p) {
x = p.getR()*cos(p.getAngle());
y = p.getR()*sin(p.getAngle());
}

void show() {
    cout << "x=" << x << " y=" << y << endl;
}

};

// ================== MAIN ==================
int main() {

// Q1
Polygon *p;
Rectangle r; Triangle t;
r.set_value(4,5);
t.set_value(4,5);

p=&r; cout<<"Rectangle: "<<p->area()<<endl;
p=&t; cout<<"Triangle: "<<p->area()<<endl;

cout << "\n";

// Q2
Shape *s;
Circle c(3);
Rect rec(4,5);

s=&c; s->display(); s->area();
s=&rec; s->display(); s->area();

cout << "\n";

// Q3
TriangleType tt;
tt.area(5);
tt.area(4,6);

cout << "\n";

// Q4
Student *st[2];
Engineering e; Medicine m;
st[0]=&e; st[1]=&m;

for(int i=0;i<2;i++)
    st[i]->show();

cout << "\n";

// Q5
Time t1(1,2,3), t2(2,3,4), t3;
t3 = t1 + t2;
t3.show();

cout << "\n";

// Q6
String s1("Hello"), s2("World");
String s3 = s1 + s2;
s3.display();

cout << "\n";

// Q7
Matrix m1,m2,m3;
cout<<"Enter matrix1:\n"; m1.input();
cout<<"Enter matrix2:\n"; m2.input();

m3 = m1 * m2;
cout<<"Result:\n"; m3.display();

cout << "\n";

// Q9
Input obj;
obj(10);

cout << "\n";

// Q10
Data d;
cout<<"Enter value: ";
cin>>d;
cout<<"You entered: "<<d<<endl;

cout << "\n";

// Q11
Test t4 = 5.5;
t4.display();

// Q12
Test2 t5(10.5);
float val = t5;
cout << "Converted: " << val << endl;

cout << "\n";

// Q13
Polar p1(10,0.5);
Cartesian c1 = p1;
c1.show();

return 0;

}
