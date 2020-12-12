#pragma once

#include "Registry.h"
namespace ELC
{
    static int NumOfCounties = 0;
    class District
    {
    private:
        const char* districtName;
        int nameSize;
        int repnum;  // number of representative
        int senum;   // serial number
        float voted; // in percentage  OR  can be int aswell and add method to evaluate the precentage
        int AlreadyVoted;
        Registry nomlist; // nominees
        Registry voters;  // points to the first and last person from the county as given in the registry
                          // all voters in county - not sure this is necessary

    public:
        District(const char* name, int repnum)
        {
            
            //maybe need to init nomlist and voters (registry)
        }
        District();
        ~District();

        //setters
        bool setcountyname(const char*);
        bool set();
        bool set(const char* disName, int numRep);
        bool setDisName(const char* disName);
        bool setNumRep(int numRep);

        //getters
        int getNumRep();
        const char* getName();
        int getvoted();
        int getsenum();
        const registry& getnomlist();
        const registry& getvoters();

        void operator=(District&);
    };

} // namespace ELC


