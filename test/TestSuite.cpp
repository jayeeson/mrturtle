#include <gtest/gtest.h>
#include "Turtle.h"
#include <cmath>

template <class T, class U>
static bool AreEqual(T num1, U num2, double delta = 1E-8)
{
  if (num1 < num2)
  {
    return num2 - num1 < delta;
  }
  if (num1 > num2)
  {
    return num1 - num2 < delta;
  }
  return true;
}

TEST(TurtleTest, turtleMovesOrthogonally)
{
  Size<int> s(420, 69);
  Turtle turtle(s);
  int forwardAmount = 5;

  turtle.Forward(forwardAmount);
  EXPECT_TRUE(AreEqual(turtle.GetPosition().x, s.width() / 2.));
  EXPECT_TRUE(AreEqual(turtle.GetPosition().y, s.height() / 2. + forwardAmount));
  turtle.Backward(forwardAmount);
  EXPECT_TRUE(AreEqual(turtle.GetPosition().x, s.width() / 2.));
  EXPECT_TRUE(AreEqual(turtle.GetPosition().y, s.height() / 2.));

  turtle.Forward(s.height() + forwardAmount);
  EXPECT_TRUE(AreEqual(turtle.GetPosition().y, s.height() / 2. + forwardAmount));
  turtle.Backward(2 * s.height() + forwardAmount);
  EXPECT_TRUE(AreEqual(turtle.GetPosition().y, s.height() / 2.));

  turtle.RotateDeg(-90);
  EXPECT_TRUE(AreEqual(turtle.GetHeading(), 0));

  turtle.Forward(forwardAmount);
  EXPECT_TRUE(AreEqual(turtle.GetPosition().x, s.width() / 2. + forwardAmount));
  EXPECT_TRUE(AreEqual(turtle.GetPosition().y, s.height() / 2.));
  turtle.Backward(forwardAmount);
  EXPECT_TRUE(AreEqual(turtle.GetPosition().x, s.width() / 2.));
  EXPECT_TRUE(AreEqual(turtle.GetPosition().y, s.height() / 2.));

  turtle.Forward(s.width() + forwardAmount);
  EXPECT_TRUE(AreEqual(turtle.GetPosition().x, s.width() / 2. + forwardAmount));
  turtle.Backward(s.width() + forwardAmount);
  EXPECT_TRUE(AreEqual(turtle.GetPosition().x, s.width() / 2.));
  EXPECT_TRUE(AreEqual(turtle.GetPosition().y, s.height() / 2.));
}

TEST(TurtleTest, turtleMovesDiagonally)
{
  Size<int> s(100, 100);
  Turtle turtle(s);

  turtle.RotateDeg(-45);
}

TEST(TurtleTest, turtleRotatesRad)
{
  Size<int> s(420, 69);
  Turtle turtle(s);

  turtle.RotateRad(M_PI / 2);
  EXPECT_TRUE(AreEqual(turtle.GetHeading(), M_PI));

  turtle.RotateRad(2 * M_PI);
  EXPECT_TRUE(AreEqual(turtle.GetHeading(), M_PI));

  turtle.RotateRad(-M_PI / 2);
  EXPECT_TRUE(AreEqual(turtle.GetHeading(), M_PI / 2));

  turtle.RotateRad(-2 * M_PI);
  EXPECT_TRUE(AreEqual(turtle.GetHeading(), M_PI / 2));
}

TEST(TurtleTest, turtleRotatesDeg)
{
  Size<int> s(420, 69);
  Turtle turtle(s);

  turtle.RotateDeg(90);
  EXPECT_TRUE(AreEqual(turtle.GetHeading(), M_PI));

  turtle.RotateDeg(360);
  EXPECT_TRUE(AreEqual(turtle.GetHeading(), M_PI));

  turtle.RotateDeg(-90);
  EXPECT_TRUE(AreEqual(turtle.GetHeading(), M_PI / 2));

  turtle.RotateDeg(-360);
  EXPECT_TRUE(AreEqual(turtle.GetHeading(), M_PI / 2));
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}