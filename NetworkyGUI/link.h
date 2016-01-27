#ifndef LINK_H
#define LINK_H

#include "node.h"

class Link
{
public:
    Link(Node * src, Node * dst);

    Node *srcNode, *dstNode;
};

#endif // LINK_H
