#ifndef IGAMEFACTORY_H
#define	IGAMEFACTORY_H

#include "IGameable.h"


class IGameFactory
{
public:
    virtual IGameable* GetGame(std::string) = 0;
    virtual std::vector<std::string> GetGamesList() = 0;
};

#endif	/* IGAMEFACTORY_H */

