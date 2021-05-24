import collections
with open("deque.in") as f:
    val = [int(x) for x in f.read().split()]

n = val[0]
k = val[1]
deque = collections.deque([])
for i in range(2, 2+k):
    if i == 2:
        min = val[2]
    elif val[i] < min:
        min = val[i]
    deque.append(val[i])

for i in range(2 + k, n + 2):
    deque.popleft()
    deque.append(val[i])
    print(deque)



