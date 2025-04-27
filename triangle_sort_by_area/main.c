#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
  int a;
  int b;
  int c;
};

typedef struct triangle triangle;

void sort_by_area(triangle* tr, int n) {
    float *p = malloc(n * sizeof(float));

    // Calculate the area using Heron's formula
    for (int i = 0; i < n; i++) {
        float s = (tr[i].a + tr[i].b + tr[i].c) / 2.0;
        p[i] = sqrt(s * (s - tr[i].a) * (s - tr[i].b) * (s - tr[i].c));
    }

    // Bubble sort triangles based on the area
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j] > p[j + 1]) {
                // Swap areas
                float temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;

                // Swap the sides of the triangles as well
                temp = tr[j].a;
                tr[j].a = tr[j + 1].a;
                tr[j + 1].a = temp;
                temp = tr[j].b;
                tr[j].b = tr[j + 1].b;
                tr[j + 1].b = temp;
                temp = tr[j].c;
                tr[j].c = tr[j + 1].c;
                tr[j + 1].c = temp;
            }
        }
    }

    free(p);
}

int main() {
    int n;
    printf("Enter the number of triangles: ");
    scanf("%d", &n);

    triangle *tr = malloc(n * sizeof(triangle));

    for (int i = 0; i < n; i++) {
        printf("Enter the sides of triangle number %d: ", i + 1);
        scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
    }

    sort_by_area(tr, n);

    printf("Triangles sorted by area:\n");
    for (int i = 0; i < n; i++) {
        printf("Triangle %d: %d, %d, %d\n", i + 1, tr[i].a, tr[i].b, tr[i].c);
    }

    free(tr);
    return 0;
}
