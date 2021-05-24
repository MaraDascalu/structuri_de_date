# import random, sys, time, copy
# sys.setrecursionlimit(10**6)
#
# def testSort(a, v):
#     dict_init = {}
#     dict_fin = {}
#     for elem in a:
#         if elem in dict_init:
#             dict_init[elem] += 1
#         else:
#             dict_init[elem] = 1
#
#     for i in range (len(v) - 1):
#         if v[i] > v[i+1]:
#             return 0
#
#     for elem in v:
#         if elem in dict_fin:
#             dict_fin[elem] += 1
#         else:
#             dict_fin[elem] = 1
#
#     if dict_fin == dict_init:
#         return True
#     return False
#
#
# #
# # Quicksort random pivot
# #
#
# def quicksort_rp (v, start, stop ):
#     if len(v)> 5000:
#         return False
#     else:
#         if start < stop:
#             p = random.randrange(start, stop)
#             v[start], v[p] = v[p], v[start]
#             pivot = partitionare(v, start, stop)
#             quicksort_rp(v,start, pivot-1)
#             quicksort_rp(v,pivot+1, stop)
#
# def partitionare (v,start, stop):
#     pivot = start
#     for i in range (start+1, stop+1):
#         if v[i] <= v[pivot]:
#             v[pivot], v[i] = v[i], v[pivot]
#     return pivot
#
# #
# # Quicksort pivot mij
# #
#
# def quicksort (v, start, stop ):
#     if len(v) > 5000:
#         return False
#     else:
#         if start < stop:
#             part_rand(v, start, stop)
#             pivot = partitionare (v, start, stop)
#             quicksort(v,start, pivot-1)
#             quicksort(v,pivot+1, stop)
#
# def part_rand(v, start, stop):
#     pivot_rand = (start+stop) // 2
#     v[start], v[pivot_rand] = v[pivot_rand], v[start]
#
# #
# #Heap sort
# #
# def heapify(v, n, idx):
#     parent = idx
#     left = 2*idx + 1
#     right = 2*idx + 2
#
#     if left<n and v[parent]<v[left]:
#         parent = left
#     if right<n and v[parent]<v[right]:
#         parent = right
#     if parent != idx:
#         v[parent], v[idx] = v[idx], v[parent]
#         heapify(v, n, parent)
#
# def heap_sort(v):
#     if len(v) > 500000:
#         return False
#     else:
#         for i in range(len(v)//2 - 1, -1, -1):
#             heapify(v, len(v), i)
#
#         for i in range(len(v) - 1, 0, -1):
#             v[0], v[i] = v[i], v[0]
#             heapify(v, i, 0)
#
# #
# # Cocktail sort
# #
#
# def cocktail_sort(v):
#     if len(v)> 5000:
#         return False
#     else:
#         swap = True
#         start = 0
#         end = len(v) - 1
#         while swap == True:
#             swap = False
#             for i in range(start, end):
#                 if v[i] > v[i+1]:
#                     v[i], v[i+1] = v[i+1], v[i]
#                     swap = True
#             if swap == False:
#                 break
#             swap = False
#             end -= 1
#             for i in range (end - 1, start - 1, -1):
#                 if v[i] > v[i+1]:
#                     v[i], v[i+1] = v[i+1], v[i]
#                     swap = True
#             start += 1
#
# #
# # Counting sort
# #
#
# def counting_sort(v):
#     if max(v) > 10000000 or len(v) > 10000000:
#         return False
#     else:
#         elem_max = max(v)
#         elem_min = int(min(v))
#         range_elem = elem_max - elem_min + 1
#         cs = [0] * range_elem
#         output = [0] * len(v)
#
#         for i in range (len(v)):
#             cs[v[i] - elem_min] += 1
#
#         for i in range (1,len(cs)):
#             cs[i] += cs[i - 1]
#
#         for i in range (len(v)-1, -1, -1):
#             output[cs[v[i] - elem_min] -1] = v[i]
#             cs[v[i] - elem_min] -= 1
#
#         for i in range(len(v)):
#             v[i] = output[i]
#
# #
# # Radix sort
# #
#
# def counting_sort_r(v, exp):
#     output = [0] * len(v)
#     cs = [0] *10
#
#     for i in range (len(v)):
#         cs[(v[i] // exp) %10] += 1
#
#     for i in range (1, 10):
#         cs[i] += cs[i-1]
#
#     for i in range (len(v) - 1, -1, -1):
#         output[cs[(v[i] // exp) %10] - 1] += v[i]
#         cs[(v[i] // exp) %10] -= 1
#
#     for i in range (len(v)):
#         v[i] = output[i]
#
# def radix_sort(v):
#     if len(v) >= 1000000:
#         return False
#     else:
#         elem_max = max(v)
#         exp = 1
#         while elem_max // exp >0:
#             counting_sort_r(v, exp)
#             exp *= 10
#
# with open("input.txt") as f:
#     tests = f.read()
#
# tests = [int(x) for x in tests.split()]
# nr_tests = tests.pop(0)
# for i in range(0, 2*nr_tests - 1, 2):
#     print("Test nr", i//2 + 1)
#     n = tests[i]
#     nr_max = tests[i+1]
#     print(n, nr_max)
#     a = [random.randint(0, nr_max) for _ in range(n)]
#     v = copy.deepcopy(a)
#     t0 = time.time()
#     result = quicksort(v, 0, len(v) - 1)
#     if result == False:
#         print("QuickSort merge prea incet.")
#     else:
#         t1 = time.time()
#         print("Quicksort time : ", t1 - t0, testSort(a, v))
#     v = copy.deepcopy(a)
#     t0 = time.time()
#     result = quicksort_rp(v, 0, len(v) - 1)
#     if result == False:
#         print("QuickSort (random pivot) merge prea incet.")
#     else:
#         t1 = time.time()
#         print("Quicksort (random pivot) time : ", t1 - t0, testSort(a, v))
#     v = copy.deepcopy(a)
#     t0 = time.time()
#     result = heap_sort(v)
#     if result == False:
#         print("HeapSort merge prea incet.")
#     else:
#         t1 = time.time()
#         print("HeapSort time : ", t1 - t0, testSort(a, v))
#     v = copy.deepcopy(a)
#     t0 = time.time()
#     result = cocktail_sort(v)
#     if result == False:
#         print("CocktailSort merge prea incet.")
#     else:
#         t1 = time.time()
#         print("CocktailSort time : ", t1 - t0, testSort(a, v))
#     v = copy.deepcopy(a)
#     t0 = time.time()
#     result = counting_sort(v)
#     if result == False:
#         print("CountingSort merge prea incet.")
#     else:
#         t1 = time.time()
#         print("CountingSort time : ", t1 - t0, testSort(a, v))
#     v = copy.deepcopy(a)
#     t0 = time.time()
#     result = radix_sort(v)
#     if result == False:
#         print("RadixSort merge prea incet.")
#     else:
#         t1 = time.time()
#         print("RadixSort time : ", t1 - t0, testSort(a, v))
#     v = copy.deepcopy(a)
#     t0 = time.time()
#     v = sorted(v)
#     t1 = time.time()
#     print("PythonSort time : ", t1 - t0, testSort(a, v))
#     print("\n")
#

# stones = [2, 1, 7, 1, 4, 8]
# while len(stones) >= 2:
#     n = len(stones)
#     stones.sort()
#     print(stones)
#     if stones[n - 2] == stones[n - 1]:
#         stones = stones[:n - 2]
#     else:
#         stones[n - 1] -= stones[n - 2]
#         stones.remove(stones[n - 2])
#
# if len(stones) == 1:
#     print(stones[0])
# else:
#     print('0')


nums = [3,2,1,5,6,4]
k = 2
fr = [0]* (max(nums) - min(nums) + 1)
print(max(nums) - min(nums) + 1)
for i in range (len(nums)):
    fr[nums[i] - min(nums)] += 1

print(fr)
for i in range (len(fr) - 1, -1, -1):
    k -= fr[i]
    if k <= 0:
        print(i + min(nums))
        break