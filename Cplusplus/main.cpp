#include <iostream>
#include <iomanip>
#include <limits>
#include "warehouse.h"
#include "queue.h"
#include "planes.h"
#include "class.h"
using namespace std;

int main()
{
   int choice = 0;
   cout << "Выберите номер задачи (1-4): ";
   cin >> choice;

   switch (choice)
   {
   case 1:
   {
      string cmd;
      cout << "Доступные команды для работы с хранилищем: ADD 'название товара' 'количество' 'адресс' | REMOVE 'название товара' 'количество' 'адресс' | INFO | EXIT\n";
      while (true)
      {
         cout << ">>>> ";
         cin >> cmd;
         if (cmd == "ADD")
         {
            string name, address;
            int cnt;
            if (!(cin >> name >> cnt >> address))
            {
               cout << "Ошибка: команда ADD требует три аргумента: название количество адрес\n";
               cin.clear();
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
               continue;
            }
            addProduct(name, cnt, address);
         }
         else if (cmd == "REMOVE")
         {
            string name, address;
            int cnt;
            cin >> name >> cnt >> address;
            removeProduct(name, cnt, address);
         }
         else if (cmd == "INFO")
         {
            info();
         }
         else if (cmd == "EXIT")
         {
            break;
         }
         else
         {
            cout << "Неверная команда. Попробуйте снова." << endl;
         }
      }
      break;
   }
   case 2:
   {
      int windows;
      cout << "Введите количество окон:" << endl;
      cin >> windows;
      string cmd;
      while (cin >> cmd)
      {
         if (cmd == "ENQUEUE")
         {
            int dur;
            cin >> dur;
            doEnqueue(dur);
         }
         else if (cmd == "DISTRIBUTE")
         {
            doDistribute(windows);
         }
         else if (cmd == "EXIT")
            break;
      }
      break;
   }
   case 3:
   {
      try {
         LoadPlanes(); // загружаем самолёты из файла
      } catch (const std::exception& ex) {
         cout << "[ОШИБКА] " << ex.what() << endl;
      }
      string line;
      while (getline(cin, line))
      {
         if (line.empty())
            continue;
         istringstream ss(line);
         string cmd;
         ss >> cmd;
         vector<string> parts;
         string tmp;
         while (ss >> tmp)
            parts.push_back(tmp);
         try {
            if (cmd == "CREATE_PLANE")
            {
               string plane_name = parts[0];
               vector<string> towns(parts.begin() + 1, parts.end());
               CreatePlane(plane_name, towns);
            }
            else if (cmd == "PLANES_FOR_TOWN")
               planesForTown(parts[0]);
            else if (cmd == "TOWNS_FOR_PLANE")
               townsForPlane(parts[0]);
            else if (cmd == "PLANES")
               listPlanes();
            else if (cmd == "EXIT")
               break;
         } catch (const std::exception& ex) {
            cout << "[ОШИБКА] " << ex.what() << endl;
         }
      }
      break;
   }
   case 4:
   {
      int N;
      cin >> N;
      while (N--)
      {
         string cmd;
         cin >> cmd;
         if (cmd == "CLASS")
         {
            int d;
            string s;
            cin >> d >> s;
            doClass(d, s);
         }
         else if (cmd == "NEXT")
            doNext();
         else if (cmd == "VIEW")
         {
            int d;
            cin >> d;
            doView(d);
         }
      }
      break;
   }
   default:
      cout << "Неверный номер задачи." << endl;
      break;
   }
   return 0;
}