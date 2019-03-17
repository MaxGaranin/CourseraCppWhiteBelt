#include <iostream>
#include <vector>
#include <map>

using namespace std;

void UpdateIfGreater(int first, int& second) {
    if (first > second) {
        second = first;
    }
}

int main() {
    int a = 4;
    int b = 2;
    cout << "Before: " << b << endl;
    UpdateIfGreater(a, b);
    cout << "After: " << b << endl;

    return 0;
}