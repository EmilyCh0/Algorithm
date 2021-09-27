#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;
int find(int i){
    if(vec[i]==i){
        return i;
    }
    else{
        return vec[i]=find(vec[i]);
    }
}
void union_node(int x, int y){
    int tmpX, tmpY;
    tmpX=find(x);
    tmpY=find(y);
    if(tmpX==tmpY){
        return;
    }
    else{
        vec[tmpX]=tmpY;
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m, tmp;
    cin>>n>>m;
    vec.resize(n);
    for(int i=0;i<n;i++){
        vec[i]=i;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>tmp;
            if(tmp==1&& i<j){
                union_node(i,j);
            }
        }
    }
    vector<int> travel(m);
    int idx, parent=-1, tmpP;
    bool flag=false;
    for(int i=0;i<m;i++){
        cin>>idx;
        tmpP=find(idx-1);
        if(parent==-1){
            parent=tmpP;
        }
        else if(parent!=tmpP){
            flag=true;
            break;
        }
    }
    if(flag){
        cout<<"NO";
    }
    else{
        cout<<"YES";
    }

    return 0;
}