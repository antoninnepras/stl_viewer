#ifndef __mesh_h__
#define __mest_h__

#include "triangle3.h"


typedef struct {
    Triangle3* triangles;
    int triangle_cnt;
    int triangle_cap;
} Mesh;


Mesh* mesh_create(void);


int mesh_destroy(Mesh* msh);


int mesh_add_triangle(Mesh* msh, Triangle3 t);


#endif
