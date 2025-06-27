#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

#include "warehouse.h"

using namespace std;

static const int maxPerCell = 10;                        // максимальное количество товаров в одной ячейке
static unordered_map<string, pair<string, int>> storage; // контейнер (адрес: название товара, количество)

bool isValidAddress(const string &address) // проверка корректности адреса
{
   return address.size() == 5 && (address[0] == 'A');
}

char getZone(const string& a) {
    return a[0];
}

void addProduct(const string &name, int cnt, const string &address)
{
   if (!isValidAddress(address))
   {
      cout << "Неправильный ввод адреса, введите корректный \nПример: 'А3401'\nА - зона хранения (доступна только А (латиница)), \
         \n3 - номер стелажа (1-5)\n 4 - номер вертикальной секции (1-5)\n01 - номер ячейки (01-15)"
           << endl;
      return;
   }
   if (cnt <= 0)
   {
      cout << "Количество товара должно быть положительным" << endl;
      return;
   }
   auto &cell = storage[address]; // создаёт запись, если нет
   int current = cell.second;
   // Запрет на смешивание товаров
   if (current > 0 && cell.first != name) {
      cout << "В ячейке уже находится другой товар: " << cell.first << endl;
      return;
   }
   if (current + cnt > maxPerCell)
   {
      cout << "Нельзя добавить. В ячейке не достаточно места" << endl;
      return;
   }
   cell = {name, current + cnt}; // обновляем имя и количество
   cout << "Добавлено " << cnt << " " << name << " в " << address << endl;
}

void removeProduct(const string& name, int cnt, const string& address) {
    auto it = storage.find(address);
    if (it == storage.end() || it->second.first != name) {
        cout << "В ячейке нет такого товара." << endl;
        return;
    }
    if (it->second.second < cnt) {
        cout << "Недостаточно товара для удаления." << endl;
        return;
    }
    if (cnt <= 0) {
        cout << "Количество товара для удаления должно быть положительным." << endl;
        return;
    }
    it->second.second -= cnt;
    cout << "Удалено " << cnt << " " << name << " из " << address << endl;
    if (it->second.second == 0) {
        storage.erase(it); // удаляем запись, если количество стало 0
    }
}

void info() {
    int totalCells = 1 * 5 * 5 * 15;    // общее число ячеек
    int used = 0;
    unordered_map<char,int> zoneUsed;
    for (auto& [addr, pr] : storage) {
        used += pr.second;
        zoneUsed[getZone(addr)] += pr.second;
    }
    cout << "Склад заполнен на: "
         << (used / (float)(totalCells * 10) * 100) << "%" << endl;
    for (char z : {'A', 'B'}) {
        cout << "В зоне " << z << ": "
             << (zoneUsed[z] / (float)(4 * 18 * 5 * 10) * 100) << "%" << endl;
    }
   cout << "Занятые ячейки:" << endl;
    for (auto& [addr, pr] : storage) {
        cout << addr << ": " << pr.first << " x" << pr.second << endl;
    }
}