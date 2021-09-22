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

	//OK
	Node* last()
	{
		if (head == nullptr)
		{
			cout << "EMPTY" << '\n';
			return nullptr;
		}
		Node * p = head;

		while (p->next != nullptr)
		{
			p = p->next;
		}
		return p;
	}

	//OK
	Node* prelast()
	{
		if (head == nullptr)
		{
			cout << "EMPTY" << '\n';
			return nullptr;
		}

		Node * p;
		p = head;

		while ((p->next->next) != nullptr)
		{
			p = p->next;
		}
		return p;
	}

	//OK
	Node* get_ptr(int n)
	{
		if (head == nullptr)
		{
			cout << "EMPTY" << '\n';
			return nullptr;
		}

		Node * p = head;
		int i = 0;

		while (i < n) {
			p = p->next;
			i++;
		}
		return p;
	}

	// ?
	void add_after_first(int d) 
	{
		Node * newNode;
		newNode = new Node(d, head->next);
		head->next = newNode;
	}

	// ?
	void add_last(int d)
	{
		Node * newNode;
		newNode = new Node(d, nullptr);
		last()->next = newNode;
	}

	// ?
	void del_last()
	{
		Node * dlt = last();
		prelast()->next = nullptr;
		delete dlt;
	}
};

int main()
{
	List a;
	a.add_first(3);
	a.add_first(4);
	a.add_first(5);

	cout << "original" << '\n';
	a.print();
	cout << '\n';
	
	cout << "add_after_first()" << '\n';
	a.add_after_first(888);
	a.print();
	cout << '\n';

	cout << "add_last()" << '\n';
	a.add_last(999);
	a.print();
	cout << '\n';

	cout << "del_last()" << '\n';
	a.del_last();
	a.print();

	return EXIT_SUCCESS;
}