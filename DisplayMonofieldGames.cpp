#include "DisplayMonofieldGames.h"
#include "FieldInfo.h"

void DisplayMonofieldGames::ShowField(const IDataTransfer &FieldContainer)
{
    FieldInfo Field = *((FieldInfo*) FieldContainer.GetData());
    int heigh = Field.Field.size();
    int width = Field.Field[0].size();
    
    int ALetter = 65; //ASCII code of A
    int QuantOfLetters = 26;
    int BottomDigits = 1;
    std::vector <std::string> TempField;

    //Show Bottom Digits
    std::cout << "\n\t";
    std::cout << "   ";
    for (int i = 0; i < width; i++)
    {
        if (BottomDigits < 9)
        {
            std::cout << " " << BottomDigits << "  ";
            BottomDigits++;
        } else
        {
            std::cout << " " << BottomDigits << " ";
            BottomDigits++;
        }
    }

    std::cout << "\n";

    int tempheigh = 0;

    while (tempheigh < heigh)
    {
        //Show Gorisontal Lines
        std::cout << "\t  ";
        for (int i = 0; i < width; i++)
        {
            std::cout << "+---";
        }
        std::cout << "+\n";

        std::cout << "\t";

        //Show Vertical Letters
        std::cout << (char) ALetter << " ";

        //Show Gorisontal Lines + Symbols
        for (int i = 0; i < width; i++)
        {
            int NumericCell = Field.Field[tempheigh][i];
            char CharCell = Field.TokenMapping[NumericCell];
            
            std::cout << "| ";
            std::cout << CharCell; //Replace by map & vector
            std::cout << " ";
        }
        std::cout << "|\n";

        tempheigh++;
        //Increment Letter
        ALetter++;
    }

    //Show Last Gorisontal Line
    std::cout << "\t  ";
    for (int i = 0; i < width; i++)
    {
        std::cout << "+---";
    }
    std::cout << "+\n";
}