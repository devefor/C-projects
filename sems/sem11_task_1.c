#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_edges(unsigned short edges, unsigned short* edges_in, unsigned short* edges_out);
int search_noad(unsigned short apex, unsigned short* edges_in, unsigned short* edges_out);

int main(void)
{
    unsigned short apex = 0;
    unsigned short edges = 0;

    if (scanf("%hu %hu", &apex, &edges) == 2) {

        unsigned short* edges_in = (unsigned short*)malloc((apex + 1) * sizeof(unsigned short));
        unsigned short* edges_out = (unsigned short*)malloc((apex + 1) * sizeof(unsigned short));

        if ((edges_in == NULL) || (edges_out == NULL)) {
            free(edges_in);
            free(edges_out);
            return -1;
        }

        memset(edges_in, 0, (apex + 1) * sizeof(unsigned short));
        memset(edges_out, 0, (apex + 1) * sizeof(unsigned short));

        read_edges(edges, edges_in, edges_out);

        printf("%d\n", search_noad(apex, edges_in, edges_out));
        free(edges_in);
        free(edges_out);
    }

    return 0;
}

void read_edges(unsigned short edges, unsigned short* edges_in, unsigned short* edges_out)
{
    while (edges--) {
        unsigned short apex_out = 0;
        unsigned short apex_in = 0;
        if (scanf("%hu %hu", &apex_out, &apex_in) == 2) {
            edges_out[apex_out]++;
            edges_in[apex_in]++;
        }
    }
}

int search_noad(unsigned short apex, unsigned short* edges_in, unsigned short* edges_out)
{
    for (unsigned short i = 1; i < apex + 1; i++) {
        if ((edges_in[i] == apex - 1) && (edges_out[i] == 0)) {
            return (int)i;
        }
    }

    return -1;
}