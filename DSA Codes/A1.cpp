#include<iostream>
using namespace std;

class Node
{
        int data;
        Node* lChild;
        Node* rChild;
        public:
        Node()
        {
                data=0;
                lChild=NULL;
                rChild=NULL;
        }
        Node(int x)
        {
                data=x;
                lChild=NULL;
                rChild=NULL;
        }
        friend class Tree;
        friend class My_Stack;
};

class My_Stack
{
        int top;
        Node* s[20];
        public:
        My_Stack()
        {
                top=-1;
        }
        void push(Node*);
        Node* pop();
        bool empty();
        friend class Tree;
};

bool My_Stack::empty()
{
        if(top==-1)
                return true;
        else
                return false;
}

void My_Stack::push(Node* p)
{
        if (top==19)
        {
                cout<<"\nStack is FULL";
        }
        else
        {
                top++;
                s[top]=p;
        }
}

Node* My_Stack::pop()
{
        Node* x;
        if(top == -1)
        {
                cout<<"\nStack is empty";
        }
        else
        {
                x=s[top];
                top--;
                return x;
        }
}

class Tree
{
        Node* root;
        public:

        Tree()
        {
                root=NULL;
        }
        Node* insert(int,Node*);
        void create(int);
        void demoInsert(int);
        void recursive();
        void nonRecursive();
        void postOrder(Node*);
        void preOrder(Node*);
        void inOrder(Node*);
        void N_postOrder(Node*);
        void N_preOrder(Node*);
        void N_inOrder(Node*);
        Node* copyTree(Node*);
        Node* mirrorTree(Node*);
        void deleteTree(Node*);
        void operations(int,Tree);
        void operator=(Tree&);
        void nodeCount(Node*,int&,int&);
        int height(Node*);
};

void Tree::operator=(Tree& t1)
{
        root=copyTree(t1.root);
        cout<<"\nt="<<t1.root;
        cout<<"\nt1="<<root<<endl;
}

void Tree::create(int ele)
{
        Node* node;
        if(root==NULL)
        {
                node=new Node(ele);
                root=node;
        }
        else
        {
                cout<<"\nTree root node is already created so calling insert function.\n";
                insert(ele,root);
        }
}

void Tree::demoInsert(int d)
{
        insert(d,root);
}

void Tree::operations(int c, Tree t)
{
        switch (c)
        {
                case 1:
                        cout<<"\nMirror Tree is:";
                        root=mirrorTree(t.root);
                        break;
                case 2:
                        deleteTree(root);
                        break;
                case 3:
                {
                        int i=0,l=0;
                        nodeCount(root,i,l);
                        cout<<"\nInteral Node Count is "<<i;
                        cout<<"\nLeaf Node Count is "<<l;
                        break;
                }
                case 4:
                {
                        int h=0;
                        h=height(root);
                        cout<<"\nHeight of Tree is "<<h;
                        break;
                }
                case 5:
                {
                        recursive();
                        nonRecursive();
                        break;
                }
        }
}

Node* Tree::insert(int d,Node* node)
{
        char side;
        if(node==NULL)
        {
                node=new Node(d);
        }
        else
        {
                cout<<"\nEnter side in which you want to insert element left or right of ("<<node->data<<") (l/r):";
                cin>>side;
                if(side=='r')
                {
                        node->rChild=insert(d,node->rChild);
                }
                else if(side=='l')
                {
                        node->lChild=insert(d,node->lChild);
                }
        }
        return node;
}

void Tree::recursive()
{
        cout<<"\n----**Recursive Traversal**----\n";
        if(root==NULL)
        {
                cout<<"\nTree is EMPTY!!!";
                return;
        }
        
        cout<<"Inorder :";
        inOrder(root);
        cout<<"\nPreorder :";
        preOrder(root);
        cout<<"\nPostorder :";
        postOrder(root);
}

void Tree::postOrder(Node* node)
{
        if(node==NULL)
        {return;}
        postOrder(node->lChild);
        postOrder(node->rChild);
        cout<<"\t"<<node->data;
}

void Tree::preOrder(Node* node)
{
        if(node==NULL)
        {return;}
        cout<<"\t"<<node->data;
        preOrder(node->lChild);
        preOrder(node->rChild);
}

void Tree::inOrder(Node* node)
{
        if(node==NULL)
        {return;}
        inOrder(node->lChild);
        cout<<"\t"<<node->data;
        inOrder(node->rChild);
}

void Tree::nonRecursive()
{
        cout<<"\n----**Non-Recursive Traversal**----\n";
        if(root==NULL)
        {
                cout<<"\nTree is EMPTY!!!";
                return;
        }
        
        cout<<"Inorder :";
        N_inOrder(root);
        cout<<"\nPreorder :";
        N_preOrder(root);
        cout<<"\nPostorder :";
        N_postOrder(root);
}

void Tree::N_postOrder(Node* node)
{
        Node* temp,*p;
        temp= new Node('#');
        My_Stack st;
        bool flag=false;
        while(flag==false)
        {
                while(node!=NULL)
                {
                        st.push(node);
                        if(node->rChild!=NULL)
                        {
                                st.push(node->rChild);
                                st.push(temp);
                        }
                        node=node->lChild;
                }
                if(st.empty())
                  flag=true;
                else
                {
                        p=st.pop();
                }
                while (p!=temp&&!st.empty())
                {
                        cout<<"\t"<<p->data;
                }
                if (!st.empty())
                {
                        node=st.pop();
                }
        }
        cout<<"\t"<<p->data;
}

void Tree::N_preOrder(Node* node)
{
        My_Stack st;
        bool flag=false;
        while(flag==false)
        {
                while (node!=NULL)
                {
                        cout<<"\t"<<node->data;
                        if (node->rChild!=NULL)
                        {
                                st.push(node->rChild);
                        }
                        node=node->lChild;
                }
                if (st.empty())
                  flag=true;
                else
                {
                        node=st.pop();
                }

        }
}

void Tree::N_inOrder(Node* node)
{
        My_Stack st;
        bool flag=false;
        while(flag==false)
        {
                while (node!=NULL)
                {
                        st.push(node);
                        node=node->lChild;
                }
                if(st.empty())
                  flag=true;  
                else
                {
                        node=st.pop();
                        cout<<"\t"<<node->data;
                        node=node->rChild;
                }
        }

}

Node* Tree::copyTree(Node* n)
{
        Node* node=NULL;
        if(n!=NULL)
        {
                node=new Node(n->data);
                node->lChild=copyTree(n->lChild);
                node->rChild=copyTree(n->rChild);
        }
        return node;
}

Node* Tree::mirrorTree(Node* n)
{
        Node* temp=NULL;
        Node* p=n;
        if(n!=NULL)
        {
                mirrorTree(p->lChild);
                mirrorTree(p->rChild);
                temp=p->lChild;
                p->lChild=p->rChild;
                p->rChild=temp;
        }
}

void Tree::nodeCount(Node* r,int& ic,int& lc)
{
        if(r!=NULL)
        {
                if(r->lChild || r->rChild)
                        ic++;
                else if(r->lChild==NULL && r->rChild==NULL)
                        lc++;
                nodeCount(r->lChild,ic,lc);
                nodeCount(r->rChild,ic,lc);
        }
}

int Tree::height(Node* n)
{
        int h1,h2;
        if(n==NULL)
                return 0;
        if(n->lChild==NULL && n->rChild==NULL)
                return 0;
        h1 = height(n->lChild);
        h2 = height(n->rChild);
        if(h1>h2)
                return h1+1;
        else
                return h2+1;
}

void Tree::deleteTree(Node* n)
{
        if(n!=NULL)
        {
                deleteTree(n->lChild);
                deleteTree(n->rChild);
                delete n;
        }
        root=NULL;
}

int main()
{
        Tree t,t1,t2;
        int choice,e;
        char ch,s;
        do
        {
                cout<<"\n1.Create Tree.";
                cout<<"\n2.Insert.";
                cout<<"\n3.Traversal.";
                cout<<"\n4.Copy Tree.";
                cout<<"\n5.Mirroring Tree.";
                cout<<"\n6.Count Leaf Nodes of Tree.";
                cout<<"\n7.Height of Tree.";
                cout<<"\n8.Delete Tree.";
                cout<<"\n0.Exit";
                cout<<"\n\nEnter your choice:";
                cin>>choice;
                switch (choice)
                {
                case 1:
                        cout<<"\nEnter root node element:";
                        cin>>e;
                        t.create(e);
                        break;

                case 2:
                        cout<<"\nEnter element:";
                        cin>>e;
                        t.demoInsert(e);
                        break;

                case 3:
                        t.operations(5,t);
                        break;

                case 4:
                        t1=t;
                        t1.operations(5,t); 
                        break;

                case 5:
                        t2.operations(1,t);
                        t2.operations(5,t);
                        break;

                case 6:
                        t.operations(3,t);
                        break;

                case 7:
                        t.operations(4,t);
                        break;
                        
                case 8:
                {
                        char ch;
                        bool flag=false;
                        while(flag==false)
                        {
                        cout<<"\nA.Delete Original Tree.\nB.Delete Copy Tree.\nC.Delete Mirror Tree.\n\nEnter your choice: ";
                        cin>>ch;
                        if(ch=='A' || ch=='a')
                        {
                                t.operations(2,t);
                                flag=true;
                        }
                        else if(ch=='B' || ch=='b')
                        {
                                t1.operations(2,t1);
                                flag=true;
                        }
                        else if(ch=='C' || ch=='c')
                        {
                                t2.operations(2,t2);
                                flag=true;
                        }
                        else
                                cout<<"\nWrong Choice...Try Again...";
                        }
                        
                        cout<<"\nTree deleted successfully.";
                        break;
                }

                case 0:
                        return 0;

                default:
                        cout<<"WRONG CHOICE!!!!\n";
                        break;
                }

                cout<<"\nDo you want to continue?(y/n): ";
                cin>>ch;
        }while(ch!='n');

        return 0;
}
