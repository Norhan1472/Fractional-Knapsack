#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct Knapsack
{
    int WT;
    double Value;
    double Ratio;

    Knapsack(){}
    Knapsack(int wt,double value,double ratio)
    {
        WT=wt;
        Value=value;
        Ratio=ratio;
    }
    int getWT()
    {
        return WT;
    }
    double getValue()
    {
        return Value;
    }
    double getRatio()
    {
        return Ratio;
    }

};

vector<struct Knapsack>knap;
void addToCapacity(struct Knapsack k)
{
    knap.push_back(k);
}

bool compare(struct Knapsack first,struct Knapsack second)
{
    return (first.Ratio>second.Ratio);
}
void sorts()
{
    sort(knap.begin(),knap.end(),compare);
}
void print()
{
    sorts();
    for(int i=0;i<knap.size();i++)
    {
        cout<<"weight : "<<knap[i].getWT()<<endl;
        cout<<"value : "<<knap[i].getValue()<<endl;
        cout<<"ratio : "<<knap[i].getRatio()<<endl;
    }
}
double addToPackage(double Capacity)
{
    sorts();
    double finalValue=0;
    for(int i=0;i<knap.size();i++)
    {
        if(knap[i].getWT()<Capacity)
        {
           finalValue+=knap[i].getValue();
           Capacity-=knap[i].getWT();
        }
        else
        {
            double newratio=Capacity/knap[i].getWT();
            Capacity-=knap[i].getWT()*newratio;
            finalValue+=newratio*knap[i].getValue();
        }
    }
    return finalValue;
}
int main()
{
    int num;
    int wt;
    double val;
    double capacity;
    struct Knapsack k;
    cout<<"enter number of packages : ";
    cin>>num;
    for(int i=0;i<num;i++)
    {
        cout<<"enter the weight : ";
        cin>>wt;
        cout<<"enter the value : ";
        cin>>val;
        double rat=val/wt;
         Knapsack kn(wt,val,rat);
         addToCapacity(kn);
    }
    cout<<"Enter your capacity : ";
    cin>>capacity;
    cout<<"The maximum value is : "<<addToPackage(capacity)<<endl;
    return 0;
}
