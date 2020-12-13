#pragma once
#include "District.h"
#include "Party.h"
#include "Registry.h"
#include "DistrictArray.h"
#include "Citizen.h"

namespace ELC
{
    class replist
    {
    private:
        Registry RPArray; //array of person linked list
        District& district;   //refrenc to the county of the reps

    public:
        replist(int countynum, District& cn) : RPArray(), District(county)
        {
        }
        ~replist();

        void addcounty(District&);
        void addcounty(const char*, int);

        void addrep(int, int);      // id and county num
        void addrep(int, Citizen&); // county num and person
    };

} // namespace ELC