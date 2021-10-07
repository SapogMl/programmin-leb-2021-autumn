#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int d = 0, Node* n = nullptr) : data(d), next(n) {}

};

Node* copy(Node* x)
{
	Node* tmp = new Node(x->data, tmp);
	if (x->next != nullptr)
	{
		return copy(x->next);
	}
	cout << tmp->data << '\n';
	return tmp;
}

struct List
{
	Node* head;
	List() { head = nullptr; }

	~List()
	{
		del();
	}
	List(const List& l)
	{
		copy(l.head);
	}

	List& operator= (const List& l)
	{
		del(); // удалили b
		head = copy(l.head);
		return *this;
	}

	void add_first(int d)
	{
		Node* tmp;
		tmp = new Node(d, head);
		head = tmp;
	}

	void print()
	{
		Node* p = head;
		while (p != nullptr)
		{
			cout << p->data << "\t";
			p = p->next;
		}
		cout << endl;
	}

	void del()
	{
		Node* ptr = head;
		while (ptr->next != nullptr)
		{
			Node* tmp = ptr->next;
			ptr = tmp->next;
			tmp = nullptr;
			delete tmp;
		}

	}

};

int main()
{
	List a;

	a.add_first(3);
	a.add_first(4);
	a.add_first(5);
	a.add_first(6);

	a.print();

	List b;
	b.add_first(1);
	b.add_first(2);

	b.print();

	List c;
	c.head = copy(a.head);
	c.print();

	/* b.operator=(a);
	a.print();
	b.print(); */


	return EXIT_SUCCESS;
}
