#include "Turtle.h"
#include <cmath>
#include <gtest/gtest.h>

static double PRECISION = 1E-6;

class TurtleMovesOrthogonallyTestFixture : public ::testing::TestWithParam<double>
{
protected:
  TurtleMovesOrthogonallyTestFixture() : canvas(), turtle(canvas)
  {
  }
  CanvasData canvas;
  Turtle turtle;
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

TEST_P(TurtleMovesOrthogonallyTestFixture, turtleMovesOrthogonally)
{
  turtle.GetCanvas().SetCanvasSize(QSize(420, 69));
  turtle.GetCanvas().SetOriginalCanvasSize(QSize(420, 69));
  int forwardAmount = 5;

  const double heading = GetParam();
  turtle.SetHeading(heading);

  turtle.Forward(forwardAmount);
  EXPECT_NEAR(turtle.GetPosition().x(), forwardAmount * cos(heading), PRECISION);
  EXPECT_NEAR(turtle.GetPosition().y(), forwardAmount * sin(heading), PRECISION);
  turtle.Backward(forwardAmount);
  EXPECT_NEAR(turtle.GetPosition().x(), 0, PRECISION);
  EXPECT_NEAR(turtle.GetPosition().y(), 0, PRECISION);

  int heightOrWidth = 0;
  int negativeModifierX = 1;
  int negativeModifierY = 1;
  if (heading == 0 || heading == M_PI)
  {
    heightOrWidth = turtle.GetCanvas().GetCanvasSize().width();
    if (heading == M_PI)
    {
      negativeModifierX = -1;
    }
  }
  else if (heading == M_PI / 2 || heading == 3 * M_PI / 2)
  {
    heightOrWidth = turtle.GetCanvas().GetCanvasSize().height();
    if (heading == M_PI)
    {
      negativeModifierY = -1;
    }
  }
  else
  {
    FAIL() << "Heading is not orthogonal angle. Exiting test case.";
  }
  turtle.Forward(heightOrWidth + forwardAmount);
  EXPECT_NEAR(turtle.GetPosition().x(), forwardAmount * cos(heading), PRECISION);
  EXPECT_NEAR(turtle.GetPosition().y(), forwardAmount * sin(heading), PRECISION);
  turtle.Backward(heightOrWidth + forwardAmount);
  EXPECT_NEAR(turtle.GetPosition().x(), 0., PRECISION);
  EXPECT_NEAR(turtle.GetPosition().y(), 0., PRECISION);
}

TEST(TurtleTest, turtleMovesDiagonally)
{
  CanvasData canvas;
  Turtle turtle(canvas);
  turtle.GetCanvas().SetCanvasSize(QSize(420, 69));
  int forwardDistance = 5;

  turtle.RotateDeg(-45);
  EXPECT_NEAR(turtle.GetHeading(), M_PI / 4, PRECISION);

  turtle.Forward(forwardDistance);
  EXPECT_NEAR(turtle.GetPosition().x(), sqrt(2) / 2 * forwardDistance, PRECISION);
  EXPECT_NEAR(turtle.GetPosition().y(), sqrt(2) / 2 * forwardDistance, PRECISION);
}

TEST(TurtleTest, turtleRotatesRad)
{
  CanvasData canvas;
  Turtle turtle(canvas);
  turtle.GetCanvas().SetCanvasSize(QSize(420, 69));

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
  CanvasData canvas;
  Turtle turtle(canvas);
  turtle.GetCanvas().SetCanvasSize(QSize(420, 69));

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
  CanvasData canvas;
  Turtle turtle(canvas);
  turtle.GetCanvas().SetCanvasSize(QSize(100, 100));
  EXPECT_EQ(turtle.GetPosition(), QPointF(0, 0));

  // Goes to valid position if its on canvas
  QPointF newPosition(10, 10);
  turtle.SetPosition(newPosition);
  EXPECT_EQ(turtle.GetPosition(), newPosition);

  // Does not change position if position outside of canvaturtle.GetCanvas().GetCanvasSize().
  turtle.SetPosition(QPointF(turtle.GetCanvas().GetCanvasSize().width() * 2, 0));
  EXPECT_EQ(turtle.GetPosition(), newPosition);
  turtle.SetPosition(QPointF(0, turtle.GetCanvas().GetCanvasSize().height() * 2));
  EXPECT_EQ(turtle.GetPosition(), newPosition);
}

TEST(TurtleTest, testGetSetHeading)
{
  CanvasData canvas;
  Turtle turtle(canvas);
  turtle.GetCanvas().SetCanvasSize(QSize(420, 69));

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
  CanvasData canvas;
  Turtle turtle(canvas);
  turtle.GetCanvas().SetCanvasSize(QSize(420, 69));

  // pen down by default
  EXPECT_EQ(turtle.IsPenDown(), true);

  turtle.PenDown(false);
  EXPECT_EQ(turtle.IsPenDown(), false);

  turtle.PenDown(true);
  EXPECT_EQ(turtle.IsPenDown(), true);
}

TEST(TurtleTest, testVisibility)
{
  CanvasData canvas;
  Turtle turtle(canvas);
  turtle.GetCanvas().SetCanvasSize(QSize(420, 69));

  // visible by default
  EXPECT_EQ(turtle.IsVisible(), true);

  turtle.SetVisible(false);
  EXPECT_EQ(turtle.IsVisible(), false);

  turtle.SetVisible(true);
  EXPECT_EQ(turtle.IsVisible(), true);
}

INSTANTIATE_TEST_SUITE_P(TurtleOrthogonalModule, TurtleMovesOrthogonallyTestFixture, testing::Values(0, M_PI / 2, M_PI, 3 * M_PI / 2));
