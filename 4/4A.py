fileInput = open("stack.in")
fileOutput = open("stack.out", "w")
 
def push(stack,number):
    stack.append(number)
def pop(stack):
    return stack.pop()
 
n=int(fileInput.readline())
new_stack=[]
 
for i in range(n):
    type_action=[str(i) for i in fileInput.readline().split()]
    if type_action[0]=='+':
        push(new_stack,int(type_action[1]))
    elif type_action[0]=='-':
        print(pop(new_stack),file=fileOutput)