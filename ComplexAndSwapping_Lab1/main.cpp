#include <iostream>

using namespace std;

class Complex
{
private:

    int real;
    int image;

public:

    void setReal (int realValue)
    {
        real=realValue;

    }
    void setImage (int imageValue)
    {
        image=imageValue;

    }
    int getReal (void)
    {
        return real;

    }
    int getImage (void)
    {
        return image;
    }
    void print (void)
    {
        //real+image j
        cout<<"the real number that you entered is  = "<<real;
        if (image>0)
        {
            cout<<" + "<<image<<"j";
        }
        else if (image<0)
        {
            cout<<image<<"j";
        }
        cout<<endl;
    }
    Complex Addition (Complex comp2)
    {
        Complex additionResult; //to put the result of comp1 and comp2 together
        additionResult.real=real+comp2.real; //adding the two reals
        additionResult.image=image+comp2.image; // adding the two images
        return additionResult;
    }
    Complex Subtraction (Complex comp2)
    {
        Complex subtractionResult; //to put the result of comp1 and comp2 together
        subtractionResult.real=real-comp2.real; //subtracting the two reals
        subtractionResult.image=image-comp2.image; // subtracting the two images
        return subtractionResult;
    }
};
void print2(Complex c);
Complex Addition (Complex comp1,Complex comp2);
Complex Subtraction (Complex comp1,Complex comp2);
void swapByValue(int value1,int value2);
void swapByAddress(int *value1,int *value2);
void swapByReference(int &value1,int &value2);
int main()
{

    Complex mainInstanse1;
    Complex mainInstanse2;

    mainInstanse1.setReal(10);
    mainInstanse1.setImage(10);

    mainInstanse2.setReal(5);
    mainInstanse2.setImage(3);

    Complex _additionResult;

    cout << "The result of addition: ";
    _additionResult=mainInstanse1.Addition(mainInstanse2);
    _additionResult.print();

    Complex _subtractionResult;

    cout << "The result of subtraction: ";
    _subtractionResult=mainInstanse1.Subtraction(mainInstanse2);
    _subtractionResult.print();
    //print2(mainInstanse1);

    Complex subtractionResult;
    Complex additionResult;

    additionResult=Addition(mainInstanse1,mainInstanse2);
    additionResult.print();
    subtractionResult=Subtraction(mainInstanse1,mainInstanse2);
    subtractionResult.print();
    int var1=1;
    int var2=3;
    swapByValue(var1,var2);
    //swapByAddress(&var1,&var2);
    //cout<<var1<<" ";
    //cout<<var2<<endl;
    swapByReference(var1,var2);
    cout<<var1<<" ";
    cout<<var2;


    return 0;
}
void print2(Complex c)
{
    //real+image j
    cout << "the complex number that you entered is  = " << c.getReal();
    if (c.getImage() > 0)
    {
        cout << " + " << c.getImage() << "j";
    }
    else if (c.getImage() < 0)
    {
        cout << c.getImage() << "j";
    }
    cout << endl;
}
Complex Addition (Complex comp1,Complex comp2)
{
    Complex additionResult; //to put the result of comp1 and comp2 together
    additionResult.setReal(comp1.getReal()+comp2.getReal()); //adding the two reals
    additionResult.setImage(comp1.getImage()+comp2.getImage()); // adding the two images
    return additionResult;
}
Complex Subtraction (Complex comp1,Complex comp2)
{
    Complex subtractionResult; //to put the result of comp1 and comp2 together
    subtractionResult.setReal(comp1.getReal()-comp2.getReal()); //subtracting the two reals
    subtractionResult.setImage(comp1.getImage()-comp2.getImage()); // subtracting the two images
    return subtractionResult;
}


void swapByValue(int value1,int value2)
{
    int temp;
    temp=value1;
    value1=value2;
    value2=temp;
    cout<<value1<<" "<<value2<<endl;
}

void swapByAddress(int *value1,int *value2)
{
    *value1=*value1+*value2;
    *value2=*value1-*value2;
    *value1=*value1-*value2;

}
void swapByReference(int &value1,int &value2)
{
    value1=value1+value2;
    value2=value1-value2;
    value1=value1-value2;

}


