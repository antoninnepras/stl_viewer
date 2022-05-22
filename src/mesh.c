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
    msh->triangle_cap *= 2;
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


Mesh* mesh_load_stl_bin(const char* file)
{
  FILE* fp = fopen(file, "r");
  if (fp == NULL) {
    return NULL;
  }

  Mesh* mesh = NULL;
  char header[80];
  for (int i = 0; i < 80; ++i) {
    header[i] = fgetc(fp);
    if (header[i] < 0) {
      fclose(fp);
      return NULL;
    }
  }

  mesh = mesh_create();

  uint32_t triangle_num;
  if (file_read_uint32(fp, &triangle_num) == ERROR) {
    fclose(fp);
    return NULL;
  }
  printf("%u\n", triangle_num);

  for (int i = 0; i < triangle_num; ++i) {
    Triangle3 tri;
    for (int j = 0; j < 3; ++j) {
      float tmp;
      file_read_float(fp, &tmp);
    }

    for (int j = 0; j < 3; ++j) {
      float tmp;
      file_read_float(fp, &tmp);
      tri.vertices[j].x = tmp;
      file_read_float(fp, &tmp);
      tri.vertices[j].y = tmp;
      file_read_float(fp, &tmp);
      tri.vertices[j].z = tmp;
    }
    
    uint16_t tmp16;
    if(file_read_uint16(fp, &tmp16) == ERROR) {
      fclose(fp);
      return NULL;
    }

    if (mesh_add_triangle(mesh, tri) == ERROR) {
      fclose(fp);
      return NULL;
    }
  }

  fclose(fp);
  return mesh;
}


Mesh* mesh_load_stl_ascii(const char* file)
{
  // TODO:
  return NULL;
}
