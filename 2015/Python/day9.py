with open("./input9.txt") as f:
    city_map = f.readlines()

map = {}
cities = set()
for edge in city_map:
    c1, _, c2, _, dist = edge.split(" ")
    print(c1, c2, dist)
    map[(c1,c2)] = int(dist)
    cities.add(c1)
    cities.add(c2)
    
cities = list(cities)
travel_loop = []
tot_cities = len(cities)
for i in range(tot_cities-1):
    try:
        travel_loop.append(map[(cities[i],cities[i+1])])
    except KeyError:
        travel_loop.append(map[(cities[i+1],cities[i])])

try:
    travel_loop.append(map[(cities[0],cities[-1])])
except KeyError:
    travel_loop.append(map[(cities[-1],cities[0])])

print(sum(travel_loop)-max(travel_loop))
