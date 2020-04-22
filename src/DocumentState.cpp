#include "include/DocumentState.h"

DocumentState::DocumentState(){}

void DocumentState::setSavedFlag(bool flag)
{
    this->savedFlag = flag;
}

bool DocumentState::getSavedFlag()
{
    return savedFlag;
}

void DocumentState::setSavedFilename(QString fileName)
{
    this->savedFilename = fileName;
}

QString DocumentState::getSavedFilename()
{
    return savedFilename;
}

DocumentState::~DocumentState(){}

