/*
<aside>
💡 Question-1:

Given preorder of a binary tree, calculate its **[depth(or height)](https://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/)** [starting from depth 0]. The preorder is given as a string with two possible characters.

1. ‘l’ denotes the leaf
2. ‘n’ denotes internal node

The given tree can be seen as a full binary tree where every node has 0 or two children. The two children of a node can ‘n’ or ‘l’ or mix of both.

**Examples :**

Input  : nlnll
Output : 2
Explanation :

</aside>
*/
#include <bits/stdc++.h>
using namespace std;

int findDepthRec(char tree[], int n, int& index)
{
    if (index >= n || tree[index] == 'l')
        return 0;
    index++;
    int left = findDepthRec(tree, n, index);
 
    index++;
    int right = findDepthRec(tree, n, index);
 
    return max(left, right) + 1;
}
 

int findDepth(char tree[], int n)
{
    int index = 0;
    return findDepthRec(tree, n, index);
}


/*
<aside>
💡 Question-2:

Given a Binary tree, the task is to print the **left view** of the Binary Tree. The left view of a Binary Tree is a set of leftmost nodes for every level.

**Examples:**

***Input:***

            4

          /   \

        5     2

             /   \

            3     1

           /  \

          6    7

***Output:** 4 5 3 6*

</aside>
*/

#include<bits/stdc++.h>
using namespace std;
 
// A Binary Tree Node
struct Node
{
    int data;
    struct Node *left, *right;
};
 
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 

void printLeftView(Node* root)
{
    if (!root)
        return;
 
    queue<Node*> q;
    q.push(root);
 
    while (!q.empty())
    {    

        int n = q.size();
         
        
        for(int i = 1; i <= n; i++)
        {
            Node* temp = q.front();
            q.pop();
                 

            if (i == 1)
                cout<<temp->data<<" ";
             

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
} 


/*
<aside>
💡 Question-3:

Given a Binary Tree, print the Right view of it.

The right view of a Binary Tree is a set of nodes visible when the tree is visited from the Right side.

**Examples:**

**Input:**

         1

      /     \

   2         3

/   \       /  \

4     5   6    7

             \

               8

**Output**: 

Right view of the tree is 1 3 7 8

**Input:**

         1

       /

    8

  /

7

**Output**: 

Right view of the tree is 1 8 7

</aside>
*/
void printRightView(Node* root)
{
    if (root == NULL)
        return;
 
    queue<Node*> q;
    q.push(root);
 
    while (!q.empty()) {
        
        int n = q.size();
 
        
        while (n--) {
 
            Node* x = q.front();
            q.pop();
 
            
            if (n == 0) {
                cout << x->data << " ";
            }
    
            if (x->left)
                q.push(x->left);
            if (x->right)
                q.push(x->right);
        }
    }
}



/*

<aside>
💡 Question-4:

Given a Binary Tree, The task is to print the **bottom view** from left to right. A node **x** is there in output if x is the bottommost node at its horizontal distance. The horizontal distance of the left child of a node x is equal to a horizontal distance of x minus 1, and that of a right child is the horizontal distance of x plus 1.

**Examples:**

**Input:**

             20

           /     \

        8         22

    /      \         \

5         3        25

        /    \

   10       14

**Output:** 5, 10, 3, 14, 25.

**Input:**

             20

           /     \

        8         22

    /      \      /   \

 5         3    4     25

         /    \

     10       14

**Output:**

5 10 4 14 25.

**Explanation:**

If there are multiple bottom-most nodes for a horizontal distance from the root, then print the later one in the level traversal.

**3 and 4** are both the bottom-most nodes at a horizontal distance of 0, we need to print 4.

</aside>
*/
struct Node
{
    int data;
    int hd; 
    Node *left, *right; 
 
 
    Node(int key)
    {
        data = key;
        hd = INT_MAX;
        left = right = NULL;
    }
};
void bottomView(Node *root)
{
    if (root == NULL)
        return;
 
    
    int hd = 0;
 
   
    map<int, int> m;
 
    queue<Node *> q;
 
    root->hd = hd;
    q.push(root);  
 
    
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();  
        hd = temp->hd;
 
        m[hd] = temp->data;
 
      
        if (temp->left != NULL)
        {
            temp->left->hd = hd-1;
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            temp->right->hd = hd+1;
            q.push(temp->right);
        }
    }
    for (auto i = m.begin(); i != m.end(); ++i)
        cout << i->second << " ";
}