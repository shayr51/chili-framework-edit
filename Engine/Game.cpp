/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	static constexpr int screenR = 798;
	static constexpr int screenL = 2;
	static constexpr int screenT = 2;
	static constexpr int screenB = 598;
	
	
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		if (inhibitright)
		{
		}
		else
		{
			vx = vx + 1;
			inhibitright = true;
		}
	}
	else
	{
		inhibitright = false;
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		if (inhibitleft)
		{
		}
		else
		{
			vx = vx - 1;
			inhibitleft = true;
		}
	}
	else
	{
		inhibitleft = false;
	}
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		if (inhibitup)
		{
		}
		else
		{
			vy = vy - 1;
			inhibitup = true;
		}
	}
	else
	{
		inhibitup = false;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		if (inhibitdown)
		{
		}
		else
		{
			vy = vy + 1;
			inhibitdown = true;
		}
	}
	else
	{
		inhibitdown = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		vx = 0;
		vy = 0;
	}

	if (x + 7 >= screenR)
	{
		x = screenR - 10;
		if (vx = +1)
		{
			vx = -1;
		}
	}
	if (x - 6 <= screenL)
	{
		x = screenL + 6;
		if (vx = -1)
		{
			vx = +1;
		}
	}
	if (y + 6 >= screenB)
	{
		y = screenB - 6;
		if (vy = +1)
		{
			vy = -1;
		}
	}
	if (y - 6 <= screenT)
	{
		y = screenT + 6;
		if (vy = -1)
		{
			vy = +1;
		}
	}

	if (vx > +5)
	{
		vx = +5;
	}
	if (vx < -5)
	{
		vx = -5;
	}
	if (vy > +5)
	{
		vy = +5;
	}
	if (vy < -5)
	{
		vy = -5;
	}

		x = x + vx;
		y = y + vy;

}

	void Game::ComposeFrame()
{	
	gfx.PutPixel(x + 3, y, 255, 255, 255);
	gfx.PutPixel(x + 4, y, 255, 255, 255);
	gfx.PutPixel(x + 5, y, 255, 255, 255);
	gfx.PutPixel(x + 6, y, 255, 255, 255);
	gfx.PutPixel(x - 3, y, 255, 255, 255);
	gfx.PutPixel(x - 4, y, 255, 255, 255);
	gfx.PutPixel(x - 5, y, 255, 255, 255);
	gfx.PutPixel(x - 6, y, 255, 255, 255);
	gfx.PutPixel(x, y + 3, 255, 255, 255);
	gfx.PutPixel(x, y + 4, 255, 255, 255);
	gfx.PutPixel(x, y + 5, 255, 255, 255);
	gfx.PutPixel(x, y + 6, 255, 255, 255);
	gfx.PutPixel(x, y - 3, 255, 255, 255);
	gfx.PutPixel(x, y - 4, 255, 255, 255);
	gfx.PutPixel(x, y - 5, 255, 255, 255);
	gfx.PutPixel(x, y - 6, 255, 255, 255);

}
