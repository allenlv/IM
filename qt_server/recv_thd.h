#ifndef RECV_THD_H_
#define RECV_THD_H_

#endif /*RECV_THD_H_*/
#include <QThread>
class recv_thd: public QThread
{
	Q_OBJECT
public:
	void run();
signals:
	void recv_msg_signal(QString);
	void err_msg_signal(QString);
};
