#python3
def period(m):
    r = 1
    a = 0
    b = 1
    c = 0
    while(not (c == 0 and a == 1)):
        c = (a+b)%m
        a = b
        b = c
        r = r + 1
    return r

def fibo(n):
    if n <= 1:
        return n
    else:
        a = 0
        b = 1
        c = 0
        for i in range(2, n + 1):
            c = a + b
            a = b
            b = c
        return c

def fibo_mod(n, m):
    p = period(m)
    return fibo(n%p)%m

a = list()
a = input().split()

n = int(a[0])
m = int(a[1])

r = fibo_mod(n,m)
print(r)


