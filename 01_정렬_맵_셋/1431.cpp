#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

struct serial{
    string s;
    int len, sum=0;
};

bool cmp(const serial& s1, const serial& s2){
    if (s1.len!=s2.len)//자리수가 같으면
        return s1.len<s2.len;
    if(s1.sum!=s2.sum)//숫자의 합이 같으면
        return s1.sum<s2.sum;//합이 작은 것이 먼저온다
    
    return s1.s<s2.s; //이름이 사전순으로 증가
  
}

int main() {
    int n;
    vector<serial> myserial;
    
    //입력
    cin >> n;
    myserial.assign(n, {});
    
    for (int i = 0; i < n; i++) {
        cin >> myserial[i].s;
        myserial[i].len=myserial[i].s.length();
        for(int j=0; j<myserial[i].len; j++){
            if(myserial[i].s[j]>=48 &&myserial[i].s[j]<58)
                myserial[i].sum+=myserial[i].s[j]-'0';    
        }
    }
    
    sort(myserial.begin(), myserial.end(), cmp);
    
    for(int i=0; i<n; i++){
        cout<<myserial[i].s<<"\n";
    }
    return 0;
}






