#include <unistd.h>
#include <stdio.h>

int main(void) {
    printf("%d", access("aaa", X_OK));
    return 0;
}