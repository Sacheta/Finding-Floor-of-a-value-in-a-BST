//program for simple execution of a function to find the Floor of a value in a BST
#include<iostream>
#include<climits>
using namespace std;

class node{  //node class
public:
    int data;
    node* right;
    node* left;

node(int n){  //paramerterized constructor
    data=n;
    right=nullptr;
    left=nullptr;
}

node(){  //default constructor
    data=0;
    right=nullptr;
    left=nullptr;
}

node *insertn(node *root,int h){  //recursive function to insert an element
    if(root==nullptr)  //when root is NULL
        return new node(h);
    if(root->data==h){  //if root->data matches the value to be inserted
        cout<<"Already present!"<<endl;
        return root;
    }
    if(root->data<h)  //if root->data is less than h, value is to inserted in right subtree
        root->right=insertn(root->right,h);
    if(root->data>h)  //if root->data is greater than h, value is to inserted in left subtree
        root->left=insertn(root->left,h);

    return root;
}

void inorder(node* root){  //recursive function to traverse tree in inorder fashion
    if(root==nullptr)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node* root){   //recursive function to traverse tree in preorder fashion
    if(root==nullptr)
        return;
    cout<<root->data<<" ";
    inorder(root->left);
    inorder(root->right);
}

void postorder(node* root){    //recursive function to traverse tree in postorder fashion
    if(root==nullptr)
        return;
    inorder(root->left);
    inorder(root->right);
    cout<<root->data<<" ";
}

void floor(node*,int);

};

void node::floor(node* root,int n){  //function to find the floor of a value in a given BST
    if(root==nullptr){  //if tree's empty
        cout<<"Empty tree!"<<endl;
        return;
    }
    int res=INT_MIN;  //assigning the minimum possible value to int
    while(root!=nullptr){  //until we don't get to end of the tree
        if(root->data==n){  //if root has the required value
            cout<<root->data<<endl;
            return;
        }
        else if(root->data>n)  //if value can be found in left subtree
            root=root->left;
        else{
            res=root->data;  //if more closer value to the value required, can be foud
            root=root->right;
        }
    }
    cout<<res<<endl;  //display the res
}

int main(){
    cout<<"Make selection: "<<endl;
    node* root=nullptr;
    cout<<"1. Insert a node"<<endl;
    cout<<"2. Display inorder"<<endl;
    cout<<"3. Display preorder"<<endl;
    cout<<"4. Display postorder"<<endl;
    cout<<"5. Display floor of an element"<<endl;

    int n;
    while(cin>>n){
        switch(n){
        case 1:
            cout<<"Enter value to be inserted: ";
            int h;
            cin>>h;
            root=root->insertn(root,h);
            break;
        case 2:
            if(root==nullptr)
                cout<<"Empty!";
            else root->inorder(root);
            cout<<endl;
            break;
        case 3:
            if(root==nullptr)
                cout<<"Empty!";
            else
            root->preorder(root);
            cout<<endl;
            break;
        case 4:
            if(root==nullptr)
                cout<<"Empty!";
            else
            root->postorder(root);
            cout<<endl;
            break;
        case 5:
            int a;
            cout<<"Enter value: ";
            cin>>a;
            root->floor(root,a);
            break;
        default:
            cout<<"Invalid Input!"<<endl;

        }
    }

}
