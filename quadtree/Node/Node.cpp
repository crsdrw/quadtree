#include "stdafx.h"
#include "Node.h"

namespace quadtree {
  const Node* Node::findLeaf(Vec p) const {
    if (!isColision(p))
      return nullptr;

    if (isLeaf())
      return this;

    const Node* leaf = nullptr;
    if (NE)
      leaf = NE->findLeaf(p);
    if (!leaf && SE)
      leaf = SE->findLeaf(p);
    if (!leaf && SW)
      leaf = SW->findLeaf(p);
    if (!leaf && NW)
      leaf = NW->findLeaf(p);

    return leaf;
  }

  void Node::findLeaves(std::vector<const Node*>& leaves) const {
    if (isLeaf()) {
      leaves.push_back(this);
      return;
    }

    if (NE)
      NE->findLeaves(leaves);
    if (SE)
      SE->findLeaves(leaves);
    if (SW)
      SW->findLeaves(leaves);
    if (NW)
      NW->findLeaves(leaves);
  }

  std::vector<const Node*>
  Node::findLeaves() const {
    std::vector<const Node*> leaves;
    findLeaves(leaves);
    return leaves;
  }

}
