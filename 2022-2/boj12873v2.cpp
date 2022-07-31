#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        vec[i]=i+1;
    }
    auto idx = vec.begin();
    for(int i=1;i<n;i++){
        long long tmp = pow(i,3);
        int rem = tmp%vec.size();
        if(rem==0){
            rem = vec.size();
        }
        for(int j=0;j<rem-1;j++){
            idx++;
            if(idx==vec.end()){
                idx = vec.begin();
            }
        }
        idx = vec.erase(idx);
        if(idx == vec.end()){
            idx = vec.begin();
        }
    }
    cout<<vec[0];
}