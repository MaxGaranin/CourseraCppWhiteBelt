#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class SortedStrings {
public:
    void AddString(const string &s) {
        _v.push_back(s);
    }

    vector<string> GetSortedStrings() {
        sort(_v.begin(), _v.end());
        return _v;
    }

private:
    vector<string> _v;
};


void PrintSortedStrings(SortedStrings &strings) {
    for (const string &s : strings.GetSortedStrings()) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    SortedStrings strings;

    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);

    strings.AddString("second");
    PrintSortedStrings(strings);

    return 0;
}