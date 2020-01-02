#include "kalman_filter.h"

KalmanFilter::KalmanFilter(int state_size_, int meas_size_, int usize_)
{
	if (state_size_ == 0 || meas_size_ == 0)
	{
		std::cerr << "状态向量和输出向量的大小都应大于0\n";
	}
	state_size = state_size_;
	meas_size = meas_size_;
	usize = usize_;
	x.resize(state_size);
	x.setZero();

	A.resize(state_size, state_size);
	A.setIdentity(); //单位矩阵

	u.resize(usize);
	u.setZero();

	B.resize(state_size, usize);
	B.setIdentity();

	P.resize(state_size, state_size);
	P.setIdentity();

	H.resize(meas_size, state_size);
	H.setIdentity();

	Q.resize(state_size, state_size);
	Q.setIdentity();

	y.resize(meas_size);
	y.setZero();

	R.resize(meas_size, meas_size);
	R.setIdentity();
}


KalmanFilter::~KalmanFilter()
{

}

void KalmanFilter::Init()
{

	A << 1,1,0,0,0,0,
		0,1,0,0,0,0,
		0,0,1,1,0,0,
		0,0,0,1,0,0,
		0,0,0,0,1,1,
		0,0,0,0,0,1;
	P << 50000, 0, 0, 0, 0, 0,
		0, 30000, 0, 0, 0, 0,
		0, 0, 50000, 0, 0, 0,
		0, 0, 0, 30000, 0, 0,
		0, 0, 0, 0, 50000, 0,
		0, 0, 0, 0, 0, 30000;
	Q << 1, 0, 0, 0, 0, 0,
		0, 1, 0, 0, 0, 0,
		0, 0, 1, 0, 0, 0,
		0, 0, 0, 1, 0, 0,
		0, 0, 0, 0, 1, 0,
		0, 0, 0, 0, 0, 1;
	R << 150, 0, 0,
		0, 150, 0,
		0, 0, 150;
	H << 1, 0, 0, 0, 0, 0,
		0, 0, 1, 0, 0, 0,
		0, 0, 0, 0, 1, 0;
}

void KalmanFilter::Predict(VectorXd xprev)
{
	x = A*x;
	P = A*P*A.transpose() + Q;
}

VectorXd KalmanFilter::Update(VectorXd y_meas)
{
	MatrixXd K = P*H.transpose()*(H*P*H.transpose() + R).inverse();
	y = H*x;
	x = x + K*(y_meas - y);
	Eigen::MatrixXd I = Eigen::MatrixXd::Identity(state_size, state_size);
	P = (I - K*H)*P;
	return x;
}
