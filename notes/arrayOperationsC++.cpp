#include <iostream>
using namespace std;

class Array
{
    private:
    //elements only accessed by member functions
    int *A; //pointer is taken so we can create a dynamically sized array
    int length;
    public:
    //member functions
    Array(int length) //constructor whitch will take values in main() function
    {
        this->length = length;
        A = new int[length]; //dynimically created an array of desired size in heap
    }
    ~Array() //used to release resouces we will be using
    {
        delete []A; //this will delete the dynamically created array in heap
    }
    void Display();
    void addElement(int x);
    void Insert(int index, int x);
    void set(int index, int x);
    int Delete(int index);
    void linearSearch(int key);
    void tlinearSearch(int key);
    int BinarySearch(int key);
    void revArr();
    int isSorted();
    void arrange();
};
void swap(int *x, int*y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
void Array::Display()
{
    for (int i = 0; i < length; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

void Array::addElement(int x){
    A[length] = x;
    length++;
}

void Array::Insert(int index, int x)
{
    if (index >= 0 && index <= length)
    {
        for (int i = length - 1; i >= index; i--)
        {
            A[i+1] = A[i];
        }
        A[index] = x;
        length++;
    }
}
void Array::set(int index, int x)
{
    if (index>=0 && index<=length)
    {
        A[index]=x;
    }
    
}
int Array::Delete(int index)
{
    int x = 0;
    if (index >= 0 && index < length)
    {
        x = A[index];
        for (int i = index; i < length - 1; i++)
        {
            A[i] = A[i+1];
        }
        length--;
    }
    return x;
}
void Array::linearSearch(int key)
{
    for (int i = 0; i < length; i++)
    {
        if (key==A[i])
        {
            cout<<i<<endl;
        }
        
    }
    
}
int Array::BinarySearch(int key)
{
    int l=0;
    int h=length;
    int mid;
     while (l<=h)
     {
         mid=(l+h)/2;
         if (A[mid]<key)
         {
             l=mid+1;
         }
         else if (A[mid]>key)
         {
             h=mid-1;
         }
         else
             break;
     }
     if (key==A[mid])
     {
         return mid;
     }
     else
        return -1;
}
void Array::revArr()
{
    int j=length-1;
    for (int i = 0; i<j; i++,j--)
    {
        swap(&A[i], &A[j]);
    }
    
}
int main(){

    int n;
    cin>>n;
    Array arr(n);
    
    
    int x;
    for (int i = 0; i < n; i++)
    {
        cin>>x;
        arr.set(i,x);
    }
    arr.Display();
    //arr.linearSearch(1);
    //cout<<arr.Delete(2)<<endl;
    //cout<<arr.BinarySearch(9);
    arr.revArr();
    arr.Display();
    return 0;
}