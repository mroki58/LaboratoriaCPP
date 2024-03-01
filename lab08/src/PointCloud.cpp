#include "PointCloud.h"

void VPointCloud::addPoint(Point3D * point)
{
    _vector.push_back(point);
}

void VPointCloud::addPoint(std::array<double,3> point)
{
    _vector.push_back(new Point3D(point));
}

void VPointCloud::displayPoints()
{
    for(int i=0;i<_vector.size();i++)
    {
        _vector[i]->displayCoordinates();
    }
}

Point3D * VPointCloud::getCopyPoint(int i)
{
    return new Point3D(*(_vector[i]));
}
////////////////////////////////////////////////////////////
//////////////////DODAWANIE///////////////////////
////////////////////////////////////////////////////////////

void VPointCloud::add(const VPointCloud & cloud)
{
    bool IsTheSameCloud = false;

    if(_vector[0] == cloud._vector[0])
    {
        IsTheSameCloud = true;
    }

    if(!IsTheSameCloud)
    for(int i = 0 ; i < cloud._vector.size() ; ++i)
    {
           _vector.push_back( new Point3D( *(cloud._vector[i]) ) );
    }
}

////////////////KONSTRUKTOR I DESTRUKTOR/////////////////////

VPointCloud::VPointCloud(VPointCloud && cloud)
    {
        for(int i=0;i < cloud._vector.size();++i)
        {
            _vector.push_back(cloud._vector[i]);
            cloud._vector[i] = nullptr;
        }
    }

VPointCloud::~VPointCloud()
    {
        for(int i=0;i<_vector.size();i++)
        {
            if(_vector[i] != nullptr)
            {
                delete _vector[i];
                _vector[i] = nullptr;
            }
        }
    }