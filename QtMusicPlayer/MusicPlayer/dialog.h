#pragma once
#ifndef DIALOG_H
#define DIALOG_H

#include <QtWidgets/QDialog>
#include<QtCore/QPoint>
#include<QtGUI/QMouseEvent>
#include<QtGUI/QPixmap>
#include<QtGUI/QPalette>
#include<QtMultimedia/QMediaPlayer>
#include<QtMultimedia/QMediaPlaylist>
#include<QtWidgets/QAction>
#include<QtWinExtras/QtWinExtras>
#include"MusicPlayer.h"
namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget* parent = 0);
    ~Dialog();
    void mousePressEvent(QMouseEvent* event);//�϶�����
    void mouseMoveEvent(QMouseEvent* event);//�϶�����
    void mouseReleaseEvent(QMouseEvent* event);//�϶�����
    void mouseDoubleClickEvent(QMouseEvent*);//˫������������
    void contextMenuEvent(QContextMenuEvent*);//�Ҽ��˵���
    void setPlaylist(QMediaPlaylist* list, int row, int position, int volume, QMediaPlayer::State state, QMediaPlaylist::PlaybackMode playmodel, int i);//��������
    void updateText();//�����ı�
    void updatePosition(qint64 position);//����λ��
    void updateDuration(qint64 duration);//����״̬
    void stateChange(QMediaPlayer::State state);//״̬�ı�
    void PlaybackModel_slot(QMediaPlaylist::PlaybackMode model);//����ģʽ�ı�
signals:
    void Data(int row, int position, QMediaPlaylist* list, QMediaPlayer::State state, QMediaPlaylist::PlaybackMode model, QList<int> Index);//��������
private slots:
    void on_pushButton_4_clicked();//�˳�


    void on_pushButton_5_clicked();//��С��

    void on_pushButton_2_clicked();//����/��ͣ

    void on_pushButton_3_clicked();//��һ��

    void on_pushButton_clicked();//��һ��
    void play_slot();//����
    void pause_slot();//��ͣ
    void next_slot();//��һ��
    void pre_slot();//��һ��
    void action1_slot();//Ĭ��Ƥ��1
    void action2_slot();//Ĭ��Ƥ��2
    void action3_slot();//Ĭ��Ƥ��3
    void action4_slot();//�Զ���Ƥ��
    void back_slot();
    void Action1_slot();//͸���ȼ�
    void Action2_slot();//͸���ȼ�
    void quit_slot();//�˳�
    void on_pushButton_7_clicked();//����ģʽ
    void UpdateIndex(int value);

private:
    Ui::Dialog* ui;
    QPoint offset;//�����λ��
    QPixmap pix;//ͼƬ
    QPalette pal;//��ɫ��
    QAction* play;//����
    QAction* pause;//��ͣ
    QAction* next;//��һ��
    QAction* pre;//��һ��
    QAction* back;//����
    QAction* action;//����Ƥ��
    QAction* action1;//Ĭ��Ƥ��1
    QAction* action2;//Ĭ��Ƥ��2
    QAction* action3;//Ĭ��Ƥ��3
    QAction* action4;//�Զ���Ƥ��
    QAction* Action;//����͸����
    QAction* Action1;//͸���ȼ�
    QAction* Action2;//͸���ȼ�
    QAction* quit;//�˳�
    QMenu* menu;//�Ҽ��˵�
    QMediaPlayer* music;//����
    QMediaPlaylist* playlist;//�����б�
    double TouMin;//͸����
//������
    QWinThumbnailToolBar* toolbar;//������������
    QWinThumbnailToolButton* next1;//��һ��
    QWinThumbnailToolButton* pre1;//��һ��
    QWinThumbnailToolButton* pause1;//����/��ͣ
    QWinTaskbarButton* Taskbotton;//������
    QWinTaskbarProgress* TaskProgress;//������������
    QString currentFile;
    QList<int> Index;
    bool flag = false;
};

#endif // DIALOG_H
