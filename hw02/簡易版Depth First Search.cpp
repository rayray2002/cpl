#include <iostream>
#include <cstdlib>
using namespace std;

void dfs(int V, int start, int **graph, int E)
{
	static bool *visit = NULL;
	if (visit == NULL) {
		visit = new bool [V];
		for(int i = 0; i < V; i++) {
			visit[i] = false;
		}
	}
	visit[start] = true;
	cout << start << ' ';
	for(int i = 0; i < E; i++) {
		if(start == graph[i][0] && !visit[graph[i][1]]) {
			dfs(V, graph[i][1], graph, E);
		}
		if(start == graph[i][1] && !visit[graph[i][0]]) {
			dfs(V, graph[i][0], graph, E);
		}
	}
}
int main()
{
	int V, E;
	cin >> V >> E;
	int **graph = new int *[E];

	for(int i = 0; i < E; i++) {
		graph[i] = new int [2];
		int a, b;
		cin >> a >> b;
		if(a < b) {
			graph[i][0] = a;
			graph[i][1] = b;
		} else {
			graph[i][0] = b;
			graph[i][1] = a;
		}
	}
	for(int i = 0; i < E; i++) {
		for(int j = 0; j < E-1; j++) {
			if (graph[j][1] > graph[j+1][1]) {
				int *temp = graph[j];
				graph[j] = graph[j+1];
				graph[j+1] = temp;
			}
		}
	}
//	for(int i = 0; i < E; i++) {
//		cout << graph[i][0] << graph[i][1] << endl;
//	}
	dfs(V, 0, graph, E);
}