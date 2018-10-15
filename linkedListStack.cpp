#include <iostream>
using namespace std;

template <class T>
class Node {
	T _info;
	Node *_link;
public:

	T getInfo() const { return _info; }
	Node *getLink() const { return _link; }
	void setLink(Node *link = nullptr) { _link = link; }
	void addLink(const T& element) { _link = new Node(element, nullptr); }

	Node() { _link = nullptr; }

	Node(const T &info, Node *link) {
		_info = info;
		_link = link;
	}

	~Node() { _link = nullptr; }

	friend ostream &operator<<(ostream &cout, const Node<T> *node) {
		if (node != nullptr)
		{
			cout << node->_info << endl;
			if (node->_link != nullptr)
				cout << node->_link << endl;
			return cout;
		}
		else
		{
			cout << "List is empty." << endl;
			return cout;
		}
	}

};

template <class T>
class LinkedList {
	Node<T> *_node;

public:
	LinkedList() { _node = nullptr; }

	~LinkedList() { delete _node; }

	void Add(const T& element)
	{
		Node<T> *t = new Node<T>(element,_node);
		_node = t;
	}

	void Remove()
	{
		if (_node == nullptr)
			return;

		Node<T> *t = _node;
		_node = _node->getLink();

		t->setLink(nullptr);
		delete t;
	}


	friend ostream &operator<<(ostream &cout, const LinkedList<T> &linkedList) {
		cout << linkedList._node;
		return cout;
	}

};


int main()
{
	LinkedList<int> linkedList;
	linkedList.Add(1);
	linkedList.Add(2);
	linkedList.Add(3);
	linkedList.Add(4);
	linkedList.Add(5);

	linkedList.Remove();
	linkedList.Remove();
	linkedList.Remove();

	cout << linkedList << endl;

	system("PAUSE>0");
}