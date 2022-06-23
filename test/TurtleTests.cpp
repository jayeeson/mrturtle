#include "Turtle.h"
#include <cmath>
#include <gtest/gtest.h>

static double PRECISION = 1E-8;

TEST(TurtleTest, turtleMovesOrthogonally)
{
  Size<int> s(420, 69);
  Turtle turtle(s);
  int forwardAmount = 5;

  turtle.Forward(forwardAmount);
  EXPECT_NEAR(turtle.GetPosition().x, s.width() / 2., PRECISION);
  EXPECT_NEAR(turtle.GetPosition().y, s.height() / 2. + forwardAmount, PRECISION);
  turtle.Backward(forwardAmount);
  EXPECT_NEAR(turtle.GetPosition().x, s.width() / 2., PRECISION);
  EXPECT_NEAR(turtle.GetPosition().y, s.height() / 2., PRECISION);

  turtle.Forward(s.height() + forwardAmount);
  EXPECT_NEAR(turtle.GetPosition().y, s.height() / 2. + forwardAmount, PRECISION);
  turtle.Backward(2 * s.height() + forwardAmount);
  EXPECT_NEAR(turtle.GetPosition().y, s.height() / 2., PRECISION);

  turtle.RotateDeg(-90);
  EXPECT_NEAR(turtle.GetHeading(), 0, PRECISION);

  turtle.Forward(forwardAmount);
  EXPECT_NEAR(turtle.GetPosition().x, s.width() / 2. + forwardAmount, PRECISION);
  EXPECT_NEAR(turtle.GetPosition().y, s.height() / 2., PRECISION);
  turtle.Backward(forwardAmount);
  EXPECT_NEAR(turtle.GetPosition().x, s.width() / 2., PRECISION);
  EXPECT_NEAR(turtle.GetPosition().y, s.height() / 2., PRECISION);

  turtle.Forward(s.width() + forwardAmount);
  EXPECT_NEAR(turtle.GetPosition().x, s.width() / 2. + forwardAmount, PRECISION);
  turtle.Backward(s.width() + forwardAmount);
  EXPECT_NEAR(turtle.GetPosition().x, s.width() / 2., PRECISION);
  EXPECT_NEAR(turtle.GetPosition().y, s.height() / 2., PRECISION);
}

TEST(TurtleTest, turtleMovesDiagonally)
{
  Size<int> s(100, 100);
  Turtle turtle(s);
  int forwardDistance = 5;

  turtle.RotateDeg(-45);
  EXPECT_NEAR(turtle.GetHeading(), M_PI / 4, PRECISION);

  turtle.Forward(forwardDistance);
  EXPECT_NEAR(turtle.GetPosition().x, s.width() / 2 + sqrt(2) / 2 * forwardDistance, PRECISION);
  EXPECT_NEAR(turtle.GetPosition().y, s.height() / 2 + sqrt(2) / 2 * forwardDistance, PRECISION);
}

TEST(TurtleTest, turtleRotatesRad)
{
  Size<int> s(420, 69);
  Turtle turtle(s);

  turtle.RotateRad(M_PI / 2);
  EXPECT_NEAR(turtle.GetHeading(), M_PI, PRECISION);

  turtle.RotateRad(2 * M_PI);
  EXPECT_NEAR(turtle.GetHeading(), M_PI, PRECISION);

  turtle.RotateRad(-M_PI / 2);
  EXPECT_NEAR(turtle.GetHeading(), M_PI / 2, PRECISION);

  turtle.RotateRad(-2 * M_PI);
  EXPECT_NEAR(turtle.GetHeading(), M_PI / 2, PRECISION);
}

TEST(TurtleTest, turtleRotatesDeg)
{
  Size<int> s(420, 69);
  Turtle turtle(s);

  turtle.RotateDeg(90);
  EXPECT_NEAR(turtle.GetHeading(), M_PI, PRECISION);

  turtle.RotateDeg(360);
  EXPECT_NEAR(turtle.GetHeading(), M_PI, PRECISION);

  turtle.RotateDeg(-90);
  EXPECT_NEAR(turtle.GetHeading(), M_PI / 2, PRECISION);

  turtle.RotateDeg(-360);
  EXPECT_NEAR(turtle.GetHeading(), M_PI / 2, PRECISION);
}