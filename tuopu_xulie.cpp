/*	
	有向图的 拓扑序列			有向无环图——拓扑图
	有环则不行	如-- a->b b->c c->a  
	广度优先遍历 的应用 
	(x,y)  x都出现在y的前边  边从前指向后，
	
	入度为0 ，无边指向我，在我前边； 我可排在前边的 
	入度 多少边指向自己，  出度从这个点出去 

1 ->  queue 所有入读为0点 入队
while queue 不空 
	t <-队头	t放在最前边的位置了 
	枚举t的所有出边 t->j
	删掉t->j	d[j]--
	if d[j]=0了 j前所有点排好序了，
		queue<-j
	
	一个有向无环图，一定至少存在一个入度为0的点 
	 
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
			int j = e[i];	//find the 出边  
			d[j]--;
			if(d[j] == 0 ) q[ ++tt] =j; 
		}
	}
	
	return tt == n-1;  //说明进入了n个点 所有点都进过了 说明是一个有向无环图 
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























