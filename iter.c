#include <stdio.h>

int draw(int height) {
    if (height <= 0) {
        return 1;
    } else {    
        draw(height - 1);
        for (int i = 0; i < height; i++) {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}

int main(void) {
    int height;
    fscanf(stdin, "%d", &height);
    draw(height);
}