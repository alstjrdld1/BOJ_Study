#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int W, H, X, Y, P;
    cin >> W >> H >> X >> Y >> P;
    
    int lCircleCenterX, lCircleCenterY;
    int rCircleCenterX, rCircleCenterY;
    float R = H / 2;
    lCircleCenterX = X;
    lCircleCenterY = Y + R;
    rCircleCenterX = X + W;
    rCircleCenterY = Y + R;
    int sunsu = 0;

    for (int i = 0 ; i < P; i++)
    {
        int x, y;
        cin >> x >> y;
        if ( ((X <= x) && (x <= X + W)) && ((Y <= y) && (y <= Y+H)) )
        {
            sunsu++;
            continue;
        }
        float lcdistance = sqrt(pow((x-lCircleCenterX), 2) + pow((y-lCircleCenterY), 2));
        float rcdistance = sqrt(pow((x-rCircleCenterX), 2) + pow((y-rCircleCenterY), 2));
        if (lcdistance <= R)
        {
            sunsu++;
            continue;
        }
        if (rcdistance <= R)
        {
            sunsu++;
            continue;
        }
    }

    cout << sunsu;
    
    return 0;
}