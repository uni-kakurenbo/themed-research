from random import randint

def gen(n_max, m_max):
    n, m = randint(1, n_max), randint(1, m_max);
    k = randint(1, m)

    return map(str, (n, m, k))

case_type = input()
cases = int(input())

n_max, m_max = map(int, input().split())

path = "cases/{}/seeds.txt".format(case_type);

try:
    open(path, 'x').close()
except FileExistsError:
    pass

file = open(path, 'w')

for i in range(cases):
    file.write(" ".join(gen(n_max, m_max)) + "\n")

file.close()
