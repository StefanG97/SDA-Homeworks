#include <iostream>
#include <queue>
using namespace std;
template<typename T>
struct node
{
    T inf;
    node<T> *left, *right;
};
template<typename T>
class BinTree
{
private:
    node<T>* root;
    void DeleteBinTree(node<T>* &) const;
    void Copy(node<T> * &, node<T>* const&) const;
    void CopyBinTree(BinTree<T> const&);
    void pr(const node<T> *) const;
    void CreateBinTree(node<T> * &) const;
    void help(node<T>* p);
public:
    BinTree();
    ~BinTree();
    BinTree(BinTree<T> const&);
    BinTree& operator=(BinTree<T> const&);
    T RootBinTree() const;
    BinTree<T> LeftBinTree() const;
    BinTree<T> RightBinTree() const;
    node<T>* GetRoot();
    bool empty() const;
    void print() const;
    void Create();
    void Create3(T, BinTree<T>, BinTree<T>);
    int findMaxHeight(node<T>*);
    void levelOrderTransversal(node<T>*);
    int check(node<T>*, long long int, long long int);
    bool checkBinarySearchTree(node<T>*);
    int findLCA(node<T>*, int, int);
    void HuffmanDecoding(node<T>*, string);
};
template<typename T>
BinTree<T>::BinTree()
{
    root = NULL;
}
template<typename T>
BinTree<T>::BinTree(BinTree<T> const& other)
{
    CopyBinTree(other);
}
template<typename T>
BinTree<T>& BinTree<T>::operator = (BinTree<T> const& other)
{
    if (this != &other)
    {
        DeleteBinTree(root);
        CopyBinTree(other);
    }
    return *this;
}
template<typename T>
T BinTree<T>::RootBinTree() const
{
    return root->inf;
}
template<typename T>
BinTree<T> BinTree<T>::LeftBinTree() const
{
    BinTree<T> t;
    Copy(t.root, root->left);
    return t;
}
template<typename T>
BinTree<T> BinTree<T>::RightBinTree() const
{
    BinTree<T> t;
    Copy(t.root, root->right);
    return t;
}
template<typename T>
node<T>* BinTree<T>::GetRoot()
{
    return root;
}
template<typename T>
bool BinTree<T>::empty() const
{
    return root==NULL;
}
template<typename T>
void BinTree<T>::print() const
{
    pr(root);
}
template<typename T>
void BinTree<T>::Create()
{
    CreateBinTree(root);
}
template<typename T>
void BinTree<T>::Create3(T x, BinTree<T> left, BinTree<T> right)
{
    node<T>* root = new node<T>;
    root->inf = x;
    Copy(root->left, left.root);
    Copy(root->right, right.root);
}
template<typename T>
int BinTree<T>::findMaxHeight(node<T>* p)
{
    int leftHeight = 0, rightHeight = 0;
 
    if (p->left) {
        leftHeight = 1 + findMaxHeight(p->left);
    }
    if (p->right != NULL) {
        rightHeight = 1 + findMaxHeight(p->right);
    }
 
    return leftHeight > rightHeight ? leftHeight: rightHeight;
}
template<typename T>
void BinTree<T>::help(node<T>* p)
{
    if (p->left)
        cout << p->left->inf << " ";
    if(p->right)
        cout<< p->right->inf << " ";
}
template<typename T>
void BinTree<T>::levelOrderTransversal(node<T>* p)
{
    queue <node<T>*> q;
    if(p){
        q.push(p);
        cout<<p->inf<<" ";
    }
    while(!q.empty()){
        const node<T>* const temp_node = q.front();
        q.pop();
        if(temp_node->left){
            q.push(temp_node->left);
            cout<<temp_node->left->inf<<" ";
        }
        if(temp_node->right){
            q.push(temp_node->right);
            cout<<temp_node->right->inf<<" ";
        }
    }

}
template<typename T>
BinTree<T>::~BinTree()
{
    DeleteBinTree(root);
}
template<typename T>
void BinTree<T>::DeleteBinTree(node<T>* &p) const
{
    if (p)
    {
        DeleteBinTree(p->left);
        DeleteBinTree(p->right);
        delete p;
        p = NULL;
    }
 }
 
template<typename T>
void BinTree<T>::Copy(node<T>* &pos, node<T>* const & r) const
{
    pos = NULL;
    if (r)
    {
        pos = new node<T>;
        pos->inf = r->inf;
        Copy(pos->left, r->left);
        Copy(pos->right, r->right);
    }
}
 
template<typename T>
void BinTree<T>::CopyBinTree(BinTree<T> const & other)
{
    Copy(root, other.root);
}
 
template<typename T>
void BinTree<T>::pr(const node<T>* p) const
{
    if (p)
    {
        pr(p->left);
        cout << p->inf<<" ";
        pr(p->right);
    }
}
 
template<typename T>
void BinTree<T>::CreateBinTree(node<T>*& p) const
{
    T x;
    cout << "Root: ";
    cin >> x;
    p = new node<T>;
    p->inf = x;
    p->left = NULL;
    p->right = NULL;
    char c;
    cout << "Left BinTree from " << x << " y/n ? ";
    cin >> c;
    if (c == 'y')
        CreateBinTree(p->left);
    cout << "Right BinTree from " << x << " y/n ? ";
    cin >> c;
    if (c == 'y')
        CreateBinTree(p->right);
}
template<typename T>
int BinTree<T>::check(node<T>* root, long long int min, long long int max){
       if(root){
            if(!((root->inf > min) && (root->inf < max))){
                return 0;
            }
            else{
                return (check(root->left, min, root->inf) && check(root->right, root->inf, max));
            }
       }
       return 1;
   }

template<typename T>
bool BinTree<T>::checkBinarySearchTree(node<T>* p){
    return check(p, -1, 9223372036854775807);
}
template<typename T>
int BinTree<T>::findLCA(node<T>* p, int n1, int n2){
    if(p->inf < n1 && p->inf < n2){
        return findLCA(root->right, n1, n2);
    }
    if(p->inf > n1 && p->inf > n2){
        return findLCA(root->left, n1, n2);
    }
    return root->inf;
}
template<typename T>
void BinTree<T>::HuffmanDecoding(node<T>* p, string s){
    string temp;
    node<T>* curr = root;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '1')
            curr = curr->right;
        else if(s[i] == '0')
            curr = curr->left;
        if(curr->left == NULL && curr->right == NULL){
            temp += curr->inf;
            curr = root;
        }
    }
    cout<<s<<" is decoded to: "<<temp<<endl;
}
int main()
{
    BinTree<char> b;
    BinTree<int>a
    //int n1, n2;
    string input;
    a.Create();
    cout<<a.findMaxHeight(a.GetRoot())<<endl;
    a.levelOrderTransversal(a.GetRoot());
    cout<<endl;
    cout<<a.checkBinarySearchTree(a.GetRoot())<<endl;
    if(a.checkBinarySearchTree(a.GetRoot())){
        cout<<"Enter first node: ";
        cin>>n1;
        cout<<"Enter second node: ";
        cin>>n2;
        cout<<"LCA of "<<n1<<" and "<<n2<<" is: "<<a.findLCA(a.GetRoot(), n1, n2)<<endl;    
    }
    cout<<"Input Char Tree:"<<endl;
    b.Create();
    cout<<"Input a string to be decoded: ";
    cin>>b;
    a.HuffmanDecoding(a.GetRoot(), b);
    return 0;
}