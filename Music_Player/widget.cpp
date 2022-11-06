//#include "widget.h"
//
//widget::widget(QWidget *parent)
//	: QWidget(parent)
//{
//	ui.setupUi(this);
//}
//
//widget::~widget()
//{}
#include "widget.h"
#include "ui_widget.h"
#include<QMediaPlayer>
#include<QMediaPlaylist>
#include<QFileDialog>
#include<QUrl>
#include<QDir>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QSqlTableModel>
#include<QMenu>
#include<dwmapi.h>
#include<windowsx.h>
#include<QPainter>
#include<QScrollBar>
#include<qmath.h>
#include<QShortcut>
#include<QMessageBox>
#include<QProgressBar>
#include<QProgressDialog>
#include"dialog.h"
#include<QGraphicsDropShadowEffect>
#include<QFile>
Widget::Widget(QWidget* parent) :
    QWidget(parent)
{
    //ui = new Ui::Widget;
    ui.setupUi(this);
    setAutoFillBackground(true);
    ui.lineEdit->setPlaceholderText(("������ֻ����"));
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect;
    effect->setOffset(1, 1);
    effect->setColor(QColor(0, 0, 0, 100));
    effect->setBlurRadius(15);
    ui.frame->setGraphicsEffect(effect);
    ui.frame->setAutoFillBackground(true);
    currentFileName.push_back("D:/");
    currentFileName.push_back("D:/");
    currentFileName.push_back("D:/");
    currentFileName.push_back("D:/");
    CreateSortCut();
    init_else();
    init_icon();
    init_list();
    init_tooltip();
    init_win();
    init_action();
    init_Connect();
    ListItemToolTip();

}
inline void Widget::init_else()
{
    labelText1.push_back("You may only be a person in this world,");
    labelText2.push_back("but for someone,you're the world.");
    labelText1.push_back("May there be enough clouds in your life");
    labelText2.push_back("        to make a beautiful sunset.");
    labelText1.push_back("The best feeling the world is when you");
    labelText2.push_back("        know your heart is smiling.");
    labelText1.push_back("Love begins with a smile,grows with a");
    labelText2.push_back("         kiss and ends with a tear.");
    labelText1.push_back("Life is not lack of beauty,but lack");
    labelText2.push_back("        of the eyes to find beauty.");
    labelText1.push_back("The shortest distance between");
    labelText2.push_back("             two people is a smile.");
    labelText1.push_back("Life is not about waiting for the storm to pass.");
    labelText2.push_back("It's about learning to dance in the rain.");
    labelText1.push_back("In order to be irrepaceable,one");
    labelText2.push_back("          must always be different.");
    labelText1.push_back("The minute you think of giving up,think of");
    labelText2.push_back("the reason why you held on so long.");
    labelText1.push_back("Life is a shipwreck,but we must not");
    labelText2.push_back("   forget to sing in the lifeboats.");
    labelText1.push_back("Give everything a shot.You never know what or");
    labelText2.push_back("who is going to change your life.");
    ui.listWidget->verticalScrollBar()->setCursor(Qt::PointingHandCursor);
    ui.listWidget_2->verticalScrollBar()->setCursor(Qt::PointingHandCursor);
    ui.listWidget_3->verticalScrollBar()->setCursor(Qt::PointingHandCursor);
    ui.listWidget_4->verticalScrollBar()->setCursor(Qt::PointingHandCursor);
    QString listWidgetStyle = "QScrollBar:vertical"
        "{"
        "width:8px;"
        "background-color:transparent;"
        "margin:0px,0px,0px,0px;"
        " padding-top:12px;   /*��Ԥ��λ��*/"
        " padding-bottom:12px;    /*��Ԥ��λ��*/"
        "}"


        "  QScrollBar::handle:vertical"
        " {"
        "width:8px;"
        " background-color:rgba(255,255,255,0.2);"
        " border-radius:4px;"
        " min-height:20px;"
        " }"


        "    QScrollBar::handle:vertical:hover"
        "   {"
        "      width:9px;"
        " background-color:rgba(255,255,255,0.5);"
        "   border-radius:4px;"
        "     min-height:20;"
        "  }"

        "  QScrollBar::add-line:vertical"
        "  {"
        " height:12px;"
        "     width:10px;"
        "        border-image:url(:/selectfile/scroll/3.png);"
        " subcontrol-position:bottom;"
        "    }"

        "    QScrollBar::sub-line:vertical"
        "    {"
        "        height:12px;"
        "width:10px;"
        "   border-image:url(:/selectfile/scroll/1.png);"
        "subcontrol-position:top;"
        "   }"
        "    QScrollBar::add-line:vertical:hover"
        "   {"
        " height:12px;"
        "width:10px;"
        " border-image:url(:/selectfile/scroll/4.png);"
        "subcontrol-position:bottom;"
        " }"


        " QScrollBar::sub-line:vertical:hover"
        " {"
        "     height:12px;"
        "  width:10px;"
        "  border-image:url(:/selectfile/scroll/2.png);"
        " subcontrol-position:top;"
        " }"

        " QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical"
        " {"
        " background-color:transparent;"
        "   border-radius:4px;"
        "}";
    ui.listWidget_2->verticalScrollBar()->setStyleSheet(listWidgetStyle);
    ui.listWidget_3->verticalScrollBar()->setStyleSheet(listWidgetStyle);
    ui.listWidget->verticalScrollBar()->setStyleSheet(listWidgetStyle);
    ui.listWidget_4->verticalScrollBar()->setStyleSheet(listWidgetStyle);
    ui.listWidget_5->verticalScrollBar()->setStyleSheet(listWidgetStyle);
    Music = new Dialog();//С������
    Music->setWindowFlags(Qt::FramelessWindowHint);//���ô�������
    QSqlQuery query;
    query.exec("select * from WALLPAPER_DATA");//�����ڱ�ֽ����
    query.next();
    QString FileName = query.value(0).toString();
    QString FileName1;
    if (FileName.isEmpty())
    {
        FileName1 = ":/image/image/background/bg8.jpg";
    }
    else
    {
        FileName1 = FileName;

    }
    query.exec("select * from TRA_DATA");//������͸��������
    query.next();
    QString Values = query.value(0).toString();
    if (Values.isEmpty())
    {
        transparency = 1;
    }
    else
    {
        transparency = Values.toDouble();
    }
    ui.frame->setWindowOpacity(transparency);//����͸����
    ui.frame->setStyleSheet(QString("QFrame#frame{border-radius:5px;border-image: url(%1);}").arg(FileName1));
    music = new QMediaPlayer(this);

    playlist = new QMediaPlaylist(this);//�������ֲ����б�
    playlist->setPlaybackMode(QMediaPlaylist::Loop);//�������
    playlist_2 = new QMediaPlaylist(this);//��ϲ�������б�
    playlist_2->setPlaybackMode(QMediaPlaylist::Loop);//�������
    playlist_3 = new QMediaPlaylist(this);//�ҵ��ղز����б�
    playlist_3->setPlaybackMode(QMediaPlaylist::Loop);//�������
    playlist_4 = new QMediaPlaylist(this);
    playlist_4->setPlaybackMode(QMediaPlaylist::Loop);

    ui.verticalSlider->hide();
    ui.verticalSlider->setValue(100);


    ui.horizontalSlider->setValue(0);
    ui.stackedWidget->setCurrentIndex(0);
    ui.pushButton_10->setStyleSheet("QPushButton"
        "{"
        "background-image: url(:/image/image/image-hover/music-hover.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"
        "border:none;"

        "}"

        "QPushButton:hover{"

        "background-image: url(:/image/image/image-hover/music-hover.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"


        "}"
        "QPushButton:pressed{"
        "background-image: url(:/image/image/image/music.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"

        "}"

    );




}

inline void Widget::init_win()
{


    QMenu* ToolMenu = new QMenu(this);//�������˵�
    if (QtWin::isCompositionEnabled())
    {

        QtWin::enableBlurBehindWindow(ToolMenu);

    }
    else
    {

        QtWin::disableBlurBehindWindow(ToolMenu);
        ToolMenu->hide();
    }
    toolbar = new QWinThumbnailToolBar(this);
    toolbar->setWindow(windowHandle());
    next = new QWinThumbnailToolButton(this);//��һ��
    pre = new QWinThumbnailToolButton(this);//��һ��
    pause = new QWinThumbnailToolButton(this);//������ͣ
    next->setToolTip(("��һ��"));
    next->setIcon(QIcon(":/image/image/next1.png"));
    connect(next, &QWinThumbnailToolButton::clicked, this, &Widget::action9_slot);//��һ��->action10_slot��
    pre->setToolTip(("��һ��"));
    pre->setIcon(QIcon(":/image/image/pre1.png"));
    connect(pre, &QWinThumbnailToolButton::clicked, this, &Widget::action10_slot);//��һ��->action9_slot��
    pause->setToolTip(("��ͣ"));
    pause->setIcon(QIcon(":/image/image/bf13.png"));
    connect(pause, &QWinThumbnailToolButton::clicked, this, &Widget::on_pushButton_2_clicked);//����/��ͣ->on_pushButton_2_clicked��
    toolbar->addButton(pre);//���������Ӱ�ť
    toolbar->addButton(pause);//���������Ӱ�ť
    toolbar->addButton(next);//���������Ӱ�ť
    Taskbotton = new QWinTaskbarButton(this);//������
    TaskProgress = new QWinTaskbarProgress(this);//������

    Taskbotton->setWindow(windowHandle());
    TaskProgress = Taskbotton->progress();//��ȡ�������Ľ�����
    connect(ui.horizontalSlider, &QSlider::valueChanged, TaskProgress, &QWinTaskbarProgress::setValue);//��������ֵ�ı�->������������������ֵ
    connect(ui.horizontalSlider, &QSlider::rangeChanged, TaskProgress, &QWinTaskbarProgress::setRange);//��������Χ�ı�->������������������Χ
}
inline void Widget::init_Connect() {


    connect(music, &QMediaPlayer::metaDataAvailableChanged, this, &Widget::updateInfo);//���ָ����ı�->������ʾ�ı�
    connect(music, &QMediaPlayer::positionChanged, this, &Widget::updatePosition);//���ŵ�λ�øı�->���½���������λ��
    connect(music, &QMediaPlayer::durationChanged, this, &Widget::updateDuration);//���Ÿ����ı�->���½�����
    connect(ui.horizontalSlider, &QSlider::sliderMoved, music, &QMediaPlayer::setPosition);//�������ƶ�->�������ֵĲ���λ��
    connect(playlist, &QMediaPlaylist::currentIndexChanged, this, &Widget::updatalistwidget_3);//�������ֲ����б�λ�øı�->����listWidget_3��λ��
    connect(playlist_2, &QMediaPlaylist::currentIndexChanged, this, &Widget::updatalistwidget_2);//��ϲ�������б�λ�øı�->����listWidget_2��λ��
    connect(playlist_3, &QMediaPlaylist::currentIndexChanged, this, &Widget::updatalistwidget);//�ҵ��ղز����б�λ�øı�->����listWidget��λ��
    connect(action1, &QAction::triggered, this, &Widget::action1_slot);//������������ֶ������->ִ��action1_slot��
    connect(action2, &QAction::triggered, this, &Widget::action2_slot);//�����ϲ���������->ִ��action2_slot��
    connect(action3, &QAction::triggered, this, &Widget::action3_slot);//����ҵ��ղض������->ִ��action3_slot��
    connect(action4_1, &QAction::triggered, this, &Widget::action4_1_slot);//͸���ȼӶ������->ִ��action4_1_slot��
    connect(action4_2, &QAction::triggered, this, &Widget::action4_2_slot);//͸���ȼ��������->ִ��action4_2_slot��
    connect(action5_1, &QAction::triggered, this, &Widget::action5_1_slot);//Ĭ��Ƥ��1�������->ִ��action5_1_slot��
    connect(action5_2, &QAction::triggered, this, &Widget::action5_2_slot);//Ĭ��Ƥ��2�������->ִ��action5_2_slot��
    connect(action5_3, &QAction::triggered, this, &Widget::action5_3_slot);//�Զ���Ƥ���������->ִ��action5_3_slot��
    connect(action5_4, &QAction::triggered, this, &Widget::action5_4_slot);//3
    connect(action6, &QAction::triggered, this, &Widget::action6_slot);//���ڶ������->ִ��action6_slot��
    connect(action7, &QAction::triggered, this, &Widget::action7_slot);//ʹ�ý��ܶ������->ִ��action7_slot��
    connect(action8, &QAction::triggered, this, &Widget::action8_slot);//�˳��������->ִ��action8_slot��
    connect(ClearALL_1, &QAction::triggered, this, &Widget::ClearALL_1_slot);//����������ֶ������->ִ��ClearALL_1_slot��
    connect(ClearALL_2, &QAction::triggered, this, &Widget::ClearALL_2_slot);//�����ϲ���������->ִ��ClearALL_2_slot��
    connect(ClearALL_3, &QAction::triggered, this, &Widget::ClearALL_3_slot);//����ҵ��ղض������->ִ��ClearALL_3_slot��
    connect(ClearALL_4, &QAction::triggered, this, &Widget::ClearALL_4_slot);//����������ֶ������->ִ��ClearALL_4_slot��
    connect(action13, &QAction::triggered, this, &Widget::action8_slot);//�˳��������->ִ��action8_slot��
    connect(action9, &QAction::triggered, this, &Widget::action9_slot);//������һ�׶������->ִ��action9_slot��
    connect(action10, &QAction::triggered, this, &Widget::action10_slot);//������һ�׶������->ִ��action10_slot��
    connect(action11, &QAction::triggered, this, &Widget::action11_slot);//��ͣ�������->ִ��action11_slot��
    connect(action11_1, &QAction::triggered, this, &Widget::action11_1_slot);//���Ŷ������->ִ��action11_1_slot��
    connect(action12_1, &QAction::triggered, this, &Widget::action12_1_slot);//˳�򲥷Ŷ������->ִ��action12_1_slot��
    connect(action12_2, &QAction::triggered, this, &Widget::action12_2_slot);//������Ŷ������->ִ��action12_2_slot��
    connect(action12_3, &QAction::triggered, this, &Widget::action12_3_slot);//����ѭ�����Ŷ������->ִ��action12_3_slot��
    connect(ui.verticalSlider, &QSlider::valueChanged, this, &Widget::changeVolume);//�����������õĸı�->�����ı�
    connect(music, &QMediaPlayer::stateChanged, this, &Widget::music_stateChang);//���ֵĲ���״̬�ı�->ִ��music_stateChang��
    connect(Music, &Dialog::Data, this, &Widget::Data_slot);//���ռ��򲥷���������
    connect(detila, &QAction::triggered, this, &Widget::detila_slot);//�������鶯�����->ִ��detila_slot��
    connect(playlist, &QMediaPlaylist::playbackModeChanged, this, &Widget::PlaylistModel_slot);//�����б�ģ�͸ı�->ִ��Widget::PlaylistModel_slot��
    connect(location, &QAction::triggered, this, &Widget::on_pushButton_7_clicked);//��λ�������->ִ��on_pushButton_7_clicked��
    connect(ClearHistory, &QAction::triggered, this, &Widget::ClearHistory_Slot);

}
inline void Widget::init_tooltip()
{
    ui.horizontalSlider->setToolTip(("���Ž���"));
    ui.pushButton->setToolTip(("��Ӹ���"));
    ui.pushButton_2->setToolTip(("��ͣ"));
    ui.pushButton_3->setToolTip(("��һ��"));
    ui.pushButton_4->setToolTip(("��һ��"));
    ui.pushButton_5->setToolTip(("����"));
    ui.pushButton_6->setToolTip(("����Ƥ��"));
    ui.pushButton_7->setToolTip(("��λ"));
    ui.pushButton_8->setToolTip(("����"));
    ui.pushButton_9->setToolTip(("˳�򲥷�"));
    ui.pushButton_10->setToolTip(("��������"));
    ui.pushButton_11->setToolTip(("��ϲ��"));
    ui.pushButton_12->setToolTip(("�ҵ��ղ�"));
    ui.pushButton_13->setToolTip(("�л�������ģʽ/˫��"));
    ui.pushButton_15->setToolTip(("���ز����б�"));
    ui.pushButton_17->setToolTip(("�ر�"));
    ui.pushButton_16->setToolTip(("��С��"));


}
inline void Widget::init_icon()
{
    ui.pushButton_2->setIconSize(QSize(48, 48));//��ͣ/����
    ui.pushButton_2->setIcon(QIcon(":/image/image/image/pase.png"));
    ui.pushButton_2->setStyleSheet(PaseStyle());
    ui.pushButton_15->setIconSize(QSize(32, 32));//����/��ʾ�����б�
    ui.pushButton_15->setIcon(QIcon(":/image/image/image/left.png"));
    ui.pushButton_15->setStyleSheet(HideListStyle());
    ui.pushButton_9->setIconSize(QSize(32, 32));//����ģʽ
    ui.pushButton_9->setIcon(QIcon(":/image/image/image/loop.png"));
    ui.pushButton_9->setStyleSheet(LoopStyle());
    ui.pushButton_14->setIconSize(QSize(32, 32));//��ϲ��
    ui.pushButton_14->setIcon(QIcon(":/image/image/image/Ilike.png"));
    ui.pushButton_14->setStyleSheet(IlikeStyle());
    ui.pushButton_8->setIconSize(QSize(32, 32));//����
    ui.pushButton_8->setStyleSheet(VoiceStyle());
    ui.pushButton_8->setIcon(QIcon(":/image/image/image/music-voice.png"));


}
inline void Widget::init_action()
{

    action1 = new QAction(this);//�������������
    action2 = new QAction(this);//�������ϲ��
    action3 = new QAction(this);//������ҵ��ղ�
    action1->setIcon(QIcon(":/image/image/music_32px_1125557_easyicon.net.png"));
    action1->setText(("�������������"));
    action1->setShortcut(QKeySequence("Ctrl+O"));
    action2->setIcon(QIcon(":/image/image/like_outline_32px_1101681_easyicon.net.png"));
    action2->setText(("�������ϲ��"));
    action2->setShortcut(QKeySequence("Ctrl+A"));
    action3->setIcon(QIcon(":/image/image/list_32px_1074296_easyicon.net.png"));
    action3->setText(("������ҵ��ղ�"));
    action3->setShortcut(QKeySequence("Ctrl+Z"));


    QMenu* menu1 = new QMenu(this);//��Ӳ˵�
    menu1->addAction(action1);
    menu1->addAction(action2);
    menu1->addAction(action3);
    add = new QAction(this);//��Ӹ���
    add->setIcon(QIcon(":/image/image/add.png"));
    add->setText(("��Ӹ���"));
    add->setMenu(menu1);
    menu1->setStyleSheet(
        MenuStyle()
    );
    ui.pushButton->setMenu(menu1);

    location = new QAction(this);//��λ
    location->setText(("��λ"));
    location->setIcon(QIcon(":/image/image/location_32px_1074876_easyicon.net.png"));

    action4 = new QAction(this);//����͸����
    action5 = new QAction(this);//����Ƥ��

    action5_1 = new QAction(this);//Ĭ��Ƥ��1
    action5_2 = new QAction(this);//Ĭ��Ƥ��2
    action5_3 = new QAction(this);//�Զ���Ƥ��
    action5_4 = new QAction(this);
    action6 = new QAction(this);//����
    action7 = new QAction(this);//ʹ�ý���
    action8 = new QAction(this);//�˳�
    ClearALL = new QAction(this);//���
    ClearALL_1 = new QAction(this);//�����������
    ClearALL_2 = new QAction(this);//�����ϲ��
    ClearALL_3 = new QAction(this);//����ҵ��ղ�
    ClearALL_4 = new QAction(this);//�������
    ClearHistory = new QAction(this);//�����ʷ��¼
    action4->setIcon(QIcon(":/image/image/ooopic_1500874104.png"));
    action4->setText(("����͸����           "));

    action4_1 = new QAction(this);//͸���ȼ�
    action4_2 = new QAction(this);//͸���ȼ�
    action4_1->setIcon(QIcon(":/image/image/add.png"));
    action4_1->setText(("+5%"));
    action4_1->setShortcut(QKeySequence("Ctrl++"));
    action4_2->setIcon(QIcon(":/image/image/sub.png"));
    action4_2->setText(("-5%"));
    action4_2->setShortcut(QKeySequence("Ctrl+-"));
    QMenu* temp = new QMenu(this);//͸���Ȳ˵�
    temp->addAction(action4_1);
    temp->addAction(action4_2);
    temp->setStyleSheet(
        MenuStyle()
    );
    action4->setMenu(temp);

    action5->setIcon(QIcon(":/image/image/pf.png"));
    action5->setText(("����Ƥ��"));

    action5_1->setIcon(QIcon(":/image/image/pf2.png"));
    action5_1->setText(("��ɫ"));

    action5_2->setIcon(QIcon(":/image/image/pf5.png"));
    action5_2->setText(("����"));
    action5_4->setIcon(QIcon(":/image/image/pf.png"));
    action5_4->setText(("��ɫ"));
    action5_3->setIcon(QIcon(":/image/image/pf4.png"));
    action5_3->setText(("�Զ���"));

    action5_3->setShortcut(QKeySequence("Ctrl+X"));
    QMenu* ChangeBackGroundMenu = new QMenu(this);//����Ƥ���˵�
    ChangeBackGroundMenu->addAction(action5_1);
    ChangeBackGroundMenu->addAction(action5_2);
    ChangeBackGroundMenu->addAction(action5_4);
    ChangeBackGroundMenu->addAction(action5_3);
    ChangeBackGroundMenu->setStyleSheet(
        MenuStyle()
    );
    action5->setMenu(ChangeBackGroundMenu);

    ui.pushButton_6->setMenu(ChangeBackGroundMenu);

    action6->setIcon(QIcon(":/image/image/ooopic_1500873230.png"));
    action6->setText(("����"));
    action7->setIcon(QIcon(":/image/image/ooopic_1500873272.png"));
    action7->setText(("ʹ�ý���"));
    ClearALL->setIcon(QIcon(":/image/image/edit_clear_locationbar_ltr_32px_539686_easyicon.net.png"));
    ClearALL->setText(("���"));

    ClearALL_1->setIcon(QIcon(":/image/image/Music_32px_1144946_easyicon.net.png"));
    ClearALL_1->setText(("������������б�"));
    ClearALL_1->setShortcut(QKeySequence("Ctrl+M"));
    ClearALL_2->setIcon(QIcon(":/image/image/like_outline_32px_1170275_easyicon.net.png"));
    ClearALL_2->setText(("�����ϲ���б�"));
    ClearALL_2->setShortcut(QKeySequence("Ctrl+N"));
    ClearALL_3->setIcon(QIcon(":/image/image/list_32px_1142913_easyicon.net.png"));
    ClearALL_3->setText(("����ҵ��ղ�"));
    ClearALL_3->setShortcut(QKeySequence("Ctrl+B"));
    ClearALL_4->setIcon(QIcon(":/image/image/playlist_27.690544412607px_1187707_easyicon.net.png"));
    ClearALL_4->setText(("��������б�"));
    ClearALL_4->setShortcut(QKeySequence("Ctrl+V"));
    ClearHistory->setIcon(QIcon(":/image/image/nextbo.png"));
    ClearHistory->setText(("�����ʷ��¼"));
    ClearHistory->setShortcut(QKeySequence("Ctrl+Shift+S"));
    QMenu* M = new QMenu(this);//����˵�

    M->addAction(ClearALL_1);
    M->addAction(ClearALL_2);
    M->addAction(ClearALL_3);
    M->addAction(ClearALL_4);
    M->addAction(ClearHistory);
    M->setStyleSheet(MenuStyle());
    ClearALL->setMenu(M);

    action8->setIcon(QIcon(":/image/image/tc.png"));
    action8->setText(("�˳�"));
    action8->setShortcut(QKeySequence("Ctrl+Q"));
    QMenu* menu2 = new QMenu(this);//���ü��˵�
    menu2->addAction(action4);
    menu2->addAction(action5);
    menu2->addAction(action6);
    menu2->addAction(action7);
    menu2->addAction(ClearALL);
    menu2->addAction(action8);
    menu2->setStyleSheet(MenuStyle());
    ui.pushButton_5->setMenu(menu2);

    action9 = new QAction(this);//������һ��
    action9->setIcon(QIcon(":/image/image/pre1.png"));
    action9->setText(("������һ��"));

    action10 = new QAction(this);//������һ��
    action10->setIcon(QIcon(":/image/image/next1.png"));
    action10->setText(("������һ��"));

    action11 = new QAction(this);//��ͣ
    action11->setIcon(QIcon(":/image/image/zangting.png"));
    action11->setText(("��ͣ"));

    action11_1 = new QAction(this);//����
    action11_1->setIcon(QIcon(":/image/image/bf2.png"));
    action11_1->setText(("����"));


    action12 = new QAction(this);//����ģʽ
    action12->setIcon(QIcon(":/image/image/moshi1.png"));
    action12->setText(("����ģʽ"));
    action12_1 = new QAction(this);//˳�򲥷�
    action12_1->setIcon(QIcon(":/image/image/player-icons_32px_1137007_easyicon.net.png"));
    action12_1->setText(("˳�򲥷�"));
    action12_2 = new QAction(this);//�������
    action12_2->setIcon(QIcon(":/image/image/player-icons_32px_1137005_easyicon.net.png"));
    action12_2->setText(("�������"));
    action12_3 = new QAction(this);//����ѭ��
    action12_3->setIcon(QIcon(":/image/image/player-icons_32px_1137006_easyicon.net.png"));
    action12_3->setText(("����ѭ��"));
    QMenu* temp1 = new QMenu(this);//����ģʽ�˵�
    temp1->addAction(action12_1);
    temp1->addAction(action12_2);
    temp1->addAction(action12_3);
    temp1->setStyleSheet(
        MenuStyle()

    );
    action12->setMenu(temp1);
    action13 = new QAction(this);//�˳�
    action13->setIcon(QIcon(":/image/image/tc.png"));
    action13->setShortcut(QKeySequence("Ctrl+Q"));
    action13->setText(("�˳�"));
    detila = new QAction(this);//��������
    detila->setIcon(QIcon(":/image/image/inf.png"));
    detila->setText(("������Ϣ"));

}
inline void Widget::init_list()
{

    QSqlQuery query;
    model = new QSqlTableModel(this);//���������б����ݿ�ģ��
    model->setTable("LocalMusic");
    model->select();
    model_2 = new QSqlTableModel(this);//��ϲ���б����ݿ�ģ��
    model_2->setTable("LikeMusic");
    model_2->select();
    model_3 = new QSqlTableModel(this);//�ҵ��ղ����ݿ�ģ��
    model_3->setTable("  CollectMusic");
    model_3->select();
    query.exec("select * from LocalMusic");
    while (query.next())//��ʼ���������ֲ����б�
    {
        QString Name = query.value(1).toString();
        QString FileName = query.value(2).toString();
        if (!Name.isEmpty() && !FileName.isEmpty())
        {
            QListWidgetItem* item1 = new QListWidgetItem;
            item1->setIcon(QIcon(":/image/image/Music_32px_1144946_easyicon.net.png"));
            item1->setText(Name);
            ui.listWidget_3->addItem(item1);
            playlist->addMedia(QUrl::fromLocalFile(FileName));
            list1.push_back(0);
            FilePath.push_back(FileName);
        }


    }
    query.exec("select * from LikeMusic");
    while (query.next())//��ʼ����ϲ�������б�
    {
        QString Name = query.value(1).toString();
        QString FileName = query.value(2).toString();
        if (!Name.isEmpty() && !FileName.isEmpty())
        {
            QListWidgetItem* item4 = new QListWidgetItem;
            item4->setIcon(QIcon(":/image/image/like_outline_32px_1170275_easyicon.net.png"));
            item4->setText(Name);
            ui.listWidget_2->addItem(item4);
            playlist_2->addMedia(QUrl::fromLocalFile(FileName));


        }

    }
    query.exec("select * from  CollectMusic");
    while (query.next())//��ʼ���ҵ��ղز����б�
    {
        QString Name = query.value(1).toString();
        QString FileName = query.value(2).toString();
        if (!Name.isEmpty() && !FileName.isEmpty())
        {
            QListWidgetItem* item5 = new QListWidgetItem;
            item5->setIcon(QIcon(":/image/image/music_not_25.570093457944px_1171234_easyicon.net.png"));
            item5->setText(Name);
            ui.listWidget->addItem(item5);
            playlist_3->addMedia(QUrl::fromLocalFile(FileName));


        }

    }
    music->setPlaylist(playlist);
    ui.listWidget_5->clear();



}
inline QString Widget::MusicListStyle() {

    return  "QPushButton"
        " {"
        "background-image:url(:/image/image/image/music.png);"
        "   background-repeat:no-repeat;"
        "  background-position:center center;"
        "   border:none;"

        "    }"

        "QPushButton:hover{"
        "  background-repeat:no-repeat;"
        "   background-position:center center;"
        "background-image:url(:/image/image/image/music.png);"

        " }"
        " QPushButton:pressed{"
        "background-repeat:no-repeat;"
        " background-position:center center;"
        " background-image:url(:/image/image/image/music.png);"

        "}";

}

inline QString Widget::MenuStyle()
{
    return     " QMenu {"
        " background: white; "
        "border-radius:2px;"
        "border:1px solid rgb(200,200,200);"

        "  }"
        "  QMenu::item {"

        " background-color: transparent;"
        " padding:5px 30px;"
        "       margin:0px 0px;"
        " border-bottom:0px solid #DBDBDB;"
        "}"
        " QMenu::item:selected { "
        "background-color: aqua;"
        "}";

}

inline QString Widget::PlayStyle()
{

    return "QPushButton"
        " {"
        "background-image:url(:/image/image/image/play.png);"
        "   background-repeat:no-repeat;"
        "  background-position:center center;"
        "   border:none;"

        "    }"

        "QPushButton:hover{"
        "  background-repeat:no-repeat;"
        "   background-position:center center;"
        "background-image:url(:/image/image/image-hover/play-hover.png);"

        " }"
        " QPushButton:pressed{"
        "background-repeat:no-repeat;"
        " background-position:center center;"
        " background-image:url(:/image/image/image/play.png);"

        "}";

}
inline QString Widget::PaseStyle()
{


    return "QPushButton"
        " {"
        "background-image:url(:/image/image/image/pase.png);"
        "   background-repeat:no-repeat;"
        "  background-position:center center;"
        "   border:none;"

        "    }"

        "QPushButton:hover{"
        "  background-repeat:no-repeat;"
        "   background-position:center center;"
        "background-image:url(:/image/image/image-hover/pase-hover.png);"

        " }"
        " QPushButton:pressed{"
        "background-repeat:no-repeat;"
        " background-position:center center;"
        " background-image:url(:/image/image/image/pase.png);"

        "}";

}
inline QString Widget::IlikeStyle()
{


    return "QPushButton"
        " {"
        "background-image:url(:/image/image/image/Ilike.png);"
        "   background-repeat:no-repeat;"
        "  background-position:center center;"
        "   border:none;"

        "    }"

        "QPushButton:hover{"
        "  background-repeat:no-repeat;"
        "   background-position:center center;"
        "background-image:url(:/image/image/image-hover/Ilike-hover.png);"

        " }"
        " QPushButton:pressed{"
        "background-repeat:no-repeat;"
        " background-position:center center;"
        " background-image:url(:/image/image/image/Ilike.png);"

        "}";

}
inline QString Widget::Ilike1Style()
{


    return "QPushButton"
        " {"
        "background-image:url(:/image/image/image/Ilike1.png);"
        "   background-repeat:no-repeat;"
        "  background-position:center center;"
        "   border:none;"

        "    }"

        "QPushButton:hover{"
        "  background-repeat:no-repeat;"
        "   background-position:center center;"
        "background-image:url(:/image/image/image-hover/Ilike1-hover.png);"

        " }"
        " QPushButton:pressed{"
        "background-repeat:no-repeat;"
        " background-position:center center;"
        " background-image:url(:/image/image/image/Ilike1.png);"

        "}";

}
inline QString Widget::ShowListStyle()
{
    return "QPushButton"
        " {"
        "background-image:url(:/image/image/image/right.png);"
        "   background-repeat:no-repeat;"
        "  background-position:center center;"
        "   border:none;"

        "    }"

        "QPushButton:hover{"
        "  background-repeat:no-repeat;"
        "   background-position:center center;"
        "background-image:url(:/image/image/image-hover/right-hover.png);"

        " }"
        " QPushButton:pressed{"
        "background-repeat:no-repeat;"
        " background-position:center center;"
        " background-image:url(:/image/image/image/right.png);"

        "}";

}
inline QString Widget::HideListStyle()
{
    return "QPushButton"
        " {"
        "background-image:url(:/image/image/image/left.png);"
        "   background-repeat:no-repeat;"
        "  background-position:center center;"
        "   border:none;"

        "    }"

        "QPushButton:hover{"
        "  background-repeat:no-repeat;"
        "   background-position:center center;"
        "background-image:url(:/image/image/image-hover/left-light.png);"

        " }"
        " QPushButton:pressed{"
        "background-repeat:no-repeat;"
        " background-position:center center;"
        " background-image:url(:/image/image/image/left.png);"

        "}";
}
inline QString Widget::RandomStyle()
{

    return "QPushButton"
        " {"
        "background-image:url(:/image/image/image/play-random.png);"
        "   background-repeat:no-repeat;"
        "  background-position:center center;"
        "   border:none;"

        "    }"

        "QPushButton:hover{"
        "  background-repeat:no-repeat;"
        "   background-position:center center;"
        "background-image:url(:/image/image/image-hover/play-random-hover.png);"

        " }"
        " QPushButton:pressed{"
        "background-repeat:no-repeat;"
        " background-position:center center;"
        " background-image:url(:/image/image/image/play-random.png);"

        "}";

}
inline QString Widget::LoopStyle()
{


    return "QPushButton"
        " {"
        "background-image:url(:/image/image/image/loop.png);"
        "   background-repeat:no-repeat;"
        "  background-position:center center;"
        "   border:none;"

        "    }"

        "QPushButton:hover{"
        "  background-repeat:no-repeat;"
        "   background-position:center center;"
        "background-image:url(:/image/image/image-hover/loop-hover.png);"

        " }"
        " QPushButton:pressed{"
        "background-repeat:no-repeat;"
        " background-position:center center;"
        " background-image:url(:/image/image/image/loop.png);"

        "}";

}
inline QString Widget::LoopOneStyle()
{


    return "QPushButton"
        " {"
        "background-image:url(:/image/image/image/loop-one.png);"
        "   background-repeat:no-repeat;"
        "  background-position:center center;"
        "   border:none;"

        "    }"

        "QPushButton:hover{"
        "  background-repeat:no-repeat;"
        "   background-position:center center;"
        "background-image:url(:/image/image/image-hover/loop-one-hover.png);"

        " }"
        " QPushButton:pressed{"
        "background-repeat:no-repeat;"
        " background-position:center center;"
        " background-image:url(:/image/image/image/loop-one.png);"

        "}";

}
inline QString Widget::VoiceStyle()
{

    return "QPushButton"
        " {"
        "background-image:url(:/image/image/image/music-voice.png);"
        "   background-repeat:no-repeat;"
        "  background-position:center center;"
        "   border:none;"

        "    }"

        "QPushButton:hover{"
        "  background-repeat:no-repeat;"
        "   background-position:center center;"
        "background-image:url(:/image/image/image-hover/music-voice-hover.png);"

        " }"
        " QPushButton:pressed{"
        "background-repeat:no-repeat;"
        " background-position:center center;"
        " background-image:url(:/image/image/image/music-voice.png);"

        "}";
}
inline QString Widget::NoVoiceStyle()
{

    return "QPushButton"
        " {"
        "background-image:url(:/image/image/image/none-music.png);"
        "   background-repeat:no-repeat;"
        "  background-position:center center;"
        "   border:none;"

        "    }"

        "QPushButton:hover{"
        "  background-repeat:no-repeat;"
        "   background-position:center center;"
        "background-image:url(:/image/image/image-hover/none-music-hover.png);"

        " }"
        " QPushButton:pressed{"
        "background-repeat:no-repeat;"
        " background-position:center center;"
        " background-image:url(:/image/image/image/none-music.png);"

        "}";
}

Widget::~Widget()//����
{
    delete ui;
}
static QString Time(qint64 time)//ת��ʱ��
{
    qint64 seconds = time / 1000;
    const qint64 minutes = seconds / 60;
    seconds -= minutes * 60;
    return QStringLiteral("%1:%2")
        .arg(minutes, 2, 10, QLatin1Char('0'))
        .arg(seconds, 2, 10, QLatin1Char('0'));
}
void Widget::updateInfo()//�����ı�
{

    QString info;
    info = ("���ڲ���:  ");
    if (music->isMetaDataAvailable())
    {
        QString title = music->metaData(QStringLiteral("Title")).toString();
        if (!title.isEmpty())
        {
            info += title;
        }
        else
        {
            info += ("δ֪����");
        }
        info += "-";
        QString author = music->metaData(QStringLiteral("Author")).toString();
        if (!author.isEmpty())
        {
            info += author;
        }
        else
        {
            info += ("δ֪����");
        }
    }
    //�жϸø����ǲ�����ϲ������
    ui.label->setText(info);
    if (music->playlist() == playlist_2)
    {
        ui.pushButton_14->setIcon(QIcon(":/image/image/image/Ilike1.png"));
        ui.pushButton_14->setStyleSheet(Ilike1Style());
        ui.pushButton_14->setToolTip(("��ϲ��"));
    }
    else if (music->playlist() == playlist_3)
    {

        ui.pushButton_14->setIcon(QIcon(":/image/image/image/music.png"));
        ui.pushButton_14->setStyleSheet(MusicListStyle());
        ui.pushButton_14->setToolTip(("�ҵ��ղ�"));

    }
    else if (music->playlist() == playlist_4)
    {
        ui.pushButton_14->setIcon(QIcon(":/image/image/image/music.png"));
        ui.pushButton_14->setStyleSheet(MusicListStyle());
        ui.pushButton_14->setToolTip(("������ʷ"));
    }
    else
    {
        //�жϸø����ǲ�����ϲ������
        QSqlQuery query;
        query.exec("select * from LocalMusic");
        model->setTable("LocalMusic");
        model->select();
        int row = playlist->currentIndex();
        int flag;
        flag = model->data(model->index(row, 3)).toInt();
        if (flag)
        {

            ui.pushButton_14->setIcon(QIcon(":/image/image/image/Ilike1.png"));
            ui.pushButton_14->setStyleSheet(Ilike1Style());
            ui.pushButton_14->setToolTip(("��ϲ��"));

        }
        else
        {

            ui.pushButton_14->setIcon(QIcon(":/image/image/image/Ilike.png"));
            ui.pushButton_14->setStyleSheet(IlikeStyle());
            ui.pushButton_14->setToolTip(("�������ϲ��"));

        }

    }

    int x = qrand() % 11;
    ui.label_3->setText(labelText1.at(x));
    ui.label_4->setText(labelText2.at(x));
}
void Widget::updatePosition(qint64 position)//���²���λ��
{
    ui.horizontalSlider->setValue(position);
    ui.label_2->setText(Time(position) + "/" + Time(music->duration()));
}
void Widget::updateDuration(qint64 duration)//���²��Ž���
{

    ui.horizontalSlider->setRange(0, duration);
    ui.horizontalSlider->setEnabled(duration > 0);
    ui.horizontalSlider->setPageStep(duration / 10);
}
void Widget::pushbuttonstyle_5()
{

    ui.pushButton_10->setStyleSheet("QPushButton"
        "{"
        "background-image: url(:/image/image/image/music.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"
        "border:none;"

        "}"

        "QPushButton:hover{"

        "background-image: url(:/image/image/image-hover/music-hover.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"


        "}"
        "QPushButton:pressed{"
        "background-image: url(:/image/image/image/music.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"

        "}"
    );
    ui.pushButton_11->setStyleSheet(

        " QPushButton"
        "{"
        "background-image: url(:/image/image/image/like.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"
        "border:none;"

        "}"

        "QPushButton:hover{"

        "background-image: url(:/image/image/image-hover/like-hover.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"


        "}"
        "QPushButton:pressed{"
        "background-image: url(:/image/image/image/like.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"

        "}"

    );

    ui.pushButton_12->setStyleSheet("QPushButton"
        "{"
        "background-image: url(:/image/image/image/list.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"
        "border:none;"

        "}"

        "QPushButton:hover{"

        "background-image: url(:/image/image/image-hover/list-hover.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"


        "}"
        "QPushButton:pressed{"
        "background-image: url(:/image/image/image/list.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"

        "}"
    );
    ui.pushButton_22->setStyleSheet("QPushButton"
        "{"
        "background-image: url(:/image/image/image-hover/play-resently-hover.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"
        "border:none;"

        "}"

        "QPushButton:hover{"

        "background-image: url(:/image/image/image-hover/play-resently-hover.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"


        "}"
        "QPushButton:pressed{"
        "background-image: url(:/image/image/image/play-resently.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"

        "}");
}

void Widget::pushbuttonstyle()//Ч������  �������ְ�ť��ʾ��ɫ����
{

    ui.pushButton_10->setStyleSheet("QPushButton"
        "{"
        "background-image: url(:/image/image/image-hover/music-hover.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"
        "border:none;"

        "}"

        "QPushButton:hover{"

        "background-image: url(:/image/image/image-hover/music-hover.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"


        "}"
        "QPushButton:pressed{"
        "background-image: url(:/image/image/image/music.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"

        "}"
    );
    ui.pushButton_11->setStyleSheet(

        " QPushButton"
        "{"
        "background-image: url(:/image/image/image/like.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"
        "border:none;"

        "}"

        "QPushButton:hover{"

        "background-image: url(:/image/image/image-hover/like-hover.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"


        "}"
        "QPushButton:pressed{"
        "background-image: url(:/image/image/image/like.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"

        "}"

    );

    ui.pushButton_12->setStyleSheet("QPushButton"
        "{"
        "background-image: url(:/image/image/image/list.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"
        "border:none;"

        "}"

        "QPushButton:hover{"

        "background-image: url(:/image/image/image-hover/list-hover.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"


        "}"
        "QPushButton:pressed{"
        "background-image: url(:/image/image/image/list.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"

        "}"
    );
    ui.pushButton_22->setStyleSheet("QPushButton"
        "{"
        "background-image: url(:/image/image/image/play-resently.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"
        "border:none;"

        "}"

        "QPushButton:hover{"

        "background-image: url(:/image/image/image-hover/play-resently-hover.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"


        "}"
        "QPushButton:pressed{"
        "background-image: url(:/image/image/image/play-resently.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"

        "}");

}
void Widget::pushbuttonstyle_2()//Ч������  ��ϲ���б�ť��ʾ��ɫ����
{
    ui.pushButton_10->setStyleSheet("QPushButton"
        "{"
        "background-image:url(:/image/image/image/music.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"
        "border:none;"

        "}"

        "QPushButton:hover{"

        "background-image: url(:/image/image/image-hover/music-hover.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"


        "}"
        "QPushButton:pressed{"
        "background-image:url(:/image/image/image/music.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"

        "}"
    );
    ui.pushButton_11->setStyleSheet(

        " QPushButton"
        "{"
        "background-image: url(:/image/image/image-hover/like-hover.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"
        "border:none;"

        "}"

        "QPushButton:hover{"

        "background-image: url(:/image/image/image-hover/like-hover.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"


        "}"
        "QPushButton:pressed{"
        "background-image: url(:/image/image/image/like.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"

        "}"

    );

    ui.pushButton_12->setStyleSheet("QPushButton"
        "{"
        "background-image: url(:/image/image/image/list.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"
        "border:none;"

        "}"

        "QPushButton:hover{"

        "background-image: url(:/image/image/image-hover/list-hover.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"


        "}"
        "QPushButton:pressed{"
        "background-image: url(:/image/image/image/list.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"

        "}"
    );
    ui.pushButton_22->setStyleSheet("QPushButton"
        "{"
        "background-image: url(:/image/image/image/play-resently.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"
        "border:none;"

        "}"

        "QPushButton:hover{"

        "background-image: url(:/image/image/image-hover/play-resently-hover.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"


        "}"
        "QPushButton:pressed{"
        "background-image: url(:/image/image/image/play-resently.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"

        "}");


}
void Widget::pushbuttonstyle_3()//Ч������  �ҵ��ղذ�ť��ʾ��ɫ����
{

    ui.pushButton_10->setStyleSheet("QPushButton"
        "{"
        "background-image:url(:/image/image/image/music.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"
        "border:none;"

        "}"

        "QPushButton:hover{"

        "background-image: url(:/image/image/image-hover/music-hover.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"


        "}"
        "QPushButton:pressed{"
        "background-image:url(:/image/image/image/music.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"

        "}"
    );
    ui.pushButton_11->setStyleSheet(

        " QPushButton"
        "{"
        "background-image: url(:/image/image/image/like.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"
        "border:none;"

        "}"

        "QPushButton:hover{"

        "background-image: url(:/image/image/image-hover/like-hover.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"


        "}"
        "QPushButton:pressed{"
        "background-image: url(:/image/image/image/like.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"

        "}"

    );

    ui.pushButton_12->setStyleSheet("QPushButton"
        "{"
        "background-image: url(:/image/image/image-hover/list-hover.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"
        "border:none;"

        "}"

        "QPushButton:hover{"

        "background-image: url(:/image/image/image-hover/list-hover.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"


        "}"
        "QPushButton:pressed{"
        "background-image: url(:/image/image/image/list.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"

        "}"
    );
    ui.pushButton_22->setStyleSheet("QPushButton"
        "{"
        "background-image: url(:/image/image/image/play-resently.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"
        "border:none;"

        "}"

        "QPushButton:hover{"

        "background-image: url(:/image/image/image-hover/play-resently-hover.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"


        "}"
        "QPushButton:pressed{"
        "background-image: url(:/image/image/image/play-resently.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"

        "}");

}
void Widget::pushbuttonstyle_4()//Ч������  ���а�ť�����������ɫ
{

    ui.pushButton_10->setStyleSheet("QPushButton"
        "{"
        "background-image:url(:/image/image/image/music.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"
        "border:none;"

        "}"

        "QPushButton:hover{"

        "background-image: url(:/image/image/image-hover/music-hover.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"


        "}"
        "QPushButton:pressed{"
        "background-image:url(:/image/image/image/music.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"

        "}"
    );
    ui.pushButton_11->setStyleSheet(

        " QPushButton"
        "{"
        "background-image: url(:/image/image/image/like.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"
        "border:none;"

        "}"

        "QPushButton:hover{"

        "background-image: url(:/image/image/image-hover/like-hover.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"


        "}"
        "QPushButton:pressed{"
        "background-image: url(:/image/image/image/like.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"

        "}"

    );

    ui.pushButton_12->setStyleSheet("QPushButton"
        "{"
        "background-image: url(:/image/image/image/list.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"
        "border:none;"

        "}"

        "QPushButton:hover{"

        "background-image: url(:/image/image/image-hover/list-hover.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"


        "}"
        "QPushButton:pressed{"
        "background-image: url(:/image/image/image/list.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"

        "}"
    );
    ui.pushButton_22->setStyleSheet("QPushButton"
        "{"
        "background-image: url(:/image/image/image/play-resently.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"
        "border:none;"

        "}"

        "QPushButton:hover{"

        "background-image: url(:/image/image/image-hover/play-resently-hover.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"


        "}"
        "QPushButton:pressed{"
        "background-image: url(:/image/image/image/play-resently.png);"
        "background-repeat:no-repeat;"
        "background-position:center center;"

        "}");

}

void Widget::on_pushButton_10_clicked()//������������
{
    ui.listWidget_2->setSelectionMode(QListWidget::SingleSelection);
    ui.listWidget->setSelectionMode(QListWidget::SingleSelection);
    ui.stackedWidget->setCurrentIndex(0);
    pushbuttonstyle();
    ListFocus();
}
void Widget::on_pushButton_11_clicked()//��������ϲ��
{
    ui.listWidget_3->setSelectionMode(QListWidget::SingleSelection);
    ui.listWidget->setSelectionMode(QListWidget::SingleSelection);
    ui.stackedWidget->setCurrentIndex(1);
    pushbuttonstyle_2();
    ListFocus();
}
void Widget::on_pushButton_12_clicked()//�����ҵ��ղ�
{
    ui.listWidget_2->setSelectionMode(QListWidget::SingleSelection);
    ui.listWidget_3->setSelectionMode(QListWidget::SingleSelection);
    ui.stackedWidget->setCurrentIndex(2);
    pushbuttonstyle_3();
    ListFocus();
}
void Widget::on_pushButton_22_clicked()//��ʷ��¼
{
    ui.listWidget->setSelectionMode(QListWidget::SingleSelection);
    ui.listWidget_2->setSelectionMode(QListWidget::SingleSelection);
    ui.listWidget_3->setSelectionMode(QListWidget::SingleSelection);
    ui.stackedWidget->setCurrentIndex(4);
    pushbuttonstyle_5();
    ListFocus();
}
void Widget::detila_slot()//��������
{
    ListFocus();
    if (music->playlist() == playlist)
    {
        int row = playlist->currentIndex();
        QString temp = ui.label->text();
        QString Author = temp.split("-").last();
        QString MusicName = temp.remove("-" + Author).split(":  ").last();
        QString time = ui.label_2->text().split("/").last();
        model->setTable("LocalMusic");
        model->select();
        QString FileName = model->data(model->index(row, 2)).toString();
        QMessageBox::about(this, "������Ϣ", QString("������ : %1  \n"
            "���� : %2 \n"
            "ʱ�� : %3 \n"
            "�ļ�·�� : %4\n").arg(MusicName).arg(Author).arg(time).arg(FileName));


    }
    else if (music->playlist() == playlist_2)
    {

        int row = playlist_2->currentIndex();
        QString temp = ui.label->text();
        QString Author = temp.split("-").last();
        QString MusicName = temp.remove("-" + Author).split(":  ").last();
        QString time = ui.label_2->text().split("/").last();
        model_2->setTable("LikeMusic");
        model_2->select();
        QString FileName = model_2->data(model_2->index(row, 2)).toString();
        QMessageBox::about(this, "������Ϣ", QString("������ : %1  \n"
            "���� : %2 \n"
            "ʱ�� : %3 \n"
            "�ļ�·�� : %4\n").arg(MusicName).arg(Author).arg(time).arg(FileName));

    }
    else if (music->playlist() == playlist_3)
    {
        int row = playlist_3->currentIndex();
        QString temp = ui.label->text();
        QString Author = temp.split("-").last();
        QString MusicName = temp.remove("-" + Author).split(":  ").last();
        QString time = ui.label_2->text().split("/").last();
        model_3->setTable("  CollectMusic");
        model_3->select();
        QString FileName = model_3->data(model_3->index(row, 2)).toString();
        QMessageBox::about(this, "������Ϣ", QString("������ : %1  \n"
            "���� : %2 \n"
            "ʱ�� : %3 \n"
            "�ļ�·�� : %4\n").arg(MusicName).arg(Author).arg(time).arg(FileName));


    }
    else
    {
        int row = playlist_4->currentIndex();
        QString temp = ui.label->text();
        QString Author = temp.split("-").last();
        QString MusicName = temp.remove("-" + Author).split(":  ").last();
        QString time = ui.label_2->text().split("/").last();
        QString FileName = FilePath[row];
        QMessageBox::about(this, "������Ϣ", QString("������ : %1  \n"
            "���� : %2 \n"
            "ʱ�� : %3 \n"
            "�ļ�·�� : %4\n").arg(MusicName).arg(Author).arg(time).arg(FileName));


    }
}

void Widget::ClearALL_1_slot()//�����������
{
    int values = QMessageBox::information(this, ("������������б�"), ("ȷ��������������б�?                              ."), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
    if (values == QMessageBox::Yes)
    {
        QSqlQuery query;
        query.exec("select * from LocalMusic");
        query.exec("delete from LocalMusic");
        ui.listWidget_3->clear();
        playlist->clear();
        list1.clear();
        map.clear();
        FilePath.clear();
        ui.listWidget_5->clear();
        if (music->playlist() == playlist)
        {
            TaskProgress->hide();
        }

    }

}
/**�����ʷ��¼
 * @brief Widget::ClearHistory_Slot
 */
void Widget::ClearHistory_Slot() {

    int values = QMessageBox::information(this, ("�����ʷ��¼"), ("ȷ�����������ʷ��¼?                              ."), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
    if (values == QMessageBox::Yes)
    {

        ui.listWidget_5->clear();
        playlist_4->clear();
        for (int i = 0; i < list1.size(); i++)
        {
            list1[i] = 0;
        }
        map.clear();
        if (music->playlist() == playlist_4)
        {
            TaskProgress->hide();
        }
    }

}

void Widget::ClearALL_2_slot()//�����ϲ���б�
{
    int values = QMessageBox::information(this, ("�����ϲ���б�"), ("ȷ�������ϲ���б�?                              ."), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
    if (values == QMessageBox::Yes)
    {
        QSqlQuery query;
        query.exec("select * from LikeMusic");
        query.exec("delete from LikeMusic");
        query.exec("select * from LocalMusic");
        query.prepare(QString("update LocalMusic set biaoji = ? where biaoji = 1"));
        query.bindValue(0, 0);
        query.exec();
        ui.listWidget_2->clear();
        playlist_2->clear();

        if (music->playlist() == playlist_2)
        {
            TaskProgress->hide();
        }
    }
}
void Widget::ClearALL_3_slot()//����ҵ��ղ�
{
    int values = QMessageBox::information(this, ("����ҵ��ղ�"), ("ȷ������ҵ��ղ�?                              ."), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
    if (values == QMessageBox::Yes)
    {
        QSqlQuery query;
        query.exec("select * from CollectMusic");
        query.exec("delete from CollectMusic");
        ui.listWidget->clear();
        playlist_3->clear();

        if (music->playlist() == playlist_3)
        {
            TaskProgress->hide();
        }

    }


}
void Widget::ClearALL_4_slot()//�������
{
    int values = QMessageBox::information(this, ("��������б�"), ("ȷ����������б�?                              ."), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
    if (values == QMessageBox::Yes)
    {
        QSqlQuery query;

        query.exec("delete from LocalMusic");
        query.exec("delete from CollectMusic");
        query.exec("delete from LikeMusic");
        ui.listWidget_3->clear();
        ui.listWidget_2->clear();
        ui.listWidget->clear();
        playlist->clear();
        playlist_2->clear();
        playlist_3->clear();
        playlist_4->clear();
        list1.clear();
        map.clear();
        FilePath.clear();
        ui.listWidget_5->clear();


        TaskProgress->hide();
    }


}

void Widget::action1_slot()//��Ӳ˵�  �������������
{

    ListFocus();
    ui.stackedWidget->setCurrentIndex(0);
    pushbuttonstyle();
    QSqlQuery query;
    query.exec("select * from LocalMusic");
    QStringList list = QFileDialog::getOpenFileNames(this, ("�ļ�"), currentFileName[1], ("��Ƶ�ļ�(*.mp3)"));
    if (!list.isEmpty())
    {
        //�������Ի���
        QProgressDialog* progressdialog = new QProgressDialog(this);
        progressdialog->setWindowModality(Qt::WindowModal);
        progressdialog->resize(400, 120);
        progressdialog->setMinimumSize(400, 120);
        progressdialog->setMaximumSize(400, 120);
        progressdialog->setMinimumDuration(100);
        progressdialog->setWindowTitle(("��Ӹ���"));
        progressdialog->setLabelText(("�������,���Ժ�."));
        QPushButton* button = new QPushButton(this);
        QPixmap pixmap;
        pixmap.load(":/image/image/58d4d135e7bce713bd501050.jpg");
        QPalette palette;
        palette.setBrush(QPalette::Window, QBrush(pixmap.scaled(progressdialog->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
        progressdialog->setPalette(palette);
        button->setStyleSheet("QPushButton{"
            "width:100px;"
            "height:32px;"
            "text-align:center;"
            "line-height:32px;"
            "background-color: deepskyblue;"
            "border-style:solid;"
            "border-width: 1px;"
            "border-radius: 6px;"
            "border-color: deepskyblue;"
            "font: bold 14px;"
            "color :white;"
            "}"
            "QPushButton:hover{"



            "background-color: aqua;"
            "color: white;"
            "border-color:aqua;"


            "}"
            "QPushButton:pressed{"


            "background-color:  white;"
            "border-color:white;"

            "color:deepskyblue;"

            "}");
        button->setText(("�ر�"));
        progressdialog->setCancelButton(button);
        progressdialog->setRange(0, list.size() - 1);
        progressdialog->setStyleSheet("QProgressBar{border: 1px solid grey;border-radius: 5px;text-align: center;background-color:rgba(255,255,255,150);}"
            "QProgressBar::chunk{background-color: #CD96CD;width: 10px;margin: 0.5px;}");

        for (int i = 0; i < list.size(); i++)
        {
            QListWidgetItem* item = new QListWidgetItem;
            item->setIcon(QIcon(":/image/image/Music_32px_1144946_easyicon.net.png"));
            QString path = QDir::toNativeSeparators(list.at(i));
            if (!progressdialog->wasCanceled())
                progressdialog->setValue(i);
            else
            {
                progressdialog->close();
            }
            if (i == list.size() - 1)
            {
                progressdialog->close();
            }

            if (!path.isEmpty())
            {

                QString path1 = path;

                playlist->addMedia(QUrl::fromLocalFile(path));
                QString Name = path.split("\\").last();
                currentFileName[1] = path1.remove(Name);
                Name.remove(QString(".mp3"));
                item->setText(QString("%1").arg(Name));
                item->setToolTip(Name);
                list1.push_back(0);
                ui.listWidget_3->addItem(item);

                int x = qrand() % 1000000;
                query.exec(QString("insert into LocalMusic values (%1,'%2','%3',%4)").arg(x).arg(Name).arg(path).arg(0));
                FilePath.push_back(path);


            }
        }
        delete button;

    }


}
void Widget::action2_slot()//��Ӳ˵�  �������ϲ��
{
    ListFocus();
    ui.stackedWidget->setCurrentIndex(0);
    pushbuttonstyle();
    /*ui.stackedWidget->setCurrentIndex(1);
    pushbuttonstyle_2();
  QSqlQuery query;
  query.exec("select *from LikeMusic");
  QStringList list = QFileDialog::getOpenFileNames(this,("�����ļ�"),currentFileName[2],("��Ƶ�ļ�(*.mp3)"));
  if(!list.isEmpty())
 {//�������Ի���
      QProgressDialog *progressdialog=new QProgressDialog(this);
  progressdialog->setWindowModality(Qt::WindowModal);
  progressdialog->resize(400,120);
  progressdialog->setMinimumSize(400,120);
  progressdialog->setMaximumSize(400,120);
  progressdialog->setMinimumDuration(100);
  progressdialog->setWindowTitle(("��Ӹ���"));
  progressdialog->setLabelText(("�������,���Ժ�."));
  QPushButton *button=new QPushButton(this);
  QPixmap pixmap;
  pixmap.load(":/image/image/58d4d135e7bce713bd501050.jpg");
  QPalette palette;
  palette.setBrush(QPalette::Window,QBrush(pixmap.scaled(progressdialog->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
  progressdialog->setPalette(palette);
  button->setStyleSheet("QPushButton{"

                        "background-color: rgba(122, 122, 122,100);"
                        "border-style:outset;"
                        "border-width: 1px;"
                        "border-radius: 10px;"
                        "border-color: rgba(122, 122, 122,100);"
                        "font: bold 14px;"
                        "color :rgba(0,0,0,100);"
                        "padding: 6px;"

                        "}"
                        "QPushButton:hover{"



                        "background-color: rgba(176, 58, 176,200);"
                        "color: rgba(0,0,0,200);"


                        "}"
                        "QPushButton:pressed{"


                            "background-color:  rgba(255,255,255,150);"
                        "border-color:rgba(255,255,255,150);"
                        "border-style:inset;"
                        "color:rgba(0,0,0,100);"

                        "}");
  button->setText(("�ر�"));
  progressdialog->setCancelButton(button);
  progressdialog->setRange(0,list.size()-1);
  progressdialog->setStyleSheet("QProgressBar{border: 1px solid grey;border-radius: 5px;text-align: center;background-color:rgba(255,255,255,150);}"
                                "QProgressBar::chunk{background-color: #CD96CD;width: 10px;margin: 0.5px;}");

  for(int i=0;i<list.size();i++)
  {
      QListWidgetItem *item2=new QListWidgetItem;
      item2->setIcon(QIcon(":/image/image/like_outline_32px_1170275_easyicon.net.png"));
      QString path=QDir::toNativeSeparators(list.at(i));
      if(!progressdialog->wasCanceled())
      {
          progressdialog->setValue(i);
      }
      else
      {
          progressdialog->close();
      }
      progressdialog->setValue(i);
      if(i==list.size()-1)
      {
          progressdialog->close();
      }

      if(!path.isEmpty())
      {
          QString path1 = path;
          playlist_2->addMedia(QUrl::fromLocalFile(path));
          QString Name=path.split("\\").last();
          currentFileName[2] = path1.remove(Name);
          Name.remove(QString(".mp3"));
          item2->setText(QString("%1").arg(Name));
          item2->setToolTip(Name);


          ui.listWidget_2->addItem(item2);
          query.exec(QString("insert into LikeMusic values (%1,'%2','%3')").arg(qrand()%1000000).arg(Name).arg(path));

      }


  }

  delete button;
  }
*/
    return;

}
void Widget::action3_slot()//��Ӳ˵�  ������ҵ��ղ�
{
    ListFocus();
    ui.stackedWidget->setCurrentIndex(0);
    pushbuttonstyle();
    /*ui.stackedWidget->setCurrentIndex(2);
    pushbuttonstyle_3();
      QSqlQuery query;
      query.exec("select *from  CollectMusic");
      QStringList list = QFileDialog::getOpenFileNames(this,("�����ļ�"),currentFileName[3],("��Ƶ�ļ�(*.mp3)"));
     if(!list.isEmpty())
     {
         //�������Ի���
      QProgressDialog *progressdialog=new QProgressDialog(this);
      progressdialog->setWindowModality(Qt::WindowModal);
      progressdialog->resize(400,120);
      progressdialog->setMinimumSize(400,120);
      progressdialog->setMaximumSize(400,120);
      progressdialog->setMinimumDuration(100);
      progressdialog->setWindowTitle(("��Ӹ���"));
      progressdialog->setLabelText(("�������,���Ժ�."));
      QPushButton *button=new QPushButton(this);
      QPixmap pixmap;
      pixmap.load(":/image/image/58d4d135e7bce713bd501050.jpg");
      QPalette palette;
      palette.setBrush(QPalette::Window,QBrush(pixmap.scaled(progressdialog->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
      progressdialog->setPalette(palette);
      button->setStyleSheet("QPushButton{"

                            "background-color: rgba(122, 122, 122,100);"
                            "border-style:outset;"
                            "border-width: 1px;"
                            "border-radius: 10px;"
                            "border-color: rgba(122, 122, 122,100);"
                            "font: bold 14px;"
                            "color :rgba(0,0,0,100);"
                            "padding: 6px;"

                            "}"
                            "QPushButton:hover{"



                            "background-color: rgba(176, 58, 176,200);"
                            "color: rgba(0,0,0,200);"


                            "}"
                            "QPushButton:pressed{"


                                "background-color:  rgba(255,255,255,150);"
                            "border-color:rgba(255,255,255,150);"
                            "border-style:inset;"
                            "color:rgba(0,0,0,100);"

                            "}");
      button->setText(("�ر�"));
      progressdialog->setCancelButton(button);
      progressdialog->setRange(0,list.size()-1);
      progressdialog->setStyleSheet("QProgressBar{border: 1px solid grey;border-radius: 5px;text-align: center;background-color:rgba(255,255,255,150);}"
                                    "QProgressBar::chunk{background-color: #CD96CD;width: 10px;margin: 0.5px;}");

      for(int i=0;i<list.size();i++)
      {
          QListWidgetItem *item3=new QListWidgetItem;
          item3->setIcon(QIcon(":/image/image/music_not_25.570093457944px_1171234_easyicon.net.png"));
          QString path=QDir::toNativeSeparators(list.at(i));
          if(!progressdialog->wasCanceled())
          {
          progressdialog->setValue(i);
          }
          else
          {
              progressdialog->close();
          }
          if(i==list.size()-1)
          {
              progressdialog->close();
          }

          if(!path.isEmpty())
          {
              QString path1 = path;

              playlist_3->addMedia(QUrl::fromLocalFile(path));
              QString Name=path.split("\\").last();
              currentFileName[3] = path1.remove(Name);
              Name.remove(QString(".mp3"));
              item3->setText(QString("%1").arg(Name));
              item3->setToolTip(Name);

              ui.listWidget->addItem(item3);
              query.exec(QString("insert into  CollectMusic values (%1,'%2','%3')").arg(qrand()%1000000).arg(Name).arg(path));

          }


      }

  delete button;
     }
  */
    return;
}
void Widget::action4_1_slot()//���ò˵�  ͸����+5%
{
    QSqlQuery query;
    query.exec("select * from TRA_DATA");
    query.exec("delete from TRA_DATA");
    if (transparency < 1.0)
    {
        transparency += 0.05;

        query.exec(QString("insert into TRA_DATA values (%1)").arg(transparency));

    }
    ui.frame->setWindowOpacity(transparency);
    ListFocus();
}
void Widget::action4_2_slot()//���ò˵�  ͸����-5%
{
    QSqlQuery query;
    query.exec("select * from TRA_DATA");
    query.exec("delete from TRA_DATA");
    if (transparency > 0.4)
    {
        transparency -= 0.05;
        query.exec(QString("insert into TRA_DATA values (%1)").arg(transparency));

    }
    ui.frame->setWindowOpacity(transparency);
    ListFocus();
}
void Widget::action5_1_slot()//����Ĭ�ϱ�ֽ1
{
    ListFocus();
    QString FileName = ":/image/image/background/bg8.jpg";
    QSqlQuery query;
    query.exec("delete from WALLPAPER_DATA");
    query.exec(QString("insert into WALLPAPER_DATA values('%1')").arg(FileName));
    ui.frame->setStyleSheet(QString("QFrame#frame{border-radius:5px;border-image: url(%1);}").arg(FileName));

}
void Widget::action5_2_slot()//����Ĭ�ϱ�ֽ2
{
    ListFocus();
    QString FileName = ":/image/image/background/bg7.jpg";
    QSqlQuery query;
    query.exec("delete from WALLPAPER_DATA");
    query.exec(QString("insert into WALLPAPER_DATA values('%1')").arg(FileName));
    ui.frame->setStyleSheet(QString("QFrame#frame{border-radius:5px;border-image: url(%1);}").arg(FileName));
}
void Widget::action5_4_slot()
{
    ListFocus();
    QString FileName = ":/image/image/background/bg3.jpg";
    QSqlQuery query;
    query.exec("delete from WALLPAPER_DATA");
    query.exec(QString("insert into WALLPAPER_DATA values('%1')").arg(FileName));
    ui.frame->setStyleSheet(QString("QFrame#frame{border-radius:5px;border-image: url(%1);}").arg(FileName));
}

void Widget::action5_3_slot()//���ò˵�  �����Զ����ֽ
{
    ListFocus();
    QString FileName = QFileDialog::getOpenFileName(this, ("�ļ�"), currentFileName[0], ("ͼƬ�ļ�(*jpg *png)"));
    if (!FileName.isEmpty())
    {
        QString file1 = FileName;
        QString file = FileName.split("//").last();
        currentFileName[0] = file1.remove(file);
        QSqlQuery query;
        query.exec("delete from WALLPAPER_DATA");
        query.exec(QString("insert into WALLPAPER_DATA values('%1')").arg(FileName));
        ui.frame->setStyleSheet(QString("QFrame#frame{border-radius:5px;border-image: url(%1);}").arg(FileName));
    }
}
void Widget::action6_slot()//����  ����
{
    ListFocus();

    QMessageBox::about(this, ("����"), (
        "���� : �ҵ�����                         \n"
        "���� : ������                           \n"
        "���� : �ҵ������Ǹ�������,�������,����,�б�����,\n"
        "ɾ�������ż�¼����ѡ������б��ñ���ģʽ�Ȼ�������,�û��ɰ�ϲ������Ƥ��,����͸����,\n"
        "ʹ�������Ѥ��,֧���Ҽ��˵����б�˵��Ϳ�ݼ�,ʹ�û�����������,\n"
        "����ģʽ,���Խ��л����Ĳ�����ͣ�ȹ���,��С�������,ʹ�����������Ը���\n"));



}
void Widget::action7_slot()//���ò˵�  ʹ��
{
    QMessageBox::about(this, ("ʹ��"), ("�Ҽ� : �˵���               Esc : �˳�����\n"
        "˫�� : �л�������ģʽ         Ctrl-- : ͸���ȼ�\n"
        "�ո� : ������ͣ              Ctrl++ : ͸���ȼ�\n"
        "���Ҽ�/���ּ�6 : ��һ��       Ctrl+Q : �˳�\n"
        "�����/���ּ�4 : ��һ��       Ctrl+V : ��������б�\n"
        "A : �л��б�                Ctrl+O : ����������б�\n"
        "D : �л��б�                Ctrl+A : �������ϲ���б�\n"
        "W : ��������                Ctrl+Z : ������ҵ��ղ�\n"
        "S : ��������                Ctrl+X : �Զ���Ƥ��\n"
        "Q : ��λ                   Ctrl+M : ������и����б�\n"
        "E : �л�����ģʽ             Ctrl+N : �����ϲ���б�\n"
        "R : �����ϲ��              Ctrl+B : ����ҵ��ղ�\n"
        "X : ��ѡ/ȡ����ѡ                              .\n"));

    ListFocus();
}
void Widget::action8_slot()//�������Ҽ��˵� �ر�
{

    QCoreApplication::quit();

}
void Widget::action9_slot()//�������Ҽ��˵� ������һ��
{
    if (ui.listWidget->count() == 0 && ui.listWidget_2->count() == 0 && ui.listWidget_3->count() == 0 && ui.listWidget_4->count() == 0 && ui.listWidget_5->count() == 0) {
        return;
    }
    ListFocus();
    if (music->playlist() == playlist)
    {
        ui.stackedWidget->setCurrentIndex(0);
        pushbuttonstyle();
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

        playlist->setCurrentIndex(currentIndex);
        if (list1[currentIndex] == 0) {
            QListWidgetItem* myitem = new QListWidgetItem(QIcon(":/image/image/nextbo.png"), ui.listWidget_3->item(currentIndex)->text());
            myitem->setToolTip(ui.listWidget_3->item(currentIndex)->text());
            ui.listWidget_5->addItem(myitem);
            playlist_4->addMedia(QUrl::fromLocalFile(FilePath[currentIndex]));
            map.push_back(currentIndex);
            list1[currentIndex]++;
        }
        else
        {
            list1[currentIndex]++;
        }
    }
    else if (music->playlist() == playlist_2)
    {
        ui.stackedWidget->setCurrentIndex(1);
        pushbuttonstyle_2();
        int currentIndex;
        if (playlist_2->playbackMode() == QMediaPlaylist::Random)
        {
            int row = playlist_2->mediaCount();
            currentIndex = qrand() % row;
        }
        else
        {
            currentIndex = playlist_2->currentIndex();

            if (++currentIndex == playlist_2->mediaCount())
            {
                currentIndex = 0;

            }

        }
        playlist_2->setCurrentIndex(currentIndex);
    }
    else if (music->playlist() == playlist_3)
    {

        ui.stackedWidget->setCurrentIndex(2);
        pushbuttonstyle_3();
        int currentIndex;
        if (playlist_3->playbackMode() == QMediaPlaylist::Random)
        {
            int row = playlist_3->mediaCount();
            currentIndex = qrand() % row;
        }
        else
        {
            currentIndex = playlist_3->currentIndex();

            if (++currentIndex == playlist_3->mediaCount())
            {
                currentIndex = 0;

            }

        }
        playlist_3->setCurrentIndex(currentIndex);

    }
    else
    {
        ui.stackedWidget->setCurrentIndex(4);
        pushbuttonstyle_5();
        int currentIndex;
        if (playlist_4->playbackMode() == QMediaPlaylist::Random)
        {
            int row = playlist_4->mediaCount();
            currentIndex = qrand() % row;
        }
        else
        {
            currentIndex = playlist_4->currentIndex();

            if (++currentIndex == playlist_4->mediaCount())
            {
                currentIndex = 0;

            }

        }
        playlist_4->setCurrentIndex(currentIndex);
    }
    music->play();
}
void Widget::action10_slot()//�������Ҽ��˵� ������һ��
{
    if (ui.listWidget->count() == 0 && ui.listWidget_2->count() == 0 && ui.listWidget_3->count() == 0 && ui.listWidget_4->count() == 0 && ui.listWidget_5->count() == 0) {
        return;
    }
    ListFocus();
    if (music->playlist() == playlist)
    {
        ui.stackedWidget->setCurrentIndex(0);
        pushbuttonstyle();
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
        if (list1[currentIndex] == 0) {
            QListWidgetItem* myitem = new QListWidgetItem(QIcon(":/image/image/nextbo.png"), ui.listWidget_3->item(currentIndex)->text());
            myitem->setToolTip(ui.listWidget_3->item(currentIndex)->text());

            ui.listWidget_5->addItem(myitem);
            playlist_4->addMedia(QUrl::fromLocalFile(FilePath[currentIndex]));
            map.push_back(currentIndex);
            list1[currentIndex]++;
        }
        else
        {
            list1[currentIndex]++;
        }
    }
    else if (music->playlist() == playlist_2)
    {

        ui.stackedWidget->setCurrentIndex(1);
        pushbuttonstyle_2();
        int currentIndex;

        if (playlist_2->playbackMode() == QMediaPlaylist::Random)
        {

            int row = playlist_2->mediaCount();
            currentIndex = qrand() % row;
        }
        else
        {
            currentIndex = playlist_2->currentIndex();
            if (--currentIndex < 0)
            {
                currentIndex = 0;
            }
        }
        playlist_2->setCurrentIndex(currentIndex);
    }
    else if (music->playlist() == playlist_3)
    {
        ui.stackedWidget->setCurrentIndex(2);
        pushbuttonstyle_3();
        int currentIndex;
        if (playlist_3->playbackMode() == QMediaPlaylist::Random)
        {
            int row = playlist_3->mediaCount();
            currentIndex = qrand() % row;
        }
        else
        {
            currentIndex = playlist_3->currentIndex();

            if (--currentIndex < 0)
            {
                currentIndex = 0;
            }
        }
        playlist_3->setCurrentIndex(currentIndex);
    }
    else
    {
        ui.stackedWidget->setCurrentIndex(4);
        pushbuttonstyle_5();
        int currentIndex;
        if (playlist_4->playbackMode() == QMediaPlaylist::Random)
        {
            int row = playlist_4->mediaCount();
            currentIndex = qrand() % row;
        }
        else
        {
            currentIndex = playlist_4->currentIndex();

            if (--currentIndex < 0)
            {
                currentIndex = 0;
            }
        }
        playlist_4->setCurrentIndex(currentIndex);

    }
    music->play();
}
void Widget::action11_slot()//��ͣ
{
    if (ui.listWidget->count() == 0 && ui.listWidget_2->count() == 0 && ui.listWidget_3->count() == 0 && ui.listWidget_4->count() == 0 && ui.listWidget_5->count() == 0) {
        return;
    }
    ListFocus();
    music->pause();


}
void Widget::action11_1_slot()//����
{
    if (ui.listWidget->count() == 0 && ui.listWidget_2->count() == 0 && ui.listWidget_3->count() == 0 && ui.listWidget_4->count() == 0 && ui.listWidget_5->count() == 0) {
        return;
    }
    ListFocus();
    music->play();
}
void Widget::action12_1_slot()//�������Ҽ��˵� ˳�򲥷�
{

    ListFocus();
    ui.pushButton_9->setIcon(QIcon(":/image/image/image/loop.png"));
    ui.pushButton_9->setStyleSheet(LoopStyle());
    ui.pushButton_9->setToolTip(("˳�򲥷�"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    playlist_2->setPlaybackMode(QMediaPlaylist::Loop);
    playlist_3->setPlaybackMode(QMediaPlaylist::Loop);

}
void Widget::action12_2_slot()//�������Ҽ��˵� �������
{

    ListFocus();
    ui.pushButton_9->setIcon(QIcon(":/image/image/image/play-random.png"));
    ui.pushButton_9->setToolTip(("�������"));
    ui.pushButton_9->setStyleSheet(RandomStyle());
    playlist->setPlaybackMode(QMediaPlaylist::Random);
    playlist_2->setPlaybackMode(QMediaPlaylist::Random);
    playlist_3->setPlaybackMode(QMediaPlaylist::Random);
}
void Widget::action12_3_slot()//�������Ҽ��˵� ����ѭ��
{

    ListFocus();
    ui.pushButton_9->setIcon(QIcon(":/image/image/image/loop-one.png"));
    ui.pushButton_9->setToolTip(("����ѭ��"));
    ui.pushButton_9->setStyleSheet(LoopOneStyle());
    playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    playlist_2->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    playlist_3->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);

}

void Widget::on_pushButton_2_clicked()//����/��ͣ
{

    if (ui.listWidget->count() == 0 && ui.listWidget_2->count() == 0 && ui.listWidget_3->count() == 0 && ui.listWidget_4->count() == 0 && ui.listWidget_5->count() == 0) {
        return;
    }
    ListFocus();
    if (music->state() == QMediaPlayer::PlayingState)
    {
        ui.pushButton_2->setIcon(QIcon(":/image/image/image/pase.png"));
        ui.pushButton_2->setStyleSheet(PaseStyle());
        ui.pushButton_2->setToolTip(("��ͣ"));
        pause->setToolTip(("��ͣ"));
        pause->setIcon(QIcon(":/image/image/bf13.png"));
        music->pause();



    }
    else
    {
        ui.pushButton_2->setIcon(QIcon(":/image/image/image/play.png"));
        ui.pushButton_2->setStyleSheet(PlayStyle());
        ui.pushButton_2->setToolTip(("����"));
        pause->setToolTip(("����"));
        pause->setIcon(QIcon(":/image/image/zt13.png"));
        music->play();

    }
}

void Widget::on_pushButton_3_clicked()//������һ��
{

    if (ui.listWidget->count() == 0 && ui.listWidget_2->count() == 0 && ui.listWidget_3->count() == 0 && ui.listWidget_4->count() == 0 && ui.listWidget_5->count() == 0) {
        return;
    }
    ListFocus();

    if (music->playlist() == playlist)
    {
        ui.stackedWidget->setCurrentIndex(0);
        pushbuttonstyle();
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
        ui.listWidget_3->scrollToItem(ui.listWidget_3->item(currentIndex));
        playlist->setCurrentIndex(currentIndex);
        if (list1[currentIndex] == 0) {
            QListWidgetItem* myitem = new QListWidgetItem(QIcon(":/image/image/nextbo.png"), ui.listWidget_3->item(currentIndex)->text());
            myitem->setToolTip(ui.listWidget_3->item(currentIndex)->text());

            ui.listWidget_5->addItem(myitem);
            playlist_4->addMedia(QUrl::fromLocalFile(FilePath[currentIndex]));
            map.push_back(currentIndex);
            list1[currentIndex]++;
        }
        else
        {
            list1[currentIndex]++;
        }

    }
    else if (music->playlist() == playlist_2)
    {
        ui.stackedWidget->setCurrentIndex(1);
        pushbuttonstyle_2();
        int currentIndex;
        if (playlist_2->playbackMode() == QMediaPlaylist::Random)
        {
            int row = playlist_2->mediaCount();
            currentIndex = qrand() % row;
        }
        else
        {
            currentIndex = playlist_2->currentIndex();

            if (++currentIndex == playlist_2->mediaCount())
            {
                currentIndex = 0;

            }

        }
        ui.listWidget_2->scrollToItem(ui.listWidget_2->item(currentIndex));
        playlist_2->setCurrentIndex(currentIndex);
    }
    else if (music->playlist() == playlist_3)
    {

        ui.stackedWidget->setCurrentIndex(2);
        pushbuttonstyle_3();
        int currentIndex;
        if (playlist_3->playbackMode() == QMediaPlaylist::Random)
        {
            int row = playlist_3->mediaCount();
            currentIndex = qrand() % row;
        }
        else
        {
            currentIndex = playlist_3->currentIndex();

            if (++currentIndex == playlist_3->mediaCount())
            {
                currentIndex = 0;

            }

        }
        ui.listWidget->scrollToItem(ui.listWidget->item(currentIndex));
        playlist_3->setCurrentIndex(currentIndex);

    }
    else
    {
        ui.stackedWidget->setCurrentIndex(4);
        pushbuttonstyle_5();
        int currentIndex;
        if (playlist_4->playbackMode() == QMediaPlaylist::Random)
        {
            int row = playlist_4->mediaCount();
            currentIndex = qrand() % row;
        }
        else
        {
            currentIndex = playlist_4->currentIndex();

            if (--currentIndex < 0)
            {
                currentIndex = 0;
            }
        }
        ui.listWidget_4->scrollToItem(ui.listWidget_4->item(currentIndex));
        playlist_4->setCurrentIndex(currentIndex);

    }
    music->play();

}

void Widget::on_pushButton_4_clicked()//������һ��
{
    if (ui.listWidget->count() == 0 && ui.listWidget_2->count() == 0 && ui.listWidget_3->count() == 0 && ui.listWidget_4->count() == 0 && ui.listWidget_5->count() == 0) {
        return;
    }
    ListFocus();

    if (music->playlist() == playlist)
    {
        ui.stackedWidget->setCurrentIndex(0);
        pushbuttonstyle();
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
        ui.listWidget_3->scrollToItem(ui.listWidget_3->item(currentIndex));
        playlist->setCurrentIndex(currentIndex);
        if (list1[currentIndex] == 0) {
            QListWidgetItem* myitem = new QListWidgetItem(QIcon(":/image/image/nextbo.png"), ui.listWidget_3->item(currentIndex)->text());
            myitem->setToolTip(ui.listWidget_3->item(currentIndex)->text());

            ui.listWidget_5->addItem(myitem);
            playlist_4->addMedia(QUrl::fromLocalFile(FilePath[currentIndex]));
            map.push_back(currentIndex);
            list1[currentIndex]++;
        }
        else
        {
            list1[currentIndex]++;
        }
    }
    else if (music->playlist() == playlist_2)
    {

        ui.stackedWidget->setCurrentIndex(1);
        pushbuttonstyle_2();
        int currentIndex;

        if (playlist_2->playbackMode() == QMediaPlaylist::Random)
        {

            int row = playlist_2->mediaCount();
            currentIndex = qrand() % row;
        }
        else
        {
            currentIndex = playlist_2->currentIndex();
            if (--currentIndex < 0)
            {
                currentIndex = 0;
            }
        }
        ui.listWidget_2->scrollToItem(ui.listWidget_2->item(currentIndex));
        playlist_2->setCurrentIndex(currentIndex);
    }
    else if (music->playlist() == playlist_3)
    {
        ui.stackedWidget->setCurrentIndex(2);
        pushbuttonstyle_3();
        int currentIndex;
        if (playlist_3->playbackMode() == QMediaPlaylist::Random)
        {
            int row = playlist_3->mediaCount();
            currentIndex = qrand() % row;
        }
        else
        {
            currentIndex = playlist_3->currentIndex();

            if (--currentIndex < 0)
            {
                currentIndex = 0;
            }
        }
        ui.listWidget->scrollToItem(ui.listWidget->item(currentIndex));
        playlist_3->setCurrentIndex(currentIndex);
    }
    else
    {
        ui.stackedWidget->setCurrentIndex(4);
        pushbuttonstyle_5();
        int currentIndex;
        if (playlist_4->playbackMode() == QMediaPlaylist::Random)
        {
            int row = playlist_4->mediaCount();
            currentIndex = qrand() % row;
        }
        else
        {
            currentIndex = playlist_4->currentIndex();

            if (--currentIndex < 0)
            {
                currentIndex = 0;
            }
        }
        ui.listWidget_4->scrollToItem(ui.listWidget_4->item(currentIndex));
        playlist_4->setCurrentIndex(currentIndex);

    }
    music->play();
}
void Widget::updatalistwidget_3(int value)//����listWidget_3
{

    if (ui.listWidget_3->selectionMode() == QListWidget::SingleSelection)
    {
        ui.listWidget_3->item(value)->setSelected(true);
        int currentIndex = value;
        if (list1[currentIndex] == 0) {
            QListWidgetItem* myitem = new QListWidgetItem(QIcon(":/image/image/nextbo.png"), ui.listWidget_3->item(currentIndex)->text());
            myitem->setToolTip(ui.listWidget_3->item(currentIndex)->text());

            ui.listWidget_5->addItem(myitem);
            playlist_4->addMedia(QUrl::fromLocalFile(FilePath[currentIndex]));
            map.push_back(currentIndex);
            list1[currentIndex]++;
        }
        else
        {
            list1[currentIndex]++;
        }
    }

}
void Widget::updatalistwidget_2(int value)//����listWidget_2
{

    if (ui.listWidget_2->selectionMode() == QListWidget::SingleSelection)
        ui.listWidget_2->item(value)->setSelected(true);


}
void Widget::updatalistwidget(int value)//����listWidget
{

    if (ui.listWidget->selectionMode() == QListWidget::SingleSelection)
        ui.listWidget->item(value)->setSelected(true);

}

void Widget::on_listWidget_3_doubleClicked(const QModelIndex& index)//˫������playlist ���������б�
{

    if (ui.listWidget_3->selectionMode() == QListWidget::SingleSelection)
    {
        music->setPlaylist(playlist);
        int currentIndex = index.row();
        playlist->setCurrentIndex(currentIndex);
        music->play();
        if (list1[currentIndex] == 0) {
            QListWidgetItem* myitem = new QListWidgetItem(QIcon(":/image/image/nextbo.png"), ui.listWidget_3->item(currentIndex)->text());
            myitem->setToolTip(ui.listWidget_3->item(currentIndex)->text());

            ui.listWidget_5->addItem(myitem);
            playlist_4->addMedia(QUrl::fromLocalFile(FilePath[currentIndex]));
            map.push_back(currentIndex);
            list1[currentIndex]++;
        }
        else
        {
            list1[currentIndex]++;
        }
    }
}
void Widget::music_stateChang(QMediaPlayer::State state)//����״̬�ı�
{


    if (state == QMediaPlayer::PlayingState)
    {
        ui.pushButton_2->setIcon(QIcon(":/image/image/image/play.png"));
        ui.pushButton_2->setToolTip(("����"));
        ui.pushButton_2->setStyleSheet(PlayStyle());
        pause->setToolTip(("����"));
        pause->setIcon(QIcon(":/image/image/zt13.png"));

        TaskProgress->show();
        TaskProgress->resume();

    }
    else
    {

        ui.pushButton_2->setIcon(QIcon(":/image/image/image/pase.png"));
        ui.pushButton_2->setToolTip(("��ͣ"));
        ui.pushButton_2->setStyleSheet(PaseStyle());
        pause->setToolTip(("��ͣ"));
        pause->setIcon(QIcon(":/image/image/bf13.png"));

        TaskProgress->show();
        TaskProgress->pause();
    }
}

void Widget::on_pushButton_15_clicked()//����stackedWidget
{
    if (ui.listWidget->count() == 0 && ui.listWidget_2->count() == 0 && ui.listWidget_3->count() == 0 && ui.listWidget_4->count() == 0 && ui.listWidget_5->count() == 0) {
        return;
    }
    QPropertyAnimation* AnimationForLabel3 = new QPropertyAnimation(ui.label_3, "geometry");
    QPropertyAnimation* AnimationForLabel4 = new QPropertyAnimation(ui.label_4, "geometry");
    QPropertyAnimation* AnimationForLabel = new QPropertyAnimation(ui.label, "geometry");
    QPropertyAnimation* AnimationForPushButton = new QPropertyAnimation(ui.pushButton_15, "geometry");


    QPropertyAnimation* AnimationForPushButton1 = new QPropertyAnimation(ui.pushButton_10, "geometry");
    QPropertyAnimation* AnimationForPushButton2 = new QPropertyAnimation(ui.pushButton_11, "geometry");
    QPropertyAnimation* AnimationForPushButton3 = new QPropertyAnimation(ui.pushButton_12, "geometry");
    QPropertyAnimation* AnimationForPushButton4 = new QPropertyAnimation(ui.pushButton_22, "geometry");

    // QPropertyAnimation *AnimationForStactWidget = new QPropertyAnimation(ui.stackedWidget,"windowOpacity");

    AnimationForLabel3->setDuration(1000);
    AnimationForLabel4->setDuration(1000);
    AnimationForLabel->setDuration(1000);
    //AnimationForStactWidget->setDuration(500);
    AnimationForPushButton->setDuration(900);
    AnimationForPushButton1->setDuration(500);
    AnimationForPushButton2->setDuration(600);
    AnimationForPushButton3->setDuration(700);
    AnimationForPushButton4->setDuration(800);
    if (ui.stackedWidget->isHidden())
    {
        ListFocus();
        ui.pushButton_15->setIcon(QIcon(":/image/image/image/left.png"));
        ui.pushButton_15->setStyleSheet(HideListStyle());
        ui.pushButton_15->setToolTip(("���ز����б�"));
        ui.stackedWidget->show();



        //        ui.pushButton_10->show();
        //        ui.pushButton_11->show();
        //        ui.pushButton_12->show();
        //        ui.pushButton_22->show();


        //        AnimationForStactWidget->setKeyValueAt(0,0);
        //        AnimationForStactWidget->setKeyValueAt(1,1);
        //        AnimationForStactWidget->setEasingCurve(QEasingCurve::InBounce);

        AnimationForLabel->setStartValue(QRect(250, 600, 510, 32));
        AnimationForLabel->setEndValue(QRect(370, 600, 510, 32));
        AnimationForLabel->setEasingCurve(QEasingCurve::InBounce);

        AnimationForLabel3->setStartValue(QRect(200, 390, 510, 32));
        AnimationForLabel3->setEndValue(QRect(400, 390, 510, 32));
        AnimationForLabel3->setEasingCurve(QEasingCurve::InBounce);

        AnimationForLabel4->setStartValue(QRect(600, 450, 450, 32));
        AnimationForLabel4->setEndValue(QRect(670, 450, 450, 32));
        AnimationForLabel4->setEasingCurve(QEasingCurve::InBounce);

        AnimationForPushButton->setStartValue(QRect(10, 60, 32, 32));
        AnimationForPushButton->setEndValue(QRect(320, 60, 32, 32));
        AnimationForPushButton->setEasingCurve(QEasingCurve::InBounce);


        AnimationForPushButton1->setStartValue(QRect(-32, 60, 32, 32));
        AnimationForPushButton1->setEndValue(QRect(10, 60, 32, 32));
        AnimationForPushButton1->setEasingCurve(QEasingCurve::InBounce);



        AnimationForPushButton2->setStartValue(QRect(-32, 60, 32, 32));
        AnimationForPushButton2->setEndValue(QRect(80, 60, 32, 32));
        AnimationForPushButton2->setEasingCurve(QEasingCurve::InBounce);

        AnimationForPushButton3->setStartValue(QRect(-32, 60, 32, 32));
        AnimationForPushButton3->setEndValue(QRect(160, 60, 32, 32));
        AnimationForPushButton3->setEasingCurve(QEasingCurve::InBounce);

        AnimationForPushButton4->setStartValue(QRect(-32, 60, 32, 32));
        AnimationForPushButton4->setEndValue(QRect(240, 60, 32, 32));
        AnimationForPushButton4->setEasingCurve(QEasingCurve::InBounce);


        AnimationForLabel->start();
        AnimationForLabel3->start();
        AnimationForLabel4->start();
        AnimationForPushButton->start();
        AnimationForPushButton1->start();
        AnimationForPushButton2->start();
        AnimationForPushButton3->start();
        AnimationForPushButton4->start();



    }
    else
    {

        ui.pushButton_15->setIcon(QIcon(":/image/image/image/right.png"));
        ui.pushButton_15->setToolTip(("��ʾ�����б�"));
        ui.pushButton_15->setStyleSheet(ShowListStyle());
        ui.stackedWidget->hide();
        //        ui.pushButton_10->hide();
        //        ui.pushButton_11->hide();
        //        ui.pushButton_12->hide();
        //        ui.pushButton_22->hide();

        //        AnimationForStactWidget->setKeyValueAt(0,1);
        //        AnimationForStactWidget->setKeyValueAt(1,0);
        //        AnimationForStactWidget->setEasingCurve(QEasingCurve::InBounce);

        AnimationForLabel->setStartValue(QRect(370, 600, 510, 32));
        AnimationForLabel->setEndValue(QRect(250, 600, 510, 32));
        AnimationForLabel->setEasingCurve(QEasingCurve::InBounce);


        AnimationForLabel3->setStartValue(QRect(400, 390, 510, 32));
        AnimationForLabel3->setEndValue(QRect(200, 390, 510, 32));
        AnimationForLabel3->setEasingCurve(QEasingCurve::InBounce);


        AnimationForLabel4->setStartValue(QRect(670, 450, 450, 32));
        AnimationForLabel4->setEndValue(QRect(600, 450, 450, 32));
        AnimationForLabel4->setEasingCurve(QEasingCurve::InBounce);


        AnimationForPushButton->setStartValue(QRect(320, 60, 32, 32));
        AnimationForPushButton->setEndValue(QRect(10, 60, 32, 32));
        AnimationForPushButton->setEasingCurve(QEasingCurve::InBounce);

        AnimationForPushButton1->setStartValue(QRect(10, 60, 32, 32));
        AnimationForPushButton1->setEndValue(QRect(-32, 60, 32, 32));
        AnimationForPushButton1->setEasingCurve(QEasingCurve::InBounce);



        AnimationForPushButton2->setStartValue(QRect(80, 60, 32, 32));
        AnimationForPushButton2->setEndValue(QRect(-32, 60, 32, 32));
        AnimationForPushButton2->setEasingCurve(QEasingCurve::InBounce);

        AnimationForPushButton3->setStartValue(QRect(160, 60, 32, 32));
        AnimationForPushButton3->setEndValue(QRect(-32, 60, 32, 32));
        AnimationForPushButton3->setEasingCurve(QEasingCurve::InBounce);

        AnimationForPushButton4->setStartValue(QRect(240, 60, 32, 32));
        AnimationForPushButton4->setEndValue(QRect(-32, 60, 32, 32));
        AnimationForPushButton4->setEasingCurve(QEasingCurve::InBounce);

        AnimationForLabel->start();
        AnimationForLabel3->start();
        AnimationForLabel4->start();
        AnimationForPushButton->start();
        AnimationForPushButton1->start();
        AnimationForPushButton2->start();
        AnimationForPushButton3->start();
        AnimationForPushButton4->start();

    }
}

void Widget::on_pushButton_9_clicked()//����ģʽ
{

    ListFocus();
    if (playlist->playbackMode() == QMediaPlaylist::Loop)
    {

        ui.pushButton_9->setIcon(QIcon(":/image/image/image/play-random.png"));
        ui.pushButton_9->setStyleSheet(RandomStyle());
        ui.pushButton_9->setToolTip(("�������"));
        playlist->setPlaybackMode(QMediaPlaylist::Random);
        playlist_2->setPlaybackMode(QMediaPlaylist::Random);
        playlist_3->setPlaybackMode(QMediaPlaylist::Random);
    }
    else if (playlist->playbackMode() == QMediaPlaylist::Random)
    {
        ui.pushButton_9->setIcon(QIcon(":/image/image/image/loop-one.png"));
        ui.pushButton_9->setStyleSheet(LoopOneStyle());
        ui.pushButton_9->setToolTip(("����ѭ��"));
        playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
        playlist_2->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
        playlist_3->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);


    }
    else if (playlist->playbackMode() == QMediaPlaylist::CurrentItemInLoop)
    {
        ui.pushButton_9->setIcon(QIcon(":/image/image/image/loop.png"));
        ui.pushButton_9->setStyleSheet(LoopStyle());
        ui.pushButton_9->setToolTip(("˳�򲥷�"));
        playlist->setPlaybackMode(QMediaPlaylist::Loop);
        playlist_2->setPlaybackMode(QMediaPlaylist::Loop);
        playlist_3->setPlaybackMode(QMediaPlaylist::Loop);

    }

}

void Widget::on_listWidget_2_doubleClicked(const QModelIndex& index)//˫������playlist_2 ��ϲ���б�
{

    if (ui.listWidget_2->selectionMode() == QListWidget::SingleSelection)
    {
        music->setPlaylist(playlist_2);
        int row = index.row();
        playlist_2->setCurrentIndex(row);
        music->play();
    }


}


void Widget::on_listWidget_doubleClicked(const QModelIndex& index)//˫������playlist_3 �ҵ��ղ�
{

    if (ui.listWidget->selectionMode() == QListWidget::SingleSelection)
    {
        music->setPlaylist(playlist_3);
        int row = index.row();
        playlist_3->setCurrentIndex(row);

        music->play();
    }


}
void Widget::on_pushButton_7_clicked()//������λ
{


    if (ui.listWidget->count() == 0 && ui.listWidget_2->count() == 0 && ui.listWidget_3->count() == 0 && ui.listWidget_4->count() == 0 && ui.listWidget_5->count() == 0) {
        return;
    }

    if (music->playlist() == playlist)
    {
        if (ui.listWidget_3->count() == 0) {
            return;
        }
        else {
            ui.stackedWidget->setCurrentIndex(0);
            ui.listWidget_3->setFocus();
            pushbuttonstyle();
            if (ui.listWidget_3->selectionMode() == QListWidget::SingleSelection)
            {
                ui.listWidget_3->item(playlist->currentIndex())->setSelected(true);
                ui.listWidget_3->scrollToItem(ui.listWidget_3->item(playlist->currentIndex()));
            }
        }
    }
    else if (music->playlist() == playlist_2)
    {
        if (ui.listWidget_2->count() == 0) {
            return;
        }
        else {
            ui.stackedWidget->setCurrentIndex(1);
            ui.listWidget_2->setFocus();
            pushbuttonstyle_2();
            if (ui.listWidget_2->selectionMode() == QListWidget::SingleSelection)
            {
                ui.listWidget_2->item(playlist_2->currentIndex())->setSelected(true);
                ui.listWidget_2->scrollToItem(ui.listWidget_2->item(playlist_2->currentIndex()));
            }
        }

    }
    else if (music->playlist() == playlist_3)
    {

        if (ui.listWidget->count() == 0) {
            return;
        }
        else {
            ui.stackedWidget->setCurrentIndex(2);
            ui.listWidget->setFocus();
            pushbuttonstyle_3();
            if (ui.listWidget->selectionMode() == QListWidget::SingleSelection)
            {
                ui.listWidget->item(playlist_3->currentIndex())->setSelected(true);
                ui.listWidget->scrollToItem(ui.listWidget->item(playlist_3->currentIndex()));

            }
        }
    }
    else
    {
        if (ui.listWidget_5->count() == 0) {
            return;
        }
        else {
            ui.stackedWidget->setCurrentIndex(4);
            ui.listWidget_5->setFocus();
            pushbuttonstyle_5();

            ui.listWidget_5->item(playlist_4->currentIndex())->setSelected(true);
            ui.listWidget_5->scrollToItem(ui.listWidget_5->item(playlist_4->currentIndex()));


        }
    }
}
void Widget::mousePressEvent(QMouseEvent* event)//��ק �ƶ�����
{

    ListFocus();
    offset = event->globalPos() - pos();
    event->accept();
    ui.verticalSlider->hide();
    setFocus();
    if (event->button() == Qt::LeftButton)
        setCursor(Qt::OpenHandCursor);


}
void Widget::mouseMoveEvent(QMouseEvent* event)//��ק �ƶ�����
{
    ListFocus();
    move(event->globalPos() - offset);
    event->accept();
    setCursor(Qt::ClosedHandCursor);


}
void Widget::mouseReleaseEvent(QMouseEvent* event)//��ק �ƶ�����
{
    ListFocus();
    offset = QPoint();
    event->accept();
    setCursor(Qt::ArrowCursor);

}
void Widget::mouseDoubleClickEvent(QMouseEvent*)//˫���л�������ģʽ
{
    setCursor(Qt::ArrowCursor);

    hide();
    int i;
    if (music->playlist() == playlist)
    {
        i = 0;
    }
    else if (music->playlist() == playlist_2)
    {
        i = 1;
    }
    else if (music->playlist() == playlist_3)
    {
        i = 2;
    }
    else
    {
        i = 3;
    }
    Music->setPlaylist(music->playlist(), music->playlist()->currentIndex(), music->position(), music->volume(), music->state(), playlist->playbackMode(), i);
    music->pause();
    if (Music->exec() == Dialog::Accepted)
    {
        ListFocus();
        show();
    }

}

void Widget::contextMenuEvent(QContextMenuEvent*)//�������Ҽ��˵�
{

    ListFocus();
    menu = new QMenu(this);
    menu->setStyleSheet(
        MenuStyle()

    );
    menu->addAction(add);
    menu->addAction(action9);
    menu->addAction(action10);
    if (music->state() == QMediaPlayer::PlayingState)

    {
        menu->addAction(action11);

    }
    else
    {

        menu->addAction(action11_1);
    }
    menu->addAction(ClearALL_3);
    menu->addAction(action12);
    menu->addAction(action5);
    menu->addAction(ClearALL);
    menu->addAction(location);
    menu->addAction(detila);
    menu->addAction(action13);
    menu->exec(QCursor::pos());

}

void Widget::on_pushButton_17_clicked()//�ر�
{
    QCoreApplication::quit();
}

void Widget::on_pushButton_16_clicked()//��С��
{
    ListFocus();
    showMinimized();

}

void Widget::on_pushButton_8_clicked()//����verticalSlider
{
    ListFocus();

    if (ui.verticalSlider->isHidden())
        ui.verticalSlider->show();
    else
    {
        ui.verticalSlider->hide();
    }

}
void Widget::changeVolume(int values)//�ı�����
{
    if (values == 0)
    {

        ui.pushButton_8->setIcon(QIcon(":/image/image/image/none-music.png"));
        ui.pushButton_8->setStyleSheet(NoVoiceStyle());
    }
    else
    {
        ui.pushButton_8->setIcon(QIcon(":/image/image/music-voice.png"));
        ui.pushButton_8->setStyleSheet(VoiceStyle());

    }
    music->setVolume(values);

}

void Widget::on_listWidget_3_customContextMenuRequested(const QPoint& pos)//listWidget_3�Ҽ��˵� ���������б�
{
    if (ui.listWidget_3->itemAt(pos) == NULL)
    {
        return;
    }
    QMenu* Menu = new QMenu(this);
    Menu->setStyleSheet(
        MenuStyle()

    );
    QAction* Action1 = new QAction(this);//����
    QAction* Action1_1 = new QAction(this);//��ͣ
    QAction* Action2 = new QAction(this);//�������ϲ��
    QAction* Action4 = new QAction(this);//������ҵ��ղ�
    QAction* Action3 = new QAction(this);//��ѡ
    QAction* Action5 = new QAction(this);//ȡ����ѡ
    QAction* Action7 = new QAction(this);//ɾ��
    QAction* Action8 = new QAction(this);//������Ϣ
    Action1->setIcon(QIcon(":/image/image/zt13.png"));
    Action1->setText(("����"));
    Action1_1->setIcon(QIcon(":/image/image/bofang1.png"));
    Action1_1->setText(("��ͣ"));
    Action2->setIcon(QIcon(":/image/image/like_outline_32px_1170275_easyicon.net.png"));
    Action2->setText(("�������ϲ��"));
    Action4->setIcon(QIcon(":/image/image/list_32px_1142913_easyicon.net.png"));
    Action4->setText(("������ҵ��ղ�"));
    Action7->setIcon(QIcon(":/image/image/duoxuan.png"));
    Action7->setText(("��ѡ"));
    Action8->setIcon(QIcon(":/image/image/quxiao.png"));
    Action8->setText(("ȡ����ѡ"));
    Action3->setIcon(QIcon(":/image/image/delete_32px_1168909_easyicon.net.png"));
    Action3->setText(("ɾ��"));
    Action5->setIcon(QIcon(":/image/image/inf.png"));
    Action5->setText(("������Ϣ"));
    connect(Action1, &QAction::triggered, this, &Widget::Action1_slot);
    connect(Action1_1, &QAction::triggered, this, &Widget::action11_slot);
    connect(Action2, &QAction::triggered, this, &Widget::Action2_slot);
    connect(Action4, &QAction::triggered, this, &Widget::Action4_slot);
    connect(Action3, &QAction::triggered, this, &Widget::Action3_slot);
    connect(Action5, &QAction::triggered, this, &Widget::Action5_slot);
    connect(Action7, &QAction::triggered, this, &Widget::Action7_slot);
    connect(Action8, &QAction::triggered, this, &Widget::Action8_slot);
    if (ui.listWidget_3->selectionMode() == QListWidget::SingleSelection)
    {
        if (music->playlist() == playlist)
        {
            if (ui.listWidget_3->currentIndex().row() == playlist->currentIndex())
            {
                if (music->state() == QMediaPlayer::PlayingState)
                {
                    Menu->addAction(Action1_1);
                }
                else
                {
                    Menu->addAction(Action1);

                }
            }
            else
            {

                Menu->addAction(Action1);
            }

        }
        else
        {
            Menu->addAction(Action1);
        }

        Menu->addAction(Action2);
        Menu->addAction(Action4);
        Menu->addAction(Action7);
        Menu->addAction(Action5);
        Menu->addAction(Action3);
    }
    else if (ui.listWidget_3->selectionMode() == QListWidget::MultiSelection)
    {
        Menu->addAction(Action2);
        Menu->addAction(Action4);
        Menu->addAction(Action8);
        Menu->addAction(Action3);
    }
    Menu->exec(QCursor::pos());
    delete Menu;
    delete Action1;
    delete Action2;
    delete Action3;
    delete Action4;
    delete Action5;
    delete Action7;
    delete Action8;
    delete Action1_1;

}
void Widget::Action1_slot()//listWidget_3�Ҽ��˵� ���Ÿ���
{

    if (music->playlist() == playlist)
    {

        if (ui.listWidget_3->currentIndex().row() == playlist->currentIndex())
        {

            music->play();

        }
        else
        {

            playlist->setCurrentIndex(ui.listWidget_3->currentIndex().row());
            music->play();
        }
        int currentIndex = ui.listWidget_3->currentIndex().row();
        if (list1[currentIndex] == 0) {
            QListWidgetItem* myitem = new QListWidgetItem(QIcon(":/image/image/nextbo.png"), ui.listWidget_3->item(currentIndex)->text());
            myitem->setToolTip(ui.listWidget_3->item(currentIndex)->text());

            ui.listWidget_5->addItem(myitem);
            playlist_4->addMedia(QUrl::fromLocalFile(FilePath[currentIndex]));
            map.push_back(currentIndex);
            list1[currentIndex]++;
        }
        else
        {
            list1[currentIndex]++;
        }


    }
    else
    {
        music->setPlaylist(playlist);
        playlist->setCurrentIndex(ui.listWidget_3->currentIndex().row());
        int currentIndex = ui.listWidget_3->currentIndex().row();
        if (list1[currentIndex] == 0) {
            QListWidgetItem* myitem = new QListWidgetItem(QIcon(":/image/image/nextbo.png"), ui.listWidget_3->item(currentIndex)->text());
            myitem->setToolTip(ui.listWidget_3->item(currentIndex)->text());

            ui.listWidget_5->addItem(myitem);
            playlist_4->addMedia(QUrl::fromLocalFile(FilePath[currentIndex]));
            map.push_back(currentIndex);
            list1[currentIndex]++;
        }
        else
        {
            list1[currentIndex]++;
        }
        music->play();
    }

}
void Widget::Action2_slot()//listWidget_3�Ҽ��˵� �������ϲ��
{
    if (ui.listWidget_3->selectionMode() == QListWidget::SingleSelection)
    {
        model->setTable("LocalMusic");
        model->select();
        int row = ui.listWidget_3->currentIndex().row();
        int flag = model->data(model->index(row, 3)).toInt();
        if (flag == 0)
        {
            QString Text = ui.listWidget_3->item(row)->text();
            QListWidgetItem* ITEMM = new QListWidgetItem;
            ITEMM->setIcon(QIcon(":/image/image/like_outline_32px_1101681_easyicon.net.png"));
            ITEMM->setText(QString("%1").arg(Text));
            ITEMM->setToolTip(Text);


            ui.listWidget_2->addItem(ITEMM);

            QSqlQuery query;
            playlist_2->addMedia(playlist->media(row));
            model->setTable("LocalMusic");
            model->select();
            QString MusicName = model->data(model->index(row, 1)).toString();
            QString FileName = model->data(model->index(row, 2)).toString();
            model->setTable("LocalMusic");
            model->select();
            model->setData(model->index(row, 3), 1);
            model->submitAll();
            query.exec("select * from LikeMusic");
            query.exec(QString("insert into LikeMusic values (%1,'%2','%3')").arg(qrand() % 10000000).arg(MusicName).arg(FileName));
            ui.stackedWidget->setCurrentIndex(1);
            pushbuttonstyle_2();
            if (music->playlist() == playlist)
            {

                if (playlist->currentIndex() == row)
                {
                    ui.pushButton_14->setIcon(QIcon(":/image/image/image/Ilike1.png"));
                    ui.pushButton_14->setStyleSheet(Ilike1Style());
                    ui.pushButton_14->setToolTip(("��ϲ��"));
                }

            }
        }
        else
        {

            QMessageBox::information(this, ("��ʾ"), ("�ø��������                              ."), QMessageBox::Yes);

        }
    }
    else if (ui.listWidget_3->selectionMode() == QListWidget::MultiSelection)
    {
        ui.stackedWidget->setCurrentIndex(1);
        pushbuttonstyle_2();
        model->setTable("LocalMusic");
        model->select();
        QList<QListWidgetItem*> items;
        items = ui.listWidget_3->selectedItems();
        if (items.size() == 0)
        {
            return;
        }
        QProgressDialog* progressdialog = new QProgressDialog(this);
        progressdialog->setWindowModality(Qt::WindowModal);
        progressdialog->setMinimumDuration(100);
        progressdialog->resize(400, 120);
        progressdialog->setMinimumSize(400, 120);
        progressdialog->setMaximumSize(400, 120);
        progressdialog->setMinimumDuration(100);
        progressdialog->setWindowTitle(("�������ϲ��"));
        progressdialog->setLabelText(("�������,���Ժ�."));
        QPushButton* button = new QPushButton(this);
        QPixmap pixmap;
        pixmap.load(":/image/image/58d4d135e7bce713bd501050.jpg");
        QPalette palette;
        palette.setBrush(QPalette::Window, QBrush(pixmap.scaled(progressdialog->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
        progressdialog->setPalette(palette);
        button->setStyleSheet("QPushButton{"

            "background-color: rgba(122, 122, 122,100);"
            "border-style:outset;"
            "border-width: 1px;"
            "border-radius: 10px;"
            "border-color: rgba(122, 122, 122,100);"
            "font: bold 14px;"
            "color :rgba(0,0,0,100);"
            "padding: 6px;"

            "}"
            "QPushButton:hover{"



            "background-color: rgba(176, 58, 176,200);"
            "color: rgba(0,0,0,200);"


            "}"
            "QPushButton:pressed{"


            "background-color:  rgba(255,255,255,150);"
            "border-color:rgba(255,255,255,150);"
            "border-style:inset;"
            "color:rgba(0,0,0,100);"

            "}");
        button->setText(("�ر�"));
        progressdialog->setCancelButton(button);
        progressdialog->setRange(0, items.size() - 1);
        progressdialog->setStyleSheet("QProgressBar{border: 1px solid grey;border-radius: 5px;text-align: center;background-color:rgba(255,255,255,150);}"
            "QProgressBar::chunk{background-color: #CD96CD;width: 10px;margin: 0.5px;}");

        for (int i = 0; i < items.size(); i++)
        {

            if (i == items.size() - 1)
            {
                progressdialog->close();
            }
            if (!progressdialog->wasCanceled())
            {
                progressdialog->setValue(i);

            }
            else
            {
                progressdialog->close();
            }
            int row = ui.listWidget_3->row(items.at(i));
            int flag = model->data(model->index(row, 3)).toInt();
            if (flag == 0)
            {
                QString Text = ui.listWidget_3->item(row)->text();
                QListWidgetItem* ITEMM1 = new QListWidgetItem;
                ITEMM1->setIcon(QIcon(":/image/image/like_outline_32px_1101681_easyicon.net.png"));
                ITEMM1->setText(QString("%1").arg(Text));
                ITEMM1->setToolTip(Text);

                ui.listWidget_2->addItem(ITEMM1);

                QSqlQuery query;
                playlist_2->addMedia(playlist->media(row));
                model->setTable("LocalMusic");
                model->select();
                QString MusicName = model->data(model->index(row, 1)).toString();
                QString FileName = model->data(model->index(row, 2)).toString();
                model->setTable("LocalMusic");
                model->select();
                model->setData(model->index(row, 3), 1);
                model->submitAll();
                query.exec("select * from LikeMusic");
                query.exec(QString("insert into LikeMusic values (%1,'%2','%3')").arg(qrand() % 10000000).arg(MusicName).arg(FileName));
                if (music->playlist() == playlist)
                {

                    if (playlist->currentIndex() == row)
                    {
                        ui.pushButton_14->setIcon(QIcon(":/image/image/image/Ilike1.png"));
                        ui.pushButton_14->setStyleSheet(Ilike1Style());
                        ui.pushButton_14->setToolTip(("��ϲ��"));
                    }

                }
            }

        }
        delete button;

        ui.listWidget_3->setSelectionMode(QListWidget::SingleSelection);



    }
}
void Widget::Action4_slot()//listWidget_3�Ҽ��˵� ������ҵ��ղ�
{


    if (ui.listWidget_3->selectionMode() == QListWidget::SingleSelection)
    {
        int row = ui.listWidget_3->currentIndex().row();
        QString Text = ui.listWidget_3->item(row)->text();
        QListWidgetItem* ITEMM1 = new QListWidgetItem;
        ITEMM1->setIcon(QIcon(":/image/image/music_not_25.570093457944px_1171234_easyicon.net.png"));
        ITEMM1->setText(QString("%1").arg(Text));
        ITEMM1->setToolTip(Text);

        ui.listWidget->addItem(ITEMM1);

        model->setTable("LocalMusic");
        model->select();
        playlist_3->addMedia(playlist->media(row));
        QSqlQuery query;
        QString MusicName = model->data(model->index(row, 1)).toString();
        QString FileName = model->data(model->index(row, 2)).toString();

        query.exec("select * from  CollectMusic");
        query.exec(QString("insert into  CollectMusic values (%1,'%2','%3')").arg(qrand() % 10000000).arg(MusicName).arg(FileName));
        ui.stackedWidget->setCurrentIndex(2);
        pushbuttonstyle_3();
    }
    else if (ui.listWidget_3->selectionMode() == QListWidget::MultiSelection)
    {
        ui.stackedWidget->setCurrentIndex(2);
        pushbuttonstyle_3();
        QList<QListWidgetItem*> items;
        items = ui.listWidget_3->selectedItems();
        if (items.size() == 0)
        {
            return;
        }
        QProgressDialog* progressdialog = new QProgressDialog(this);
        progressdialog->setWindowModality(Qt::WindowModal);
        progressdialog->resize(400, 120);
        progressdialog->setMinimumSize(400, 120);
        progressdialog->setMaximumSize(400, 120);
        progressdialog->setMinimumDuration(100);
        progressdialog->setWindowTitle(("������ҵ��ղ�"));
        progressdialog->setLabelText(("�������,���Ժ�."));
        QPushButton* button = new QPushButton(this);
        QPixmap pixmap;
        pixmap.load(":/image/image/58d4d135e7bce713bd501050.jpg");
        QPalette palette;
        palette.setBrush(QPalette::Window, QBrush(pixmap.scaled(progressdialog->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
        progressdialog->setPalette(palette);
        button->setStyleSheet("QPushButton{"

            "background-color: rgba(122, 122, 122,100);"
            "border-style:outset;"
            "border-width: 1px;"
            "border-radius: 10px;"
            "border-color: rgba(122, 122, 122,100);"
            "font: bold 14px;"
            "color :rgba(0,0,0,100);"
            "padding: 6px;"

            "}"
            "QPushButton:hover{"



            "background-color: rgba(176, 58, 176,200);"
            "color: rgba(0,0,0,200);"


            "}"
            "QPushButton:pressed{"


            "background-color:  rgba(255,255,255,150);"
            "border-color:rgba(255,255,255,150);"
            "border-style:inset;"
            "color:rgba(0,0,0,100);"

            "}");
        button->setText(("�ر�"));
        progressdialog->setCancelButton(button);
        progressdialog->setRange(0, items.size() - 1);
        progressdialog->setStyleSheet("QProgressBar{border: 1px solid grey;border-radius: 5px;text-align: center;background-color:rgba(255,255,255,150);}"
            "QProgressBar::chunk{background-color: #CD96CD;width: 10px;margin: 0.5px;}");

        for (int i = 0; i < items.size(); i++)
        {

            if (i == items.size() - 1)
            {
                progressdialog->close();
            }
            if (!progressdialog->wasCanceled())
            {
                progressdialog->setValue(i);

            }
            else
            {
                progressdialog->close();
            }

            int row = ui.listWidget_3->row(items.at(i));
            QString Text = ui.listWidget_3->item(row)->text();
            QListWidgetItem* ITEMM2 = new QListWidgetItem;
            ITEMM2->setIcon(QIcon(":/image/image/music_not_25.570093457944px_1171234_easyicon.net.png"));
            ITEMM2->setText(QString("%1").arg(Text));
            ITEMM2->setToolTip(Text);

            ui.listWidget->addItem(ITEMM2);
            model->setTable("LocalMusic");
            model->select();
            playlist_3->addMedia(playlist->media(row));
            QSqlQuery query;
            QString MusicName = model->data(model->index(row, 1)).toString();
            QString FileName = model->data(model->index(row, 2)).toString();

            query.exec("select * from  CollectMusic");
            query.exec(QString("insert into  CollectMusic values (%1,'%2','%3')").arg(qrand() % 10000000).arg(MusicName).arg(FileName));



        }


        delete button;
        ui.listWidget_3->setSelectionMode(QListWidget::SingleSelection);
    }


}
void Widget::Action7_slot()//��ѡģʽ
{
    ui.listWidget_3->setSelectionMode(QListWidget::MultiSelection);
}
void Widget::Action8_slot()//��ѡģʽ
{

    if (ui.listWidget_3->selectionMode() == QListWidget::MultiSelection)
    {
        ui.listWidget_3->setSelectionMode(QListWidget::SingleSelection);
        if (music->playlist() == playlist)
        {

            ui.listWidget_3->item(playlist->currentIndex())->setSelected(true);
        }
        else
        {
            ui.listWidget_3->item(0)->setSelected(true);
        }
    }
}

void Widget::Action5_slot()//������Ϣ
{
    int row = ui.listWidget_3->currentIndex().row();
    QString temp = ui.listWidget_3->currentIndex().data().toString();
    QString MusicName = temp.split(" - ").last();
    QString Author = temp.remove(" - " + MusicName);
    model->setTable("LocalMusic");
    model->select();
    QString FileName = model->data(model->index(row, 2)).toString();
    QString time;
    if (music->playlist() == playlist)
    {

        if (row == playlist->currentIndex())
        {
            time = Time(music->duration());
        }
        else
        {
            time = "00:00";
        }
    }
    else
    {
        time = "00:00";
    }
    QMessageBox::about(this, "������Ϣ", QString("������ : %1  \n"
        "���� : %2 \n"
        "ʱ�� : %3\n "
        "�ļ�·�� : %4\n").arg(MusicName).arg(Author).arg(time).arg(FileName));

}

void Widget::Action3_slot()//listWidget_3�Ҽ��˵� ɾ��
{


    if (ui.listWidget_3->selectionMode() == QListWidget::SingleSelection)
    {
        if (music->playlist() == playlist)
        {

            int Row = playlist->currentIndex();
            int row = ui.listWidget_3->currentIndex().row();
            if (row < Row)
            {
                int Position = 0;
                int flag = 0;
                if (music->state() == QMediaPlayer::PlayingState)
                {
                    Position = music->position();
                    flag = 1;
                }

                playlist->setCurrentIndex(0);
                delete ui.listWidget_3->takeItem(row);
                playlist->removeMedia(row, row);
                model->setTable("LocalMusic");
                model->select();
                model->removeRow(row);
                model->submitAll();
                music->setPlaylist(playlist);
                playlist->setCurrentIndex(Row - 1);
                music->setPosition(Position);
                ui.horizontalSlider->setValue(Position);
                if (flag)
                    music->play();
                if (list1[row]) {
                    int index;
                    if ((index = map.indexOf(row)) != -1)
                    {
                        delete ui.listWidget_5->takeItem(index);
                        playlist_4->removeMedia(index, index);
                        map.removeAt(index);
                        for (int i = 0; i < map.size(); i++)
                        {
                            if (map[i] > row)
                            {
                                map[i]--;
                            }
                        }
                    }
                }

                FilePath.removeAt(row);
                list1.removeAt(row);

            }
            else
            {


                ui.listWidget_3->takeItem(row);
                playlist->removeMedia(row, row);
                model->setTable("LocalMusic");
                model->select();
                model->removeRow(row);
                model->submitAll();
                if (list1[row]) {
                    int index;
                    if ((index = map.indexOf(row)) != -1)
                    {
                        delete ui.listWidget_5->takeItem(index);
                        playlist_4->removeMedia(index, index);
                        map.removeAt(index);
                        for (int i = 0; i < map.size(); i++)
                        {
                            if (map[i] > row)
                            {
                                map[i]--;
                            }
                        }
                    }
                }
                list1.removeAt(row);
                FilePath.removeAt(row);
            }


        }
        else
        {
            int row = ui.listWidget_3->currentIndex().row();

            ui.listWidget_3->takeItem(row);
            playlist->removeMedia(row, row);
            model->setTable("LocalMusic");
            model->select();
            model->removeRow(row);
            model->submitAll();
            if (list1[row]) {
                int index;
                if ((index = map.indexOf(row)) != -1)
                {
                    delete ui.listWidget_5->takeItem(index);
                    playlist_4->removeMedia(index, index);
                    map.removeAt(index);
                    for (int i = 0; i < map.size(); i++)
                    {
                        if (map[i] > row)
                        {
                            map[i]--;
                        }
                    }
                }
            }
            list1.removeAt(row);
            FilePath.removeAt(row);
        }

    }
    else if (ui.listWidget_3->selectionMode() == QListWidget::MultiSelection)
    {
        QList<QListWidgetItem*> items;
        items = ui.listWidget_3->selectedItems();
        if (items.size() == 0)
        {
            return;
        }
        QProgressDialog* progressdialog = new QProgressDialog(this);
        progressdialog->setWindowModality(Qt::WindowModal);
        progressdialog->setMinimumDuration(100);
        progressdialog->resize(400, 120);
        progressdialog->setMinimumSize(400, 120);
        progressdialog->setMaximumSize(400, 120);
        progressdialog->setMinimumDuration(100);
        progressdialog->setWindowTitle(("ɾ��"));
        progressdialog->setLabelText(("����ɾ��,���Ժ�."));
        QPushButton* button = new QPushButton(this);
        QPixmap pixmap;
        pixmap.load(":/image/image/58d4d135e7bce713bd501050.jpg");
        QPalette palette;
        palette.setBrush(QPalette::Window, QBrush(pixmap.scaled(progressdialog->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
        progressdialog->setPalette(palette);
        button->setStyleSheet("QPushButton{"

            "background-color: rgba(122, 122, 122,100);"
            "border-style:outset;"
            "border-width: 1px;"
            "border-radius: 10px;"
            "border-color: rgba(122, 122, 122,100);"
            "font: bold 14px;"
            "color :rgba(0,0,0,100);"
            "padding: 6px;"

            "}"
            "QPushButton:hover{"



            "background-color: rgba(176, 58, 176,200);"
            "color: rgba(0,0,0,200);"


            "}"
            "QPushButton:pressed{"


            "background-color:  rgba(255,255,255,150);"
            "border-color:rgba(255,255,255,150);"
            "border-style:inset;"
            "color:rgba(0,0,0,100);"

            "}");
        button->setText(("�ر�"));
        progressdialog->setCancelButton(button);
        progressdialog->setRange(0, items.size() - 1);
        progressdialog->setStyleSheet("QProgressBar{border: 1px solid grey;border-radius: 5px;text-align: center;background-color:rgba(255,255,255,150);}"
            "QProgressBar::chunk{background-color: yellow;width: 10px;margin: 0.5px;}");

        int position = 0;
        int current = 0;
        int count = 0;

        if (music->playlist() == playlist)
        {
            int flag = 0;
            if (music->state() == QMediaPlayer::PlayingState)
            {
                flag = 1;
                position = music->position();
                music->pause();
            }
            current = playlist->currentIndex();
            for (int i = 0; i < items.count(); i++)
            {
                if (current > (ui.listWidget_3->row(items.at(i))))
                {
                    count++;
                }
            }
            for (int i = 0; i < items.size(); i++)
            {

                if (i == items.size() - 1)
                {
                    progressdialog->close();
                }
                if (!progressdialog->wasCanceled())
                {
                    progressdialog->setValue(i);

                }
                else
                {
                    progressdialog->close();
                }
                int row = ui.listWidget_3->row(items.at(i));


                delete ui.listWidget_3->takeItem(row);
                playlist->removeMedia(row, row);

                model->setTable("LocalMusic");
                model->select();
                model->removeRow(row);
                model->submitAll();
                if (list1[row]) {
                    int index;
                    if ((index = map.indexOf(row)) != -1)
                    {
                        delete ui.listWidget_5->takeItem(index);
                        playlist_4->removeMedia(index, index);
                        map.removeAt(index);
                        for (int i = 0; i < map.size(); i++)
                        {
                            if (map[i] > row)
                            {
                                map[i]--;
                            }
                        }
                    }
                }
                list1.removeAt(row);
                FilePath.removeAt(row);
            }
            music->setPlaylist(playlist);
            playlist->setCurrentIndex(current - count);
            music->setPosition(position);
            ui.horizontalSlider->setValue(position);
            if (flag)
                music->play();

        }
        else
        {
            for (int i = 0; i < items.size(); i++)
            {

                if (i == items.size() - 1)
                {
                    progressdialog->close();
                }
                if (!progressdialog->wasCanceled())
                {
                    progressdialog->setValue(i);
                }
                else
                {
                    progressdialog->close();

                }
                int row = ui.listWidget_3->row(items.at(i));
                delete ui.listWidget_3->takeItem(row);

                playlist->removeMedia(row, row);

                model->setTable("LocalMusic");
                model->select();
                model->removeRow(row);
                model->submitAll();
                if (list1[row]) {
                    int index;
                    if ((index = map.indexOf(row)) != -1)
                    {
                        delete ui.listWidget_5->takeItem(index);
                        playlist_4->removeMedia(index, index);
                        map.removeAt(index);
                        for (int i = 0; i < map.size(); i++)
                        {
                            if (map[i] > row)
                            {
                                map[i]--;
                            }
                        }
                    }
                }
                list1.removeAt(row);
                FilePath.removeAt(row);
            }

        }
        delete button;
        ui.listWidget_3->setSelectionMode(QListWidget::SingleSelection);

    }

}

void Widget::on_listWidget_2_customContextMenuRequested(const QPoint& pos)//listWidget_2�Ҽ��˵� ��ϲ���б�
{
    QListWidgetItem* curItem1 = ui.listWidget_2->itemAt(pos);
    if (curItem1 == NULL)
    {
        return;
    }
    QMenu* Menu1 = new QMenu(this);
    Menu1->setStyleSheet(
        MenuStyle()

    );
    QAction* Action1_2 = new QAction(this);
    QAction* Action1_2_1 = new QAction(this);
    QAction* Action2_2 = new QAction(this);
    QAction* Action3_2 = new QAction(this);
    QAction* Action4_2 = new QAction(this);
    QAction* Action6_2 = new QAction(this);
    QAction* Action7_2 = new QAction(this);
    Action1_2->setIcon(QIcon(":/image/image/zt13.png"));
    Action1_2->setText(("����"));
    Action1_2_1->setIcon(QIcon(":/image/image/bofang1.png"));
    Action1_2_1->setText(("��ͣ"));
    Action3_2->setIcon(QIcon(":/image/image/list_32px_1142913_easyicon.net.png"));
    Action3_2->setText(("������ҵ��ղ�"));

    Action2_2->setIcon(QIcon(":/image/image/delete_32px_1168909_easyicon.net.png"));
    Action2_2->setText(("�Ƴ�"));
    Action4_2->setIcon(QIcon(":/image/image/inf.png"));
    Action4_2->setText(("������Ϣ"));
    Action6_2->setIcon(QIcon(":/image/image/duoxuan.png"));
    Action6_2->setText(("��ѡ"));
    Action7_2->setIcon(QIcon(":/image/image/quxiao.png"));
    Action7_2->setText(("ȡ����ѡ"));
    if (ui.listWidget_2->selectionMode() == QListWidget::SingleSelection)
    {
        if (music->playlist() == playlist_2)
        {
            if (ui.listWidget_2->currentIndex().row() == playlist_2->currentIndex())
            {

                if (music->state() == QMediaPlayer::PlayingState)
                {
                    Menu1->addAction(Action1_2_1);
                }
                else
                {
                    Menu1->addAction(Action1_2);
                }
            }
            else
            {
                Menu1->addAction(Action1_2);
            }
        }
        else
        {
            Menu1->addAction(Action1_2);
        }

        Menu1->addAction(Action3_2);
        Menu1->addAction(Action6_2);
        Menu1->addAction(Action4_2);
        Menu1->addAction(Action2_2);

    }
    else if (ui.listWidget_2->selectionMode() == QListWidget::MultiSelection)
    {

        Menu1->addAction(Action3_2);
        Menu1->addAction(Action7_2);
        Menu1->addAction(Action2_2);
    }
    connect(Action1_2, &QAction::triggered, this, &Widget::Action1_2_slot);
    connect(Action1_2_1, &QAction::triggered, this, &Widget::action11_slot);
    connect(Action2_2, &QAction::triggered, this, &Widget::Action2_2_slot);
    connect(Action3_2, &QAction::triggered, this, &Widget::Action3_2_slot);
    connect(Action4_2, &QAction::triggered, this, &Widget::Action4_2_slot);
    connect(Action6_2, &QAction::triggered, this, &Widget::Action6_2_slot);
    connect(Action7_2, &QAction::triggered, this, &Widget::Action7_2_slot);
    Menu1->exec(QCursor::pos());
    delete Menu1;
    delete Action1_2;
    delete Action1_2_1;
    delete Action2_2;
    delete Action3_2;
    delete Action4_2;
    delete Action6_2;
    delete Action7_2;

}
void Widget::Action1_2_slot()//listWidget_2�Ҽ��˵�   ����
{

    if (music->playlist() == playlist_2)
    {
        if (ui.listWidget_2->currentIndex().row() == playlist_2->currentIndex())
        {


            music->play();

        }
        else
        {
            playlist_2->setCurrentIndex(ui.listWidget_2->currentIndex().row());
            music->play();
        }
    }
    else
    {
        music->setPlaylist(playlist_2);
        playlist_2->setCurrentIndex(ui.listWidget_2->currentIndex().row());

        music->play();
    }

}

void Widget::Action3_2_slot()//������ҵ��ղ�
{

    if (ui.listWidget_2->selectionMode() == QListWidget::SingleSelection)
    {
        int row = ui.listWidget_2->currentIndex().row();
        QString Text = ui.listWidget_2->item(row)->text();
        QListWidgetItem* ITEMM1 = new QListWidgetItem;
        ITEMM1->setIcon(QIcon(":/image/image/music_not_25.570093457944px_1171234_easyicon.net.png"));
        ITEMM1->setText(QString("%1").arg(Text));
        ITEMM1->setToolTip(Text);

        ui.listWidget->addItem(ITEMM1);
        model_2->setTable("LikeMusic");
        model_2->select();
        playlist_3->addMedia(playlist_2->media(row));
        QSqlQuery query;
        QString MusicName = model_2->data(model_2->index(row, 1)).toString();
        QString FileName = model_2->data(model_2->index(row, 2)).toString();

        query.exec("select * from  CollectMusic");
        query.exec(QString("insert into  CollectMusic values (%1,'%2','%3')").arg(qrand() % 10000000).arg(MusicName).arg(FileName));
        ui.stackedWidget->setCurrentIndex(2);
        pushbuttonstyle_3();

    }
    else if (ui.listWidget_2->selectionMode() == QListWidget::MultiSelection)
    {

        ui.stackedWidget->setCurrentIndex(2);
        pushbuttonstyle_3();
        QList<QListWidgetItem*> items;
        items = ui.listWidget_2->selectedItems();
        if (items.size() == 0)
        {
            return;
        }
        QProgressDialog* progressdialog = new QProgressDialog(this);
        progressdialog->setWindowModality(Qt::WindowModal);
        progressdialog->resize(400, 120);
        progressdialog->setMinimumSize(400, 120);
        progressdialog->setMaximumSize(400, 120);
        progressdialog->setMinimumDuration(100);
        progressdialog->setWindowTitle(("������ҵ��ղ�"));
        progressdialog->setLabelText(("�������,���Ժ�."));
        QPushButton* button = new QPushButton(this);
        QPixmap pixmap;
        pixmap.load(":/image/image/58d4d135e7bce713bd501050.jpg");
        QPalette palette;
        palette.setBrush(QPalette::Window, QBrush(pixmap.scaled(progressdialog->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
        progressdialog->setPalette(palette);
        button->setStyleSheet("QPushButton{"

            "background-color: rgba(122, 122, 122,100);"
            "border-style:outset;"
            "border-width: 1px;"
            "border-radius: 10px;"
            "border-color: rgba(122, 122, 122,100);"
            "font: bold 14px;"
            "color :rgba(0,0,0,100);"
            "padding: 6px;"

            "}"
            "QPushButton:hover{"



            "background-color: rgba(176, 58, 176,200);"
            "color: rgba(0,0,0,200);"


            "}"
            "QPushButton:pressed{"


            "background-color:  rgba(255,255,255,150);"
            "border-color:rgba(255,255,255,150);"
            "border-style:inset;"
            "color:rgba(0,0,0,100);"

            "}");
        button->setText(("�ر�"));
        progressdialog->setCancelButton(button);
        progressdialog->setRange(0, items.size() - 1);
        progressdialog->setStyleSheet("QProgressBar{border: 1px solid grey;border-radius: 5px;text-align: center;background-color:rgba(255,255,255,150);}"
            "QProgressBar::chunk{background-color: #CD96CD;width: 10px;margin: 0.5px;}");

        for (int i = 0; i < items.size(); i++)
        {

            if (i == items.size() - 1)
            {
                progressdialog->close();
            }
            if (progressdialog->wasCanceled())
            {
                progressdialog->close();
            }
            else
            {
                progressdialog->setValue(i);
            }

            int row = ui.listWidget_2->row(items.at(i));
            QString Text = ui.listWidget_2->item(row)->text();
            QListWidgetItem* ITEMM2 = new QListWidgetItem;
            ITEMM2->setIcon(QIcon(":/image/image/music_not_25.570093457944px_1171234_easyicon.net.png"));
            ITEMM2->setText(QString("%1").arg(Text));
            ITEMM2->setToolTip(Text);

            ui.listWidget->addItem(ITEMM2);
            model_2->setTable("LikeMusic");
            model_2->select();
            playlist_3->addMedia(playlist_2->media(row));
            QSqlQuery query;
            QString MusicName = model_2->data(model_2->index(row, 1)).toString();
            QString FileName = model_2->data(model_2->index(row, 2)).toString();

            query.exec("select * from  CollectMusic");
            query.exec(QString("insert into  CollectMusic values (%1,'%2','%3')").arg(qrand() % 10000000).arg(MusicName).arg(FileName));



        }


        delete button;
        ui.listWidget_2->setSelectionMode(QListWidget::SingleSelection);
    }
}

void Widget::Action6_2_slot()//��ѡģʽ
{

    ui.listWidget_2->setSelectionMode(QListWidget::MultiSelection);
}
void Widget::Action7_2_slot()//��ѡģʽ
{

    if (ui.listWidget_2->selectionMode() == QListWidget::MultiSelection)
    {
        ui.listWidget_2->setSelectionMode(QListWidget::SingleSelection);
        if (music->playlist() == playlist_2)
        {

            ui.listWidget_2->item(playlist_2->currentIndex())->setSelected(true);
        }
        else
        {
            ui.listWidget_2->item(0)->setSelected(true);
        }
    }

}

void Widget::Action4_2_slot()//������Ϣ
{

    int row = ui.listWidget_2->currentIndex().row();
    QString temp = ui.listWidget_2->currentIndex().data().toString();
    QString MusicName = temp.split(" - ").last();
    QString Author = temp.remove(" - " + MusicName);
    model_2->setTable("LikeMusic");
    model_2->select();
    QString FileName = model_2->data(model_2->index(row, 2)).toString();
    QString time;
    if (music->playlist() == playlist_2)
    {

        if (row == playlist_2->currentIndex())
        {
            time = Time(music->duration());
        }
        else
        {
            time = "00:00";
        }
    }
    else
    {
        time = "00:00";
    }
    QMessageBox::about(this, "������Ϣ", QString("������ : %1  \n"
        "���� : %2 \n"
        "ʱ�� : %3 \n"
        "�ļ�·�� : %4\n").arg(MusicName).arg(Author).arg(time).arg(FileName));

}

void Widget::Action2_2_slot()//listWidget_2�Ҽ��˵� ɾ��
{
    if (ui.listWidget_2->selectionMode() == QListWidget::SingleSelection)
    {
        QString MusicName = ui.listWidget_2->currentItem()->text();
        if (music->playlist() == playlist_2)
        {

            int Row = playlist_2->currentIndex();
            int row = ui.listWidget_2->currentIndex().row();

            if (row < Row)
            {
                int Position = 0;
                if (music->state() == QMediaPlayer::PlayingState)
                {

                    Position = music->position();
                }
                playlist_2->setCurrentIndex(0);
                ui.listWidget_2->takeItem(row);
                playlist_2->removeMedia(row, row);

                model_2->setTable("LikeMusic");
                model_2->select();
                model_2->removeRow(row);
                model_2->submitAll();

                music->setPlaylist(playlist_2);
                playlist_2->setCurrentIndex(Row - 1);
                music->setPosition(Position);
                ui.horizontalSlider->setValue(Position);
                music->play();
            }
            else
            {
                ui.listWidget_2->takeItem(row);

                playlist_2->removeMedia(row, row);
                model_2->setTable("LikeMusic");
                model_2->select();
                model_2->removeRow(row);
                model_2->submitAll();

            }


        }
        else
        {
            int row = ui.listWidget_2->currentIndex().row();

            ui.listWidget_2->takeItem(row);
            playlist_2->removeMedia(row, row);
            model_2->setTable("LikeMusic");
            model_2->select();
            model_2->removeRow(row);
            model_2->submitAll();
        }
        QSqlQuery query;
        query.exec("select * from LocalMusic");
        query.prepare(QString("update LocalMusic set biaoji = ? where MusicName = '%1' ").arg(MusicName));
        query.bindValue(0, 0);
        query.exec();


    }
    else if (ui.listWidget_2->selectionMode() == QListWidget::MultiSelection)
    {
        QList<QListWidgetItem*> items;
        items = ui.listWidget_2->selectedItems();
        if (items.size() == 0)
        {
            return;
        }
        QProgressDialog* progressdialog = new QProgressDialog(this);
        progressdialog->setWindowModality(Qt::WindowModal);
        progressdialog->resize(400, 120);
        progressdialog->setMinimumSize(400, 120);
        progressdialog->setMaximumSize(400, 120);
        progressdialog->setMinimumDuration(100);
        progressdialog->setWindowTitle(("�Ƴ�"));
        progressdialog->setLabelText(("�����Ƴ�,���Ժ�."));
        QPushButton* button = new QPushButton(this);
        QPixmap pixmap;
        pixmap.load(":/image/image/58d4d135e7bce713bd501050.jpg");
        QPalette palette;
        palette.setBrush(QPalette::Window, QBrush(pixmap.scaled(progressdialog->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
        progressdialog->setPalette(palette);
        button->setStyleSheet("QPushButton{"

            "background-color: rgba(122, 122, 122,100);"
            "border-style:outset;"
            "border-width: 1px;"
            "border-radius: 10px;"
            "border-color: rgba(122, 122, 122,100);"
            "font: bold 14px;"
            "color :rgba(0,0,0,100);"
            "padding: 6px;"

            "}"
            "QPushButton:hover{"



            "background-color: rgba(176, 58, 176,200);"
            "color: rgba(0,0,0,200);"


            "}"
            "QPushButton:pressed{"


            "background-color:  rgba(255,255,255,150);"
            "border-color:rgba(255,255,255,150);"
            "border-style:inset;"
            "color:rgba(0,0,0,100);"

            "}");
        button->setText(("�ر�"));
        progressdialog->setCancelButton(button);
        progressdialog->setRange(0, items.size() - 1);
        progressdialog->setStyleSheet("QProgressBar{border: 1px solid grey;border-radius: 5px;text-align: center;background-color:rgba(255,255,255,150);}"
            "QProgressBar::chunk{background-color: yellow;width: 10px;margin: 0.5px;}");

        int position = 0;
        int current = 0;
        int count = 0;
        if (music->playlist() == playlist_2)
        {
            int flag = 0;
            if (music->state() == QMediaPlayer::PlayingState)
            {
                flag = 1;
                position = music->position();
                music->pause();
            }
            current = playlist_2->currentIndex();
            for (int i = 0; i < items.count(); i++)
            {

                if (current > (ui.listWidget_2->row(items.at(i))))
                {
                    count++;
                }
            }
            for (int i = 0; i < items.size(); i++)
            {

                if (i == items.size() - 1)
                {
                    progressdialog->close();
                }
                if (progressdialog->wasCanceled())
                {
                    progressdialog->close();
                }
                else
                {
                    progressdialog->setValue(i);
                }
                int row = ui.listWidget_2->row(items.at(i));
                QString MusicName = ui.listWidget_2->item(row)->text();
                delete ui.listWidget_2->takeItem(row);

                playlist_2->removeMedia(row, row);
                model_2->setTable("LikeMusic");
                model_2->select();
                model_2->removeRow(row);
                model_2->submitAll();
                QSqlQuery query;
                query.exec("select * from LocalMusic");
                query.prepare(QString("update LocalMusic set biaoji = ? where MusicName = '%1' ").arg(MusicName));
                query.bindValue(0, 0);
                query.exec();

            }
            music->setPlaylist(playlist_2);
            playlist_2->setCurrentIndex(current - count);
            music->setPosition(position);
            ui.horizontalSlider->setValue(position);
            if (flag)
                music->play();

        }
        else
        {
            for (int i = 0; i < items.size(); i++)
            {


                if (i == items.size() - 1)
                {
                    progressdialog->close();
                }
                if (progressdialog->wasCanceled())
                {
                    progressdialog->close();
                }
                else
                {
                    progressdialog->setValue(i);
                }
                int row = ui.listWidget_2->row(items.at(i));
                QString MusicName = ui.listWidget_2->item(row)->text();
                delete ui.listWidget_2->takeItem(row);

                playlist_2->removeMedia(row, row);
                model_2->setTable("LikeMusic");
                model_2->select();
                model_2->removeRow(row);
                model_2->submitAll();
                QSqlQuery query;
                query.exec("select * from LocalMusic");
                query.prepare(QString("update LocalMusic set biaoji = ? where MusicName = '%1' ").arg(MusicName));
                query.bindValue(0, 0);
                query.exec();
            }

        }
        ui.listWidget_2->setSelectionMode(QListWidget::SingleSelection);
        delete button;
    }

}

void Widget::on_listWidget_customContextMenuRequested(const QPoint& pos)//listWidget�Ҽ��˵�  �ҵ��ղ�
{
    QListWidgetItem* curItem2 = ui.listWidget->itemAt(pos);
    if (curItem2 == NULL)
    {
        return;
    }
    QMenu* Menu2 = new QMenu(this);
    Menu2->setStyleSheet(
        MenuStyle()

    );
    QAction* Action1_3 = new QAction(this);//����
    QAction* Action1_3_1 = new QAction(this);//��ͣ
    QAction* Action3_3 = new QAction(this);//������Ϣ
    QAction* Action2_3 = new QAction(this);//�Ƴ�
    QAction* Action5_3 = new QAction(this);//��ѡ
    QAction* Action6_3 = new QAction(this);//ȡ����ѡ
    Action1_3->setIcon(QIcon(":/image/image/zt13.png"));
    Action1_3->setText(("����"));
    Action1_3_1->setIcon(QIcon(":/image/image/bofang1.png"));
    Action1_3_1->setText(("��ͣ"));
    Action2_3->setIcon(QIcon(":/image/image/delete_32px_1168909_easyicon.net.png"));
    Action2_3->setText(("�Ƴ�"));
    Action3_3->setIcon(QIcon(":/image/image/inf.png"));
    Action3_3->setText(("������Ϣ"));
    Action5_3->setIcon(QIcon(":/image/image/duoxuan.png"));
    Action5_3->setText(("��ѡ"));
    Action6_3->setIcon(QIcon(":/image/image/quxiao.png"));
    Action6_3->setText(("ȡ����ѡ"));
    if (ui.listWidget->selectionMode() == QListWidget::SingleSelection)
    {
        if (music->playlist() == playlist_3)
        {
            if (ui.listWidget->currentIndex().row() == playlist_3->currentIndex())
            {
                if (music->state() == QMediaPlayer::PlayingState)
                {
                    Menu2->addAction(Action1_3_1);
                }
                else
                {
                    Menu2->addAction(Action1_3);
                }
            }
            else
            {
                Menu2->addAction(Action1_3);
            }
        }
        else
        {
            Menu2->addAction(Action1_3);
        }

        Menu2->addAction(Action5_3);
        Menu2->addAction(Action3_3);
        Menu2->addAction(Action2_3);

    }
    else if (ui.listWidget->selectionMode() == QListWidget::MultiSelection)
    {

        Menu2->addAction(Action6_3);
        Menu2->addAction(Action2_3);

    }
    connect(Action1_3, &QAction::triggered, this, &Widget::Action1_3_slot);
    connect(Action1_3_1, &QAction::triggered, this, &Widget::action11_slot);
    connect(Action2_3, &QAction::triggered, this, &Widget::Action2_3_slot);
    connect(Action3_3, &QAction::triggered, this, &Widget::Action3_3_slot);
    connect(Action5_3, &QAction::triggered, this, &Widget::Action5_3_slot);
    connect(Action6_3, &QAction::triggered, this, &Widget::Action6_3_slot);
    Menu2->exec(QCursor::pos());
    delete Menu2;
    delete Action1_3;
    delete Action2_3;
    delete Action3_3;
    delete Action5_3;
    delete Action6_3;
    delete Action1_3_1;

}
void Widget::Action1_3_slot()//listWidget�Ҽ��˵� ����
{

    if (music->playlist() == playlist_3)
    {

        int row = ui.listWidget->currentIndex().row();
        if (row == playlist_3->currentIndex())
        {


            music->play();

        }
        else
        {

            playlist_3->setCurrentIndex(ui.listWidget->currentIndex().row());
            music->play();
        }

    }
    else
    {
        music->setPlaylist(playlist_3);
        playlist_3->setCurrentIndex(ui.listWidget->currentIndex().row());
        music->play();
    }

}
void Widget::Action5_3_slot()//��ѡģʽ
{
    ui.listWidget->setSelectionMode(QListWidget::MultiSelection);
}
void Widget::Action6_3_slot()//��ѡģʽ
{
    if (ui.listWidget->selectionMode() == QListWidget::MultiSelection)
    {
        ui.listWidget->setSelectionMode(QListWidget::SingleSelection);
        if (music->playlist() == playlist_3)
        {

            ui.listWidget->item(playlist_3->currentIndex())->setSelected(true);
        }
        else
        {
            ui.listWidget->item(0)->setSelected(true);
        }
    }

}
void Widget::Action3_3_slot()//������Ϣ
{

    int row = ui.listWidget->currentIndex().row();
    QString temp = ui.listWidget->currentIndex().data().toString();
    QString MusicName = temp.split(" - ").last();
    QString Author = temp.remove(" - " + MusicName);
    model_3->setTable("  CollectMusic");
    model_3->select();
    QString FileName = model_3->data(model_3->index(row, 2)).toString();
    QString time;
    if (music->playlist() == playlist_3)
    {

        if (row == playlist_3->currentIndex())
        {
            time = Time(music->duration());
        }
        else
        {
            time = "00:00";
        }
    }
    else
    {
        time = "00:00";
    }
    QMessageBox::about(this, "������Ϣ", QString("������ : %1  \n"
        "���� : %2 \n"
        "ʱ�� : %3 \n"
        "�ļ�·�� : %4\n").arg(MusicName).arg(Author).arg(time).arg(FileName));

}

void Widget::Action2_3_slot()//listWidget�Ҽ��˵�  ɾ��
{
    if (ui.listWidget->selectionMode() == QListWidget::SingleSelection)
    {
        if (music->playlist() == playlist_3)
        {

            int Row = playlist_3->currentIndex();
            int row = ui.listWidget->currentIndex().row();
            if (row < Row)
            {
                int Position = 0;
                if (music->state() == QMediaPlayer::PlayingState)
                {

                    Position = music->position();
                }
                playlist_3->setCurrentIndex(0);

                ui.listWidget->takeItem(row);
                playlist_3->removeMedia(row, row);
                model_3->setTable("  CollectMusic");
                model_3->select();
                model_3->removeRow(row);
                model_3->submitAll();
                music->setPlaylist(playlist_3);
                playlist_3->setCurrentIndex(Row - 1);
                music->setPosition(Position);
                ui.horizontalSlider->setValue(Position);
                music->play();
            }
            else
            {
                ui.listWidget->takeItem(row);

                playlist_3->removeMedia(row, row);
                model_3->setTable("  CollectMusic");
                model_3->select();
                model_3->removeRow(row);
                model_3->submitAll();

            }


        }
        else
        {
            int row = ui.listWidget->currentIndex().row();
            ui.listWidget->takeItem(row);

            playlist_3->removeMedia(row, row);
            model_3->setTable("  CollectMusic");
            model_3->select();
            model_3->removeRow(row);
            model_3->submitAll();
        }

    }
    else if (ui.listWidget->selectionMode() == QListWidget::MultiSelection)
    {
        QList<QListWidgetItem*> items;
        items = ui.listWidget->selectedItems();
        if (items.size() == 0)
        {
            return;
        }
        QProgressDialog* progressdialog = new QProgressDialog(this);
        progressdialog->setWindowModality(Qt::WindowModal);
        progressdialog->resize(400, 120);
        progressdialog->setMinimumSize(400, 120);
        progressdialog->setMaximumSize(400, 120);
        progressdialog->setMinimumDuration(100);
        progressdialog->setWindowTitle(("�Ƴ�"));
        progressdialog->setLabelText(("�����Ƴ�,���Ժ�."));
        QPushButton* button = new QPushButton(this);
        QPixmap pixmap;
        pixmap.load(":/image/image/58d4d135e7bce713bd501050.jpg");
        QPalette palette;
        palette.setBrush(QPalette::Window, QBrush(pixmap.scaled(progressdialog->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
        progressdialog->setPalette(palette);
        button->setStyleSheet("QPushButton{"

            "background-color: rgba(122, 122, 122,100);"
            "border-style:outset;"
            "border-width: 1px;"
            "border-radius: 10px;"
            "border-color: rgba(122, 122, 122,100);"
            "font: bold 14px;"
            "color :rgba(0,0,0,100);"
            "padding: 6px;"

            "}"
            "QPushButton:hover{"



            "background-color: rgba(176, 58, 176,200);"
            "color: rgba(0,0,0,200);"


            "}"
            "QPushButton:pressed{"


            "background-color:  rgba(255,255,255,150);"
            "border-color:rgba(255,255,255,150);"
            "border-style:inset;"
            "color:rgba(0,0,0,100);"

            "}");
        button->setText(("�ر�"));
        progressdialog->setCancelButton(button);
        progressdialog->setRange(0, items.size() - 1);
        progressdialog->setStyleSheet("QProgressBar{border: 1px solid grey;border-radius: 5px;text-align: center;background-color:rgba(255,255,255,150);}"
            "QProgressBar::chunk{background-color: yellow;width: 10px;margin: 0.5px;}");

        int position = 0;
        int current = 0;
        int count = 0;
        if (music->playlist() == playlist_3)
        {
            int flag = 0;
            if (music->state() == QMediaPlayer::PlayingState)
            {
                flag = 1;
                position = music->position();
            }
            current = playlist_3->currentIndex();
            for (int i = 0; i < items.count(); i++)
            {
                if (current > (ui.listWidget->row(items.at(i))))
                {
                    count++;

                }
            }
            for (int i = 0; i < items.size(); i++)
            {

                if (i == items.size() - 1)
                {
                    progressdialog->close();
                }
                if (progressdialog->wasCanceled())
                {
                    progressdialog->close();
                }
                else
                {
                    progressdialog->setValue(i);
                }
                int row = ui.listWidget->row(items.at(i));
                delete ui.listWidget->takeItem(row);

                playlist_3->removeMedia(row, row);
                model_3->setTable("  CollectMusic");
                model_3->select();
                model_3->removeRow(row);
                model_3->submitAll();

            }
            music->setPlaylist(playlist_3);
            playlist_3->setCurrentIndex(current - count);
            music->setPosition(position);
            ui.horizontalSlider->setValue(position);
            if (flag)
                music->play();

        }
        else
        {
            for (int i = 0; i < items.size(); i++)
            {


                if (i == items.size() - 1)
                {
                    progressdialog->close();
                }
                if (progressdialog->wasCanceled())
                {
                    progressdialog->close();
                }
                else
                {
                    progressdialog->setValue(i);
                }
                int row = ui.listWidget->row(items.at(i));
                delete ui.listWidget->takeItem(row);

                playlist_3->removeMedia(row, row);
                model_3->setTable("  CollectMusic");
                model_3->select();
                model_3->removeRow(row);
                model_3->submitAll();
            }

        }
        ui.listWidget->setSelectionMode(QListWidget::SingleSelection);
        delete button;
    }

}
void Widget::on_pushButton_13_clicked()//����ģʽ
{

    hide();
    int i;
    if (music->playlist() == playlist)
    {
        i = 0;
    }
    else if (music->playlist() == playlist_2)
    {
        i = 1;
    }
    else
    {
        i = 2;
    }
    Music->setPlaylist(music->playlist(), music->playlist()->currentIndex(), music->position(), music->volume(), music->state(), playlist->playbackMode(), i);
    music->pause();
    if (Music->exec() == Dialog::Accepted)
    {

        show();

    }


}

void Widget::Data_slot(int row, int position, QMediaPlaylist* list, QMediaPlayer::State state, QMediaPlaylist::PlaybackMode model, QList<int> Index)//��������
{
    playlist->setPlaybackMode(model);
    playlist_2->setPlaybackMode(model);
    playlist_3->setPlaybackMode(model);
    if (list == playlist)
    {
        playlist->setCurrentIndex(row);
        music->setPosition(position);
        if (state == QMediaPlayer::PlayingState)
            music->play();
        for (int i = 0; i < Index.size(); i++)
        {
            if (list1[Index[i]] == 0)
            {
                list1[Index[i]]++;
                map.push_back(Index[i]);
                QListWidgetItem* myitem = new QListWidgetItem(QIcon(":/image/image/nextbo.png"), ui.listWidget_3->item(Index[i])->text());
                myitem->setToolTip(ui.listWidget_3->item(Index[i])->text());

                ui.listWidget_5->addItem(myitem);
                playlist_4->addMedia(QUrl::fromLocalFile(FilePath[Index[i]]));
            }
        }

    }
    else  if (list == playlist_2)
    {


        playlist_2->setCurrentIndex(row);
        music->setPosition(position);
        if (state == QMediaPlayer::PlayingState)
            music->play();


    }
    else
    {
        playlist_3->setCurrentIndex(row);
        music->setPosition(position);
        if (state == QMediaPlayer::PlayingState)
            music->play();

    }

}

void Widget::on_pushButton_14_clicked()//�������ϲ��
{
    if (ui.listWidget->count() == 0 && ui.listWidget_2->count() == 0 && ui.listWidget_3->count() == 0 && ui.listWidget_4->count() == 0 && ui.listWidget_5->count() == 0) {
        return;
    }
    ListFocus();
    if (music->playlist() == playlist)
    {

        int row = playlist->currentIndex();
        model->setTable("LocalMusic");
        model->select();
        int flag = model->data(model->index(row, 3)).toInt();
        if (flag == 0)
        {
            ui.pushButton_14->setIcon(QIcon(":/image/image/image/Ilike1.png"));
            ui.pushButton_14->setStyleSheet(Ilike1Style());
            ui.pushButton_14->setToolTip(("��ϲ��"));
            int row = playlist->currentIndex();
            QString Text = ui.listWidget_3->item(row)->text();
            QListWidgetItem* ITEMM2 = new QListWidgetItem;
            ITEMM2->setIcon(QIcon(":/image/image/like_outline_32px_1101681_easyicon.net.png"));
            ITEMM2->setText(QString("%1").arg(Text));
            ui.listWidget_2->addItem(ITEMM2);
            playlist_2->addMedia(playlist->media(row));
            QSqlQuery query;
            model->setTable("LocalMusic");
            model->select();
            QString MusicName = model->data(model->index(row, 1)).toString();
            QString FileName = model->data(model->index(row, 2)).toString();
            model->setData(model->index(row, 3), 1);
            model->submitAll();
            query.exec("select * from LikeMusic");
            query.exec(QString("insert into LikeMusic values (%1,'%2','%3')").arg(qrand() % 10000000).arg(MusicName).arg(FileName));
        }
        else
        {


            QMessageBox::information(this, ("��ʾ"), ("�ø��������                              ."), QMessageBox::Yes);
        }

    }

}


void Widget::on_pushButton_18_clicked()//���Ҹ���
{
    QString text = ui.lineEdit->text();
    if (!text.isEmpty())
    {
        load.clear();
        ui.listWidget_4->clear();
        std::string MusicName = ui.lineEdit->text().toStdString();
        const char* MusicName1 = MusicName.c_str();
        ui.stackedWidget->setCurrentIndex(3);
        int Count = ui.listWidget_3->count();
        pushbuttonstyle_4();
        for (int i = 0; i < Count; i++)
        {


            QString Text = ui.listWidget_3->item(i)->text();
            QString Name = Text.split(" - ").last();
            std::string Name1 = Name.toStdString();
            const  char* Name2 = Name1.c_str();
            QString Author = Text.remove(" - " + Name);
            std::string Author1 = Author.toStdString();
            const char* Author2 = Author1.c_str();
            if (strstr(Name2, MusicName1) || strstr(Author2, MusicName1))
            {

                QString Text = ui.listWidget_3->item(i)->text();
                QListWidgetItem* item20 = new QListWidgetItem;
                item20->setIcon(QIcon(":/image/image/sss.png"));
                item20->setText(Text);
                ui.listWidget_4->addItem(item20);
                load.push_back(i);

            }
        }
        ui.lineEdit->clear();
    }
}

void Widget::on_listWidget_4_doubleClicked(const QModelIndex& index)//˫������ListWidget_4 �����б�
{


    music->setPlaylist(playlist);
    playlist->setCurrentIndex(load[index.row()]);
    music->play();
}

void Widget::on_listWidget_4_customContextMenuRequested(const QPoint& pos)//listWidget_4 �˵� �����б�
{
    QListWidgetItem* ITEM20 = ui.listWidget_4->itemAt(pos);
    if (ITEM20 == NULL)
    {

        return;
    }
    QMenu* MENU20 = new QMenu(this);
    MENU20->setStyleSheet(
        MenuStyle()
    );
    QAction* Action = new QAction(this);//����
    QAction* Action_A = new QAction(this);//��ͣ
    QAction* Action1 = new QAction(this);//�������ϲ��
    QAction* Action2 = new QAction(this);//������ҵ��ղ�
    QAction* Action3 = new QAction(this);//ɾ������
    QAction* Action4 = new QAction(this);//������Ϣ
    Action->setIcon(QIcon(":/image/image/zt13.png"));
    Action->setText(("����"));
    Action_A->setIcon(QIcon(":/image/image/bofang1.png"));
    Action_A->setText(("��ͣ"));
    Action1->setIcon(QIcon(":/image/image/like_outline_32px_1101681_easyicon.net.png"));
    Action1->setText(("�������ϲ��"));
    Action2->setIcon(QIcon(":/image/image/list_32px_1074296_easyicon.net.png"));
    Action2->setText(("������ҵ��ղ�"));
    Action3->setIcon(QIcon(":/image/image/delete_32px_1168909_easyicon.net.png"));
    Action3->setText(("ɾ������"));
    Action4->setIcon(QIcon(":/image/image/inf.png"));
    Action4->setText(("������Ϣ"));
    connect(Action, &QAction::triggered, this, &Widget::Action_slot);
    connect(Action_A, &QAction::triggered, this, &Widget::action11_slot);
    connect(Action1, &QAction::triggered, this, &Widget::Action_1_slot);
    connect(Action2, &QAction::triggered, this, &Widget::Action_2_slot);
    connect(Action3, &QAction::triggered, this, &Widget::Action_3_slot);
    connect(Action4, &QAction::triggered, this, &Widget::Action_4_slot);
    int row = ui.listWidget_4->currentIndex().row();
    if (music->playlist() == playlist)
    {
        if (load[row] == playlist->currentIndex())
        {

            if (music->state() == QMediaPlayer::PlayingState)
            {
                MENU20->addAction(Action_A);

            }
            else
            {
                MENU20->addAction(Action);
            }

        }
        else
        {
            MENU20->addAction(Action);
        }

    }
    else
    {
        MENU20->addAction(Action);
    }
    MENU20->addAction(Action1);
    MENU20->addAction(Action2);
    MENU20->addAction(Action4);
    MENU20->addAction(Action3);
    MENU20->exec(QCursor::pos());
    delete Action;
    delete Action1;
    delete Action2;
    delete Action3;
    delete Action4;
    delete MENU20;
}
void Widget::Action_slot()//����
{

    int row = ui.listWidget_4->currentIndex().row();

    if (music->playlist() == playlist)
    {

        if (load[row] == playlist->currentIndex())
        {


            music->play();

        }
        else
        {
            playlist->setCurrentIndex(load[row]);

            music->play();

            ui.listWidget_3->item(load[row])->setSelected(true);

        }
    }
    else
    {
        music->setPlaylist(playlist);
        playlist->setCurrentIndex(load[row]);
        music->play();
    }
}
void Widget::Action_1_slot()//�������ϲ��
{
    model->setTable("LocalMusic");
    model->select();
    int row = ui.listWidget_4->currentIndex().row();
    int flag = model->data(model->index(load[row], 3)).toInt();
    if (flag == 0)
    {
        QString Text = ui.listWidget_3->item(load[row])->text();
        QListWidgetItem* ITEMM = new QListWidgetItem;
        ITEMM->setIcon(QIcon(":/image/image/like_outline_32px_1101681_easyicon.net.png"));
        ITEMM->setText(QString("%1").arg(Text));
        ui.listWidget_2->addItem(ITEMM);
        QSqlQuery query;
        playlist_2->addMedia(playlist->media(load[row]));
        model->setTable("LocalMusic");
        model->select();
        QString MusicName = model->data(model->index(load[row], 1)).toString();
        QString FileName = model->data(model->index(load[row], 2)).toString();
        model->setTable("LocalMusic");
        model->select();
        model->setData(model->index(load[row], 3), 1);
        model->submitAll();
        query.exec("select * from LikeMusic");
        query.exec(QString("insert into LikeMusic values (%1,'%2','%3')").arg(qrand() % 10000000).arg(MusicName).arg(FileName));
        ui.stackedWidget->setCurrentIndex(1);
        pushbuttonstyle_2();
        if (music->playlist() == playlist)
        {

            if (playlist->currentIndex() == load[row])
            {
                ui.pushButton_14->setIcon(QIcon(":/image/image/image/Ilike1.png"));
                ui.pushButton_14->setToolTip(("��ϲ��"));
            }

        }
    }
    else
    {

        QMessageBox::information(this, ("��ʾ"), ("�ø��������                              ."), QMessageBox::Yes);

    }

}
void Widget::Action_2_slot()//������ҵ��ղ�
{
    int row = ui.listWidget_4->currentIndex().row();
    QString Text = ui.listWidget_3->item(load[row])->text();
    QListWidgetItem* ITEMM1 = new QListWidgetItem;
    ITEMM1->setIcon(QIcon(":/image/image/music_not_25.570093457944px_1171234_easyicon.net.png"));
    ITEMM1->setText(QString("%1").arg(Text));
    ui.listWidget->addItem(ITEMM1);
    model->setTable("LocalMusic");
    model->select();
    playlist_3->addMedia(playlist->media(load[row]));
    QSqlQuery query;
    QString MusicName = model->data(model->index(load[row], 1)).toString();
    QString FileName = model->data(model->index(load[row], 2)).toString();

    query.exec("select * from  CollectMusic");
    query.exec(QString("insert into  CollectMusic values (%1,'%2','%3')").arg(qrand() % 10000000).arg(MusicName).arg(FileName));
    ui.stackedWidget->setCurrentIndex(2);
    pushbuttonstyle_3();


}
void Widget::Action_4_slot()//������Ϣ
{

    int row = ui.listWidget_4->currentIndex().row();
    QString temp = ui.listWidget_4->currentIndex().data().toString();
    QString MusicName = temp.split(" - ").last();
    QString Author = temp.remove(" - " + MusicName);
    model->setTable("LocalMusic");
    model->select();
    QString FileName = model->data(model->index(load[row], 2)).toString();
    QString time;
    if (music->playlist() == playlist)
    {

        if (load[row] == playlist->currentIndex())
        {
            time = Time(music->duration());
        }
        else
        {
            time = "00:00";
        }
    }
    else
    {
        time = "00:00";
    }
    QMessageBox::about(this, "������Ϣ", QString("������ : %1  \n"
        "���� : %2 \n"
        "ʱ�� : %3 \n"
        "�ļ�·�� : %4\n").arg(MusicName).arg(Author).arg(time).arg(FileName));

}

void Widget::Action_3_slot()//ɾ��
{

    if (music->playlist() == playlist)
    {

        int Row = playlist->currentIndex();
        int row = ui.listWidget_4->currentIndex().row();
        if (load[row] < Row)
        {
            int Position = 0;
            if (music->state() == QMediaPlayer::PlayingState)
            {
                Position = music->position();
            }
            playlist->setCurrentIndex(0);
            ui.listWidget_3->takeItem(load[row]);
            ui.listWidget_4->takeItem(row);
            playlist->removeMedia(load[row], load[row]);
            model->setTable("LocalMusic");
            model->select();
            model->removeRow(load[row]);
            model->submitAll();
            music->setPlaylist(playlist);
            playlist->setCurrentIndex(Row - 1);
            music->setPosition(Position);
            ui.horizontalSlider->setValue(Position);
            music->play();
        }
        else
        {
            ui.listWidget_4->takeItem(row);
            ui.listWidget_3->takeItem(load[row]);
            playlist->removeMedia(load[row], load[row]);
            model->setTable("LocalMusic");
            model->select();
            model->removeRow(load[row]);
            model->submitAll();

        }


    }
    else
    {
        int row = ui.listWidget_4->currentIndex().row();
        ui.listWidget_4->takeItem(row);
        ui.listWidget_3->takeItem(load[row]);
        playlist->removeMedia(load[row], load[row]);
        model->setTable("LocalMusic");
        model->select();
        model->removeRow(load[row]);
        model->submitAll();
    }
}

void Widget::CreateSortCut()//������ݼ�
{
    QShortcut* QUIT = new QShortcut(Qt::Key_Escape, this);//�˳�
    connect(QUIT, &QShortcut::activated, QCoreApplication::quit);
    QShortcut* play = new QShortcut(Qt::Key_Space, this);//����/��ͣ
    connect(play, &QShortcut::activated, this, &Widget::Key_Space_slot);
    QShortcut* next = new QShortcut(Qt::Key_Right, this);//��һ��
    QShortcut* next1 = new QShortcut(Qt::Key_6, this);//��һ��
    connect(next, &QShortcut::activated, this, &Widget::Next_slot);
    connect(next1, &QShortcut::activated, this, &Widget::Next_slot);
    QShortcut* pre = new QShortcut(Qt::Key_Left, this);//��һ��
    QShortcut* pre1 = new QShortcut(Qt::Key_4, this);//��һ��
    connect(pre, &QShortcut::activated, this, &Widget::Pre_slot);
    connect(pre1, &QShortcut::activated, this, &Widget::Pre_slot);
    QShortcut* nextlist = new QShortcut(Qt::Key_D, this);//ת���б�
    connect(nextlist, &QShortcut::activated, this, &Widget::nextlist_slot);
    QShortcut* prelist = new QShortcut(Qt::Key_A, this);//ת���б�
    connect(prelist, &QShortcut::activated, this, &Widget::prelist_slot);
    QShortcut* addV = new QShortcut(Qt::Key_W, this);//������
    connect(addV, &QShortcut::activated, this, &Widget::addV_slot);
    QShortcut* subV = new QShortcut(Qt::Key_S, this);//������
    connect(subV, &QShortcut::activated, this, &Widget::subV_slot);
    QShortcut* Locole = new QShortcut(Qt::Key_Q, this);//��λ
    connect(Locole, &QShortcut::activated, this, &Widget::Locale_slot);
    QShortcut* change = new QShortcut(Qt::Key_E, this);//�ı䲥��ģʽ
    connect(change, &QShortcut::activated, this, &Widget::change_slot);
    QShortcut* love = new QShortcut(Qt::Key_R, this);//�����ϲ��
    connect(love, &QShortcut::activated, this, &Widget::love_slot);
    QShortcut* multiselect = new QShortcut(Qt::Key_X, this);//��ѡ/ȡ����ѡ
    connect(multiselect, &QShortcut::activated, this, &Widget::Multiselect_slot);



}
void Widget::Key_Space_slot()//����/��ͣ
{
    ListFocus();
    if (music->state() == QMediaPlayer::PlayingState)
    {
        music->pause();
    }
    else
    {
        music->play();
    }
}
void Widget::Multiselect_slot()//��ѡ
{

    if (ui.stackedWidget->currentIndex() == 0)
    {

        if (ui.listWidget_3->selectionMode() == QListWidget::SingleSelection)
        {

            ui.listWidget_3->setSelectionMode(QListWidget::MultiSelection);

        }
        else if (ui.listWidget_3->selectionMode() == QListWidget::MultiSelection)
        {
            ui.listWidget_3->setSelectionMode(QListWidget::SingleSelection);
            if (music->playlist() == playlist)
            {

                ui.listWidget_3->item(playlist->currentIndex())->setSelected(true);
            }
            else
            {
                ui.listWidget_3->item(0)->setSelected(true);
            }

        }

    }
    else if (ui.stackedWidget->currentIndex() == 1)
    {
        if (ui.listWidget_2->selectionMode() == QListWidget::SingleSelection)
        {

            ui.listWidget_2->setSelectionMode(QListWidget::MultiSelection);

        }
        else if (ui.listWidget_2->selectionMode() == QListWidget::MultiSelection)
        {
            ui.listWidget_2->setSelectionMode(QListWidget::SingleSelection);
            if (music->playlist() == playlist_2)
            {

                ui.listWidget_2->item(playlist_2->currentIndex())->setSelected(true);
            }
            else
            {
                ui.listWidget_2->item(0)->setSelected(true);
            }
        }

    }
    else if (ui.stackedWidget->currentIndex() == 2)
    {

        if (ui.listWidget->selectionMode() == QListWidget::SingleSelection)
        {

            ui.listWidget->setSelectionMode(QListWidget::MultiSelection);

        }
        else if (ui.listWidget->selectionMode() == QListWidget::MultiSelection)
        {
            ui.listWidget->setSelectionMode(QListWidget::SingleSelection);
            if (music->playlist() == playlist_3)
            {

                ui.listWidget->item(playlist_3->currentIndex())->setSelected(true);
            }
            else
            {
                ui.listWidget->item(0)->setSelected(true);
            }
        }

    }
}

void Widget::Next_slot()//��һ��
{
    if (ui.listWidget->count() == 0 && ui.listWidget_2->count() == 0 && ui.listWidget_3->count() == 0 && ui.listWidget_4->count() == 0 && ui.listWidget_5->count() == 0) {
        return;
    }
    ListFocus();
    if (music->playlist() == playlist)
    {
        ui.stackedWidget->setCurrentIndex(0);
        pushbuttonstyle();
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
        ui.listWidget_3->scrollToItem(ui.listWidget_3->item(currentIndex));
        playlist->setCurrentIndex(currentIndex);
        if (list1[currentIndex] == 0) {
            QListWidgetItem* myitem = new QListWidgetItem(QIcon(":/image/image/nextbo.png"), ui.listWidget_3->item(currentIndex)->text());
            myitem->setToolTip(ui.listWidget_3->item(currentIndex)->text());

            ui.listWidget_5->addItem(myitem);
            playlist_4->addMedia(QUrl::fromLocalFile(FilePath[currentIndex]));
            map.push_back(currentIndex);
            list1[currentIndex]++;
        }
        else
        {
            list1[currentIndex]++;
        }

    }
    else if (music->playlist() == playlist_2)
    {
        ui.stackedWidget->setCurrentIndex(1);
        pushbuttonstyle_2();
        int currentIndex;
        if (playlist_2->playbackMode() == QMediaPlaylist::Random)
        {
            int row = playlist_2->mediaCount();
            currentIndex = qrand() % row;
        }
        else
        {
            currentIndex = playlist_2->currentIndex();

            if (++currentIndex == playlist_2->mediaCount())
            {
                currentIndex = 0;

            }

        }
        ui.listWidget_2->scrollToItem(ui.listWidget_2->item(currentIndex));
        playlist_2->setCurrentIndex(currentIndex);
    }
    else if (music->playlist() == playlist_3)
    {

        ui.stackedWidget->setCurrentIndex(2);
        pushbuttonstyle_3();
        int currentIndex;
        if (playlist_3->playbackMode() == QMediaPlaylist::Random)
        {
            int row = playlist_3->mediaCount();
            currentIndex = qrand() % row;
        }
        else
        {
            currentIndex = playlist_3->currentIndex();

            if (++currentIndex == playlist_3->mediaCount())
            {
                currentIndex = 0;

            }

        }
        ui.listWidget->scrollToItem(ui.listWidget->item(currentIndex));
        playlist_3->setCurrentIndex(currentIndex);

    }
    else if (music->playlist() == playlist_4)
    {

        ui.stackedWidget->setCurrentIndex(4);
        pushbuttonstyle_5();
        int currentIndex;
        if (playlist_4->playbackMode() == QMediaPlaylist::Random)
        {
            int row = playlist_4->mediaCount();
            currentIndex = qrand() % row;
        }
        else
        {
            currentIndex = playlist_4->currentIndex();

            if (++currentIndex == playlist_4->mediaCount())
            {
                currentIndex = 0;

            }

        }
        ui.listWidget_5->scrollToItem(ui.listWidget_5->item(currentIndex));
        playlist_4->setCurrentIndex(currentIndex);
    }
    music->play();
}
void Widget::Pre_slot()//��һ��
{
    if (ui.listWidget->count() == 0 && ui.listWidget_2->count() == 0 && ui.listWidget_3->count() == 0 && ui.listWidget_4->count() == 0 && ui.listWidget_5->count() == 0) {
        return;
    }
    ListFocus();
    if (music->playlist() == playlist)
    {
        ui.stackedWidget->setCurrentIndex(0);
        pushbuttonstyle();
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
        ui.listWidget_3->scrollToItem(ui.listWidget_3->item(currentIndex));
        playlist->setCurrentIndex(currentIndex);
        if (list1[currentIndex] == 0) {
            QListWidgetItem* myitem = new QListWidgetItem(QIcon(":/image/image/nextbo.png"), ui.listWidget_3->item(currentIndex)->text());
            myitem->setToolTip(ui.listWidget_3->item(currentIndex)->text());

            ui.listWidget_5->addItem(myitem);
            playlist_4->addMedia(QUrl::fromLocalFile(FilePath[currentIndex]));
            map.push_back(currentIndex);
            list1[currentIndex]++;
        }
        else
        {
            list1[currentIndex]++;
        }

    }
    else if (music->playlist() == playlist_2)
    {

        ui.stackedWidget->setCurrentIndex(1);
        pushbuttonstyle_2();
        int currentIndex;

        if (playlist_2->playbackMode() == QMediaPlaylist::Random)
        {

            int row = playlist_2->mediaCount();
            currentIndex = qrand() % row;
        }
        else
        {
            currentIndex = playlist_2->currentIndex();
            if (--currentIndex < 0)
            {
                currentIndex = 0;
            }
        }
        ui.listWidget_2->scrollToItem(ui.listWidget_2->item(currentIndex));
        playlist_2->setCurrentIndex(currentIndex);
    }
    else if (music->playlist() == playlist_3)
    {
        ui.stackedWidget->setCurrentIndex(2);
        pushbuttonstyle_3();
        int currentIndex;
        if (playlist_3->playbackMode() == QMediaPlaylist::Random)
        {
            int row = playlist_3->mediaCount();
            currentIndex = qrand() % row;
        }
        else
        {
            currentIndex = playlist_3->currentIndex();

            if (--currentIndex < 0)
            {
                currentIndex = 0;
            }
        }
        ui.listWidget->scrollToItem(ui.listWidget->item(currentIndex));
        playlist_3->setCurrentIndex(currentIndex);
    }
    else
    {
        ui.stackedWidget->setCurrentIndex(4);
        pushbuttonstyle_5();
        int currentIndex;
        if (playlist_4->playbackMode() == QMediaPlaylist::Random)
        {
            int row = playlist_4->mediaCount();
            currentIndex = qrand() % row;
        }
        else
        {
            currentIndex = playlist_4->currentIndex();

            if (--currentIndex < 0)
            {
                currentIndex = 0;
            }
        }
        ui.listWidget_5->scrollToItem(ui.listWidget_5->item(currentIndex));
        playlist_4->setCurrentIndex(currentIndex);
    }
    music->play();

}
void Widget::nextlist_slot()//��һ�������б�
{

    int current = ui.stackedWidget->currentIndex();

    if (current < 3)
    {
        current++;
        ui.stackedWidget->setCurrentIndex(current);
        if (current == 0)
        {

            pushbuttonstyle();

        }
        else if (current == 1)
        {

            pushbuttonstyle_2();

        }
        else if (current == 2)
        {

            pushbuttonstyle_3();

        }
        else
        {
            pushbuttonstyle_5();
        }

    }


}
void Widget::prelist_slot()//��һ�������б�
{

    int current = ui.stackedWidget->currentIndex();
    if (current > 0)
    {

        current--;
        ui.stackedWidget->setCurrentIndex(current);

        if (current == 0)
        {

            pushbuttonstyle();

        }
        else if (current == 1)
        {

            pushbuttonstyle_2();

        }
        else if (current == 2)
        {

            pushbuttonstyle_3();

        }
        else {
            pushbuttonstyle_5();
        }


    }


}
void Widget::addV_slot()//��������
{

    ui.verticalSlider->show();
    int values = ui.verticalSlider->value();
    if (values < 100)
    {

        values++;
        ui.verticalSlider->setValue(values);

    }
}
void Widget::subV_slot()//��������
{

    ui.verticalSlider->show();
    int values = ui.verticalSlider->value();
    if (values > 0)
    {

        values--;
        ui.verticalSlider->setValue(values);

    }
}
void Widget::Locale_slot()//��λ
{
    if (ui.listWidget->count() == 0 && ui.listWidget_2->count() == 0 && ui.listWidget_3->count() == 0 && ui.listWidget_4->count() == 0 && ui.listWidget_5->count() == 0) {
        return;
    }

    if (music->playlist() == playlist)
    {



        if (ui.listWidget_3->count() == 0) {
            return;
        }
        else {
            ui.stackedWidget->setCurrentIndex(0);
            ui.listWidget_3->setFocus();
            pushbuttonstyle();
            if (ui.listWidget_3->selectionMode() == QListWidget::SingleSelection)
            {
                ui.listWidget_3->item(playlist->currentIndex())->setSelected(true);
                ui.listWidget_3->scrollToItem(ui.listWidget_3->item(playlist->currentIndex()));
            }
        }
    }
    else if (music->playlist() == playlist_2)
    {


        if (ui.listWidget_2->count() == 0) return;
        else {
            ui.stackedWidget->setCurrentIndex(1);
            ui.listWidget_2->setFocus();
            pushbuttonstyle_2();
            if (ui.listWidget_2->selectionMode() == QListWidget::SingleSelection)
            {
                ui.listWidget_2->item(playlist_2->currentIndex())->setSelected(true);
                ui.listWidget_2->scrollToItem(ui.listWidget_2->item(playlist_2->currentIndex()));
            }
        }

    }
    else if (music->playlist() == playlist_3)
    {



        if (ui.listWidget->count() == 0) {
            return;
        }
        else
        {
            ui.stackedWidget->setCurrentIndex(2);
            ui.listWidget->setFocus();
            pushbuttonstyle_3();
            if (ui.listWidget->selectionMode() == QListWidget::SingleSelection)
            {
                ui.listWidget->item(playlist_3->currentIndex())->setSelected(true);
                ui.listWidget->scrollToItem(ui.listWidget->item(playlist_3->currentIndex()));

            }
        }
    }
    else
    {
        if (ui.listWidget->count() == 0) {
            return;
        }
        else
        {
            ui.stackedWidget->setCurrentIndex(4);
            ui.listWidget->setFocus();
            pushbuttonstyle_5();

            ui.listWidget_5->item(playlist_4->currentIndex())->setSelected(true);
            ui.listWidget_5->scrollToItem(ui.listWidget_5->item(playlist_4->currentIndex()));


        }
    }
}
void Widget::change_slot()//�ı䲥��ģʽ
{

    if (playlist->playbackMode() == QMediaPlaylist::Loop)
    {

        ui.pushButton_9->setIcon(QIcon(":/image/image/image/play-random.png"));
        ui.pushButton_9->setToolTip(("�������"));
        playlist->setPlaybackMode(QMediaPlaylist::Random);
        playlist_2->setPlaybackMode(QMediaPlaylist::Random);
        playlist_3->setPlaybackMode(QMediaPlaylist::Random);
    }
    else if (playlist->playbackMode() == QMediaPlaylist::Random)
    {
        ui.pushButton_9->setIcon(QIcon(":/image/image/image/loop-one.png"));
        ui.pushButton_9->setToolTip(("����ѭ��"));
        playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
        playlist_2->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
        playlist_3->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);


    }
    else if (playlist->playbackMode() == QMediaPlaylist::CurrentItemInLoop)
    {
        ui.pushButton_9->setIcon(QIcon(":/image/image/loop.png"));
        ui.pushButton_9->setToolTip(("˳�򲥷�"));
        playlist->setPlaybackMode(QMediaPlaylist::Loop);
        playlist_2->setPlaybackMode(QMediaPlaylist::Loop);
        playlist_3->setPlaybackMode(QMediaPlaylist::Loop);

    }
}
void Widget::love_slot()//�������ϲ��
{
    if (ui.listWidget->count() == 0 && ui.listWidget_2->count() == 0 && ui.listWidget_3->count() == 0 && ui.listWidget_4->count() == 0 && ui.listWidget_5->count() == 0) {
        return;
    }
    if (music->playlist() == playlist)
    {

        int row = playlist->currentIndex();
        model->setTable("LocalMusic");
        model->select();
        int flag = model->data(model->index(row, 3)).toInt();
        if (flag == 0)
        {
            ui.pushButton_14->setIcon(QIcon(":/image/image/Ilike.png"));
            ui.pushButton_14->setStyleSheet(IlikeStyle());
            ui.pushButton_14->setToolTip(("��ϲ��"));
            int row = playlist->currentIndex();
            QString Text = ui.listWidget_3->item(row)->text();
            QListWidgetItem* ITEMM2 = new QListWidgetItem;
            ITEMM2->setIcon(QIcon(":/image/image/like_outline_32px_1101681_easyicon.net.png"));
            ITEMM2->setText(QString("%1").arg(Text));
            ui.listWidget_2->addItem(ITEMM2);
            playlist_2->addMedia(playlist->media(row));
            QSqlQuery query;
            model->setTable("LocalMusic");
            model->select();
            QString MusicName = model->data(model->index(row, 1)).toString();
            QString FileName = model->data(model->index(row, 2)).toString();
            model->setData(model->index(row, 3), 1);
            model->submitAll();
            query.exec("select * from LikeMusic");
            query.exec(QString("insert into LikeMusic values (%1,'%2','%3')").arg(qrand() % 10000000).arg(MusicName).arg(FileName));
        }

    }

}

void Widget::on_lineEdit_returnPressed()//�����س�����
{
    QString text = ui.lineEdit->text();
    if (!text.isEmpty())
    {
        load.clear();
        ui.listWidget_4->clear();
        std::string MusicName = ui.lineEdit->text().toStdString();
        const char* MusicName1 = MusicName.c_str();
        ui.stackedWidget->setCurrentIndex(3);
        int Count = ui.listWidget_3->count();
        pushbuttonstyle_4();
        for (int i = 0; i < Count; i++)
        {

            QString Text = ui.listWidget_3->item(i)->text();
            QString Name = Text.split(" - ").last();
            std::string Name1 = Name.toStdString();
            const  char* Name2 = Name1.c_str();
            QString Author = Text.remove(" - " + Name);
            std::string Author1 = Author.toStdString();
            const char* Author2 = Author1.c_str();
            if (strstr(Name2, MusicName1) || strstr(Author2, MusicName1))
            {
                QString Text = ui.listWidget_3->item(i)->text();
                QListWidgetItem* item20 = new QListWidgetItem;
                item20->setIcon(QIcon(":/image/image/sss.png"));
                item20->setText(Text);
                ui.listWidget_4->addItem(item20);
                load.push_back(i);

            }
        }
        ui.lineEdit->clear();
    }
}
void Widget::PlaylistModel_slot(QMediaPlaylist::PlaybackMode model)//����ģʽ�ı�
{

    if (model == QMediaPlaylist::Loop)//˳�򲥷�
    {
        ui.pushButton_9->setIcon(QIcon(":/image/image/image/loop.png"));
        ui.pushButton_9->setStyleSheet(LoopStyle());
        ui.pushButton_9->setToolTip(("˳�򲥷�"));

    }
    else if (model == QMediaPlaylist::Random)//�������
    {
        ui.pushButton_9->setIcon(QIcon(":/image/image/image/play-random.png"));
        ui.pushButton_9->setStyleSheet(RandomStyle());
        ui.pushButton_9->setToolTip(("�������"));

    }
    else if (model == QMediaPlaylist::CurrentItemInLoop)//����ѭ��
    {
        ui.pushButton_9->setIcon(QIcon(":/image/image/image/loop-one.png"));
        ui.pushButton_9->setStyleSheet(LoopOneStyle());
        ui.pushButton_9->setToolTip(("����ѭ��"));
        playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);

    }
}

void Widget::on_pushButton_19_clicked()
{
    ListFocus();


    //


}


void Widget::on_pushButton_20_clicked()
{
    ListFocus();
    QPropertyAnimation* a = new QPropertyAnimation(ui.pushButton_5, "geometry");
    QPropertyAnimation* a1 = new QPropertyAnimation(ui.pushButton_6, "geometry");
    QPropertyAnimation* a2 = new QPropertyAnimation(ui.pushButton, "geometry");
    QPropertyAnimation* a3 = new QPropertyAnimation(ui.pushButton_13, "geometry");
    a->setDuration(500);
    a1->setDuration(600);
    a2->setDuration(700);
    a3->setDuration(800);
    if (ui.pushButton_5->y() == -32)
    {
        a->setStartValue(QRect(1020, -32, 32, 32));
        a->setEndValue(QRect(1020, 20, 32, 32));
        a->setEasingCurve(QEasingCurve::InBounce);

        a1->setStartValue(QRect(968, -32, 32, 32));
        a1->setEndValue(QRect(968, 20, 32, 32));
        a1->setEasingCurve(QEasingCurve::InBounce);

        a2->setStartValue(QRect(916, -32, 32, 32));
        a2->setEndValue(QRect(916, 20, 32, 32));
        a2->setEasingCurve(QEasingCurve::InBounce);


        a3->setStartValue(QRect(864, -32, 32, 32));
        a3->setEndValue(QRect(864, 20, 32, 32));
        a3->setEasingCurve(QEasingCurve::InBounce);

    }
    else
    {

        a->setStartValue(QRect(1020, 20, 32, 32));
        a->setEndValue(QRect(1020, -32, 32, 32));
        a->setEasingCurve(QEasingCurve::InBounce);

        a1->setStartValue(QRect(968, 20, 32, 32));
        a1->setEndValue(QRect(968, -32, 32, 32));
        a1->setEasingCurve(QEasingCurve::InBounce);

        a2->setStartValue(QRect(916, 20, 32, 32));
        a2->setEndValue(QRect(916, -32, 32, 32));
        a2->setEasingCurve(QEasingCurve::InBounce);


        a3->setStartValue(QRect(864, 20, 32, 32));
        a3->setEndValue(QRect(864, -32, 32, 32));
        a3->setEasingCurve(QEasingCurve::InBounce);
    }
    a->start();
    a1->start();
    a2->start();
    a3->start();


}
inline void Widget::ListFocus() {

    if (music->playlist() == playlist) {

        ui.listWidget_3->setFocus();

    }
    else if (music->playlist() == playlist_2) {
        ui.listWidget_2->setFocus();
    }
    else if (music->playlist() == playlist_3) {
        ui.listWidget->setFocus();
    }
    else
    {
        ui.listWidget_5->setFocus();
    }

}
void Widget::ListItemToolTip()
{

    for (int i = 0; i < ui.listWidget_3->count(); i++)
    {
        ui.listWidget_3->item(i)->setToolTip(ui.listWidget_3->item(i)->text());
    }
    for (int i = 0; i < ui.listWidget_2->count(); i++)
    {
        ui.listWidget_2->item(i)->setToolTip(ui.listWidget_2->item(i)->text());


    }
    for (int i = 0; i < ui.listWidget->count(); i++) {

        ui.listWidget->item(i)->setToolTip(ui.listWidget->item(i)->text());

    }
    for (int i = 0; i < ui.listWidget_4->count(); i++)
    {
        ui.listWidget_4->item(i)->setToolTip(ui.listWidget_4->item(i)->text());

    }
    for (int i = 0; i < ui.listWidget_5->count(); i++)
    {
        ui.listWidget_5->item(i)->setToolTip(ui.listWidget_5->item(i)->text());
    }

}


void Widget::on_listWidget_5_doubleClicked(const QModelIndex& index)
{
    music->setPlaylist(playlist_4);
    int currentIndex = index.row();
    playlist_4->setCurrentIndex(currentIndex);
    music->play();
}

void Widget::on_listWidget_5_customContextMenuRequested(const QPoint& pos)//������ʷ
{
    QListWidgetItem* curItem = ui.listWidget_5->itemAt(pos);
    if (curItem == NULL)
    {
        return;
    }
    QMenu* Menu = new QMenu(this);
    Menu->setStyleSheet(
        MenuStyle()

    );
    QAction* play = new QAction(this);//����
    QAction* puase = new QAction(this);//��ͣ
    QAction* information = new QAction(this);//������Ϣ
    QAction* Clear = new QAction(this);
    play->setIcon(QIcon(":/image/image/zt13.png"));
    play->setText(("����"));
    puase->setIcon(QIcon(":/image/image/bofang1.png"));
    puase->setText(("��ͣ"));
    information->setIcon(QIcon(":/image/image/inf.png"));
    information->setText(("������Ϣ"));

    Clear->setText(("������ż�¼"));
    Clear->setIcon(QIcon(":/image/image/quxiao.png"));

    if (music->playlist() == playlist_4)
    {
        if (ui.listWidget_5->currentIndex().row() == playlist_4->currentIndex())
        {
            if (music->state() == QMediaPlayer::PlayingState)
            {
                Menu->addAction(puase);
            }
            else
            {
                Menu->addAction(play);
            }
        }
        else
        {
            Menu->addAction(play);
        }
    }
    else
    {
        Menu->addAction(play);
    }

    Menu->addAction(information);

    Menu->addAction(Clear);

    connect(play, &QAction::triggered, this, &Widget::playMusic_slot);
    connect(puase, &QAction::triggered, this, &Widget::action11_slot);
    connect(information, &QAction::triggered, this, &Widget::listWidget_5_info);
    connect(Clear, &QAction::triggered, this, &Widget::clearListWidget_slot);
    Menu->exec(QCursor::pos());
    delete Menu;
    delete  play;
    delete  puase;
    delete  information;

    delete  Clear;
}
void Widget::playMusic_slot()
{
    if (music->playlist() == playlist_4)
    {
        if (ui.listWidget_5->currentIndex().row() == playlist_4->currentIndex())
        {


            music->play();

        }
        else
        {
            playlist_4->setCurrentIndex(ui.listWidget_5->currentIndex().row());
            music->play();
        }
    }
    else
    {
        music->setPlaylist(playlist_4);
        playlist_4->setCurrentIndex(ui.listWidget_5->currentIndex().row());

        music->play();
    }

}

void Widget::listWidget_5_info()
{
    {
        int row = ui.listWidget_5->currentIndex().row();
        QString temp = ui.listWidget_5->currentIndex().data().toString();
        QString MusicName = temp.split(" - ").last();
        QString Author = temp.remove(" - " + MusicName);

        QString FileName = FilePath[row];
        QString time;
        if (music->playlist() == playlist_4)
        {

            if (row == playlist_4->currentIndex())
            {
                time = Time(music->duration());
            }
            else
            {
                time = "00:00";
            }
        }
        else
        {
            time = "00:00";



        }
        QMessageBox::about(this, "������Ϣ", QString("������ : %1  \n"
            "���� : %2 \n"
            "ʱ�� : %3\n "
            "�ļ�·�� : %4\n").arg(MusicName).arg(Author).arg(time).arg(FileName));

    }
}
void Widget::clearListWidget_slot()
{
    ClearHistory_Slot();
}
