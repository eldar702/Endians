/* big and small endian are 2 different method for storing bits and bytes of data types.
 * the difference is expressed in how everything is representing and saving in the memory.
 * in Big endian the, the MSB is represent by the most left bit of the most left byte ,and the LSB is represent by the most right bit.
 * however, in Small endian the MSB is represent by the most right bit of the most left byte, and the
 * LSB is the most left bit of the most right byte. the most left  while in Small endian
 * Little and big endian are two ways of storing multibyte data-types
 * int represent by 4 byte (=32 bits) and char represent by 1 byte (=8 bits).
 * so for unsigned int 1:
 * Big Endian's machine will represents by    0000 0000 0000 0000
 * Small Endian's machine will represents by  0001 0000 0000 0000
 * char is represent by 1 byte (8 bits) so for the line  " char *c = (char *) &i; "
 * in Big Endian's machine
 * so in the line  " char *c = (char *) &i; ", in the action of the comparison,
 *  we make the pointer (that he is of size of 1 byte) to point only for 1 byte - the
 *  most right one, which in big endian's mechine  the LSB and therefore we will get 1
 *  and in small endian's mechine the oposite, so we will get 0.
 * to the
 */
int is_big_endian() {

    unsigned int i = 1;
    char *c = (char *) &i;
    if (*c)
        return 0;
    else
        return 1;
}
/*
 * Endianness is the way values are stored in the memory. the difference between big and small
 * endian is as described in the section of is_big_endian() method. when loaded into the
 * processor's register, the shifting operating is working the same (because Endianness is effect
 * only the method of memory save, and the load of data from the memory happened before the shift
 * operating). therefore, the shifting operator is working the same for both small and big endians.
 *  so when we shift variable half of is bits number, we actually delete the bits that shift
 *  (in our case, long is 8 byte and 64 bits. shifing it to some direction and shift it back to
 *  the opposite direction will make the variable contain now only half of its original bits - the
 *  smaller half if we shift first to the left, and the bigger half if opposite).
 */
unsigned long merge_bytes(unsigned long x, unsigned long int y)
{
    int size = sizeof(unsigned long) * 4; // size of unsigned long multiple by num of bit / 2 (8/2=4)
    y = y << (unsigned)size;
    y = y >> (unsigned)size;

    x = x >> (unsigned)size;
    x = x << (unsigned)size;

   return (x | y);
}
/**
 * i create pointer (c) which point to 1 byte of the variable that we want to change part of him.
 * and we implement him considering the endianess (as i allready described in the section of
 * method 1.
 */
unsigned long put_byte(unsigned long x, unsigned char b, int i)
{
    char *c = (char *) &x;
    int size = sizeof(unsigned long); // number of bytes
    if(!is_big_endian()) // the mechine is work as small endian
    {
        c[(size - 1 - i)] = b;
    }
    else // the mechine work as big endian
    {
        c[i] = b;
    }
    return x;
}
