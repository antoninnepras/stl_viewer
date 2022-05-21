#include "mesh.h"


Mesh* mesh_create(void)
{
  Mesh* msh = (Mesh*)malloc(sizeof(Mesh));
  if (msh == NULL) {
    return NULL;
  }

  msh->triangles = (Triangle3*)calloc(sizeof(Triangle3), MESH_DEFAULT_CAP);
  if (msh->triangles == NULL) {
    mesh_destroy(msh);
    return NULL;
  }

  msh->triangle_cap = MESH_DEFAULT_CAP;
  msh->triangle_cnt = 0;

  return msh;
}


int mesh_destroy(Mesh* msh)
{
  if (msh == NULL) {
    return ERROR;
  }

  if (msh->triangles != NULL) {
    free(msh->triangles);
  }

  free(msh);

  return SUCCESS;
}


int mesh_add_triangle(Mesh* msh, Triangle3 t)
{
  if (msh == NULL) {
    return ERROR;
  }

  if (msh->triangle_cap == msh->triangle_cnt) {
    msh->triangle_cnt *= 2;
    msh->triangles = (Triangle3*)realloc(msh->triangles,
                                         msh->triangle_cap * sizeof(Triangle3));
    if (msh->triangles == NULL) {
      return ERROR;
    }
  }

  msh->triangles[msh->triangle_cnt] = t;
  msh->triangle_cnt++;

  return SUCCESS;
}
