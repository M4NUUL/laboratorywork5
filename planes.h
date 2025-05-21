#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

enum class Cmd { CREATE_PLANE, PLANES_FOR_TOWN, TOWNS_FOR_PLANE, PLANES};
static map<string, vector<string>> planeToTowns;
static map<string, vector<string>> townToPlanes;

void createPlane(const vector<string>& args) {
    string name = args[0];
    for (size_t i=1; i<args.size(); ++i) {
        planeToTowns[name].push_back(args[i]);
        townToPlanes[args[i]].push_back(name);
    }
}

void planesForTown(const string& town) {
    if (!townToPlanes.count(town)) {
      cout << "Нет самолётов для города" << endl;
    } else {
        for (auto &pl : townToPlanes[town]) cout << pl << " ";
        cout << endl;
    }
}

void townsForPlane(const string& name) {
    if (!planeToTowns.count(name)) {
      cout << "Нет такого самолёта" << endl;
    } else {
        for (auto &town : planeToTowns[name]) {
            cout << town << ":";
            for (auto &pl : townToPlanes[town]) if (pl!=name) cout << " "<<pl;
            cout << endl;
        }
    }
}

void listPlanes() {
    for (auto &pr : planeToTowns) {
        cout << pr.first << ":";
        for (auto &t: pr.second) cout << " "<<t;
        cout << endl;
    }
}