#include "GameFactoryMonofield.h"
#include "Quatropoly.h"

GameFactoryMonofield::GameFactoryMonofield()
{
    this->GamesCollection["Quatropoly"] = new Quatropoly();
}

IGameable* GameFactoryMonofield::GetGame(std::string Game)
{
    return this->GamesCollection[Game]->Clone();
}

std::vector<std::string> GameFactoryMonofield::GetGamesList()
{
    int MapSize = this->GamesCollection.size();
    std::vector<std::string> GameList;
    for(std::map<std::string, IGameable*>::iterator i = this->GamesCollection.begin(); i!=this->GamesCollection.end(); ++i)
    {
        std::pair<std::string, IGameable*> elem = *i;
        GameList.push_back(elem.first);
    }
    return GameList;
}