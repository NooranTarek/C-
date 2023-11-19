#include <iostream>

using namespace std;
class Exception{
public:
    int statusCode;
    char *message;
};
int main()
{
    int x;
    int y;
    cout<<"please enter two number to divide them"<<endl;
    cin>>x>>y;
    try{
        if (y==0){
            throw "please take care that you have to enter non zero value";
        }
        if(y<0){
            throw 404;
        }
        if (y>0){
        Exception exption;
        exption.message="success divide by positive number ";
        exption.statusCode=100;
        throw exption;
        }
        cout<<x/y<<endl;;
    }
    catch (const char *message){
        cout<<message<<endl;
    }
    catch (int statusCode){
        if (statusCode==404){
            cout<<"error 404 page NOT FOUND you dived by negative number "<<endl;
        }
    }
    catch (Exception &exption){
        cout<<exption.message<<exption.statusCode<<endl;
    }
    catch (...){
        cout<<"default catch statement"<<endl;
    }
        return 0;
}
