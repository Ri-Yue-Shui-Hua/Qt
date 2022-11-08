#include "dialog.h"
#include "ui_dialog.h"
#include<QtGUI/QPixmap>
#include<QtGUI/QPalette>
#include<QtGUI/QIcon>
#include<QtWidgets/QMenu>
#include<QtWidgets/QAction>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QtWidgets/QShortcut>
#include<QtWidgets/QGraphicsDropShadowEffect>
#include<QtWidgets/QFileDialog>
Dialog::Dialog(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->frame->setAutoFillBackground(true);
    setAutoFillBackground(true);
    setAttribute(Qt::WA_TranslucentBackground);

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect;
    effect->setOffset(5, 5);
    effect->setColor(QColor(0, 0, 0, 60));
    effect->setBlurRadius(10);
    ui->frame->setGraphicsEffect(effect);

    QSqlQuery query;
    query.exec("select * from Bizi_DATA");//��ֽ����
    query.next();
    QString FileName = query.value(0).toString();
    QString FileName1;
    if (FileName.isEmpty())
    {
        FileName1 = ":/MusicPlayer/image/background/bg4.jpg";
    }
    else
    {

        FileName1 = FileName;
    }
    ui->frame->setStyleSheet(QString("QFrame#frame{border-radius:3px;border-image: url(%1);}").arg(FileName1));
    query.exec("select * from Toumin_DATA");//͸��������
    query.next();
    QString Temp = query.value(0).toString();
    if (Temp == "")
    {
        TouMin = 1.0;
    }
    else
    {
        TouMin = Temp.toDouble();
    }
    ui->frame->setWindowOpacity(TouMin);//����͸����
    ui->pushButton_2->setIconSize(QSize(24, 24));
    ui->pushButton_2->setIcon(QIcon(":/MusicPlayer/image/image/pase.png"));
    ui->pushButton->setToolTip(("��һ��"));
    ui->pushButton_2->setToolTip(("��ͣ"));
    ui->pushButton_3->setToolTip(("��һ��"));
    ui->pushButton_4->setToolTip(("�ر�"));
    ui->pushButton_5->setToolTip(("��С��"));
    ui->horizontalSlider->setToolTip(("���Ž���"));
    music = new QMediaPlayer(this);
    playlist = new QMediaPlaylist(this);
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    play = new QAction(this);//����
    pause = new QAction(this);//��ͣ
    next = new QAction(this);//��һ��
    pre = new QAction(this);//��һ��
    back = new QAction(this);//����
    play->setIcon(QIcon(":/MusicPlayer/image/zt13.png"));
    play->setText(("����"));
    pause->setIcon(QIcon(":/MusicPlayer/image/bofang1.png"));
    pause->setText(("��ͣ"));
    next->setIcon(QIcon(":/MusicPlayer/image/next1.png"));
    next->setText(("��һ��"));
    pre->setIcon(QIcon(":/MusicPlayer/image/pre1.png"));
    pre->setText(("��һ��"));
    back->setIcon(QIcon(":/MusicPlayer/image/�˳� (3).png"));
    back->setText(("����������"));


    action = new QAction(this);//����Ƥ��
    action1 = new QAction(this);//Ĭ��Ƥ��1
    action2 = new QAction(this);//Ĭ��Ƥ��2
    action3 = new QAction(this);//Ĭ��Ƥ��3
    action4 = new QAction(this);//�Զ���Ƥ��
    action->setIcon(QIcon(":/MusicPlayer/image/pf.png"));
    action->setText(("����Ƥ��"));

    action1->setIcon(QIcon(":/MusicPlayer/image/pf2.png"));
    action1->setText(("��ɫ"));
    action2->setIcon(QIcon(":/MusicPlayer/image/pf5.png"));
    action2->setText(("����"));
    action3->setIcon(QIcon(":/MusicPlayer/image/pf3.png"));
    action3->setText(("���"));
    action4->setIcon(QIcon(":/MusicPlayer/image/pf4.png"));
    action4->setText(("�Զ���"));

    QMenu* Menu = new QMenu(this);//Ƥ���˵�
    Menu->addAction(action1);
    Menu->addAction(action2);
    Menu->addAction(action3);
    Menu->addAction(action4);
    Menu->setStyleSheet(
        " QMenu {\
                background-color: white; /* sets background of the menu ���������˵�����ı���ɫ�����õ��ǰ�ɫ��white*/\
                border: 3px solid white;/*�����˵�����ı߿��ϸ����ʽ����ɫ*/\
            }\
            QMenu::item {\
                /* sets background of menu item. set this to something non-transparent\
                    if you want menu color and menu item color to be different */\
                background-color: transparent;\
                padding:5px 30px;/*���ò˵����������º����ҵ��ڱ߾࣬Ч�����ǲ˵��е���Ŀ�����������˼��*/\
                margin:0px 0px;/*���ò˵������߾�*/\
                border-bottom:0px solid #DBDBDB;/*Ϊ�˵���֮����Ӻ��߼��*/\
            }\
            QMenu::item:selected { /* when user selects item using mouse or keyboard */\
                background-color: rgba(122,122,122,100);/*��һ�������ò˵�����꾭��ѡ�е���ʽ*/\
            }"

    );
    action->setMenu(Menu);
    Action = new QAction(this);//����͸����
    Action1 = new QAction(this);//͸���ȼ�
    Action2 = new QAction(this);//͸���ȼ�
    Action->setIcon(QIcon(":/MusicPlayer/image/ooopic_1500874104.png"));
    Action->setText(("����͸����"));
    Action1->setIcon(QIcon(":/MusicPlayer/image/add.png"));
    Action1->setText(("+5%"));

    Action2->setIcon(QIcon(":/MusicPlayer/image/sub.png"));

    Action2->setText(("-5%"));


    QMenu* Menu1 = new QMenu(this);//͸���Ȳ˵�
    Menu1->addAction(Action1);
    Menu1->addAction(Action2);
    Menu1->setStyleSheet(
        " QMenu {\
            background-color: white; /* sets background of the menu ���������˵�����ı���ɫ�����õ��ǰ�ɫ��white*/\
            border: 3px solid white;/*�����˵�����ı߿��ϸ����ʽ����ɫ*/\
        }\
        QMenu::item {\
            /* sets background of menu item. set this to something non-transparent\
                if you want menu color and menu item color to be different */\
            background-color: transparent;\
            padding:5px 30px;/*���ò˵����������º����ҵ��ڱ߾࣬Ч�����ǲ˵��е���Ŀ�����������˼��*/\
            margin:0px 0px;/*���ò˵������߾�*/\
            border-bottom:0px solid #DBDBDB;/*Ϊ�˵���֮����Ӻ��߼��*/\
        }\
        QMenu::item:selected { /* when user selects item using mouse or keyboard */\
            background-color: rgba(122,122,122,100);/*��һ�������ò˵�����꾭��ѡ�е���ʽ*/\
        }"

    );
    Action->setMenu(Menu1);
    quit = new QAction(this);
    quit->setIcon(QIcon(":/MusicPlayer/image/tc.png"));
    quit->setText(("�˳�"));
    connect(music, &QMediaPlayer::metaDataAvailableChanged, this, &Dialog::updateText);
    connect(music, &QMediaPlayer::positionChanged, this, &Dialog::updatePosition);
    connect(music, &QMediaPlayer::durationChanged, this, &Dialog::updateDuration);
    connect(music, &QMediaPlayer::stateChanged, this, &Dialog::stateChange);
    connect(ui->horizontalSlider, &QSlider::sliderMoved, music, &QMediaPlayer::setPosition);
    connect(play, &QAction::triggered, this, &Dialog::play_slot);
    connect(pause, &QAction::triggered, this, &Dialog::pause_slot);
    connect(next, &QAction::triggered, this, &Dialog::next_slot);
    connect(pre, &QAction::triggered, this, &Dialog::pre_slot);
    connect(action1, &QAction::triggered, this, &Dialog::action1_slot);
    connect(action2, &QAction::triggered, this, &Dialog::action2_slot);
    connect(action3, &QAction::triggered, this, &Dialog::action3_slot);
    connect(action4, &QAction::triggered, this, &Dialog::action4_slot);
    connect(Action1, &QAction::triggered, this, &Dialog::Action1_slot);
    connect(Action2, &QAction::triggered, this, &Dialog::Action2_slot);
    connect(quit, &QAction::triggered, this, &Dialog::quit_slot);
    connect(playlist, &QMediaPlaylist::playbackModeChanged, this, &Dialog::PlaybackModel_slot);
    connect(back, &QAction::triggered, this, &Dialog::back_slot);
    ui->pushButton_7->setIconSize(QSize(20, 20));
    ui->pushButton_7->setIcon(QIcon(":/MusicPlayer/image/image/loop.png"));
    ui->pushButton_7->setToolTip(("˳�򲥷�"));

    ui->pushButton_8->setIconSize(QSize(20, 20));
    ui->pushButton_8->setIcon(QIcon(":/MusicPlayer/image/Music_32px_1144946_easyicon.net.png"));
    ui->pushButton_8->setToolTip(("���������б�"));

    //�������˵�
    QMenu* ToolMenu = new QMenu(this);

 /*   if (QtWin::isCompositionEnabled())
    {

        QtWin::enableBlurBehindWindow(ToolMenu);

    }
    else
    {

        QtWin::disableBlurBehindWindow(ToolMenu);
        ToolMenu->hide();
    }*/

    toolbar = new QWinThumbnailToolBar(this);
    toolbar->setWindow(windowHandle());
    next1 = new QWinThumbnailToolButton(this);
    pre1 = new QWinThumbnailToolButton(this);
    pause1 = new QWinThumbnailToolButton(this);
    next1->setToolTip(("��һ��"));
    next1->setIcon(QIcon(":/MusicPlayer/image/next1.png"));
    connect(next1, &QWinThumbnailToolButton::clicked, this, &Dialog::on_pushButton_3_clicked);
    pre1->setToolTip(("��һ��"));
    pre1->setIcon(QIcon(":/MusicPlayer/image/pre1.png"));
    connect(pre1, &QWinThumbnailToolButton::clicked, this, &Dialog::on_pushButton_clicked);
    pause1->setToolTip(("��ͣ"));
    pause1->setIcon(QIcon(":/MusicPlayer/image/bf13.png"));
    connect(pause1, &QWinThumbnailToolButton::clicked, this, &Dialog::on_pushButton_2_clicked);
    toolbar->addButton(pre1);
    toolbar->addButton(pause1);
    toolbar->addButton(next1);
    Taskbotton = new QWinTaskbarButton(this);
    TaskProgress = new QWinTaskbarProgress(this);

    Taskbotton->setWindow(windowHandle());
    TaskProgress = Taskbotton->progress();
    connect(ui->horizontalSlider, &QSlider::valueChanged, TaskProgress, &QWinTaskbarProgress::setValue);
    connect(ui->horizontalSlider, &QSlider::rangeChanged, TaskProgress, &QWinTaskbarProgress::setRange);

    currentFile = "D:/";
}
void Dialog::UpdateIndex(int value)
{

    if (Index.indexOf(value) == -1)
    {
        Index.push_back(value);
    }

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_4_clicked()//�˳�
{
    QCoreApplication::quit();
}
/*
void Dialog::on_pushButton_6_clicked()//����������
{

    emit Data(playlist->currentIndex(),music->position(),playlist,music->state(),playlist->playbackMode());
    music->pause();
    accept();

}
*/
void Dialog::on_pushButton_5_clicked()//��С��
{
    showMinimized();
}
void Dialog::mousePressEvent(QMouseEvent* event)//�϶�����
{

    offset = event->globalPos() - pos();
    event->accept();
    if (event->button() == Qt::LeftButton)
    {
        setCursor(Qt::OpenHandCursor);
    }

}
void Dialog::mouseMoveEvent(QMouseEvent* event)//�϶�����
{

    move(event->globalPos() - offset);
    event->accept();
    setCursor(Qt::ClosedHandCursor);
}
void Dialog::mouseReleaseEvent(QMouseEvent* event)//�϶�����
{

    offset = QPoint();
    event->accept();
    setCursor(Qt::ArrowCursor);
}
void Dialog::mouseDoubleClickEvent(QMouseEvent*)//˫������������
{

    setCursor(Qt::ArrowCursor);
    emit Data(playlist->currentIndex(), music->position(), playlist, music->state(), playlist->playbackMode(), Index);
    music->pause();
    accept();

}
void Dialog::setPlaylist(QMediaPlaylist* list, int row, int position, int volume, QMediaPlayer::State state, QMediaPlaylist::PlaybackMode playmodel, int i)//��������
{
    playlist = list;
    music->setPlaylist(playlist);
    playlist->setCurrentIndex(row);
    music->setPosition(position);
    music->setVolume(volume);

    if (state == QMediaPlayer::PlayingState)
        music->play();
    playlist->setPlaybackMode(playmodel);
    PlaybackModel_slot(playmodel);
    if (i == 0)
    {

        ui->pushButton_8->setIcon(QIcon(":/MusicPlayer/image/Music_32px_1144946_easyicon.net.png"));
        ui->pushButton_8->setToolTip(("���ظ����б�"));
        flag = true;
    }
    else if (i == 1)
    {


        ui->pushButton_8->setIcon(QIcon(":/MusicPlayer/image/like_32px_1101682_easyicon.net.png"));
        ui->pushButton_8->setToolTip(("��ϲ���б�"));
    }
    else if (i == 2)
    {
        ui->pushButton_8->setIcon(QIcon(":/MusicPlayer/image/list_32px_1074296_easyicon.net.png"));
        ui->pushButton_8->setToolTip(("�ҵ��ղ��б�"));
    }
    else if (i == 3)
    {
        ui->pushButton_8->setIcon(QIcon(":/MusicPlayer/image/list_32px_1074296_easyicon.net.png"));
        ui->pushButton_8->setToolTip(("���ż�¼�б�"));
    }

}
void Dialog::updateText()//�����ı�
{

    QString Text;
    if (music->isMetaDataAvailable())
    {


        QString Title = music->metaData(QStringLiteral("Title")).toString();
        if (!Title.isEmpty())
        {

            Text = Title;
        }
        else
        {

            Text += ("δ֪����");
        }
        Text += "-";
        QString Author = music->metaData(QStringLiteral("Author")).toString();
        if (!Author.isEmpty())
        {
            Text += Author;

        }
        else
        {

            Text += ("δ֪����");

        }

    }
    ui->label->setText(Text);

}
static QString Time(qint64 time)//ת��ʱ��
{

    int sec = time / 1000;
    int min = sec / 60;
    sec -= min * 60;
    return QStringLiteral("%1:%2")
        .arg(min, 2, 10, QLatin1Char('0'))
        .arg(sec, 2, 10, QLatin1Char('0'));
}
void Dialog::updatePosition(qint64 position)//����λ��
{
    ui->horizontalSlider->setValue(position);
    ui->label_2->setText(Time(position) + "/" + Time(music->duration()));

}
void Dialog::updateDuration(qint64 duration)//����״̬
{

    ui->horizontalSlider->setRange(0, duration);
    ui->horizontalSlider->setEnabled(duration > 0);
    ui->horizontalSlider->setPageStep(duration / 10);

}

void Dialog::on_pushButton_2_clicked()//����/��ͣ
{
    if (playlist->isEmpty())return;
    if (music->state() == QMediaPlayer::PlayingState)
    {

        music->pause();
        ui->pushButton_2->setIcon(QIcon(":/MusicPlayer/image/image/pase.png"));
        ui->pushButton_2->setToolTip(("��ͣ"));
        pause1->setToolTip(("��ͣ"));
        pause1->setIcon(QIcon(":/MusicPlayer/image/bf13.png"));
    }
    else
    {
        music->play();
        ui->pushButton_2->setIcon(QIcon(":/MusicPlayer/image/image/play.png"));
        ui->pushButton_2->setToolTip(("����"));
        pause1->setToolTip(("����"));
        pause1->setIcon(QIcon(":/MusicPlayer/image/zt13.png"));
    }
}
void Dialog::stateChange(QMediaPlayer::State state)//״̬�ı�
{

    if (state == QMediaPlayer::PlayingState)
    {
        ui->pushButton_2->setIcon(QIcon(":/MusicPlayer/image/image/play.png"));
        ui->pushButton_2->setToolTip(("����"));
        pause1->setToolTip(("����"));
        pause1->setIcon(QIcon(":/MusicPlayer/image/zt13.png"));
        TaskProgress->show();
        TaskProgress->resume();

    }
    else
    {

        ui->pushButton_2->setIcon(QIcon(":/MusicPlayer/image/image/pase.png"));
        ui->pushButton_2->setToolTip(("��ͣ"));
        pause1->setToolTip(("��ͣ"));
        pause1->setIcon(QIcon(":/MusicPlayer/image/bf13.png"));
        TaskProgress->show();
        TaskProgress->pause();

    }
}

void Dialog::on_pushButton_3_clicked()//��һ��
{
    if (playlist->isEmpty())return;
    int currentIndex;
    if (playlist->playbackMode() == QMediaPlaylist::Random)
    {
        int row = playlist->mediaCount();
        currentIndex = qrand() % row;


    }
    else
    {
        currentIndex = playlist->currentIndex();
        if (++currentIndex == playlist->mediaCount())
        {
            currentIndex = 0;

        }

    }
    if (flag && Index.indexOf(currentIndex) == -1)
    {
        Index.push_back(currentIndex);
    }
    playlist->setCurrentIndex(currentIndex);
}

void Dialog::on_pushButton_clicked()//��һ��
{
    if (playlist->isEmpty())return;
    int currentIndex;
    if (playlist->playbackMode() == QMediaPlaylist::Random)
    {

        int row = playlist->mediaCount();
        currentIndex = qrand() % row;
    }
    else
    {
        currentIndex = playlist->currentIndex();
        if (--currentIndex < 0)
        {

            currentIndex = 0;


        }

    }
    if (flag && Index.indexOf(currentIndex) == -1)
    {
        Index.push_back(currentIndex);
    }
    playlist->setCurrentIndex(currentIndex);
}

void Dialog::contextMenuEvent(QContextMenuEvent*)//�Ҽ��˵���
{


    menu = new QMenu(this);
    menu->setStyleSheet(
        " QMenu {\
             background-color: white; /* sets background of the menu ���������˵�����ı���ɫ�����õ��ǰ�ɫ��white*/\
             border: 3px solid white;/*�����˵�����ı߿��ϸ����ʽ����ɫ*/\
         }\
         QMenu::item {\
             /* sets background of menu item. set this to something non-transparent\
                 if you want menu color and menu item color to be different */\
             background-color: transparent;\
             padding:5px 30px;/*���ò˵����������º����ҵ��ڱ߾࣬Ч�����ǲ˵��е���Ŀ�����������˼��*/\
             margin:0px 0px;/*���ò˵������߾�*/\
             border-bottom:0px solid #DBDBDB;/*Ϊ�˵���֮����Ӻ��߼��*/\
         }\
         QMenu::item:selected { /* when user selects item using mouse or keyboard */\
             background-color: rgba(122,122,122,100);/*��һ�������ò˵�����꾭��ѡ�е���ʽ*/\
         }"

    );
    if (music->state() == QMediaPlayer::PlayingState)
    {
        menu->addAction(pause);
    }
    else
    {
        menu->addAction(play);
    }

    menu->addAction(next);
    menu->addAction(pre);
    menu->addAction(back);
    menu->addAction(action);
    menu->addAction(Action);
    menu->addAction(quit);
    menu->exec(QCursor::pos());



}
void Dialog::play_slot()//����
{

    music->play();

}
void Dialog::pause_slot()//��ͣ
{

    music->pause();
}

void Dialog::next_slot()//��һ��
{
    if (playlist->isEmpty())return;
    int currentIndex;
    if (playlist->playbackMode() == QMediaPlaylist::Random)
    {

        int row = playlist->mediaCount();
        currentIndex = qrand() % row;
    }
    else
    {
        currentIndex = playlist->currentIndex();
        if (++currentIndex == playlist->mediaCount())
        {
            currentIndex = 0;

        }

    }
    if (flag && Index.indexOf(currentIndex) == -1)
    {
        Index.push_back(currentIndex);
    }
    playlist->setCurrentIndex(currentIndex);

}
void Dialog::pre_slot()//��һ��

{
    if (playlist->isEmpty())return;
    int currentIndex;
    if (playlist->playbackMode() == QMediaPlaylist::Random)
    {

        int row = playlist->mediaCount();
        currentIndex = qrand() % row;
    }
    else
    {
        currentIndex = playlist->currentIndex();
        if (--currentIndex < 0)
        {

            currentIndex = 0;


        }

    }
    playlist->setCurrentIndex(currentIndex);
    if (flag && Index.indexOf(currentIndex) == -1)
    {
        Index.push_back(currentIndex);
    }

}
void Dialog::action1_slot()//Ĭ��Ƥ��1
{

    QString FileName = ":/MusicPlayer/image/background/bg4.jpg";
    QSqlQuery query;
    query.exec("select * from Bizi_DATA");
    query.exec("delete from Bizi_DATA");
    query.exec(QString("insert into Bizi_DATA values ('%1')").arg(FileName));
    ui->frame->setStyleSheet(QString("QFrame#frame{border-radius:3px;border-image: url(%1);}").arg(FileName));


}
void Dialog::action2_slot()//Ĭ��Ƥ��2
{

    QString FileName = ":/MusicPlayer/image/background/bg5.jpg";
    QSqlQuery query;
    query.exec("select * from Bizi_DATA");
    query.exec("delete from Bizi_DATA");
    query.exec(QString("insert into Bizi_DATA values ('%1')").arg(FileName));

    ui->frame->setStyleSheet(QString("QFrame#frame{border-radius:3px;border-image: url(%1);}").arg(FileName));

}
void Dialog::action3_slot()//Ĭ��Ƥ��3
{

    QString FileName = ":/MusicPlayer/image/background/bg6.jpg";
    QSqlQuery query;
    query.exec("select * from Bizi_DATA");
    query.exec("delete from Bizi_DATA");
    query.exec(QString("insert into Bizi_DATA values ('%1')").arg(FileName));
    ui->frame->setStyleSheet(QString("QFrame#frame{border-radius:3px;border-image: url(%1);}").arg(FileName));
}
void Dialog::action4_slot()//�Զ���Ƥ��
{

    QString FileName = QFileDialog::getOpenFileName(this, ("�ļ�"), currentFile, ("ͼƬ�ļ�(*jpg *png)"));
    if (!FileName.isEmpty())
    {
        QString file = FileName;
        QString file1 = FileName.split("//").last();
        currentFile = file.remove(file1);
        QSqlQuery query;
        query.exec("select * from Bizi_DATA");
        query.exec("delete from Bizi_DATA");
        query.exec(QString("insert into Bizi_DATA values ('%1')").arg(FileName));
        ui->frame->setStyleSheet(QString("QFrame#frame{border-radius:3px;border-image: url(%1);}").arg(FileName));
    }
}
void Dialog::Action1_slot()//͸���ȼ�
{

    QSqlQuery query;
    query.exec("select * from Toumin_DATA");
    query.exec("delete from Toumin_DATA");
    if (TouMin < 1.0)
    {
        TouMin += 0.05;

        query.exec(QString("insert into Toumin_DATA values (%1)").arg(TouMin));

    }
    ui->frame->setWindowOpacity(TouMin);

}
void Dialog::Action2_slot()//͸���ȼ�
{
    QSqlQuery query;
    query.exec("select * from Toumin_DATA");
    query.exec("delete from Toumin_DATA");
    if (TouMin > 0.4)
    {
        TouMin -= 0.05;

        query.exec(QString("insert into Toumin_DATA values (%1)").arg(TouMin));

    }
    ui->frame->setWindowOpacity(TouMin);

}
void Dialog::quit_slot()//�˳�
{
    QCoreApplication::quit();
}

void Dialog::on_pushButton_7_clicked()//����ģʽ
{


    if (playlist->playbackMode() == QMediaPlaylist::Loop)
    {

        ui->pushButton_7->setIcon(QIcon(":/MusicPlayer/image/image/play-random.png"));
        ui->pushButton_7->setToolTip(("�������"));
        playlist->setPlaybackMode(QMediaPlaylist::Random);

    }
    else if (playlist->playbackMode() == QMediaPlaylist::Random)
    {
        ui->pushButton_7->setIcon(QIcon(":/MusicPlayer/image/image/loop-one.png"));
        ui->pushButton_7->setToolTip(("����ѭ��"));
        playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);


    }
    else if (playlist->playbackMode() == QMediaPlaylist::CurrentItemInLoop)
    {
        ui->pushButton_7->setIcon(QIcon(":/MusicPlayer/image/image/loop.png"));
        ui->pushButton_7->setToolTip(("˳�򲥷�"));
        playlist->setPlaybackMode(QMediaPlaylist::Loop);

    }
}
void Dialog::PlaybackModel_slot(QMediaPlaylist::PlaybackMode model)//����ģʽ�ı�
{

    if (model == QMediaPlaylist::Loop)
    {
        ui->pushButton_7->setIcon(QIcon(":/MusicPlayer/image/image/loop.png"));
        ui->pushButton_7->setToolTip(("˳�򲥷�"));

    }
    else if (model == QMediaPlaylist::Random)
    {
        ui->pushButton_7->setIcon(QIcon(":/MusicPlayer/image/image/play-random.png"));
        ui->pushButton_7->setToolTip(("�������"));

    }
    else if (model == QMediaPlaylist::CurrentItemInLoop)
    {
        ui->pushButton_7->setIcon(QIcon(":/MusicPlayer/image/image/loop-one.png"));
        ui->pushButton_7->setToolTip(("����ѭ��"));


    }
}
void Dialog::back_slot() {

    setCursor(Qt::ArrowCursor);
    emit Data(playlist->currentIndex(), music->position(), playlist, music->state(), playlist->playbackMode(), Index);
    music->pause();
    accept();

}
