import random

#
# Implementare stack cu list
#

stack = []
n = random.randint(3,20)
for i in range (n):
    stack.append(random.randint(0, 100))
print(stack)
for i in range (n):
    print(stack.pop())

#
# Implementare queue cu linked list
#



