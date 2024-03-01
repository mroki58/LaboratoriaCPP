#include "PointCloud.h"

Point3D::Point3D(std::array<double,3> table)
{
    _cords = table;
}

void Point3D::displayCoordinates() const
{
    std::cout << "(" <<_cords[0];

    for(int i=1;i<3;++i)
    {
        std::cout << ", " << _cords[i];
    }

    std::cout<<")";

}
//////////////////////////////////////////////////////////////////////////

APointCloud::APointCloud()
{
    _table = nullptr;
    _iter = 0;
}

void APointCloud::addPoint(Point3D point)
{
    _iter++;
    Point3D * newTable = new Point3D[_iter];

    for(int i=0; i < _iter -1; ++i)
    {
        newTable[i] = _table[i];
    }

    delete [] _table;

    newTable[_iter - 1] = point;

    _table = newTable;

}

void APointCloud::displayPoints() const
{
    std::cout<<"Chmura punktow [APC]:"<<std::endl;
    for(int i=0;i < _iter; i++)
    {
        _table[i].displayCoordinates();
        std::cout<<std::endl;
    }
}

Point3D APointCloud::geoCentre()
{
    double x=0,y=0,z=0;
    for(int i=0;i<_iter;++i)
    {
        x += _table[i]._cords[0];// Zwraca wspolrzedne geometryczne punktu znajdujacego sie w geometrycznym
    // srodku wszystkich punktow w chmurze
        y += _table[i]._cords[1];
        z += _table[i]._cords[2];
    }

    return Point3D({x/_iter,y/_iter,z/_iter});
}

APointCloud::~APointCloud()
{
    delete [] _table;
}

/////////////////////////////////////////////////////////////////////////////

void VPointCloud::addPoint(Point3D point)
{
    _vector.push_back(point);
}

void VPointCloud::add(const VPointCloud & cloud)
{
    _vector.insert(_vector.end(),cloud._vector.begin(),cloud._vector.end());
}

void VPointCloud::add(const APointCloud & cloud)
{
    for(int i=0 ; i < cloud._iter ; ++i)
    {
        _vector.push_back(cloud._table[i]);
    }
}

Point3D VPointCloud::geoCentre()
{
    double x=0,y=0,z=0;
    for(int i=0;i<_vector.size();++i)
    {
        x += _vector[i]._cords[0];
        y += _vector[i]._cords[1];
        z += _vector[i]._cords[2];
    }

    return Point3D({x/_vector.size(),y/_vector.size(),z/_vector.size()});
}

int VPointCloud::count()
{
    return _vector.size();
}