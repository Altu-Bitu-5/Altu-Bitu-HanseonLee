#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int findEnd(int N){
    int n=665, count=0;
    string s;
    while(count!=N){
    s=to_string(n);
    for(int i=0; i<s.size()-2; i++){
        if(s[i]=='6' && s[i+1]=='6' && s[i+2]=='6'){//string vector에서 문자 비교하고 싶을 때 "" 쓰면 pointer error 발생!!
        // '7' 이런식으로 작은 따옴표 사용해줘야 한다. 문자열 비교하고 싶으면 .compare함수 사용하기
            count++;
            break;
        }
    }
    n++;
    }
    return --n;
    
    
}

int main()
{
    int N;
    
    //입력
    cin>>N;
    
    int result=findEnd(N);
    //연산
    cout<<result;

    return 0;
}
