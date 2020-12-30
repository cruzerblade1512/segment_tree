#include<iostream>
using namespace std;

void createSeg(int *arr,int *tree,int index,int s,int e)
{
    //BASE CONDITION
    //LEAF NODES
    if(s == e)
    {
        tree[index] = arr[s];
        return;
    }
    //EXIT CONDITION
    if(s > e)
        return;

    int mid = (s+e)/2;
    createSeg(arr,tree,2*index,s,mid);
    createSeg(arr,tree,2*index + 1,mid+1,e);

    int left = tree[2*index];
    int right = tree[2*index+1];

    tree[index] = min(left,right);


}
int main()
{
    int arr[] = {2,3,-1,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    int *tree = new int[4*n+1];
    createSeg(arr,tree,1,0,n-1);

    //tree array is 1 based indexing

    for(int j=1;j<4*n+1;j++)
    {
        cout<< tree[j] <<" ";
    }
    return 0;
}
