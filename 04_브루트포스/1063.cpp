#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int isValid(string kd, string dis) {
    char s, n;
    
    n = kd[1];
    s = kd[0];

    if (s == 'A') {
        if (n == '1') {
            if (dis == "L" || dis == "B" || dis == "LT" || dis == "RB" || dis == "LB")
                return 0;
        } else if (n == '8') {
            if (dis == "L" || dis == "T" || dis == "RT" || dis == "LT" || dis == "LB")
                return 0;
        } else if (n > '1' && n < '8') {
            if (dis == "L" || dis == "LT" || dis == "LB") //이거 위에거 복붙해서 범위 오류로 실행과 동시에 실패 했었음
                return 0;
        } else {
            return 1;
        }
    } else if (s == 'H') {
        if (n == '1') {
            if (dis == "R" || dis == "B" || dis == "RT" || dis == "RB" || dis == "LB")
                return 0;
        } else if (n == '8') {
            if (dis == "R" || dis == "T" || dis == "LT" || dis == "RT" || dis == "RB")
                return 0;
        } else if (n > '1' && n < '8') {
            if (dis == "R" || dis == "RT" || dis == "RB")
                return 0;
        }
    } else if (n == '1') {
        if (s > 'A' || s < 'H') {
            if (dis == "B" || dis == "RB" || dis == "LB")
                return 0;
        }
    } else if (n == '8') {
        if (s > 'A' || s < 'H') {//이거 범위 반대로 줘서 실행하자마자 실패
            if (dis == "T" || dis == "RT" || dis == "LT")
                return 0;
        }
    }

    return 1;
}


string move(string ori, string dis){
    char s, n;
    
    n=ori[1];
    s=ori[0];
    
    if(dis=="R"){
        s++;}
    else if(dis=="L"){
        s--;}
    else if(dis=="B"){
        n--;}
    else if(dis=="T"){
        n++;}
    else if(dis=="RT"){
        s++;
        n++;
    }
    else if(dis=="LT"){
        s--;
        n++;
    }
    else if(dis=="RB"){
        s++;
        n--;
    }
    else if(dis=="LB"){
        s--;
        n--;
    }
    string result=string(1,s)+string(1,n);
    return result;
}

vector<string> chessClac(string kd, string sd, vector<string> s){
    vector<string> dis(2);
    string tmp;
    for(int i=0; i<s.size(); i++){
        if(isValid(kd, s[i])){
            tmp=move(kd, s[i]);}
        else
            continue;
        if(tmp==sd){
            if(isValid(sd, s[i])){
                kd=tmp;
                sd=move(sd, s[i]);
            }
        }
        else{
            kd=tmp;
        }
    }
    dis[0]=kd;
    dis[1]=sd;
    
    return dis;
}

int main()
{
    //변수선언
    string kd, sd;
    int N;
    vector<string> dis(2);
    
    //입력
    cin>>kd>>sd;
    cin>>N;
    
    vector<string> s(N);
    for(int i=0; i<N; i++){
        cin>>s[i];
    }
    
    //연산
    dis=chessClac(kd, sd, s);
    
    //출력
    cout<<dis[0]<<"\n"<<dis[1];
    
    return 0;
}
