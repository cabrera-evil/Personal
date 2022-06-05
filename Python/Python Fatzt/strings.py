myString = "Hello World"
name = "Douglas"

print("My name is " + name)
print(f"My name is {name}")
print("My name is {0}".format(name))

print(dir(myString))
print(myString.upper())
print(myString.lower())
print(myString.swapcase())
print(myString.capitalize())
print(myString.replace('hello', 'bye').upper())
print(myString.count('l'))

print(myString.startswith('Hello'))
print(myString.endswith("World"))

print(myString.split())
print(myString.find('W'))

print(len(myString))
print(myString.index('e'))

print(myString.isnumeric())
print(myString.isalpha())

print(myString[4])