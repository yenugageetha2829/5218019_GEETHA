
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100
#define INF 1000000

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point data[MAXN * MAXN];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = 0;
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

void enqueue(Queue *q, int x, int y) {
    q->data[q->rear].x = x;
    q->data[q->rear].y = y;
    q->rear++;
}

Point dequeue(Queue *q) {
    return q->data[q->front++];
}

int minimumMoves(char grid[MAXN][MAXN], int n, int startX, int startY, int goalX, int goalY) {
    int dist[MAXN][MAXN];
    int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = INF;

    dist[startX][startY] = 0;

    Queue q;
    initQueue(&q);
    enqueue(&q, startX, startY);

    while (!isEmpty(&q)) {
        Point p = dequeue(&q);
        int cx = p.x, cy = p.y;

        for (int d = 0; d < 4; d++) {
            int nx = cx + directions[d][0];
            int ny = cy + directions[d][1];

            while (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == '.') {
                if (dist[nx][ny] > dist[cx][cy] + 1) {
                    dist[nx][ny] = dist[cx][cy] + 1;
                    enqueue(&q, nx, ny);
                }
                nx += directions[d][0];
                ny += directions[d][1];
            }
        }
    }
    return dist[goalX][goalY];
}

int main() {
    int n;
    scanf("%d", &n);

    char grid[MAXN][MAXN];
    for (int i = 0; i < n; i++) {
        scanf("%s", grid[i]);
    }

    int startX, startY, goalX, goalY;
    scanf("%d %d %d %d", &startX, &startY, &goalX, &goalY);

    int result = minimumMoves(grid, n, startX, startY, goalX, goalY);
    printf("%d\n", result);

    return 0;
}
