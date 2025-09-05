import json
import re

def hook(obj:dict):
    if "red" in obj.values():
        return {}
    else:
        return obj

with open("./input12_2.txt", "r") as f:
    data = str(json.load(f, object_hook=hook))
    print(sum(map(int,re.findall(r"-?[0-9]+", data))))
