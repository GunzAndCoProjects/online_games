#ifndef APPLICATION_H
#define	APPLICATION_H


#include <conio.h>
#include <vector>
#include <map>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "Network.h"
#include "IDisplay.h"
#include "FieldInfo.h"
#include "IGameable.h"
#include "Quatropoly.h"
#include "ILayerFactory.h"

enum GameMode {NONE, LOCAL, ONLINE_CREATE, ONLINE_CONNECT};

class Application
{
private:
    struct ApplicationParams
    {         
        bool in_process;
        std::string currentPlayer;
        std::string opponentPlayer;
        bool yourTurn;
        GameMode Mode;
        std::string IP;
        std::string Port;
        std::string Layer;
        std::string Game;
        std::pair<std::string, char> currentPlayerToken;
        std::pair<std::string, char> opponentPlayerToken;
        Network* AppNet;
        IDisplay* AppDisplay;
        ILayerFactory* LayerFactory;
    } AppParams;
    static Application* ApplicationObject;
    Application();
    
public:
    void Start();
    static Application* CreateInstance();
    ~Application();
    
protected:
    void InitializeAppParams();
    GameMode CastIntToEnum(int);
};

#endif