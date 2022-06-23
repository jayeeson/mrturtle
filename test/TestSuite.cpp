#include <gtest/gtest.h>
#include "Turtle.h"
#include "iostream"

TEST(TurtleTest, turtleMovesForward)
{
  Size<int> s(420, 69);
  Turtle turtle(s);
  int forwardAmount = 5;
  turtle.Forward(forwardAmount);
  auto position = turtle.GetPosition();
  EXPECT_EQ(position.x, s.width() / 2);
  EXPECT_EQ(position.y, s.height() / 2 + forwardAmount);
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}