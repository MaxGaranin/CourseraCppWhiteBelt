#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

///---------------------------------
/// Алгоритм Евклида для поиска НОД
///---------------------------------
int findNodByEvklidAtgorithm(int a, int b) {
    while(a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        } else if (a < b) {
            b = b % a;
        }
    }

    return a + b;
}

///-------------------------------------------------
/// Эта реализация поиска НОД должна быть медленной
///-------------------------------------------------
int findNod(int a, int b) {
    a = min(a, b);
    b = max(a, b);

    if (a == b)
        return a;

    if (a == 1 || b == 1)
        return 1;

    if (a % b == 0)
        return b;

    int c = b / 2;

    for (int i = c; i >= 1; i--) {
        if (a % i == 0 && b % i == 0)
            return i;
    }

    return 1;
}

int main() {
    int a, b;
    cin >> a >> b;

    int result = findNod(a, b);
    cout << result << endl;

    return 0;
}