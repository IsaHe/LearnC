
#include "point.h"

Point point_create(int x, int y)
{
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

void point_print(Point p)
{
    printf("(%d, %d)\n", p.x, p.y);
}

Point3D point3D_create(int x, int y, int z)
{
    Point3D p;
    p.x = x;
    p.y = y;
    p.z = z;
    return p;
}

void point3D_print(Point3D p)
{
    printf("(%d, %d, %d)\n", p.x, p.y, p.z);
}

Point point_project(Point3D p, int d)
{
    Point projected;
    projected.x = p.x * d / p.z;
    projected.y = p.y * d / p.z;
    return projected;
}

void point_rotate(Point3D* p, double angle)
{
    double s = sin(angle);
    double c = cos(angle);

    int x = p->x;
    int y = p->y;

    p->x = x * c - y * s;
    p->y = x * s + y * c;
}

