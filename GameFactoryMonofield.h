#ifndef GAMEFACTORYMONOFIELD_H
#define	GAMEFACTORYMONOFIELD_H

#include "IGameFactory.h"

class GameFactoryMonofield: public IGameFactory
{
public:
    GameFactoryMonofield();
    virtual IGameable* GetGame(std::string);
    virtual std::vector<std::string> GetGamesList();
private:
    std::map<std::string, IGameable*> GamesCollection;
};

#endif	/* GAMEFACTORYMONOFIELD_H */

