#include "Point3D.h"

int Point3D::DISPLAY_PRESITION = -1;

Point3D::Point3D(std::array<double,3> table)
{
    _cords = table;
}

void Point3D::displayCoordinates() const
{
    if(DISPLAY_PRESITION != -1)
    {
        std::cout << std::fixed;
        std::cout << std::setprecision(DISPLAY_PRESITION);
    }
    std::cout << "(" <<_cords[0];

    for(int i=1;i<3;++i)
    {
        std::cout << ", " << _cords[i];
    }

    std::cout<<")";
    std::cout<<std::endl;

}
