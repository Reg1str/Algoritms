#include <fstream>
#include <vector>

using namespace std;

struct BinTree
{
    int data;
    int left;
    int right;
};

int is_tree(vector <int> & TopArray)
{
    for (int i = 1; i < TopArray.size(); i++)
    {
        if (TopArray[i] <= TopArray[i - 1])
            return 1;
    }
    return 0;
}

void inorderTravelsal(BinTree* Tree, vector <int>& TopArray, int child) //
{
    if (child != -1)
    {
        inorderTravelsal(Tree, TopArray, Tree[child].left);
        TopArray.push_back(Tree[child].data);
        inorderTravelsal(Tree, TopArray, Tree[child].right);
    }
}

int is_correct_answer(BinTree* Tree, int x){
    vector <int> TopArray;
    inorderTravelsal(Tree, TopArray, 0);
    return is_tree(TopArray);
}

int main(){
    ifstream fileInput("check.in");
    ofstream fileOutput("check.out");
    int n;
    fileInput >> n;
    BinTree* Tree = new BinTree[n];
    for (int i = 0; i < n; i++){
        fileInput >> Tree[i].data >> Tree[i].left >> Tree[i].right;
        Tree[i].left--;
        Tree[i].right--;
    }
    n == 0 || is_correct_answer(Tree, 0) == 0 ? fileOutput << "YES" : fileOutput << "NO";
    fileInput.close();
    fileOutput.close();
    return 0;
}