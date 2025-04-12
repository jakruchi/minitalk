// file2.c
#include <stdio.h>

int ft_isspace(int c);

int main() {
    printf("%d\n", ft_isspace(' '));  // ❌ ERROR: Undefined reference
    return 0;
}
