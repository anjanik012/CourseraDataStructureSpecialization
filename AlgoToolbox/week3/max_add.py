# python3

def max_ad_rev(a , b):
    a.sort()
    b.sort()
    
    max_rev = 0
    for i , j in zip(a , b):
        max_rev = max_rev + i*j

    return max_rev

a = list()
b = list()
n = int(input())
x = input().split()
y = input().split()

for i in x:
    a.append(int(i))
for j in y:
    b.append(int(j))

print(max_ad_rev(a , b))


