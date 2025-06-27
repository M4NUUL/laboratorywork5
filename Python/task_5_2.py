queue_list = []
next_id = 1

def gen_ticket(id):
    return f"T{id:03d}"

def enqueue(duration):
    global next_id
    ticket = gen_ticket(next_id)
    next_id += 1
    queue_list.append((ticket, duration))
    print(ticket)

def distribute(windows):
    loads = [0]*windows
    assign = [[] for _ in range(windows)]
    for ticket, dur in queue_list:
        idx = loads.index(min(loads))
        loads[idx] += dur
        assign[idx].append(ticket)
    for i in range(windows):
        print(f"Окно {i+1} ({loads[i]} мин):", *assign[i])