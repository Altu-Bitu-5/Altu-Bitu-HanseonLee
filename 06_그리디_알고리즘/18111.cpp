#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> mine(vector<int> g, int B){
    vector<int> ans(2);
    
    int max=*max_element(g.begin(), g.end());
    int min=*min_element(g.begin(), g.end());
    
    int s=0;
    int insert_count=0;
    int delete_count=0;

    while(max!=min){
        for(int i=0; i<g.size(); i++){
            if(g[i]==min) insert_count++;
            if(g[i]==max) delete_count+=2;
        }
        if(insert_count<=delete_count){
            if(insert_count<=B){
                for(int i=0; i<g.size(); i++){
                    if(g[i]==min){
                        g[i]++;
                        s++;
                        B--;
                    }
                }
            }
            else{
                for(int i=0; i<g.size(); i++){
                    if(g[i]==max){
                        g[i]--;
                        s+=2;
                        B++;
                    }
                }
            }
        }
        else{
            for(int i=0; i<g.size(); i++){
                if(g[i]==max){
                    g[i]--;
                    s+=2;
                    B++;
                }
            }
        }
        max=*max_element(g.begin(), g.end());
        min=*min_element(g.begin(), g.end());
        insert_count=delete_count=0;
    }
    
    ans[0]=s;
    ans[1]=g[0];
    
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //변수선언
    int N, M, B;
    cin>>N>>M>>B;
    
    vector<int> g(N*M);
    
    //입력
    for(int i=0; i<N*M; i++){
        cin>>g[i];
    }
    //연산
    vector<int> answer=mine(g, B);
    
    //출력
    cout<<answer[0]<<" "<<answer[1];

    return 0;
}