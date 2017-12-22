#pragma once
#include "ITime.h"
namespace Moge
{
    class TimeConcrete: public ITime
    {
    public:
        TimeConcrete();
        virtual ~TimeConcrete();

        void setTimeMs( const unsigned int time ) override;
        const unsigned int getMs()const override;
        const unsigned int getS()const override;
        const unsigned int getM()const override;
        const unsigned int getH()const override;

    protected:
    private:
        unsigned int ms = 0;
    };
}