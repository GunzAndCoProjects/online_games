#ifndef QUATROPOLY_H
#define	QUATROPOLY_H

#include "IGameable.h"
#include <utility>
#include "DataTransferMonofieldGames.h"

class Quatropoly: public IGameable
{
public:
    Quatropoly();
    ~Quatropoly();
    void moveTo(std::string, char);
    bool canMoveTo(std::string);
    bool gameOver();
    IDataTransfer* getCurrentField();
    int calculateResult(std::string);
    char getWinner();
    void saveGameMatch(ISave*);
    IGameable* Clone();
    char GetFirstToken() const;
    char GetSecondToken() const;
protected:
    std::pair<int, int> ConvertStringToCoordinates(std::string) const;
    bool gameOver(char &token);
private:
    field Field;
    char FirstToken;
    char SecondToken;
    DataTransferMonofieldGames* OutData;
};

#endif