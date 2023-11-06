/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>


using namespace std;

string trans(string a, string b){
    int j=0;
    string temp;
    vector<string> la, lb, ls;
    //아.. 뒤에서 부터 더해야 되는구나
    //큰 수 분리하기
    for(int i=a.length()-1; i >0; i-=9){//계산 쉽게 int로
        temp = a.substr(i-9, 9); 
        la.push_back(temp); // 문자열을 숫자로 변환하여 벡터에 추가
        j++;
    }
    j=0;
    for(int i=b.length()-1; i > 0; i-=9){
        temp = b.substr(i-9, 9); // 길이 18의 부분 문자열 추출
        lb.push_back(temp); // 문자열을 숫자로 변환하여 벡터에 추가
        j++;
    }
    for(int i=0; i<la.size(); i++)
        cout<<la[i]<<'\n';

    //합구하기
    vector<int> size;
    if (la.size() >= lb.size()) {
        for (int i = 0; i < lb.size(); i++) {
            unsigned long long sum = stoi(la[i]) + stoi(lb[i]);
            ls.push_back(to_string(sum));
            size.push_back(la[i+1].length());
        }
        for (int i = lb.size(); i < la.size(); i++) {
            ls.push_back(la[i]);
        }
    }
    else{
        for (int i = 0; i < la.size(); i++) {
            unsigned long long sum = stoi(la[i]) + stoi(lb[i]);
            ls.push_back(to_string(sum));
            size.push_back(lb[i+1].length());
        }
        for (int i = la.size(); i < lb.size(); i++) {
            ls.push_back(lb[i]);
        }
        
    }
    
    for(int i=0; i<ls.size(); i++)
        cout<<ls[i]<<" ";
    string result = "";
    string s = "0"; // 연산 결과를 문자열로 초기화

    for (int i = ls.size(); i >0; i--) {
        if (ls[i].length() > size[i]) {
            int sum = stoi(ls[i].substr(ls[i].length() - 1)) + stoi(ls[i + 1].substr(0, 1));
            s = to_string(sum);
            ls[i-1] = ls[i-1].substr(0, ls[i-1].length() - 1) + s; // 문자열을 수정하여 연산 결과 반영
            ls[i] = ls[i].substr(1); // 다음 문자열 재조정
        }
        result+=ls[i];
        cout<<result<<"\n";
    }
    
    return result;

}


int main()
{
    string a, b, result;
    
    cin>>a>>b;
    result=trans(a,b);
    
    cout<<result;
    
    return 0;
}