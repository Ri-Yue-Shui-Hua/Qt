#include "MusicPlayer.h"
#include <QtWidgets/QApplication>
#include <QApplication>
#include"connection.h"
#include<QTime>
#include<QSplashScreen>
#include<QPixmap>
int main(int argc, char* argv[])
{

    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

    QApplication a(argc, argv);
    if (!CreatConnection())
    {
        return 1;
    }
    MusicPlayer w;
    w.setWindowIcon(QIcon(u8"ooopic_1520340986.ico"));
    w.setWindowTitle((u8"Œ“µƒ“Ù¿÷"));
    w.show();
    return a.exec();
}
