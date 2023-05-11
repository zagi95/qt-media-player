#include "videowidget.h"

VideoWidget::VideoWidget(QWidget* parent)
    : QVideoWidget(parent)
{

}

void VideoWidget::mouseMoveEvent(QMouseEvent* event)
{
    setMouseTracking(true);
    qDebug() << "moved";
    if((event->type() == QEvent::MouseMove) && isFullScreen())
    {
        qDebug() << "moved";
    }
}

void VideoWidget::mouseDoubleClickEvent(QMouseEvent* event)
{
    setFullScreen(!isFullScreen());
}

void VideoWidget::mousePressEvent(QMouseEvent* event)
{
    //if()
    emit mouseClickPausePlay();
}
