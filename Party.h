#pragma once
#include "Citizen.h"
namespace ELC
{
    class Party
    {
        private:
            char* partyname; 
            int nameSize;
            Citizen* candidate; // points to a person that is the runner up
            replistArray repLst;  // array of linked lists, each linked list is of representatives of a district
            int se_num;

        public:
            bool setPartyName(char* name);
            Party(char* name, Citizen* candidate);
            Party();
            ~Party();

            replistArray& getReplistArray();
            Party& operator=(const Party& vec);
    };

} // namespace ELC