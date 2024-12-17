students_marks = {}

N = int(input("Enter number of students : "))

for _ in range(N):
    name = input("Enter name of student : ")
    marks = input(f"Enter marks of {name} / if absent enter 'A' : ")

    if(marks.upper() == 'A'):
        students_marks[name]=None
    else:
        students_marks[name]=int(marks)

present_marks = [marks for marks in students_marks.values() if marks is not None]

if present_marks:
    average = sum(present_marks)/len(present_marks)
else:
    average = 0

highest = max(present_marks)
lowest = min(present_marks)

counter = 0
max_count = 0

for i in present_marks:
    counter_max = present_marks.count(i)
    if(counter_max > counter):
        counter = counter_max
        max_count = i

absent_list = [name for name, marks in students_marks.items() if marks is None]


print(f"Average of {N} students : ",average)
print(f"Highest of {N} students : ",highest)
print(f"Lowest of {N} students : ",lowest)
print(f"Most common marks of {N} students : ",max_count)
print(f"Absent students out of {N} students : ", absent_list )