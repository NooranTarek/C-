#include <iostream>

using namespace std;
template <typename T>
class Stack
{
private :
    int stackSize ;
    int stackTop;
    T *stackArray;

public :
    Stack()
    {
        stackSize=6;
        stackTop=-1;
        stackArray=new T [stackSize] {0};
    }
    Stack(int UserStackSize)
    {
        stackSize=UserStackSize;
        stackTop=-1;
        stackArray=new T [stackSize] {0};
    }
    int getTop(){
        return stackTop;
    }
    void pushIntoStack (T data ){
        if (stackTop<(stackSize-1)){
            stackTop++;
            stackArray[stackTop]=data;

            cout<<"the element you pushed is "<<stackArray[stackTop]<<endl;

        }
        else {
            cout<<"Sorry..the stack is already full you can't push into it "<<endl;
        }
    }
    void popFromStack(){
        if (stackTop!=-1){
            int element=stackArray[stackTop];
            stackTop--;
            cout<<"the element you poped is "<<element<<endl;
          //  return element;

        }
        else {
            cout<<"Sorry..the stack is already empty you can't pop from if "<<endl;
        }
       // return -100;
    }
    void printFromStack(){
        for(int i=0; i <=stackTop; i++){
            std:cout<<"the element you pushed in index "<<i<<"is"<<stackArray[i]<<endl;
        }
    }
    ~Stack (){
        cout<<"END"<<endl;
        delete [] stackArray;
    }

}; //end stack class :)
int main()
{
    Stack<int> stack1;
    stack1.popFromStack();
    stack1.pushIntoStack(1);
    stack1.pushIntoStack(5);
    //stack1.printFromStack();
    stack1.popFromStack();
   // stack1.popFromStack();

    return 0;
}

