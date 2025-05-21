from task_5_1 import *
from task_5_2 import *
from task_5_3 import *
from task_5_4 import *

while True:
   print("Выберите номер задания (1-4) или 0 для выхода:")
   try:
       choice = int(input())
   except ValueError:
       print("Ошибка ввода!")
       continue  
   if choice == 1:
      while True:
            parts = input().split()
            if not parts or parts[0] == 'EXIT':
                break
            cmd = parts[0]
            if cmd == 'ADD':
                add_product(parts[1], int(parts[2]), parts[3])
            elif cmd == 'REMOVE':
                remove_product(parts[1], int(parts[2]), parts[3])
            elif cmd == 'INFO':
                info()
   elif choice == 2:
      w = int(input('Введите количество окон: '))
      while True:
         parts = input().split()
         if not parts or parts[0] == 'EXIT':
            break
            cmd = parts[0]
         if cmd == 'ENQUEUE':
            enqueue(int(parts[1]))
         elif cmd == 'DISTRIBUTE':
            distribute(w)
   elif choice == 3:
      while True:
         parts = input().split()
         if not parts or parts[0] == 'EXIT':
               break
         cmd, args = parts[0], parts[1:]
         if cmd == 'CREATE_PLANE':
               create_plane(args)
         elif cmd == 'PLANES_FOR_TOWN':
               planes_for_town(args[0])
         elif cmd == 'TOWNS_FOR_PLANE':
               towns_for_plane(args[0])
         elif cmd == 'PLANES':
               list_planes()
   elif choice == 4:
      n = int(input())
      for _ in range(n):
         parts = input().split()
         cmd = parts[0]
         if cmd == 'CLASS': do_class(int(parts[1]), parts[2])
         elif cmd == 'NEXT': do_next()
         elif cmd == 'VIEW': do_view(int(parts[1]))