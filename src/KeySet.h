#ifndef KEYSET_H
#define KEYSET_H

#include "KeyAction.h"

class KeySet
{
private:

    KeyAction keyAction;

public:
    KeySet(/* args */);
    ~KeySet();
    void getAction();
    void setAction();
};

#endif