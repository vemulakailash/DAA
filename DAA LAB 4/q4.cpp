#include <iostream>
using namespace std;

class Box {
    double l, b, h;
public:
    void input() { cin >> l >> b >> h; }
    friend void compare(Box b1, Box b2);
};

void compare(Box b1, Box b2) {
    double v1 = b1.l * b1.b * b1.h;
    double v2 = b2.l * b2.b * b2.h;
    
    if (v1 > v2) cout << "Box 1 is larger.\n";
    else if (v2 > v1) cout << "Box 2 is larger.\n";
    else cout << "Both boxes are equal.\n";
}

int main() {
    Box b1, b2;
    cout << "Enter L, B, H for Box 1: "; b1.input();
    cout << "Enter L, B, H for Box 2: "; b2.input();
    compare(b1, b2);
    return 0;
}