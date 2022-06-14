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
		void Start(); // ���� �ð� ����
		void Stop(); // ���� �ð� ���� 
		unsigned int Get_ElapsedTime(); // ����ð� (���� �ð� - ���� �ð�)�� ms������ ��ȯ
};