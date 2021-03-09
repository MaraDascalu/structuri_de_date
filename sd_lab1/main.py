import random, sys, time
sys.setrecursionlimit(10**6)

#
# Quicksort random pivot
#

def quicksort_rp (v, start, stop ):
    if start < stop:
        p = random.randrange(start, stop)
        v[start], v[p] = v[p], v[start]
        pivot = partitionare(v, start, stop)
        quicksort_rp(v,start, pivot-1)
        quicksort_rp(v,pivot+1, stop)

def partitionare (v,start, stop):
    pivot = start
    for i in range (start+1, stop+1):
        if v[i] <= v[pivot]:
            v[pivot], v[i] = v[i], v[pivot]
    return pivot

#
# Quicksort pivot mij
#

def quicksort (v, start, stop ):
    if start < stop:
        part_rand(v, start, stop)
        pivot = partitionare (v, start, stop)
        quicksort(v,start, pivot-1)
        quicksort(v,pivot+1, stop)

def part_rand(v, start, stop):
    pivot_rand = (start+stop) // 2
    v[start], v[pivot_rand] = v[pivot_rand], v[start]

#
#Heap sort
#
def heapify(v, n, idx):
    parent = idx
    left = 2*idx + 1
    right = 2*idx + 2

    if left<n and v[parent]<v[left]:
        parent = left
    if right<n and v[parent]<v[right]:
        parent = right
    if parent != idx:
        v[parent], v[idx] = v[idx], v[parent]
        heapify(v, n, parent)

def heap_sort(v):
    for i in range(len(v)//2 - 1):
        heapify(v, len(v), i)

    for i in range(len(v) - 1, 0, -1):
        v[0], v[i] = v[i], v[0]
        heapify(v, i, 0)

#
# Cocktail sort
#

def cocktail_sort(v):
    swap = True
    start = 0
    end = len(v) - 1
    while swap == True:
        swap = False
        for i in range(start, end):
            if v[i] > v[i+1]:
                v[i], v[i+1] = v[i+1], v[i]
                swap = True
        if swap == False:
            break
        swap = False
        end -= 1
        for i in range (end - 1, start - 1, -1):
            if v[i] > v[i+1]:
                v[i], v[i+1] = v[i+1], v[i]
                swap = True
        start += 1

#
# Counting sort
#

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

#
# Radix sort
#

def counting_sort_r(v, exp):
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
        counting_sort_r(v, exp)
        exp *= 10

v = random.sample(range(1000000),1000)
t0 = time.time()
quicksort(v,0, len(v) - 1)
t1 = time.time()
print("Qiucksort time : ",t1 - t0)
t0 = time.time()
quicksort_rp(v, 0, len(v) - 1)
t1 = time.time()
print("Quicksort random pivot time : ", t1 - t0)
t0 = time.time()
heap_sort(v)
t1 = time.time()
print("Heap sort time : ", t1 - t0)
t0 = time.time()
cocktail_sort(v)
t1 = time.time()
print("Cocktil sort time : ", t1 - t0)
t0 = time.time()
counting_sort(v)
t1 = time.time()
print("Counting sort time : ", t1 - t0)
t0 = time.time()
radix_sort(v)
t1 = time.time()
print("Radix sort time : ", t1 - t0)
t0 = time.time()
v_sort = sorted(v)
t1 = time.time()
print("Python sort time : ", t1 - t0)
