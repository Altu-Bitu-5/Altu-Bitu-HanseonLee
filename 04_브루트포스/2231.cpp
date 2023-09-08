#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int result(int N, int count){
    int sum=0, result=0;
    string s;
    for(int i=N-count*9; i<=N-1; i++){
        s=to_string(i);
        for(int j=0; j<s.size(); j++){
            sum+=stoi(string(1,s[j]));
        }
        sum+=i;
        if(sum==N){
            result=i;
            break;
        }
        sum=0;
    }
    return result;
}

int main()
{
    //변수 선언
    int N, sum=0, count=1, temp, answer=0;
    
    //입력
    cin>>N;
    
    //자리수 구하기
    temp=N;
    while(temp>10){
        temp/=10;
        count++;
    }
    
    answer=result(N, count);
    
    cout<<answer;
    
    return 0;
}
