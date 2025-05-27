#include<stdio.h>
int main() {
    float radius;
    float area;

    printf("원의 반지름을 입력하세요:");
    scanf("%f", &radius);

    area = 3.141592 * radius * radius;
    printf("이 원의 반지름은 %f이고,\n 면적은 %f입니다.", radius, area);

    return 0;
}
