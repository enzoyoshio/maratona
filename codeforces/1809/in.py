lista = []

for i in range(2, 31):
    for n in range(i*(i+1)//2):
        lista.append((i, n))

print(len(lista))

for n, k in lista:
    print(n, k)
