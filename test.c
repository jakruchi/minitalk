#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t size = 1L << 30;  // Start with 1 GB
    void *ptr;

    while ((ptr = malloc(size)) != NULL) {
        printf("Allocated %zu bytes\n", size);
        free(ptr);
        size *= 2;  // Try double the size
    }

    printf("Failed at %zu bytes\n", size);
    return 0;
}
