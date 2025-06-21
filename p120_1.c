#include <stdio.h>

int main(){

    int money;
    float time;

    printf("연봉을 입력하시오(단위:만원): ");

    scanf("%d",&money); //  변수 주소를 저장하려면 "&" 붙이는거 기억하기기

    time = 1000000000.0 / (money*10000) ;
    
    printf("10억을 모으는데 걸리는 시간(단위: 년): %.2f",time);


}