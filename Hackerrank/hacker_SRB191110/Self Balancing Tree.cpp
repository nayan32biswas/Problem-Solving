#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int val;
    struct node *left;
    struct node *right;
    int ht;
} node;

int height(node *root)
{
    if (root)
        return (1 + max(height(root->left), height(root->right)));
    return -1;
}
void up_height(node *root)
{
    if (root)
        root->ht = (1 + max(height(root->left), height(root->right)));
}
node *update_left(node *root)
{
    node *right = root->right;
    node *left = right->left;
    root->right = left;
    right->left = root;
    up_height(right);
    up_height(root);
    return right;
}
node *update_right(node *root)
{
    node *left = root->left;
    root->left = left->right;
    left->right = root;
    up_height(left);
    up_height(root);
    return left;
}
node *insert(node *root, int val)
{
    if (!root)
    {
        root = new node;
        root->val = val;
        root->ht = 0;
        root->left = root->right = nullptr;
        return root;
    }
    if (root->val < val)
        root->right = insert(root->right, val);
    else if (root->val > val)
        root->left = insert(root->left, val);
    up_height(root);
    int bal = height(root->left) - height(root->right);
    if (bal < -1 and val > root->right->val)
        root = update_left(root);
    if (bal > 1 and val < root->left->val)
        root = update_right(root);
    if (bal < -1 and val < root->right->val)
    {
        root->right = update_right(root->right);
        root = update_left(root);
    }
    if (bal > 1 and val > root->left->val)
    {
        root->left = update_left(root->left);
        root = update_right(root);
    }
    return root;
}