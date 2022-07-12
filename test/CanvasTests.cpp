#include "CanvasData.h"
#include "Turtle.h"
#include <QPair>
#include <QVariant>
#include <cmath>
#include <gtest/gtest.h>

static double PRECISION = 1E-6;

class CanvasDrawsTurtlePathsFixture
    : public ::testing::TestWithParam<QPair<QPointF, QPair<double, double>>>
{
   protected:
    CanvasDrawsTurtlePathsFixture() : canvas(), turtle(canvas) {}
    CanvasData canvas;
    Turtle turtle;
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

TEST_P(CanvasDrawsTurtlePathsFixture, canvasDrawsTurtlePaths)
{
    turtle.GetCanvas().SetCanvasSize(QSize(420, 69));
    turtle.GetCanvas().SetOriginalCanvasSize(QSize(420, 69));

    const auto param = GetParam();
    const auto pos = param.first;
    const auto distance = param.second.first;
    const auto heading = param.second.second;

    QList<QLine> lines;
    lines = canvas.DrawTurtlePath(pos, heading, distance);
}

// Param holds Pair<position, Pair<distance, heading>>
INSTANTIATE_TEST_SUITE_P(CanvasDrawsTurtlePathsModule, CanvasDrawsTurtlePathsFixture,
                         testing::Values(QPair(QPointF(0, 0), QPair(100, 0))));
