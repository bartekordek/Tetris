#ifndef __ORIENTATION_YY__
#define __ORIENTATION_YY__

#include <bitset>

/*
 * @brief Class to handle orientation. 
 */
class COrientation
{
public:
	enum Direction{ L, R, U, D };

	COrientation( const Direction direction = R );

	/*
	 * @brief Sets orientation. 
	 * @param[in] Direction orientation. 
	 */
	void Set( const Direction direction );
	/*
	 * @brief Gets orientation. 
	 * @param[in] Direction orientation. 
	 */
	const Direction Get()const;

private:
	Direction m_direction;

};
#endif
