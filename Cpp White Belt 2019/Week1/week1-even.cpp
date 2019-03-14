#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    vector<int> even_numbers;

    for (int i = a; i <= b; ++i) {
        if (i % 2 == 0) {
            even_numbers.push_back(i);
        }
    }

    for (auto n : even_numbers) {
        cout << n << " ";
    }

    cout << endl;

    return 0;
}