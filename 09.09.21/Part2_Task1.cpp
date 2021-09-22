#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
	int data;
	Node * next;
	Node(int d = 0, Node * n = nullptr) : data(d), next(n) {}

};

struct List
{
	Node * head;
	List() { head = nullptr; }

	void add_first(int d)
	{
		Node *tmp;
		tmp = new Node(d, head);
		head = tmp;
	}

	void print()
	{
		Node *p = head;
		while (p != nullptr)
		{
			cout << p->data << "\t";
			p = p->next;
		}
		cout << endl;
	}

	// ?
	void insertp(int n, int d)
	{
		int i = 0;

		Node * ptr;
		ptr = head;

		while (i < (n - 1))
		{
			if (ptr != nullptr)
			{
				i++;
				ptr = ptr->next;
			}
		}

		bool isHead = (n == 0);
		bool isTail = (ptr->next == nullptr);
		
		cout << i << " " << isHead << " " << isTail << '\n';

		if (isHead) 
		{
			add_first(d);
		}
		else
		{
			Node * insertion;

			if (isTail)
			{
				insertion = new Node(d, nullptr);
			}
			else
			{
				insertion = new Node(d, ptr->next);
			}

			ptr->next = insertion;
		}

	}

};

int main()
{
	List a;
	a.add_first(3);
	a.add_first(4);
	a.add_first(5);
	a.print();

	a.insertp(1, 222);
	a.print();

	return EXIT_SUCCESS;
}