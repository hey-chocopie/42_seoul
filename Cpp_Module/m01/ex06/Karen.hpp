#ifndef __KAREN_H__
#define __KAREN_H__
#include <string>
#include <iostream>

class karen{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

		struct widget
		{
			std::string str;
			void (karen::*ptr) (void);
		};
	public:
		void complain( std::string level );
};

#endif
