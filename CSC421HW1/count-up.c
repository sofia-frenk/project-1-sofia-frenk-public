
/*
 * Printing different bases.
 * Code for printing in binary
 */

#include<stdio.h>
#include<stdlib.h>

void print_binary_aux(int i) {
    int bit ;
    if (i==0) return ;

    // you finish the code. Hint: You can note whether i is even or
    // odd. If even printf 0, else printf 1. But you cannot do that
    // right now else the bits will be printed out in reverse.
    // recurse on the approximate half of i then print out the bit

    // printf("%1d", bit) ; this is the format to use
    print_binary_aux(i/2);
    if(i%2==0)
    {
        bit=0;
        printf("%1d", bit) ;
    }
    else
    {
        bit=1;
        printf("%1d", bit) ;
    }
    return ;
}

void print_binary(int i) {
    if (i==0) printf("0b%d", i) ;
    else {
        printf("0b") ;
        print_binary_aux(i) ;
    }
}

//int main(int argc, char * argv[]){
//    int i ;
//    int N = atoi(argv[1]) ;
//    for (i=0;i<N;i++) {
//        printf("%d\t", i) ;
//        print_binary(i) ;
//        printf("\t0x%d", i) ;
//        printf("\n") ;
//    }
//    return 0 ;
//}



/*
this is the  output

0    0b0    0x0
1    0b1    0x1proper
2    0b10    0x2
3    0b11    0x3
4    0b100    0x4
5    0b101    0x5
6    0b110    0x6
7    0b111    0x7
8    0b1000    0x8
9    0b1001    0x9
10    0b1010    0x10
11    0b1011    0x11
12    0b1100    0x12
13    0b1101    0x13
14    0b1110    0x14
15    0b1111    0x15
16    0b10000    0x16
17    0b10001    0x17
18    0b10010    0x18
19    0b10011    0x19
20    0b10100    0x20
21    0b10101    0x21
22    0b10110    0x22
23    0b10111    0x23
24    0b11000    0x24
25    0b11001    0x25
26    0b11010    0x26

*/
