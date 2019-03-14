#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if (b == 0) {
        cout << "Impossible" << endl;
        return 0;
    }

    int c = a / b;

    cout << c << endl;
    return 0;
}