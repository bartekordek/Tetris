#pragma once

#include <string>
#include <vector>

enum class Axis: short
{
	X = 0,
	Y,
	Z,
	SIZE
};

class V3D
{
public:
	V3D();
	V3D( const double values );
	V3D( const double x, const double y, const double z );
	V3D( const V3D& v3d );
	virtual ~V3D();
	V3D& operator=( const V3D& v3d );
	double operator-( const V3D& v3d )const;
	void Set( const double val );

	const double getAxisValue( const Axis axis )const;
	const double GetX()const;
	const double GetY()const;
	const double GetZ()const;
	const double GetMod()const;

	void SetX( const double x );
	void SetY( const double y );
	void SetZ( const double z );

private:
	void calcMod();

	double val[3] = { 0.0, 0.0, 0.0 };
	double m_mod = 0.0;
};

class Atom
{
public:
	/**Position, forces, elastic forces, momentum and kinetic energy.*/
	V3D R, F, FS, P, KE;
	Atom();
	Atom( const double val );
	Atom( const double x, const double y, const double z );
	virtual ~Atom();

	double operator-( const Atom& atom )const;
	Atom& operator=( const Atom& atom );
private:

};

class Argon
{
public:
	Argon( const std::string& fileName );
	virtual ~Argon();
	const Atom& operator[]( const unsigned index )const;
	Atom &operator[]( const unsigned index );
	bool Init();
	void MainLoop();
	void MainLoopIteration();

private:
	void SetForces( const unsigned at1Index, const unsigned at2Index );
	static double RanD();
	void MomentumAct();
	void PosAct();
	void setNullForces();
	const bool InitializeVariables( const std::string& filename );
	void ResizeStructure( const unsigned size );
	void SetPositions();
	void CalcKE();
	static const double calcKePerAxis( const double temp );
	void CalcMomKin();
	void CalcMom();
	void CalcForces();

	std::string m_fileName;

	V3D P, KE;
	std::vector< V3D > B;
	std::vector< Atom > atom;
	std::string outputFilename;
	unsigned size1x = 0;
	unsigned size3x = 0; 
	unsigned dimensions = 0;
	unsigned loops = 0;
	unsigned loopFrame = 0;
	double mass = 0.0;
	double elasticCoefficient = 0.0;
	double length = 0.0;
	double startTemp = 0.0;
	double tau = 0.0;
	static double BoltzmanConst;
	static double a;
	static double electronCharge;
};