#include <iostream>
#include <stack>
using namespace std;
class queue {
private :
   stack<int> s1, s2;
public  :
   void enqueue(int element);
   int dequeue();
   int getFrontElement();
   void shiftStacks();
};
void queue :: shiftStacks(){
   if(s2.empty()){
      while(!s1.empty()){
         s2.push(s1.top());
         s1.pop();
      }
   }
}
void queue :: enqueue(int element) {
   s1.push(element);
}
int queue :: dequeue() {
   shiftStacks();
   int temp = s2.top();
   s2.pop();
   return temp;
}
int queue :: getFrontElement(){
   shiftStacks();
   return s2.top();
}
int main() {
   int n, type, input;
   queue testQueue;
   cin>>n;
   for(int i = 0; i < n; i++){
      cin>>type;
      switch(type){
         case 1:{
            cin>>input;
            testQueue.enqueue(input);
            break;
         }
         case 2:{
            testQueue.dequeue();
            break;
         }
         case 3:{
            cout<<testQueue.getFrontElement()<<endl;
            break;
         }
      }
   }
   return 0;
}