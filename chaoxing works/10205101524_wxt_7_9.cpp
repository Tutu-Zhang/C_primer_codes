#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;

const double PI = 3.14;

class circle
{
private:
    double radius; 
    double posx; 
    double posy;
public:
    double area()
    {
        double area = radius * radius * PI;
        return area;
    }

    double circumference()
    {
        double circumference = 2 * radius * PI;
        return circumference;
    }

    void setCircle(double r,double x,double y)
    {
        radius = r;
        posx = x;
        posy = y;
    }

    void print()
    {
        cout << "radius: " << radius << " ";
        cout << "xPoint: " << posx << " ";
        cout << "yPoint: " << posy << " ";
        cout << endl;
        cout << "area is: " << area() << endl;
        cout << "circumference is:" << circumference() << endl;
        cout << endl;
    }
};





int main()
{
    ifstream inFile;
    circle c;
    double r;
    double x,y;
    inFile.open("d://information.txt");
    if(!inFile)
    {
        cout << "Invalid input file." << endl;
        exit(0);
    }
    inFile >> r >> x >> y;
    while(inFile)
    {
        c.setCircle(r,x,y);
        c.print();
        inFile >> r >> x >> y;
    }
    return 0;
}
