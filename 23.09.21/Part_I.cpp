#include <iostream>
#include <cstdlib>
using namespace std;


struct DNode
{
	int data;
	DNode* next;
	DNode* prev;
	DNode(int d = 0, DNode* n = nullptr, DNode* p = nullptr) :
		data(d), next(n), prev(p) {}

};

struct DList
{
	DNode* head, * tail;
	DList() { head = nullptr; tail = nullptr; }

	void add_first(int d)
	{
		DNode* t;
		t = new DNode(d, head, nullptr);

		if (head == nullptr)
		{
			head = t;
			tail = t;
		}
		else
		{
			head->prev = t;
			head = t;
		}
	}

	void print()
	{
		DNode* p = head;
		while (p != nullptr)
		{
			cout << p->data << "\t";
			p = p->next;
		}
		cout << endl;
	}

	void print_reverse()
	{
		DNode* p = tail;
		while (p != nullptr)

		{
			cout << p->data << "\t";
			p = p->prev;
		}
		cout << endl;
	}

	void Print()
	{
		print();
		print_reverse();
		cout << endl;
	}

	// OK
	void add_last(int d)
	{
		DNode* tmp;
		tmp = new DNode(d, nullptr, tail);
		tail->next = tmp;
		tail = tmp;
	}

	// OK
	void add_after_first(int d)
	{
		DNode* tmp;
		tmp = new DNode(d, head->next, head);
		head->next->prev = tmp;
		head->next = tmp;
	}

	// OK
	void del_last()
	{
		DNode* t = tail;
		t->prev->next = nullptr;
		tail = t->prev;
		delete t;
	}

	// OK
	void del_second()
	{
		if (head == tail) // åñëè óçëîâ â ñïèñêå < 2
		{
			cout << "ERROR: list too short" << '\n';
		}
		else
		{
			DNode* t = head->next;

			if (t == tail) // åñëè óçëîâ 2
			{
				del_last();
			}
			else
			{
				head->next = t->next;
				t->next->prev = t->prev;
				delete t;
			}
		}
	}

};

int main()
{
	DList l;

	l.add_first(3);
	l.add_first(2);
	l.add_first(1);

	//l.add_last(4);
	//l.add_after_first(6);
	//l.del_last();
	//l.del_second();

	l.Print();

	return EXIT_SUCCESS;
}
