#include <iostream>
using namespace std;

// ================== Q1 ==================
// Library + Book (Array of Objects + functions)

class Book {
string title, author, ISBN;

public:
Book() {}  // default constructor

Book(string t, string a, string i) {  // parameter constructor
    title = t;
    author = a;
    ISBN = i;
}

// Copy constructor
Book(const Book &b) {
    title = b.title;
    author = b.author;
    ISBN = b.ISBN;
}

string getISBN() {
    return ISBN;
}

void display() {
    cout << title << " | " << author << " | " << ISBN << endl;
}

};

class Library {
Book books[10];
int count;

public:
Library() {
count = 0;
}

// Add Book (pass by reference)
bool addNewBook(string &t, string &a, string &i) {
    if (count < 10) {
        books[count] = Book(t, a, i);
        count++;
        return true;
    }
    return false;
}

// Remove Book (defined outside class)
bool removeBooks(string &isbn);

void displayDetails() {
    for (int i = 0; i < count; i++) {
        books[i].display();
    }
}

};

// Function outside class using scope resolution
bool Library::removeBooks(string &isbn) {
for (int i = 0; i < count; i++) {
if (books[i].getISBN() == isbn) {
books[i] = books[count - 1];
count--;
return true;
}
}
return false;
}

// ================== Q2 ==================
// this pointer + constructors

class Book2 {
string title, author, ISBN;

public:
Book2() {}

Book2(string t, string a, string i) {
    this->title = t;
    this->author = a;
    this->ISBN = i;
}

Book2(const Book2 &b) {
    title = b.title;
    author = b.author;
    ISBN = b.ISBN;
}

void display() {
    cout << title << " " << author << " " << ISBN << endl;
}

};

// ================== Q3 ==================
// Account system

class Account {
long accNo;
long transactionID;
string type;
double balance;

public:
void setData(long a, double b) {
accNo = a;
balance = b;
transactionID = 0;
}

long depositAmount(long to, long from, double amt) {
    balance += amt;
    transactionID++;
    type = "credit";
    return transactionID;
}

long withdrawAmount(long to, long from, double amt) {
    if (balance >= amt) {
        balance -= amt;
        transactionID++;
        type = "debit";
        return transactionID;
    }
    return -1;
}

void displayDetails() const {
    cout << "AccNo: " << accNo 
         << ", Balance: " << balance 
         << ", Last Transaction: " << type << endl;
}

};

// ================== Q4 ==================
// Friend function (Add objects)

class B;

class A {
int x;

public:
void set(int a) { x = a; }
friend int add(A, B);
};

class B {
int y;

public:
void set(int b) { y = b; }
friend int add(A, B);
};

int add(A a, B b) {
return a.x + b.y;
}

// ================== Q5 ==================
// Complex class

class Complex {
float real, imag;

public:
// Parameterized constructor
Complex(float r = 0, float i = 0) {
real = r;
imag = i;
}

// Copy constructor
Complex(const Complex &c) {
    real = c.real;
    imag = c.imag;
}

void display() {
    cout << real << " + " << imag << "i" << endl;
}

friend Complex sum(Complex, Complex);

};

Complex sum(Complex c1, Complex c2) {
return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

// ================== MAIN ==================
int main() {

// Q1
cout << "Q1: Library\n";
Library lib;

string t="C++", a="Bjarne", i="101";
lib.addNewBook(t,a,i);

t="DSA"; a="CLRS"; i="102";
lib.addNewBook(t,a,i);

lib.displayDetails();

string rem="101";
lib.removeBooks(rem);

cout << "After removal:\n";
lib.displayDetails();

cout << "\n";


// Q2
cout << "Q2: this pointer\n";
Book2 b1("OOPS","Author","111");
Book2 b2 = b1;
b1.display();
b2.display();

cout << "\n";


// Q3
cout << "Q3: Account\n";
Account acc;
acc.setData(1001, 5000);

acc.depositAmount(1,2,1000);
acc.withdrawAmount(1,2,500);

acc.displayDetails();

cout << "\n";


// Q4
cout << "Q4: Friend Function\n";
A obj1;
B obj2;

obj1.set(5);
obj2.set(10);

cout << "Sum = " << add(obj1,obj2) << endl;

cout << "\n";


// Q5
cout << "Q5: Complex\n";
Complex c1(2,3), c2(4,5);

Complex result = sum(c1,c2);
result.display();

return 0;

}
