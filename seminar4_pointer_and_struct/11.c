#include <stdio.h>
#include <math.h>

struct point
{
    double x;
    double y;
};
typedef struct point Point;

struct triangle
{
    Point a;
    Point b;
    Point c;
};
typedef struct triangle Triangle;

void print_point(Point p)
{
    printf("(%f, %f)", p.x, p.y);
}

void print_triangle(const Triangle* t)
{
    printf("{");
    print_point(t->a);
    printf(", ");
    print_point(t->b);
    printf(", ");
    print_point(t->c);
    printf("}\n");
}

double distance(Point p1, Point p2)
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

double get_triangle_perimeter(const Triangle* t)
{
    return distance(t->a, t->b) + distance(t->b, t->c) + distance(t->c, t->a);
}

void move_triangle(Triangle* t, Point d)
{
    t->a.x += d.x;
    t->a.y += d.y;
    t->b.x += d.x;
    t->b.y += d.y;
    t->c.x += d.x;
    t->c.y += d.y;
}

int main()
{
    Triangle t = {{{1.00, 0.00}, {0.50, 2.00}, {0.00, 1.50}}};
    printf("%f\n", get_triangle_perimeter(&t));
    Point d = {1.0, 1.0};
    print_triangle(&t);
    move_triangle(&t, d);
    print_triangle(&t);
    return 0;
}