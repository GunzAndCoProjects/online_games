#include "DataTransferMonofieldGames.h"

DataTransferMonofieldGames::DataTransferMonofieldGames(const FieldInfo &Data_)
{
    this->pData = new FieldInfo();
    *(this->pData) = Data_;
}

DataTransferMonofieldGames::DataTransferMonofieldGames()
{
    this->pData = new FieldInfo();
}

DataTransferMonofieldGames::DataTransferMonofieldGames(const DataTransferMonofieldGames &DataTransfer_)
{
    this->pData = new FieldInfo();
    *(this->pData) = *(DataTransfer_.pData);
}

DataTransferMonofieldGames::~DataTransferMonofieldGames()
{
    delete this->pData;
}

DataTransferMonofieldGames & DataTransferMonofieldGames::operator = (const DataTransferMonofieldGames &DataTransfer_)
{
    if((void*)this == (void*)&DataTransfer_)
    {
        return *this;
    }
    else
    {
        unsetPointer();
        this->pData = new FieldInfo();
        *(this->pData) = *(DataTransfer_.pData);
        return *this;
    }
}

void* DataTransferMonofieldGames::GetData() const
{
    return (void*)(pData);
}

void DataTransferMonofieldGames::SetData(void* Data_)
{
    if (Data_ != NULL)
    {
        unsetPointer();
        this->pData = new FieldInfo();
        *(this->pData) = *((FieldInfo*) Data_);
    }
}

void DataTransferMonofieldGames::unsetPointer()
{
    if(this->pData != NULL)
    {
        delete this->pData;
    }
}