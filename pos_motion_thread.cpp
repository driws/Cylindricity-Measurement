#include "pos_motion_thread.h"
#include <QDebug>
PosMotionThread::PosMotionThread(int axis, double destPos, double destVel):m_axis(axis),m_destPos(destPos),m_destVel(destVel)
{
	connect(this, SIGNAL(finished()), this, SLOT(deleteLater()));
}

void PosMotionThread::run()
{
	short sRtn;
	long sts;
	TTrapPrm trap;
	double dprfPos;
	sRtn = GT_PrfTrap(m_axis);
	sRtn = GT_GetTrapPrm(m_axis, &trap);
	trap.acc = 0.25;
	trap.dec = 0.125;
	trap.smoothTime = 25;
	sRtn = GT_SetTrapPrm(m_axis, &trap);
	sRtn = GT_SetPos(m_axis, m_destPos);
	sRtn = GT_SetVel(m_axis, m_destVel);
	sRtn = GT_Update(1 << (m_axis - 1));
	do
	{
		sRtn = GT_GetSts(m_axis, &sts);
	} while (sts & 0x400);
	sRtn = GT_AxisOff(m_axis);
	emit MotionFinished(m_axis);
}