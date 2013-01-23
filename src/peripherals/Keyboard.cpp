/*-------------------------------------*\
|
|  File Name: Keyboard.cpp
|
|  Creation Date: 21-11-2012
|
|  Last Modified:
|
|  Created By: Darren Stahl
|
\*-------------------------------------*/

#include "Keyboard.hpp"

#include <cstring>
#include <iostream>
#include <sstream>

Keyboard::Keyboard(){
	kbStatus = 0;
	kbBuffer = 0;
}

void Keyboard::Dump() {

}

bool Keyboard::Put16(unsigned int port, unsigned int data) {
	return false;
}

bool Keyboard::Put8(unsigned int port, unsigned int data) {
	return false;
}

unsigned int Keyboard::Get8(unsigned int port) {
	switch(port) {
	case 0x0001: //Status
		return kbStatus;
	case 0x0060: //Data Buffer
		return kbBuffer;
	}
	return 0xFFFFFFFF;
}

unsigned int Screen::Get16(unsigned int port) {
	switch(port) {
	case 0x04E8: //Control
		return 0;
	case 0x04E9:
		return mScreen[mCurX][mCurY][0] | (mScreen[mCurX][mCurY][1] << 8);
	case 0x04EA:
		return mCurX;
	case 0x04EB:
		return mCurY;
	}
	return 0xFFFFFFFF;

}

void Screen::_PutChar(char chr) {
	mScreen[mCurX][mCurY][0] = chr;

	if(mCurX + 1 == NUM_COLS) {
		mCurY = (mCurY + 1) % NUM_ROWS;
		if(mCurY == mFirstRow) {
			mFirstRow = (mFirstRow + 1) % NUM_ROWS;
		}
		for(unsigned int i = 0; i < NUM_ROWS; i++) {
			mScreen[i][mCurY][0] = ' ';
			mScreen[i][mCurY][1] = 0;
		}
		mCurX = 0;
	} else {
		mCurX++;
	}
}

void Screen::_PutColour(unsigned char colour) {
	mScreen[mCurX][mCurY][1] = colour;
}

std::string Screen::GetStr() {
    std::stringstream ss;
    unsigned int row = mFirstRow;

    do {
        for(unsigned int col = 0; col < NUM_COLS; col++) {
            ss << mScreen[col][row][0];
        }
        ss << std::endl;
        row = (row + 1) % NUM_ROWS;
    } while(row != mFirstRow);
    return ss.str();
}
