#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool can(vector<int>& A, int M, int lim){
    int seg = 1, cur = 0;
    for(int x:A){
        if((cur|x) <= lim) cur |= x;
        else{
            seg++;
            cur = x;
        }
    }
    return seg <= M;
}

int main(){
    int N,M; 
    cin>>N>>M;
    vector<int>A(N);
    for(int&i:A) cin>>i;

    int lo=0, hi=0;
    for(int x:A){
        lo=max(lo,x);
        hi|=x;
    }

    int ans=hi;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(can(A,M,mid)){
            ans=mid;
            hi=mid-1;
        }else lo=mid+1;
    }
    cout<<ans;
}
