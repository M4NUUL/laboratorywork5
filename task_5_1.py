MAX_PER_CELL = 10      # макс. товара в ячейке
storage = {}           # словарь адрес -> (название, количество)

def add_product(name, qty, addr):
   # проверка корректности адреса (только 'A')
   if len(addr) != 5 or addr[0] != 'A':
      print('Некорректный адрес.')
      return
   # получить текущее состояние ячейки
   cur_name, cur_qty = storage.get(addr, (name,0))
   if cur_name != name and cur_qty > 0:
      print('Ячейка занята другим товаром.')
      return
   if cur_qty + qty > MAX_PER_CELL:
      print('Нельзя добавить: переполнение ячейки.')
      return
   storage[addr] = (name, cur_qty + qty)
   print(f'Добавлено {qty} {name} в {addr}')

def remove_product(name, qty, addr):
   # проверка существования товара
   if addr not in storage or storage[addr][0] != name:
      print('В ячейке нет такого товара.')
      return
   if storage[addr][1] < qty:
      print('Недостаточно товара для удаления.')
      return
   new_qty = storage[addr][1] - qty
   if new_qty > 0:
      storage[addr] = (name, new_qty)
   else:
      del storage[addr]           # удаляем запись при qty=0
   print(f'Удалено {qty} {name} из {addr}')

def info():
   total = 1*5*5*15*10  # только зона A
   used = sum(q for a, (_, q) in storage.items() if a[0] == 'A')
   print(f'Склад заполнен на: {used/total*100:.2f}%')
   zone_used = sum(q for a,(_,q) in storage.items() if a[0]=='A')
   print(f'В зоне A: {zone_used/(5*5*15*10)*100:.2f}%')
   print('Занятые ячейки:')
   for addr, (n, q) in storage.items():
      if addr[0] == 'A':
         print(f'{addr}: {n} x{q}')