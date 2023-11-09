// Template, IGAD version 3
// Get the latest version from: https://github.com/jbikker/tmpl8
// IGAD/NHTV/BUAS/UU - Jacco Bikker - 2006-2023
#include "precomp.h"
#include "game.h"

#include <string>


// -----------------------------------------------------------
// Initialize the application
// -----------------------------------------------------------
void Game::Init()
{
	
}


// -----------------------------------------------------------
// Main application tick function - Executed once per frame
// -----------------------------------------------------------
void Game::Tick( float deltaTime)
{
	screen->Clear( 0 );
	stage.Clear(0);

	elapsedTime += deltaTime;

	UpdateXYBasedOnElapsedTime();	
	
	// Row highlight / Y position.
	int rowYStart{ blockPos.y - 3 + (y * (stride.y + 1)) };
	stage.Bar(blockPos.x - 2, rowYStart, blockPos.x + rowSize.x, rowYStart + stride.y + 1, 0x003030);
	stage.Box(blockPos.x - 2, rowYStart, blockPos.x + rowSize.x, rowYStart + stride.y + 1, 0x005050);
	str.clear();
	str.append("Y ").append(std::to_string(y));
	stage.Print(str.data(), blockPos.x + rowSize.x + 7, rowYStart + 3, 0xFFFF00);

	// Column highlight / X position.
	int columnXStart{ blockPos.x + (x * stride.x) };
	stage.Bar(columnXStart - 2, blockPos.y - 3, columnXStart + columnSize.x, blockPos.y + columnSize.y, 0x303000);
	stage.Box(columnXStart - 2, blockPos.y - 3, columnXStart + columnSize.x, blockPos.y + columnSize.y, 0x505000);
	str.clear();
	str.append("X ").append(std::to_string(x));
	stage.Print(str.data(), columnXStart - 3, 9 * 10, 0x00FFFF);
	
	// Green index box.
	stage.Bar(columnXStart - 2, rowYStart, columnXStart + columnSize.x, rowYStart + stride.y + 1, 0x005000);
	stage.Box(columnXStart - 2, rowYStart, columnXStart + columnSize.x, rowYStart + stride.y + 1, 0x00FF00);

	// DEMO TEXT //
	
	// Setup - width, height, and size.
	int printRow{ 0 };
	stage.Print("int width  = 5;", 10, ++printRow * 10, 0xFFFFFF);
	stage.Print("width", 10 + (6 * 4), printRow * 10, 0x005050);
	stage.Print("5", 10 + (6 * 13), printRow * 10, 0x005050);

	stage.Print("int height = 3;", 10, ++printRow * 10, 0xFFFFFF);
	stage.Print("height", 10 + (6 * 4), printRow * 10, 0x505000);
	stage.Print("3", 10 + (6 * 13), printRow * 10, 0x505000);

	stage.Print("int size   = width x height;", 10, ++printRow * 10, 0xFFFFFF);
	stage.Print("width", 10 + (6 * 13), printRow * 10, 0x005050);
	stage.Print("height", 10 + (6 * 21), printRow * 10, 0x505000);
	++printRow;

	// Example 1D array.
	stage.Print("int array_1d[size]{", 10, ++printRow * 10, 0xFFFFFF);
	stage.Print("14, 98, 32, 09, 51,", 10 + 18, ++printRow * 10, 0xFFFFFF);
	stage.Print("72, 40, 08, 67, 23,", 10 + 18, ++printRow * 10, 0xFFFFFF);
	stage.Print("35, 17, 20, 82, 06,", 10 + 18, ++printRow * 10, 0xFFFFFF);
	stage.Print("};", 10, ++printRow * 10, 0xFFFFFF);
	++printRow;

	// 1D access.
	str.clear();
	str.append("array_1d[x + (y x width)]");
	stage.Print(str.data(), 10, ++printRow * 10, 0xFFFFFF);
	stage.Print("x", 10 + (6 * 9), printRow * 10, 0x00FFFF);
	stage.Print("y", 10 + (6 * 14), printRow * 10, 0xFFFF00);
	stage.Print("width", 10 + (6 * 18), printRow * 10, 0x005050);

	// Underlying math.
	str.clear();
	str.append("= ").append(std::to_string(x)).append(" + (").append(std::to_string(y)).append(" x ").append(std::to_string(w)).append(")");
	stage.Print(str.data(), 10 + 18, ++printRow * 10, 0xFFFFFF);
	stage.Print(std::to_string(x).data(), 10 + 18 + (6 * 2), printRow * 10, 0x00FFFF);
	stage.Print(std::to_string(y).data(), 10 + 18 + (6 * 7), printRow * 10, 0xFFFF00);
	stage.Print(std::to_string(w).data(), 10 + 18 + (6 * 11), printRow * 10, 0x005050);

	// Result.
	str.clear();
	str.append("= ").append(std::to_string(x + y * w));
	stage.Print(str.data(), 10 + 18, ++printRow * 10, 0xFFFFFF);
	stage.Print(std::to_string(x + y * w).data(), 10 + 18 + (6 * 2), printRow * 10, 0x00FF00);

	stageSprite.DrawScaled(0, 0, screen->width, screen->height, screen);
}


void Game::UpdateXYBasedOnElapsedTime()
{
	if (elapsedTime > 1.0f)
	{
		x += 1;

		if (x > w - 1)
		{
			x = 0;
			y += 1;
		}

		if (y > h - 1)
		{
			y = 0;
		}

		elapsedTime = 0.0f;
	}
}