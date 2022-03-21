#include <iostream>
using namespace std;

class Diagonal
{
    private:
        int *A;
        int n;
    public:
        Diagonal()
        {
            n = 2;
            A = new int[2];
        }
        Diagonal(int n)
        {
            this->n=n;
            A = new int[n];
        }
        void set(int i, int j, int x);
        int get(int i, int j);
        void Display();
        ~Diagonal(){delete []A;}
};

void Diagonal::set(int i, int j, int x)
{
    if (i==j)
    {
        A[i-1]=x;
    }
}

int Diagonal::get(int i, int j)
{
    if (i==j)
    {
        return A[i-1];
    }
    else
        return 0;
}

void Diagonal::Display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i==j)
            {
                cout<<A[i]<<" ";
            }
            else
                cout<<"0 ";
            
        }
        cout<<endl;
    }
    
}
class lowerTriangular
{
    private:
        int *A;
        int n;
    public:
        lowerTriangular()
        {
            n=2;
            A=new int[2];
        }
        lowerTriangular(int n)
        {
            this->n=n;
            A=new int[n];
        }
        void set(int i, int j, int x);
        int get(int i, int j);
        void Display();
        ~lowerTriangular(){delete []A;}
};

void lowerTriangular::set(int i, int j, int x)
{
    if (i>=j)
    {
        A[i*(i-1)/2+j-1]=x;
    }
    
}
int lowerTriangular::get(int i, int j)
{
    if (i>=j)
    {
        return A[i*(i-1)/2+j-1];
    }return 0;
    
}
void lowerTriangular::Display()
{
        for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i>=j)
            {
                cout<<A[i*(i-1)/2+j-1]<<" ";
            }
            else
                cout<<"0 ";
            
        }
        cout<<endl;
    }
}
class upperTriangular
{
    private:
        int *A;
        int n;
    public:
        upperTriangular()
        {
            n=2;
            A=new int[2];
        }
        upperTriangular(int n)
        {
            this->n=n;
            A=new int[n];
        }
        void set(int i, int j, int x);
        int get(int i, int j);
        void Display();
        ~upperTriangular(){delete []A;}
};

void upperTriangular::set(int i, int j, int x)
{
    if (i<=j)
    {
        A[j*(j-1)/2+i-1]=x;
    }
    
}
int upperTriangular::get(int i, int j)
{
    if (i<=j)
    {
        return A[j*(j-1)/2+i-1];
    }return 0;
    
}
void upperTriangular::Display()
{
        for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i<=j)
            {
                cout<<A[j*(j-1)/2+i-1]<<" ";
            }
            else
                cout<<"0 ";
            
        }
        cout<<endl;
    }
}

int main()
{
    Diagonal m(5);

    m.set(1,1,5);m.set(2,2,7);m.set(3,3,4);m.set(4,4,8);m.set(5,5,5);
    m.Display();
    cout<<m.get(3,3)<<endl; 

    int d;
    cin>>d;

    lowerTriangular lt(d);

    int x;
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cin>>x;
            lt.set(i,j,x);
        }
        
    }
    lt.Display();
    cout<<endl;

    upperTriangular ut(d);

    int x1;
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cin>>x1;
            ut.set(i,j,x1);
        }
        
    }
    ut.Display();
    
}