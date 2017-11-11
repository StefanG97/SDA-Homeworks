#include <iostream>
#include <stack>
using namespace std;

int main(){
	int n, type, input;
	stack <int> a;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>type;
		switch(type){
			case 1 : {
				cin>>input;
				if(a.empty()){
					a.push(input);
				}
				else{
					if(input > a.top()){
						a.push(input);
					}
					else{
						a.push(a.top());
					}
				}
				break;
			}
			case 2 : {
				if(!(a.empty())){
					a.pop();
				}
				break;
			}
			case 3 : {
				cout<<a.top()<<endl;
				break;
			}
			default:
				break;
		}
	}
	return 0;
}