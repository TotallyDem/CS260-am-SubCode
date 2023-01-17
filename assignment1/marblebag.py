from random import randint
marblebag = []

def addmarble():
    """Prompts the user for what kind of marble to add to the marblebag variable."""

    c = -1
    while ((c > 2) or (c < 0)): # using a number based selection
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
    else: # Shouldn't be possible, but it doesn't hurt to include.
        print("ERROR: color not in expected range")

def removemarble():
    """Removes a random marble from the marblebag variable."""

    marbleindex = randint(0, len(marblebag)-1)
    print(f"You pulled out a {marblebag[marbleindex]} marble!")
    marblebag.pop(marbleindex)

def marblecount():
    """Prints out the amount of each kind of marble inside the marblebag variable."""

    red = 0
    green = 0
    blue = 0
    for i in range(0, len(marblebag)): # Iterating through all indexes
        case = marblebag[i]
        if case == "red":
            red += 1
        elif case == "green":
            green += 1
        elif case == "blue":
            blue += 1
        else: # Shouldn't be possible unless the user manually edits the variables, but doesn't hurt to incldue.
            print("There is a wierd marble in the bag!")
    print(f"There are {red} red marbles, {green} green marbles, and {blue} blue marbles")

# Just a little function spam to verify the program is working correctly.
addmarble()
addmarble()
addmarble()
removemarble()
marblecount()
print(marblebag) # For a good last measure, just printing the entire list shows that the count is correct.