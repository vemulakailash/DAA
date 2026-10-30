#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    int bookId;
    string title;
    float price;

public:
    void accept() {
        cout << "Enter Book ID, Title, and Price: ";
        cin >> bookId >> title >> price;
    }

    void display() {
        cout << "ID: " << bookId << " | Title: " << title << " | Price: " << price << endl;
    }

    friend void findHigherPrice(Book b1, Book b2);
};

void findHigherPrice(Book b1, Book b2) {
    cout << "\nBook with the higher price:\n";
    if (b1.price > b2.price) b1.display();
    else b2.display();
}

int main() {
    Book b1, b2;
    b1.accept();
    b2.accept();
    findHigherPrice(b1, b2);
    return 0;
}