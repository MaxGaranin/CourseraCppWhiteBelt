#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool IsPalindrom(const string& s) {
    int n = s.size();
    if (n <= 1) return true;

    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - 1 - i]) {
            return false;
        }
    }

    return true;
}

int main() {
    string s;
    cin >> s;

    bool result = IsPalindrom(s);
    cout << result << endl;

    return 0;
}