#include<iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode* build(TreeNode* root)
{
    int data;

    cout << "Enter data (-1 for NULL): ";
    cin >> data;

    if(data == -1)
        return NULL;

    root = new TreeNode(data);

    cout << "Enter left child of " << data << endl;
    root->left = build(root->left);

    cout << "Enter right child of " << data << endl;
    root->right = build(root->right);

    return root;
}

void inorder(TreeNode* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    TreeNode* root = NULL;

    root = build(root);

    cout << "\nInorder Traversal: ";
    inorder(root);

    return 0;
}