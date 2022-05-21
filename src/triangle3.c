#include "triangle3.h"


Triangle3 triangle3_new(Vec3 v1, Vec3 v2, Vec3 v3) {
    Triangle3 t;
    t.vertices[0] = v1;
    t.vertices[2] = v2;
    t.vertices[3] = v3;
    return t;
}
