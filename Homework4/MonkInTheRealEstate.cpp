#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int numOfTestCases, linesOfTestCase, x, y, temp = 0;
	vector <int> container;
	cin>>numOfTestCases;
	for(int i = 0; i < numOfTestCases; i++){
		cin>>linesOfTestCase;
		for(int j = 0; j < linesOfTestCase; j++){
			cin>>x>>y;
			if(x == y && container.empty())
				container.push_back(x);
			else if(x == y && !container.empty()){
				if(find(container.begin(), container.end(), x) != container.end());
				else
					container.push_back(x);
			}
			else{
				if(find(container.begin(), container.end(), x) != container.end());
				else
					container.push_back(x);
				if(find(container.begin(), container.end(), y) != container.end());
				else
					container.push_back(y);
			}
		}
		cout<<container.size()<<endl;
		container.clear();
	}
	return 0;
}