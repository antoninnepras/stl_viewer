#ifndef __mesh_h__
#define __mest_h__


#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "triangle3.h"
#include "fileread.h"

#define MESH_DEFAULT_CAP 4


typedef struct {
  Triangle3* triangles;
  int triangle_cnt;
  int triangle_cap;
} Mesh;


Mesh* mesh_create(void);


int mesh_destroy(Mesh* msh);


int mesh_add_triangle(Mesh* msh, Triangle3 t);


Mesh* mesh_load_stl_bin(const char* file);


Mesh* mesh_load_stl_ascii(const char* file);


#endif
