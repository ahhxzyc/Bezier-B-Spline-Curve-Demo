#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>

#include <paintedwidget.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    PaintedWidget *pw = new PaintedWidget(800, 600, 300);
    pw->show();


    return app.exec();
}
