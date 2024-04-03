//
// Created by PC on 03/04/2024.
//

#include <stdio.h>
#include <math.h>

#ifndef LEARNING_POINT_H
#define LEARNING_POINT_H

typedef struct
{
    int x;
    int y;
} Point;

typedef struct
{
    int x;
    int y;
    int z;
    double angle;
} Point3D;

Point point_create(int x, int y);
void point_print(Point p);
Point3D point3D_create(int x, int y, int z);
void point3D_print(Point3D p);
Point point_project(Point3D p, int d);
void point_rotate(Point3D* p, double angle, Point center);

#endif //LEARNING_POINT_H
