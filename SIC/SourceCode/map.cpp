#include "all.h"

void map_update()
{
	debug::setString("cursor%d", cursor);
	
}

void map_render()
{
	/*primitive::rect(
		{ 0 - scroll.x, 0 - scroll.y },
		{ SCREEN_W, SCREEN_H * 2},
		{ 0,0 },
		ToRadian(0),
		{ 1, 0.5f, 0, 1 }
	);
	primitive::rect(
		{ 0 - scroll.x, SCREEN_H * 2 - scroll.y },
		{ SCREEN_W, SCREEN_H * 2 },
		{ 0,0 },
		ToRadian(0),
		{ 1, 0, 1, 1 }
	);*/
	switch (cursor)
	{
	case 0:
	{
		for (int i = 0; i < 42/*magicNumber*/; ++i)
		{
			if (i % 2)
			{
				primitive::rect(
					{ 0 - scroll.x, SCREEN_H * i - scroll.y },
					{ SCREEN_W, SCREEN_H },
					{ 0,0 },
					ToRadian(0),
					{ 1, 0.5f, 0, 1 }
				);
			}
			else
			{
				primitive::rect(
					{ 0 - scroll.x, SCREEN_H * i - scroll.y },
					{ SCREEN_W, SCREEN_H },
					{ 0,0 },
					ToRadian(0),
					{ 1, 0, 1, 1 }
				);
			}
		}
		break;

	}
	case 1:
	{
		for (int i = 0; i < 42/*magicNumber*/; ++i)
		{
			if (i % 2)
			{
				primitive::rect(
					{ 0 - scroll.x, SCREEN_H * i - scroll.y },
					{ SCREEN_W, SCREEN_H },
					{ 0,0 },
					ToRadian(0),
					{ 1, 0.761f, 0.039f, 1 }
				);
			}
			else
			{
				primitive::rect(
					{ 0 - scroll.x, SCREEN_H * i - scroll.y },
					{ SCREEN_W, SCREEN_H },
					{ 0,0 },
					ToRadian(0),
					{ 0.98f, 0.557f, 0, 1 }
				);
			}
		}
		break;
		
	}
	case 2:
	{
		for (int i = 0; i < 42/*magicNumber*/; ++i)
		{
			if (i % 2)
			{
				primitive::rect(
					{ 0 - scroll.x, SCREEN_H * i - scroll.y },
					{ SCREEN_W, SCREEN_H },
					{ 0,0 },
					ToRadian(0),
					{ 0.529f, 0.949f,0.361f, 1 }
				);
			}
			else
			{
				primitive::rect(
					{ 0 - scroll.x, SCREEN_H * i - scroll.y },
					{ SCREEN_W, SCREEN_H },
					{ 0,0 },
					ToRadian(0),
					{ 0.973f, 1, 0.388f, 1 }
				);
			}

		}
		break;

	}
	case 3:
	{
		for (int i = 0; i < 42/*magicNumber*/; ++i)
		{
			if (i % 2)
			{
				primitive::rect(
					{ 0 - scroll.x, SCREEN_H * i - scroll.y },
					{ SCREEN_W, SCREEN_H },
					{ 0,0 },
					ToRadian(0),
					{ 0.125f, 0.008f,0.412f, 1 }
				);
			}
			else
			{
				primitive::rect(
					{ 0 - scroll.x, SCREEN_H * i - scroll.y },
					{ SCREEN_W, SCREEN_H },
					{ 0,0 },
					ToRadian(0),
					{ 0.357f, 0.027f, 0.522f, 1 }
				);
			}

		}
		break;

	}
	case 4:
	{
		for (int i = 0; i < 42/*magicNumber*/; ++i)
		{
			if (i % 2)
			{
				primitive::rect(
					{ 0 - scroll.x, SCREEN_H * i - scroll.y },
					{ SCREEN_W, SCREEN_H },
					{ 0,0 },
					ToRadian(0),
					{ 0.18f, 0.769f,1, 1 }
				);
			}
			else
			{
				primitive::rect(
					{ 0 - scroll.x, SCREEN_H * i - scroll.y },
					{ SCREEN_W, SCREEN_H },
					{ 0,0 },
					ToRadian(0),
					{ 0.98f, 0.8f, 0.118f, 1 }
				);
			}

		}
		break;

	}
	}
	
}

void map_init()
{
	
}

void map_deinit()
{

}