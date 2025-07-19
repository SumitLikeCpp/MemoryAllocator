#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <errno.h>

// attribute is tell compiler to how it handle every thing
#define packed __attribute__((__packed__))
#define unused __attribute__((__unused__))

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
typedef unsigned long long int int64;
typedef unsigned long long int128;  // Using 64-bit instead of 128-bit for compatibility
typedef void heap;
typedef int32 word;         // word data type

// header
struct s_header {
    word w:30;
    bool alloced:1;
    bool reserved:1;
} __attribute__((__packed__));
typedef struct s_header header;


// some alias
#define $1 (int8 *)
#define $2 (int16)
#define $4 (int32)
#define $8 (int64)
#define $16 (int128)
#define $c (char *)
#define $i (int)
#define $v (void *)
#define $h (header *)

int main(int , char**);