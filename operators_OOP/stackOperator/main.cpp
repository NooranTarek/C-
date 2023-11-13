#include <iostream>

using namespace std;
class Stack
{
private :
    int stackSize ;
    int stackTop;
    int *stackArray;

public :
    Stack()
    {
        stackSize=6;
        stackTop=-1;
        stackArray=new int [stackSize] {0};
    }
    Stack(int UserStackSize)
    {
        stackSize=UserStackSize;
        stackTop=-1;
        stackArray=new int [stackSize] {0};
    }
    int getTop(){
        return stackTop;
    }
    int pushIntoStack (int data ){
        if (stackTop<(stackSize-1)){
            cout<<"pushIntoStack "<<stackTop;
            stackTop++;
            stackArray[stackTop]=data;

            cout<<"the element you pushed is "<<stackArray[stackTop]<<endl;

        }
        else {
            cout<<"Sorry..the stack is already full you can't push into it "<<endl;
        }
    }
    int popFromStack(){
        if (stackTop!=-1){
            int element=stackArray[stackTop];
            stackTop--;
            cout<<"the element you poped is "<<element<<endl;
            return element;

        }
        else {
            cout<<"Sorry..the stack is already empty you can't pop from if "<<endl;
        }
    }
    void printFromStack(){
        for(int i=0; i <=stackTop; i++){
            cout<<"the element you pushed in index "<<i<<"is"<<stackArray[i]<<endl;
        }
    }
Stack& operator=(const Stack& stackEqual) {
    if (this != &stackEqual) { // Check for self-assignment
        stackTop = stackEqual.stackTop;
        stackSize = stackEqual.stackSize;

        delete[] stackArray;
        stackArray = new int[stackSize];

        for (int i = 0; i <= stackTop; i++) {
            stackArray[i] = stackEqual.stackArray[i];
        }
    }
    return *this;
}

    ~Stack (){
        cout<<"END"<<endl;
        delete [] stackArray;
    }

}; //end stack class :)
int main()
{
    Stack stack1;
    Stack stack2;
    Stack stack3;
    stack1.pushIntoStack(1);
    stack1.pushIntoStack(5);
    stack2.pushIntoStack(2);
    stack3=stack1=stack2;
    stack3.printFromStack();
  return 0;
}

