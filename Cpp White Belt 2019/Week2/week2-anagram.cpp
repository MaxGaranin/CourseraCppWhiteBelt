#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<char, int> BuildCharCounters(const string &s) {
    map<char, int> counters;
    for (char ch : s) {
        ++counters[ch];
    }

    return counters;
}

bool IsAnagrams(const string &s1, const string &s2) {
    map<char, int> counters1 = BuildCharCounters(s1);
    map<char, int> counters2 = BuildCharCounters(s2);

    bool result = (counters1 == counters2);
    return result;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string s1, s2;
        cin >> s1 >> s2;

        bool result;
        if (s1.size() != s2.size()) {
            result = false;
        } else {
            result = IsAnagrams(s1, s2);
        }

        cout << (result ? "YES" : "NO") << endl;
    }

    return 0;
}