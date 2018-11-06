#include <iostream>
#include <fstream>


using namespace std;

template<typename T>
class Unit {
public:
	T data;
	Unit<T>* next;
	Unit<T>* prev;

	Unit(T data) {
		this->data = data;
		next = nullptr;
		/*prev = nullptr;*/
	}
	/*~Unit() {
		this->data = NULL;
		next = nullptr;
	}*/
};

template<typename T>
class MyLinkedList {

	Unit<T>* start;
	int len;

public:
	MyLinkedList() {
		len = 0;
		start = nullptr;
	}

	~MyLinkedList() {
		
		Unit<T>* buf = start;
		Unit<T>* next = start->next;

		while (true) {
			delete buf;
			buf = next;
			if (next == nullptr) {
				break;
			}
			next = next->next;
			
		}

	}



	void add(Unit<T>* &n) {
		if (start == nullptr) {
			start = n;
		}
		else {
			Unit<T>* start_copy = start;
			while (true) {

				Unit<T>* buf = start_copy->next;
				if (buf == nullptr) {
					start_copy->next = n;
					break;
				}
				else {
					start_copy = start_copy->next;
				}
			}
		}

		len++;
	}
	double get(int index) {
		bool res = true;

		if (index > len || index < 1) {
			res = false;
		}
		Unit<T>* cur = start;
		for (int i = 1; i < index; i++) {
			cur = cur->next;
		}
		if (res == true) {
			return cur->data;
		}
		else {
			throw "Incorrect Index";
		}
	
	
	}

	void removeFirst() {
		if (start != nullptr) {
			start = start->next;
			len--;
		}
	}

	void removeLast() {
		Unit<T>* buf = start;
		for (int i = 1; i < len - 1; i++) {
			buf = buf->next;
		}
		buf->next = nullptr;
		len--;
	}

	bool removeByValue(T value) {
		bool res = true;
		if (start->data == value) {
			removeFirst();
		}
		else {
			Unit<T>* prev = start;
			Unit<T>* cur = start->next;
			while (true) {

				if (cur == nullptr) {
					res = false;
					break;
				}
				else {
					if (cur->data == value) {
						prev->next = cur->next;
						break;
					}
					else {
						prev = cur;
						cur = cur->next;
					}
				}
			}

		}
		if (res) {
			len--;
		}
		return res;
	}

	bool removeByIndex(int index) {
		bool res = true;

		if (index > len || index < 1) {
			res = false;
		}
		Unit<T>* prev = nullptr;
		Unit<T>* cur = start;
		for (int i = 1; i < index; i++) {
			prev = cur;
			cur = cur->next;
		}
		if (prev == nullptr) {
			removeFirst();
		}
		else {
			prev->next = cur->next;
		}
		if (res) {
			len--;
		}


		return res;
	}
	

	void print() {
		Unit<T>* start_copy = start;
		if (start_copy != nullptr) {
			while (true) {

				Unit<T>* buf = start_copy;
				if (buf == nullptr) {
					break;
				}
				else {
					cout << buf->data << " -> ";
					start_copy = start_copy->next;
				}
			}
			cout << "NULL" << endl;
		}
		else {
			cout << "List is empty" << endl;
		}
	}
	void save() {
		ofstream out;
		out.open("C:\\Save.txt");
		if (out.is_open())
		{
			Unit<T>* start_copy = start;
			if (start_copy != nullptr) {
				while (true) {

					Unit<T>* buf = start_copy;
					if (buf == nullptr) {
						break;
					}
					else {
						out << buf->data << " ";
						start_copy = start_copy->next;
					}
				}
			
			}
			else {
				out << "" << endl;
			}
		}
		out.close();
	}
	void load() {
		double d;
		ifstream in("C:\\Save.txt"); 
		if (in.is_open())
		{
			while (in >> d)
			{
				cout << d << endl;
			}
		}
		in.close();
	
	
	
	}
};



int main() {
	MyLinkedList<int> list;
	int menu;


	while (true) {
		int i;
		cin >> i;
		if (i == 0) {
			break;
		}
		if (i == 11) {
			list.load();
		}
		Unit<int>* a = new Unit<int>(i);

		list.add(a);













		list.print();
	}

	
	
	system("pause");
	return 0;
}