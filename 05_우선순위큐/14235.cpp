#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int> pq;
    vector<int> ans;
    int n, a;
    int k;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>k;
        if(k!=0){//a값을 입력받는 경우
            a=k;
            for(int j=0; j<a; j++){
                cin>>k;
                pq.push(k);
            }
        }
        else{
            if(!(pq.empty())){
                ans.push_back(pq.top());
                pq.pop();
            }
            else{
                ans.push_back(-1);
            }
        }
    }
    
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<"\n";
    }

    return 0;
}