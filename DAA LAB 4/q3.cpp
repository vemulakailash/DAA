#include <iostream>
using namespace std;

class Student {
    int roll;
    double marks;
public:
    void accept() { cin >> roll >> marks; }
    void display() { cout << "Roll: " << roll << ", Marks: " << marks << endl; }
    friend void compare(Student s1, Student s2);
};

void compare(Student s1, Student s2) {
    if (s1.marks > s2.marks) cout << "Roll " << s1.roll << " has higher marks.\n";
    else if (s2.marks > s1.marks) cout << "Roll " << s2.roll << " has higher marks.\n";
    else cout << "Both have equal marks.\n";
}

int main() {
    Student s1, s2;
    cout << "Enter Roll and Marks for Student 1: "; s1.accept();
    cout << "Enter Roll and Marks for Student 2: "; s2.accept();
    s1.display(); s2.display();
    compare(s1, s2);
    return 0;
}