#include <iostream>
//#include <stdio.h>
#define max 10

using namespace std;

class Stack
{
    int top, size, *arr;

public:
    Stack()
    {
        size = max;
        top = 0;
        arr = new int[size];
    }
    Stack(int sz)
    {
        size = sz;
        top = 0;
        arr = new int[size];
    }
    void push(int);
    int pop();
    bool empty();
    friend class ListGraph;
};

void Stack::push(int data)
{
    if (top == size)
    {
        cout << "\nStack is full";
    }
    else
    {
        arr[++top] = data;
    }
    return;
}

int Stack::pop()
{
    if (top == 0)
    {
        cout << "\nStack is empty";
        return 0;
    }
    else
    {
        return arr[top--];
    }
}

bool Stack::empty()
{
    if (top == 0)
        return true;
    else
        return false;
}

class Queue
{
    int front, rear, size, *arr;

public:
    Queue()
    {
        front =1;
        rear= 0;
        size = max;
        arr = new int[size];
    }
    Queue(int sz)
    {
        front = 1;
        rear = 0;
        size = sz;
        arr = new int[size];
    }
    void enqueue(int);
    int dequeue();
    bool empty();
    friend class ListGraph;
};

void Queue::enqueue(int data)
{
    if (rear == size)
        cout << "\nQueue if FULL!";
    else if (empty())
    {
        front = rear = 1;
        arr[rear] = data;
    }
    else
    {
        arr[++rear] = data;
    }
}

int Queue::dequeue()
{
    if (empty())
        cout << "\nQueue is EMPTY!";
    else
    {
        return arr[front++];
    }
}

bool Queue::empty()
{
    if (rear < front || rear == 0)
        return true;
    else
        return false;
}

class Node
{
    int data;
    Node *next;

public:
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int d)
    {
        data = d;
        next = NULL;
    }
    friend class ListGraph;
};

class ListGraph
{
    Node *listOfVertices[max];
    int noOfVertices, noOfEdges;
    bool *visited;

public:
    ListGraph()
    {
        noOfVertices = noOfEdges = 0;
        listOfVertices[noOfVertices];
        for (int i = 1; i <= noOfVertices; i++)
        {
            listOfVertices[i] = new Node(i);
        }
    }
    ListGraph(int v, int e)
    {
        noOfVertices = v;
        noOfEdges = e;
        listOfVertices[noOfVertices];
        for (int i = 1; i <= noOfVertices; i++)
        {
            listOfVertices[i] = new Node(i);
        }
    }
    inline visit();
    void create();
    void DFS(int);
    void BFS(int);
    void display();
};

inline ListGraph::visit()
{
    visited = new bool[noOfVertices];
    for (int i = 1; i <= noOfVertices; i++)
    {
        visited[i] = 0;
    }
}

void ListGraph::create()
{
    int s, d;
    cout << "\nEnter the two vertices to form link between them.";
    for (int i = 1; i <= noOfEdges; i++)
    {
        cout << "\nEnter first vertex aka Source : ";
        cin >> s;
        cout << "\nEnter second vertex aka Destination: ";
        cin >> d;
        Node *dest = new Node(d);
        if (listOfVertices[s] == NULL)
        {
            listOfVertices[s] = dest;
        }
        else
        {
            Node *temp = listOfVertices[s];
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = dest;
        }
    }
}

void ListGraph::DFS(int source)
{
    Stack s(noOfVertices);
    int v;
    Node *temp;
    visit();
    visited[source] = 1;
    s.push(source);
    cout << "\nDFS:";
    while (!s.empty())
    {
        v = s.pop();
        cout << "\t" << v;
        temp = listOfVertices[v];
        while (temp != NULL)
        {
            if (visited[temp->data] == 0)
            {
                s.push(temp->data);
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }
    }
}

void ListGraph::BFS(int source)
{
    Queue q(noOfVertices);
    int v;
    Node *temp;
    visit();
    visited[source] = 1;
    q.enqueue(source);
    cout << "\nBFS:";
    while (!q.empty())
    {
        v = q.dequeue();
        cout << "\t" << v;
        temp = listOfVertices[v];
        while (temp != NULL)
        {
            if (visited[temp->data] == 0)
            {
                q.enqueue(temp->data);
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }
    }
}

void ListGraph::display()
{
    Node *temp;
    int count = 1;
    do
    {
        temp = listOfVertices[count];
        cout << "\n"<< count << ": ";
        temp=temp->next;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL";
        count++;
    } while (count <= noOfVertices);
    return;
}

int main()
{
    int ch;
    char repeat;
    bool yn = true;
    int pass, pass1, s;
    cout << "Enter number of vertices: ";
    cin >> pass;
    cout << "\nEnter number of edges: ";
    cin >> pass1;
    ListGraph lg(pass, pass1);
    while (yn == true)
    {
        cout << "\n1. Create"
                "\n2. DFS"
                "\n3. BFS"
                "\n4. Display"
                "\n5. Exit"
                "\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            lg.create();
            break;

        case 2:
            cout << "\nEnter the source vertex for DFS: ";
            cin >> s;
            lg.DFS(s);
            break;

        case 3:
            cout << "\nEnter the source vertex for BFS: ";
            cin >> s;
            lg.BFS(s);
            break;

        case 4:
            lg.display();
            break;

        case 5:
            return 0;

        default:
            cout << "\n!!Wrong Choice!!";
            break;
        }
        cout << "\nDo you want to continue (y/n or 1/0) ? : ";
        cin >> repeat;
        if (repeat == 'n' || repeat == 'N' || repeat == '0')
            yn = false;
    }
    return 0;
}