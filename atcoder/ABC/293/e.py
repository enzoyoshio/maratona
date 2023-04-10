a, x, m = [int(x) for x in input().split()]

print((a*(a**(x-1)-1)//(a-1) + 1)%m)
