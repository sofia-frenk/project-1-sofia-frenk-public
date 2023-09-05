#include<stdio.h>
#include<stdlib.h>

char repetiton_check(char c) {
    int mask = 0x01 ;
    //int bit_number ;
    int parity = 0 ;
    
    // count the number of 1s in c, and if 2 or more return 0x07, else return 0x00
    int maskRes;
    char cCopy =c;
//    bit_number = 0;
//    do {
//        maskRes = cCopy &mask;
//        cCopy = cCopy>>bit_number;
//        bit_number++;
//        if (maskRes) parity++;
//    } while(bit_number != 8);
    
    do {
        maskRes = cCopy &mask;
        cCopy = cCopy>>1;
        if (maskRes) parity++;
    } while(cCopy != 0);
    
    if(parity >= 2)
    {
        c = 0x07;
    }
    else
    {
        c = 0x00;
    }
    
    return c ;
}

int main(int argc, char * argv[]) {
    unsigned char uc = (unsigned char) atoi(argv[1]) ;
    unsigned char uc_chk ;
    uc_chk = repetiton_check(uc) ;
    printf("0x%02x: 0x%02x\n", (int) uc, (int) uc_chk ) ;
    return 0 ;
}

/*
this should be the output

code  parity
------------
0x00: 0x00
0x01: 0x00
0x02: 0x00
0x03: 0x07
0x04: 0x00
0x05: 0x07
0x06: 0x07
0x07: 0x07

*/
