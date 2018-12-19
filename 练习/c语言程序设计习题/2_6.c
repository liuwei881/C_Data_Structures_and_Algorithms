#include <stdio.h>

//int setbits(unsigned int x, unsigned int p, unsigned int n, unsigned int y);
//
//int main(){
//    int r;
//    r=setbits(111111, 3, 2, 101010);
//    printf("%d ", r);
//    return 0;
//}
//
//int setbits(unsigned int x, unsigned int p, unsigned int n, unsigned int y){
//    int a;
//    x=x>>p;
//    a=(x>>n - y<<n);
//    return a;
//}


unsigned setbits(unsigned x, int p, int n, unsigned y){
    return (x & ((~0 << (p + 1)) | (~(~0 << (p + 1 - n))))) | ((y & ~(~0 << n)) << (p + 1 - n));
}

int main(void){
    unsigned i;
    unsigned j;
    unsigned k;
    int p;
    int n;
    for(i = 0; i < 30000; i += 511){
        for(j = 0; j < 1000; j += 37){
            for(p = 0; p < 16; p++){
                for(n = 1; n <= p + 1; n++){
                    k = setbits(i, p, n, j);
                    printf("setbits(%u, %d, %d, %u) = %u\n", i, p, n, j, k);
                }
            }
        }
    }
    return 0;
}