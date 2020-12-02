#include <iostream>
#include <queue>

using namespace std;
char **maze;
bool **visit;
int path[100000] = {};
int fpath[100000] = {};
int deep = -1;
int fdeep = 100001;

struct node {
	int x, y;
};

bool check(const int &x, const int &y, const node &end) {
	if (x == end.x && y == end.y) {
		return true;
	} else {
		return false;
	}
}

bool solver(int x, int y, const node &end) {
	visit[y][x] = true;
	deep++;
	if (check(x, y, end)) {
		if (deep < fdeep) {
			fdeep = deep;
			for (int i = 0; i < fdeep; i++) fpath[i] = path[i];
		}
	}
	if (maze[y - 1][x] == '_' && !visit[y - 1][x]) {
		//up
		path[deep] = 4;
		solver(x, y - 1, end);
	}
	if (maze[y + 1][x] == '_' && !visit[y + 1][x]) {
		//down
		path[deep] = 2;
		solver(x, y + 1, end);
	}
	if (maze[y][x + 1] == '_' && !visit[y][x + 1]) {
		//r
		path[deep] = 1;
		solver(x + 1, y, end);
	}
	if (maze[y][x - 1] == '_' && !visit[y][x - 1]) {
		//l
		path[deep] = 3;
		solver(x - 1, y, end);
	}
	deep--;
	visit[y][x] = false;
	return false;
}

int main() {
	int h, w;
	cin >> h >> w;
	node start = {0, 0}, end = {w - 1, 0};
	maze = new char *[h];
	visit = new bool *[h];
	for (int i = 0; i < h; i++) {
		maze[i] = new char[w];
		visit[i] = new bool[w];
		for (int j = 0; j < w; j++) {
			cin >> maze[i][j];
			visit[i][j] = false;
		}
	}
	while (maze[start.y][0] == '#') {
		start.y++;
	}
	while (maze[end.y][w - 1] == '#') {
		end.y++;
	}
	solver(start.x, start.y, end);
	cout << "Shortest path: " << fdeep;
	if (fdeep > 1) {
		cout << " steps\n";
	} else {
		cout << " step\n";
	}
	int dir = fpath[0], i = 0, len = 0;
	while (i < fdeep) {
		while (fpath[i + len] == dir && i + len < fdeep) len++;
		if (dir == 1) cout << "Go right for " << len;
		if (dir == 2) cout << "Go down for " << len;
		if (dir == 3) cout << "Go left for " << len;
		if (dir == 4) cout << "Go up for " << len;
		if (len > 1) {
			cout << " steps\n";
		} else {
			cout << " step\n";
		}
//        cout << dir << len << endl;
		i += len;
		len = 0;
		dir = fpath[i];
	}
//    for (int i = 0; i < fdeep; i++) cout << fpath[i];
	return 0;
}
