#include <iostream>
using namespace std;

class element
{
private:
    /* data */
public:
    int i;
    int j;
    int x;
};
 class sprase
 {
 private:
     int m;
     int n;
     int num;
     element *e;
 public:
     sprase(int m, int n, int num)
     {
         this->m=m;
         this->n=m;
         this->num=num;
         e=new element[this->num];
     }
     ~sprase()
     {
         delete [] e;
     }
     friend istream & operator>>(istream &is, sprase &s);
     friend ostream & operator<<(ostream &os, sprase &s);
 };

    istream & operator>>(istream &is, sprase &s)
     {
         for (int i = 0; i < s.num; i++)
         {
             cin>>s.e[i].i>>s.e[i].j>>s.e[i].x;
         }
         return is;
     }
    ostream & operator<<(ostream &os, sprase &s)
     {
         int k=0;
         for (int i = 0; i <s.m; i++)
         {
             for (int j = 0; j <s.n; j++)
             {
                 if (s.e[k].i==i && s.e[k].j==j)
                 {
                     cout<<s.e[k++].x<<" ";
                 }
                 else
                    cout<<"0 ";
             }
             cout<<endl;
         }
         return os;
     }
 

 int main()
 {
     int m,n,num;
     cin>>m>>n>>num;
     sprase s1(m,n,num);

     cin>>s1;
     cout<<s1;

     return 0;
 }
 