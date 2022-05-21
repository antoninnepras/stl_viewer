#ifndef __vec3_h__
#define __vec3_h__

#include <math.h>


typedef struct {
  double x;
  double y;
  double z;
} Vec3;


Vec3 vec3_new(double x, double y, double z);


Vec3 vec3_add(Vec3 v1, Vec3 v2);


Vec3 vec3_sub(Vec3 v1, Vec3 v2);


Vec3 vec3_mul(Vec3 v, double s);


Vec3 vec3_div(Vec3 v, double s);


double vec3_dot(Vec3 v1, Vec3 v2);


Vec3 vec3_cross(Vec3 v1, Vec3 v2);


double vec3_size(Vec3 v);


#endif
