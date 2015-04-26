#ifndef GAME_LAYER_FACTORY_H
#define	GAME_LAYER_FACTORY_H

#include "ILayerFactory.h"
#include "LayerFactoryMonofield.h"

class GAME_LAYER_FACTORY
{
public:
    GAME_LAYER_FACTORY();
    std::vector<std::string> GetLayerList();
    ILayerFactory* GetLayer(std::string);
private:
    std::map<std::string, ILayerFactory*> Layers;
};

#endif	/* GAME_LAYER_FACTORY_H */

