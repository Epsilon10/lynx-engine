#include <stdlib.h>

typedef union {
    uint8_t*  u8;
    uint16_t* u16;
    uint32_t* u32;
    double*   f64;
    uintptr_t* uptr;
} lx_bson_parser_t;


#define FILESIZE 1000
#define LX_TYPE_STRING 1
#define LX_TYPE_INT 2
#define LX_TYPE_ARRAY 3
