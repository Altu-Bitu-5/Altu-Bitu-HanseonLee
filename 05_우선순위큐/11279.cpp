#include <iostream>

using namespace std;

bool isEmpty(vector<int> & heap){
    return heap.size()==1;
    
}

void push(int x, vector<int>&heap){
    int idx=heap.size();
    heap.push_back(x);
    while(heap[idx], heap[idx/2]){
        swap(heap[idx], heap[idx/2]);
        idx/=2;
    }
    return;
}

int pop(vector<int> &heap){
    int itemp=heap[1];
    
    heap[1]=heap[heap.size()-1];
    heap.pop_back();
    
    int size=heap.size();
    int parent=1, child=2;
    while(){
        if(child+1<size&&heap[child+1]>heap[child]){
            child++;
        }
        if(child[])
    }
    
}

int main()
{
    cout<<"Hello World";
    
    int n, x;
    cin>> n;
    while(n--){
        cin>>x;
        if(x==0){
            //head이 비어있는지 확인
            if(isEmpty(heap_vec)){
                cout<<"0\n";
            }
            else{
                cout<<pop(heap_vec)<<"\n";
        
            }
        }
        //x가 0이 아닌 자연수일경우
        else{
            
        }
    }

    return 0;
}