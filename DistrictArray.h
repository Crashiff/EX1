#pragma once
#include "District.h"
namespace ELC
{
    class DistrictArray
    {
        private:
            District* districtArr;
            int lsize, psize; // lsize for actual number of items, psize for the arr actual size [ (psize >= lsize) == true ]
            void resize();
            void resize(int); // resize to a specific asked size

        public:
            DistrictArray() : districtArr(new District[2]), lsize(0), psize(2) {}
            explicit DistrictArray(District& d) : DistrictArray() 
            {
                lsize++;
                districtArr[0] = d;
            }
            ~DistrictArray();

            void addDistrict(District&);
            // void addcounty(const char* name, int num_of_reps); // not realy required i think

            District& getDistrict(int); // get by serial number
            int getnum_of_districts() const;
    };

} // namespace ELC
