#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int CNT=9;
void select(vector<int> &arr){
    int sum=0; 
    for(int i=0; i<CNT; i++){
        sum+=arr[i];
    }
    for(int i=0; i<CNT; i++){
        for(int j=i; j<CNT; j++) {
            if(sum-arr[i]-arr[j]==sum){
                arr.erase(arr.begin()+j);
                arr.erase(arr.begin()+i);
                return;
            }
        }
    }
}

int main()
{
    //변수 선언
    vector<int> arr(CNT);
    for(int i=0; i<CNT; i++){
        cin>>arr[i];
    }
    select(arr);

    sort(arr.begin(), arr.end());


    for(auto it:arr){
        cout<<it<<"\n";
    }
    
    return 0;
}
