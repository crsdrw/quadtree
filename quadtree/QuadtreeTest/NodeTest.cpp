#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Node\Node.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using quadtree::Node;
using quadtree::Vec;

namespace {
  std::unique_ptr<Node> createTestTree() {
    auto root = Node::create(Vec(0.0f, 0.0f), Vec(1.0f, 1.0f));
    root->setNE(Vec(0.6f, 0.5f), Vec(0.4f, 0.5f));
    root->setSW(Vec(0.0f, 0.0f), Vec(0.2f, 0.3f));
    return root;
  }
}

namespace QuadtreeTest
{
	TEST_CLASS(NodeTest)
	{
	public:
		
		TEST_METHOD(CreateNode)
		{
      auto node = Node::create(Vec(0.0f, 0.0f), Vec(1.0f, 1.0f));
		}

    TEST_METHOD(CreateNodeWithLeaves)
    {
      auto root = createTestTree();

      root->findLeaf(Vec(0.5f, 0.5f));
      Assert::IsNotNull(root->findLeaf(Vec(0.5f, 0.5f)));

      const Node* tmp = root->findLeaf(Vec(0.7f, 0.8f));
      Assert::IsNotNull(tmp);
      Assert::AreEqual(0.6f, tmp->getPos().x);
      Assert::AreEqual(0.5f, tmp->getPos().y);
    }

    TEST_METHOD(FindLeaves)
    {
      auto root = createTestTree();
      
      std::vector<const Node*> leaves = root->findLeaves();
      Assert::AreEqual((size_t)2, leaves.size());
    }
	};
}