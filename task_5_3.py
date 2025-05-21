plane_to_towns = {}
town_to_planes = {}

def create_plane(parts):
    name, stops = parts[0], parts[1:]
    plane_to_towns.setdefault(name, []).extend(stops)
    for t in stops:
        town_to_planes.setdefault(t, []).append(name)

def planes_for_town(town):
    print(*town_to_planes.get(town, []))

def towns_for_plane(name):
    for t in plane_to_towns.get(name, []):
        others = [p for p in town_to_planes.get(t, []) if p!=name]
        print(f"{t}:", *others)

def list_planes():
    for name, stops in plane_to_towns.items():
        print(name+":", *stops)