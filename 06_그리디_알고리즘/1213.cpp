#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    //입력
    string str;
    cin>>str;
    vector<int> in(26);
    for(int i=0; i<str.size(); i++){
        in[str[i]-'A']++;
    }
    //연산
    int odd=0, odd_index=0;
    for(int i=0; i<in.size(); i++){
        if(in[i]%2==1){
            odd++;
            odd_index=i;
        }
    }
    if(odd>1) {
        cout<<"I'm Sorry Hansoo";
    }
    else{
        vector<char> p(str.size());
        int left=0, right=str.size()-1;
        
        for(int i=0; i<in.size(); i++){
            if(in[i]>0){
                for(int j=0; j<in[i]/2; j++){
                    p[left]=p[right]=i+'A';
                    left++; right--;
                }
            }
        }
        if(odd==1) p[str.size()/2]=odd_index+'A';
        
        //출력
        for(int i=0; i<p.size(); i++){
        cout<<p[i];
        }
        
    }
    return 0;
}