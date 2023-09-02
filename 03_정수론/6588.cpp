#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int RANGE=10000001;

struct gold{
    int a, b;//vector<int>를 여기다가 넣어서 한번에 처리하고 싶었는데 그러면 입력받는 코드 짜기가 어려워서 따로 뺐다.

    string s;
};

vector<bool> isPrime(){
    vector<bool> is_prime(RANGE, true);

    is_prime[0]=is_prime[1]=false;
    
    for(int i=2; i<sqrt(RANGE); i++){
        if(is_prime[i]){//i가 소수라면
            for(int j=i*i; j<=RANGE; j+=i){
                is_prime[j]=false;
            }
        }
    }
    return is_prime;
}

vector<gold> goldbach(vector<int> n, vector<bool> &is_prime){//is_prime을 받을 때 &로 안받고 계속 메모리 새로 받는 것으로 했더니 시간 초과랑 runtime error : double free~ 떴었다.
    //변수 선언
    vector<gold> g(n.size());
    
    int temp;
    //소수 구하기 1000000이하의 짝수
    for(int i=0; i<n.size(); i++){
        for(int j=2; j<=n[i]; j++){//여기서 sqrt(n[i])하면 값이 2.8...가 나오기 때문에 sqrt를 하려면 반올림을 이용해 줘야 한다.
            if (is_prime[j]){
                temp=n[i]-j;
            }
            if(is_prime[temp]){
                g[i].a=j;
                g[i].b=temp;
                break;
            }
        }
        if(g[i].a==0) g[i].s="Goldbach's conjecture is wrong";
    }
    return g;
    
}


int main()
{
    //변수 선언
    vector<int> n;
    vector<gold> g;
    int temp;
    int num;
    
    //입력
    while(cin>>temp&& temp!=0){
        n.push_back(temp);
    }
    
    vector<bool> is_prime=isPrime();
    
    g=goldbach(n, is_prime);
    
    //출력
    for(int i=0; i<g.size(); i++){
        if(g[i].s!=""){
            cout<<g[i].s<<"\n";
        }
        else
            cout<<n[i]<<" = "<<g[i].a<<" + "<<g[i].b<<'\n';
    }
    return 0;
}
