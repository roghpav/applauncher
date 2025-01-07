#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class launcher;
}
QT_END_NAMESPACE

class launcher : public QMainWindow
{
    Q_OBJECT

public:
    launcher(QWidget *parent = nullptr);
    ~launcher();

public:
    void applauncher(void);

private slots:
    void launch(void);

private:
    Ui::launcher *ui;
};
#endif // LAUNCHER_H
