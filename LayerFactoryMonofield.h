#ifndef LAYERFACTORYMONOFIELD_H
#define	LAYERFACTORYMONOFIELD_H

#include "ILayerFactory.h"
#include "DisplayMonofieldGames.h"
#include "GameFactoryMonofield.h"

class LayerFactoryMonofield: public ILayerFactory
{
public:
    virtual IGameFactory* ConstructGame();
    virtual IDisplay* ConstructDisplay();
    virtual ILayerFactory * Clone();
};

#endif	/* LAYERFACTORYMONOFIELD_H */

