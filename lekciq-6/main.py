import math


n = int(input())
def firstDigit(n) :

    while n >= 10: 
        n = n / 10;

    return math.floor(int(n))
conter = 0
if n < 1:
    print('try again!')
for i in range(n):
    if conter == 3:
        break
    if i ==3:
        print(i)
        conter +=1
    elif firstDigit(i) == 3 and i%2>0 and i%3>0 and i%5>0 and i%7>0:
        conter +=1
        print(i)

        