#include "GAME_LAYER_FACTORY.h"

GAME_LAYER_FACTORY::GAME_LAYER_FACTORY()
{
    this->Layers["Monofield"] = new LayerFactoryMonofield();
}

std::vector<std::string> GAME_LAYER_FACTORY::GetLayerList()
{
    std::vector<std::string> LayersList;
    for(std::map<std::string, ILayerFactory*>::iterator i = this->Layers.begin(); i!=this->Layers.end(); ++i)
    {
        std::pair<std::string, ILayerFactory*> elem = *i;
        LayersList.push_back(elem.first);
    }
    return LayersList;
}

ILayerFactory* GAME_LAYER_FACTORY::GetLayer(std::string Layer)
{
    return this->Layers[Layer]->Clone();
}
