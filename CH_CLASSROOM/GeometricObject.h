#pragma once


class GeometricObject
{
	private:
		double m_x, m_y;

	public:
		double Get_X();
		double Get_Y();
		bool IsContains(double x, double y);
};