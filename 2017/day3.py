from math import isqrt

# Part 1
# 17  16  15  14  13
# 18   5   4   3  12
# 19   6   1   2  11
# 20   7   8   9  10
# 21  22  23  24  25 -->
#
# Consider the following rows:
# 1  2  3
# 4  5  6  7
# 8  9  10 11 12 13
# 14 15 16 17 18 19 20 21
# 22 23 24 25 26 27 28 29 30
# and so on ...
#
# See if you can define the sequence in any ith row

a = 361527
n = isqrt(a)
i = a-n**2 > -a+(n+1)**2
c = a!=n**2
n += i
y, x = c and [1+n**2-a,0][i], c and [-1,-a+n**2][i]
print(
    [
        abs(-y-n/2)+abs(-x-1+n/2),
        abs(y+(n-1)/2)+abs(x+(1-n)/2),
    ][n%2]
)
