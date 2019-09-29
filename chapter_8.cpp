#include<iostream>
/*
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
*/

using namespace std;

void swap(int & a,int &b);

int main()
{
        int a=3,b=4;
        cout<<"a="<<a<<'\t'<<"b="<<b<<endl;
        swap(a,b);
        cout<<"a="<<a<<'\t'<<"b="<<b<<endl;
        return  0;
}

void swap(int & a,int & b)
{
        int c;
        c=a;
        a=b;
        b=c;
}