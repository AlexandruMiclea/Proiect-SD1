for i in range(1, 65):
    with open(f"test{i}.out", "r") as fopen:
        l = []
        l = fopen.readlines()
        for line in l:
            print(line)
            #l.append([x for x in line])