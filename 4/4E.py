length=int(input())
new_array=[int(i) for i in input().split()][:length]
 
search_length=int(input())
search_array=[int(i) for i in input().split()][:search_length]
 
 
def bin_search_first(array,item,left,right): 
    if right-left<=1:
        if array[left] == item:
            return left
        elif array[right] == item:
            return right
        else:
            return -1
    mid=(left+right)//2
    if item <= array[mid]:
        return bin_search_first(array, item, left, mid)
    else:
        return bin_search_first(array, item, mid, right)
     
         
def bin_search_second(array,item,left,right): 
    if right-left<=1:
        if array[right] == item:
            return right
        elif array[left] == item:
            return left
        else:
            return -1
    mid=(left+right)//2
    if item >= array[mid]:
        return bin_search_second(array, item, mid, right)
    else:
        return bin_search_second(array, item, left, mid)
 
 
 
                   
for i in range(search_length):
    first_in = bin_search_first(new_array,search_array[i],0,length-1)
    second_in = bin_search_second(new_array,search_array[i],0,length-1)
                   
    if first_in != -1:
        first_in+=1
    if second_in != -1:
        second_in+=1
    print(first_in, second_in)