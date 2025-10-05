val = [
    ("le", 123), ("cours", 22), ("appelé", 88), ("structure", 43), ("de", 4),
    ("données", 28), ("est", 73), ("absolument", 7), ("génial", 13)
]


def f1(x):
    return x


def f2(x):
    return 10*x


def f3(x):
    return 2*x


def f4(x):
    if x == 0:
        return 0
    return 8 * f4(int(x/10)) + x % 10


print([(a,f1(b)) for a, b in val])
print("")
print([(a,f2(b)) for a, b in val])
print("")
print([(a,f3(b)) for a, b in val])
print("")
print([(a,f4(b)) for a, b in val])

print("")
print("collisions f1", len(val) - len({ f1(b) % 10 for _, b in val }))
print("")
print("collisions f2", len(val) - len({ f2(b) % 10 for _, b in val }))
print("")
print("collisions f3", len(val) - len({ f3(b) % 10 for _, b in val }))
print("")
print("collisions f4", len(val) - len({ f4(b) % 10 for _, b in val }))


print("")
print("La meilleure fonction est donc f4, car elle génère moins de collisions que les autres")
