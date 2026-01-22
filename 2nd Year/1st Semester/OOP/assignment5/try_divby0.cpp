#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    try {
        if (b==0) throw "Division by 0!\n";
        double c = double(a)/b;
        cout << a << " / " << b << " = " << c << endl;
    }
    catch (const char *ex) {
        cout << ex;
    }
}
