
import random, sys, time
sys.setrecursionlimit(10**6)

# Quicksort random pivot
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
        if v[i] < v[pivot]:
            v[pivot], v[i] = v[i], v[pivot]
    return pivot

#Quicksort pivot mij
# def quicksort (v, start, stop ):
#     if start < stop:
#         part_rand(v, start, stop)
#         pivot = partitionare(v, start, stop)
#         quicksort(v,start, pivot-1)
#         quicksort(v,pivot+1, stop)
#
# def part_rand(v, start, stop):
#     pivot_rand = (start+stop) // 2
#     v[start], v[pivot_rand] = v[pivot_rand], v[start]
#
# def partitionare (v,start, stop):
#     pivot = start
#     for i in range (start+1, stop+1):
#         if v[i] <= v[pivot]:
#             v[pivot], v[i] = v[i], v[pivot]
#     return pivot


v = [1] * 100000

t0 = time.time()
#quicksort_rp(arr,0, len(arr) -1)
t1 = time.time()
print(t1-t0)








