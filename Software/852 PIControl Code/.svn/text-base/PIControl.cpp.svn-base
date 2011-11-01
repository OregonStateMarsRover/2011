#include "PIControl.h"

PIControl::PIControl(double _kp, double _kiUp, double _kiDown, double _hClamp, double _lClamp)
{
	kiUp = _kiUp;
	hClamp = _hClamp;
	lClamp = _lClamp;
	kp = _kp;
	kiDown = _kiDown;
	integrator = 0;
}

double PIControl::Control(double _target, double _actual){
	double pi, ki;
	target = _target;
	actual = _actual;
	ki=kiUp;
	error = target - actual;
	if(integrator>0)
	{
		if(error<0) ki=kiDown;
	}
	else // integrator<0
	{
		if(error>0) ki=kiDown;
	}
	integrator += (ki*error);
	if(integrator>hClamp)integrator = hClamp;
	else if (integrator<lClamp) integrator = lClamp;
	
	pi = (kp*error)+integrator;
	return pi;
}
void PIControl::init(void)
{
	integrator = 0;
}

ostream& operator<<(ostream& stream, const PIControl& pi)
{
	stream<<"Error: "<<pi.error<<"\t"<<"Integrator: "<<pi.integrator<<" Target: "<<pi.target<<" Actual: "<<pi.actual<<"\t";
	return stream;
}



