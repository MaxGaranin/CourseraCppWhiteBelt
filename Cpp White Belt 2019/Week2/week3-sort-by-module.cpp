#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void PrintVector(const vector<int>& v) {
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    cout << "Before sort:" << endl;
    PrintVector(v);

    sort(v.begin(), v.end(), [] (int i, int j) {
        return abs(i) < abs(j);
    });

    cout << "After sort:" << endl;
    PrintVector(v);

    return 0;
}