#include "launcher.h"
#include "./ui_launcher.h"

#include <QTimer>
#include <QObject>
#include <QProcess>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QStringList>

QTimer *splash_timer = new QTimer();

launcher::launcher(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::launcher)
{
    ui->setupUi(this);

    this->setWindowTitle("App Launcher");

    QGraphicsScene* scene = new QGraphicsScene();
    QImage image("./utilities/splashimage.png");
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->addItem(item);
    ui->graphicsView->setScene(scene);
}

launcher::~launcher()
{
    delete ui;
}

void launcher::applauncher(void){

    this->show();
    QObject::connect(splash_timer, &QTimer::timeout, this, &launcher::launch );
    splash_timer->start(4000);
}

void launcher::launch(void){
    splash_timer->stop();
    QStringList script;
    script <<  "app.py";
    QProcess *process = new QProcess();
    process->startDetached("./python-3.9.10-embed-amd64/python.exe", script);
    process->close();
    this->close();

}
