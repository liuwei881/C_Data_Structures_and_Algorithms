#include <stdio.h>

//int invert(x, p, n);
//
//int main(){
//    int j;
//    j = invert(4567, 3, 2);
//    printf("%u\n", j);
//    return 0;
//}
//
//int invert(x, p, n){
//    return ~(x & ((~0 << (p + 1)) | (~(~0 << (p + 1 - n)))));
//}

unsigned invert(unsigned x, int p, int n){
    return x ^ (~(~0U << n) << p);
}

int main(){
    unsigned x;
    int p, n;
    for(x = 0; x < 700; x += 49)
        for(n = 1; n < 8; n++)
            for(p = 1; p < 8; p++)
                printf("%u, %d, %d: %u\n", x, n, p, invert(x, n, p));
    return 0;
}