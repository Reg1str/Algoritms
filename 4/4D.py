fin = open("postfix.in")
fout = open("postfix.out", "w")
 
stack=[]
result=0
for element in  fin.readline().split():
  if element in '+-*':
    first=stack[-2]
    second=stack[-1]
    stack.pop()
    stack.pop()
 
    if element=='+':
      result=first+second
    elif element=='-':
      result=first-second
    else: 
      result=first*second
 
    stack.append(result)
  else:
    stack.append(int(element))
print(stack[0],file=fout)