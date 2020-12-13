
#include "DistrictArray.h"
#include "iostream"

namespace ELC
{
    // need to check for index starts from 0 OR 1 and adjust accordingly

    void DistrictArray::addDistrict(District& d)
    {
        if (this->lsize == this->psize)
        {
            this->resize();
        }
        districtArr[lsize] = d;
        lsize++;
    }

    void DistrictArray::resize(int newsize)
    {
        if (newsize > psize)
        {
            District* newarr = new District[newsize];
            for (int i = 0; i < lsize; i++)
            {
                newarr[i] = districtArr[i];
            }
            delete[] districtArr;
            districtArr = newarr;
            psize = newsize;
        }
        else
        {
            std::cout << " Error! new size nust be greater then the physical size" << std::endl;
        }
    }

    void DistrictArray::resize()
    {
        psize *= 2;
        District* newarr = new District[psize];
        for (int i = 0; i < lsize; i++)
        {
            newarr[i] = districtArr[i];
        }
        delete[] districtArr;
        districtArr = newarr;
    }

    District& DistrictArray::getDistrict(int sernum)
    {
        return districtArr[sernum - 1];
    }

    int DistrictArray::getnum_of_districts() const
    {
        return lsize;
    }

    DistrictArray::~DistrictArray()
    {
        delete[] districtArr;
    }
} // namespace ELC