#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void PrintVector(const vector<string>& v) {
    for (string s : v) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    cout << "Before sort:" << endl;
    PrintVector(v);

    sort(v.begin(), v.end(), [] (string s1, string s2) {
        int k = min(s1.size(), s2.size());
        for (int i = 0; i < k; ++i) {
            char c1 = tolower(s1[i]);
            char c2 = tolower(s2[i]);
            if (c1 == c2) continue;
            return c1 < c2;
        }
        return s1.size() < s2.size();
    });

    cout << "After sort:" << endl;
    PrintVector(v);

    return 0;
}