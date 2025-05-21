#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Генерация номера талона (фиксированная длина: буква+номер)
string genTicket(int id) {
    char buf[5];
    sprintf(buf, "T%03d", id % 1000);
    return string(buf);
}


static vector<pair<string,int>> queueList;
static int nextId = 1;

void doEnqueue(int duration) {
    string ticket = genTicket(nextId++);
    queueList.push_back({ticket, duration});
    cout << ticket << endl;
}

void doDistribute(int windows) {
    // загрузка каждого окна
    vector<int> load(windows, 0);
    vector<vector<string>> assign(windows);
    for (auto &p : queueList) {
        int idx = min_element(load.begin(), load.end()) - load.begin();
        load[idx] += p.second;
        assign[idx].push_back(p.first);
    }
    // вывод распределения
    for (int i = 0; i < windows; i++) {
        cout << "Окно " << i+1 << " (" << load[i] << " мин):";
        for (auto &t : assign[i]) cout << " " << t;
        cout << endl;
    }
}

