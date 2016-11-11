#pragma once

namespace Moge
{
class Scale
{
public:
	Scale();
	virtual ~Scale();

	virtual void setScale( const double scale ) = 0;
	virtual void setXscale( const double scale ) = 0;
	virtual void setYscale( const double scale ) = 0;
	virtual void setZscale( const double scale ) = 0;

	virtual const double getScale() = 0;
	virtual const double getXscale() = 0;
	virtual const double getYscale() = 0;
	virtual const double getZscale() = 0;
};
}