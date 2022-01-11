#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    vector<int> tree(1000001);
    int mx = 0;
    for(int i=0;i<n;i++){
        cin>>tree[i];
        mx = max(mx, tree[i]);
    }
    int left = 0;
    int right = mx;
    int mid;
    int ans = -1;
    while(left<right){
        long long sum=0;
        mid = (left+right)/2;
        for(int i=0;i<n;i++){
            sum+=(tree[i]-mid)>0?tree[i]-mid:0;
        }
        if(sum>=m){
            ans = max(ans, mid);
            left = mid+1;
        }else{
            right = mid;
        }
    }

    cout<< ans;
    return 0;
}

