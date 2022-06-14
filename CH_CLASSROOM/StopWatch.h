#include <ctime>

class StopWatch
{
	private :
		unsigned int m_StartTime;
		unsigned int m_EndTime;

	public :
		StopWatch(); 
		~StopWatch();
		unsigned int Get_StartTime();
		unsigned int Get_EndTime();
		void Start(); // 시작 시각 측정
		void Stop(); // 종료 시각 측정 
		unsigned int Get_ElapsedTime(); // 경과시간 (종료 시각 - 시작 시각)을 ms단위로 반환
};