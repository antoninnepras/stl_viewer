#include "vec3.h"


Vec3 vec3_new(double x, double y, double z)
{
  return (Vec3){x, y, z};
}


Vec3 vec3_add(Vec3 v1, Vec3 v2)
{
  return (Vec3){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}


Vec3 vec3_sub(Vec3 v1, Vec3 v2)
{
  return (Vec3){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}


Vec3 vec3_mul(Vec3 v, double s)
{
  return (Vec3){v.x * s, v.y * s, v.z * s};
}


Vec3 vec3_div(Vec3 v, double s)
{
  return (Vec3){v.x / s, v.y / s, v.z / s};
}


double vec3_dot(Vec3 v1, Vec3 v2)
{
  return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}


Vec3 vec3_cross(Vec3 v1, Vec3 v2)
{
  return (Vec3){v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z,
                v1.x * v2.y - v1.y * v2.x};
}


double vec3_size(Vec3 v)
{
  return sqrt(vec3_dot(v, v));
}
