# longest word
String1 = "Heyyyyyyyyyy there I am Sinix and I am a Coder"
words = String1.split(" ")
largest = sorted(words, key=len)

print(f"Largest word in {String1} is {largest[-1]}")

# count
count = 0
for i in String1:
    if i=='a':
        count+=1

print(f"\nIn {String1} , 'a' appeared {count} times" )


# palindrome 
String2 = input("Enter the word to check if it's palindrome")
if String2 == String2[::-1]:
    print(f"\n{String2} is a Palindrome")
else:
    print(f"\n{String2} is not a Palindrome")


# substring
print("Substring found at :",end="")
print(String1.find("nix"))


# occurence
occ_word = dict()

for word in words:
    if word in occ_word:
        occ_word[word] = occ_word[word]+1
    else:
        occ_word[word]=1

print("Occurence of each word : ", end="")
print(occ_word)