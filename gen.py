from random import randint

def gen(n_max, m_max):
    n, m = randint(1, n_max), randint(1, m_max);
    k = randint(1, m)

    return map(str, (n, m, k))

case_type = input()
cases = int(input())

n_max, m_max = map(int, input().split())

for i in range(cases):
    path = "cases/{}/case-{}".format(case_type, str(i).zfill(5));
    try:
        open(path, 'x').close()
    except FileExistsError:
        pass
    file = open(path, 'w')
    file.write(" ".join(gen(n_max, m_max)))
    file.close()
