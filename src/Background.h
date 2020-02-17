#pragma once
#ifndef __Background__
#define __Background__

#include "DisplayObject.h"

class Background : public DisplayObject
{
public:
	Background();
	~Background();

	void draw() override;
	void update() override;
	void clean() override;
private:

};

#endif /* defined (__Background__) */