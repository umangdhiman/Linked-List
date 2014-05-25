#include<iostream>  //for cout,cin
#include<stdlib.h>  //for exit function
using namespace std;
struct node{
    int info;
    struct node *next;
}*ls; //structure variable
class link{
    int x;
    public:
    void insert_node(){
        cout<<"Enter no. to insert\n";
        cin>>x;
        struct node *p,*r,*s;   //structure variables
        p=new(struct node );    //memory allocation for node
        p->info=x;      //insert the data
        p->next=NULL;   //p is the node to be inserted
        if(ls==NULL)    //empty list
            ls=p;   //initialize list
        else{
            r=s=ls;
            while(r!=NULL&&r->info<x){  //to keep the list sorted for better efficiency
                s=r;
                r=r->next;  //r remains ahead of s
            }
            if(r==s){   //node to be inserted at first position
                p->next=ls;
                ls=p;
            }
            else if(r==NULL) //node to be inserted at the end of the list
                s->next=p;
            else{   //node to be inserted the list in-between
                s->next=p;
                p->next=r;
            }
        }
    }
    void delete_node(){
        cout<<"Enter no. to delete\n";
        cin>>x;
        struct node *r,*s;  //structure variables
        r=s=ls;
        while(r!=NULL&&r->info!=x){     //locate the node to be deleted
            s=r;
            r=r->next;
        }
        if(r==NULL)     //end of list reached
            cout<<"Item not found\n";
        else{
            if(r==s)    //1st node to be deleted
                ls=r->next;
            else
                s->next=r->next;
        }
    }
    void show_list(){
        struct node *r,*s;   //structure variables
        r=s=ls;
        while(r!=NULL){  //while end of list not reached
            cout<<r->info<<"\t";
            s=r;
            r=r->next;
        }
        cout<<"\n";
    }
}l;
int main(){
    int choice;
    while(1){ //loop true until exit not encountered
        cout<<"Enter 1 to insert, 2 to delete, 3 to show, 4 to exit\n";
        cin>>choice;
        switch(choice){
        case 1:
            l.insert_node(); //insert function called
            break;
        case 2:
            l.delete_node(); //delete function called
            break;
        case 3:
            l.show_list(); //show function called
            break;
        case 4:
            exit(0); //exit function called
        }
    }
    return 0;
}

