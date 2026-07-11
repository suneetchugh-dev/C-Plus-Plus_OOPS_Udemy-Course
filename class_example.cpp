#include <iostream>
using namespace std;
//class is a blueprint of an object

class house
{
private: //this is us specifying the access modifier so that our data can be accessed
    int length =0 , breadth=0;

 public: void setData(int x, int y)
    {
        length=x;
        breadth =y;
    }


    public: void area()
    {
        cout << "area of the house " << length*breadth;
    }
};



//creating an object of class house
//here we will get an error that data is inaccessible it is rather private so it is because of a concept of access specifier
//public accesss specifier once defined we can access members of it.
int main()
{
    house h1; //to intialise a object => we give classname followed by object name => class_name object_name; //we can also do something like house h1,h2,h3; //this is how we can create multiple objects of a class
    //in multiple objects created from space object sperate variable of a object will get seperate memory allocation and will not be shared with other objects of the same class
    h1.setData(500,600); //this is how you call method of a class  => object_name.method_name(param1, param2, ...)
    h1.area();
    return 0;
}



//for member variable i can't write private because it will not be accessible outside the class so we have to use public access specifier to access it outside the class. //this will help us to hide our data
//for memeber function to update them i can write public because it will be accessible outside the class so we have to use public access specifier to access it outside the class.