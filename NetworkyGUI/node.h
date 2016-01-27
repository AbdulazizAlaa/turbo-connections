#ifndef NODE_H
#define NODE_H

#include <QString>

class Node
{
public:
    Node(QString name, float x, float y);

    QString name;
    float x, y;
};

#endif // NODE_H
