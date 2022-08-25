import os

files = os.listdir('debug/dep')

s = set()

for f in files:
    if f.endswith('.d'):
        ff = open('debug/dep/' + f)
        lines = ff.readlines()[1:]
        for l in lines:
            l = l.strip().split('\\')[0]
            items = l.split()
            for i in items:
                i = os.path.split(i)[0]
                if i:
                    s.add(i)

result = list(s)
result.sort()

output = file('resgen_dep_inc.txt', 'w')

if 1:
    # output readable log
    count = 0
    for i in result:
        output.write(i+'\n')
        count += 1

    output.write('count: ' + str(count) + '\n')
else:
    # output make inc path
    output.write('RESGEN_INC =')
    for i in result:
        output.write(' -I' + i)
