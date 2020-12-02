#include <iostream>
#include <iomanip>
#define qtr ios::sync_with_stdio(0); cin.tie(0);
//#define endl '\n'
using namespace std;

int main() {
	// read num of input
	int n;
	qtr
	cin >> n;
	for (int i = 0; i < n; i++) {
		//maze setup
		int w, h;
		cin >> h >> w;
		char **maze;
		int num_vertex = 0;
		int *color, *distance, *predecessor, **vertexs;
		maze = new char*[h];
		for (int j = 0; j < h; j++) {
			maze[j] = new char[w];
		}

		//read maze
		for (int j = 0; j < h; j++) {
			for (int k = 0; k < w; k++) {
				cin >> maze[j][k];
				if (maze[j][k] == '.') num_vertex++;
//				cout << maze[j][k];
			}
//			cout << endl;
		}
//		cout << num_vertex << endl;

		//find vertexs
		vertexs = new int*[num_vertex];
		for (int j = 0; j < num_vertex; j++) {
			vertexs[j] = new int[2];
		}
		int count = 0;
		for (int j = 0; j < h; j++) {
			for (int k = 0; k < w; k++) {
				if (maze[j][k] == '.') {
					vertexs[count][0] = j;
					vertexs[count][1] = k;
					count++;
				}
			}
		}
//		cout << "vertexes\n";
//		for (int j = 0; j < num_vertex; j++) {
//			cout << j << vertexs[j][0] << vertexs[j][1] << endl;
//		}

		//find vertex relation
		int **graph;
		graph = new int *[num_vertex];
		for (int j = 0; j < num_vertex; j++) {
			count = 0;
			graph[j] = new int [4];
			for (int k = 0; k < 4; k++) {
				graph[j][k] = -1;
			}
			for (int k = 0; k < num_vertex; k++) {
				if (abs(vertexs[j][0]-vertexs[k][0]) + abs(vertexs[j][1]-vertexs[k][1]) == 1) {
					graph[j][count] = k;
					count++;
				}
				if (count >= 4) break;
			}
		}
//		cout << "graph\n";
//		for (int j = 0; j < num_vertex; j++) {
//			for (int k = 0; k < 4; k++) {
//				cout << setw(3) << graph[j][k];
//			}
//			cout << endl;
//		}

		//maze init
		color = new int[num_vertex];
		distance = new int[num_vertex];
		predecessor = new int[num_vertex];

		for (int j = 0; j < num_vertex; j++) {
			color[j] = 0;
			distance[j] = -1;
			predecessor[j] = -1;
		}

		//queue setup
		int *queue;
		int size = 1;
		queue = new int [size];

		//start init
		queue[0] = 0;
		color[0] = 1;
		distance[0] = 0;
		predecessor[0] = -1;

		//bfs
		while (size) {
			int front = queue[0];
			for (int j = 0; j < 4; j++) {
				int target = graph[front][j];
				if (target != -1) {
					if (color[target] == 0) {
						color[target] = 1;
						distance[target] = distance[front] + 1;
						predecessor[target] = front;
						//push target to queue
						int *temp;
						temp = new int [size];
						for (int k = 0; k < size; k++) {
							temp[k] = queue[k];
						}
						delete queue;
						size++;
						queue = new int [size];
						for (int k = 0; k < size-1; k++) {
							queue[k] = temp[k];
						}
						queue[size-1] = target;
						delete temp;
					}
				} else {
					break;
				}
			}
			color[front] = -1;
			//remove front of the queue
			int *temp;
			temp = new int [size-1];
			for (int k = 1; k < size; k++) {
				temp[k-1] = queue[k];
			}
			delete queue;
			size--;
			queue = new int [size];
			for (int k = 0; k < size; k++) {
				queue[k] = temp[k];
			}
			delete temp;

//			for (int j = 0; j < num_vertex; j++) {
//				cout << setw(3) << distance[j];
//			}
//			cout << endl;
		}
		//output
		int ans = distance[num_vertex-1];
		if (ans == -1) {
			cout << "unbelievable" << endl;
		} else {
			cout << distance[num_vertex - 1] << endl;
		}

		delete queue;
		delete color;
		delete distance;
		delete predecessor;
		for (int j = 0; j < h; j++) {
			delete maze[j];
		}
		delete maze;
		for (int j = 0; j < num_vertex; j++) {
			delete vertexs[j];
		}
		delete vertexs;
	}
}