#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;

struct donater
{
        char  name[80];
        double money;
};


int main()
{
        ifstream fin;
        fin.open("./a.txt");
        if(!fin.is_open())
        {
                exit(EXIT_FAILURE);
        }
        int n;
        fin>>n;
        donater *pt= new donater [n];
        int i;
        for(i=0;i<n;i++)
        {
               fin.getline(pt[i].name,80);
               fin>>pt[i].money;
        }
        cout<<n<<endl;
        cout<<pt->money<<endl;
        cout<<"patrons"<<endl;
        cout<<"Grand patrons"<<endl;
        bool flag=false;
        for(i=0;i<n;i++)
        {
                if(pt[i].money>=10000)
                {
                        cout<<"name\t"<<pt[i].name<<'\t'<<"money:"<<pt[i].money<<endl;
                        if(!flag)
                                flag=true;
                }
        }
        if(!flag)
        {
                cout<<"None";
        }
        cout<<"Nomal patrons"<<endl;
        for(i=0;i<n;i++)
        {
                if(pt[i].money<10000)
                {
                        cout<<"name\t"<<pt[i].name<<'\t'<<"money:"<<pt[i].money<<endl;
                        if(!flag)
                                flag=true;
                }
        }
        fin.close();
        return 0;
}
