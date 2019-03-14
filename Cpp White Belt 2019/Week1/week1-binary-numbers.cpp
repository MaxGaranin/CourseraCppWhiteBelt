#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    vector<int> numbers;

    int n;
    cin >> n;

    int d;
    int k = 0;

    while(true) {
        d = static_cast<int>(pow(2, k));
        if (d >= n) {
            if (d > n) k--;
            break;
        }
        k++;
    }

    while(true) {
        d = static_cast<int>(pow(2, k));
        if (d < n) {
            n = n % d;
            numbers.push_back(k);
        }

        if (n == 0)
            break;

        if (n == 1) {
            numbers.push_back(0);
            break;
        }

        k--;
    }

    if (numbers.size() == 0)
        return 0;

    string s = string(numbers[0] + 1, '0');
    for(int num : numbers) {
        s[num] = '1';
    }

    reverse(s.begin(), s.end());
    cout << s << endl;

    return 0;
}