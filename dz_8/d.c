#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Location {
    int8_t now_x;
    int8_t now_y;
    int16_t distance;
} Location_t;

void input_table(int8_t heigth, int8_t width, int8_t** table);
void set_location(int8_t x, int8_t y, int16_t distance, int16_t place, Location_t* queue);
bool check_entry(int8_t heigth, int8_t width, int8_t start_x, int8_t start_y, int8_t x, int8_t y);
bool is_path(int8_t heigth, int8_t width, int8_t x, int8_t y, int8_t** table, int8_t** visit);
int16_t search_path(int8_t heigth, int8_t width, int8_t start_x, int8_t start_y, int8_t** table);

int main(void)
{
    int8_t heigth = 0;
    int8_t width = 0;
    if (scanf("%hhd %hhd", &heigth, &width) != 2)
        return -1;

    int8_t start_x = 0;
    int8_t start_y = 0;
    if (scanf("%hhd %hhd", &start_x, &start_y) != 2)
        return -1;

    int8_t** table = (int8_t**)malloc(heigth * sizeof(int8_t*));
    if (table == NULL)
        return -1;
    for (int8_t i = 0; i < heigth; i++) {
        table[i] = (int8_t*)malloc(width * sizeof(int8_t));
        if (table[i] == NULL) {
            for (int8_t j = 0; j < i; j++)
                free(table[j]);
            free(table);
        }
    }

    input_table(heigth, width, table);

#ifdef OUTPUT
    printf("\nTable:");
    for (int8_t i = 0; i < heigth; i++) {
        printf("\n");
        for (int8_t j = 0; j < width; j++)
            printf("%d ", table[i][j]);
    }
    printf("\n\n");
#endif

    int16_t res = search_path(heigth, width, start_x, start_y, table);
    printf("%hd\n", res);

    for (int8_t i = 0; i < heigth; i++)
        free(table[i]);
    free(table);
    return 0;
}

void input_table(int8_t heigth, int8_t width, int8_t** table)
{
    for (int8_t i = 0; i < heigth; i++) {
        for (int8_t j = 0; j < width; j++) {
            int8_t object = 0;
            if (scanf("%hhd", &object))
                table[i][j] = object;
        }
    }
}

// Устанавдиваем данные в очереди
void set_location(int8_t x, int8_t y, int16_t distance, int16_t place, Location_t* queue)
{
    queue[place].now_x = x;
    queue[place].now_y = y;
    queue[place].distance = distance;
}

// Проверка на выход
bool check_entry(int8_t heigth, int8_t width, int8_t start_x, int8_t start_y, int8_t x, int8_t y)
{
    if (((x == 0 || x == heigth - 1) || (y == 0 || y == width - 1)) && (x != start_x || y != start_y))
        return true;
    else
        return false;
}

// Можно ли туда идти
bool is_path(int8_t heigth, int8_t width, int8_t x, int8_t y, int8_t** table, int8_t** visit)
{
    if ((x >= 0) && (x < heigth) && (y >= 0) && (y < width) && (table[x][y] == 0) && !visit[x][y])
        return true;
    else
        return false;
}

int16_t search_path(int8_t heigth, int8_t width, int8_t start_x, int8_t start_y, int8_t** table)
{
    int8_t** visit = (int8_t**)calloc(heigth, sizeof(int8_t*));
    for (int8_t i = 0; i < heigth; i++)
        visit[i] = (int8_t*)calloc(width, sizeof(int8_t));
    visit[start_x][start_y] = 1;

    Location_t* queue = (Location_t*)malloc(heigth * width * sizeof(Location_t));
    if (queue == NULL) {
        for (int8_t i = 0; i < heigth; i++)
            free(visit[i]);
        free(visit);
        return -1;
    }
    int16_t head = 0;
    int16_t tail = 0;

    set_location(start_x, start_y, 0, tail, queue);
    tail++;

    while (head < tail) {
        Location_t current = queue[head++];
        int8_t current_x = current.now_x;
        int8_t current_y = current.now_y;
        int16_t distance = current.distance;

        if (check_entry(heigth, width, start_x, start_y, current_x, current_y)) {
            free(queue);
            for (int8_t i = 0; i < heigth; i++)
                free(visit[i]);
            free(visit);
            return distance;
        }

        // По направлениям смотрим (-1; 0) (0; -1) (1; 0) (0; 1)
        for (int8_t i = -1; i <= 1; i += 2) {
            int8_t x = current_x + i;
            int8_t y = current_y;
            if (is_path(heigth, width, x, y, table, visit)) {
                visit[x][y] = 1;
                set_location(x, y, distance + 1, tail, queue);
                tail++;
            }

            x = current_x;
            y = current_y + i;
            if (is_path(heigth, width, x, y, table, visit)) {
                visit[x][y] = 1;
                set_location(x, y, distance + 1, tail, queue);
                tail++;
            }
        }
    }

    free(queue);
    for (int8_t i = 0; i < heigth; i++)
        free(visit[i]);
    free(visit);
    return -1;
}