#include "stdafx.h"
#include "../Node/Node.h"
#include <cassert>
#include <iostream>


int main()
{
  using namespace quadtree;
  auto root = Node::create(Vec(0.0f, 0.0f), Vec(1.0f, 1.0f));
  root->setNE(Vec(0.6f, 0.5f), Vec(0.4f, 0.5f));
  root->setSW(Vec(0.0f, 0.0f), Vec(0.2f, 0.3f));


  assert(!root->findLeaf(Vec(0.5f, 0.5f)));

  const Node* tmp = root->findLeaf(Vec(0.7f, 0.8f));
  assert(tmp->getPos().x == 0.6f && tmp->getPos().y == 0.5f);

  std::vector<const Node*> leaves = root->findLeaves();
  for (auto leaf : leaves) {
    Vec pos = leaf->getPos();
    Vec size = leaf->getSize();
    std::cout << pos.x << "," << pos.y << ":" << size.x << "," << size.y << std::endl;
  }
}

