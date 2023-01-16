from random import randint
marblebag = []
def addmarble():
    c = -1
    while ((c > 2) or (c < 0)):
        print("0=red\n1=green\n2=blue")
        c = int(input("What color of marble do you want to add? "))
        if ((c > 2) or (c < 0)):
            print("Invalid color choice")
    if c == 0:
        marblebag.append("red")
    elif c == 1:
        marblebag.append("green")
    elif c == 2:
        marblebag.append("blue")
    else:
        print("ERROR: color not in expected range")
def removemarble():
    marbleindex = randint(0, len(marblebag)-1)
    print(f"You pulled out a {marblebag[marbleindex]} marble!")
    marblebag.pop(marbleindex)
def marblecount():
    red = 0
    green = 0
    blue = 0
    for i in range(0, len(marblebag)):
        case = marblebag[i]
        if case == "red":
            red += 1
        elif case == "green":
            green += 1
        elif case == "blue":
            blue += 1
        else:
            print("There is a wierd marble in the bag!")
    print(f"There are {red} red marbles, {green} green marbles, and {blue} blue marbles")
addmarble()
addmarble()
addmarble()
removemarble()
marblecount()
print(marblebag)