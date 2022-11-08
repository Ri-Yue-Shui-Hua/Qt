#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_MusicPlayer.h"
#include<QWidget>
#include<QMediaPlayer>
#include<QMediaPlaylist>
#include<QPixmap>
#include<QPalette>
#include<dwmapi.h>
#include<windowsx.h>
#include<QStandardItemModel>
#include<QStandardItem>
#include<QAction>
#include<QtWinExtras>
#include<QMouseEvent>
#include<QList>
#include<QStringList>
#include<QPaintEvent>
#include<QSqlTableModel>
#include"dialog.h"
#include<QPropertyAnimation>
class QMediaPlayer;
class QMediaPlaylist;
class QMenu;
class QAction;
class QSqlTableModel;
class Dialog;
class Form;

class MusicPlayer : public QMainWindow
{
    Q_OBJECT

public:
    MusicPlayer(QWidget *parent = nullptr);
    ~MusicPlayer();

    void updateInfo();//�����ı�
    void updatePosition(qint64 position);//���²���λ��
    void updateDuration(qint64 duration);//���²��Ž���
    void updatalistwidget_3(int value);//����listWidget_3
    void updatalistwidget_2(int value);//����listWidget_2
    void updatalistwidget(int value);//����listWidget
    void changeVolume(int values);//�ı�����
    void pushbuttonstyle();//Ч������  �������ְ�ť��ʾ��ɫ����
    void pushbuttonstyle_2();//Ч������  ��ϲ���б�ť��ʾ��ɫ����
    void pushbuttonstyle_3();//Ч������  ���Ŷ��а�ť��ʾ��ɫ����
    void pushbuttonstyle_4();//Ч������  ���а�ť�����������ɫ
    void pushbuttonstyle_5();

    void mouseDoubleClickEvent(QMouseEvent*);//˫���л�������ģʽvoid mousePressEvent(QMouseEvent *event);//��ק �ƶ�����
    void mouseMoveEvent(QMouseEvent* event);//��ק �ƶ�����
    void mouseReleaseEvent(QMouseEvent* event);//��ק �ƶ�����
    void mousePressEvent(QMouseEvent* event);
    void ListItemToolTip();
    inline void init_Connect();
    inline void init_tooltip();
    inline  void init_icon();
    inline void init_action();
    inline  void init_list();
    inline  void init_win();
    inline  void init_else();
    inline QString MenuStyle();
    inline QString PlayStyle();
    inline QString PaseStyle();
    inline QString IlikeStyle();
    inline QString Ilike1Style();
    inline QString ShowListStyle();
    inline QString HideListStyle();
    inline QString RandomStyle();
    inline QString LoopStyle();
    inline QString LoopOneStyle();
    inline QString VoiceStyle();
    inline QString NoVoiceStyle();
    inline QString MusicListStyle();
    inline void ListFocus();

private slots:
    void on_pushButton_10_clicked();//������������
    void on_pushButton_11_clicked();//��������ϲ��
    void on_pushButton_12_clicked();//�������Ŷ���
    void on_pushButton_2_clicked();//����/��ͣ
    void on_pushButton_3_clicked();//������һ��
    void on_pushButton_4_clicked();//������һ��
    void on_pushButton_15_clicked();//����stackedWidget
    void on_pushButton_9_clicked();//����ģʽ

    void on_listWidget_3_doubleClicked(const QModelIndex& index);//˫������playlist ���������б�
    void on_listWidget_2_doubleClicked(const QModelIndex& index);//˫������playlist_2 ���������б�
    void on_listWidget_doubleClicked(const QModelIndex& index);//˫������playlist_3 ���������б�
    void on_listWidget_4_doubleClicked(const QModelIndex& index);//˫������playlist ���������б�

    void action1_slot();//��Ӳ˵�  �������������
    void action2_slot();//��Ӳ˵�  �������ϲ��
    void action3_slot();//��Ӳ˵�  ��������Ŷ���
    void action4_1_slot();//���ò˵�  ͸����+5%
    void action4_2_slot();//���ò˵�  ͸����-5%
    void action5_1_slot();//����Ĭ�ϱ�ֽ1
    void action5_2_slot();//����Ĭ�ϱ�ֽ2
    void action5_4_slot();//3
    void action5_3_slot();//���ò˵�  �����Զ����ֽ
    void action6_slot();//����  ����
    void action7_slot();//���ò˵�  ʹ��
    void action8_slot();//�������Ҽ��˵� �ر�
    void ClearALL_1_slot();//�����������
    void ClearALL_2_slot();//�����ϲ���б�
    void ClearALL_3_slot();//������Ŷ���
    void ClearALL_4_slot();//�������
    void action9_slot();//�������Ҽ��˵� ������һ��
    void action10_slot();//�������Ҽ��˵� ������һ��

    void action11_slot();//��ͣ
    void action11_1_slot();//����

    void action12_1_slot();//�������Ҽ��˵� ˳�򲥷�
    void action12_2_slot();//�������Ҽ��˵� �������
    void action12_3_slot();//�������Ҽ��˵� ����ѭ��

    void Action1_slot();//listWidget_3�Ҽ��˵� ���Ÿ���
    void Action2_slot();//listWidget_3�Ҽ��˵� �������ϲ��
    void Action3_slot();//listWidget_3�Ҽ��˵� ɾ��
    void Action4_slot();//listWidget_3�Ҽ��˵� ��������Ŷ���
    void Action5_slot();//������Ϣ
    void Action7_slot();//��ѡģʽ
    void Action8_slot();//��ѡģʽ

    void Action1_2_slot();//listWidget_2�Ҽ��˵�   ����
    void Action2_2_slot();//listWidget_2�Ҽ��˵� ɾ��
    void Action3_2_slot();//��������Ŷ���
    void Action4_2_slot();//������Ϣ
    void Action6_2_slot();//��ѡģʽ
    void Action7_2_slot();//��ѡģʽ

    void Action1_3_slot();//listWidget�Ҽ��˵� ����
    void Action2_3_slot();//listWidget�Ҽ��˵�  ɾ��
    void Action3_3_slot();//������Ϣ
    void Action5_3_slot();//��ѡģʽ
    void Action6_3_slot();//��ѡģʽ

    void Action_slot();//����
    void Action_1_slot();//�������ϲ��
    void Action_2_slot();//��������Ŷ���
    void Action_3_slot();//ɾ��
    void Action_4_slot();//������Ϣ

    void detila_slot();//��������
    void on_pushButton_7_clicked();//������λ
    void contextMenuEvent(QContextMenuEvent*);//�������Ҽ��˵�
    void on_pushButton_17_clicked();//�ر�
    void on_pushButton_16_clicked();//��С��
    void on_pushButton_8_clicked();//����verticalSlider
    void on_listWidget_3_customContextMenuRequested(const QPoint& pos);//listWidget_3�Ҽ��˵� ���������б�
    void on_listWidget_2_customContextMenuRequested(const QPoint& pos);//listWidget_2�Ҽ��˵� ��ϲ���б�
    void on_listWidget_customContextMenuRequested(const QPoint& pos);//listWidget�Ҽ��˵�  ���Ŷ���
    void music_stateChang(QMediaPlayer::State state);//����״̬�ı�
    void on_pushButton_13_clicked();//����ģʽ
    void on_pushButton_14_clicked();//�������ϲ��
    void on_pushButton_18_clicked();//���Ҹ���

    void on_listWidget_4_customContextMenuRequested(const QPoint& pos);//listWidget_4 �˵� �����б�
    void Next_slot();//��һ��
    void Pre_slot();//��һ��
    void nextlist_slot();//��һ�������б�
    void prelist_slot();//��һ�������б�
    void addV_slot();//��������
    void subV_slot();//��������
    void Locale_slot();//��λ
    void change_slot();//�ı䲥��ģʽ
    void love_slot();//�������ϲ��
    void Data_slot(int row, int position, QMediaPlaylist* list, QMediaPlayer::State state, QMediaPlaylist::PlaybackMode model, QList<int> Index);//��������
    void on_lineEdit_returnPressed();//�����س�����
    void PlaylistModel_slot(QMediaPlaylist::PlaybackMode model);//����ģʽ�ı�
    void  Key_Space_slot();//����/��ͣ
    void Multiselect_slot();//��ѡ

    void on_pushButton_19_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_20_clicked();
    void on_listWidget_5_doubleClicked(const QModelIndex& index);
    void ClearHistory_Slot();
    void on_listWidget_5_customContextMenuRequested(const QPoint& pos);
    void listWidget_5_info();
    void playMusic_slot();
    void clearListWidget_slot();
private:
    void CreateSortCut();//������ݼ�

    //Ui::Widget* ui;
    QMediaPlayer* music = NULL;//����

    QMediaPlaylist* playlist = NULL;//�����б�1
    QMediaPlaylist* playlist_2 = NULL;//�����б�2
    QMediaPlaylist* playlist_3 = NULL;//�����б�3
    QMediaPlaylist* playlist_4 = NULL;//��ʷ

    QPixmap pix;//ͼƬ
    QPalette pal;//��ɫ��

    QAction* action1;//�������������
    QAction* action2;//�������ϲ��
    QAction* action3;//��������Ŷ���
    QAction* add;//���Ӳ˵�
    QAction* location;//��λ

    QAction* action4;//͸��������
    QAction* action4_1;//͸���ȼ�
    QAction* action4_2;//͸���ȼ�
    QAction* action5;//Ƥ������
    QAction* action5_1;//Ĭ��Ƥ��1
    QAction* action5_2;//Ĭ��Ƥ��2
    QAction* action5_4;
    QAction* action5_3;//�Զ���Ƥ��
    QAction* action6;//����
    QAction* action7;//ʹ�ý���
    QAction* action8;//�˳�
    QAction* ClearALL;//����˵�
    QAction* ClearALL_1;//�����������
    QAction* ClearALL_2;//�����ϲ��
    QAction* ClearALL_3;//������Ŷ���
    QAction* ClearALL_4;//�������
    QAction* ClearHistory;
    //�Ҽ��˵�
    QAction* action9;//��һ��
    QAction* action10;//��һ��
    QAction* action11;//����
    QAction* action11_1;//��ͣ
    QAction* action12;//����ģʽ
    QAction* action12_1;//˳�򲥷�
    QAction* action12_2;//�������
    QAction* action12_3;//����ѭ��
    QAction* action13;//�˳�
    QAction* detila;//��������
    QMenu* menu;//�Ҽ��˵�
    QPoint offset;//��
    double transparency;//͸����

    QSqlTableModel* model;//�����б�1ģ��
    QSqlTableModel* model_2;//�����б�2ģ��
    QSqlTableModel* model_3;//�����б�3ģ��

    QList<int> load;//ӳ��
    QStringList labelText1;
    QStringList labelText2;
    Dialog* Music = NULL;//������

    QWinThumbnailToolBar* toolbar;//������������
    QWinThumbnailToolButton* next;//��һ�װ�ť
    QWinThumbnailToolButton* pre;//��һ�װ�ť
    QWinThumbnailToolButton* pause;//����/��ͣ��ť
    QWinTaskbarButton* Taskbotton;//������
    QWinTaskbarProgress* TaskProgress;//������������
    QVector<QString> currentFileName;
    QVector<int> list1;
    QList<int> map;
    QVector<QString> FilePath;

private:
    Ui::MusicPlayerClass ui;
};
