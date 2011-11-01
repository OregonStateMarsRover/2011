#ifndef PICONTROL_H
#define PICONTROL_H

#include <iostream.h>

class PIControl
{
public:
	PIControl(double _kp, double _kiUp, double _kiDown, double _hClamp, double _lClamp);
	
	~PIControl(){}
	double Control(double _target, double _actual);
	friend ostream& operator<<(ostream& stream, const PIControl& pi);
	void init(void);
protected:
	double kiUp, kiDown, kp, integrator, error, target, actual, hClamp, lClamp;
private:
	PIControl();
};

ostream& operator<<(ostream& stream, const PIControl& pi);

#endif
