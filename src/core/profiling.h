/*
 * This engine was built uppon
 * tutorials created by: Copyright (C) 2014 Benny Bobaganoosh.
 * The above tutorials served as the base on which
 * this engine was developed further by Kyle Pearce.
 * The game created using this engine has been entirly
 * created by Kyle Pearce.
 */

#ifndef PROFILING_H_INCLUDED
#define PROFILING_H_INCLUDED

#include <string>

#define PROFILING_DISABLE_MESH_DRAWING 0
#define PROFILING_DISABLE_SHADING 0
#define PROFILING_SET_1x1_VIEWPORT 0
#define PROFILING_SET_2x2_TEXTURE 0

class ProfileTimer
{
public:
	ProfileTimer() :
		m_numInvocations(0),
		m_totalTime(0.0),
		m_startTime(0) {}

	void StartInvocation();
	void StopInvocation();
	
	double DisplayAndReset(const std::string& message, double divisor = 0, int displayedMessageLength = 40);
	double GetTimeAndReset(double divisor = 0);
protected:
private:
	int    m_numInvocations;
	double m_totalTime;
	double m_startTime;
};

#endif // PROFILING_H_INCLUDED
