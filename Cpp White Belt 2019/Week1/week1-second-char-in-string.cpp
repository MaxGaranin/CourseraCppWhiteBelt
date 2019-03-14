#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {

    string s;
    cin >> s;

    int counter = 0;
    int index = -1;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'f') {
            counter++;
            if (counter == 2) {
                index = i;
                break;
            }
        }
    }

    int result = -2;
    if (index > 0) {
        result = index;
    }
    else if (counter == 1) {
        result = -1;
    }

    cout << result << endl;

    return 0;
}