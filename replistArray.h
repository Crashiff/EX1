#pragma once
#include "replist.h"
using namespace ELC;
class replistArray
{
    private:
        replist* replistarr;
        int psize, lsize;
        void resize();
        void resize(int);

    public:
        replistArray(/* args */);
        ~replistArray();

        replist* getReplistArray();
        void addRepresentative(Citizen& c, District& d);

        void addReplist(); // adds new district replist
        void addreplist(Citizen); // creats new replist with perosn
        void addreptocounty(int, Citizen); // adds person as rep for exsiting district

};

