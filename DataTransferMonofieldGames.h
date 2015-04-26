#ifndef DATATRANSFER_H
#define	DATATRANSFER_H

#include "IDataTransfer.h"
#include "FieldInfo.h"
#include <cstdlib>

class DataTransferMonofieldGames: public IDataTransfer
{
public:
    DataTransferMonofieldGames(const FieldInfo &Data_);
    DataTransferMonofieldGames();
    DataTransferMonofieldGames(const DataTransferMonofieldGames &DataTransfer_);
    
    ~DataTransferMonofieldGames();
    
    DataTransferMonofieldGames & operator = (const DataTransferMonofieldGames &DataTransfer_);
    
    void* GetData() const;
    void SetData(void* Data_);
    
protected:
    void unsetPointer();
    
private:
    FieldInfo* pData;
};

#endif