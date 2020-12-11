#ifndef _BST_H_
#define _BST_H_
/*
This implementation of a binary search tree was found on the internet.
Sources can be found here:
  https://stackoverflow.com/questions/5085091/binary-search-tree-implementation-in-c-stl
  https://www.techiedelight.com/print-nodes-binary-tree-specific-order/

*/
#include <queue>
using namespace std;
// Basic structure for our tree nodes
struct Node {
   int key;
   Node* left;
   Node* right;
};

// Create a new tree node
Node* createNewNode(int x)
{
    Node* nn = new Node;
    nn->key = x;
    nn->left  = nullptr;
    nn->right = nullptr;

    return nn;
}

// Insert the value into our BST
void bstInsert(Node* &root, int x)
{
    if(root == nullptr) {
        root = createNewNode(x);
        return;
    }

    if(x < root->key)
    {
        if(root->left == nullptr) {
            root->left = createNewNode(x);
            return;
        } else {
            bstInsert(root->left, x);
        }
    }

    if( x > root->key )
    {
        if(root->right == nullptr) {
            root->right = createNewNode(x);
            return;
        } else {
            bstInsert(root->right, x);
        }
    }
}

void inorder(Node *root) {
  if (root != NULL) {
    inorder(root->left);
    cout << root->key << endl;
    inorder(root->right);
  }
}

#endif //BST_H_
