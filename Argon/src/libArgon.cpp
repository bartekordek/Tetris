#include "libArgon.hpp"
#include "File.h"

#include <iostream>
#include <iomanip> 
#include <cmath>

V3D::V3D( const double values ): val{ values, values, values }
{
    calcMod();
}

V3D::V3D( const double x, const double y, const double z ): val{ x, y, z }
{
    calcMod();
}

V3D::V3D( const V3D& v3d )
{
    this->val[0] = v3d.val[0];
    this->val[1] = v3d.val[1];
    this->val[2] = v3d.val[2];
    m_mod = v3d.m_mod;
}

V3D& V3D::operator=( const V3D& v3d )
{
    if( &v3d != this )
    {
        this->val[0] = v3d.val[0];
        this->val[1] = v3d.val[1];
        this->val[2] = v3d.val[2];
        m_mod = v3d.m_mod;
    }    
    return *this;
}

double V3D::operator-( const V3D& v3d )const
{
    const double dx2 = std::pow( this->val[0] - v3d.val[0], 2 );
    const double dy2 = std::pow( this->val[1] - v3d.val[1], 2 );
    const double dz2 = std::pow( this->val[2] - v3d.val[2], 2 );
    return std::sqrt( dx2 + dy2 + dz2 );
}

V3D& V3D::operator+=( const V3D& v3d )
{
    for( unsigned int i = 0; i < 3; ++i )
    {
        this->val[i] = this->val[i] + v3d.val[i];
    }
    calcMod();
    return *this;
}

void V3D::calcMod()
{
    const double dx2 = std::pow( this->val[0], 2 );
    const double dy2 = std::pow( this->val[1], 2 );
    const double dz2 = std::pow( this->val[2], 2 );
    m_mod = std::sqrt( dx2 + dy2 + dz2 );
}

void V3D::Set( const double val )
{
    this->val[0] = val;
    this->val[1] = val;
    this->val[2] = val;
    calcMod();
}

const double V3D::getAxisValue( const Axis axis )const
{
    return this->val[ static_cast<const unsigned long>( axis ) ];
}

const double V3D::GetX()const
{
    return this->val[static_cast<const unsigned long>( Axis::X )];
}

const double V3D::GetY()const
{
    return this->val[static_cast<const unsigned long>( Axis::Y )];
}

const double V3D::GetZ()const
{
    return this->val[static_cast<const unsigned long>( Axis::Z )];
}

const double V3D::mod()const
{
    return m_mod;
}

void V3D::SetX( const double x )
{
    this->val[static_cast<const unsigned long>( Axis::X )] = x;
    calcMod();
}

void V3D::SetY( const double y )
{
    this->val[static_cast<const unsigned long>( Axis::Y )] = y;
    calcMod();
}

void V3D::SetZ( const double z )
{
    this->val[static_cast<const unsigned long>( Axis::Z )] = z;
    calcMod();
}

Atom::Atom( const double val ):
    R( val ), 
    F( val ),
    FS( val ),
    P( val ),
    KE( val )
{
}

Atom::Atom( const double x, const double y, const double z )
{
    R.SetX( x );
    R.SetY( y );
    R.SetZ( z );
}

double Atom::operator-( const Atom& atom )const
{
    return sqrt( 
            ( R.GetX()-atom.R.GetX() )*( R.GetX()-atom.R.GetX() ) + 
            ( R.GetY()-atom.R.GetY() )*( R.GetY()-atom.R.GetY() ) + 
            ( R.GetZ()-atom.R.GetZ() )*( R.GetZ()-atom.R.GetZ() ));
}

Atom& Atom::operator=( const Atom& atom )
{
    if( &atom != this )
    {
        R = atom.R;
        F = atom.F;
        FS = atom.FS;
        P = atom.P;
        KE = atom.KE;
    }
    return *this;
}

double Argon::BoltzmanConst = 0.0;
double Argon::a = 0.0;
double Argon::electronCharge = 0.0;

Argon::Argon( const std::string& dataFname, const std::string& outputFname ): 
    m_fileName( dataFname ), 
    outputFilename( outputFname ), 
    P( 0.0 ), KE( 0.0 )
{
}

const Atom& Argon::operator[]( const unsigned index )const
{
    return atom[ index ];
}

Atom& Argon::operator[]( const unsigned index )
{
    return atom[ index ];
}

bool Argon::Init()
{
    if( false == InitializeVariables( m_fileName ) )
    {
        return false;
    }
    SetPositions();
    CalcMomKin();
    return true;
}

void Argon::ResizeStructure( const unsigned size )
{
    std::cout<< "Resizing structure to " << size << " elemnts." << std::endl;
    atom.resize( size );
}

double Argon::RanD() 
{
    return ( rand())*1.0/( RAND_MAX );
}


const bool Argon::InitializeVariables( const std::string& filename )
{
    Moge::File file;
    file.loadFile( Moge::Path( filename ) );
    if( file.isEmpty() )
    {
        const std::string errorTxt = "Could not open file " + filename + ".\n";
        std::cerr << errorTxt;
        return false;
    }
    std::cout<< "InitializeVariables()"<< std::endl;
    dimensions = 3;
    size1x                     = atoi( file.getLine(1).c_str());
    mass                    = atof( file.getLine(3).c_str());
    electronCharge            = atof( file.getLine(5).c_str());
    BoltzmanConst            = atof( file.getLine(7).c_str());
    elasticCoefficient         = atoi( file.getLine(9).c_str());
    length                     = atof( file.getLine(11).c_str());
    a                         = atof( file.getLine(13).c_str());
    startTemp                 = atof( file.getLine(15).c_str());
    tau                     = atof( file.getLine(17).c_str());
    loops                     = atoi( file.getLine(19).c_str());
    loopFrame                = atoi( file.getLine(21).c_str());
    size3x                     = size1x * size1x * size1x;
    B.resize(dimensions);
    B[0]=V3D(a,         0.0, 0.0);
    B[1]=V3D(a/2.0, a*sqrt(3.0)/2.0, 0.0 );
    B[2]=V3D(a/2.0, a*sqrt(3.0)/6.0, a*sqrt(2.0/3.0) );
    std::cout<<"Filename: \t\t"<<filename<<"\n";
    std::cout<<"Size = \t\t\t"<<size1x<<"("<<size3x<<")"<<"\n";
    std::cout<<"Mass = \t\t\t"<<mass<<"\n";
    std::cout<<"electronCharge = \t"<<std::setprecision(4)<<std::showpos<<std::fixed<<electronCharge<<"\n";
    std::cout<<"elastic coefficient = \t"<<std::setprecision(4)<<std::showpos<<std::fixed<<elasticCoefficient<<"\n";
    std::cout<<"length = \t\t"<<length<<"\n";
    std::cout<<"a-a length = \t\t"<<a<<"\n";
    std::cout<<"startTemp = \t\t"<<startTemp<<"\n";
    std::cout<<"tau = \t\t\t"<<tau<<"\n";
    std::cout<<"B 0 = "<<B[0].GetX() << ", " << B[0].GetY() << ", " << B[0].GetZ();
    std::cout << "B 1 = " << B[1].GetX() << ", " << B[1].GetY() << ", " << B[1].GetZ();
    std::cout << "B 2 = " << B[2].GetX() << ", " << B[2].GetY() << ", " << B[2].GetZ();
    std::cout<<"Resizing forces, momentums and positions to atom number ("<<size3x<<").\n";
    ResizeStructure(size3x);
    return true;
}

void Argon::SetPositions()
{
    unsigned i=0;
    for( unsigned xIndex = 0; xIndex < size1x; ++xIndex )
    {
        for( unsigned yIndex = 0; yIndex < size1x; ++yIndex )
        {
            for( unsigned zIndex = 0; zIndex < size1x; ++zIndex )
            {
                atom[i].R.SetX(
                            (xIndex - 0.5*( size1x - 1 ))*B[0].GetX() +
                            (yIndex - 0.5*( size1x - 1 ))*B[1].GetX() +
                            (zIndex - 0.5*( size1x - 1 ))*B[2].GetX()
                        );
                atom[i].R.SetY(
                            (xIndex - 0.5*( size1x - 1 ))*B[0].GetY() +
                            (yIndex - 0.5*( size1x - 1 ))*B[1].GetY() +
                            (zIndex - 0.5*( size1x - 1 ))*B[2].GetY()
                        );
                atom[i].R.SetZ(
                            (xIndex - 0.5*( size1x - 1 ))*B[0].GetZ() +
                            (yIndex - 0.5*( size1x - 1 ))*B[1].GetZ() +
                            (zIndex - 0.5*( size1x - 1 ))*B[2].GetZ()
                        );
                ++i;
            }        
        }
    }
}

void Argon::CalcMomKin()
{
    startTemp = 2.0/(3.0*BoltzmanConst*size3x);
    CalcKE();
    CalcMom();
    for( unsigned i = 0; i<size3x; ++i )
    {
        atom[i].P.SetX
            (
             atom[i].P.GetX() - 1.0*atom[i].P.GetX()/size3x 
            );
        atom[i].P.SetY
            (
             atom[i].P.GetY() - 1.0*atom[i].P.GetY()/size3x 
            );
        atom[i].P.SetZ
            (
             atom[i].P.GetZ() - 1.0*atom[i].P.GetZ()/size3x 
            );

        atom[ i ].KE = V3D( 
            atom[ i ].P.GetX() / ( 2.0*mass ),
            atom[ i ].P.GetY() / ( 2.0*mass ),
            atom[ i ].P.GetZ() / ( 2.0*mass ) );
        startTemp += atom[i].KE.mod(); 
    }
    CalcForces();
}

void Argon::CalcKE()
{
    for( auto& atom: this->atom )
    {
        atom.KE.SetX( calcKePerAxis( startTemp ) );
        atom.KE.SetY( calcKePerAxis( startTemp ) );
        atom.KE.SetZ( calcKePerAxis( startTemp ) );
    }
}

const double Argon::calcKePerAxis( const double temp )
{
    return -0.5*BoltzmanConst*temp*log( RanD() );
}

void Argon::CalcMom()
{
    for( unsigned i=0; i<size3x; ++i )
    {
        for( unsigned int i = 0; i < static_cast<unsigned int>( Axis::SIZE ); ++i )
        {
            atom[i].P.SetX( ( RanD() >= 0.5 )?(-1):1 * sqrt( 2.0*mass*atom[i].KE.GetX() ) );
        }
        P.SetX( P.GetX() + atom[ i ].P.GetX() );
        P.SetY( P.GetY() + atom[ i ].P.GetY() );
        P.SetZ( P.GetZ() + atom[ i ].P.GetZ() );
    }
}

void Argon::MainLoopIteration()
{
    PosAct();
    setNullForces();
    CalcForces();
    MomentumAct();
}

void Argon::PosAct()
{
    for( auto& atom : this->atom )
    {
        atom.R.SetX( atom.R.GetX() + 1.0*atom.P.GetX()*tau / mass );
        atom.R.SetY( atom.R.GetY() + 1.0*atom.P.GetY()*tau / mass );
        atom.R.SetZ( atom.R.GetZ() + 1.0*atom.P.GetZ()*tau / mass );
    }
}

void Argon::setNullForces()
{
    for( auto& atom : this->atom )
    {
        atom.F.Set( 0.0 );
    }
}

void Argon::CalcForces()
{
    for( unsigned i = 0; i<size3x; ++i )
    {
        Atom& atom = this->atom[i];
        if( atom.R.mod() > length )
        {
            atom.F.SetX( atom.F.GetX() + elasticCoefficient*( length - atom.R.mod() )*atom.R.GetX() / atom.R.mod() );
            atom.F.SetY( atom.F.GetY() + elasticCoefficient*( length - atom.R.mod() )*atom.R.GetY() / atom.R.mod() );
            atom.F.SetZ( atom.F.GetZ() + elasticCoefficient*( length - atom.R.mod() )*atom.R.GetZ() / atom.R.mod() );
        }

        for( unsigned j = 0; j<i; ++j )
        {
            SetForces( i, j );
            SetForces( j, i );
        }
    }
}

void Argon::SetForces( const unsigned at1Index, const unsigned at2Index )
{
    Atom& at1 = this->atom[at1Index];
    const Atom& at2 = this->atom[at2Index];
    const double delta = at1.R - at2.R;
    const double delta2 = std::pow( at1.R - at2.R, 2 );
    at1.F.SetX( at1.F.GetX() + 12.0*electronCharge*
        ( std::pow( a / delta, 12 ) - std::pow( a / delta, 6 ) )* ( ( at1.R.GetX() - at2.R.GetX() ) / delta2 ) );

    at1.F.SetY( at1.F.GetY() + 12.0*electronCharge* 
        ( std::pow( a / delta, 12 ) - std::pow( a / delta, 6 ) )* ( ( at1.R.GetY() - at2.R.GetY() ) / delta2 ) );

    at1.F.SetZ( at1.F.GetZ() + 12.0*electronCharge*
        ( std::pow( a / delta, 12 ) - std::pow( a / delta, 6 ) )* ( ( at1.R.GetZ() - at2.R.GetZ() ) / delta2 ) );
}

void Argon::MomentumAct()
{
    for( auto& atom : this->atom )
    {
        atom.P.SetX( atom.P.GetX() + 0.5*tau*atom.F.GetX() );
        atom.P.SetY( atom.P.GetY() + 0.5*tau*atom.F.GetY() );
        atom.P.SetZ( atom.P.GetZ() + 0.5*tau*atom.F.GetZ() );
    }
}

void Argon::MainLoop()
{
    Moge::File result;
    for( unsigned s = 0; s<loops; ++s )
    {
        if(s%loopFrame == 0)
        {
            result.addLine( std::to_string( size3x ) + "\nARGON" );
        }
        MainLoopIteration();
 
        if( 0 == s%loopFrame )
        {
            for( auto it = this->atom.begin(); it != this->atom.end(); ++it )
            {
                const auto index = it - this->atom.begin();
                result.addLine(
                    "ATOM" + std::to_string( index + 1 ) + 
                    "\t" + std::to_string( atom[index].R.GetX() ) +
                    "\t" + std::to_string( atom[index].R.GetY() ) +
                    "\t" + std::to_string( atom[index].R.GetZ() ));
            }
            std::cout.precision(0);
            std::cout<<"Wykonano "<<std::setw(4)<<std::noshowpos<<(s*100.0/loops)<<"%\n";
        }
    }
    
    result.writeContents2( Moge::Path( this->outputFilename ) );
}