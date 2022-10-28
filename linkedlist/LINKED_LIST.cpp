// All POSSIBLY BASIC OPERATIONS RELATED TO SINGLY LINKED LIST ONLY
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<stack>
#include <conio.h>
#include <malloc.h>


using namespace std;
struct node {
int data;
node *next;
};


void  display (struct node *start);
struct node *  Sort_LL (struct node *start);
struct node *  Delete_LL (struct node *start);
struct node *  Insert_beg (struct node *start);
struct node *  Insert_end (struct node *start);
struct node *  Delete_beg (struct node *start);
struct node *  Delete_end (struct node *start);
struct node *  Insert_bef (struct node *start);
struct node *  Insert_aft (struct node *start);
struct node *  Delete_bef (struct node *start);
struct node *  Delete_aft (struct node *start);
struct node *  Reverse_LL (struct node *start);
struct node *  Reverse_LL_IT (struct node *start);
struct node *  Reverse_LL_STACK (struct node *start);



 int main(){
    struct node *start;
    int ch;
    start=new node(); //OR start= (struct node*) malloc (sizeof(node));
    start=NULL;
    while(1){
    cout<<"\n1. Insert LL @ beginning\n2. Insert LL @ end\n3. Delete LL @ beginning\n4. Delete LL @ end\n5. Insert LL before given node\n6. Insert LL after given node\n7. Delete LL before given node\n8. Delete LL after given node\n9.Display LL\n10.Delete LL\n11.  Sort LL\n12.ReverseLL\n13.Exit\n";
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch){
        case 1:{
            start=Insert_beg(start);
        }break;
        case 2:{
            start=Insert_end(start);
        }break;
        case 3:{
            start=Delete_beg(start);
        }break;
        case 4:{
            start=Delete_end(start);
        }break;
        case 9:{
            display(start);
        }break;
        case 5:{
            start=Insert_bef(start);
        }break;
        case 6:{
            start=Insert_aft(start);
        }break;
        case 7:{
            start=Delete_bef(start);
        }break;
         case 8:{
            start=Delete_aft(start);
        }break;
        case 11:{
            start=Sort_LL(start);
        }break;
        case 10:{
            start=Delete_LL(start);
        }break;
        case 12: {
            start=Reverse_LL(start);
        }break;
        case 13: exit(0);
        }
    if(ch==13){
        exit(0);
        }
    }
    return 0;
 }



 struct node* Insert_beg(struct node *start){
    struct  node *newnode;
    int val;
    cout<<"Enter data: ";
    cin>>val;
    newnode=new node();
    newnode->data=val;   //OR  (*newnode).data=val;
    if(start==NULL){
        newnode->next=NULL;
        start=newnode;
    }
    else{
        newnode->next=start;
        start=newnode;
    }
return start;
}

struct node* Insert_bef(struct node* start){
    struct node *newnode;
    newnode=new node();
    int val;
    cout<<"Enter value to be inserted: ";
    cin>>val;
    newnode->data=val;
    struct node *ptr=start;
    cout<<"Enter value before which you want to insert: ";
    int num;
    cin>>num;
    struct node *pptr;
    while(ptr->data!=num){
        pptr=ptr;
        ptr=ptr->next;
        }
    pptr->next=newnode;
    newnode->next=ptr;
    return start;
}


struct node* Insert_aft(struct node* start){
    struct node *newnode;
    newnode=new node();
    int val;
    cout<<"Enter value to be inserted: ";
    cin>>val;
    newnode->data=val;
    struct node *ptr=start;
    cout<<"Enter value after which you want to insert: ";
    int num;
    cin>>num;
    while(ptr->data!=num){
        ptr=ptr->next;
        }
    newnode->next=ptr->next;
    ptr->next=newnode;
    return start;
}


struct node* Insert_end(struct node *start){
    struct  node *newnode, *ptr;
    int val;
    newnode=new node();
    cout<<"Enter data: ";
    cin>>val;
    ptr=start;
    newnode->data=val;   //OR  (*newnode).data=val;
    newnode->next=NULL;
    if(start==NULL){
        start=newnode;
    }
    else{
        while(ptr->next!=NULL){
        ptr=ptr->next;
        }
        ptr->next=newnode;
    }
return start;
}

void display(node *start){
    struct node *newnode;
    cout<<"\nLinked List is: \n************************************************************************\n";
    if(start==NULL){
        cout<<"LinkedList is empty\n";
        return;
    }
    while(start!=NULL){
     cout<<"| "<<start->data<<" |--->";
     start=start->next;
    }
    cout<<"NULL\n***********************************************************************\n";
}

struct node* Delete_beg(struct node *start){
    struct  node *ptr;
    ptr=start;
    if(start==NULL){
        cout<<"LL is empty\n";
        return start;
    }
    start=start->next;
    free(ptr);
return start;

}

struct node* Delete_end(struct node *start){
    struct  node *ptr,*pptr;
    ptr=start;
    if(start==NULL){
        cout<<"LL is empty\n";
        return start;
    }
    while(ptr->next!=NULL){
        pptr=ptr;
        ptr=ptr->next;
    }
    pptr->next=NULL;
    free(ptr);
return start;
}


struct node* Delete_LL(struct node* start){
    if(start==NULL){
        cout<<"LL is already Empty";
        return start;
    }
    //since we have to delete each and every node so we can go with delete from beginning or delete from end;
    struct node *ptr=start;
    while(ptr->next!=NULL){
        start=Delete_end(ptr);
        ptr=start;
    }
    ptr=start;
    if(ptr!=NULL){
        start=NULL;
    }
    cout<<"LL deleted\n";
    return start;
}


struct node * Delete_bef(struct node *start){
    struct node *ptr,*pptr;
    ptr=start;
    int num;
    cout<<"Enter value before which you want to delete: ";
    cin>>num;
    if(start==NULL){
        cout<<"LL is empty";
        return start;
    }
    while((ptr->next)->data!=num){
        pptr=ptr;
        ptr=ptr->next;
    }
    pptr->next=ptr->next;
    free(ptr);
    cout<<"LL is sorted\n";
return start;
}


struct node * Delete_aft(struct node *start){
 struct node *ptr,*pptr;
    ptr=start;
    int num;
    cout<<"Enter value after which you want to delete: ";
    cin>>num;
    if(start==NULL){
        cout<<"LL is empty";
        return start;
    }
    pptr=ptr;
    while(pptr->data!=num){
        pptr=ptr;
        ptr=ptr->next;
    }
    pptr->next=ptr->next;
    free(ptr);
return start;
}


struct node* Sort_LL(struct node *start){
  struct node *ptr1, *ptr2;
  ptr1=start;
  ptr2=ptr1;
  while(ptr1->next!=NULL){
        ptr2=ptr1->next;
    while(ptr2!=NULL){
        if(ptr2->data < ptr1->data){
            int temp;
            temp=ptr1->data;
            ptr1->data=ptr2->data;
            ptr2->data=temp;
        }
        ptr2=ptr2->next;
    }
    ptr1=ptr1->next;
  }

return start;
}


struct node * Reverse_LL_STACK(struct node * start){

//3. by using  stack
stack<struct node*>sp;
struct node *ptr=start;
if(start==NULL){
    return NULL;
}
while(ptr!=NULL){
    sp.push(ptr);
    ptr=ptr->next;
}
start=ptr=sp.top();
sp.pop();
while(!sp.empty()){
    ptr->next=sp.top();
    sp.pop();
    ptr=ptr->next;
}
ptr->next=NULL;

return start;
}

struct node * Reverse_LL_IT(struct node *start){

//1. using only node pointer and iterative method
struct node *cptr,*pptr,*nptr;
cptr=start;
pptr=NULL;
while(cptr!=NULL)
{
    nptr=cptr->next;
    cptr->next=pptr;
    pptr=cptr;
    cptr=nptr;
}
start=pptr;
return start;
}


struct node * Reverse_LL(struct node * start){
//actually there are two ways to reverse linked list
//1.iterative method
//2.recursive method
//3.stack

cout<<"1.Reverse using stack method\n2.Reverse using iterative method: ";
int num;
cin>>num;

if(num==1)
    start=Reverse_LL_STACK(start);
else
    start=Reverse_LL_IT(start);


cout<<"Linked List is reversed \n";
return start;
}
