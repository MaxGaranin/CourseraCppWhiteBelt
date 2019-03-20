#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, string> countries_map;

    for (int i = 0; i < n; ++i) {
        string op;
        cin >> op;

        if (op == "CHANGE_CAPITAL") {
            string country, new_capital, old_capital;
            cin >> country >> new_capital;

            if (countries_map.count(country) == 0) {
                cout << "Introduce new country " << country << " with capital " << new_capital << endl;
                countries_map[country] = new_capital;
            }
            else {
                old_capital = countries_map[country];

                if (old_capital == new_capital) {
                    cout << "Country " << country << " hasn't changed its capital" << endl;
                } else {
                    cout << "Country " << country << " has changed its capital from " << old_capital << " to "
                         << new_capital << endl;
                    countries_map[country] = new_capital;
                }
            }
        } else if (op == "RENAME") {
            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;

            if (old_country_name == new_country_name ||
                countries_map.count(old_country_name) == 0 ||
                countries_map.count(new_country_name) > 0) {
                cout << "Incorrect rename, skip" << endl;
            } else {
                string old_capital = countries_map[old_country_name];
                countries_map[new_country_name] = old_capital;
                countries_map.erase(old_country_name);
                cout << "Country " << old_country_name << " with capital " << old_capital << " has been renamed to " << new_country_name << endl;
            }
        } else if (op == "ABOUT") {
            string country;
            cin >> country;

            if (countries_map.count(country) == 0) {
                cout << "Country " << country << " doesn't exist" << endl;
            }
            else {
                cout << "Country " << country << " has capital " << countries_map[country] << endl;
            }
        } else if (op == "DUMP") {
            if (countries_map.size() == 0) {
                cout << "There are no countries in the world" << endl;
            }
            else {
                for (auto item : countries_map) {
                    cout << item.first << "/" << item.second << " ";
                }
                cout << endl;
            }
        } else {
            cout << "Undefinded operation: " << op;
            return 0;
        }
    }

    return 0;
}