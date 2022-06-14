#include "StopWatch.h"
#include <ctime>

StopWatch::StopWatch()
{ 
	m_StartTime = clock();
}

StopWatch::~StopWatch()
{
}

unsigned int StopWatch::Get_StartTime()
{
	return m_StartTime;
}

unsigned int StopWatch::Get_EndTime()
{
	return m_EndTime;
}

void StopWatch::Start()
{
	m_StartTime = clock();
}

void StopWatch::Stop()
{
	m_EndTime = clock();
}

unsigned int StopWatch::Get_ElapsedTime()
{
	return m_EndTime - m_StartTime;
}
