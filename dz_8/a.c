#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Apex {
    int32_t* connect_apex;
    int32_t amount_apex;
    int32_t memory;
} Apex_t;

void input_edge(int32_t edge, Apex_t* graph);
void add_connect_apex(int32_t apex, int32_t connect_apex, Apex_t* graph);
int8_t search_path(int32_t start, int32_t end, int32_t apex, Apex_t* matrix);

int main(void)
{
    int32_t apex = -1;
    int32_t edge = -1;
    int32_t start = -1;
    int32_t end = -1;

    if (!(scanf("%d %d %d %d", &apex, &edge, &start, &end) == 4))
        return -1;

    Apex_t* graph = calloc(apex, sizeof(Apex_t));
    if (graph == NULL)
        return -1;

    input_edge(edge, graph);

#ifdef OUTPUT
    printf("\nEdges:\n");
    for (int32_t i = 0; i < apex; i++)
        for (int32_t j = 0; j < graph[i].amount_apex; j++)
            printf("(%d -- %d)\n", i, graph[i].connect_apex[j]);
    putchar('\n');
#endif

    if (search_path(start, end, apex, graph) == 1)
        printf("true\n");
    else
        printf("false\n");

    for (int32_t i = 0; i < apex; i++) {
        free(graph[i].connect_apex);
    }
    free(graph);
    return 0;
}

void input_edge(int32_t edge, Apex_t* graph)
{
    int32_t apex_1 = 0;
    int32_t apex_2 = 0;

    for (int32_t i = 0; i < edge; i++) {
        if (scanf("%d %d", &apex_1, &apex_2) == 2) {
            add_connect_apex(apex_1, apex_2, graph);
            add_connect_apex(apex_2, apex_1, graph);
        }
    }
}

void add_connect_apex(int32_t apex, int32_t connect_apex, Apex_t* graph)
{
    if (graph[apex].memory <= graph[apex].amount_apex) {
        graph[apex].memory += 5;
        graph[apex].connect_apex = realloc(graph[apex].connect_apex, graph[apex].memory * sizeof(int32_t*));
    }
    // К вершине добавляем вершину, которая с ней связана ребром
    graph[apex].connect_apex[graph[apex].amount_apex] = connect_apex;
    graph[apex].amount_apex++;
}

int8_t search_path(int32_t start, int32_t end, int32_t apex, Apex_t* graph)
{
    uint8_t* visit_apex = (uint8_t*)calloc(apex, sizeof(uint8_t));
    if (visit_apex == NULL)
        return -1;

    int32_t* stack = (int32_t*)malloc(apex * sizeof(int32_t));
    if (stack == NULL) {
        free(visit_apex);
        return -1;
    }

    int32_t index_apex = 0;
    stack[index_apex] = start;
    visit_apex[start] = 1;

    while (index_apex > -1) {
        int32_t now = stack[index_apex--];
        if (now == end) {
            free(visit_apex);
            free(stack);
            return 1;
        }

        for (int32_t i = 0; i < graph[now].amount_apex; i++) {
            int32_t connect = graph[now].connect_apex[i];
            if (!visit_apex[connect]) {
                index_apex++;
                stack[index_apex] = connect;
                visit_apex[connect] = 1;
            }
        }
    }

    free(visit_apex);
    free(stack);
    return 0;
}