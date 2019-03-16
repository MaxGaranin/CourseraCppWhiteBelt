#include <iostream>
#include <vector>
#include <map>

using namespace std;

int Factorial(int n) {
    if (n <= 1) return 1;

    return Factorial(n - 1) * n;
}

int FactorialIterative(int n) {
    if (n <= 1) return 1;

    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    int result = Factorial(n);
    cout << result << endl;

    int result2 = FactorialIterative(n);
    cout << result2 << endl;

    return 0;
}