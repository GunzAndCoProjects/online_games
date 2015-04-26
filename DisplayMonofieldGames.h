#ifndef DISPLAYMONOFIELDGAMES_H
#define	DISPLAYMONOFIELDGAMES_H


#include "Display.h"

class DisplayMonofieldGames: public Display 
{
public:
    virtual void ShowField(const IDataTransfer&);
};

#endif	

