#ifndef DISPLAY_H
#define	DISPLAY_H

#include "IDisplay.h"
#include <cstdlib>
#include <iostream>
#include <sstream>

class Display: public IDisplay
{
public:
    Display();
    ~Display();
    virtual void ClearScreen();
    virtual void Greetings(); // when application starts
    virtual void InformWinner(std::string winnerName);
    virtual void InformLooser(std::string looserName);
    virtual std::string AskForString(std::string availableChars = ""); //whenever a string required from user
    virtual void AskForSmth();
    virtual std::string GetMovement();
    virtual void Message(std::string);
    virtual int MenuChoose(std::string caption, std::vector<std::string> menu);
    virtual void ShowField(const IDataTransfer&);
    virtual void ShowScore(std::map<std::string, int>);
    virtual void SpecializeDisplay(IDisplay * pDisplay_);
    virtual bool ExitProgCheckBl();
protected:
    virtual std::string GetFiltratedStr(std::string availableChars, int symbolsQuantity = -1);
    virtual bool CheckAvailableChar(char ch, std::string availableChars);
    virtual bool CheckPositionInsideLimits(int pos, int downLimit, int upLimit);
private:
    IDisplay * pDisplay;
    std::string NumAllowableStr;
    std::string LettersAllowableStr;
};

#endif