#include <iostream>
#include <vector>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    //입력
    int n;
    unsigned long long ans;//int는 ans 연산 과정 중에서 범위초과라서 long long으로 써줌
    
    cin>>n;
    
    vector<int> in(n);
    for(int i=0; i<n; i++){
        cin>>in[i];
    }
    
    //연산
    ans=in[n-1];//이거 초기화 안해줬더니 79%에서 틀림
    for(int i=n-1; i>=0; i--){
        if(ans<in[i]) ans=in[i];
        else if(ans>in[i]){ //in[i]와 가장 가까운 배수로 초기화
            if(ans%in[i]){
                ans=((ans/in[i])+1)*in[i];//이렇게 안하고 for문으로 하니까 시간초과
            }
        }
    }

    //출력
    cout<<ans;
    
    return 0;
}
