#include <iostream>

using namespace std;
const int N = 100010;

// 头结点的下标，e 结点i的值
//ne结点i的next指针下标是， idx存储用到了哪个点
int head, e[N], ne[N], idx;

void init(){
    head = -1;
    idx = 0; 
}
// 将x插入到head结点
void add_to_head(int x){
    e[idx] = x;
    ne[idx] = head;
    head = idx++;
}

// 将 x插入到下标是 k 的点的后面
void add( int k ,int x ){
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

//将下标是k的点的后边的点删掉
void remove(int k){
    ne[k] =ne[ne[k]];
}

int main(){
     int m ;
     cin >> m ; 
     init();
     
     while( m--){
         int k, x;
         char op;
         
         cin >> op;
         if(op == 'H'){
             cin >> x;
             add_to_head(x);
         }
         else if( op == 'D'){
             cin >> k;
             if(!k) head =ne[head];
             
             remove(k-1);
         }
         else if( op == 'I'){
             cin >> k >>x;
             add(k-1, x);
         }
     }
     
     for(int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';
     cout << endl;
     return 0;
     
     
}




