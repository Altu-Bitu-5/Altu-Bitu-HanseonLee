#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> find_two(vector<int> n, int sum){
    vector<int> ij;//이 부분 어색한데 return 이 for문 내에서만 발생한다면 어떻게 처리?
    for(int i=0; i<8; i++){
        for(int j=i+1; j<9; j++){
            if(n[i]+n[j]==sum){
                ij.push_back(i);
                ij.push_back(j);
                return ij;
            }
        }
    }
    return ij;
}

int main()
{
    //변수 선언
    vector<int> n;
    int in, sum=0;
    
    //입력
    for(int i=0; i<9; i++){
        cin>>in;
        n.push_back(in);
        sum+=in;
    }
    sum-=100;
    
    vector<int> ij=find_two(n, sum);
    
    vector<int> result;



    // 이 부분도 함수로 뺴는 것이 바람직한가?
    for(int i=0; i<9; i++){
        if(i==ij[0]||i==ij[1]) continue;
        result.push_back(n[i]);
    }
    sort(result.begin(), result.end());
    //



    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<"\n";
    }
    
    return 0;
}
