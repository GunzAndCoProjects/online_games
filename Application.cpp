#include "Application.h"
#include "Display.h"
#include "GAME_LAYER_FACTORY.h"
//

////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////CLASS BUILDING METHODS////////////////////////
////////////////////////////////////////////////////////////////////////////////

void Application::InitializeAppParams()
{
    this->AppParams.AppDisplay = new Display();
    this->AppParams.AppNet = new Network();
    this->AppParams.in_process = true;
    this->AppParams.yourTurn = false;
}

Application::Application()
{
    this->InitializeAppParams();    
}

Application::~Application()
{
    delete this->AppParams.AppNet;
    delete this->AppParams.AppDisplay;
    delete this->AppParams.LayerFactory;        
}

Application* Application::ApplicationObject = NULL;

Application* Application::CreateInstance()
{
    if(Application::ApplicationObject != NULL)
    {
        return Application::ApplicationObject;
    }
    else
    {
        Application::ApplicationObject = new Application();
    }
}

////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////MAIN METHODS//////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void Application::Start()
{
    this->AppParams.AppDisplay->Greetings();
    this->AppParams.AppDisplay->AskForSmth();    
    while(this->AppParams.in_process)
    {
        this->AppParams.AppDisplay->ClearScreen();
        
        this->AppParams.AppDisplay->Message("Enter your name:");
        this->AppParams.currentPlayer = this->AppParams.AppDisplay->AskForString();
        
        this->AppParams.AppDisplay->ClearScreen();
        
        std::vector<std::string> GameModes;
        GameModes.push_back("Nothing to choose.");
        GameModes.push_back("Local game between two loosers.");
        GameModes.push_back("Create an online game.");
        GameModes.push_back("Connect to online game.");
        this->AppParams.Mode = this->CastIntToEnum(this->AppParams.AppDisplay->MenuChoose("Now choose your game mode:", GameModes));
        
        this->AppParams.AppDisplay->ClearScreen();
        
        this->AppParams.AppDisplay->Message("Enter your IP:");
        this->AppParams.IP = this->AppParams.AppDisplay->AskForString("0123456789.");
        this->AppParams.AppDisplay->Message("Enter your port:");
        this->AppParams.Port = this->AppParams.AppDisplay->AskForString("0123456789");
        
        this->AppParams.AppDisplay->ClearScreen();
        
        GAME_LAYER_FACTORY* LayerFactoryConstructor = new GAME_LAYER_FACTORY();
        std::vector<std::string> LayersList = LayerFactoryConstructor->GetLayerList();
        int iLayerChosen = this->AppParams.AppDisplay->MenuChoose("Choose game type:", LayersList);
        this->AppParams.Layer = LayersList[iLayerChosen];
        this->AppParams.LayerFactory = LayerFactoryConstructor->GetLayer(this->AppParams.Layer);
        
        this->AppParams.AppDisplay->ClearScreen();
        
        IGameFactory* GameFactory = this->AppParams.LayerFactory->ConstructGame();
        IDisplay* DisplaySpecification = this->AppParams.LayerFactory->ConstructDisplay();
        this->AppParams.AppDisplay->SpecializeDisplay(DisplaySpecification);
        
        std::vector<std::string> GamesList = GameFactory->GetGamesList();
        int iGameChosen = this->AppParams.AppDisplay->MenuChoose("Choose game to play:", GamesList);
        this->AppParams.Game = GamesList[iGameChosen];
        IGameable* Game = GameFactory->GetGame(this->AppParams.Game);
        this->AppParams.currentPlayerToken.first = this->AppParams.currentPlayer;
        this->AppParams.currentPlayerToken.second = Game->GetFirstToken();
        
        this->AppParams.AppDisplay->ClearScreen();
                
        if(this->AppParams.Mode == ONLINE_CREATE)
        {                        
            IDataTransfer* DataTrans = Game->getCurrentField();
            this->AppParams.AppDisplay->ShowField(*DataTrans);
            getch();
        }
        
        if (this->AppParams.Mode == LOCAL)
        {
            this->AppParams.AppDisplay->Message("Enter Second Player name:");
            this->AppParams.opponentPlayer = this->AppParams.AppDisplay->AskForString();

            this->AppParams.opponentPlayerToken.first = this->AppParams.opponentPlayer;
            this->AppParams.opponentPlayerToken.second = Game->GetSecondToken();

            bool CheckGameEnd = false;
            bool WhichPlayerTurn = true;
            char currentToken = '*';

            while (!CheckGameEnd)
            {
                currentToken = (WhichPlayerTurn ? AppParams.currentPlayerToken.second : AppParams.opponentPlayerToken.second);

                this->AppParams.AppDisplay->ClearScreen();
                IDataTransfer* DataTrans = Game->getCurrentField();
                this->AppParams.AppDisplay->ShowField(*DataTrans);

                std::string MoveTmpStr;
                bool MoveValid = false;

                while (!MoveValid)
                {
                    std::string currentUserInfoAboutMove = "Player " + (WhichPlayerTurn ? this->AppParams.currentPlayer: this->AppParams.opponentPlayer) + " makes movement ( " + currentToken + " )";
                    this->AppParams.AppDisplay->Message(currentUserInfoAboutMove);
                    MoveTmpStr = this->AppParams.AppDisplay->GetMovement();
                    MoveValid = Game->canMoveTo(MoveTmpStr);

                    if (MoveValid == false)
                    {
                        this->AppParams.AppDisplay->Message("You Turn Is Not Valid, Press Enter And Try Again");
                        getch();
                        this->AppParams.AppDisplay->ClearScreen();
                        IDataTransfer* DataTrans = Game->getCurrentField();
                        this->AppParams.AppDisplay->ShowField(*DataTrans);
                    } 
                    else
                    {
                        Game->moveTo(MoveTmpStr, currentToken);
                        WhichPlayerTurn = (!WhichPlayerTurn);
                        MoveValid = true;
                    }
                }

                if (Game->gameOver() == true)
                {
                    this->AppParams.AppDisplay->ClearScreen();
                    IDataTransfer* DataTrans = Game->getCurrentField();
                    this->AppParams.AppDisplay->ShowField(*DataTrans);
                    if (Game->getWinner() == ' ')
                    {
                        AppParams.AppDisplay->Message("Nobody Wins");
                    } else
                    {
                        if (this->AppParams.currentPlayerToken.second == Game->getWinner())
                        {
                            this->AppParams.AppDisplay->InformWinner(this->AppParams.currentPlayerToken.first);
                            this->AppParams.AppDisplay->InformLooser(this->AppParams.opponentPlayerToken.first);
                        } else
                        {
                            std::cout << this->AppParams.opponentPlayerToken.first;
                            this->AppParams.AppDisplay->InformWinner(this->AppParams.opponentPlayerToken.first);
                            this->AppParams.AppDisplay->InformLooser(this->AppParams.currentPlayerToken.first);
                        }
                    }
                    CheckGameEnd = true;
                }
            }
        }
        
        if(this->AppParams.Mode == ONLINE_CONNECT)
        {
            //
        }
                
        delete LayerFactoryConstructor;
        this->AppParams.in_process = !(this->AppParams.AppDisplay->ExitProgCheckBl());
    }
}

////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////SERVICE METHODS///////////////////////////////
////////////////////////////////////////////////////////////////////////////////

GameMode Application::CastIntToEnum(int INT)
{
    if(INT == 1)
    {
        return LOCAL;
    };
    if(INT == 2)
    {
        return ONLINE_CREATE;
    };
    if(INT == 3)
    {
        return ONLINE_CONNECT;        
    };
    return NONE;
}