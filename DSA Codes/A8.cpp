#include <bits/stdc++.h>
using namespace std;

#define MAX 100
#define sz 10

class Node
{
    int name;
    Node *next;

public:
    friend class Graph;
    Node(int s)
    {
        name = s;
        next = NULL;
    }
};

class Queue
{
    int front, rear;
    Node *q[MAX];

public:
    Queue()
    {
        front = rear = -1;
    }
    int is_Full()
    {
        if (rear == MAX - 1)
            return 1;
        else
            return 0;
    }
    int is_Empty()
    {
        if (front > rear || rear == -1)
            return 1;
        else
            return 0;
    }
    void enqueue(Node *p)
    {
        if (is_Full())
        {
            cout << "\nQueue is Full";
        }
        else if (is_Empty())
        {
            front = 0;
            rear = 0;
            q[rear] = p;
        }
        else
        {
            rear++;
            q[rear] = p;
        }
    }
    Node *dequeue()
    {
        Node *p;
        if (is_Empty())
        {
            cout << "\nQueue is Empty";
        }
        else
        {
            p = q[front];
            front++;
        }
        return p;
    }
};

class Graph
{
    int no_vertices, no_edges;
    Node *header[sz];

public:
    Graph(int v, int e)
    {
        no_vertices = v;
        no_edges = e;
        for (int i = 0; i < no_vertices; i++)
        {
            header[i] = new Node(i);
        }
    }

    void accept_graph()
    {
        int s, d;
        while (no_edges--)
        {
            cout << "\n";
            cout << "Enter source city: ";
            cin >> s;
            cout << "Enter destination city: ";
            cin >> d;
            Node *temp = header[s];
            Node *dest = new Node(d);
            if (header[s] == NULL)
            {
                header[s] = dest;
            }
            else
            {
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = dest;
            }
        }
    }

    void display_graph()
    {
        cout << "\nDISPLAY\n";
        for (int i = 0; i < no_vertices; i++)
        {
            Node *temp = header[i];
            cout << temp->name << " ---> [ ";
            temp = temp->next;
            while (temp != NULL)
            {
                cout <<temp->name << " -> ";
                temp = temp->next;
            }
            cout << "# ] ";
            cout << "\n";
        }
    }

    void topologicalSort()
    {
        int indegree[no_vertices];
        for (int i = 0; i < no_vertices; i++)
        {
            indegree[i] = 0;
        }
        Node* temp;
        for (int i = 0; i < no_vertices; i++)
        {
            temp = header[i]->next;
            while (temp != NULL)
            {
                indegree[temp->name]++;
                temp = temp->next;
            }
        }
        Queue q;
        for (int i = 0; i < no_vertices; i++)
        {
            if (indegree[i] == 0)
            {
                q.enqueue(header[i]);
            }
        }
        if (q.is_Empty())
        {
            cout << "\nTopological Sort not possible due to no vertex with zero indegree";
        }
        else
        {
            Node *temp;
            int no = 0;
            while (!q.is_Empty())
            {
                temp = q.dequeue();
                temp = header[temp->name];
                cout <<temp->name;
                no++;
                temp = temp->next;
                while (temp != NULL)
                {
                    if (indegree[temp->name] > 0)
                    {
                        indegree[temp->name] = indegree[temp->name] - 1;
                    }
                    if (indegree[temp->name] == 0)
                    {
                        q.enqueue(temp);
                    }
                    temp = temp->next;
                }
            }
            if (no == no_vertices)
            {
                cout << "\nAbove is topological sort order";
            }
            else
            {
                cout << "\nTopological sort not possible due to cyclic nature";
            }
        }
    }
};

int main()
{
    cout << "\n\nACCEPTING GRAPH\n\n";
    int v, e;
    cout << "Enter no. of vertices (cities) :";
    cin >> v;
    cout << "Enter no. of edges (routes) :";
    cin >> e;
    Graph g(v, e);
    g.accept_graph();
    int var = 1;
    while (var == 1)
    {
        int choice;
        cout << "\n\n--------------MENU--------------\n\n";
        cout << "Enter your choice : \n";
        cout << " 1)Display Graph \n 2)Topological Sort \n ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            g.display_graph();
            break;
        }
        case 2:
        {
            g.topologicalSort();
            cout << "\n";
            break;
        }
        default:
        {
            cout << "Enter valid choice !";
            break;
        }
        }
        cout << "\nDo you want to continue (0/1) : ";
        cin >> var;
    }
}
