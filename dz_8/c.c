#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// (n - 1) * k n-число ребер, k-максимальное время между
const int MAX_TIME = (100 - 1) * 100;

typedef struct Edge {
    int8_t end;
    int16_t time;
} Edge_t;

void input_edges(int16_t count, Edge_t** graph);
void deikstra(int8_t apex, int8_t start, int16_t* distance, Edge_t** graph);

int main(void)
{
    int8_t apex = 0;
    int8_t start = 0;
    int16_t amount_edge = 0;

    if (scanf("%hhd %hhd %hd", &apex, &start, &amount_edge) != 3)
        return -1;
    start--;

    Edge_t** graph = (Edge_t**)malloc(apex * sizeof(Edge_t*));
    if (graph == NULL)
        return -1;
    else {
        for (int8_t i = 0; i < apex; i++) {
            graph[i] = (Edge_t*)malloc(apex * sizeof(Edge_t));
            if (graph[i] == NULL) {
                for (int8_t j = 0; j < i; j++)
                    free(graph[j]);
                free(graph);
                return -1;
            }

            for (int8_t j = 0; j < apex; j++) {
                graph[i][j].end = -1;
                graph[i][j].time = MAX_TIME;
            }
        }
    }

    input_edges(amount_edge, graph);

#ifdef OUTPUT
    printf("\nEdges:\n");
    for (int8_t i = 0; i < apex; i++) {
        printf(" For apex %d\n", i + 1);
        for (int8_t j = 0; j < apex; j++)
            if (graph[i][j].time != MAX_TIME)
                printf("   to apex %hhd time %hd\n", graph[i][j].end + 1, graph[i][j].time);
    }
    putchar('\n');
#endif

    int16_t* distance = (int16_t*)malloc(apex * sizeof(int16_t));
    if (distance == NULL) {
        for (int8_t i = 0; i < apex; i++)
            free(graph[i]);
        free(graph);
        return -1;
    }

    deikstra(apex, start, distance, graph);

    int16_t max_distance = 0;
    for (int8_t i = 0; i < apex; i++) {
        if (distance[i] == MAX_TIME) {
            max_distance = -1;
            break;
        }

        if (max_distance < distance[i])
            max_distance = distance[i];
    }

    printf("%d\n", max_distance);

    free(distance);
    for (int8_t i = 0; i < apex; i++)
        free(graph[i]);
    free(graph);
    return 0;
}

void input_edges(int16_t count, Edge_t** graph)
{
    int8_t start = 0;
    int8_t end = 0;
    int8_t time = 0;

    for (int16_t i = 0; i < count; i++) {
        if (scanf("%hhd %hhd %hhd", &start, &end, &time) != 3)
            return;
        start--;
        end--;
        // Для вершины, у которой есть соединение с другой вершиной пишем время
        graph[start][end].end = end;
        graph[start][end].time = time;
    }
}

// Алгоритм Дейкстры
void deikstra(int8_t apex, int8_t start, int16_t* distance, Edge_t** graph)
{
    int8_t visit[apex];
    for (int8_t i = 0; i < apex; i++) {
        distance[i] = MAX_TIME;
        visit[i] = 0;
    }
    distance[start] = 0;

    for (int8_t i = 0; i < apex; i++) {
        // Ищем непосещенную вершину ближайшую или завершаем, если таких нет
        int8_t apex_time = -1;
        for (int8_t j = 0; j < apex; j++)
            if (!visit[j] && (apex_time == -1 || (distance[j] < distance[apex_time])))
                apex_time = j;
        if (distance[apex_time] == MAX_TIME)
            break;

        // Обновляем время до соседей
        visit[apex_time] = 1;
        for (int8_t j = 0; j < apex; j++) {
            if (graph[apex_time][j].end != -1 && !visit[j]) {
                if (distance[apex_time] + graph[apex_time][j].time < distance[j])
                    distance[j] = distance[apex_time] + graph[apex_time][j].time;
            }
        }
    }
}