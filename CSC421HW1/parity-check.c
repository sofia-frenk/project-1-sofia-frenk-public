#include<stdio.h>
#include<stdlib.h>

char parity_check(char c, int direction) {
    int mask = 0x01 ;
    int parity = 0 ;
    //int bit_number;
    
    // count the number of 1s in c. You can use (c&mask) to isolate the bit
    // you wish to count. Then flip the top bit to correct the parity.
    // A good bit flip operation is c^0x80
    
//    int maskRes;
//    char cCopy =c;
//    bit_number = 0;
//    do {
//        maskRes = cCopy &mask;
//        cCopy = cCopy>>bit_number;
//        bit_number++;
//        if (maskRes) parity++;
//    } while(bit_number != 8);
//
//    if(parity%2 != 0)
//        c = c^0x80;
//    return c;
    
    int maskRes;
    char cCopy =c;
    do {
        maskRes = cCopy &mask;
        cCopy = cCopy>>1;
        if (maskRes) parity++;
    } while(cCopy != 0);
    
    if(parity%2 != 0)
        c = c^0x80;
    return c;
}

int main(int argc, char * argv[]) {
    unsigned char uc = (unsigned char) atoi(argv[1]) ;
    unsigned char uc_chk ;
    uc_chk = parity_check(uc,0) ;
    printf("0x%02x: 0x%02x\n", (int) uc, (int) uc_chk ) ;
    return 0 ;
}

/*
this should be the output

code  parity
------------
0x00: 0x00
0x01: 0x81
0x02: 0x82
0x03: 0x03
0x10: 0x90
0x30: 0x30
0x1c: 0x9c
*/
