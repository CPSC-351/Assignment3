#ifndef _BST_H_
#define _BST_H_
/*
This implementation of a binary search tree was found on the internet.
Sources can be found here:
  https://stackoverflow.com/questions/5085091/binary-search-tree-implementation-in-c-stl
  https://www.techiedelight.com/print-nodes-binary-tree-specific-order/

*/

// Basic structure for our tree nodes
struct treeNode {
   int val;
   treeNode* left;
   treeNode* right;
};

// Create a new tree node
treeNode* createNewNode(int x)
{
    treeNode* nn = new treeNode;
    nn->val = x;
    nn->left  = nullptr;
    nn->right = nullptr;

    return nn;
}

// Insert the value into our BST
void bstInsert(treeNode* &root, int x)
{
    if(root == nullptr) {
        root = createNewNode(x);
        return;
    }

    if(x < root->val)
    {
        if(root->left == nullptr) {
            root->left = createNewNode(x);
            return;
        } else {
            bstInsert(root->left, x);
        }
    }

    if( x > root->val )
    {
        if(root->right == nullptr) {
            root->right = createNewNode(x);
            return;
        } else {
            bstInsert(root->right, x);
        }
    }
/*
========================================================================
  The below function was taken and modified from:
    https://www.techiedelight.com/print-nodes-binary-tree-specific-order/
========================================================================
/ Function to print all nodes of a given binary tree in specific
/ order from top to bottom*/
void printTree(Node* root)
    {
    // return is tree is empty
    if (root == nullptr)
        return;

    // print root node
    cout << root->key << " ";

    // create a two empty queues and enqueue root's left and
    // right child respectively
    queue<Node*> q1, q2;
    q1.push(root->left);
    q2.push(root->right);

    // loop till queue is empty
    while (!q1.empty())
    {
      // calculate number of nodes in current level
      int n = q1.size();

      // process every node of current level
      while (n--)
        {
        // pop front node from first queue and print it
          treeNode* x = q1.front();
          q1.pop();

          cout << x->key << " ";

          // push left and right child of x to first queue
            if (x->left)
              q1.push(x->left);

            if (x->right)
              q1.push(x->right);

          // pop front node from second queue and print it
               treeNode* y = q2.front();
               q2.pop();
               cout << y->key << " ";

          // push right and left child of y to second queue
            if (y->right)
                q2.push(y->right);

            if (y->left)
                q2.push(y->left);
            }
        }
    }
}
#endif //BST_H_
