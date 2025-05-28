#ifndef ITRANSFER_H
#define ITRANSFER_H

class ITransfer
{
public:
    virtual ~ITransfer() = default;
    virtual void TransferData() = 0;
};

#endif // ITRANSFER_H
