#include <iostream>
using namespace std;
#define sz 10
class HashEntry
{
	long int tno;
	string nm;

public:
	HashEntry()
	{
		tno = 0;
		nm = " ";
	}
	HashEntry(long int x, string s)
	{
		tno = x;
		nm = s;
	}
	friend class HashTable;
};

class HashTable
{
	HashEntry h1[sz], h2[sz];

public:
	HashTable()
	{
		for (int i = 0; i < sz; i++)
		{
			h1[i].nm = " ";
			h1[i].tno = 0;
			h2[i].nm = " ";
			h2[i].tno = 0;
		}
	}

	int hashFunction(int k)
	{
		return (k % sz);
	}
	void insert();
	void withReplacement(long int k, string n);
	void withoutReplacement(long int k, string n);
	void search(long int k);
	void display()
	{
		cout << "\n**Without Replacement**";
		for (int i = 0; i < sz; i++)
		{
			cout << "\n\nIndex: " << i << "\t Name: " << h1[i].nm << "\t\tTelephone no: " << h1[i].tno;
		}
		cout << "\n\n\n**With Replacement**";
		for (int i = 0; i < sz; i++)
		{
			cout << "\n\nIndex: " << i << "\t Name: " << h2[i].nm << "\t\tTelephone no: " << h2[i].tno;
		}
	}
};
void HashTable::insert()
{
	int ch, n;
	long int k;
	string s;
	cout << "Enter Total Number Of Entries-";
	cin >> n;
	cout << "\n1.Insert with replacement\n2.Insert without replacement\nYour choice: ";
	cin >> ch;
	for (int i = 0; i < n; i++)
	{
		cout << "\n Enter Name: ";
		cin >> s;

		cout << "\n\t Enter telephone no: ";
		cin >> k;
		if (ch == 1)
		{
			withReplacement(k, s);
		}
		else if (ch == 2)
		{
			withoutReplacement(k, s);
		}
	}
}
void HashTable::withoutReplacement(long int k, string n)
{
	int i = hashFunction(k);
	if (h1[i].tno == 0)
	{
		h1[i].tno = k;
		h1[i].nm = n;
	}
	else
	{
		int index = i;
		while (h1[index].tno != 0)
		{
			index++;
		}
		if (index < sz && h1[index].tno == 0)
		{
			h1[index].tno = k;
			h1[index].nm = n;
		}
		else
		{
			index = 0;
			if (h1[index].tno == 0)
			{
				h1[index].tno = k;
				h1[index].nm = n;
			}
			else
			{
				while (h1[index].tno != 0)
				{
					index++;
				}
				if (index < sz && h1[index].tno == 0)
				{
					h1[index].tno = k;
					h1[index].nm = n;
				}
			}
		}
	}
}
void HashTable::withReplacement(long int k, string n)
{
	int i = hashFunction(k);
	int key=h2[i].tno;
	int ival=hashFunction(key);
	if (h2[i].tno == 0)
	{
		h2[i].tno = k;
		h2[i].nm = n;
	}
	else
	{
		int index = i;
		if(ival==i)
		{
			while (h2[index].tno != 0)
		{
			index++;
		}
		if (index <= sz)
		{
			h2[index].tno = k;
			h2[index].nm = n;
		}
		else
		{
			index = 0;
			if (h2[index].tno == 0)
			{
				h2[index].tno = k;
				h2[index].nm = n;
			}
			else
			{
				while (h2[index].tno != 0)
				{
					index++;
				}
				if (index <= sz)
				{
					h2[index].tno = k;
					h2[index].nm = n;
				}
			}
		}
		}
		else
		{
		long int v = h2[i].tno;
		string name = h2[i].nm;
		h2[i].tno = k;
		h2[i].nm = n;
		while (h2[index].tno != 0)
		{
			index++;
		}
		if (index <= sz)
		{
			h2[index].tno = v;
			h2[index].nm = name;
		}
		else
		{
			index = 0;
			if (h2[index].tno == 0)
			{
				h2[index].tno = v;
				h2[index].nm = name;
			}
			else
			{
				while (h2[index].tno != 0)
				{
					index++;
				}
				if (index <= sz)
				{
					h2[index].tno = v;
					h2[index].nm = name;
				}
			}
		}
		}
		
	}
}
void HashTable::search(long int k)
{
	int index = hashFunction(k);
	int ivalue = index;
	int count = 0, ch;
	cout << "\n1. Search in With Replacement Hash Table.";
	cout << "\n2. Search in Without Replacement Hash Table.";
	cout << "\nEnter your choice: ";
	cin >> ch;
	if (ch == 1)
	{
		int flag=0;
		if (h2[index].tno == k)
		{
			count++;
			cout << "\nValue found \tName: " << h2[index].nm << "\tTelephone Number: " << h2[index].tno;
			cout << "\nNumber of comparisions: " << count;
		}
		else
		{
			while (ivalue <= sz)
			{	count++;
				if (h2[ivalue].tno == k)
				{	
					cout << "\nValue found \tName: " << h2[ivalue].nm << "\tTelephone Number: " << h2[ivalue].tno;
					cout << "\nNumber of comparisions: " << count;
					flag=1;
					break;
				}
				ivalue++;
			}
			if (flag==0)
			{
				ivalue=0;
				while (ivalue <= sz)
				{	count++;
				if (h2[ivalue].tno == k)
				{	
					cout << "\nValue found \tName: " << h2[ivalue].nm << "\tTelephone Number: " << h2[ivalue].tno;
					cout << "\nNumber of comparisions: " << count;
					break;
				}
				ivalue++;
				}
			}
			else
			{
				cout<<"\nValue not found!";
			}
		}
	}
	else if (ch == 2)
	{
		int flag=0;
		if (h1[index].tno == k)
		{
			count++;
			cout << "\nValue found \tName: " << h1[index].nm << "\tTelephone Number: " << h1[index].tno;
			cout << "\nNumber of comparisions: " << count;
		}
		else
		{
			
			while (ivalue <= sz)
			{	count++;
				if (h1[ivalue].tno == k)
				{	
					cout << "\nValue found \tName: " << h1[ivalue].nm << "\tTelephone Number: " << h1[ivalue].tno;
					cout << "\nNumber of comparisions: " << count;
					flag=1;
					break;
				}
				ivalue++;
			}
			if (flag==0)
			{
				ivalue=0;
				while (ivalue <= sz)
				{	count++;
				if (h1[ivalue].tno == k)
				{	
					cout << "\nValue found \tName: " << h1[ivalue].nm << "\tTelephone Number: " << h1[ivalue].tno;
					cout << "\nNumber of comparisions: " << count;
					break;
				}
				ivalue++;
				}
			}
			else
			{
				cout<<"\nValue not found!";
			}
		}
	}
	else
	{
		cout << "Wrong Choice!!!";
		return;
	}
}
int main()
{
	HashTable t;
	int choice;
	int flag = 1;
	long int k;
	do
	{
		cout << "\n\n----Main Menu----\n1.Create Hash table"
				"\n2.Insert New Entry"
				"\n3.Display Hash Table"
				"\n4.Search Hash Table"
				"\n5.Exit"
			 << endl;
		cout << "\nEnter Your Choice-";
		cin >> choice;
		switch (choice)
		{
		case 1:
		case 2:
			t.insert();
			break;
		case 3:
			t.display();
			break;
		case 4:
			cout << "\nEnter the telephone number you want to search: ";
			cin >> k;
			t.search(k);
			break;
		case 5:
			return 0;
		default:
			cout << "\nInvalid Choice!!........Please enter valid choice";
			break;
		}
		cout << "\n\nDo you want to perform again (1/0) :";
		cin >> flag;
	} while (flag == 1);

	return 0;
}