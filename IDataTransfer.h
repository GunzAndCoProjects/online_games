#ifndef IDATATRANSFER_H
#define	IDATATRANSFER_H


class IDataTransfer
{
public:
    virtual void* GetData() const = 0;
    virtual void SetData(void*) = 0;
};

#endif