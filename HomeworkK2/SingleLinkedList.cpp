#include <iostream>

using namespace std;
template <typename T>
struct elem_link{
	T inf;
	elem_link<T> *link;
};
template <typename T>
class List{
private:
	elem_link<T> *start;
	elem_link<T> *end;
	elem_link<T> *current;
	void DeleteList();
	void CopyList(List<T> const &);
public:
	List();
	List(List<T> const &);
	List& operator= (List<T> const &);
	~List();
	void IterStart(elem_link<T> *p = NULL);
	elem_link<T>* Iter();
	void ToEnd(T const &);
	void InsertAfter(elem_link<T>*, T const &);
	void InsertBefore(elem_link<T>*, T const &);
	bool DeleteAfter(elem_link<T>*);
	bool DeleteBefore(elem_link<T>*);
	void DeleteElem(elem_link<T>*);
	void print();
	int lenght();
	void concat(List<T> const& list);
	bool empty();
	void push_front(T x);
	void push_back(T x);
	T pop_back();
	T pop_front();
};
template <typename T>
List<T>::List(){
	start = NULL;
	end = NULL;
}
template <typename T>
List<T>::~List(){
	DeleteList();
}
template <typename T>
List<T>::List(List<T> const & list){
	CopyList(list);
}
template <typename T>
List<T>& List<T>::operator=(List<T> const & list){
	if(this != &list){
		DeleteList();
		CopyList(list);
	}
	return *this;
}
template <typename T>
void List<T>::DeleteList(){
	elem_link<T> *p;
	while(start){
		p = start;
		start = start->link;
		delete p;
	}
	end = NULL;
}
template <typename T>
void List<T>::CopyList(List<T> const & list){
	start = end = NULL;
	if(list.start){
		elem_link<T> *p = list.start;
		while(p){
			ToEnd(p->inf);
			p = p->link;
		}
	}
}
template <typename T>
void List<T>::IterStart(elem_link<T> *p){
	if (p) current = p;
	else current = start;
}
template <typename T>
elem_link<T>* List<T>::Iter(){
	elem_link<T> *p = current;
	if(current) current = current->link;
	return p;
}
template <typename T>
void List<T>::ToEnd(T const & x){
	current = end;
	end = new elem_link<T>;
	end->inf = x;
	end->link = NULL;
	if(current) current->link = end;
	else start = end;
}
template <typename T>
void List<T>::push_back(T x) {
	elem_link<T>* p = new elem_link<T>;
	p->inf = x;
	p->link = NULL;
	if (!start) {
		start = p;
	}
	else {
		end->link = p;
	}
	end = p;
}
template <typename T>
void List<T>::push_front(T x) {
	elem_link<T>* p = new elem_link<T>;
	p->inf = x;
	p->link = start;
	if (!start) {
		end = p;
	}
	start = p;
}
template <typename T>
T List<T>::pop_front() {
	if (start) {
		elem_link<T>* p = start;
		start = p->link;
		T x = p->inf;
		delete p;
		return x;
	}
	else {
		cerr << "Empty list!" << endl;
	}
}
template <typename T>
T List<T>::pop_back() {
	if (start) {
		elem_link<T>* p = end;
		elem_link<T>* k = start;
		while (k->link != end) {
			k = k->link;
		}
		end = k;
		end->link = NULL;
		T x = p->inf;
		delete p;
		return x;
	}
	else {
		cerr << "Empty list!" << endl;
	}
}

template <typename T>
void List<T>::InsertAfter(elem_link<T> *p, T const & x){
	elem_link<T> *q = new elem_link<T>;
	q->inf = x;
	q->link = p->link;
	if (p == end) end = q;
	p->link = q;
}	
template <typename T>
void List<T>::InsertBefore(elem_link<T> *p, T const & x){
	elem_link<T> *q = new elem_link<T>;
	*q = *p;
	if(p == end) end = q;
	p->inf = x;
	p->link = q;
}
template <typename T>
bool List<T>::DeleteAfter(elem_link<T> *elem){
	elem_link<T> *p = elem->link;
	elem->link = elem->link->link;
	T x = p->inf;
	delete p;
	return x; 
}
template <typename T>
void List<T>::DeleteElem(elem_link<T> *elem){
	elem_link<T>* p = start;
	while(p->link != elem){
		p = p->link;
	}
	DeleteAfter(p);
}
template <typename T>
bool List<T>::DeleteBefore(elem_link<T> *p){
	if(p != start){
		elem_link<T> *q = start;
		while(q->link != p) q = q->link;
		DeleteElem(q);
		return 1;
	}
	return 0;
}
template <typename T>
void List<T>::print(){
	elem_link<T> *p = start;
	while(p){
		cout<<p->inf<<" ";
		p = p->link;
	}
	cout<<endl;
}
template <typename T>
int List<T>::lenght(){
	int n = 0;
	elem_link<T> *p = start;
	while(p){
		n++;
		p = p->link;
	}
	return n;
}
template <typename T>
void List<T>::concat(List<T> const & list){
	elem_link<T> *p = list.start;
	while(p){
		ToEnd(p->inf);
		p = p->link;
	}
}
template <typename T>
bool List<T>::empty(){
	return start == NULL;
}
void DeleteDuplicates(List<int>& a){
	a.IterStart();
	elem_link<int>* p = a.Iter();
	int tempInfo = p->inf;
	while(p->link){
		if(tempInfo == p->link->inf){
			elem_link<int>* temp = p->link;
			a.DeleteElem(temp);
		}
		else{
			p = p->link;
			tempInfo = p->inf;
		}
	}
}
List<int> mergeSortedLists(List<int> a, List<int> b) {
	a.IterStart();
	b.IterStart();
	elem_link<int>* A = a.Iter();
	elem_link<int>* B = b.Iter();
	List<int> res;
	while (!a.empty() || !b.empty()) {
		if (!a.empty() && !b.empty()) {
			if (A->inf < B->inf) {
				A = A->link;
				res.push_back(a.pop_front());
			}
			else {
				B = B->link;
				res.push_back(b.pop_front());
			}
		}
		else if (!a.empty() && b.empty()) {
			A = A->link;
			res.push_back(a.pop_front());
		}
		else {
			B = B->link;
			res.push_back(b.pop_front());
		}
	}
	return res;
}
int main(){
	List<int> temp;
	temp.ToEnd(1);
	temp.ToEnd(1);
	temp.ToEnd(2);
	temp.ToEnd(3);
	temp.ToEnd(4);
	temp.ToEnd(4);
	temp.ToEnd(6);
	temp.ToEnd(7);
	temp.ToEnd(8);
	temp.ToEnd(8);
	DeleteDuplicates(temp);
	temp.print();
	List<int> p, q;
	p.ToEnd(1);
	p.ToEnd(2);
	q.ToEnd(3);
	q.ToEnd(4);
	p.ToEnd(7);
	q.ToEnd(9);
	mergeSortedLists(p, q).print();
	return 0;
}