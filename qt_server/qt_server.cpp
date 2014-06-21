#include "qt_server.h"
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <QMessageBox>
#include <QMutex>
#include <sys/ioctl.h>
#include <net/if.h>
int sock;
QString client_info;
QMutex mutex;

qt_server::qt_server(QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	connect(&thd, SIGNAL( recv_msg_signal(QString) ), this, SLOT( update_msg(QString) ));
	connect(&thd, SIGNAL( err_msg_signal(QString) ), this, SLOT( err_msg_update(QString) ));
	thd.start();
	connect(ui.pushButton, SIGNAL( clicked() ), this, SLOT( send_msg() ));
	
	int inet_sock;
	struct ifreq ifr;

	inet_sock = socket(AF_INET, SOCK_DGRAM, 0);
	strcpy(ifr.ifr_name, "eth0");
	ioctl(inet_sock, SIOCGIFADDR, &ifr);
	ui.textEdit->append("local ip address is : "
			+ QString::fromLatin1(inet_ntoa(((struct sockaddr_in*)&(ifr.ifr_addr))->sin_addr)) );
}

qt_server::~qt_server()
{

}
void qt_server::send_msg()
{
	if(sock == -1 || sock == 0)
			{
				QMessageBox::about(this, "", "client have not connected yet");
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
					ui.textEdit->append("<font color=green>server : " + s + "</font>");
					send(sock, s.toLatin1().data(), strlen(s.toLatin1().data()), 0);
					ui.lineEdit->setText("");
					ui.lineEdit->setFocus();
				}
			}
}

void qt_server::err_msg_update(QString s)
{
	ui.textEdit->append("<font color=red>" + s + "</font>");
}
void qt_server::update_msg(QString s)
{
	ui.textEdit->append("<font color=blue>client  : " + s + "</font>");
}

void recv_thd::run()
{
		char msg[1024];
		int Listen_socket;
		struct sockaddr_in local_addr;
		struct sockaddr_in client_addr;
		if( (Listen_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
		{
			emit err_msg_signal("failed create socket");
		}
		local_addr.sin_family = AF_INET;
		local_addr.sin_port = htons(5150);
		local_addr.sin_addr.s_addr = INADDR_ANY;
		
		if(bind(Listen_socket, (struct sockaddr*)&local_addr, sizeof(struct sockaddr)) == -1)
		{
			emit err_msg_signal("failed bind");
		}
		
		if(listen(Listen_socket, 5) == -1)
		{
			emit err_msg_signal("failed listen");
		}
		socklen_t addr_size;
		addr_size = sizeof(struct sockaddr_in);
		mutex.lock();
		if((sock = accept(Listen_socket, (struct sockaddr *)&client_addr, &addr_size)) == -1)
		{
				emit err_msg_signal("failed accept");
		}
		else
		{
			emit err_msg_signal("client ip: " + QString::fromLatin1(inet_ntoa(client_addr.sin_addr)) + 
					" port: " + QString::number(ntohs(client_addr.sin_port)));
		}
		mutex.unlock();
	
		int res;
		while(1)
		{
			if( (res = recv(sock, msg, 1024, 0)) <= 0)
			{
				close(sock);
				emit err_msg_signal("lost client");
				break;
			}
			else
			{
				msg[res] = '\0';
				emit recv_msg_signal(QString::fromLatin1(msg));
			}
		}
}
