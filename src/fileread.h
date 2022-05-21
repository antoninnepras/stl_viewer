#ifndef __fileread_h__
#define __fileread_h__


#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rcodes.h"


int file_read_float(FILE* fp, float* f);


int file_read_double(FILE* fp, double* d);


int file_read_int32(FILE* fp, int32_t* i);


int file_read_uint32(FILE* fp, uint32_t* u);


int file_read_uint16(FILE* fp, uint16_t* u);


#endif
