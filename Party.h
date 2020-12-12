#pragma once
#include "Citizen.h"
#include "Registry.h"
namespace ELC
{
    class Party
    {
    private:
        const char* partyname;
        Citizen& candidate; // points to a person that is the runner up
        Registry replist;  // linked list of persons
        int se_num;

    public:
        Party(/* args */);
        ~Party();
    };

} // namespace ELC