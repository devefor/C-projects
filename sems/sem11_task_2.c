#include <stdio.h>

void search_end_island(unsigned short apex, unsigned short column, unsigned short location_x, unsigned short location_y, unsigned short* matrix, unsigned short* visit_matrix);

int main(void)
{
    unsigned short row = 0;
    unsigned short cloumn = 0;

    if (scanf("%hu %hu", &row, &cloumn) == 2) {

        unsigned short matrix[row * cloumn];
        unsigned short visit_matrix[row * cloumn];

        for (unsigned short i = 0; i < row; i++) {
            for (unsigned short j = 0; j < cloumn; j++) {
                matrix[i * cloumn + j] = 0;
                visit_matrix[i * cloumn + j] = 0;
            }
        }

        for (unsigned short i = 0; i < row; i++) {
            for (unsigned short j = 0; j < cloumn; j++) {
                unsigned short land = 0;
                if (scanf("%hu", &land) == 1)
                    matrix[i * cloumn + j] = land;
            }
        }

        unsigned short island = 0;
        for (unsigned short i = 0; i < row; i++) {
            for (unsigned short j = 0; j < cloumn; j++) {
                if ((matrix[i * cloumn + j]) && (visit_matrix[i * cloumn + j] == 0)) {
                    search_end_island(row, cloumn, i, j, matrix, visit_matrix);
                    island++;
                }
            }
        }

        printf("%hu\n", island);
    }

    return 0;
}

void search_end_island(unsigned short row, unsigned short column,
    unsigned short location_x, unsigned short location_y,
    unsigned short* matrix, unsigned short* visit_matrix)
{
    visit_matrix[location_x * column + location_y] = 1;

    if ((matrix[(location_x - 1) * column + location_y] == 1) && (location_x - 1 >= 0) && (visit_matrix[(location_x - 1) * column + location_y] == 0))
        search_end_island(row, column, location_x - 1, location_y, matrix, visit_matrix);

    if ((matrix[(location_x + 1) * column + location_y] == 1) && (location_x + 1 >= 0) && (visit_matrix[(location_x + 1) * column + location_y] == 0))
        search_end_island(row, column, location_x + 1, location_y, matrix, visit_matrix);

    if ((matrix[location_x * column + location_y - 1] == 1) && (location_y - 1 >= 0) && (visit_matrix[location_x * column + location_y - 1] == 0))
        search_end_island(row, column, location_x, location_y - 1, matrix, visit_matrix);

    if ((matrix[location_x * column + location_y + 1] == 1) && (location_y + 1 >= 0) && (visit_matrix[location_x * column + location_y + 1] == 0))
        search_end_island(row, column, location_x, location_y + 1, matrix, visit_matrix);
}
