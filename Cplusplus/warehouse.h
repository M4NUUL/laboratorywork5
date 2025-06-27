#pragma once

bool isValidAddress(const string &address); // проверка корректности адреса


char getZone(const string& a);

void addProduct(const string &name, int cnt, const string &address);

void removeProduct(const string& name, int cnt, const string& address);

void info();