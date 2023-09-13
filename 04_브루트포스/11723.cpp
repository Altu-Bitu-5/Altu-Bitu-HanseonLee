#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;


void add(int& ans, int value){
    ans=ans|(1<<value);
}

void remove(int &ans, int value){
    ans=ans&~(1<<value);
}

void check(int& ans, int value){
    if (ans&(1<<value)) {
        cout << "1\n";
    } 
    else {
        cout << "0\n";
    }
}

void toggle(int& ans, int value){
    ans^=(1<<value);
}

void all(int& ans){
    ans=(1<<21)-1;
}

void empty(int& ans){
    ans=0;
}

int main()
{
    ios_base::sync_with_stdio(false);//이거 안썼더니 계속 시간초과 났다.
	cin.tie(0);
    
    int n;
    int ans=0;
    
    cin>>n;
    
    cin.ignore();
    
    //연산
    string key;
    int value;
    
    for(int i=0; i<n; i++){
        cin>>key;
        
        if (key == "add") {
            cin>>value;
            add(ans, value);
            
        } 
        else if (key == "remove") {
            cin>>value;
            remove(ans, value);
        } 
        else if (key == "check") {
            cin>>value;
            check(ans, value);
        } 
        else if (key == "toggle") {
            cin>>value;
            toggle(ans, value);
        }
        else if (key == "all") {
            all(ans);
        } 
        else if (key == "empty") {
            empty(ans);
        }
    }
    return 0;
}