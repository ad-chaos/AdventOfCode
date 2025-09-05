from itertools import chain

def manhat_dist(p1: tuple[int, int], p2: tuple[int, int]) -> int:
    x1, y1 = p1
    x2, y2 = p2
    return abs(x2 - x1) + abs(y2 - y1)


sensors = []
beacons = []
with open("./input15.txt") as f:
    for line in f:
        sensor, beacon = line.split(": ")
        sensor_loc = map(
            int,
            map(lambda x: x.split("=")[-1], sensor.split("Sensor at ")[-1].split(", ")),
        )
        beacon_loc = map(
            int,
            map(
                lambda x: x.split("=")[-1],
                beacon.split("closest beacon is at ")[-1].split(", "),
            ),
        )
        sensors.append(tuple(sensor_loc)[::-1])
        beacons.append(tuple(beacon_loc)[::-1])

min_x = min(map(lambda x: x[0], chain(sensors, beacons)))
max_x = max(map(lambda x: x[0], chain(sensors, beacons)))
min_y = min(map(lambda x: x[1], chain(sensors, beacons)))
max_y = max(map(lambda x: x[1], chain(sensors, beacons)))

sensor_map = set()
for dist, sensor in zip(map(manhat_dist, sensors, beacons), sensors):
    x, y = sensor
    for i in range(dist):
        sensor_map.add((x + i - dist, y + i))
        sensor_map.add((x + i, y - i + dist))
        sensor_map.add((x - i + dist, y - i))
        sensor_map.add((x - i, y + i - dist))




# from rich import print as rprint
# color = False
# for i in range(max_x-min_x):
#     if i==10:
#         color = True
#     for j in range(max_y-min_y):
#         point = (i + min_x, j + min_y)
#         if point in sensor_map:
#             if point in beacons:
#                 on = "B"
#             else:
#                 on = "#"
#             if color:
#                 rprint(f"[bold red]{on}[/]", end="")
#             else:
#                 print(end=on)
#         elif point in sensors:
#             print(end="S")
#         else:
#             print(end=".")
#     print()
#     color = False
