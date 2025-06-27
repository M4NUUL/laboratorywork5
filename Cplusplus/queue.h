#pragma once

#include <vector>
#include <string>
#include <algorithm>


using namespace std;

string genTicket(int id);

void doEnqueue(int duration);

void doDistribute(int windows);