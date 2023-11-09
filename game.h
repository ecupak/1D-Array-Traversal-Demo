// Template, IGAD version 3
// Get the latest version from: https://github.com/jbikker/tmpl8
// IGAD/NHTV/BUAS/UU - Jacco Bikker - 2006-2023

#pragma once

namespace Tmpl8
{
	class Game : public TheApp
	{
	public:
		// game flow methods
		void Init();
		void Tick( float deltaTime );
		void Shutdown() { /* implement if you want to do something on exit */ }
		// input handling
		void MouseUp( int ) { /* implement if you want to detect mouse button presses */ }
		void MouseDown( int ) { /* implement if you want to detect mouse button presses */ }
		void MouseMove( int x, int y ) { /* implement if you want to detect mouse button presses */ }
		void MouseWheel( float ) { /* implement if you want to handle the mouse wheel */ }
		void KeyUp( int ) { /* implement if you want to handle keys */ }
		void KeyDown( int ) { /* implement if you want to handle keys */ }
		
	private:
		void UpdateXYBasedOnElapsedTime();

		// Arbitrary values to line up with the first element in the example array.
		int2 blockPos{ 10 + 18, 60 };
		
		// Size of border around array elements.
		int2 elementSize{ 2 * 6, 10 };

		// Selection border strides.
		int2 stride{
			4		// char per element (##, )
			* 6,	// size of each char
			9		// arbitrary size that looks good
		};
		
		// Selection border sizes.
		int2 rowSize{
			5			// element count
			* stride.x	// size of each element group
			- 6 * 2,	// last element has 2 less char
			stride.y
		};

		int2 columnSize{
			2			// char per element (##)
			* 6,		// size of each char
			stride.y	// height of each row
			* 3			// row count
		};


		float elapsedTime{ 0.0f };
		
		int x{ 0 };
		int y{ 0 };
		
		int w{ 5 };
		int h{ 3 };

		Surface stage{ 200, 160 };
		Sprite stageSprite{ &stage, 1 };

		std::string str{ "" };
	};

} // namespace Tmpl8