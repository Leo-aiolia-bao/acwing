#include <iostream>

using namespace std;
const int N = 100010;

// ͷ�����±꣬e ���i��ֵ
//ne���i��nextָ���±��ǣ� idx�洢�õ����ĸ���
int head, e[N], ne[N], idx;

void init(){
    head = -1;
    idx = 0; 
}
// ��x���뵽head���
void add_to_head(int x){
    e[idx] = x;
    ne[idx] = head;
    head = idx++;
}

// �� x���뵽�±��� k �ĵ�ĺ���
void add( int k ,int x ){
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

//���±���k�ĵ�ĺ�ߵĵ�ɾ��
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




