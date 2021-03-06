//=============================================================================
//  MuseScore
//  Music Composition & Notation
//
//  Copyright (C) 2020 MuseScore BVBA and others
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License version 2.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//=============================================================================
#ifndef MU_NOTATIONSCENE_NOTATIONPAINTVIEW_H
#define MU_NOTATIONSCENE_NOTATIONPAINTVIEW_H

#include <QObject>
#include <QQuickPaintedItem>
#include <QTransform>

#include "modularity/ioc.h"
#include "interfaces/iinteractive.h"
#include "domain/notation/interfaces/inotationcreator.h"

namespace mu {
namespace scene {
namespace notation {
class NotationViewInputController;
class NotationPaintView : public QQuickPaintedItem
{
    Q_OBJECT

    INJECT(notation, framework::IInteractive, interactive)
    INJECT(notation, domain::notation::INotationCreator, notationCreator)

public:
    NotationPaintView();

    Q_INVOKABLE void cmd(const QString& name);

    void open();

    // Draw
    void paint(QPainter* painter) override;

    // Input
    void wheelEvent(QWheelEvent*) override;
    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;

private:

    friend class NotationViewInputController;

    QPoint toLogical(const QPoint& p) const;
    QPoint toPhysical(const QPoint& p) const;

    void moveScene(int dx, int dy);
    void scrollVertical(int dy);
    void scrollHorizontal(int dx);
    void zoomStep(qreal step, const QPoint& pos);
    void zoom(qreal mag, const QPoint& pos);

    // ---

    std::shared_ptr<domain::notation::INotation> m_notation;
    QTransform m_matrix;
    NotationViewInputController* m_inputController = nullptr;
};
}
}
}

#endif // MU_NOTATIONSCENE_NOTATIONPAINTVIEW_H
