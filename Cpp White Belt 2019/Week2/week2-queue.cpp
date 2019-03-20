#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    const int QUIET = 0;
    const int WORRY = 1;

    vector<int> q;
    for (int i = 0; i < n; ++i) {
        string op;
        cin >> op;

        int k;
        if (op == "WORRY") {
            cin >> k;
            q[k] = WORRY;
        } else if (op == "QUIET") {
            cin >> k;
            q[k] = QUIET;
        } else if (op == "COME") {
            cin >> k;
            q.resize(q.size() + k);
        } else if (op == "WORRY_COUNT") {
            int worry_count = 0;
            for (int j = 0; j < q.size(); ++j) {
                if (q[j] == WORRY) worry_count++;
            }
            cout << worry_count;
        } else {
            cout << "Undefinded operation: " << op;
            return 0;
        }
    }

    return 0;
}