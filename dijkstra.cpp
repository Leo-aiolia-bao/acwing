/*	���ڣ� 2020��11��29��19��27�� 
	Author:Zhang
	dijkstra
	
����һ��n����m���ߵ�����ͼ��ͼ�п��ܴ����رߺ��Ի������б�Ȩ��Ϊ��ֵ��

�������1�ŵ㵽n�ŵ����̾��룬����޷���1�ŵ��ߵ�n�ŵ㣬�����-1��

	
	1: dist[1] =0 ; dist[v] = +�� 
	2: for v 1 ~ n 			s ��ǰ�Ѿ�ȷ����̾���ĵ�	 
		t <- ����s �еľ�������ĵ�
		s <- t 
		��t ����������ľ���  �����Ǵ�ԭ�������  
*/

// ����ͼ �����࣬ ���ڽӾ�������
 

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
//500���� 10������ 
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
	
	if( dist[n] == 0x3f3f3f3f) return -1;// 1 n����ͨ 
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





























