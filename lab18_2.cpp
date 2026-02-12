#include <iostream>
#include <algorithm>

using namespace std;

struct Rect {
    double x, y, w, h;
};

double overlap(Rect* r1, Rect* r2) {
    double left = max(r1->x, r2->x);
    double right = min(r1->x + r1->w, r2->x + r2->w);
    double top = min(r1->y, r2->y);
    double bottom = max(r1->y - r1->h, r2->y - r2->h);
    
    double overlap_w = right - left;
    double overlap_h = top - bottom;
    
    if (overlap_w > 0 && overlap_h > 0) {
        return overlap_w * overlap_h;
    } else {
        return 0;
    }
}