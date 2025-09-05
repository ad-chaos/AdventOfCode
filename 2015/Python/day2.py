import json

with open("./input2.txt", "r") as f:
    dims = json.load(f)
#dims = [[2,3,4]]
#part 1
total1 = 0
for dim in dims:
    l,w,h = dim
    total1 += 2*(l*w + w*h + h*l) 
    total1 += min(l*w , w*h , h*l)

print(total1)


#part 2
total2 = 0
for dim in dims:
    l,w,h = dim
    total2 += l*w*h
    total2 += 2*min(l+w, w+h, h+l)

print(total2)
