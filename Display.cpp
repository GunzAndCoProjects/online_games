#include "Display.h"

Display::Display()
{
    NumAllowableStr = "1234567890";
    LettersAllowableStr = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
}

Display::~Display()
{
    if(this->pDisplay != NULL)
    {
        delete pDisplay;
    }
}

//GetFiltratedStr FUNCTION
//arguments:
//1) availableChars - string of available chars, used as a filter
//2) symbolsQuantity - total number of symbols for user to input,
//N.B.: if symbolsQuantity is set as (-1), this means that there is no limitation on quantity input
std::string Display::GetFiltratedStr(std::string availableChars, int symbolsQuantity)
{
    char atomic_char;
    std::string s_choice = "";
    int entered_chars_quantity = 0;
    while ( symbolsQuantity<0 ? (atomic_char = getch()) != '\r' : entered_chars_quantity<symbolsQuantity && (atomic_char = getch()) != '\r' ) 
    {
        if (CheckAvailableChar(atomic_char, availableChars)) 
        {
            s_choice += atomic_char;
            std::cout << atomic_char;
            ++entered_chars_quantity;
        }
    }
    return s_choice;
}

bool Display::CheckAvailableChar(char ch, std::string availableChars)
{
    int pos = availableChars.find(ch);
    return (pos==std::string::npos ? false : true);
}

bool Display::CheckPositionInsideLimits(int pos, int downLimit, int upLimit)
{
    return (pos >= downLimit && pos<=upLimit)? true : false;
}

int Display::MenuChoose(std::string caption, std::vector<std::string> menu)
{
    std::stringstream RResultSS;
    int Result;
    bool CheckResult = false;

    while (CheckResult != true) {
        std::cout << "\t\t\t" << caption << "\n\n";

        for (int i = 0, vec_size = menu.size(); i < vec_size; i++) {
            std::cout << i << " : " << menu[i] << "\n";
        }

        RResultSS.clear();
        RResultSS << GetFiltratedStr(NumAllowableStr, 2);
        RResultSS>>Result;

        CheckResult = CheckPositionInsideLimits(Result, 0, menu.size()-1);

        if (CheckResult == false) 
        {
            std::cout << "\n Incorrect value, please press Enter and enter a number in the range from " << 0 << " to " << menu.size()-1<<"\n";
            getch();
            ClearScreen();
        }
    }
    return Result;
}

void Display::Message(std::string MessageString)
{
    std::cout<<"\n"<<MessageString<<"\n";
}

std::string Display::GetMovement()
{
    std::string ResultStr;
    std::string LetterStr;
    std::string DigitStr;
     
    std::cout<<"Please, make you movement. Enter a letter: ";
    LetterStr = GetFiltratedStr(LettersAllowableStr, 1);
    std::cout<<"\n";
    
    std::cout<<"Please, make you movement. Enter a Digit: ";
    DigitStr = GetFiltratedStr(NumAllowableStr, 1);
    std::cout<<"\n";
    
    ResultStr = LetterStr + DigitStr;
  
    return ResultStr;
}

 std::string Display::AskForString(std::string availableChars)
 {
    std::string ResultStr ="";
    if (availableChars == "")
    {
        std::cin>>ResultStr;
    }
    else
    {
        ResultStr=GetFiltratedStr(availableChars);   
    }
    return ResultStr;
 }

void Display::AskForSmth()
{
    getch();
}
 
 void Display::InformLooser(std::string looserName)
 {
    std::vector <std::string> LoserView;

    LoserView.push_back("\n\t\t\t         .1Q$$ES.        \n");
    LoserView.push_back("\t\t\t      YMMMM06UQMMMM;     \n");
    LoserView.push_back("\t\t\t    .MMZ          bMM.   \n");
    LoserView.push_back("\t\t\t   iM@   .      .   MM:  \n");
    LoserView.push_back("\t\t\t   M$   bMM:  iMM6   MM  \n");
    LoserView.push_back("\t\t\t  MM    MMM;  XMM#    M@ \n");
    LoserView.push_back("\t\t\t  M@     7.    ,c     MM \n");
    LoserView.push_back("\t\t\t  M@      :E@#0,      MM \n");
    LoserView.push_back("\t\t\t  MM   tMMM$8b$MMM7   M@ \n");
    LoserView.push_back("\t\t\t   M# MMS        oMM @M  \n");
    LoserView.push_back("\t\t\t   iM@,            :MM,  \n");
    LoserView.push_back("\t\t\t    .MM2          8MM    \n");
    LoserView.push_back("\t\t\t      iMMMMWAZQMMMMi     \n");
    LoserView.push_back("\t\t\t          ;t9USi         \n");

    for (int i = 0, vec_size = LoserView.size(); i < vec_size; i++)
    {
        std::cout << LoserView[i];
    }

    std::cout << "\n\t\t\t Game Over " << looserName << ". You Lose.\n";
 }
 
 void Display::InformWinner(std::string winnerName)
 {
    std::vector <std::string> WinnView;

    WinnView.push_back("\n\t\t\t          iE@@M#E,        \n");
    WinnView.push_back("\t\t\t       6MMMM$Q0#MMMMt     \n");
    WinnView.push_back("\t\t\t     :MMQ          $MM.   \n");
    WinnView.push_back("\t\t\t    SMM   ,.    .,   MM;  \n");
    WinnView.push_back("\t\t\t   .M#   #MM;  CMMQ   MM  \n");
    WinnView.push_back("\t\t\t   MM    MMMX  bMM@    MM \n");
    WinnView.push_back("\t\t\t   M@     Qn    98     MM \n");
    WinnView.push_back("\t\t\t   M@  M,          c@  MM \n");
    WinnView.push_back("\t\t\t   MM  MM         .MM  MM \n");
    WinnView.push_back("\t\t\t   .MM  MM$.    .@MM  MM  \n");
    WinnView.push_back("\t\t\t    7MM  .MMMMMMMM.  MM,  \n");
    WinnView.push_back("\t\t\t     .MMW          #MM    \n");
    WinnView.push_back("\t\t\t       7MMMMEo2EMMMM;     \n");
    WinnView.push_back("\t\t\t           YIb9U;         \n");


    for (int i = 0, vec_size = WinnView.size(); i < vec_size; i++)
    {
        std::cout << WinnView[i];
    }

    std::cout << "\nt\t\t\t Congratulations " << winnerName << " You Win!\n";
 }
 
 void Display::Greetings()
{
    std::vector <std::string> TitleView;

    TitleView.push_back("\t      _    _      _                            _              \n");
    TitleView.push_back("\t     | |  | |    | |                          | |             \n");
    TitleView.push_back("\t     | |  | | ___| | ___ ___  _ __ ___   ___  | |_ ___        \n");
    TitleView.push_back("\t     | |/\\| |/ _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | __/ _ \\       \n");
    TitleView.push_back("\t     \\  /\\  /  __/ | (_| (_) | | | | | |  __/ | || (_) |      \n");
    TitleView.push_back("\t      \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___|  \\__\\___/       \n");
    TitleView.push_back("\t                                                              \n");
    TitleView.push_back("\t _____       _ _              _____                           \n");
    TitleView.push_back("\t|  _  |     | (_)            |  __ \\                          \n");
    TitleView.push_back("\t| | | |_ __ | |_ _ __   ___  | |  \\/ __ _ _ __ ___   ___  ___ \n");
    TitleView.push_back("\t| | | | '_ \\| | | '_ \\ / _ \\ | | __ / _` | '_ ` _ \\ / _ \\/ __|\n");
    TitleView.push_back("\t\\ \\_/ / | | | | | | | |  __/ | |_\\ \\ (_| | | | | | |  __/\\__ \\\n");
    TitleView.push_back("\t \\___/|_| |_|_|_|_| |_|\\___|  \\____/\\__,_|_| |_| |_|\\___||___/\n\n");
    TitleView.push_back("\t\t       ___      __      _      ___   \n");
    TitleView.push_back("\t\t      |_  )    /  \\    / |    | __|  \n");
    TitleView.push_back("\t\t       / /    | () |   | |    |__ \\  \n");
    TitleView.push_back("\t\t      /___|   _\\__/   _|_|_   |___/  \n");
    TitleView.push_back("\t\t    _|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"| \n");
    TitleView.push_back("\t\t    \"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-' \n\n");
    TitleView.push_back("\t\t          All Rights Reserved (c) \n\n");

    for (int i = 0, vec_size = TitleView.size(); i < vec_size; i++)
    {
        std::cout << TitleView[i];
    }
 }
 
 void Display::ClearScreen()
 {
     system("cls");
 }
 
 void Display::ShowScore(std::map<std::string, int> PlayerScoreMap)
{
    std::cout << "\n\t +----------------------- ~ SCORE ~ -----------------------+";

    typedef std::map<std::string, int>::const_iterator MapIterator;
    
    for (MapIterator iter = PlayerScoreMap.begin(); iter != PlayerScoreMap.end(); iter++) 
    {
        std::cout << "\n\t |\t\t" << iter->first << "\t\t\t" << " : " << iter->second << "\t\t   |\n";
        std::cout << "\t +---------------------------------------------------------+";
    }
    std::cout << "\n";
 }
 
 bool Display::ExitProgCheckBl ()
{
    std::cout << "Are you sure you want to exit the application (Y/N)? ";
    std::string FilterStr = "yYnN";

    std::string ExChk;
    ExChk = GetFiltratedStr(FilterStr, 1);    

    if (ExChk == "y" || ExChk == "Y")
    {
        return true;
    } 
    else if (ExChk == "n" || ExChk == "N")
    {
        return false;
    } 
    else
    {
        system("cls");
        return false;
    }
}
 
void Display::ShowField(const IDataTransfer& Field)
{
    if(this->pDisplay == NULL)
    {
        std::cout<<"No realization available";
    }
    else
    {
        this->pDisplay->ShowField(Field);
    }
}
 
void Display::SpecializeDisplay(IDisplay * pDisplay_)
{
    this->pDisplay = pDisplay_;
}