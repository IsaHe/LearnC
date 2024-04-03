
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

void point_rotate(Point3D* p, double angle, Point center)
{
    double s = sin(angle);
    double c = cos(angle);

    p->x -= center.x;
    p->y -= center.y;

    int x = p->x * c - p->y * s;
    int y = p->y * s + p->x * c;

    p->x = x + center.x;
    p->y = y + center.y;

    p->angle += angle;
    printf("Angle: %f\n", p->angle);
}

