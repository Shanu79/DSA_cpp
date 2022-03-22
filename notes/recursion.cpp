#include<iostream>
using namespace std;
int f=1;
void rprint(int n)
{
    if(n>0)
    {
        cout<<n<<" ";
        rprint(n-1);
        //first print then function call
    }
}
void rprintBacktracking(int n)
{
    if(n>0)
    {
        rprintBacktracking(n-1);
        cout<<n<<" ";
        //first call then print while function returning
    }
}

int recursionAddFirstnNos(int n)
{
    if (n>0)
    {
        n=n+recursionAddFirstnNos(n-1);
    }
    return n;
}

int recursionFactorial(int n)
{
    if (n>=1)
    {
        f=f*n;
        recursionFactorial(n-1);
    }
    return f;
}

int recursionPower(int n,int p)
{
    if (p>1)
    {
        n=n*recursionPower(n,p-1);                
    }
    return n;
}

int main()
{
    rprint(4);
    cout<<endl;
    rprintBacktracking(4);
    cout<<endl;
    cout<<recursionAddFirstnNos(100);
    cout<<endl;
    cout<<recursionFactorial(9);
    cout<<endl;
    cout<<recursionPower(9,7);
    return 0;
}