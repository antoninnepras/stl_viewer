#ifndef __triangle3_h__
#define __triangle3_h__


#include "vec3.h"


typedef struct {
  Vec3 vertices[3];
} Triangle3;


Triangle3 triangle3_new(Vec3 v1, Vec3 v2, Vec3 v3);


#endif
