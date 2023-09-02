#include <iostream>
#include <algorithm>

using namespace std;

int gcdIter(int x, int y){//y>x
    while(x){
        y%=x;
        swap(x,y);
    }
    return y;
}
int main()
{
    //변수 선언
    int a, b, c, d, x, y, gcd;
    
    //입력
    cin>>a>>b;
    cin>>c>>d;
    
    x=a*d+b*c;
    y=b*d;
    
    
    gcd=gcdIter(x, y);
    
    x/=gcd;
    y/=gcd;
    
    //출력
    cout<<x<<" "<<y;
    
    return 0;
}
