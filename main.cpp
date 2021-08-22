#include <iostream>
using namespace std;

void afisare_vector(int v[100],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void schimba(int &a,int &b)
{
     int aux=a;
     a=b;
     b=aux;
} 

int partitie(int v[100],int l,int r)
{
    int pivot=v[r];
    int i=(l-1);
    int j;
    for(j=l;j<=r-1;j++)
    {
        if(v[j]<pivot)
        {
            i++;
            schimba(v[i],v[j]);
        }
    }
    schimba(v[i+1],v[r]);
    return (i+1);
}

void quick_sort(int v[100],int l,int r)
{
    if(l<r)
    {
        int pivot=partitie(v,l,r);
        quick_sort(v,l,pivot-1);
        quick_sort(v,pivot+1,r);
    }
}


int main()
{
    int v[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    quick_sort(v,0,n-1);
    afisare_vector(v,n);
}