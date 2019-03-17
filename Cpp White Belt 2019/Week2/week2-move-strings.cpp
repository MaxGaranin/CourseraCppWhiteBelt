#include <iostream>
#include <vector>
#include <map>

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination) {
    for(auto s : source) {
        destination.push_back(s);
    }

    source.clear();
}

void PrintStringVector(const vector<string>& v) {
    for(auto s : v) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    vector<string> source = {"a", "b", "c"};
    vector<string> destination = {"z"};
    MoveStrings(source, destination);

    PrintStringVector(source);
    PrintStringVector(destination);

    return 0;
}