#include<iostream>
using namespace std;
#define sz 10
class hnode
{
    string word;
    string mean;
    hnode *next;

public:
    hnode()
    {
        word = " ";
        mean = " ";
        next = NULL;
    }
    hnode(string k, string v)
    {
        word = k;
        mean = v;
        next = NULL;
    }
    friend class HashTable;
};

class HashTable
{
    hnode *h[sz], *p,*q;

public:
    HashTable()
    {
        for (int i = 0; i < sz; i++)
        {
            h[i] = NULL;
        }
    }
    int HashFunction(string k)
    {
        return ((k[0] - NULL) % sz);
    }
    void insert(string k, string v);
    void search(string k);
    void deleteh(string k);
    void display()
    {
        for (int i = 0; i < sz; i++)
        {
            if (h[i] == NULL)
            {
                cout << "\nIndex: " << i;
            }
            else
            {
                cout << "\nIndex: " << i;
                hnode *temp = h[i];
                while (temp != NULL)
                {
                    cout << "\tWord= " << temp->word << "   Meaning= " << temp->mean << "-->>";
                    temp = temp->next;
                }
                cout << "\tNULL";
            }
        }
}
};

void HashTable::insert(string k, string v)
{
    int i = HashFunction(k);
    if (h[i] == NULL)
    {
        hnode *temp = new hnode(k, v);
        h[i] = temp;
    }
    else
    {
        p = h[i];
        while (p->next != NULL)
        {
            p = p->next;
        }
        hnode *temp = new hnode(k, v);
        p->next = temp;
    }
}

void HashTable::search(string k)
{
    int i = HashFunction(k);
    int flag = 0;
    int count = 0;
    if (h[i]->word == k)
    {
        count++;
        cout << "\nWord found \tWord: " << h[i]->word << "\tMeaning: " << h[i]->mean;
        cout << "\nComparisions required: " << count;
    }
    else
    {
        p = h[i];
        count++;
        while (p->next != NULL)
        {
            p = p->next;
            count++;
            if (p->word == k)
            {
                cout << "\nWord found Word: " << p->word << "\tMeaning: " << p->mean;
                cout << "\nComparisions required: " << count;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            cout << "\nWord not found!!!";
        }
    }
}

void HashTable::deleteh(string k)
{
    int i = HashFunction(k);
    int flag = 0;
    if (h[i]->word == k)
    {
        p = h[i];
        h[i] = p->next;
        delete p;
        cout << "\nWord deleted successfully";
    }
    else
    {
        p = h[i];
        cout<<p->word<<"\n";
        while (p != NULL)
        {
            q=p;
            p = p->next;
            if (p->word == k)
            {
                
                hnode *temp = p;
                p = p->next;
                q->next = p;
                //p=temp->next;
                delete temp;
                //hnode *p = new hnode();
                //temp->next=p;
                cout << "\nWord deleted successfully";
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            cout << "\nWord not found!!!";
        }
    }
}

int main()
{
    HashTable t;
    int ch, flag = 1, n;
    string k, v;
    do
    {
        cout << "\n\n----Main Menu----\n1.Create Hash table"
                "\n2.Insert New Entry"
                "\n3.Display Hash Table"
                "\n4.Search Hash Table"
                "\n5.Delete an Entry"
             << endl;
        cout << "\nEnter Your Choice-";
        cin >> ch;
        switch (ch)
        {
        case 1:
        case 2:
            cout << "\nEnter total number of entries: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "\nEnter word: ";
                cin >> k;
                cout << "\nEnter meaning: ";
                cin >> v;
                t.insert(k, v);
            }
            break;
        case 3:
            t.display();
            break;
        case 4:
            cout << "\nEnter the word you want to search: ";
            cin >> k;
            t.search(k);
            break;
        case 5:
            cout << "\nEnter the word you want to delete: ";
            cin >> k;
            t.deleteh(k);
            break;
        default:
            break;
        }
        cout << "\nDo you want to continue(1/0)? ";
        cin >> flag;
    } while (flag == 1);

    return 0;
}