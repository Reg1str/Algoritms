fin = open("brackets.in")
fout = open("brackets.out", "w")
 
def push(stack, number):
    stack.append(number)
 
def pop_back(stack):
    deletedNum = stack[-1]
    del(stack[-1])
    return deletedNum
 
 
input_str = '1'
while input_str != '':
    input_str = str(fin.readline())
    if input_str != '':
        stack = ['elem']
        for i in range(len(input_str)):
            if input_str[i] == "(":
                push(stack, "(")
 
            elif input_str[i] == "[":
                push(stack, "[") 
 
            elif input_str[i] == ")" and stack[-1] == "(":
                pop_back(stack)
             
            elif input_str[i] == "]" and stack[-1] == "[":
                pop_back(stack)
 
            elif input_str[i] == "]":
                push(stack, "]")
 
            elif input_str[i] == ")":
                push(stack, ")")
 
        if stack == ['elem']:
            print("YES", file = fout)
        else:
            print("NO", file = fout)
 
 
fout.close()