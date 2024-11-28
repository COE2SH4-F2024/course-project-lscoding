#include "objPosArrayList.h"

// Paste your Tested implementation here.
// Paste your Tested implementation here.
// Paste your Tested implementation here.

objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP];
    arrayCapacity = ARRAY_MAX_CAP;
    listSize = 0;
}


objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(listSize == arrayCapacity)
    {
        cout << "Array is Full!" << endl;
        return;
    }
    
    for(int i = listSize; i > 0; i--)
    {
        aList[i] = aList[i-1];
    }

    aList[0] = thisPos;
    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(listSize == arrayCapacity)
    {
        cout << "Array is Full!" << endl;
        return;
    }

    aList[listSize] = thisPos;
    listSize++;
}

void objPosArrayList::removeHead()
{
    if(listSize == 0)
    {
        cout << "List is Empty, No Removal Allowed!" << endl;
        return;
    }

    for(int i = 0; i < listSize-1; i++)
    {

        aList[i] = aList[i+1];
    }
    listSize--;
}

void objPosArrayList::removeTail()
{
    if(listSize == 0)
    {
        cout << "List is Empty, No Removal Allowed!" << endl;
        return;
    }
    listSize--;
}

int objPosArrayList::getSize() const
{
   return listSize;
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    
    return aList[listSize-1];
}

objPos objPosArrayList::getElement(int index) const
{
    if(index < 0 || index >= listSize)
    {
        cout << "You have supplied an invalid index." << endl;
        return;
    }
    return aList[index];
}
