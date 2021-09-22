/*
Деструктор и конструктор, насколько я понимаю, пишутся просто по определению.
А вот про оператор присваивания непонятно: он чем-то должен отличаться от
конструктор или нет?
*/

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
	Node* tmp;
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
	Node* head;
	List() { head = nullptr; }

	~List() { cout << "del" << '\n'; del(); }
	List(const List& l) { copy(l.head); }

	List& operator= (const List& l) {
		// ?
	}

	void add_first(int d) {
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


	return EXIT_SUCCESS;
}