#pragma once
#ifndef mathTools_h
#define mathTools_h

namespace mathTools
{
const long double Pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998;

float getwheelDistanceMoved(float ticksMoved, float wheelDiameter, float ticksPerRotation);

float getHypotenuse(float x, float y);

int sgn(float a);

float getDegrees(float x);

float getRadians(float x);

float round360(float given);

int direction360(float first, float second);

float distance360(float first, float second);

float radiansToGyro(float r);

} // namespace mathTools

#endif