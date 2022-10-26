#include<iostream>
using namespace std;

class Node
{
    int data;
    Node* lchild;
    Node* rchild;
    bool lbit,rbit;
    public:
    Node(){
        data = 0;
        lchild =rchild = NULL;
        rbit = lbit= 0;
    }
    Node(int x){
        data = x;
        lchild =rchild = NULL;
        rbit = lbit= 0;      
    }
    friend class Threaded_BST;
};

class Threaded_BST
{
    Node* root;
    public:
    Threaded_BST()
    {
        root = NULL;
    }
    void Insert(int k);
    Node* get_root();
    void Traverse_Inorder();
    void Traverse_Preorder();
};

Node* Threaded_BST::get_root()
{
    return root;
}
void Threaded_BST::Insert(int k)
{
    if(root==NULL)
    {
        root = new Node(k);
        return;
    }
    Node* temp = root;
    while(temp!=NULL)
    {
        if(temp->data < k)
        {
            if(temp->rbit == 1)
            {
                temp = temp->rchild;
            }
            else
            {
                Node* new_node = new Node(k);
                new_node->lchild = temp;
                new_node->rchild = temp->rchild;
                temp->rbit = 1;
                temp->rchild = new_node;
                return;
            }
        }
        else if(temp->data > k)
        {
            if(temp->lbit == 1)
            {
                temp = temp->lchild;
            }
            else
            {
                Node* new_node = new Node(k);
                new_node->rchild = temp;
                new_node->lchild = temp->lchild;
                temp->lbit = 1;
                temp->lchild = new_node;
                return;
            }
        }
        else
        {
            cout<<"Entered data is already present"<<endl;
            return;
        }
    }
}

void Threaded_BST::Traverse_Inorder()
{
    if(root==NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    cout<<"Inorder Traversal: ";
    Node* current = root;
    bool flag = 0;
    while(current!=NULL)
    {
        while(current->lbit==1 && flag==0)
        {
            current = current->lchild;
        }
        cout<<current->data<<" ";
        if(current->rbit == 1)
        {
            flag = 0;
        }
        else
        {
            flag = 1; 
        }
        current = current->rchild;

    }
    cout<<endl;
}

void Threaded_BST::Traverse_Preorder()
{
    if(root==NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    cout<<"Preorder Traversal: ";
    Node* temp = root;
    bool flag = 0;
    while(temp!=NULL)
    {
        while(temp->lbit==1 && flag==0)
        {
            cout<<temp->data<<" ";
            temp = temp->lchild;
        }
        if(flag==0)
        {
            cout<<temp->data<<" ";
        }
        if(temp->rbit==1)
        {
            flag = 0;   
        }
        else
        {
            flag = 1;
        }
        temp = temp->rchild;
    }
    cout<<endl;
}

int main()
{
    Threaded_BST T;
    cout<<"Enter the number of elements in tree: ";
    int n;
    cin>>n;
    while(n--)
    {
        int data;
        cout<<"Enter the data: ";
        cin>>data;
        T.Insert(data);
    }
    cout<<"Do you want to print elements(y/n): ";
    char c;
    cin>>c;
    if(c=='y')
    {
        T.Traverse_Inorder();
        T.Traverse_Preorder();
    }
    return 0;
}
