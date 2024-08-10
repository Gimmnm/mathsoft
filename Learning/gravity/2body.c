#include <math.h>
#include <stdio.h>

#define G 6.67430e-11
#define dt 0.001
#define N 10000

int main() {
    double r11 = 0, r12 = 0,
            r21 = 1, r22 = 0,
            v11 = 0, v12 = 1,
            v21 = 0, v22 = -1,
            m1 = 1e11, m2 = 1e11;
    for (int i = 0; i < N; i++) {
        double dx = r21 - r11;
        double dy = r22 - r12;
        r11 = r11 + v11 * dt;
        r12 = r12 + v12 * dt;
        double d = sqrt(dx * dx + dy * dy);
        double d3 = d * d * d;
        double a11 = G * m2 * dx / d3;
        double a12 = G * m2 * dy / d3;
        v11 = v11 + a11 * dt;
        v12 = v12 + a12 * dt;

        r21 = r21 + v21 * dt;
        r22 = r22 + v22 * dt;
        dx = -dx;
        dy = -dy;
        d = sqrt(dx * dx + dy * dy);
        d3 = d * d * d;
        double a21 = G * m1 * dx / d3;
        double a22 = G * m1 * dy / d3;
        v21 = v21 + a21 * dt;
        v22 = v22 + a22 * dt;
    }
    return 0;
}