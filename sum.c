// 有问题的版本 
#include <stdio.h>
int main() {
    float sum = 0.0f;
    int sumi = 0;
    for (int i = 0; i < 10000; i++){
        sum += i + 1;
        sumi += i + 1;
        if (sum < sumi) {
            printf("%d : %f, %d\n", i, sum, sumi);
            break;
        }            
    } 
      printf("Sum: %f\n", sum);
    return 0;
}
// 1 + 2 + 3 + … + 10000 = 10000 * (10000 + 1) / 2 = 50005000 ?

// // 修正的版本
// #include <stdio.h>
// int main() {
//     float sum = 0.0f, corr = 0.0f; /* corrective value for rounding error */
//     for (int i = 0; i < 10000; i++) {
//       float y = (i + 1) - corr; /* add the correction to specific item */
//       float t = sum + y; /* bits might be lost */
//       corr = (t - sum) - y; /* recover lost bits */
//       sum = t;
//       printf("%d : %f\n", i, sum);
//     }
//     printf("Sum: %f\n", sum);
//     return 0;
// }