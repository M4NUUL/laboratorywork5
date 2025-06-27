#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <set>

#include "planes.h"

using namespace std;


static map<string, vector<string>> planeToTowns;
static map<string, vector<string>> townToPlanes;



void CreatePlane(const string &plane_name, const vector<string> &towns)
{
    // Проверка: название не должно совпадать с уже существующим
    if (planeToTowns.count(plane_name))
    {
        throw runtime_error("Самолет '" + plane_name + "' уже существует!");
    }
    // Проверка: маршрут должен содержать хотя бы два разных города
    if (towns.size() < 2)
    {
        throw runtime_error("Маршрут самолета должен содержать не менее двух городов!");
    }
    // Проверка: все города в маршруте должны быть разными
    set<string> unique_towns(towns.begin(), towns.end());
    if (unique_towns.size() != towns.size())
    {
        throw runtime_error("Маршрут не должен содержать одинаковые города!");
    }
    else
    {
        planeToTowns.emplace(plane_name, towns);
        for (const auto &town : towns)
        {
            townToPlanes[town].push_back(plane_name);
        }
    }
}

void planesForTown(const string &town)
{
    if (!townToPlanes.count(town))
    {
        cout << "Нет самолётов для города" << endl;
    }
    else
    {
        for (auto &pl : townToPlanes[town])
            cout << pl << " ";
        cout << endl;
    }
}

void townsForPlane(const string &name)
{
    if (!planeToTowns.count(name))
    {
        cout << "Нет такого самолёта" << endl;
    }
    else
    {
        for (auto &town : planeToTowns[name])
        {
            cout << town << ":";
            for (auto &pl : townToPlanes[town])
                if (pl != name)
                    cout << " " << pl;
            cout << endl;
        }
    }
}

void listPlanes()
{
    for (auto &pr : planeToTowns)
    {
        cout << pr.first << ":";
        for (auto &t : pr.second)
            cout << " " << t;
        cout << endl;
    }
}

void LoadPlanes()
{
    ifstream in("planes.txt");
    if (!in.is_open())
    {
        throw runtime_error("Не удалось открыть файл planes.txt");
    }

    string plane;
    int towns_count;

    while (in >> plane >> towns_count)
    {
        vector<string> towns;
        for (int i = 0; i < towns_count; i++)
        {
            string town;
            in >> town;
            towns.push_back(town);
        }
        CreatePlane(plane, towns);
    }
}
