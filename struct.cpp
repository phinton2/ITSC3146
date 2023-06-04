// Paydreanne E. Hinton
#include <iostream>
#include <cmath>
struct CartesianCoordinate {
    float x;
    float y;
};

float calculateDistance (const CartesianCoordinate& p1, const CartesianCoordinate& p2) {
    // float distance = sqrt(((p2.x - p1.x)*(p2.x - p1.x))+((p2.y - p1.y)(p2.y - p1.y)));
    return sqrt(((p2.x - p1.x)*(p2.x - p1.x))+((p2.y - p1.y)*(p2.y - p1.y)));
}

int main() {
    CartesianCoordinate p1;
    CartesianCoordinate p2;
    
    std::cout << "Enter the x-coordinate of the first point: ";
    std::cin >> p1.x; // assigns integer to p1's x-coordinate
    std::cout << "Enter the y-coordinate of the first point: ";
    std::cin >> p1.y; // assigns integer to p1's y-coordinate

    std::cout << "\nEnter the x-coordinate of the second point: ";
    std::cin >> p2.x; // assigns integer to p2's x-coordinate
    std::cout << "Enter the y-coordinate of the second point: ";
    std::cin >> p2.y; // assigns integer to p2's y-coordinate

    float distance = calculateDistance(p1, p2); // assigns value of calculated distance to "distance" variable

    std::cout << "\nDistance between the two points: " << distance; // displays distance between two points

    return 0;
  
    /*
    1) https://www.delftstack.com/howto/cpp/calculate-distance-between-two-points-in-cpp/
    2) https://www.geeksforgeeks.org/program-calculate-distance-two-points/
    3) https://codereview.stackexchange.com/questions/144586/finding-the-distance-between-two-points-in-c
    */
}
