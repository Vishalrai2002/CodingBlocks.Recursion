#include<iostream>
using namespace std;
// last occurence
int f(int* a,int t,int i, int count)
{
    // base case
    if (i==-1){
        return -1;
    }
    if (a[i]==t){
        return count-i-1;
    }
    // Recursive case
    return f(a,t,i-1, count);
}

int main()
{
    int a[]={10,20,30,40,50};
    int n=sizeof(a)/sizeof(int);
    int t=20;
    int count=n;
    cout<<f(a,t,n-1,count)<<endl;
    return 0;
}
