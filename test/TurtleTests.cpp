#include <gtest/gtest.h>

#include <cmath>

#include "Turtle.h"

static double PRECISION = 1E-6;

class TurtleMovesOrthogonallyTestFixture : public ::testing::TestWithParam<std::pair<double, bool>>
{
   protected:
    TurtleMovesOrthogonallyTestFixture() : canvas(), turtle(canvas) {}
    CanvasData canvas;
    Turtle turtle;
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

TEST_P(TurtleMovesOrthogonallyTestFixture, turtleMovesOrthogonally)
{
    auto param = GetParam();
    const double heading = param.first;
    const double doublePlusOneCanvasSize = param.second;

    turtle.GetCanvas().SetOriginalCanvasSize(QSize(420, 69));
    if (doublePlusOneCanvasSize)
    {
        turtle.GetCanvas().SetCanvasSize(QSize(420 * 2 + 1, 69 * 2 + 1));
    }
    else
    {
        turtle.GetCanvas().SetCanvasSize(QSize(420, 69));
    }

    int forwardAmount = 5;
    turtle.SetHeading(heading);

    turtle.Forward(forwardAmount);
    EXPECT_NEAR(turtle.GetPosition().x(), forwardAmount * cos(heading), PRECISION);
    EXPECT_NEAR(turtle.GetPosition().y(), forwardAmount * sin(heading), PRECISION);
    turtle.Backward(forwardAmount);
    EXPECT_NEAR(turtle.GetPosition().x(), 0, PRECISION);
    EXPECT_NEAR(turtle.GetPosition().y(), 0, PRECISION);

    int heightOrWidth = 0;
    if (heading == 0 || heading == M_PI)
    {
        heightOrWidth = turtle.GetCanvas().GetCanvasSize().width();
    }
    else if (heading == M_PI / 2 || heading == 3 * M_PI / 2)
    {
        heightOrWidth = turtle.GetCanvas().GetCanvasSize().height();
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

INSTANTIATE_TEST_SUITE_P(TurtleOrthogonalModule, TurtleMovesOrthogonallyTestFixture,
                         testing::Values(std::make_pair(0, false), std::make_pair(M_PI / 2, false),
                                         std::make_pair(M_PI, false),
                                         std::make_pair(3 * M_PI / 2, false),
                                         std::make_pair(0, true), std::make_pair(M_PI / 2, true),
                                         std::make_pair(M_PI, true),
                                         std::make_pair(3 * M_PI / 2, true)));
