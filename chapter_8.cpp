#include<iostream>

inline double cube(double);

using namespace std;

int main()
{
        double x;
        cout<<"give the x"<<endl;
        cin>>x;
        cout<<cube(x)<<endl;
}

inline double cube(double x)
{
        return x*x*x;
}