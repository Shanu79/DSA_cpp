#include<iostream>
using namespace std;

int s;
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
        s=s+n;
        recursionAddFirstnNos(n-1);
    }
    return s;
}

int BacktrackRecursionAddFirstnNos(int n)
{
    if (n>0)
    {
        BacktrackRecursionAddFirstnNos(n-1);
        s=s+n;
    }
    return s;
}

int main()
{
    rprint(4);
    cout<<endl;
    rprintBacktracking(4);
    cout<<endl;
    //cout<<recursionAddFirstnNos(3);
    cout<<endl;
    cout<<BacktrackRecursionAddFirstnNos(7);
    return 0;
}