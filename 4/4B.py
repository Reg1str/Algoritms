fileInput = open("queue.in")
fileOutput = open("queue.out", "w")
def push(queue,number):
    queue.append(number)
 
def pop(queue):
    return queue.pop(0)
 
countOfOperations=int(fileInput.readline())
new_queue=[]
for i in range(countOfOperations):
  input_new=[str(i) for i in fileInput.readline().split()]
  if input_new[0]=='+':
    push(new_queue,int(input_new[1]))
  elif input_new[0]=='-':
    print(pop(new_queue),file=fileOutput)