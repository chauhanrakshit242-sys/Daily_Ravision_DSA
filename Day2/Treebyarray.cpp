#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* buildArray(vector<int>& arr, int index)
{
    if(index >= arr.size())
        return NULL;

    Node* root = new Node(arr[index]);

    root->left = buildArray(arr, 2 * index + 1);
    root->right = buildArray(arr, 2 * index + 2);

    return root;
}

void inorder(Node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements of array: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Node* root = buildArray(arr, 0);

    cout << "\nInorder Traversal: ";
    inorder(root);

    return 0;
}