import time
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

v = [1]*100000
t0 = time.time()
heap_sort(v)
t1 = time.time()
print(t1-t0, v)