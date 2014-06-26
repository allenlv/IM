#include "qt_client.h"
#include "conn.cpp"
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <QMutex>
#include <QMessageBox>
QMutex mutex;
int sock;
qt_client::qt_client(QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	connect(&thd, SIGNAL( recv_msg_signal(QString) ), this, SLOT( update_msg(QString) ));
	connect(&thd, SIGNAL( err_msg_signal(QString) ), this, SLOT( err_msg_update(QString) ));
	connect(ui.pushButton, SIGNAL( clicked() ), this, SLOT( send_msg() ));
	connect(ui.pushButton_2, SIGNAL( clicked() ), this, SLOT( conn() ));
}

qt_client::~qt_client()
{
	
}

void qt_client::err_msg_update(QString s)
{
	ui.textEdit->append(s);
}
void recv_thd::run()
{
	int res;
	char msg[1024];
	while(1)
		{
			if( (res = recv(sock, msg, 1024, 0)) <= 0)
			{
                close(sock);
				emit err_msg_signal("<font color=red>lost connection</font>");
				break;
			}
			else
			{
				msg[res] = '\0';
				emit recv_msg_signal("<font color=green>" + QString::fromLatin1(msg) + "</font>");
			}
		}
}

void qt_client::send_msg()
{
	if(sock == -1 || sock == 0)
		{
			QMessageBox::about(this, "", "please connect first or reconnect");
		}
		else
		{
			QString s;
			s = ui.lineEdit->text();
			if(s == "")
			{
				QMessageBox::about(this, "", "empty");
			}
			else
			{
				ui.textEdit->append("<font color=blue> client : " + s + "</font>");
				send(sock, s.toLatin1().data(), strlen(s.toLatin1().data()), 0);
				ui.lineEdit->setText("");
				ui.lineEdit->setFocus();
			}
		}
}

void qt_client::conn()
{
	int re;
	QString ip = ui.lineEdit_2->text();
	re = conn_server(ip, "5150");
	switch(re)
	{
	case 0:
		QMessageBox::about(this, "", "create socket error");
		break;
	case 1:
		QMessageBox::about(this, "", "connect error");
		break;
	default:
		ui.textEdit->append("<font color=red>connect successed</font>");
		thd.start();
		break;
	}
}

void qt_client::update_msg(QString s)
{
	ui.textEdit->append("<font color=green> server : </font>" + s);
}
