#include<iostream>
using namespace std;
// Binary search using recursion

int f(int* a,int t,int s,int e)
{
    // base case
    if (s>e){
        return -1;
    }
    // recursive case
    int m=s+(e-s)/2;
    if (a[m]==t)
    {
        return m;
    }
    else if (a[m]>t){
        //freien woerl
        return f(a,t,s,m-1);
    }
    else{
        //friend work
        return f(a,t,m+1,e);
    }
}

int main()
{
    int a[]={10,20,30,40,50};
    int n=sizeof(a)/sizeof(int);
    int t=40;
    cout<<f(a,t,0,n-1);

    return 0;
}