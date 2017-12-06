#include "IObservable.h"
#include "IObserver.h"

namespace Moge
{
    void IObservable::registerObserver( IObserver* observer )
    {
        this->observers.insert( observer );
    }

    void IObservable::unregisterObserver( IObserver* observer )
    {
        this->observers.erase( observer );
    }
}