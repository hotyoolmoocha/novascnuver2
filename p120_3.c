#include <stdio.h>

int main() {
    int base;
    int height;
    float area;

    printf("삼각형의 밑변: ");
    scanf("%d", &base);
    
    printf("삼각형의 높이: ");
    scanf("%d", &height);

    area = 0.5 * base * height;

    printf("삼각형의 넓이: %.2f\n", area);

    return 0;
}