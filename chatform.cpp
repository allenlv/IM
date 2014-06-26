#include "chatform.h"
#include "ui_chatform.h"
#include<QFile>

chatform::chatform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chatform)
{
    ui->setupUi(this);
}

chatform::chatform(QString usrname, QString peerIp, QString peerPort, QUdpSocket *udpSocket):ui(new Ui::chatform)
{
    this->usrname = usrname;
    this->serverIp = peerIp;
    this->serverPort = peerPort;
    this->udpSocket = udpSocket;
    ui->setupUi(this);
}

chatform::~chatform()
{
    delete ui;
}

void chatform::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void chatform::displayText(QString nickname, QString usrname, QString text)
{
    QString str=nickname + "(" + usrname + ") :\n" + text + "\n";
    QListWidgetItem *displayItem = new QListWidgetItem(str);
    ui->listWidget->addItem(displayItem);
    QString file="/home/allen/donkey_x/donkeyhead-client/"+usrname+".txt";
    saveHistory(file,str);
}

size_t chatform::saveHistory(QString historyFile,QString str)
{
    qDebug("I am in history");
    QFile file(historyFile);
    QTextStream stream (&file);

    if(file.open(QIODevice::WriteOnly|QIODevice::Append))
    {
        stream<<str;
        file.close();
        return 0;
    }
    return 1;
}

size_t chatform::showHistory(QString historyFile)
{
    QString str;
    QFile *file=new QFile(historyFile);
    if(!QFile::exists(historyFile))
    {
        QFile file(historyFile);
        file.open(QIODevice::WriteOnly);
        file.close();
    }
    file->open(QIODevice::ReadOnly|QIODevice::Text);
    str= QString(file->readAll());
    qDebug("I am here");
    QListWidgetItem *displayItem = new QListWidgetItem(str);
    ui->listWidget->addItem(displayItem);
    return 0;
}


void chatform::on_sendButton_clicked()
{
    QString sendText = ui->textEdit->toPlainText();
       if(!sendText.isEmpty())
       {

           QString windowTitle = this->windowTitle().replace("].","");
           QString toId = QString(windowTitle.split("[").at(1));
           QString msgType = "MSG_CLIENT_CHAT";
           QByteArray block;
           QDataStream out(&block, QIODevice::WriteOnly);
           out.setVersion(QDataStream::Qt_4_6);
           out << (quint16)0 << msgType << usrname << toId << sendText;
           out.device()->seek(0);

           out << (quint16)(block.size() - sizeof(quint16));

           udpSocket->writeDatagram(block.data(), block.size(), QHostAddress(serverIp), (quint16)serverPort.toUInt()+1);

           QString str="I say :\n" + sendText + "\n";
           ui->listWidget->addItem(str);
           QString fileName="/home/allen/donkey_x/donkeyhead-client/"+toId+".txt";
           if(!QFile::exists(fileName))
           {
               QFile file(fileName);
               file.open(QIODevice::WriteOnly);
               file.close();
           }
           saveHistory(fileName,str);
       }
       ui->textEdit->clear();
}

void chatform::closeEvent(QCloseEvent *e)
{
    ui->listWidget->clear();
    ui->textEdit->clear();
}


void chatform::on_pushButton_clicked()
{
  ui->listWidget->setStyleSheet("background-image: url(:/new/prefix1/6.jpg);");
}

void chatform::on_pushButton_2_clicked()
{
    ui->listWidget->setStyleSheet("background-image: url(:/new/prefix1/2.jpg);");
}

void chatform::on_pushButton_3_clicked()
{
    ui->listWidget->setStyleSheet("background-image: url(:/new/prefix1/1.jpg);");
}
void chatform::mousePressEvent(QMouseEvent *event)
{
    this->windowPos = this->pos();
            this->mousePos = event->globalPos();
            this->dPos = mousePos - windowPos;
}

void chatform::mouseMoveEvent(QMouseEvent *event)
{
     this->move(event->globalPos() - this->dPos);

}

void chatform::on_pushButton_4_clicked()
{
    this->close();
}
