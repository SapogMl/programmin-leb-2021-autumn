#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node * next;
	Node(int d = 0, Node * n = nullptr) : data(d), next(n) {}

};

Node * copy(Node *x)
{
	Node * tmp;
	return x;

	if (x != nullptr)
	{
		tmp = new Node(x->data, tmp);
		return x->next;
	}
	return tmp;
}

struct List
{
	Node * head;
	List() { head = nullptr; }

	void add_first(int d) {
		Node * tmp;
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
	b.head = copy(a.head);
	b.print();


	return EXIT_SUCCESS;
}