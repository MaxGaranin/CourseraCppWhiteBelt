#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Person {
    string Name;
    string SurName;
    int Age;
};

class Animal {
public:
    string Name;
    string Breead;
    int Age;
};

int main() {
    int x = 5;
    double pi = 3.1415;
    char symbol = 'Z';

    string s = "aaa";
    vector<int> nums = {1, 5, 6, 8};

    map<string, int> nameToValue;
    nameToValue["one"] = 1;
    nameToValue["two"] = 2;

    vector<Person> staff;
    staff.push_back({"Ivan", "Ivanov", 25});
    staff.push_back({"Petr", "Petrov", 44});

    cout << s << endl;
    cout << nums.size() << endl;
    cout << nameToValue["one"] << endl;
    cout << staff[1].Age << endl;
    cout << "Hello, World!" << endl;

    Animal cow;
    cow.Name = "Milka";
    cow.Breead = "cow";
    cow.Age = 2;

    Animal dog = cow;
    dog.Name = "Rex";
    dog.Breead = "Dog";

    cout << cow.Breead << ":" << cow.Name << endl;
    cout << dog.Breead << ":" << dog.Name << endl;

    return 0;
}