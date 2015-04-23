#ifndef ILAYERFACTORY_H
#define	ILAYERFACTORY_H

#include "IGameable.h"
#include "IDisplay.h"
#include "IGameFactory.h"

class ILayerFactory
{
public:
    virtual IGameFactory* ConstructGame() = 0;
    virtual IDisplay* ConstructDisplay() = 0;
    virtual ILayerFactory * Clone() = 0;
};

#endif
