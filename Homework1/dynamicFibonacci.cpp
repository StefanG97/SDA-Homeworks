#include<iostream>
using namespace std;
unsigned long long DynamicFibSeries(unsigned long long x){
    unsigned long long *fib = new unsigned long long [x+1];
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i <= x; i++)
        fib[i] = fib[i-1] + fib[i-2];
    return fib[x];
    delete [] fib;
}
int main(){
    unsigned long long n;
    cin>>n;
        cout<<DynamicFibSeries(n);
    return 0;
}
