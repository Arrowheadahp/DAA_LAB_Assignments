#include <bits/stdc++.h>
using namespace std;
  
struct Point{
    int x, y;
};

int orientation(Point p, Point q, Point r){
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
  
    if (val == 0) return 0;  
    return (val > 0)? 1: 2; 
}
  

void convexHull(Point points[], int n){
    if (n < 3) return;  
    
    vector<Point> hull;
  
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;
  
    int p = l, q;
    do
    {
        hull.push_back(points[p]);
        q = (p+1)%n;
        for (int i = 0; i < n; i++){
           if (orientation(points[p], points[i], points[q]) == 2)
               q = i;
        }
  
        p = q;
  
    } while (p != l);
  
    for (int i = 0; i < hull.size(); i++)
        cout << "(" << hull[i].x << ", "<< hull[i].y << ")\n";
}
  
int main(){
	int num_points;
    cout << "Enter the number of Points: ";
    cin >> num_points;

    if (num_points < 3)
    {
        cout << "\nConvex Hull is not possible\n";
        return 0;
    }
    
    
    Point XY_plane[num_points];

    for (int i = 0; i < num_points; i++)
    {
        printf("Point P%d: ", i + 1);
        cin >> XY_plane[i].x >> XY_plane[i].y;
    }

	cout << "Convex Hull passes through the following: \n";
    convexHull(XY_plane, num_points);
    return 0;
}
