//basic functions related to binary tree
//all traversal
// height of btree,mirror image
//creation of btree
#include<stdio.h>
#include<iostream>
#include <queue>
#define space 10
using namespace std;
struct node {
    int data;
    node *left;
    node *right;
 };


void preorder(struct node *start){
if(start){
    cout<<start->data<<" ";
    preorder(start->left);
    preorder(start->right);
}
}


void inorder(struct node *start){
if(start){
    inorder(start->left);
    cout<<start->data<<" ";
    inorder(start->right);
}
}


void postorder(struct node *start){
if(start){

    postorder(start->left);
    postorder(start->right);
    cout<<start->data<<" ";
}
}


void levelorder(struct node *start){
    queue<struct node *>q;
    q.push(start);
    while(!q.empty()){
        struct node *temp;
        temp=q.front();
        cout<<q.front()->data<<" ";
        q.pop();
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}



void make_tree(struct node* &start)
{
    int val,right,left;
    cout<<"Enter data for current node: ";
    cin>>val;
    start=new node;
    start->data=val;
    cout<<"Enter 1 for left node: ";
    cin>>left;
    if(left ==1 ){
        make_tree(start->left);
    }
    else{
        start->left=NULL;
    }
    cout<<"Enter 1 for right node: ";
    cin>>right;
    if(right ==1 ){
        make_tree(start->right);
    }
    else{
        start->right=NULL;
    }
}


struct node * insert_tree(struct node *start,int value, queue<struct node *>& q){
    struct node *ptr;
    ptr=new node;
    ptr->data=value;
    ptr->left=ptr->right=NULL;
    if(start==NULL){
    start=ptr;
    }

    else if(q.front()->left==NULL){
        q.front()->left=ptr;
    }
    else {
        q.front()->right=ptr;
        q.pop();
    }
    q.push(ptr);
    return start;
}


int height(struct node *start){
    if(start==NULL)
        return 0;
    else{
    int left=height(start->left);
    int right=height(start->right);
    return (1+max(left,right));}
}



void mirror(struct node *start){
    if(start==NULL)
        return;
    else{
        struct node *temp;
        mirror(start->left);
        mirror(start->right);
        temp=start->left;
        start->left=start->right;
        start->right=temp;
    }
}


struct node * create_tree(struct node * start){
    queue<struct node *>q;
    start=NULL;
    int n;
    cout<<"\nNo of node you want to enter: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++){
        start=insert_tree(start,arr[i],q);
    }

return start;
}


struct node* tree(struct node *start){
    make_tree(start);
    return start;
}


void print_tree(struct node *start, int sp)
{
    if (start == NULL)
        return;
    sp += space;
    print_tree(start->right, sp);
    cout<<endl;
    for (int i =space; i < sp; i++)
        cout<<" ";
    cout<<start->data<<"\n";
    print_tree(start->left, sp);
}


void print(struct node *start)
{
  print_tree(start, 0);
}


int main(){
    struct node *start;
    int ch;
    cout<<"Enter tree by: \n1.recursion\n2.level order: ";
    cin>>ch;
    if(ch==1){
    cout<<"Enter tree: by using recursion\n";
    start=tree(start);}
    if(ch==2){
    cout<<"enter tree using level order: ";
    start=create_tree(start);}
    cout<<"\ntree looks like:  \n\n";
    print(start);

    cout<<"\n\nlevel-order traversal: \n";
    levelorder(start);
    cout<<"\npre-order traversal: \n";
    preorder(start);
    cout<<"\nin-order traversal: \n";
    inorder(start);
    cout<<"\npost-order traversal: \n";
    postorder(start);


    cout<<"\nHeight of tree: ";
    int ht=height(start);
    cout<<" "<<ht;

    cout<<"mirror image of binary tree: ";
    mirror(start);

    cout<<" tree looks like:  \n\n";
    print(start);
    cout<<"\nlevel-order traversal: \n";
    levelorder(start);
    return 0;
}
