#include "fileread.h"


int file_read_float(FILE* fp, float* f)
{
  if (fp == NULL || f == NULL) {
    return ERROR;
  }

  char tmp[sizeof(float)];
  for (int k = 0; k < sizeof(float); ++k) {
    tmp[k] = fgetc(fp);
    if (k < 0) {
      return ERROR;
    }
  }

  memcpy(f, tmp, sizeof(float));

  return SUCCESS;
}


int file_read_double(FILE* fp, double* d)
{
  if (fp == NULL || d == NULL) {
    return ERROR;
  }

  char tmp[sizeof(double)];
  for (int k = 0; k < sizeof(double); ++k) {
    tmp[k] = fgetc(fp);
    if (k < 0) {
      return ERROR;
    }
  }

  memcpy(d, tmp, sizeof(double));

  return SUCCESS;
}


int file_read_int32(FILE* fp, int32_t* i)
{
  if (fp == NULL || i == NULL) {
    return ERROR;
  }

  char tmp[sizeof(int32_t)];
  for (int k = 0; k < sizeof(int32_t); ++k) {
    tmp[k] = fgetc(fp);
    if (k < 0) {
      return ERROR;
    }
  }

  memcpy(i, tmp, sizeof(int32_t));

  return SUCCESS;
}


int file_read_uint32(FILE* fp, uint32_t* u)
{
  if (fp == NULL || u == NULL) {
    return ERROR;
  }

  char tmp[sizeof(uint32_t)];
  for (int k = 0; k < sizeof(uint32_t); ++k) {
    tmp[k] = fgetc(fp);
    if (k < 0) {
      return ERROR;
    }
  }

  memcpy(u, tmp, sizeof(uint32_t));

  return SUCCESS;
}



int file_read_uint16(FILE* fp, uint16_t* u)
{
  if (fp == NULL || u == NULL) {
    return ERROR;
  }

  char tmp[sizeof(uint16_t)];
  for (int k = 0; k < sizeof(uint16_t); ++k) {
    tmp[k] = fgetc(fp);
    if (k < 0) {
      return ERROR;
    }
  }

  memcpy(u, tmp, sizeof(uint16_t));

  return SUCCESS;
}
