#include <QThread>
#include "./Resources/single_card/gts.h"

class PosMotionThread :  public QThread
{
	Q_OBJECT
public:
	PosMotionThread(int axis, double destPos, double destVel);
signals:
	void MotionFinished(int);
protected:
	void run();
private:
	int m_axis;
	double m_destPos;
	double m_destVel;
};