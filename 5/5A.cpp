#include <fstream>
#include <iostream>

using namespace std;

ifstream fileInput("height.in");
ofstream fileOutput("height.out");

struct BinTree {
    int data;
    int left;
    int right;
};

int BtHeight(BinTree* Tree, int height) {
    if (height == -1) {
        return 0;
    }
    else {
        int lHeight = BtHeight(Tree, Tree[height].left) +1;
        int rHeight = BtHeight(Tree, Tree[height].right)+1;
        if (lHeight >= rHeight){
            return lHeight;
        }
        else {
            return rHeight;
        }

    }
}
int main()
{
    int n;
    fileInput >> n;
    BinTree* Tree = new BinTree[n];
    for (int i = 0; i < n; i++) {
        fileInput >> Tree[i].data >> Tree[i].left >> Tree[i].right;
        Tree[i].left--;
        Tree[i].right--;
    }
    if (n == 0) {
        fileOutput << 0;
    }
    else {
        fileOutput << BtHeight(Tree, 0);
    }
    fileInput.close();
    fileOutput.close();
}
