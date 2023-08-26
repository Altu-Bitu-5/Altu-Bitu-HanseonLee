#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


int main() {
    int w0, l0, T;
    int D, l, A, w;
    int t, l1;
    
    //입력
    cin>>w0>>l0>>T;
    cin>>D>>l>>A;
    w=w0;
    l1=l0;
    //첫번째 줄=>기초 대사량 변화 X
    for(int i=0; i<D; i++){
        w+=l-(l0+A);
    }
    
    if (w<=0) cout<<"Danger Diet\n";
    else cout<<w<<" "<<l0<<"\n";
    
    //두번째 줄=>기초대사량 변화 O
    w=w0;
    for (int i=0; i<D; i++){
        t=l-(l1+A);
        w+=t;
        if (t<0){
            if((t*-1)>T) {
                if((t*-1)%2==1)l1+=(t/2)-1;//이거 계산할 때 if문에서 *-1안해줬더니 계속 틀렸었다.
                else l1+=(t/2);
            }
        }
        else{
            if (t>T) l1+=t/2;
        } 
        
        if(l1<=0 || w<=0) {
        cout<<"Danger Diet"; 
        return 0;
        }
    }
    
    //출력
    cout<<w<<" "<<l1<<" ";
    if(l0-l1>0) cout<<"YOYO";
    else cout<<"NO";
    
    return 0;
}






