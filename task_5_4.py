sched = {i: [] for i in range(1,32)}
month_days = 31

def do_class(day, name): sched[day].append(name)

def do_next():
    global month_days, sched
    prev = month_days
    month_days = 30 if month_days==31 else (31 if month_days==30 else 28)
    new = {i: [] for i in range(1, month_days+1)}
    for d in range(1, prev+1):
        if d <= month_days:
            new[d].extend(sched[d])
        else:
            new[month_days].extend(sched[d])
    sched = new

def do_view(day):
    v = sched.get(day, [])
    if not v:
        print(f"In {day} day We are free!")
    else:
        print(f"In {day} day {len(v)} classes in university:", *v)