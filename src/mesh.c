#include "mesh.h"


Mesh* mesh_create(void);


int mesh_destroy(Mesh* msh);


int mesh_add_triangle(Mesh* msh, Triangle3 t);
