#include "LayerFactoryMonofield.h"

IGameFactory* LayerFactoryMonofield::ConstructGame()
{
    return new GameFactoryMonofield();    
}

IDisplay* LayerFactoryMonofield::ConstructDisplay()
{
    return new DisplayMonofieldGames();
}

ILayerFactory * LayerFactoryMonofield::Clone()
{
    LayerFactoryMonofield * pLayerFactoryMonofield = new LayerFactoryMonofield();
    *pLayerFactoryMonofield = *this;
    return pLayerFactoryMonofield;
}