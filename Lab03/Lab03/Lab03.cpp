#include <iostream>

#include "stdafx.h"
#include "UInterface.h"
#include "Image.h"

using namespace std;

void main()
{
	Quadrilateral i(1,2,3,4,-1,-2,-3,-4);
	i.getParameters();
	Triangle u(0, 2, 3, 3, 6, 4);
	u.getParameters();
	system("pause");
}

