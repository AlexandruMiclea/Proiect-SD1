timpi = [0] * 16

for i in range(1, 65):
    with open(f"test{i}.out", "r") as fopen:
        l = fopen.readlines()
        #print(l)

        for i in range(len(l)):
            aux = [x for x in l[i].split()]
            timpi[i] += float(aux[7])
            print(aux[7])

timpi = [x/64 for x in timpi]
print(timpi)
        