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
    int getReal (void)const
    {
        return real;

    }
    int getImage (void)const
    {
        return image;
    }
    void print (void)
    {
        //real+image j
        cout<<"the complex number is  = "<<real;
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
    //plus operator
    Complex operator + (Complex compPlus)
    {
        Complex plusResult;

        plusResult.real=real+compPlus.real;
        plusResult.image=image+compPlus.image;
        return plusResult;
    }
    //plus operator
    Complex operator + (int intPlus)
    {
        Complex plusResult;

        plusResult.real=real+intPlus;
        plusResult.image=image;
        return plusResult;
    }
    //minus operator
    Complex operator - (Complex compMinus)
    {
        Complex minusResult;

        minusResult.real=real-compMinus.real;
        minusResult.image=image-compMinus.image;
        return minusResult;
    }
    //minus operator
    Complex operator - (int intMinus)
    {
        Complex minusResult;

        minusResult.real=real-intMinus;
        minusResult.image=image;
        return minusResult;
    }
    //equality operator
    int operator == (Complex complexEquality)
    {
        if(real == complexEquality.real && image == complexEquality.image)
        {
            cout<< 1<<endl;
        }
        else
        {
            cout<< 0<<endl;
        }
    }
    //plus equal operator
    Complex operator += (Complex compPlusEqual)
    {
        real=real+compPlusEqual.real;
        image=image+compPlusEqual.image;
    }
    //prefix plus operator
    Complex operator++ ()
    {
        real=real+1;
        return *this;
    }
    //postfix plus operator
    Complex operator++ (int)
    {
        Complex Temp = *this;
        real=real+1;
        return Temp;
        //cout << Temp << endl;
    }
    //casting
    operator float()
    {
        return  real;
    }

    //square brackets
    int& operator[](int index)
    {
        if (index == 0)
        {
            return real;
        }
        else if (index == 1)
        {
            return image;
        }
        else
        {
            cout<< "Invalid index" <<endl;
        }
    }
    friend ostream& operator<<(ostream& out, const Complex& c);
    friend istream& operator>>(istream& in, Complex& c);
      //  friend std::ostream& operator<<(std::ostream& out, const Complex& c) {
   //     return out << c.real << "+" << c.image << "j";
   // }

    //friend std::istream& operator>>(std::istream& in, Complex& c) {
    //    return in >> c.real >> c.image;
   // }
};//End Class
//plus operator
Complex operator + (int intPlus, const Complex& ComplexPlus)
{
    Complex plusResult;
    plusResult.setReal(ComplexPlus.getReal() + intPlus);
    plusResult.setImage(ComplexPlus.getImage());
    return plusResult;
}
//minus operator
Complex operator - (int intPlus, const Complex& ComplexMinus)
{
    Complex minusResult;
    minusResult.setReal(ComplexMinus.getReal() - intPlus);
    minusResult.setImage(ComplexMinus.getImage());
    return minusResult;
}
ostream& operator<<(ostream& out, const Complex& c) {
        return out << c.real << "+" << c.image << "j";

}

istream& operator>>(istream& in, Complex& c) {
        return in >> c.real >> c.image;

}
int main()
{

    Complex mainInstanse1;
    Complex mainInstanse2;

    mainInstanse1.setReal(10);
    mainInstanse1.setImage(10);

    mainInstanse2.setReal(5);
    mainInstanse2.setImage(3);


    cout<<"_______________PLUS OPERATOR + _________________"<<endl;
    Complex Result1;
    Result1=mainInstanse1+mainInstanse2;
    Result1.print();
    cout<<"_______________MINUS OPERATOR - ________________"<<endl;
    Complex Result2;
    Result2=mainInstanse1-mainInstanse2;
    Result2.print();
    cout<<"_____________PLUS OPERATOR +num _______________"<<endl;
    Complex Result3;
    Result3=mainInstanse1+5;
    Result3.print();
    cout<<"___________MINUS OPERATOR -num ________________"<<endl;
    Complex Result4;
    Result4=mainInstanse1-5;
    Result4.print();
    cout<<"____________PLUS OPERATOR num+ _________________"<<endl;
    Complex Result5;
    Result5=5+mainInstanse1;
    Result5.print();
    cout<<"_________MINUS OPERATOR num- _________________"<<endl;
    Complex Result6;
    Result6=5-mainInstanse1;
    Result6.print();
    cout<<"____________EQUALITY OPERATOR == ______________"<<endl;
    mainInstanse2==mainInstanse1;
    cout<<"____________PLUS EQUAL OPERATOR += ____________"<<endl;
    mainInstanse2 += mainInstanse1;
    mainInstanse2.print();
    cout<<"____________POSTFIX OPERATOR c++ ______________"<<endl;
    mainInstanse2 =mainInstanse1++;
    mainInstanse2.print();
    cout<<"____________PREFIX OPERATOR ++c ______________"<<endl;
    mainInstanse2 =++mainInstanse1;
    mainInstanse2.print();
    cout<<"__________CASTING OPERATOR (float)____________"<<endl;
    cout<<(float) mainInstanse1<<endl;

    mainInstanse1[0]=2;
    // mainInstanse1[1]=1;
    // mainInstanse1[7]=1;
    mainInstanse1.print();
    Complex c20;
    cin >> c20;
    cout << "You entered: " << c20<<endl;
    return 0;
}

/*
c3 = c1 + c2;
c3 = c1 - c2;
c3 = c1 + 5;
c3 = c1 - 5;
c3 = 5 + c1;
c3 = 5 - c1;
c1 == c2;
c1 += c2;
++c1; //--c1;
c1 ++ ; // c1--;
(float)�c1;*/

//input &output streem
//square brackets


