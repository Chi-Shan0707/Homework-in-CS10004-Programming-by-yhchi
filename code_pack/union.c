#include<stdio.h>
union
{
    short int i;
    char c[2];
}u;
int main()
{
    /*
     * Explanation:
     * - A union overlays its members in the same memory region. Here `u.i` and
     *   `u.c[2]` share the same 2 bytes of storage.
     * - We store two characters into the byte array: 'A' (0x41) at c[0]
     *   and 'a' (0x61) at c[1]. On a little-endian machine the lowest-address
     *   byte (c[0]) is the least-significant byte of the `short`.
     * - The 16-bit value of `u.i` becomes 0x6161<<8? No — correct calculation:
     *   u.i = (unsigned char)u.c[1] << 8 | (unsigned char)u.c[0]
     *   = 0x61 * 256 + 0x41 = 97*256 + 65 = 24897
     * - Therefore printing `u.i` yields 24897, and printing `u.c[0]`/`u.c[1]`
     *   shows the characters 'A' and 'a'. On big-endian machines the numeric
     *   value would be different because byte order is reversed.
     */
    u.c[0] = 'A';
    u.c[1] = 'a';
    printf("u.i  =  %d", u.i);
    printf("\nu.c[0]  =  %c", u.c[0]);
    printf("\nu.c[1]  =  %c", u.c[1]);
    return 0;
 /* 
u.i  =  24897
u.c[0]  =  A
u.c[1]  =  a
 */
//u.i=(unsigned char)u.c[1]×256+(unsigned char)u.c[0]=97×256+65=24897，

/*
If "union" is replaced by "struct", u.i u.c[0] u.c[1] will have their own places because  struct isn't stingy but very generous !
The output will be:
0
A
a
*/
}
