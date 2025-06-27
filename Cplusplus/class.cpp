#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Для std::find

#include "class.h"

using namespace std;

static vector<vector<string>> sched(32); // 1–31
static int monthDays = 31;
static int currentMonth = 0; // 0 - январь
static const int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

void doClass(int day, const string& cls) {
    auto& v = sched[day];
    if (find(v.begin(), v.end(), cls) != v.end()) {
        // Просто игнорируем попытку добавить дубликат
        return;
    }
    v.push_back(cls);
}

void doNext() {
    int prevDays = monthDays;
    currentMonth = (currentMonth + 1) % 12;
    monthDays = daysInMonth[currentMonth];
    vector<vector<string>> newSched(32);
    int minDay = min(prevDays, monthDays);
    for (int d=1; d<=minDay; ++d) newSched[d] = sched[d];
    int targetDay = monthDays - 1;
    for (int d = monthDays+1; d<=prevDays; ++d) {
        for (const auto& cls : sched[d]) {
            auto& v = newSched[targetDay];
            if (find(v.begin(), v.end(), cls) == v.end())
                v.push_back(cls);
        }
    }
    sched.swap(newSched);
}

void doView(int day) {
    auto &v = sched[day];
    if (v.empty()) {
        cout << "On day " << day << " we are free!" << endl;
    } else {
        cout << "On day " << day << " there are " << v.size() << " classes at the university: ";
        for (size_t i = 0; i < v.size(); ++i) {
            cout << v[i];
            if (i + 1 < v.size()) cout << ", ";
        }
        cout << endl;
    }
}
