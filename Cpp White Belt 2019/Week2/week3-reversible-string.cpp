#include <iostream>
#include <vector>
#include <map>

using namespace std;

class ReversibleString {
public:
    ReversibleString(string s = "") {
        _str = s;
    }

    void Reverse() {
        int n = _str.size();
        for (int i = 0; i <= (n - 1) / 2; ++i) {
            char temp = _str[i];
            _str[i] = _str[n - 1 - i];
            _str[n - 1 - i] = temp;
        }
    }

    string ToString() const {
        string s = _str;
        return s;
    }

private:
    string _str;
};

int main() {
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
}