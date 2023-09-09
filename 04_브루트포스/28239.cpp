#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

//비트마스크 : 메모리 효율적, 시간 빠름
typedef long long ll;
const int MAX=60;//10^18이 약 2^60 정도 되기 때문

pair<int, int> getPair(ll m){
    int x, y;

    //m이 2의 제곱수인 경우(m=2^i)
    //m=2^(i-1)+2^(i-1)
    //x=y=i-1
    for(int i=0; i<MAX; i++){
        //m==2^i, 
        if(m==((ll)i<<i)){//60까지하면 오버플로우 발생
            return {i-1, i-1};
        }
    }

    //m이 2의 제곱수가 아닌경우
    //m=2^x+2^y
    for(x=0; x<MAX; x++){
        if(m & (1<<x)){//x번째 비트가 1이면, 
            break;
        }
        for(y=x+1; y<MAX; y++){
            if(m&((ll)1<<y)){//y번째 비트가 1이면
                break;
            }
        }

    }
    return {x, y};
}

int main(){
    //입력
    int n;
    ll m;
    pair<int, int> ans;
    cin>>n;
    while(n--){
        cin>>m;
        ans=getPair(m);
    }
    cout<<ans.first<<" "<<ans.first+1; 
    return 0;
}
