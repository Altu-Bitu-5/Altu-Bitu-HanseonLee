#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<char> s;

int samestructCheck(vector<char> cmp){//cmp가 s에 포함된다면~ 을 check 포함관계인지 
    //다른 문자의 개수를 n으로 세기
    //같은 구성이라면
    int k=0;//s에 포함되지 않는 cmp의 문자 종류의 개수
    int flag=0;
    if(cmp.size()<s.size()) swap(cmp, s);
    for(int i=0; i<s.size(); i++){
        for(int j=0; j<cmp.size(); j++){
            if(s[i]==cmp[j]){
                flag=1;
                break;
            }
        }
        if(flag!=1) k++;
        flag=0;
    }
    return k;
    
}
void wordCheck(int &count, string in){
    vector<char> cmp(in.size());
    
    for(int i=0; i<in.size(); i++){
        cmp.push_back(in[i]);
    }
    
    int k=samestructCheck(cmp);
    int size=s.size()-cmp.size();
    
    if(k==0||k==1){
        if(size>-2 && size<2){
            count++;
            return;
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);
    
    int n, count=0;
    cin>>n;
    cin.ignore();
    
    vector<string> in(n-1);
    
    string str;
    cin>>str;
    cin.ignore();
    
    for(int i=0; i<n-1; i++){
        cin>>in[i];
        cin.ignore();
    }
    
    for(int i=0; i<str.size(); i++){
        s.push_back(str[i]);
    }
    
    for(int i=0; i<in.size(); i++){
        wordCheck(count, in[i]);
    }
    cout<<count;

    return 0;
}