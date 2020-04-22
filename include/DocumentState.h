#ifndef DOCUMETSTATE_H
#define DOCUMETSTATE_H


#include <QString>


class DocumentState
{
public:
    DocumentState();

    void setSavedFlag(bool flag);

    bool getSavedFlag();

    void setSavedFilename(QString filename);

    QString getSavedFilename();

    ~DocumentState();
private:

    bool savedFlag = false;

    QString savedFilename = QString();
};

#endif // DOCUMETSTATE_H
