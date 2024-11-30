#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ABS(value) ((value) < 0 ? -(value) : (value))

typedef struct Edge {
    int32_t apex_1;
    int32_t apex_2;
    int32_t length;
} Edge_t;

void lsd_sort(Edge_t* edges, int32_t count_edge);
int32_t origin(int32_t* parent, int32_t apex);
void merge_set(int32_t* parent, int32_t* level, int32_t root_1, int32_t root_2);
int32_t kraskal(Edge_t* edges, int32_t apexs, int32_t count_edge);

int main(void)
{
    int32_t apexs = 0;
    if (!scanf("%d", &apexs))
        return -1;

    int32_t(*points)[2] = (int32_t(*)[2])malloc(apexs * sizeof(int32_t[2]));
    for (int32_t i = 0; i < apexs; i++) {
        if (scanf("%d %d", &points[i][0], &points[i][1]) != 2)
            return -1;
    }

    Edge_t* edges = (Edge_t*)calloc(apexs * (apexs - 1) / 2, sizeof(Edge_t));

    // Заполняем длины между вершинами
    int32_t count_edge = 0;
    for (int32_t i = 0; i < apexs; i++) {
        for (int32_t j = i + 1; j < apexs; j++) {
            int32_t length = ABS(points[i][0] - points[j][0]) + ABS(points[i][1] - points[j][1]);
            edges[count_edge].apex_1 = i;
            edges[count_edge].apex_2 = j;
            edges[count_edge++].length = length;
        }
    }

#ifdef OUTPUT
    printf("\nLength:\n|");
    for (int32_t i = 0; i < count_edge; i++)
        printf("%d|", edges[i].length);
    printf("\n\n");
#endif

    lsd_sort(edges, count_edge);

#ifdef OUTPUT
    printf("Sorted length:\n|");
    for (int32_t i = 0; i < count_edge; i++)
        printf("%d|", edges[i].length);
    printf("\n\n");
#endif

    int32_t length = kraskal(edges, apexs, count_edge);
    if (length != -1)
        printf("%d\n", length);

    free(edges);
    free(points);
    return 0;
}

void lsd_sort(Edge_t* edges, int32_t count_edge)
{
    if (count_edge <= 1)
        return;

    int32_t max_length = 0;
    for (int32_t i = 0; i < count_edge; i++) {
        if (edges[i].length > max_length) {
            max_length = edges[i].length;
        }
    }

    Edge_t* temp_edges = (Edge_t*)malloc(count_edge * sizeof(Edge_t));
    if (temp_edges == NULL)
        return;

    for (int32_t i = 1; 0 < max_length / i; i *= 10) {
        int32_t amount_edges[10] = { 0 };

        for (int32_t j = 0; j < count_edge; j++) {
            int32_t number = edges[j].length / i;
            int32_t degit = number % 10;
            amount_edges[degit]++;
        }

        int32_t start_number[10] = { 0 };
        for (int8_t j = 1; j < 10; j++)
            start_number[j] = start_number[j - 1] + amount_edges[j - 1];

        for (int32_t j = 0; j < count_edge; j++) {
            int32_t number = edges[j].length / i;
            int32_t degit = number % 10;
            temp_edges[start_number[degit]] = edges[j];
            start_number[degit]++;
        }

        memcpy(edges, temp_edges, count_edge * sizeof(Edge_t));
    }

    free(temp_edges);
}

// Проходимся до корневой вершины
int32_t origin(int32_t* root, int32_t apex)
{
    if (root[apex] != apex)
        root[apex] = origin(root, root[apex]);
    return root[apex];
}

// Конкатенируем графы, то есть задаем корневые вершины для вершин
void merge_set(int32_t* root, int32_t* level, int32_t root_1, int32_t root_2)
{
    if (level[root_1] > level[root_2])
        root[root_2] = root_1;
    else if (level[root_2] > level[root_1])
        root[root_1] = root_2;
    else {
        root[root_2] = root_1;
        level[root_1]++;
    }
}

// Алгоритм Краскала
int32_t kraskal(Edge_t* edges, int32_t apexs, int32_t count_edge)
{
    int32_t* root = (int32_t*)malloc(apexs * sizeof(int32_t));
    if (root == NULL)
        return -1;
    int32_t* level = (int32_t*)malloc(apexs * sizeof(int32_t));
    if (level == NULL) {
        free(root);
        return -1;
    }

    for (int32_t i = 0; i < apexs; i++) {
        root[i] = i;
        level[i] = 0;
    }

    int32_t sum_length = 0;
    int32_t sum_edge = 0;
    for (int32_t i = 0; i < count_edge; i++) {
        int32_t apex_1 = edges[i].apex_1;
        int32_t apex_2 = edges[i].apex_2;
        int32_t length = edges[i].length;

        int32_t root_1 = origin(root, apex_1);
        int32_t root_2 = origin(root, apex_2);

        if (root_1 != root_2) {
            merge_set(root, level, root_1, root_2);
            sum_length += length;
            sum_edge++;
        }

        if (sum_edge == apexs - 1)
            break;
    }

    free(root);
    free(level);
    return sum_length;
}