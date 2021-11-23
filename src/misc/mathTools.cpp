#include "misc/mathTools.h"
#include <cmath>

namespace mathTools
{
float getwheelDistanceMoved(float ticksMoved, float wheelDiameter, float ticksPerRotation)
{
	long double x  = Pi;
	return (ticksMoved / ticksPerRotation) * (wheelDiameter * Pi);
}

float getHypotenuse(float x, float y)
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

int sgn(float a)
{
	if (a > 0)
	{
		return 1;
	}
	else if (a < 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

float getDegrees(float x)
{
	return x * (180 / Pi);
}

float getRadians(float x)
{
	return x * (Pi / 180);
}

float round360(float given)
{
	if ((given >= 360) || (given <= -360))
	{
		given = fmod(given, 360);
	}
	if (given < 0)
	{
		given = given + 360;
	}
	return given;
}

int direction360(float first, float second)
{
	second = round360(second);
	first = round360(first);
	if (first < second)
	{
		if ((second - first) < ((360 - second) + first))
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
	else if (first > second)
	{
		if ((first - second) < ((360 - first) + second))
		{
			return -1;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		return 0;
	}
}

float distance360(float first, float second)
{
	first = round360(first);
	second = round360(second);
	float distance = 0;
	if (second < first)
	{
		if ((first - second) < ((3600 - first) + second))
		{
			distance = (first - second);
		}
		else
		{
			distance = ((3600 - first) + second);
		}
	}
	else if (second > first)
	{
		if ((second - first) < ((3600 - second) + first))
		{
			distance = (second - first);
		}
		else
		{
			distance = ((3600 - second) + first);
		}
	}
	else
	{
		distance = 0;
	}
	distance = distance * direction360(first, second);
	return distance;
}

float radiansToGyro(float r)
{
	r = getDegrees(r);
	r = -r;
	r = round360(r);
	r = r - 90;
	r = round360(r);
	return r;
}
} // namespace mathTools