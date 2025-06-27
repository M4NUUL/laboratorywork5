#pragma once

#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <set>

using namespace std;

enum class Cmd
{
    CREATE_PLANE,
    PLANES_FOR_TOWN,
    TOWNS_FOR_PLANE,
    PLANES
};

void CreatePlane(const string &plane_name, const vector<string> &towns);

void planesForTown(const string &town);

void townsForPlane(const string &name);

void listPlanes();

void LoadPlanes();
