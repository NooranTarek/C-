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
    Stack(Stack& copiedStack)
    {
        stackSize=copiedStack.stackSize;
        stackTop=copiedStack.stackTop;
        stackArray=new int [stackSize] {0};
        for (int i=0;i<stackSize;i++){
            stackArray[i]=copiedStack.stackArray[i];
        };
    }
    int getTop(){
        return stackTop;
    }
    int pushIntoStack (int data ){
        if (stackTop<(stackSize-1)){
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
    ~Stack (){
        cout<<"END"<<endl;
        delete [] stackArray;
    }

}; //end stack class :)
//void popTesting(Stack testedStack);
void popTesting(Stack& testedStack);
int main()
{
    Stack stack1;
    stack1.popFromStack();
    stack1.pushIntoStack(1);
    stack1.pushIntoStack(5);
    stack1.pushIntoStack(6);
    //stack1.printFromStack();
    stack1.popFromStack();//6
    stack1.popFromStack();//5
    stack1.pushIntoStack(7);
    stack1.popFromStack();//1
    stack1.popFromStack();//7
    stack1.popFromStack();//empty
    stack1.pushIntoStack(7);
    stack1.popFromStack();//7

    popTesting(stack1);//1
    stack1.pushIntoStack(6);
    stack1.pushIntoStack(7);

//    Stack originalStack=stack1;
    //stack1.pushIntoStack(20);
   // stack2.popFromStack();
    return 0;
}

    /*void popTesting(Stack testedStack){
        testedStack.popFromStack();
    }*/
    void popTesting(Stack& testedStack){
        testedStack.popFromStack();
    }
//pop empty
//push 1
//push 5
//push 6
//pop 1
//pop 5
//push 7
//pop 6
//pop7
//pop empty
//push 7
//pop7
