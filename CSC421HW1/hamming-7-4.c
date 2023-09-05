#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

unsigned char hamming_check(char c) {
    int mask = 0x01 ;
    int bit_number ;
    int parity = 0 ;
    for (bit_number=0;bit_number<7;bit_number++) {
        if (c&mask)
            parity ^= (bit_number+1) ;
        mask <<= 1 ;
    }
    return parity ;
}

unsigned char hamming_encode(char m) {
    char code = 0 ;
    int i, j;
    int parity;
    int mask = 0x01;
    
    for(i=0; i<4; i++)
    {
        int place[] = {0x04, 0x10, 0x20, 0x40};
        j=0x01<<i;
        if(m&j)
            code |=place[i];
    }
    parity = hamming_check(code);
    for(i=0; i<3; i++)
    {
        int place[] = {0x01, 0x02, 0x08};
        j = 0x01<<i;
        if(parity&j)
        {
            code |= place[i];
        }
        
    }
    assert(!hamming_check(code)) ;
    return code ;
}



//int main(int argc, char * argv[]) {
//    unsigned char uc = (unsigned char) atoi(argv[1]) ;
//    unsigned char uc_chk, uc_code ;
//    uc_code = hamming_encode(uc) ;
//    printf("0x%02x: 0x%02x\n", (int) uc, (int) uc_code ) ;
//    return 0 ;
//}

/*
correct output

data  code
----------
0x00: 0x00
0x01: 0x07
0x02: 0x19
0x03: 0x1e
0x04: 0x2a
0x05: 0x2d
0x06: 0x33
0x07: 0x34
0x08: 0x4b
0x09: 0x4c
0x0a: 0x52
0x0b: 0x55
0x0c: 0x61
0x0d: 0x66
0x0e: 0x78
0x0f: 0x7f
    
*/
