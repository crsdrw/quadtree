#pragma once

#include <memory>
#include <vector>
#include "Vec.h"

namespace quadtree {
  class Node;

  class Node {
   private:
    Vec pos;
    Vec sz;
    std::unique_ptr<Node> SE;
    std::unique_ptr<Node> SW;
    std::unique_ptr<Node> NW;
    std::unique_ptr<Node> NE;
    bool isLeaf() const { return !(NE || SW || SE || NW); }
    bool isColision(Vec p) const { return p.x > pos.x && p.y > pos.y && p.x < pos.x + sz.x && p.y < pos.y + sz.y; }
    void findLeaves(std::vector<const Node*>& leaves) const;

    Node(Vec pos, Vec sz) : pos(pos), sz(sz) {};
   public:

    void setNE(Vec pos, Vec sz) { NE.reset(new Node(pos, sz)); }
    void setSE(Vec pos, Vec sz) { SE.reset(new Node(pos, sz)); }
    void setSW(Vec pos, Vec sz) { SW.reset(new Node(pos, sz)); }
    void setNW(Vec pos, Vec sz) { NW.reset(new Node(pos, sz)); }

    const Node*                  findLeaf(Vec p) const;
    std::vector<const Node*>     findLeaves() const;
    Vec                          getPos() const { return pos; }
    Vec                          getSize() const { return sz; }
    static std::unique_ptr<Node> create(Vec pos, Vec sz) { return std::unique_ptr<Node>(new Node(pos, sz)); }
  };
}

