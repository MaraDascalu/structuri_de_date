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

v = [5, 1, 4, 2, 8, 0, 2]
cocktail_sort(v)
print(v)