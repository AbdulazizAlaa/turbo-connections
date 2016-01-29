#ifndef NODE_H
#define NODE_H

#include <QString>

class Node
{
public:
    Node(QString name, float x, float y, float radius);

    QString name;
    float x, y, radius;
};

#endif // NODE_H
