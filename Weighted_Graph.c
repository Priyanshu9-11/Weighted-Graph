#include <stdio.h>

#define MAX 100
#define INF 32767

void shortestdistance(int a[MAX][MAX], int nov, int ref);

main() {
    int nov, i, j, ref;
    int a[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &nov);

    printf("Enter the weighted adjacency matrix (use %d for infinity where there is no edge):\n", INF);
    for (i = 0; i < nov; i++) {
        for (j = 0; j < nov; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the reference vertex (starting vertex index): ");
    scanf("%d", &ref);

    shortestdistance(a, nov, ref);


}

void shortestdistance(int a[MAX][MAX], int nov, int ref) {
    int sdf[MAX], d[MAX];  // sdf[] keeps track of shortest distance finalized
    int min, v, i, j;

    // Initialize sdf[] as 0 and d[] with distances from the reference vertex
    for (i = 0; i < nov; i++) {
        sdf[i] = 0;           // Mark all vertices as unprocessed
        d[i] = a[ref][i];      // Initialize distances to the adjacency matrix values
    }

    sdf[ref] = 1;  // Mark the reference vertex as processed

    // Loop to find the shortest path for all vertices
    for (i = 0; i < nov - 1; i++) {
        min = INF;

        // Find the vertex with the minimum distance that is not processed
        for (j = 0; j < nov; j++) {
            if (!sdf[j] && d[j] < min) {
                min = d[j];
                v = j;
            }
        }

        printf("Vertex %d to Vertex %d: Shortest distance = %d\n", ref, v, min);
        sdf[v] = 1;  // Mark the vertex as processed

        // Update distances for neighboring vertices
        for (j = 0; j < nov; j++) {        //Using j <= nov would try to access index 7, which does not exist and would cause an error.
            if (!sdf[j] && a[v][j] != INF && d[v] + a[v][j] < d[j]) {
                d[j] = d[v] + a[v][j];
            }
        }
    }
}
