#include "CanvasData.h"
#include <QDebug>

CanvasData::CanvasData()
    : _canvasSize(),
      _origCanvasSize(),
      _maxCanvasSize(),
      _penDown(true),
      _penColor("black"),
      _penSize(1)
{
}

void CanvasData::SetCanvasSize(const QSize &size)
{
    _canvasSize = size;

    UpdateMaxCanvasSizeIfNeeded();
    emit CanvasSizeChanged();
}

void CanvasData::SetOriginalCanvasSize(const QSize &size)
{
    _origCanvasSize = size;
    emit OriginalCanvasSizeChanged();
}

void CanvasData::SetMaxCanvasSize(const QSize &size)
{
    _maxCanvasSize = size;
    emit OriginalCanvasSizeChanged();
}

void CanvasData::DoAddLineToCommandHistoryPanel(QString line, QString color)
{
    emit addLineToCommandHistoryPanel(line, color);
}

void CanvasData::DoDrawPaths(const QList<QLineF> &pathList)
{
    QList<double> startX;
    QList<double> startY;
    QList<double> endX;
    QList<double> endY;
    QList<double> distance;

    for (auto line = pathList.begin(); line != pathList.end(); ++line)
    {
        startX.append(line->x1());
        startY.append(line->y1());
        endX.append(line->x2());
        endY.append(line->y2());
        distance.append(line->length());
    }
    emit drawPaths(startX, startY, endX, endY, distance);
}

void CanvasData::DoClearCanvas() { emit clearCanvas(); }

QList<QLineF> CanvasData::GetTurtlePath(const QPointF &pos, double heading, double distance)
{
    // 1. create up to 2 lines to check intersection
    // QLine::intersects(line, insersectionPoint)
    // 2. if no intersection, we are finished
    // else, intersection point is p2
    // and we translate line to new pos
    // and decrease its length by distance moved.
    // 3. repeat step 2 until finished.

    QList<QLineF> list{};
    const double qtCoordinateOffsetX = _canvasSize.width() / 2.;

    const double qtCoordinateOffsetY = _canvasSize.height() / 2.;

    QLineF edge1{};  // always most clockwise edge
    QLineF edge2{};  // always most counter-clockwise edge
    GetCanvasBordersThatCouldIntersect(heading, edge1, edge2);
    // todo: use fuzzy compare
    const bool edge2IsUnset =
        edge2.p1().x() == 0 && edge2.p1().y() == 0 && edge2.p2().x() == 0 && edge2.p2().y() == 0;
    const int numEdges = edge2IsUnset ? 1 : 2;

    // qt y+ is down.. hence negatives below
    QPointF start{pos.x() + qtCoordinateOffsetX, -pos.y() + qtCoordinateOffsetY};
    QPointF end{start.x() + distance * cos(heading), start.y() - distance * sin(heading)};
    QLineF line{start, end};

    QPointF intersectionPoint{};
    QLineF *intersected = nullptr;
    do
    {
        intersected = nullptr;
        if (QLineF::BoundedIntersection == line.intersect(edge1, &intersectionPoint))
        {
            intersected = &edge1;
        }
        else if (numEdges == 2 &&
                 QLineF::BoundedIntersection == line.intersect(edge2, &intersectionPoint))
        {
            intersected = &edge2;
        }
        else if (intersected == nullptr)
        {
            break;
        }

        QLineF newLine{line.p1(), intersectionPoint};
        list.append(newLine);
        if (intersected->p1() == br(_canvasSize))
        {
            line.translate(-line.p1().x(), intersectionPoint.y() - line.p1().y());
        }
        else if (intersected->p1() == tr(_canvasSize))
        {
            line.translate(intersectionPoint.x() - line.p1().x(),
                           _canvasSize.height() - line.p1().y());
        }
        else if (intersected->p1() == tl())
        {
            line.translate(_canvasSize.width() - line.p1().x(),
                           intersectionPoint.y() - line.p1().y());
        }
        else if (intersected->p1() == bl(_canvasSize))
        {
            line.translate(intersectionPoint.x() - line.p1().x(), -line.p1().y());
        }
        else
        {
            qDebug() << "Error in canvasData::GetTurtlePath\r\n"
                     << "line: " << line << "\r\nintersected: " << *intersected;
        }
        line.setLength(line.length() - newLine.length());

    } while (intersected != nullptr);

    // final non-intersecting line that ends in middle of canvas somewhere
    if (line.length() > 0)
    {
        list.append(line);
    }

    return list;
}

void CanvasData::UpdateMaxCanvasSizeIfNeeded()
{
    bool changed = false;
    if (_canvasSize.height() > _maxCanvasSize.height())
    {
        _maxCanvasSize.rheight() = _canvasSize.height();
        changed = true;
    }
    if (_canvasSize.width() > _maxCanvasSize.width())
    {
        _maxCanvasSize.rwidth() = _canvasSize.width();
        changed = true;
    }

    if (changed)
    {
        emit MaxCanvasSizeChanged();
    }
}

void CanvasData::GetCanvasBordersThatCouldIntersect(double heading, QLineF &edge1, QLineF &edge2)
{
    if (heading == 0)
    {
        edge1.setP1(br(_canvasSize));
        edge1.setP2(tr(_canvasSize));
    }
    else if (heading == M_PI / 2)
    {
        edge1.setP1(tr(_canvasSize));
        edge1.setP2(tl());
    }
    else if (heading == M_PI)
    {
        edge1.setP1(tl());
        edge1.setP2(bl(_canvasSize));
    }
    else if (heading == 3 * M_PI / 2)
    {
        edge1.setP1(bl(_canvasSize));
        edge1.setP2(br(_canvasSize));
    }
    else if (heading > 0 && heading < M_PI / 2)
    {
        edge1.setP1(br(_canvasSize));
        edge1.setP2(tr(_canvasSize));
        edge2.setP1(tr(_canvasSize));
        edge2.setP2(tl());
    }
    else if (heading > M_PI / 2 && heading < M_PI)
    {
        edge1.setP1(tr(_canvasSize));
        edge1.setP2(tl());
        edge2.setP1(tl());
        edge2.setP2(bl(_canvasSize));
    }
    else if (heading > M_PI && heading < 3 * M_PI / 2)
    {
        edge1.setP1(tl());
        edge1.setP2(bl(_canvasSize));
        edge2.setP1(bl(_canvasSize));
        edge2.setP2(br(_canvasSize));
    }
    else if (heading > 3 * M_PI / 2 && heading < 2 * M_PI)
    {
        edge1.setP1(bl(_canvasSize));
        edge1.setP2(br(_canvasSize));
        edge2.setP1(br(_canvasSize));
        edge2.setP2(tr(_canvasSize));
    }
}

QPointF CanvasData::tl() { return QPointF(0, 0); }

QPointF CanvasData::tr(const QSize &canvas) { return QPointF(canvas.width(), 0); }

QPointF CanvasData::bl(const QSize &canvas) { return QPointF(0, canvas.height()); }

QPointF CanvasData::br(const QSize &canvas) { return QPointF(canvas.width(), canvas.height()); }

void CanvasData::SetPenColor(const QString &color)
{
    if (QColor::isValidColor(color))
    {
        _penColor = QColor(color);
        emit PenColorChanged();
    }
}