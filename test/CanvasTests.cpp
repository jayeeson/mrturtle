#include <gtest/gtest.h>

#include <QPair>
#include <QVariant>
#include <cmath>

#include "CanvasData.h"
#include "Turtle.h"

static double PRECISION = 1E-6;

class CanvasDrawsTurtlePathsFixture : public ::testing::TestWithParam<QPair<QPointF, QPointF>>
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
}

INSTANTIATE_TEST_SUITE_P(CanvasDrawsTurtlePathsModule, CanvasDrawsTurtlePathsFixture,
                         testing::Values(QPair(QPointF(0, 0), QPointF(100, 0))));
