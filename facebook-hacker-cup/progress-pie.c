#include<stdio.h>
#include<math.h>
#define PI 3.14159

int checkPtOnCircle(int x, int y, int cx, int cy, int r) {
    return (x - cx)*(x - cx) + (y - cy)*(y - cy) <= r*r; 
}

int main(int argc, char** argv) {
    if (argc > 1) {
        freopen(argv[1], "r", stdin);
        freopen(argv[2], "w", stdout);
    }

    int t, i=1;
    int x, y, p;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &p, &x, &y);
        // equation of circle
        // (x-50)^2 - (y-50)^2 = 50^2
        
        // Checks 
        // 1. Check if point lies on the circle
        // 2. Check the the angle the point makes 
        if (checkPtOnCircle(x, y, 50, 50, 50)) {
            int pAngleDeg = p * 360/100;
            double angleRad = atan2(x - 50, y - 50);
            int angleDeg = angleRad * 180/PI;
            if (angleDeg < 0)
                angleDeg += 360;
            // printf("%d\n", pAngleDeg); 
            // printf("%d\n", angleDeg);
            if (pAngleDeg == 0) {
                printf("Case #%d: white\n", i++);
            }
            else if (angleDeg <= pAngleDeg) {
                printf("Case #%d: black\n", i++);
            }
            else printf("Case #%d: white\n", i++);
        }
        else printf("Case #%d: white\n", i++);
    }
    return 0;
}