#include "src/mesh.h"


int main(int argc, const char** argv)
{
  Mesh* msh = mesh_load_stl_bin("stl.stl");
  if (msh == NULL) {
    return 10;
  }
  
  mesh_destroy(msh);
  return 0;
}
