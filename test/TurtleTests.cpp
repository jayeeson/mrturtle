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
  EXPECT_NEAR(turtle.GetPosition().x, 0., PRECISION);
  EXPECT_NEAR(turtle.GetPosition().y, forwardAmount, PRECISION);
  turtle.Backward(forwardAmount);
  EXPECT_NEAR(turtle.GetPosition().x, 0, PRECISION);
  EXPECT_NEAR(turtle.GetPosition().y, 0, PRECISION);

  turtle.Forward(s.height() + forwardAmount);
  EXPECT_NEAR(turtle.GetPosition().y, forwardAmount, PRECISION);
  turtle.Backward(2 * s.height() + forwardAmount);
  EXPECT_NEAR(turtle.GetPosition().y, 0., PRECISION);

  turtle.RotateDeg(-90);
  EXPECT_NEAR(turtle.GetHeading(), 0, PRECISION);

  turtle.Forward(forwardAmount);
  EXPECT_NEAR(turtle.GetPosition().x, forwardAmount, PRECISION);
  EXPECT_NEAR(turtle.GetPosition().y, 0., PRECISION);
  turtle.Backward(forwardAmount);
  EXPECT_NEAR(turtle.GetPosition().x, 0., PRECISION);
  EXPECT_NEAR(turtle.GetPosition().y, 0., PRECISION);

  turtle.Forward(s.width() + forwardAmount);
  EXPECT_NEAR(turtle.GetPosition().x, forwardAmount, PRECISION);
  turtle.Backward(s.width() + forwardAmount);
  EXPECT_NEAR(turtle.GetPosition().x, 0., PRECISION);
  EXPECT_NEAR(turtle.GetPosition().y, 0., PRECISION);
}

TEST(TurtleTest, turtleMovesDiagonally)
{
  Size<int> s(100, 100);
  Turtle turtle(s);
  int forwardDistance = 5;

  turtle.RotateDeg(-45);
  EXPECT_NEAR(turtle.GetHeading(), M_PI / 4, PRECISION);

  turtle.Forward(forwardDistance);
  EXPECT_NEAR(turtle.GetPosition().x, sqrt(2) / 2 * forwardDistance, PRECISION);
  EXPECT_NEAR(turtle.GetPosition().y, sqrt(2) / 2 * forwardDistance, PRECISION);
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

  turtle.RotateRad(-4 * M_PI);
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

TEST(TurtleTest, testGetSetPosition)
{
  Size<int> s(100, 100);
  Turtle turtle(s);
  EXPECT_EQ(turtle.GetPosition(), Point(0, 0));

  // Goes to valid position if its on canvas
  Point newPosition = Point(10, 10);
  turtle.SetPosition(newPosition);
  EXPECT_EQ(turtle.GetPosition(), newPosition);

  // Does not change position if position outside of canvas.
  turtle.SetPosition(Point(s.width() * 2, 0));
  EXPECT_EQ(turtle.GetPosition(), newPosition);
  turtle.SetPosition(Point(0, s.height() * 2));
  EXPECT_EQ(turtle.GetPosition(), newPosition);
}

TEST(TurtleTest, testGetSetHeading)
{
  Size<int> s(100, 100);
  Turtle turtle(s);

  // default pointed upward
  EXPECT_EQ(turtle.GetHeading(), M_PI / 2);

  double heading = M_PI;
  turtle.SetHeading(heading);
  EXPECT_EQ(turtle.GetHeading(), heading);

  turtle.SetHeading(heading + 2 * M_PI);
  EXPECT_EQ(turtle.GetHeading(), heading);

  turtle.SetHeading(heading - 4 * M_PI);
  EXPECT_EQ(turtle.GetHeading(), heading);
}

TEST(TurtleTest, testPenDown)
{
  Size<int> s(100, 100);
  Turtle turtle(s);

  // pen down by default
  EXPECT_EQ(turtle.IsPenDown(), true);

  turtle.PenDown(false);
  EXPECT_EQ(turtle.IsPenDown(), false);

  turtle.PenDown(true);
  EXPECT_EQ(turtle.IsPenDown(), true);
}

TEST(TurtleTest, testVisibility)
{
  Size<int> s(100, 100);
  Turtle turtle(s);

  // visible by default
  EXPECT_EQ(turtle.IsVisible(), true);

  turtle.SetVisible(false);
  EXPECT_EQ(turtle.IsVisible(), false);

  turtle.SetVisible(true);
  EXPECT_EQ(turtle.IsVisible(), true);
}