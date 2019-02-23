#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
    int data;
    struct Node *left,*right;
    Node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
}Node;
bool checkBST2(Node*root ,int low,int high)
{
    if(root->data<=low||root->data>=high)
        return false;
    bool left=true,right=true;
    if(root->left)
        left=checkBST2(root->left,low,root->data);
    if(root->right)
        right=checkBST2(root->right,root->data,high);
    return (left&&right);    
        
}
bool checkBST(Node* root)
{
    if(root==NULL)
        return true;
    return checkBST2(root,-2147483648,2147483647);
}
int main()
{
    Node *root=new Node(4);
    root->left=new Node(2);
    root->left->left=new Node(1);
    root->left->right= new Node(3);
    root->right=new Node(6);
    root->right->left  = new Node(5);
    root->right->right = new Node(7);
    cout<<(checkBST(root)?"Yes":"No")<<endl;
    return 0;
}