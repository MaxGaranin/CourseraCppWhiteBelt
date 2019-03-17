#include <iostream>
#include <vector>
#include <map>

using namespace std;

void ReverseVector(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n / 2; ++i) {
        int temp = v[i];
        v[i] = v[n - 1 - i];
        v[n - 1 - i] = temp;
    }
}

void PrintIntVector(const vector<int>& v) {
    for(auto s : v) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    vector<int> numbers = {1, 5, 3, 4, 2};
    ReverseVector(numbers);
    PrintIntVector(numbers);

    return 0;
}