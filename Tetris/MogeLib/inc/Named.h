#pragma once

#include <MOGE.h>
#include "GeneralUtilities.h"

namespace MOGE
{
	class MOGE_API Named
	{
	public:
		Named();
		virtual ~Named();

		void SetName( const String& name );
		const String& GetName()const;

	protected:
	private:
		String mName;

	};
}