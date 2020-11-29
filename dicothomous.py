
array = ['a','b','c','d']
length = 4
pos = length//2
letter = 'c'
temp = array[pos]
added = 0
before = -1

while added == 0:
    if length%2 == 0:
        if array[pos] == letter or array[pos-1] == letter:
            added = 1
    elif temp == letter:
        print("add occurence")
        added = 1
    elif temp < letter:
        if pos == length or pos == before:
            added = -1
        else:
            before = pos
            pos = (length+pos+1)//2
            temp = array[pos]
    else: #mean that the temp letter is not equal or less than the letter that we search so its only higher
        if pos == length or pos == before:
            added = -1
        else:
            befor = pos
            pos = (length-(pos+1))//2
            temp = array[pos]
if added == -1:
    array.insert(pos,letter)
    print('add node')
print(array)
