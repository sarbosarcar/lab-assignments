#include <iostream>
using namespace std;

int main() {
    int a[] = {0, 1, 2, -3, -5};
    for (int i=0; i<5; i++) {
        try {
            if (a[i]<0) throw a[i];
            else throw "Exception!\n";
        }
        catch (int i) {
            cout << "Received int " << i << endl;
        }
        catch (const char *ex) {
            cout << ex;
        }
        catch (...) {
            cout << "Default!\n";
        }
    }
}
