#include <stdint.h>
#include<stdio.h>
int32_t abs(int32_t num){
    int32_t mask = (num >> 31);
    return ((num - mask) ^ mask);
    // return ~num + 1;
}

int main() {
    printf("%d\n", abs(22));
    return 0;
}