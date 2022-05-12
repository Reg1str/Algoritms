#include <iostream>
#include <fstream>

using namespace std;

struct TreeNode {
    int key;
    int right;
    int left;
    int balance;
};

int TreeBalance(TreeNode *Tree, int currentPointer, int heightCounter) {
    int leftHeight = 0;
    int rightHeight = 0;

    if (Tree[currentPointer].left != 0) {
        leftHeight = TreeBalance(Tree, Tree[currentPointer].left, heightCounter);
    }
    leftHeight++;

    if (Tree[currentPointer].right != 0) {
        rightHeight = TreeBalance(Tree, Tree[currentPointer].right, heightCounter);
    }
    rightHeight++;

    if (leftHeight > rightHeight)
        heightCounter = leftHeight;

    else if (leftHeight < rightHeight)
        heightCounter = rightHeight;

    else if (leftHeight == rightHeight && leftHeight != 0)
        heightCounter = leftHeight;

    Tree[currentPointer].balance = rightHeight - leftHeight;

    return heightCounter;
}

void leftRotate(TreeNode *Tree, int currentPointer) {
    int rotateRight = Tree[currentPointer].right;
    int rotateLeft = Tree[currentPointer].left;
    int rotateRightLeft = Tree[Tree[currentPointer].right].left;
    int rotateRightRight = Tree[Tree[currentPointer].right].right;

    swap(Tree[currentPointer], Tree[Tree[currentPointer].right]);

    Tree[currentPointer].left = rotateRight;
    Tree[currentPointer].right = rotateRightRight;
    Tree[Tree[currentPointer].left].right = rotateRightLeft;
    Tree[Tree[currentPointer].left].left = rotateLeft;
}

void rightRotate(TreeNode *Tree, int currentPointer) {
    int rotateLeft = Tree[currentPointer].left;
    int rotateRight = Tree[currentPointer].right;
    int rotateLeftRight = Tree[Tree[currentPointer].left].right;
    int rotateLeftLeft = Tree[Tree[currentPointer].left].left;

    swap(Tree[currentPointer], Tree[Tree[currentPointer].left]);

    Tree[currentPointer].right = rotateLeft;
    Tree[currentPointer].left = rotateLeftLeft;
    Tree[Tree[currentPointer].right].left = rotateLeftRight;
    Tree[Tree[currentPointer].right].right = rotateRight;
}

void bigLeftRotate(TreeNode *Tree, int currentPointer) {
    rightRotate(Tree, Tree[currentPointer].right);
    leftRotate(Tree, currentPointer);
}

int j=1;
void newArray(TreeNode *Tree, TreeNode new_array[], int index) {
    
    new_array[j] = Tree[index];
    int m=j;
    j++;

    if (Tree[index].left != 0) {
        new_array[m].left = j;
        newArray(Tree, new_array, Tree[index].left);
    }
    if (Tree[index].right != 0) {
        new_array[m].right = j;
        newArray(Tree, new_array, Tree[index].right);
    }
}

int main() {
    int count;

    ifstream fileInput("rotation.in");
    ofstream fileOutput("rotation.out");

    fileInput >> count;

    if (count == 0 || count == 1) {
        fileOutput << "0";
        return 0;
    }

    TreeNode *Tree = new TreeNode[count + 1];

    for (int i = 1; i < count + 1; i++) {
        fileInput >> Tree[i].key;
        fileInput >> Tree[i].left;
        fileInput >> Tree[i].right;
    }

    TreeBalance(Tree, 1, 1);

    if (Tree[Tree[1].right].balance == -1)
        bigLeftRotate(Tree, 1);
    else
        leftRotate(Tree, 1);

    fileOutput << count << endl;

    TreeNode BalancedTree[count + 1];

    newArray(Tree, BalancedTree, 1);

    for (int i = 1; i < count + 1; i++) {
        fileOutput << BalancedTree[i].key << ' ';
        fileOutput << BalancedTree[i].left << ' ';
        fileOutput << BalancedTree[i].right << endl;
    }

    return 0;
}