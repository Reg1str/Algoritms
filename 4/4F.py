fileInput = open("garland.in")
fileOutput = open("garland.out", "w")

n, A = map(float, fileInput.readline().split())
n = int(n)

garland = [0 for x in range(n)]
garland[0]=A

left=0
right = A

switch= True

while switch == True:
    
    prev = garland[-1]
    garland[1] = (left + right) / 2
    
    for i in range(2, n):
        garland[i] = 2 * garland[i - 1] + 2 - garland[i - 2]
        
    minimum = float('inf')
    
    for i in range(n):
        if garland[i] < minimum:
            minimum = garland[i]
            
    if minimum < 0:
        left = garland[1]
        
    elif minimum == 0 or (abs(garland[-1] - prev) < 0.01):
        answer = garland[-1]
        switch = False
        
    else:
        right = garland[1]


print(round(answer, 2),file=fileOutput)