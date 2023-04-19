print(1)

lista = [1]

idx = 1

while lista[-1] + idx <= 5*(10**5):
    lista.append(lista[-1] + idx)
    idx += 1

print(len(lista));
for el in lista:
    print(el)
