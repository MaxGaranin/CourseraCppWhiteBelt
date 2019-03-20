#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += v[i];
    }

    int mean = sum / n;

    vector<int> above_mean;
        for (int i = 0; i < n; ++i) {
        if (v[i] > mean) {
            above_mean.push_back(i);
        }
    }

    int k = above_mean.size();
    cout << k << endl;
    for (int j = 0; j < k; ++j) {
        cout << above_mean[j] << " ";
    }

    return 0;
}