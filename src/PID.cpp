#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID():
	_Kp(0),
	_Ki(0),
	_Kd(0),
	_p_error(0),
	_i_error(0),
	_d_error(0)
{

}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	_Kp = Kp;
	_Ki = Ki;
	_Kd = Kd;
}

void PID::UpdateError(double cte) {

	_d_error = cte - _p_error;
	_p_error = cte;
	_i_error += cte;
}

double PID::TotalError() {
	double totalErr = (- _Kp * _p_error) + (- _Ki * _i_error) + (- _Kd * _d_error);
	return totalErr;
}

