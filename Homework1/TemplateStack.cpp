#include <iostream>
using namespace std;
template <typename T>
struct node{
	T data;
	node* next;
};
template <typename T>
class Stack{
private:
	node<T>* topNode;
	void copy(node<T>* toCopy);
	void eraseStack();
 	void copyStack(Stack const&);
public:
 	Stack(); 
 	Stack(Stack const&);
 	Stack& operator=(Stack const&);
 	~Stack();
 	bool empty() const;
 	void push(T const& x);
 	T pop();
 	T top() const;
};
template <typename T>
Stack<T>::Stack() : topNode(nullptr) {}
template <typename T>
bool Stack<T>::empty() const {
	return topNode == nullptr;
}
template <typename T>
void Stack<T>::push(T const& x) {
 	node<T>* p = new node<T>;
 	p->data = x;
 	p->next = topNode;
 	topNode = p;
}
template <typename T>
T Stack<T>::pop() {
 	if (empty()) {
 		return 0;
 	}
 	node<T>* p = topNode;
 	topNode = topNode->next;
 	T x = p->data;
 	delete p;
 	return x;
}
template <typename T>
T Stack<T>::top() const {
 	if (empty()) {
 		return 0;
 	}
 	return topNode->data;
}
template <typename T>
void Stack<T>::eraseStack() {
 	while (!empty())
 		pop();
	}
template <typename T>
Stack<T>::~Stack() {
 	eraseStack();
}
template <typename T>
void Stack<T>::copy(node<T>* toCopy) {
 	if (toCopy == nullptr)
 		return;
 	copy(toCopy->next);
 	push(toCopy->data);
}
template <typename T>
void Stack<T>::copyStack(Stack const& ls) {
 	topNode = nullptr;
 	copy(ls.topNode);
}
template <typename T>
Stack<T>::Stack(Stack const& ls) {
 	copyStack(ls);
}
template <typename T>
Stack<T>& Stack<T>::operator=(Stack const& ls){
 	if (this != &ls) {
 		eraseStack();
 		copyStack(ls);
 	}
 	return *this;
}
int main(){
	Stack<int> a;
	int x;
	do{
		cin>>x;
		a.push(x);
	}while(x != 0);
	a.pop();
	while(!(a.empty())){
		cout<<a.pop()<<" ";
	}
	return 0;
}