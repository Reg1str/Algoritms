#include <iostream>
#include <fstream>

using namespace std;

ifstream fileInput("balance.in");
ofstream fileOutput("balance.out");

struct TreeNode {
    int value;
    int height;
    int left;
    int right;
};

int treeHeight(TreeNode *Tree, int height) {
    if (height==-1){
        return 0;
    }

    int leftHeight = treeHeight(Tree, Tree[height].left) + 1;
    int rightHeight = treeHeight(Tree, Tree[height].right) + 1;

    if (leftHeight >= rightHeight) {
        Tree[height].height = leftHeight;
        return leftHeight;
    } else {
        Tree[height].height = rightHeight;
        return rightHeight;
    }
}


void TreeHeightCheck(TreeNode *Tree, int treeSize) {


    treeHeight(Tree, 0);

    for (int i = 0; i < treeSize; i++) {
        int leftHeight, rightHeight;

        if (Tree[i].left==-1){
            leftHeight=0;
        } else {
            leftHeight = Tree[Tree[i].left].height;
        }

        if (Tree[i].right==-1){
            rightHeight=0;
        } else {
            rightHeight= Tree[Tree[i].right].height;
        }


        fileOutput << rightHeight - leftHeight << "\n";
    }


}

int main() {
    int n;
    fileInput >> n;
    TreeNode *Tree = new TreeNode[n];

    for (int i = 0; i < n; i++) {
        fileInput >> Tree[i].value >> Tree[i].left >> Tree[i].right;
        Tree[i].left--;
        Tree[i].right--;
    }

    TreeHeightCheck(Tree, n);
    return 0;
}
