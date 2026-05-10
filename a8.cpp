#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// ================== Q1 ==================
// Write numbers 1 to 200 in file NUM.TXT

void writeNumbers() {
ofstream fout("NUM.txt");
for(int i = 1; i <= 200; i++) {
fout << i << " ";
}
fout.close();
cout << "Numbers written to NUM.txt\n";
}

// ================== Q2 ==================
// Count alphabets in file NOTES.TXT

void countAlphabets() {
ifstream fin("NOTES.txt");
char ch;
int count = 0;

while(fin.get(ch)) {
    if(isalpha(ch))
        count++;
}

cout << "Total alphabets = " << count << endl;
fin.close();

}

// ================== Q3 ==================
// Binary I/O (write object to file)

class Student {
public:
int id;
char name[20];

void input() {
    cout << "Enter ID and Name: ";
    cin >> id >> name;
}

void display() {
    cout << id << " " << name << endl;
}

};

void binaryIO() {
Student s;

ofstream fout("student.dat", ios::binary);
s.input();
fout.write((char*)&s, sizeof(s));
fout.close();

ifstream fin("student.dat", ios::binary);
fin.read((char*)&s, sizeof(s));
cout << "Data from file: ";
s.display();
fin.close();

}

// ================== Q4 ==================
// Copy contents of one file to another

void copyFile() {
ifstream fin("NUM.txt");
ofstream fout("COPY.txt");

char ch;
while(fin.get(ch)) {
    fout.put(ch);
}

cout << "File copied successfully\n";
fin.close();
fout.close();

}

// ================== Q5 ==================
// Character I/O (string operations)

void stringIO() {
char str[100];

cout << "Enter string: ";
cin.ignore();
cin.getline(str, 100);

int len = strlen(str);
cout << "Length = " << len << endl;

ofstream fout("STRING.txt");
fout << str;
fout.close();

ifstream fin("STRING.txt");
char ch;
cout << "From file: ";
while(fin.get(ch))
    cout << ch;

cout << endl;
fin.close();

}

// ================== Q6 ==================
// File pointers (seekg, seekp, tellg, tellp)

void filePointers() {
fstream file("NUM.txt", ios::in | ios::out);

file.seekg(0, ios::end);
cout << "File size (tellg) = " << file.tellg() << endl;

file.seekp(0, ios::beg);
file << "START ";

file.seekg(0, ios::beg);
cout << "First char: " << (char)file.get() << endl;

file.close();

}

// ================== MAIN ==================
int main() {

// Q1
writeNumbers();
cout << "\n";

// Q2
countAlphabets();
cout << "\n";

// Q3
binaryIO();
cout << "\n";

// Q4
copyFile();
cout << "\n";

// Q5
stringIO();
cout << "\n";

// Q6
filePointers();

return 0;

}
