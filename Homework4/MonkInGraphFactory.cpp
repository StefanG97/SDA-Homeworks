#include <iostream>
using namespace std;
int main(){
	int num_of_vertices, vertices, sum = 0;
	cin>>num_of_vertices;
	for(int i = 0; i < num_of_vertices; i++){
		cin>>vertices;
		sum += vertices;
	}
	if((sum / 2) == (num_of_vertices - 1)){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
	return 0;
}