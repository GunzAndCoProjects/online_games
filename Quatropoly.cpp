#include "Quatropoly.h"

Quatropoly::Quatropoly()
{
    this->FirstToken = 'X';
    this->SecondToken = 'O';
    std::vector<int> Lines;
    for (int i=0; i<7; ++i)
    {
        int j = 0;
        Lines.push_back(j);
    }
    for (int i=0; i<6; ++i)
    {
        this->Field.push_back(Lines);
    }
    this->OutData = new DataTransferMonofieldGames();
}

Quatropoly::~Quatropoly()
{
    if (this->OutData != NULL)
    {
        delete this->OutData;
    }
}

void Quatropoly::moveTo(std::string Movement, char Token)
{
    if(this->canMoveTo(Movement))
    {
        std::pair<int, int> MovementInt = ConvertStringToCoordinates(Movement);
        int TokenInt = (Token == this->FirstToken ? 1 : 2);
        this->Field[MovementInt.first][MovementInt.second] = TokenInt;
    }
}

bool Quatropoly::canMoveTo(std::string Movement)
{
    std::pair<int, int> MovementInt = this->ConvertStringToCoordinates(Movement);
    bool predicate = false;
    bool Emptyness = (this->Field[MovementInt.first][MovementInt.second] == 0);
    bool Gravity = ( (MovementInt.first==5) || (this->Field[MovementInt.first+1][MovementInt.second] != 0) );
    predicate = (Emptyness && Gravity);
    return predicate;
}

std::pair<int, int> Quatropoly::ConvertStringToCoordinates(std::string Movement) const
{
    char Letter = Movement[0];
    char Numeral = Movement[1];
    std::pair<int, int> result;
    switch(Letter)
    {
        case 'A':
        {
            result.first = 0;
            break;
        }
        case 'a':
        {
            result.first = 0;
            break;
        }
        case 'B':
        {
            result.first = 1;
            break;
        }
        case 'b':
        {
            result.first = 1;
            break;
        }
        case 'C':
        {
            result.first = 2;
            break;
        }
        case 'c':
        {
            result.first = 2;
            break;
        }
        case 'D':
        {
            result.first = 3;
            break;
        }
        case 'd':
        {
            result.first = 3;
            break;
        }
        case 'E':
        {
            result.first = 4;
            break;
        }
        case 'e':
        {
            result.first = 4;
            break;
        }
        case 'F':
        {
            result.first = 5;
            break;
        }
        case 'f':
        {
            result.first = 5;
            break;
        }
    };
    switch(Numeral)
    {
        case '1':
        {
            result.second = 0;
            break;
        }
        case '2':
        {
            result.second = 1;
            break;
        }
        case '3':
        {
            result.second = 2;
            break;
        }
        case '4':
        {
            result.second = 3;
            break;
        }
        case '5':
        {
            result.second = 4;
            break;
        }
        case '6':
        {
            result.second = 5;
            break;
        }
        case '7':
        {
            result.second = 6;
            break;
        }
    };
    return result;
}

bool Quatropoly::gameOver()
{
    bool result = false;
    int notEmptyCounter = 0;
    for (int X = 0; X < 6; ++X)
    {
        if(result)
        {
            break;
        }
        for (int Y = 0; Y < 7; ++Y)
        {
            if(result)
            {
                break;
            }
            int currentToken = this->Field[X][Y];
            if (currentToken != 0)
            {
                ++notEmptyCounter;
                //try each direction
                for (int i = -1; i <= 1; ++i)
                {
                    for (int j = -1; j <= 1; ++j)
                    {
                        if (!(i == 0 && j == 0))
                        {
                            bool stop_direction = false;
                            int followingTokensCounter=1;
                            //move into direction
                            for (int Rad = 1; Rad < 7; ++Rad)
                            {
                                if (stop_direction)
                                {
                                    break;
                                }

                                int offset_X = i * Rad;
                                int offset_Y = j * Rad;

                                int coordX = X + offset_X;
                                int coordY = Y + offset_Y;

                                if (coordX < 0 || coordY < 0 || coordX > 5 || coordY > 6)
                                {
                                    continue;
                                }
                                else
                                {
                                    int tempToken = this->Field[coordX][coordY];
                                    if (tempToken != currentToken)
                                    {
                                        stop_direction = true;
                                    } else
                                    {
                                        ++followingTokensCounter;
                                    }
                                }
                            }
                            if (followingTokensCounter >= 4)
                            {
                                result = true;
                            }
                        }
                    }
                }
            }
        }
    }
    if(!result && notEmptyCounter==(6*7))
    {
        result = true;
    }
    return result;
}

bool Quatropoly::gameOver(char &token)
{
    bool result = false;
    int notEmptyCounter = 0;
    for (int X = 0; X < 6; ++X)
    {
        if(result)
        {
            break;
        }
        for (int Y = 0; Y < 7; ++Y)
        {
            if(result)
            {
                break;
            }
            int currentToken = this->Field[X][Y];
            if (currentToken != 0)
            {
                ++notEmptyCounter;
                //try each direction
                for (int i = -1; i <= 1; ++i)
                {
                    for (int j = -1; j <= 1; ++j)
                    {
                        if (!(i == 0 && j == 0))
                        {
                            bool stop_direction = false;
                            int followingTokensCounter = 1;
                            //move into direction
                            for (int Rad = 1; Rad < 7; ++Rad)
                            {
                                if (stop_direction)
                                {
                                    break;
                                }

                                int offset_X = i * Rad;
                                int offset_Y = j * Rad;

                                int coordX = X + offset_X;
                                int coordY = Y + offset_Y;

                                if (coordX < 0 || coordY < 0 || coordX > 5 || coordY > 6)
                                {
                                    continue;
                                } else
                                {
                                    int tempToken = this->Field[coordX][coordY];
                                    if (tempToken != currentToken)
                                    {
                                        stop_direction = true;
                                    } else
                                    {
                                        ++followingTokensCounter;
                                    }
                                }
                            }
                            if (followingTokensCounter >= 4)
                            {
                                result = true;
                                token = (currentToken == 1 ? this->FirstToken : this->SecondToken);
                            }
                        }
                    }
                }
            }
        }
    }
    if(!result && notEmptyCounter==(6*7))
    {
        result = true;
        token = ' ';
    }
    return result;
}

IDataTransfer* Quatropoly::getCurrentField()
{
    FieldInfo* WrappedField = new FieldInfo();
    WrappedField->Field = this->Field;
    mapping TokenMapping;
    std::pair<int, char> Empty(0, ' ');
    TokenMapping.insert(Empty);
    std::pair<int, char> First(1, this->FirstToken);
    TokenMapping.insert(First);
    std::pair<int, char> Second(2, this->SecondToken);
    TokenMapping.insert(Second);
    WrappedField->TokenMapping = TokenMapping;
    this->OutData->SetData((void*)WrappedField);
    delete WrappedField;
    return this->OutData;
}

int Quatropoly::calculateResult(std::string)
{
    //
}

char Quatropoly::getWinner()
{
    char result = '*';
    gameOver(result);
    return result;
}

void Quatropoly::saveGameMatch(ISave*)
{
    //
}

IGameable* Quatropoly::Clone()
{
    Quatropoly* Copy = new Quatropoly();
    *Copy = *this;
    return Copy;
}

char Quatropoly::GetFirstToken() const
{
    return this->FirstToken;
}

char Quatropoly::GetSecondToken() const
{
    return this->SecondToken;
}
