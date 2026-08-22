#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class node
{
public:
    int val;
    node *left;
    node *right;
    node(int val)
    {
        this->val = val;
        left = right = NULL;
    }
};
int idx = -1;

node *buildTree(vector<int> &preOrder)
{
    idx++;
    if (preOrder[idx] == -1)
        return NULL;
    node *curr = new node(preOrder[idx]);

    curr->left = buildTree(preOrder);
    curr->right = buildTree(preOrder);
    return curr;
}

void preOrder(node *root)
{
    if (root == NULL)
        return;

    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

void postOrder(node *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

void levelOrder(node *root)
{
    if (root == NULL)
        return;

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *curr = q.front();
        q.pop();

        if (curr == NULL)
        {
            cout << endl;

            if (q.empty())
            {
                break;
            }
            q.push(NULL);
        }
        else
        {
            cout << curr->val << " ";

            if (curr->left)
            {
                q.push(curr->left);
            }

            if (curr->right)
            {
                q.push(curr->right);
            }
        }
    }
}

int main()
{
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    node *root = buildTree(preorder);
    cout << "Preorder :" << endl;
    preOrder(root);
    cout << endl;
    cout << "inorder :" << endl;
    inOrder(root);
    cout << endl;
    cout << "postorder :" << endl;
    postOrder(root);
    cout << endl;
    cout << "levelorder :" << endl;
    levelOrder(root);
    return 0;
}