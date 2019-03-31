#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    vector<int> month_days_counts = {
           31,  // январь
           28,  // февраль
           31,  // март
           30,  // апрель
           31,  // май
           30,  // июнь
           31,  // июль
           31,  // август
           30,  // сентябрь
           31,  // октябрь
           30,  // ноябрь
           31,  // декабрь
    };

    int n;
    cin >> n;

    // начинаем с января, нумерация дней с единицы
    int month = 0;
    vector<vector<string>> current_tasks(month_days_counts[month] + 1);

    for (int i = 0; i < n; ++i) {
        string op;
        cin >> op;

        int k;
        string task;
        if (op == "ADD") {
            cin >> k >> task;
            current_tasks[k].push_back(task);

        } else if (op == "NEXT") {
            int prev_month = month;
            month++;
            if (month > 11) month = 0;

            vector<string> last_tasks;
            if (month_days_counts[month] < month_days_counts[prev_month]) {
                for (int j = month_days_counts[month] + 1; j <=  month_days_counts[prev_month]; ++j) {
                    last_tasks.insert(end(last_tasks), begin(current_tasks[j]), end(current_tasks[j]));
                }
            }

            current_tasks.resize(month_days_counts[month] + 1);
            vector<string>& v = current_tasks[month_days_counts[month]];
            v.insert(end(v), begin(last_tasks), end(last_tasks));

        } else if (op == "DUMP") {
            int day;
            cin >> day;

            int count = current_tasks[day].size();
            cout << count << " ";
            for (int m = 0; m < count; ++m) {
                cout << current_tasks[day][m] << " ";
            }
            cout << endl;
        } else {
            cout << "Undefinded operation: " << op;
            return 0;
        }
    }

    return 0;
}