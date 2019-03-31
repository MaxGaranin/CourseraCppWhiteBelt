#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        _yearToNames[year] = first_name;
    }

    void ChangeLastName(int year, const string& last_name) {
        _yearToLastNames[year] = last_name;
    }

    string GetFullName(int year) {
        bool isNameFound = false;
        string foundName = "";
        for (auto kv : _yearToNames) {
            if (year >= kv.first) {
                isNameFound = true;
                foundName = kv.second;
            }
            else {
                if (isNameFound) break;
            }
        }

        bool isLastNameFound = false;
        string foundLastName = "";
        for (auto kv : _yearToLastNames) {
            if (year >= kv.first) {
                isLastNameFound = true;
                foundLastName = kv.second;
            }
            else {
                if (isLastNameFound) break;
            }
        }

        if (isNameFound) {
            if (isLastNameFound) {
                return  foundName + " " + foundLastName;
            }
            else {
                return foundName + " with unknown last name";
            }
        }
        else {
            if (isLastNameFound) {
                return foundLastName + " with unknown first name";
            }
            else {
                return "Incognito";
            }
        }
    }

private:
    map<int, string> _yearToNames;
    map<int, string> _yearToLastNames;
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}