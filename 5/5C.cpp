#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("bstsimple.in");
ofstream fout("bstsimple.out");

struct BinTree {
    BinTree* lC=nullptr;
    BinTree* rC=nullptr;
    int data=NULL;
};

BinTree* insert(BinTree* node, int value) {
    if (node == nullptr) {
        BinTree * newNode = new BinTree;
        newNode->data = value;
        return newNode;
    }
    else if (value < node->data) {
        node->lC = insert(node->lC, value);
    }
    else if (value > node->data) {
        node->rC = insert(node->rC, value);
    }
    return node;
}

BinTree* minimum(BinTree* node) {
    if (node->lC == nullptr) {
        return node;
    }
    return minimum(node->lC);
}

BinTree* delete_func(BinTree* node, int needed_value) {
    if (node == nullptr) {
        return node;
    }
    if (needed_value < node->data) {
        node->lC = delete_func(node->lC, needed_value);
    }
    else if (needed_value > node->data) {
        node->rC = delete_func(node->rC, needed_value);
    }
    else if (node->lC != NULL && node->rC != NULL) {
        node->data = minimum(node->rC)->data;
        node->rC = delete_func(node->rC, node->data);
    }
    else {
        if (node->lC != NULL) {
            node = node->lC;
        }
        else if (node->rC != NULL) {
            node = node->rC;
        }
        else {
            node = NULL;
        }
    }
    return node;
}

BinTree* exists(BinTree* node, int needed_element) {
    if (node == nullptr or needed_element == node->data)
        return node;
    if (needed_element < node->data) {
        return exists(node->lC, needed_element);
    }
    else {
        return exists(node->rC, needed_element);
    }
}

BinTree* next(BinTree* node,int needed_value) {
    BinTree* current = node;
    BinTree* successor = nullptr;
    while (current != nullptr) {
        if (current->data > needed_value) {
            successor = current;
            current = current->lC;
        }
        else {
            current = current->rC;
        }
    }
    return successor;
}

BinTree* prev(BinTree* node, int needed_value) {
    BinTree* current = node;
    BinTree* successor = nullptr;
    while (current != nullptr) {
        if (current->data <needed_value) {
            successor = current;
            current = current->rC;
        }
        else {
            current = current->lC;
        }
    }
    return successor;
}

void inorder_traversal(BinTree* node) {
    if (node != nullptr) {
        inorder_traversal(node->lC);
        fout << node->data;
        inorder_traversal(node->rC);
    }
}

int main() {
    string command_string;
    int data;
    BinTree* Tree = nullptr;
    while (fin >> command_string) {
        fin >> data;
        if (command_string == "insert") {
            Tree = insert(Tree, data);
        }
        if (command_string == "exists") {
            if (exists(Tree, data) == nullptr) {
                fout << "false" << endl;
            }
            else {
                fout << "true" << endl;
            }
        }
        if (command_string == "next") {
            BinTree* NewNextNode = next(Tree, data);
            if (NewNextNode == nullptr) {
                fout << "none" << endl;
            }
            else {
                fout << NewNextNode->data << endl;
            }

        }
        if (command_string == "prev") {
            BinTree* NewPrevNode = prev(Tree, data);
            if (NewPrevNode == nullptr) {
                fout << "none" << endl;
            }
            else {
                fout << NewPrevNode->data<< endl;
            }
        }
        if (command_string == "delete") {
            Tree = delete_func(Tree, data);
        }
    }
    return 0;
}


