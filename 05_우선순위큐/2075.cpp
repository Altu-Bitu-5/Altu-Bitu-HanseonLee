#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);//이거 안해줬더니 시간 초과
	cin.tie(0);
    
    int n, k;
    cin>>n;
    
    priority_queue< int, vector<int>, greater<int> > pq;
    for(int i=0; i<n*n; i++){
        cin>>k;
        pq.push(k);
        if(pq.size()>n){//pq에서 안빼줬더니 메모리 초과 발생했었다.
            pq.pop();
        }
    }
    cout<<pq.top();

    return 0;
}