import time, random
def counting_sort(v, exp):
    output = [0] * len(v)
    cs = [0] *10

    for i in range (len(v)):
        cs[(v[i] // exp) %10] += 1

    for i in range (1, 10):
        cs[i] += cs[i-1]

    for i in range (len(v) - 1, -1, -1):
        output[cs[(v[i] // exp) %10] - 1] += v[i]
        cs[(v[i] // exp) %10] -= 1

    for i in range (len(v)):
        v[i] = output[i]

def radix_sort(v):
    elem_max = max(v)
    exp = 1
    while elem_max // exp >0:
        counting_sort(v, exp)
        exp *= 10

v = random.sample(range(0,1000), 200)
t0 = time.time()
radix_sort(v)
t1 = time.time()
print(t1-t0,v)