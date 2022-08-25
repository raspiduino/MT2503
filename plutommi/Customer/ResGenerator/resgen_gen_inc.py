debug = False


resgen_inc = file("resgen_default_inc.txt")
custom_inc = file("custom_include.txt")

#read resgen_default_inc.txt---------------
inc_list_1 = []
for line in resgen_inc:
    line = line.strip()
    if line:
        line = line.replace("\\", "/")
        line = line.lower()
        line = line.replace("../../customer/resgenerator/", "./")
        inc_list_1.append(line)


if debug:
    print "inc_list1-----------------"
    for i in inc_list_1:
        print i

#read custom_include.txt--------------------        
inc_list_2 = []
line = custom_inc.readline()
line = line.strip()
items = line.split("-I")
items = items[1:]

for i in items:
    item = i.strip().strip("\"")
    item = item.replace("\\", "/")
    item = item.lower()
    item = item.replace("../../plutommi/customer/", "")
    item = item.replace("../plutommi/", "")
    inc_list_2.append(item)

if debug:
    for i in range(5):
        print
    print "inc_list2-----------------"
    for i in inc_list_2:
        print i
        
#merge two list------------------------------      

all_list = inc_list_1 + inc_list_2


#to reduce the duplicate ones----------------  

reduced_list = []
dup_list = []

count = 0
lenn = 0

for i in all_list:
    if i in reduced_list:
        count += 1
        lenn += len(i)
        dup_list.append(i)        
    else:
        reduced_list.append(i)

if debug:
    for i in range(5):
        print
    print 'dup-----------------'
    print
    print "dup count:", count
    print "dup len:", lenn


if debug:
    print "dup list"
    for i in dup_list:
        print i

#to output the reduced include path to resgen_inc.txt-----------
output = file("resgen_inc.txt", "w")

output.write("RESGEN_INC =")
for i in reduced_list:
    if '(' in i or ')' in i:
        output.write(" -I\""+i+"\"")
    else:
        output.write(" -I"+i)

