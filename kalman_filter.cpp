#include "kalman_filter.h"

KalmanFilter::KalmanFilter(int state_size_, int meas_size_, int usize_)
{
	state_size = state_size_;
	meas_size = meas_size_;
	usize = usize_;
	x.resize(state_size);
	x.setZero();

	A.resize(state_size, state_size);
	A.setIdentity(); //µ•Œªæÿ’Û

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

void KalmanFilter::Init(QString filename)
{
	QFile fp(filename);
	QStringList numList;
	QString line;
	QVector<MatrixXd*> paramVector;
	int row, col;
	paramVector.push_back(&A);
	paramVector.push_back(&B);
	paramVector.push_back(&H);
	paramVector.push_back(&P);
	paramVector.push_back(&Q);
	paramVector.push_back(&R);

	if (fp.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream in(&fp);
		for (int k = 0; k < paramVector.size(); k++)
		{
			line = in.readLine();
			line = in.readLine();
			numList = line.split(" ");
			row = numList[0].toInt();
			col = numList[1].toInt();
			paramVector[k]->setZero(row, col);
			for (int i = 0; i < row; i++)
			{
				line = in.readLine();
				numList = line.split(" ");
				for (int j = 0; j < col; j++)
				{
					(*paramVector[k])(i, j) = numList[j].toDouble();
				}
			}
		}
	}

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
