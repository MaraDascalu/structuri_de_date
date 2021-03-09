import time
def counting_sort(v):
    elem_max = max(v)
    elem_min = int(min(v))
    range_elem = elem_max - elem_min + 1
    cs = [0] * range_elem
    output = [0] * len(v)

    for i in range (len(v)):
        cs[v[i] - elem_min] += 1

    for i in range (1,len(cs)):
        cs[i] += cs[i - 1]

    for i in range (len(v)-1, -1, -1):
        output[cs[v[i] - elem_min] -1] = v[i]
        cs[v[i] - elem_min] -= 1

    for i in range(len(v)):
        v[i] = output[i]


v = [-5, -10, 0, -3, 8, 5, -1, 10]
t0 = time.time()
counting_sort(v)
t1=time.time()
print(v, t1-t0)
