#include "CanvasData.h"
#include "Turtle.h"
#include <QPair>
#include <QLine>
#include <QList>
#include <QVariant>
#include <cmath>
#include <gtest/gtest.h>

static double PRECISION = 1E-6;

TEST(CanvasDrawingTests, canvasDrawsTurtlePaths)
{
    CanvasData canvas;
    Turtle turtle(canvas);
    canvas.SetCanvasSize(QSize(420, 69));
    canvas.SetOriginalCanvasSize(QSize(420, 69));

    auto position = QPointF(0, 0);
    auto heading = 0.;
    QList<QLineF> lines;
    lines = canvas.GetTurtlePath(position, heading, 100);
    ASSERT_EQ(lines.length(), 1);
    EXPECT_NEAR(lines.at(0).x1(), position.x() + canvas.GetCanvasSize().width() / 2., PRECISION);
    EXPECT_NEAR(lines.at(0).y1(), canvas.GetCanvasSize().height() / 2., PRECISION);
    EXPECT_NEAR(lines.at(0).x2(), 100 + canvas.GetCanvasSize().width() / 2., PRECISION);
    EXPECT_NEAR(lines.at(0).y2(), canvas.GetCanvasSize().height() / 2., PRECISION);

    lines = canvas.GetTurtlePath(position, heading, 420);
    ASSERT_EQ(lines.length(), 2);
    EXPECT_NEAR(lines.at(0).x1(), canvas.GetCanvasSize().width() / 2., PRECISION);
    EXPECT_NEAR(lines.at(0).y1(), canvas.GetCanvasSize().height() / 2., PRECISION);
    EXPECT_NEAR(lines.at(0).x2(), canvas.GetCanvasSize().width(), PRECISION);
    EXPECT_NEAR(lines.at(0).y2(), canvas.GetCanvasSize().height() / 2., PRECISION);
    EXPECT_NEAR(lines.at(1).x1(), 0, PRECISION);
    EXPECT_NEAR(lines.at(1).y1(), canvas.GetCanvasSize().height() / 2., PRECISION);
    EXPECT_NEAR(lines.at(1).x2(), canvas.GetCanvasSize().width() / 2., PRECISION);
    EXPECT_NEAR(lines.at(1).y2(), canvas.GetCanvasSize().height() / 2., PRECISION);

    heading = M_PI / 2.;
    lines = canvas.GetTurtlePath(position, heading, 69);
    ASSERT_EQ(lines.length(), 2);
    EXPECT_NEAR(lines.at(0).x1(), canvas.GetCanvasSize().width() / 2., PRECISION);
    EXPECT_NEAR(lines.at(0).y1(), canvas.GetCanvasSize().height() / 2., PRECISION);
    EXPECT_NEAR(lines.at(0).x2(), canvas.GetCanvasSize().width() / 2., PRECISION);
    EXPECT_NEAR(lines.at(0).y2(), 0, PRECISION);
    EXPECT_NEAR(lines.at(1).x1(), canvas.GetCanvasSize().width() / 2., PRECISION);
    EXPECT_NEAR(lines.at(1).y1(), canvas.GetCanvasSize().height(), PRECISION);
    EXPECT_NEAR(lines.at(1).x2(), canvas.GetCanvasSize().width() / 2., PRECISION);
    EXPECT_NEAR(lines.at(1).y2(), canvas.GetCanvasSize().height() / 2., PRECISION);

    heading = M_PI;
    lines = canvas.GetTurtlePath(position, heading, 420);
    ASSERT_EQ(lines.length(), 2);
    EXPECT_NEAR(lines.at(0).x1(), canvas.GetCanvasSize().width() / 2., PRECISION);
    EXPECT_NEAR(lines.at(0).y1(), canvas.GetCanvasSize().height() / 2., PRECISION);
    EXPECT_NEAR(lines.at(0).x2(), 0, PRECISION);
    EXPECT_NEAR(lines.at(0).y2(), canvas.GetCanvasSize().height() / 2., PRECISION);
    EXPECT_NEAR(lines.at(1).x1(), canvas.GetCanvasSize().width(), PRECISION);
    EXPECT_NEAR(lines.at(1).y1(), canvas.GetCanvasSize().height() / 2., PRECISION);
    EXPECT_NEAR(lines.at(1).x2(), canvas.GetCanvasSize().width() / 2., PRECISION);
    EXPECT_NEAR(lines.at(1).y2(), canvas.GetCanvasSize().height() / 2., PRECISION);

    heading = 3 * M_PI / 2.;
    lines = canvas.GetTurtlePath(position, heading, 69);
    ASSERT_EQ(lines.length(), 2);
    EXPECT_NEAR(lines.at(0).x1(), canvas.GetCanvasSize().width() / 2., PRECISION);
    EXPECT_NEAR(lines.at(0).y1(), canvas.GetCanvasSize().height() / 2., PRECISION);
    EXPECT_NEAR(lines.at(0).x2(), canvas.GetCanvasSize().width() / 2., PRECISION);
    EXPECT_NEAR(lines.at(0).y2(), canvas.GetCanvasSize().height(), PRECISION);
    EXPECT_NEAR(lines.at(1).x1(), canvas.GetCanvasSize().width() / 2., PRECISION);
    EXPECT_NEAR(lines.at(1).y1(), 0, PRECISION);
    EXPECT_NEAR(lines.at(1).x2(), canvas.GetCanvasSize().width() / 2., PRECISION);
    EXPECT_NEAR(lines.at(1).y2(), canvas.GetCanvasSize().height() / 2., PRECISION);

    heading = M_PI / 4;
    lines = canvas.GetTurtlePath(position, heading, 69 / sin(heading));
    ASSERT_EQ(lines.length(), 2);
    EXPECT_NEAR(lines.at(0).x1(), canvas.GetCanvasSize().width() / 2., PRECISION);
    EXPECT_NEAR(lines.at(0).y1(), canvas.GetCanvasSize().height() / 2., PRECISION);
    EXPECT_NEAR(lines.at(0).x2(), canvas.GetCanvasSize().width() / 2. + 69 / 2., PRECISION);
    EXPECT_NEAR(lines.at(0).y2(), 0, PRECISION);
    EXPECT_NEAR(lines.at(1).x1(), canvas.GetCanvasSize().width() / 2. + 69 / 2., PRECISION);
    EXPECT_NEAR(lines.at(1).y1(), canvas.GetCanvasSize().height(), PRECISION);
    EXPECT_NEAR(lines.at(1).x2(), canvas.GetCanvasSize().width() / 2. + 69, PRECISION);
    EXPECT_NEAR(lines.at(1).y2(), canvas.GetCanvasSize().height() / 2., PRECISION);
}

TEST(CanvasPainterTest, testPenDown)
{
    CanvasData canvas;

    // pen down by default
    EXPECT_EQ(canvas.IsPenDown(), true);

    canvas.SetPenDown(false);
    EXPECT_EQ(canvas.IsPenDown(), false);

    canvas.SetPenDown(true);
    EXPECT_EQ(canvas.IsPenDown(), true);
}