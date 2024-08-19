#include <iostream>
#include <graphics.h>
using namespace std;

void drawEllipse(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
}

void midpointEllipse(int xc, int yc, int rx, int ry)
{
    float dx, dy, d1, d2, x, y;
    x = 0;
    y = ry;

    // Initial decision parameter of region 1
    d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    // For region 1
    while (dx < dy)
    {
        drawEllipse(xc, yc, x, y);

        // Checking and updating value of decision parameter based on algorithm
        if (d1 < 0)
        {
            x++;
            dx = dx + (2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        }
        else
        {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
        }
    }

    // Decision parameter of region 2
    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);

    // Plotting points of region 2
    while (y >= 0)
    {
        drawEllipse(xc, yc, x, y);

        // Checking and updating parameter value based on algorithm
        if (d2 > 0)
        {
            y--;
            dy = dy - (2 * rx * rx);
            d2 = d2 + (rx * rx) - dy;
        }
        else
        {
            y--;
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d2 = d2 + dx - dy + (rx * rx);
        }
    }
}

int main()
{
    int xc, yc, rx, ry;

    // Initialize graphics mode
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Input center and radii of the ellipse
    cout << "Enter the center of the ellipse (xc, yc): ";
    cin >> xc >> yc;
    cout << "Enter the x-radius (rx): ";
    cin >> rx;
    cout << "Enter the y-radius (ry): ";
    cin >> ry;

    // Draw the ellipse using Midpoint Ellipse Algorithm
    midpointEllipse(xc, yc, rx, ry);

    getch(); // Wait for a key press
    closegraph(); // Close the graphics mode

    return 0;
}

