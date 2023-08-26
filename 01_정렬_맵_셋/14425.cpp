#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


int main() {
    int n, m, count;
    set<string> s;
    string str;
    
    //입력
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        cin>>str;
        s.insert(str);
    }
    
    
    for (int i=0; i<m; i++){
        cin>>str;
        if(s.find(str)!=s.end())
            count++;
    }
    
    //출력 
    cout<<count;
    
    return 0;
}






