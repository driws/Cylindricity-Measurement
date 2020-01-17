#ifndef KALMAN_FILTER_H
#define KALMAN_FILTER_H
#include <Eigen\Dense>
#include <Eigen\Core>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QDebug>
using Eigen::VectorXd;
using Eigen::MatrixXd;


class KalmanFilter
{
private:
	int state_size;
	int meas_size;
	int usize;
	VectorXd x;
	VectorXd y;
	MatrixXd A;
	MatrixXd B;
	VectorXd u;
	MatrixXd P;
	MatrixXd H;
	MatrixXd R;
	MatrixXd Q;
public:
	KalmanFilter(int state_size_, int meas_size_, int usize_);
	~KalmanFilter();
	int get_state_size() const { return state_size; };
	int get_meas_size() const { return meas_size; };
	int get_usize() const { return usize; };
	void Init(QString filename);
	void Predict(VectorXd xprev);
	VectorXd Update(VectorXd y_meas);

};
#endif // !KALMAN_FILTER_H
