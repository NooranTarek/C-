#include <iostream>

using namespace std;

class Queue
{
private:
    int queueFront;
    int queueRear;
    int queueSize;
    int *queueArray;
public:
    Queue()
    {
        queueSize=6;
        queueFront=queueRear=-1;
        queueArray=new int [queueSize] {0};
        cout<<"End Queue ";
    }
    Queue(int userQueueSize)
    {
        queueSize=userQueueSize;
        queueRear=queueFront=-1;
        queueArray=new int [queueSize] {0};
    }
    int enqueue(int data)
    {
        if (queueRear<queueSize-1)
        {
            queueRear++;
            queueArray[queueRear]=data;
            cout << "the element you enque is" << queueArray[queueRear]<<endl;

        }
        else
        {
            cout<<"sorry queue is already full"<<endl;
        }
    }
    int dequeue()
    {
        if (queueFront != queueRear)
        {
            int element = queueArray[queueFront + 1];
            queueFront++;
            cout << "the element you deque is" << element<<endl;

            return element;
        }
        else
        {
            cout << "sorry queue is already empty" << endl;
        }
    }
        void printFromQueue(){
        for(int i=queueFront+1; i <=queueRear; i++){
            cout<<"the element you pushed in index "<<i<<"is"<<queueArray[i]<<endl;
        }
    }
        ~Queue (){
        cout<<"END"<<endl;
        delete [] queueArray;
    }

};//end of queue class


int main()
{
    Queue queue1;
    queue1.dequeue();
    queue1.enqueue(5);
    queue1.enqueue(7);
    queue1.enqueue(10);
    queue1.dequeue();
    queue1.dequeue();
    queue1.enqueue(11);
    queue1.dequeue();
    queue1.dequeue();
    queue1.dequeue();

    queue1.printFromQueue();
    return 0;
}
//enq 5
//enq 7
//enq 10
//deq 5
//deq 7
