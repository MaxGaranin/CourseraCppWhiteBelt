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

vector<string> PalindromFilter(const vector<string>& words, int minLength) {
    vector<string> result;

    for(auto w : words) {
        if (w.size() >= minLength && IsPalindrom(w)) {
            result.push_back(w);
        }
    }

    return result;
}

void PrintStringVector(const vector<string>& v) {
    for(auto s : v) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    vector<string> v = {"abacaba", "aba"};
    auto result = PalindromFilter(v, 5);
    PrintStringVector(result);

    v = {"abacaba", "aba"};
    result = PalindromFilter(v, 2);
    PrintStringVector(result);

    v = {"weew", "bro", "code"};
    result = PalindromFilter(v, 4);
    PrintStringVector(result);

    return 0;
}