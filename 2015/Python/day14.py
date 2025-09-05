from pprint import pprint

S = 1000

maximum = 0
deers: dict = {}
# part 1
with open("./input14.txt") as f:
    for line in f.readlines():
        name = line.rstrip().split(" ")[0]
        speed, time, rest = map(int, line.rstrip().split(" ")[1:])
        deers[name] = {
            "speed": speed,
            "time": time,
            "rest": rest,
            "distance": 0,
            "points": 0,
            "running?": True,
            "internal_timer": time,
        }
        n = int(S / (time + rest))
        if time * (n + 1) + rest * n <= S:
            maximum = max(maximum, speed * time * (n + 1))
        else:
            maximum = max(maximum, speed * time * n)

pprint(maximum)

# part 2 (remains unsolved :( )
# the dist_per dictionary contains the state and information of a deer
# dist_per = {"deer_name":
#       speed,
#       time it can run for,
#       resting time,
#       distance travelled,
#       points accumulated,
#       it it running?,
#       internal timer]}
#
S = 0
while S != 1000:
    for deer in deers:
        if deers[deer]["running?"]:
            if deers[deer]["internal_timer"]:
                deers[deer]["distance"] += deers[deer]["speed"]
                deers[deer]["internal_timer"] -= 1
            else:
                deers[deer]["running?"] = False
                deers[deer]["internal_timer"] = deers[deer]["rest"]
        else:
            if deers[deer]["internal_timer"]:
                deers[deer]["internal_timer"] -= 1
            else:
                deers[deer]["running?"] = True
                deers[deer]["internal_timer"] = deers[deer]["time"]

    maximum = max(deers, key=lambda x: deers[x]["distance"])
    for deer in deers:
        if deers[deer]["distance"] == deers[maximum]["distance"]:
            deers[deer]["points"] += 1
    S += 1


maximum = max(deers, key=lambda x: deers[x]["distance"])
pprint(deers)
