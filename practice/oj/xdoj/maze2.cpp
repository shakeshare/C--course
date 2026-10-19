#include <bits/stdc++.h>
using namespace std;
#define Maxleng 22

int maze[Maxleng][Maxleng];
int mazedist[Maxleng][Maxleng];
typedef struct position {
    int x;
    int y;
} pos;
pos location[Maxleng * Maxleng];
queue<pos> q;

int main() {
    memset(mazedist, -1, sizeof(mazedist)); // 初始化为-1表示未访问
    pos start, end, temp;
    int m;
    scanf("%d %d %d %d %d", &m, &start.x, &start.y, &end.x, &end.y);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    // BFS部分
    q.push(start);
    mazedist[start.x][start.y] = 0;
    while (!q.empty()) {
        pos current = q.front();
        q.pop();
        if (current.x == end.x && current.y == end.y) break;

        // 检查四个方向：下、右、上、左
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            if (nx >= 1 && nx <= m && ny >= 1 && ny <= m && maze[nx][ny] == 0 && mazedist[nx][ny] == -1) {
                mazedist[nx][ny] = mazedist[current.x][current.y] + 1;
                q.push({nx, ny});
            }
        }
    }

    // 路径回溯
    int count = 0;
    pos current = end;
    while (current.x != start.x || current.y != start.y) {
        location[count++] = current;
        // 寻找前驱：顺序下、右、上、左的逆，即上、左、下、右
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            if (nx >= 1 && nx <= m && ny >= 1 && ny <= m && mazedist[nx][ny] == mazedist[current.x][current.y] - 1) {
                current = {nx, ny};
                break;
            }
        }
    }
    location[count++] = current; // 加入起点

    // 输出结果
    printf("%d\n", mazedist[end.x][end.y]);
    for (int i = count - 1; i >= 0; i--) {
        printf("(%d,%d)", location[i].x, location[i].y);
    }
    printf("\n");
    return 0;
}