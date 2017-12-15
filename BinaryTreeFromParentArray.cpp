#include <iostream>
#include <vector>
using namespace std;
template<typename T>
class Tree{
private:
	vector<T>parent;
	void Create(T prev_x){
		T x;
		char c;
		if(parent.empty()){
			cout<<"Root: ";
			cin>>x;
			parent.resize(x + 1);
			parent[x] = -1;
		}
		else{
			cout<<"Vertex: ";
			cin>>x;
			if(x >= parent.size())
				parent.resize(x + 1);
			parent[x] = prev_x;
		}
		cout<<"Left tree of: "<<x<<" y/n?";
		cin>>c;
		if(c == 'y'){
			prev_x = x;
			Create(prev_x);
		}
		cout<<"Right tree of: "<<x<<" y/n?";
		cin>>c;
		if(c == 'y'){
			prev_x = x;
			Create(prev_x);
		}
	}
public:
	Tree();
	Tree(Tree<T> const&);
	Tree& operator=(Tree<T> const&);
	~Tree();
	bool empty();
	void print();
	void Create();
	void CopyTree(Tree<T> const&);
	void DeleteTree();
};

template<typename T>
Tree<T>::Tree(){
	parent.clear();
}
template<typename T>
Tree<T>::Tree(Tree<T> const& other){
	CopyTree(other);
}
template<typename T>
Tree<T>& Tree<T>::operator=(Tree<T> const& other){
	if(this != other){
		DeleteTree();
		CopyTree(other);
	}
	return *this;
}
template<typename T>
Tree<T>::~Tree(){
	DeleteTree();
}
template<typename T>
bool Tree<T>::empty(){
	return parent.empty();
}
template<typename T>
void Tree<T>::print(){
	for(int i = 0; i < parent.size(); i++){
		cout<<parent[i]<<" ";
	}
}
template<typename T>
void Tree<T>::CopyTree(Tree<T> const& other){
	if(other.parent.size() > parent.size())
		parent.resize(other.parent.size());
	for(int i = 0; i < other.parent.size(); i++)
		parent[i] = other.parent[i];
}
template<typename T>
void Tree<T>::DeleteTree(){
	parent.clear();
}
template<typename T>
void Tree<T>::Create(){
	Create(T());
}
int main(){
	Tree<int>a, b;
	a.Create();
	cout<<a.empty()<<endl;
	a.print();
	cout<<endl;
	b.CopyTree(a);
	a.DeleteTree();
	b.print();
	cout<<endl;
	cout<<a.empty()<<endl;
	return 0;
}