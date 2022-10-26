#include<iostream>
using namespace std;
class MinHeap
{
	int *harr, capacity, heap_size; 
	Queue q;
public:
	MinHeap(int capacity);

	void MinHeapify(int );

	void insertKey(int k);

	int extractMin();

	inline int parent(int i) { return (i-1)/2; }

	int left(int i) { return (2*i + 1); }

	int right(int i) { return (2*i + 2); }

	int getMin() { return harr[0]; }

	inline void swap(int *x, int *y)
	{
	int temp = *x;
	*x = *y;
	*y = temp;
	}
	
	void display()
    {
        cout << "\nDISPLAYING MIN-HEAP:\t[ ";
        for (int i = 0; i < heap_size; i++)
        {
            cout << harr[i] << " ";
        }
        cout << "]\n";
	}
	void sort()
	{
		int h=heap_size;
		for(int i = 0; i < h; i++)
		{
			int j= extractMin();
			cout<<" "<<j;
		}
	}
};

MinHeap::MinHeap(int cap)
{
	heap_size = 0;
	capacity = cap;
	harr = new int[cap];
}

void MinHeap::insertKey(int k)
{
	if (heap_size == capacity)
	{
		cout << "\nHeap Tress is full!!";
		return;
	}

	int i = heap_size;
	harr[i] = k;
	heap_size++;
	while (i != 0 && harr[parent(i)] > harr[i])
	{
	swap(&harr[i], &harr[parent(i)]);
	i = parent(i);
	}
}

int MinHeap::extractMin()
{
	if (heap_size <= 0)
		return 0;
	if (heap_size == 1)
	{
		heap_size--;
		return harr[0];
	}

	int root = harr[0];
	q.enqueue(root);
	harr[0] = harr[heap_size-1];
	heap_size--;
	MinHeapify(0);

	return root;
}

void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l] < harr[i])
		smallest = l;
	if (r < heap_size && harr[r] < harr[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(&harr[i], &harr[smallest]);
		MinHeapify(smallest);
	}
}

int main()
{
	MinHeap h(20);
    int choice,n,ele,d,flag = 1;
    while (flag == 1)
    {
        cout << "\n1.Insert element \n2.Remove minimum element\n3.Get Minimum element\n4.Display Min-Heap";
        cout << "\n\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout<<"\nEnter number of elements you want to enter: ";
            cin>>n;
            for (int i=0;i<n;i++)
            {
                cout << "\nEnter element"<<i+1<<" : ";
                cin>>ele;
                h.insertKey(ele);
            }
            break;
        case 2:
           	cout<<"\nExtracted element is: "<<h.extractMin();
			break;
        case 3:
            cout<<"\nMinimum element is: "<<h.getMin();
            break;
        case 4:
			h.display();
			break;
		case 5:
			h.sort();
         	break;
        default:
            cout << "\nInvalid Choice!!........Please enter valid choice";
            break;
        }
        cout << "\n\nDo you want to perform again (1/0) :";
        cin >> flag;
    }
	return 0;
}
