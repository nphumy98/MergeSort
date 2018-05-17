#include <iostream>
#include<bits/stdc++.h>
using namespace std;

ifstream f("data.in");
ofstream g("data.out");

int A[10];

void join(int low,int mid, int high)
{
    int b[50],l1,m,l2;

    l1=low;
    m=mid;
    l2=low;

    while (l2<=high+1)
    {
        if (l1>mid)
        {
            b[l2]=A[m+1];
            m++;
        }
        else if (m+1>high)
        {
            b[l2]=A[l1];
            l1++;
        }
        else if ((A[l1]<=A[m+1]))
        {
            b[l2]=A[l1];
            l1++;
        }
        else if ((A[l1]>A[m+1]))
        {
            b[l2]=A[m+1];
            m++;
        }
        l2++;
    }
    //in ra
    for (int i=low; i<=high;i++)
    {
        A[i]=b[i];
    }
}

void merge_sort(int low, int high)
{
    int mid;
    if ((high-low)>=1)
    {
        mid=(high+low)/2;
        merge_sort(low,mid);
        merge_sort(mid+1,high);
        join(low, mid, high);
    }
}

int main()
{
    cout << "Hello world!" << endl;

    for (int i=1;i<=9;i++)
    {
        f>>A[i];
    }

    for (int i=1;i<=9;i++)
    {
        cout<<A[i]<<" ";
    }
    printf("\n");

    merge_sort(1,9);
    for (int i=1;i<=9;i++)
    {
        cout<<A[i]<<" ";
        g<<A[i];
    }
    printf("\n");
    return 0;
}
