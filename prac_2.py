group_A = []    # Cricket
group_B = []    # Badminton
group_C = []    # Football

# Input for Cricket players
cric = int(input("Enter no. of players playing cricket : "))
for i in range(cric):
    n = int(input("Enter player no. : "))
    group_A.append(n)

# Input for Badminton players
bad = int(input("Enter no. of players playing Badminton: "))
for i in range(bad):
    n = int(input("Enter player no. : "))
    group_B.append(n)

# Input for Football players
foot = int(input("Enter no. of players playing Football : "))
for i in range(foot):
    n = int(input("Enter player no. : "))
    group_C.append(n)

# Find students who play only one sport
totalStudents = []
all_players = group_A + group_B + group_C

for player in all_players:
    count = 0
    if player in group_A:
        count += 1
    if player in group_B:
        count += 1
    if player in group_C:
        count += 1
    if count == 1:
        if player not in totalStudents:  # Avoid duplicates
            totalStudents.append(player)

# Cricket and Badminton
cricWbad = []
for i in group_A:
    if i in group_B and i not in cricWbad:
        cricWbad.append(i)
print("Cricket and Badminton : ", cricWbad)

# Either Cricket or Badminton
cricOrbad = []
for i in group_A:
    if i not in group_B and i not in cricOrbad:
        cricOrbad.append(i)
for i in group_B:
    if i not in group_A and i not in cricOrbad:
        cricOrbad.append(i)
print("Either Cricket or Badminton : ", cricOrbad)

# Neither Cricket Nor Badminton
cricNbad = []
for i in totalStudents:
    if i not in group_A and i not in group_B:
        cricNbad.append(i)
print("Neither Cricket Nor Badminton : ", cricNbad)

# Cricket and Football but not Badminton
cricWfootNbad = []
for i in group_A:
    if i in group_C and i not in group_B:
        cricWfootNbad.append(i)
print("Cricket and Football but not Badminton : ", cricWfootNbad)
