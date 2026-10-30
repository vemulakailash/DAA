#include <iostream>
using namespace std;
class Product {
private:
    int productId;
    double price;

public:
    void readProduct() {
        cout << "Enter Product ID: ";
        cin >> productId;
        cout << "Enter Product Price: ";
        cin >> price;
    }

    void displayProduct() const {
        cout << "\n--- Product Information ---" << endl;
        cout << "Product ID: " << productId << endl;
        cout << "Price: $" << price << endl;
    }
};

int main() {
    Product prod;
    prod.readProduct();
    prod.displayProduct();
    return 0;
}