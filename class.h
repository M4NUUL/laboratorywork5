#include <iostream>
#include <vector>
#include <string>
using namespace std;

static vector<vector<string>> sched(32); // 1–31
static int monthDays = 31;

void doClass(int day, const string& cls) {
    sched[day].push_back(cls);
}

void doNext() {
    int prevDays = monthDays;
    monthDays = (monthDays==31?30: (monthDays==30?31:28));
    vector<vector<string>> newSched(32);
    int minDay = min(prevDays, monthDays);
    for (int d=1; d<=minDay; ++d) newSched[d] = sched[d];
    // перепад: дни > new monthDays -> перенос на последний
    for (int d = monthDays+1; d<=prevDays; ++d)
        newSched[monthDays].insert(
            newSched[monthDays].end(),
            sched[d].begin(), sched[d].end());
    sched.swap(newSched);
}
void doView(int day) {
    auto &v = sched[day];
    if (v.empty()) {
        cout << "On day " << day << " we are free!" << endl;
    } else {
        cout << "On day " << day << " there are " << v.size() << " classes at the university: ";
        for (auto &s : v) cout << s << ", ";
        cout << endl;
    }
}
