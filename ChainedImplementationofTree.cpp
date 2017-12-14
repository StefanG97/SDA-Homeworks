#include <iostream>
#include <vector>
using namespace std;
template<typename T>
class Tree{
private:
	vector <T> vertices;
	vector <T> leftSubTree;
	vector <T> rightSubTree;
	int RootIndex;
	void CopyTree(Tree<T> const&);
	void DeleteTree();
	void pr(int);
public:
	Tree();
	~Tree();
	Tree(Tree<T> const&);
	Tree& operator=(Tree<T> const&);
	bool empty();
	T GetRoot();
	void print();
	void Create();
	void printArrays();
};
template<typename T>
Tree<T>::Tree(){
	vertices.clear();
	leftSubTree.clear();
	rightSubTree.clear();
	RootIndex = 0;
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
	return vertices.empty();
}
template<typename T>
T Tree<T>::GetRoot(){
	return vertices[RootIndex];
}
template<typename T>
void Tree<T>::print(){
	pr(RootIndex);
}
template<typename T>
void Tree<T>::CopyTree(Tree<T> const& other){
	RootIndex = other.RootIndex;
	for(int i = 0; i < other.vertices.size(); i++){
		vertices[i] = other.vertices[i];
		leftSubTree[i] = other.leftSubTree[i];
		rightSubTree[i] = other.rightSubTree[i];
	}
}
template<typename T>
void Tree<T>::DeleteTree(){
	vertices.clear();
	leftSubTree.clear();
	rightSubTree.clear();
}
template<typename T>
void Tree<T>::pr(int index){
	if(leftSubTree[index] != -1)
		pr(leftSubTree[index]);
	cout<<vertices[index]<<" ";
	if(rightSubTree[index] != -1)
		pr(rightSubTree[index]);
}
template<typename T>
void Tree<T>::Create(){
	T x;
	char c;
	int temp = vertices.size();
	if(vertices.empty()){
		cout<<"Root: ";
		cin>>x;
		vertices.push_back(x);
		rightSubTree.push_back(-1);
	}
	else{
		cout<<"Vertex: ";
		cin>>x;
		vertices.push_back(x);
		rightSubTree.push_back(-1);
	}
	cout<<"Left tree of: "<<x<<" y/n?";
	cin>>c;
	if(c == 'y'){
		leftSubTree.push_back(vertices.size());
		Create();
	}
	else if(c == 'n'){
		leftSubTree.push_back(-1);
	}
	cout<<"Right tree of: "<<x<<" y/n?";
	cin>>c;
	if(c == 'y'){
		rightSubTree[temp] = vertices.size();
		Create();
	}
	else if(c == 'n'){
		rightSubTree[temp] = -1;
	}
}
template<typename T>
void Tree<T>::printArrays(){
	for(int i = 0; i < vertices.size(); i++)
		cout<<vertices[i]<<" ";
	cout<<endl;
	for(int i = 0; i < vertices.size(); i++)
		cout<<leftSubTree[i]<<" ";
	cout<<endl;
	for(int i = 0; i < vertices.size(); i++)
		cout<<rightSubTree[i]<<" ";
	cout<<endl;
}

int main(){
	Tree<int>a;
	a.Create();
	cout << a.empty() << " " << a.GetRoot() << endl;
	a.printArrays();
	cout << endl;
	a.print();
	return 0;
}