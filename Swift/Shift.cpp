#include <iostream>
#include "list.h"


using namespace std;

int main()
{
	int n;
	cout << "Input count of numbers\n";
	cin >> n;
	list2<int> l;
	cout << "Input list\n";
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		add(l, x);
	}

	int pos, shift;
	cout << "input number position: " << endl;
	cin >> pos;
	pos--;

	cout << "how much to shift: " << endl;
	cin >> shift;

	if (pos < 0 || shift <= 0 || pos + 1 > l.count) {
		cout << "error\n";
		return -1;
	}

	int pos2 = pos - shift;
	if (pos2 < 0) pos2 = 0;
	auto cur = l.first;
	list2_elem<int>* toShift = nullptr;
	for (int i = 0; i < pos; i++) {
		if (i == pos2)
			toShift = cur;
		cur = cur->next;
	}
	auto prev = cur->prev;
	auto next = cur->next;
	if (prev != nullptr)
		prev->next = next;
	if (next != nullptr)
		next->prev = prev;
	toShift -> prev->next = cur;
	cur -> prev = toShift->prev;
	cur->next = toShift;
	
	if (pos2 == 0)
		l.first = cur;
	if (pos + 1 == l.count)
		l.last = prev;

	auto c = l.first;
	cout << endl;
	while (c != nullptr) {
		cout << c->data << " ";
		c = c->next;
	}
}
