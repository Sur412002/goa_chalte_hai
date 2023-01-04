groupA = []
groupB = []
groupC = []
print("INPUT: ")
print("Enter roll no.s of students who play cricket:(Enter -1 to terminate input) ")
i = 0
while i != -1:
    i = int(input())
    if i != -1:
        groupA.append(i)
    print("\n")
print("Enter roll no.s of students who play badminton:(Enter -1 to terminate input) ")
i = 0
while i != -1:
    i = int(input())
    if i != -1:
        groupB.append(i)
    print("\n")
print("Enter roll no.s of students who play football:(Enter -1 to terminate input) ")
i = 0
while i != -1:
    i = int(input())
    if i != -1:
        groupC.append(i)
    print("\n")
def intersection(list1, list2):
    list = []
    for i in list1:
        if i in list2:
            list.append(i)
    return list
def list1_or_list2_not_both(list1, list2):
    list = []
    for i in list1:
        if i not in list2:
            list.append(i)
    for i in list2:
        if i not in list1:
            list.append(i)
    return list
def neither_list1_nor_list2(list1, list2, list3):
    list = []
    for i in list3:
        if i not in list1 and i not in list2:
            list.append(i)
    return list
def list1_and_list2_not_list3(list1,list2,list3):
    list = []
    for i in list1:
        if i in list2 and i not in list3:
            list.append(i)
    return list
print("OUTPUT: ")
print("a) List of students who play both cricket and badminton: ")
list = intersection(groupA, groupB)
print(list)
print("\n")
print("b) List of students who play either cricket or badminton but not both: ")
list = list1_or_list2_not_both(groupA, groupB)
print(list)
print("\n")
print("c) Number of students who play neither cricket nor badminton: ")
list = neither_list1_nor_list2(groupA, groupB, groupC)
print(len(list))
print("\n")
print("d) Number of students who play cricket and football but not badminton: ")
list = list1_and_list2_not_list3(groupA,groupC,groupB)
print(len(list))
print("\n")
print("EXIT")
