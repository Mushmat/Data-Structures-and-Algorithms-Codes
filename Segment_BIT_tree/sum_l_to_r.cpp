#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
int a[N], tree[4*N];

void build(int node, int s, int e){
    if(s == e){
        tree[node] = a[s];
        return;
    }
    int mid = (s+e)/2;
    build(2*node, s, mid);
    build(2*node + 1, mid+1,e);
    
    tree[node] = tree[2*node] + tree[2*node+1];
}
int sumitoj(int node, int s, int e, int l, int r){
    if(s > r || e < l){
        return 0;
    }
    if(l <= s && e <= r){
        return tree[node];
    }
    int mid = (s+e)/2;
    int q1 = sumitoj(2*node, s, mid, l, r);
    int q2 = sumitoj(2*node + 1, mid + 1, e, l, r);
    return q1 + q2;
}

int main(){
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        int temp;
        cin>>temp;
        a[i] = temp;
    }
    build(1,0,n-1);
    int x = sumitoj(1,0,n-1,2,6);
    cout<<"The sum from 2nd index to 5th index is: "<< x <<endl;

} 
