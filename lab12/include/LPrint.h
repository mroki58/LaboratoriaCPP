#pragma once
#include "LArray.h"

class LPrint
{
public:
        LPrint() = default;
        void operator ()(const Line & fa) const;
        void operator ()(const LArray & arr) const;
};

