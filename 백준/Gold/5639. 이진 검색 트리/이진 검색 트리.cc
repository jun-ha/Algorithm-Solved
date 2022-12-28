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
using BSTree = Node*;

BSTree makeBSTreeNode(int input);
void BSTInsert(BSTree* root, int input);
void postorder(BSTree root);

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    BSTree Tree = nullptr;
    int num;
    while (cin >> num) {
        BSTInsert(&Tree, num);
    }
    postorder(Tree);
	return 0;
}

BSTree makeBSTreeNode(int input) {
    BSTree newNode = new Node;
    newNode->data = input;
    newNode->left = newNode->right = nullptr;
    return newNode;
}
void BSTInsert(BSTree* root, int input) {
    BSTree newNode = makeBSTreeNode(input);
    if (!(*root)) {
        *root = newNode;
        return;
    }

    BSTree parent = *root;
    BSTree child = *root;
    while (child) {
        parent = child;
        if (child->data < input) child = child->right;
        else child = child->left;
    }
    if (parent->data < input) parent->right = newNode;
    else parent->left = newNode;
}
void postorder(BSTree root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << ENDL;
}
