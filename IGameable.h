#ifndef IGAMEABLE_H
#define	IGAMEABLE_H


#include <string>
#include "IDataTransfer.h"
#include "FieldInfo.h"
#include "ISave.h"

class IGameable
{
public:
    virtual void moveTo(std::string, char) = 0;
    virtual bool canMoveTo(std::string) = 0;
    virtual bool gameOver() = 0;
    virtual IDataTransfer* getCurrentField() = 0;
    virtual int calculateResult(std::string) = 0;
    virtual char getWinner() = 0;
    virtual void saveGameMatch(ISave*) = 0;
    virtual IGameable* Clone() = 0;
    virtual char GetFirstToken() const = 0;
    virtual char GetSecondToken() const = 0;
};

#endif