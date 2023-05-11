#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QAudioOutput>
#include <QGraphicsVideoItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QBoxLayout>
#include <QScreen>
#include <QMediaMetaData>
#include <QPushButton>
#include <QAction>
#include <QFileDialog>
#include <QMouseEvent>
#include "videowidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(ui->actionplay, &QAction::triggered, this, &MainWindow::playClicked);
    connect(ui->actionpause, &QAction::triggered, this, &MainWindow::pause);
    connect(ui->actionstop, &QAction::triggered, this, &MainWindow::stop);
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::open);

    player = new QMediaPlayer(this);
    audio = new QAudioOutput(this);
    player->setAudioOutput(audio);
    video = new VideoWidget(this);

    //connect(ui->actionfullscreen, &QAction::triggered, &video, &VideoWidget::fullscreenClicked);
    connect(video, &VideoWidget::mouseClickPausePlay, player, &QMediaPlayer::pause);

    player->setVideoOutput(video);
    this->setCentralWidget(video);

    player->setSource(QUrl::fromLocalFile("C:\\Users\\jzaga\\Downloads\\unberbl-vejt\\The.Unbearable.Weight.Of.Massive.Talent.mp4"));


    video->resize(1600, 900);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::playClicked()
{
    player->play();
    qDebug() << "play";
}

void MainWindow::pause()
{
    player->pause();
    qDebug() << "pause";
}

void MainWindow::stop()
{
    player->stop();
    qDebug() << "stop";
}

void MainWindow::open()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open file", nullptr, nullptr, nullptr);
    stop();
    player->setSource(filename);
    playClicked();
}

void MainWindow::setFullscreen()
{
    qDebug() << "fullscreen";
    emit fullscreenClicked();
}

