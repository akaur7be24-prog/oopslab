#include <iostream>
using namespace std;

int main() {
// ================== Q1 ==================
// Display "Hello World"
cout << "Q1: Hello World Program\n";
cout << "Hello World\n\n";


// ================== Q2 ==================
// Input integer, decimal and character and display them
cout << "Q2: Input and Display Values\n";
int i;
float f;
char ch;

cout << "Enter an integer: ";
cin >> i;

cout << "Enter a decimal number: ";
cin >> f;

cout << "Enter a character: ";
cin >> ch;

cout << "You entered -> Integer: " << i << ", Float: " << f << ", Character: " << ch << "\n\n";


// ================== Q3 ==================
// Add, subtract, multiply, divide
cout << "Q3: Arithmetic Operations\n";
int a, b;

cout << "Enter two numbers: ";
cin >> a >> b;

cout << "Addition = " << a + b << endl;
cout << "Subtraction = " << a - b << endl;
cout << "Multiplication = " << a * b << endl;

if(b != 0)
    cout << "Division = " << (float)a / b << endl;
else
    cout << "Division not possible (divide by 0)\n";

cout << "\n";


// ================== Q4 ==================
// Celsius to Fahrenheit
cout << "Q4: Temperature Conversion\n";
float celsius;

cout << "Enter temperature in Celsius: ";
cin >> celsius;

float fahrenheit = (9 * celsius / 5) + 32;
cout << "Temperature in Fahrenheit = " << fahrenheit << "\n\n";


// ================== Q5 ==================
// Formatting output
cout << "Q5: Formatting Output\n";
cout << "Line1\nLine2\n";   // \n new line
cout << "Hello\tWorld\n";   // \t tab space
cout << "Back\bspace example\n"; // \b backspace
cout << "Using endl" << endl << endl;


// ================== Q6 ==================
// Assignment operators
cout << "Q6: Assignment Operators\n";
int x = 10;

x += 5;
cout << "After += 5: " << x << endl;

x -= 3;
cout << "After -= 3: " << x << "\n\n";


// ================== Q7 ==================
// Swap using bitwise XOR
cout << "Q7: Swap using Bitwise Operator\n";
int num1, num2;

cout << "Enter two numbers: ";
cin >> num1 >> num2;

num1 = num1 ^ num2;
num2 = num1 ^ num2;
num1 = num1 ^ num2;

cout << "After swapping -> num1: " << num1 << ", num2: " << num2 << "\n\n";


// ================== Q8 ==================
// Library fine problem
cout << "Q8: Library Fine\n";
int days;

cout << "Enter number of late days: ";
cin >> days;

if(days <= 5)
    cout << "Fine = " << days * 0.50 << " rupees\n";
else if(days <= 10)
    cout << "Fine = " << (5 * 0.50 + (days - 5) * 1) << " rupees\n";
else if(days <= 30)
    cout << "Fine = " << (5 * 0.50 + 5 * 1 + (days - 10) * 5) << " rupees\n";
else
    cout << "Membership Cancelled\n";

cout << "\n";


// ================== Q9 ==================
// Arithmetic using switch case
cout << "Q9: Switch Case Calculator\n";
int n1, n2;
char op;

cout << "Enter two numbers: ";
cin >> n1 >> n2;

cout << "Enter operator (+, -, *, /): ";
cin >> op;

switch(op) {
    case '+': cout << "Result = " << n1 + n2; break;
    case '-': cout << "Result = " << n1 - n2; break;
    case '*': cout << "Result = " << n1 * n2; break;
    case '/': 
        if(n2 != 0)
            cout << "Result = " << (float)n1 / n2;
        else
            cout << "Division by zero not allowed";
        break;
    default: cout << "Invalid operator";
}

cout << "\n\n";


// ================== Q10 ==================
// Even or Odd
cout << "Q10: Even or Odd\n";
int number;

cout << "Enter a number: ";
cin >> number;

if(number % 2 == 0)
    cout << "Even Number\n";
else
    cout << "Odd Number\n";


return 0;

}
