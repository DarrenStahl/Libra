/*-------------------------------------*\
|
|  File Name: Keyboard.hpp
|
|  Creation Date: 21-11-2012
|
|  Last Modified:
|
|  Created By: Darren Stahl
|
\*-------------------------------------*/

#pragma once

#include "../IPeripheral.hpp"
#include <string>

class Keyboard : public IPeripheral {
	public:
		Keyboard();

		bool Put8(unsigned int port, unsigned int data);
		bool Put16(unsigned int port, unsigned int data);

		unsigned int Get8(unsigned int port);
		unsigned int Get16(unsigned int port);

		virtual void Dump();

        unsigned int GetType() { return PERIPH_KEYBOARD; }

        std::string GetStr();

	protected:

		int kbStatus, kbBuffer;
};
