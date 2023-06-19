#include <gtest/gtest.h>
#include "node.h"

TEST(node, equality)
{
    // arrange
    miit::Node first_node(5);
    miit::Node second_node(5);

    // act 
    bool act = (first_node == second_node);

    // assert
    ASSERT_EQ(true, act);
}