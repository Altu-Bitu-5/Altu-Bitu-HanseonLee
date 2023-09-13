#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int bruteforce(int n){
    for(int i=1; i<n; i++){
        //분해합 구하기
        int tmp=i;
        int sum=i;//분해합 저장하기

        while(tmp>0){
            sum+=tmp%10;
            tmp/=10;
        }
        if(sum==n) return i;
    }
    return 0;
}

int main()
{
    //입력
    int n;
    cin>>n;

    cout<<bruteforce(n);
    
    return 0;
}
