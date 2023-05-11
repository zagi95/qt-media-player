#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class QMediaPlayer;
class QVideoWidget;
class QAudioOutput;
class QGraphicsVideoItem;
class QGraphicsScene;
class QGraphicsView;
class QBoxLayout;
class QMouseEvent;
class VideoWidget;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void play();
    void mouseMoved();
    void fullscreenClicked();

public slots:
    void playClicked();
    void pause();
    void stop();
    void open();
    void setFullscreen();

private:
    Ui::MainWindow *ui;
    QMediaPlayer* player;
    VideoWidget* video;
    QAudioOutput* audio;
};
#endif // MAINWINDOW_H
