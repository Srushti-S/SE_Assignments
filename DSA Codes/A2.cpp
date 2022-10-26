#include <iostream>
//#include <stdlib.h>
//#include <string.h>
using namespace std;

class Node
{
  string k,m;
  Node *lChild;
  Node *rChild;

public:
  Node()
  {
    k = "";
    m = "";
    lChild = rChild = NULL;
  }
  Node(string x, string y)
  {
    k = x;
    m = y;
    lChild = rChild = NULL;
  }
  friend class BST;
};

class BST
{
  Node *root;

public:
  BST()
  {
    root = NULL;
  }
  void create(string, string);
  void insert(string, string, Node *, Node *);
  Node *search(string, Node *&, Node *&);
  void asc(Node *);
  void desc(Node *);
  void demo();
  void deleteN(string);
  void deleteN1(string, Node *&, Node *&);
  void deleteN2(string, Node *&, Node *&);
  void nodeSearch(string);
  int update(string k);
};

void BST::demo()
{
  cout << "\n\n++++Ascending Traversal+++++";
  asc(root);
  cout << "\n\n-----Descending Traversal-----";
  desc(root);
}

void BST::create(string ele, string mean)
{
  Node *node;
  if (root == NULL)
  {
    node = new Node(ele, mean);
    root = node;
  }
  else
  {
    cout << "\nTree root node is already created so calling insert function.\n";
    insert(ele, mean, 0, 0);
  }
}

Node *BST::search(string key, Node *&loc, Node *&par)
{
  int count = 1;
  if (root == NULL)
  {
    cout << "\nTree does not exist";
    loc =par =  NULL;
    return loc, par;
  }
  loc = NULL;
  par = NULL;

  Node *temp = root;
  while (temp != NULL)
  {
    if (key == temp->k)
    {
      loc = temp;
      if (par == NULL)
      {
        cout << "\npar : NULL \nCurrent Node : " << loc->k;
      }
      else
      {
        cout << "\npar : " << par->k << "\nCurrent Node : " << loc->k;
        cout << "\nNumber of comparison:" << count;
      }
      return loc, par;
    }
    else if (key < temp->k)
    {
      par = temp;
      temp = temp->lChild;
    }
    else
    {
      par = temp;
      temp = temp->rChild;
    }
    count++;
  }

  if (loc = NULL)
  {
    cout << "\nKey Not Found.";
  }
}

void BST::insert(string key, string mean, Node *loc, Node *par)
{
  search(key, loc, par);

  if (loc != NULL)
  {
    cout << "\nNode already exist";
  }
  Node *p = new Node(key, mean);
  if (par == NULL)
  {
    root = p;

    return;
  }
  else if (p->k < par->k)
  {
    par->lChild = p;
    return;
  }
  else
  {
    par->rChild = p;
    return;
  }
}

void BST::asc(Node *p)
{
  if (p == NULL)
  {
    return;
  }
  asc(p->lChild);
  cout << "\nKey-" << p->k << "  Meaning-" << p->m;
  asc(p->rChild);
}

void BST::desc(Node *p)
{
  if (p == NULL)
  {
    return;
  }
  desc(p->rChild);
  cout << "\nKey-" << p->k << "  Meaning-" << p->m;
  desc(p->lChild);
}

void BST::deleteN(string key)
{
  Node *loc = NULL;
  Node *par = NULL;
  search(key, loc, par);

  if (loc == NULL)
  {
    cout << "\nNode does not exist.";
    return;
  }
  if ((loc->lChild != NULL) and (loc->rChild != NULL))
  {
    deleteN2(key, loc, par);
  }
  else
  {
    deleteN1(key, loc, par);
  }
}

void BST::deleteN1(string key, Node *&loc, Node *&par)
{
  Node *child;
  if ((loc->lChild == NULL) and (loc->rChild == NULL))
  {
    child = NULL;
  }
  else if (loc->lChild != NULL)
  {
    child = loc->lChild;
  }
  else
  {
    child = loc->rChild;
  }
  if (par != NULL)
  {
    if (loc == par->lChild)
    {
      par->lChild = child;
    }
    else
    {
      par->rChild = child;
    }
  }
  else
    root = child;
  // delete child;
}

void BST::deleteN2(string key, Node *&loc, Node *&par)
{
  Node *ptr1 = loc;
  Node *ptr2 = loc->rChild;
  while (ptr2->lChild != NULL)
  {
    ptr1 = ptr2;
    ptr2 = ptr2->lChild;
  }
  deleteN1(key, ptr2, ptr1);
  if (par != NULL)
  {
    if (loc == par->lChild)
      par->lChild = ptr2;
    else
      par->rChild = ptr2;
  }
  else
    root = ptr2;
  ptr2->lChild = loc->lChild;
  ptr2->rChild = loc->rChild;
}

void BST::nodeSearch(string key)
{
  Node *loc = NULL;
  Node *par = NULL;
  search(key, loc, par);
  if (loc == NULL)
  {
    cout << "\nNode not found in tree.";
  }
}

int BST::update(string k)
{
  Node *temp=root;
  while (temp != NULL)
  {
    if (k == temp->k)
    {
      cout << "\nEnter New Meaning of Keyword " << temp->k<<": ";
      cin >> temp->m;
      return 1;
    }

    if (k < temp->k)
      temp = temp->lChild;
    if (k > temp->k)
      temp = temp->rChild;
  }
  return -1;
}

int main()
{
  BST t;
  int choice,a;
  string e, m,k;
  char ch;
  do
  {
    cout << "\n1.Create Tree.\n2.Insert.\n3.Traversal.\n4.Delete Node.\n5.Search Node.\n6.Update Node.\n0.Exit";
    cout << "\n\nEnter your choice:";
    cin >> choice;
    switch (choice)
    {
    case 1:
      cout << "\nEnter root node keyword:";
      cin >> e;
      cout << "\nEnter meaning:";
      cin >> m;
      t.create(e, m);
      break;
    case 2:
      do
      {
      cout << "\nEnter keyword:";
      cin >> e;
      cout << "\nEnter meaning:";
      cin >> m;
      t.insert(e, m, 0, 0);
      cout<<"\nAdd more keywords(1/0)?: ";
      cin>>a;
      } while (a==1);
      break;
    case 3:
      cout << "\nNodes in Binary Search Tree are:\n";
      t.demo();
      break;
    case 4:
      cout << "\nEnter keyword to delete: ";
      cin >> k;
      t.deleteN(k);
      cout << "\nKeyword Deleted.";
      break;
    case 5:
      cout << "\nEnter key to search: ";
      cin >> k;
      t.nodeSearch(k);
      break;
    case 6:
        cout << "\nEnter Keyword whose meaning you want to update:";
        cin >> k;
        if (t.update(k) == 1)
          cout << "\nMeaning Updated";
        else
          cout << "\nKeyword missing";
          break;
    case 0:
      return 0;
    default:
      cout << "WRONG CHOICE!!!!\n";
      break;
    }

    cout << "\nDo you want to continue?(y/n): ";
    cin >> ch;
  } while (ch != 'n');

  return 0;
}
