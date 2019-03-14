#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    double n, a, b, x, y;
    cin >> n >> a >> b >> x >> y;

    double discount = 0;
    if (n > b) {
        discount = y;
    }
    else if (n > a) {
        discount = x;
    }

    double cost = n - discount * n /100;
    cout << cost << endl;

    return 0;
}