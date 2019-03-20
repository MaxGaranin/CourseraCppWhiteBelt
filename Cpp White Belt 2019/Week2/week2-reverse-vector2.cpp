#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> Reversed(const vector<int>& v) {
    vector<int> result;

    for (int i = 0; i < v.size(); ++i) {
        result.push_back(v[v.size() - 1 - i]);
    }

    return result;
}

void PrintIntVector(const vector<int>& v) {
    for(auto s : v) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    vector<int> numbers = {1, 5, 3, 4, 2};
    PrintIntVector(numbers);

    auto result = Reversed(numbers);
    PrintIntVector(result);

    return 0;
}