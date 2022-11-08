#pragma once
#ifndef CONNECTION_H
#define CONNECTION_H
#include<QSqlDatabase>
#include<QSqlQuery>
#include<dwmapi.h>
#include<windowsx.h>
static bool CreatConnection()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");//����
    db.setDatabaseName("mymusic.db");
    if (!db.open())
    {
        return false;
    }
    QSqlQuery query;
    query.exec(QString("create table LocalMusic (id int,MusicName varchar,FileName varchar,biaoji int,primary key(id,MusicName,FileName))"));//���������б�����
    query.exec(QString("create table LikeMusic (id int,MusicName varchar,FileName varchar,primary key(id,MusicName,FileName))"));//��ϲ���б�����
    query.exec(QString("create table CollectMusic (id int,MusicName varchar,FileName varchar,primary key(id,MusicName,FileName))"));//���Ŷ�������
    query.exec(QString("create table WALLPAPER_DATA (FileName varchar primary key)"));//�����ڱ�ֽ����
    query.exec(QString("create table TRA_DATA (TRA double primary key)"));//������͸����
    query.exec(QString("create table Bizi_DATA (FileName varchar primary key)"));//�����ڱ�ֽ
    query.exec(QString("create table Toumin_DATA (TouMin double primary key)"));//������͸����
    return true;
}

#endif // CONNECTION_H
