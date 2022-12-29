#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#define ENDL '\n'

using namespace std;
using ll = long long;

typedef struct _node {
    int data;
    struct _node* left;
    struct _node* right;
}Node;
using BTree = Node*;

BTree makeBTree();
BTree makeBTreeNode(int input);
void makeLeftTree(BTree root, BTree left);
void makeRightTree(BTree root, BTree right);
void preorder(BTree root);

int* InorderSequence;
int* PostorderSequence;

BTree recursiveToMakeBTree(int IStartIDX, int IEndIDX, int PStartIDX, int PEndIDX);

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    BTree Tree = makeBTree();
    int T; cin >> T;
    InorderSequence = new int[T];
    PostorderSequence = new int[T];
    for (int i = 0; i < T; i++) cin >> InorderSequence[i];
    for (int i = 0; i < T; i++) cin >> PostorderSequence[i];
    Tree = recursiveToMakeBTree(0, T - 1, 0, T - 1);
    preorder(Tree);
    return 0;
}

BTree makeBTree() {
    BTree newNode = new Node;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

BTree makeBTreeNode(int input) {
    BTree newNode = new Node;
    newNode->data = input;
    newNode->left = newNode->right = nullptr;
    return newNode;
}
void makeLeftTree(BTree root, BTree left) {
    root->left = left;
}
void makeRightTree(BTree root, BTree right) {
    root->right = right;
}
void preorder(BTree root) {
    if (!root) return;
    cout << root->data << ' ';
    preorder(root->left);
    preorder(root->right);
}
BTree recursiveToMakeBTree(int IStartIDX, int IEndIDX, int PStartIDX, int PEndIDX) {
    if (IStartIDX > IEndIDX) return nullptr;
    int rootValue = PostorderSequence[PEndIDX];
    BTree tree = makeBTreeNode(rootValue);
    if (IStartIDX == IEndIDX) return tree;

    int findIDX, howManyLeft;
    for (findIDX = IStartIDX; ; findIDX++) {
        if (InorderSequence[findIDX] == rootValue) break;
    }
    howManyLeft = findIDX - IStartIDX;
    tree->left = recursiveToMakeBTree(IStartIDX, findIDX - 1, PStartIDX, PStartIDX + howManyLeft - 1);
    tree->right = recursiveToMakeBTree(findIDX + 1, IEndIDX, PStartIDX + howManyLeft, PEndIDX - 1);
    return tree;
}
