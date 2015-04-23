#ifndef IDISPLAY_H
#define	IDISPLAY_H


#include "IDataTransfer.h"
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <map>
#include <utility>

class IDisplay
{
public:
    virtual void ClearScreen() = 0;
    virtual void Greetings() = 0; // when application starts
    virtual void InformWinner(std::string winnerName) = 0;
    virtual void InformLooser(std::string looserName) = 0;
    virtual std::string AskForString(std::string availableChars = "") = 0; //whenever a string required from user
    virtual void AskForSmth() = 0;
    virtual std::string GetMovement() = 0;
    virtual void Message(std::string) = 0;
    virtual int MenuChoose(std::string caption, std::vector<std::string> menu) = 0;
    virtual void ShowField(const IDataTransfer&) = 0;
    virtual void ShowScore(std::map<std::string, int>) = 0;
    virtual void SpecializeDisplay(IDisplay * pDisplay_) = 0;
    virtual bool ExitProgCheckBl() = 0;
};

#endif