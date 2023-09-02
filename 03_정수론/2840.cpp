#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct wheel{
    int n;
    string s="";
};

string wheelF(vector<wheel> &w, vector<string> &ans,int N, int K){//출력을 간단히 하기 위해 ans 벡터를 인자로 가져옴.
    int temp=0;
    for(int i=0; i<K; i++){
        temp = (temp+w[i].n) % N;
        if(ans[temp] != ""&&ans[temp]!=w[i].s){
            return "!";
        }
        auto it=find(ans.begin(), ans.end(), w[i].s);//중복 제거를 안해주면 틀린다.
        if(!(it==ans.end())&&ans[temp]!=w[i].s){
            return "!";
        }
        ans[temp] = w[i].s;
    }
    for(int i=0; i<N; i++){
        if(ans[i] == ""){
            ans[i] = "?";
        }
    }
    return "";
}

int main()
{
    //변수 선언
    int N, K, sum=0;
    
    //입력
    cin>>N>>K;
    
    vector<wheel> w(K);//K만큼 할당 안해주고 값 입력받으면 for 문 안돌아간다.
    vector<string> ans(N, "");
    
    for(int i=0; i<K; i++){
        cin>>w[i].n>>w[i].s;
        sum+=w[i].n;
    }
    string str;
    str=wheelF(w,ans, N, K);
    
    //출력
    if(str=="!"){
        cout<<str;
    }
    else{
        int n=sum%N;//출력 시작 인덱스
        n+=N;
        for(int i=n+N; i>n; i--){
            cout<<ans[i%N];
        }
    }
    return 0;
}
