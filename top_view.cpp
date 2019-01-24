#include <bits/stdc++.h>
using namespace std;
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
}NODE;
void topView(NODE * root) {
    int max_left=0,max_right=0;//we will keep increasing it in respective direction for the node encountered first  
    //at any level of tree we can't see nodes between these
    deque <int> Top_View;//we push left side nodes to displayed from front end 
    //and right side nodes to displayed from back end
    queue<pair<NODE*,int> > Q;//store pair of NODE and its distance from root 
    //(-ve = left side) and (+ve = right side
    if(root!=NULL)//check if any node is present in tree
    {
        Q.push(make_pair(root,0));//start BFS from 1
        Top_View.push_front(root->data);//left----1----right
    }
    while(!Q.empty())//loop until all nodes have been traversed
    {
        pair<NODE*,int> curr = Q.front();
        Q.pop();//remove 1 instance from front of queue
        int dist_from_root = curr.second;
        NODE* curr_node = curr.first;
        //for BFS
        if(curr_node->left!=NULL)
        {
            Q.push(make_pair(curr_node->left,dist_from_root-1));//we subtracted distance from current 
            //distance from root because for left side distance we are using -ve value ,so we subtract
            // -1 from current distance
        }
        if(curr_node->right!=NULL)
        {
            Q.push(make_pair(curr_node->right,dist_from_root+1));//we addeded distance from current 
            //distance from root because for left side distance we are using +ve value ,so we add
            // +1 from current distance
        }
        if(dist_from_root<max_left)
        {
            Top_View.push_front(curr_node->data);//since left side we push it in front side
            max_left--;//no nodes below this will be considered
        }
        else if(dist_from_root>max_right)
        {
            Top_View.push_back(curr_node->data);//since right side we push it in back side
            max_right++;//no nodes below this will be considered
        }
    }
    while(!Top_View.empty())//pop all element in DEQUEUE from front side to display from left to right
    {
        cout<<Top_View.front()<<" ";
        Top_View.pop_front();
    }
    cout<<endl;
}
int main()
{
    NODE *root=new NODE(1);//assuming root is 1
    root->left = new NODE(2);//left child of 1
    root->right = new NODE(3);//right child of 1
    root->right->left = new NODE(4);
    root->right->left->right = new NODE(5);
    root->right->left->right->right = new NODE(6);
    root->left->right = new NODE(7);
    root->left->right->left = new NODE(8);
    root->left->right->left->left = new NODE(9);
    root->left->right->left->right = new NODE(10);
    root->left->right->left->right->right = new NODE(11);
    root->left->right->left->right->right->right = new NODE(12);
    root->left->right->left->right->right->right->right = new NODE(13);
    root->left->right->left->right->right->right->right->right = new NODE(14);
    topView(root);
    return 0;
}