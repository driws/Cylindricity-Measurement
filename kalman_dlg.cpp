#include "kalman_dlg.h"

KalmanDlg::KalmanDlg(QWidget *parent):QDialog(parent)
{
	ui.setupUi(this);
	this->setWindowIcon(QIcon("Resources/pic/ava.ico"));
}



KalmanDlg::~KalmanDlg()
{

}


void KalmanDlg::Predict(VectorXd xprev)
{
	x = A*x;
	P = A*P*A.transpose() + Q;
}

VectorXd KalmanDlg::Update(VectorXd y_meas)
{
	MatrixXd K = P*H.transpose()*(H*P*H.transpose() + R).inverse();
	y = H*x;
	x = x + K*(y_meas - y);
	Eigen::MatrixXd I = Eigen::MatrixXd::Identity(state_size, state_size);
	P = (I - K*H)*P;
	return x;
}