#include <stdio.h>
#include <stdlib.h>
#include "pointy.h"

/**
    Function: getMrPointyAndFriends()
    Description: Retrieves points that share the same quadrant as the first point (Mr. Pointy) in the cartesian plane.
    Param: points - a collection of points starting with Mr. Pointy followed by the others.
    Return: a collection of points that are in the same quadrant as Mr. Pointy, including Mr. Pointy himself.
*/
Points getMrPointyAndFriends(Points points) {
    Points friends;
    friends.count = 0;
    friends.max = points.count;
    friends.points = (MyPoint*) malloc(friends.max * sizeof(MyPoint));

    // Extract Mr. Pointy
    MyPoint mrPointy = points.points[0];

    // Determine the quadrant of Mr. Pointy
    int x_sign = (mrPointy.x > 0) ? 1 : (mrPointy.x < 0) ? -1 : 0;
    int y_sign = (mrPointy.y > 0) ? 1 : (mrPointy.y < 0) ? -1 : 0;

    // Iterate through points to find friends in the same quadrant
    for (int i = 0; i < points.count; i++) {
        MyPoint currentPoint = points.points[i];

        // Check if the current point is in the same quadrant as Mr. Pointy
        if ((currentPoint.x * x_sign >= 0 && currentPoint.y * y_sign >= 0) ||
            (currentPoint.x == 0 && currentPoint.y == 0 && (x_sign != 0 || y_sign != 0))) {
            friends.points[friends.count++] = currentPoint;
        }
    }

    return friends;
}

void main() {
    Points points = createPoints(30);
    Points friends;
    int x, y;

    populatePoints(&points);

    printf("Enter x - coordinate: ");
    scanf("%d", &x);
    printf("Enter y - coordinate: ");
    scanf("%d", &y);

    // Update Mr. Pointy with user input
    points.points[0].x = x;
    points.points[0].y = y;

    displayPointMsg(points.points[0]);

    // Get friends in the same quadrant as Mr. Pointy
    friends = getMrPointyAndFriends(points);

    printf("Friends: ");
    displayAllPointsWithStartIndex(friends, 0);

    // Free allocated memory for friends
    free(friends.points);
}
