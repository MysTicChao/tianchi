// ********************************************************************************************************************
// Tianchi C++ library for Qt (open source)
// ��ع���Դ���
// ��Ȩ���� (C) ��ع���Դ��⿪����
// ��ȨЭ�飺���Ķ���ع���Դ��⸽������ȨЭ��
// ********************************************************************************************************************
// �ĵ�˵����HTTP �ļ����߳�������
// ====================================================================================================================
// ������־��
// ����         ��Ա        ˵��
// --------------------------------------------------------------------------------------------------------------------
// 2013.04.19   ʥ������    ����
//
// ====================================================================================================================
/// @file DownloadHttp.h HTTP �ļ����߳�������
#ifndef TIANCHI_DOWNLOADHTTP_H
#define TIANCHI_DOWNLOADHTTP_H

#include "Global.h"

#include <QtCore>
#include <QtNetwork>

TIANCHI_BEGIN_NAMESPACE

/// @brief ���������ļ������ļ���һ���֣�
/// ע�⣺������δ�����ϸ����
/// @author ���Ի�����
/// @date 2013-04-19
class TIANCHI_API Download : public QObject
{
    Q_OBJECT

public:
    Download(int index, QObject *parent = 0);
    void StartDownload(const QUrl &url, QFile* file, qint64 startPoint=0, qint64 endPoint=-1);

signals:
    void DownloadFinished();

public slots:
    void FinishedSlot();
    void HttpReadyRead();

private:
    QNetworkAccessManager   m_Qnam;
    QNetworkReply*          m_Reply;
    QFile*                  m_File;

    const int   m_Index;
    qint64      m_HaveDoneBytes;
    qint64      m_StartPoint;
    qint64      m_EndPoint;

};

// ���ڹ����ļ�������
/// @brief ���ڹ����ļ�������
class TIANCHI_API DownloadList : public QObject
{
    Q_OBJECT
public:
    DownloadList(QObject *parent = 0);

    void StartFileDownload(const QString &url, int count);
    qint64 GetFileSize(QUrl url);

signals:
    void FileDownloadFinished();

private slots:
    void SubPartFinished();

private:
    int m_DownloadCount;
    int m_FinishedNum;
    int m_FileSize;
    QUrl m_Url;
    QFile *m_File;
};

TIANCHI_END_NAMESPACE

#endif // TIANCHI_DOWNLOADHTTP_H