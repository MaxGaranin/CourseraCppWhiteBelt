#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Incognizable {
public:
    Incognizable(int a = 0, int b = 0) {
    }

private:
};

int main() {
    Incognizable a;
    Incognizable b = {};
    Incognizable c = {0};
    Incognizable d = {0, 1};
    return 0;
}