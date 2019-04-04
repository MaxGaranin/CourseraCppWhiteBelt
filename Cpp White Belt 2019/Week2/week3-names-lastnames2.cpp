#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct YearName {
    int year;
    string name;
};

class Person {
public:
    //// добавить факт изменения имени на first_name в год year
    //// по условию, года изменений не повторяются
    void ChangeFirstName(int year, const string &first_name) {
        _firstNames.push_back({year, first_name});
    }

    //// добавить факт изменения фамилии на last_name в год year
    //// по условию, года изменений не повторяются
    void ChangeLastName(int year, const string &last_name) {
        _lastNames.push_back({year, last_name});
    }

    //// получить все имена и фамилии по состоянию на конец года year
    string GetFullNameWithHistory(int year) {
        sort(_firstNames.begin(), _firstNames.end(), [](YearName yn1, YearName yn2) {
            return yn1.year < yn2.year;
        });
        sort(_lastNames.begin(), _lastNames.end(), [](YearName yn1, YearName yn2) {
            return yn1.year < yn2.year;
        });

        vector<YearName> foundFirstNames = FindNames(year, _firstNames);
        vector<YearName> foundLastNames = FindNames(year, _lastNames);

        reverse(foundFirstNames.begin(), foundFirstNames.end());
        reverse(foundLastNames.begin(), foundLastNames.end());

        bool isNameFound = !foundFirstNames.empty();
        bool isLastNameFound = !foundLastNames.empty();

        if (isNameFound) {
            if (isLastNameFound) {
                return NamesToString(foundFirstNames) + " " + NamesToString(foundLastNames);
            } else {
                return NamesToString(foundFirstNames) + " with unknown last name";
            }
        } else {
            if (isLastNameFound) {
                return NamesToString(foundLastNames) + " with unknown first name";
            } else {
                return "Incognito";
            }
        }
    }

private:
    vector<YearName> FindNames(int year, const vector<YearName> &names) {
        vector<YearName> foundNames;
        for (auto v : names) {
            if (year >= v.year) {
                if (foundNames.empty() ||
                    (!foundNames.empty() && foundNames[foundNames.size() - 1].name != v.name)) {
                    foundNames.push_back(v);
                }
            } else {
                break;
            }
        }
        return foundNames;
    }

    string NamesToString(const vector<YearName> &names) {
        if (names.empty())
            return "";

        string result = names[0].name;
        if (names.size() == 1)
            return result;

        result += " (";
        for (int i = 1; i < names.size(); ++i) {
            result += names[i].name + ", ";
        }
        result = result.substr(0, result.size() - 2);
        result += ")";

        return result;
    }

    vector<YearName> _firstNames;
    vector<YearName> _lastNames;
};

//// Первая проверка
//int main() {
//    Person person;
//
//    person.ChangeFirstName(1900, "Eugene");
//    person.ChangeLastName(1900, "Sokolov");
//    person.ChangeLastName(1910, "Sokolov");
//    person.ChangeFirstName(1920, "Evgeny");
//    person.ChangeLastName(1930, "Sokolov");
//    cout << person.GetFullNameWithHistory(1940) << endl;
//
//    return 0;
//}

//// Вторая проверка
int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;

    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;

    return 0;
}