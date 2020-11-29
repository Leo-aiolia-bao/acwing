/*	日期： 2020年11月29日19点27分 
	Author:Zhang
	dijkstra
	
给定一个n个点m条边的有向图，图中可能存在重边和自环，所有边权均为正值。

请你求出1号点到n号点的最短距离，如果无法从1号点走到n号点，则输出-1。

	
	1: dist[1] =0 ; dist[v] = +∞ 
	2: for v 1 ~ n 			s 当前已经确定最短距离的点	 
		t <- 不再s 中的距离最近的点
		s <- t 
		用t 更新其它点的距离  即不是从原点更新了  
*/

// 稠密图 边数多， 用邻接矩阵来存
 

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
//500个点 10万条边 
const int N = 510;

int n,m;
int g[N][N];
int dist[N];
bool st[N];


int dijkstra(){
	
	memset(dist, 0x3f , sizeof dist);
	dist[1]=0;
	
	for(int i = 1; i <= n; i++){
		int t = -1;
		for( int j = 1; j <= n; j ++)
			if( !st[j] && ( t== -1 || dist[t] > dist[j])) 
				t = j;

		st[t]= true;
		
		for(int j = 1 ; j <= n; j++)
			dist[j] = min(dist[j], dist[t] + g[t][j]) ;
	}
	
	if( dist[n] == 0x3f3f3f3f) return -1;// 1 n不连通 
	else return dist[n]; 
}





int main(){
	
	scanf("%d%d", &n , &m);
	memset(g, 0x3f , sizeof g);
	
	while(m --){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		g[a][b] = min(g[a][b], c) ;
		
	}
	
	int t = dijkstra();
	printf("%d",t);
	
	return 0;
} 





























