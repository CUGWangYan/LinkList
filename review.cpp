#include <iostream>
#include "head.h"
using namespace std;
int main() {
	List<int> t;
	t.input(0);
	cout << "headdatais:" << t.getHead()->data << endl;
	int a = 0;
	t.getData(3,a);
	cout << "3is:" << a << endl;
	cout << "lengthis:"<<t.getLength()<< endl;
	t.insert(3, 555);
	t.getData(4, a);
	cout << "4is:"<<a<< endl;
	cout<<"Full?"<<t.isFull();
	cout<<"EMpty?"<<t.isEmpty()<<endl;
	cout << "output:" << endl;
	t.output();
	List<int> e;
	LinkNode<int>* p = new LinkNode<int>;
	p=e.reverseList(t.getHead());
	cout << "nizhighoushi zheyang " << endl;
		LinkNode<int>* f = p->link;
		while (f != nullptr) {
			cout << f->data << endl;
			f = f->link;
		}
	system("pause");
	return 0;
}
