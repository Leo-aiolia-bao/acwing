/*	
	����ͼ�� ��������			�����޻�ͼ��������ͼ
	�л�����	��-- a->b b->c c->a  
	������ȱ��� ��Ӧ�� 
	(x,y)  x��������y��ǰ��  �ߴ�ǰָ���
	
	���Ϊ0 ���ޱ�ָ���ң�����ǰ�ߣ� �ҿ�����ǰ�ߵ� 
	��� ���ٱ�ָ���Լ���  ���ȴ�������ȥ 

1 ->  queue �������Ϊ0�� ���
while queue ���� 
	t <-��ͷ	t������ǰ�ߵ�λ���� 
	ö��t�����г��� t->j
	ɾ��t->j	d[j]--
	if d[j]=0�� jǰ���е��ź����ˣ�
		queue<-j
	
	һ�������޻�ͼ��һ�����ٴ���һ�����Ϊ0�ĵ� 
	 
*/ 
#include <cstring>
#include  <iostream>
#include <algorithm>
 
 using namespace std;
 
 const int N = 100010;
 
 int n,m;
 int h[N], e[N], ne[N], idx;
 int q[N], d[N];
 
 void add(int a, int b){
 	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
 } 
 
bool topsort(){
	int hh = 0, tt = -1;

	for(int i = 1; i<= n; i++){
		if(! d[i])
			q[ ++tt] = i;
	}
	
	while( hh <= tt){
		int t =q[hh ++];
		
		for(int i= h[t]; i != -1; i = ne[i]){
			int j = e[i];	//find the ����  
			d[j]--;
			if(d[j] == 0 ) q[ ++tt] =j; 
		}
	}
	
	return tt == n-1;  //˵��������n���� ���е㶼������ ˵����һ�������޻�ͼ 
	}
 
 int main(){
 	cin >>  n >>  m; 
 	memset(h, -1, sizeof h);
 	
 	for(int i=0; i< m ; i++){
 		int a, b;
 		cin >> a >> b;
 		add(a,b);
 		d[b]++;
 		
 	}
 	
 	if( topsort()){
 		for(int i = 0 ; i< n; i++) printf("%d ",q[i]);
 	}
 	else puts("-1"); 
 	
 	return 0;
 }























