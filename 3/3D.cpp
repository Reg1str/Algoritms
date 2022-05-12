#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void SiftDown(vector <int> &arr,int i,int roof){
    long long right;
    long long left;
    long long score;
    while(2*i<roof){
        left = 2*i;
        right = 2*i+1;
        score = 2*i;
        if((right!=roof) && (arr[right]<arr[left]))
        score=right;
         
        if(arr[score]<arr[i])
        swap(arr[score],arr[i]);
        else return;
        i=score;
    }
    return;
}

void SiftUp(vector <int> &arr,int i){
    while(true){
        if(i==1)
        return;
        if(arr[i] < arr[i/2])
        swap(arr[i],arr[i/2]);
        else return;
        i = i/2;
         
    }
}

int ExtractMin(vector <int> &CurHeap){
  int z;
  swap(CurHeap[1],CurHeap[CurHeap.size()-1]);
  z = CurHeap[CurHeap.size()-1];
  CurHeap.pop_back();
  SiftDown(CurHeap,1,CurHeap.size());
  return z;
}

void decreasekey(vector <int> &CurHeap,int CurNum, int reverse){
  int i;
  for(i = 1 ; i < CurHeap.size() ;i++){
    if(CurHeap[i] == CurNum){
      CurHeap[i] = reverse;
      break;
    }
  }
  SiftUp(CurHeap,i);
  return;
}

int main() {
  vector <int> CurHeap;
  CurHeap.push_back(0);
  ifstream inp("priorityqueue.in");
  ofstream outp("priorityqueue.out");
  int CurNum;
  vector <int> PosElements;
  string check;
  for(;;){
    inp >> check;
    if(inp.eof())
    break;
    if(check == "push"){
      inp >> CurNum;
      PosElements.push_back(CurNum);
      CurHeap.push_back(CurNum);
      SiftUp(CurHeap , CurHeap.size()-1); 
    }
    else{
      PosElements.push_back(0);
      }
    if(check == "extract-min"){
      if(CurHeap.size() == 1)
      outp << "*" << "\n";
      else
      outp << ExtractMin(CurHeap) << '\n';
    }
    if(check == "decrease-key"){
      int reverse;
      int j;
      inp >> CurNum;
      j = CurNum;
      CurNum = PosElements[CurNum - 1];
      inp >> reverse;
      PosElements[j-1]= reverse;
      decreasekey(CurHeap,CurNum,reverse);
    }
  }
}