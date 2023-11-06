#include <iostream>
#include <queue>

using namespace std;

void josep(queue<int> q, int N, int K){
    int r;
    
    cout<<"<";//이걸 for문 안에 넣을 경우 반례 1, 1에서 출력이 이상하게 된다.
    
    for(int i=N; i>1; i--){
        for(int j=0; j<K; j++){
            if(j==K-1){
                r=q.front();
                q.pop();
                cout<<r<<", ";
            }
            else{
                r=q.front();
                q.pop();
                q.push(r);
            }
        }
    }
    r=q.front();
    cout<<r<<">";
}

int main() {
    
    //기본 변수 선언
    int N, K;
    queue<int> q;
    
    //입력
    cin>>N>>K;
    
    for(int i=1; i<=N; i++){
        q.push(i);
    }
    
    //출력
    josep(q,N,K);
    
    return 0;
}






