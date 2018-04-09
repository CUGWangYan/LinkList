#pragma once
#include <iostream>
using namespace std;
template <typename T>
struct LinkNode {
	T data;
	LinkNode* link;
	LinkNode(LinkNode<T> *ptr = nullptr) { link = ptr; }
	LinkNode(const T&item, LinkNode<T>*ptr = nullptr) {
		data = item;
		link = ptr;
	}
};
template <typename T>
class List {
private:
	LinkNode<T>* first;
public:
	List() { first = new LinkNode<T>; }//with headNode
	List(const T&item) { first = new LinkNode<T>(item); }
	List(const List<T>&L) { 
		T value;
		LinkNode<T>*srcptr = L.getHead();
		LinkNode<T>*destptr = first = new LinkNode<T>;
		while (srcptr->link != nullptr) {
			value = srcptr->link->data;
			destptr->link = new LinkNode<T>(value);
			destptr = destptr->link;
			srcptr = srcpty->link;
		}
	}
	~List() { makeEmpty(); }
	void makeEmpty() {
		LinkNode<T>* p;
		while (first->link != nullptr) {
			p = first->link;
			first->link = p->link;//×îºólinkÊÇnullptr°É
			delete p;
		}
	}
	int getLength()const {
		int a = 0;
		LinkNode<T> *t;
		t = first->link;
		while (t!= nullptr) {
			a++;
			t = t->link;
		}
		return a;
	}
	LinkNode<T>* getHead() {
		if (!isEmpty()) return first->link; else cerr << "kong" << endl;
	}
	LinkNode<T>* Search(const T& x)const {
		LinkNode<T> *f = first->link;
		while (f != nullptr) {
			if (f->data == x) break;
			else f = f->link;
		}
		return f;
	}
	LinkNode<T>* Locate(int i)const {
		int a = getLength();
		if (i > a) return nullptr;
		LinkNode<T>*f = first->link;
		while (i--) {
			f = f->link;
		}
		return f;
	}
	bool getData(int i,T&x)const {
		if (i < 0)return false;
		LinkNode<T>* f = Locate(i);
		if (f != nullptr) {
			x = f->data;
			return true;
		}
		else return false;
	}
	void setData(int i, const T&x) {
		if (i < 0)return false;
		LinkNode<T>*f = Locate(i);
		if (f != nullptr) {
			f->data = x;
			return true;
		}
	}
	bool insert(int i, const T&x) {
		if (i < 0)return false;
		LinkNode<T>*f = Locate(i);
		if (f == nullptr)return false;
		LinkNode<T>*newnode=new LinkNode<int>(x);
		newnode->link = f->link;
		f->link = newnode;
		return true;
	}
	bool remove(int i, T&x) {
		if (i < 0)return false;
		LinkNode<T>*f = Locate(i);
		if (f == nullptr) return false;
		LinkNode<T>*del = f->link;
		x = f->data;
		f->data = del->data;
		delete del;
		return true;
	}
	bool isEmpty()const {
		return first->link == nullptr ? true : false;
	}
	bool isFull()const { return false; }
	void sort() {
		return;
	}
	void input(T endTag) {
		LinkNode<T>* newNode;
		T val;
		makeEmpty();
		cin >> val;
		while (val != endTag) {
			newNode = new LinkNode<T>(val);
			if (newNode == nullptr) { cerr << "wrong" << endl; }
			newNode->link = first->link;
			first->link = newNode;
			cin >> val;
		}
	}
	void output() {
		LinkNode<T>* f = first->link;
		while (f != nullptr) {
			cout << f->data << endl;
			f = f->link;
		}
	}
	LinkNode<int>* reverseList(LinkNode<int>* head) {
		if (head == nullptr) {
			return head;
		}
		LinkNode<T>*tail = new LinkNode<int>;
		tail = head;
		LinkNode<T>*temp = nullptr, *cur;
		while (tail->link != nullptr) {
			cur = tail->link;
			tail->link = temp;
			temp = tail;
			tail = cur;
		}
		tail->link = temp;
		return tail;
	}
};

