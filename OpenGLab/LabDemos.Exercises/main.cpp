import Exercise;

#include <iostream>
#include <functional>

using namespace std;

vector<std::pair<string, function<int()>>> exercises = {
	{
		"Add Shape OnKeyPress", []()-> int
		{
			return AddShapeOnKeyPress::main();
		},
	},
	{
		"Audio Player", []()-> int
		{
			return AudioPlayer::main();
		},
	},
	{
		"Drag Shape By Mouse", []()-> int
		{
			return DragByMouse::main();
		},
	},
	{
		"Pick Texture With File Picker", []()-> int
		{
			return PickTextureFromDevice::main();
		},
	},
	{
		"Move By WSAD", []()-> int
		{
			return MoveByWSAD::main();
		},
	},
	{
		"Color With RGB Keys", []()-> int
		{
			return ColorByRGBKeys::main();
		},
	},
	{
		"Read Vertices From File", []()-> int
		{
			return ReadVerticesFromFile::main();
		},
	},
	{
		"Read Vertices From .Lib", []()-> int
		{
			return ReadVerticesFromLib::main();
		},
	},
	{
		"Read Vertices From .Obj", []()-> int
		{
			return ReadVerticesFromObj::main();
		},
	},
	{
		"Create and Draw on Two Windows", []()-> int
		{
			return TwoWindows::main();
		},
	},
	{
		"Sine Wave", []()-> int
		{
			return SineWave::main();
		},
	},
	{
		"NeedFix: Combine Textures", []()-> int
		{
			return NeedFix_CombineTextures::main();
		},
	},
	{
		"NeedFix: Scene Is not At Center When Window Size Changed", []()-> int
		{
			return NeedFix_KeepSceneAtCenter::main();
		},
	},
	{
		"NeedFix: Texture is not loaded correctly", []()-> int
		{
			return NeedFix_LoadTexture::main(); // it's upside down + more..
		},
	},
	{
		"Draw Shape Based on User Selection", []()-> int
		{
			return DrawShapeOnUserSelection::main(); // it's upside down + more..
		},
	},
	{
		"NeedFix: VAO, nothing drawn!", []()-> int
		{
			return NeedFix_VAO::main();
		},
	},
	{
		"NeedFix: Indices, nothing drawn!", []()-> int
		{
			return NeedFix_WrongIndices::main();
		},
	},
	{
		"NeedFix: Wrong Coloring", []()-> int
		{
			return NeedFix_WrongColoring::main();
		},
	},
};

int main()
{
	auto keepShowingDemos = true;
	auto demoNumber = -1;

	while (keepShowingDemos)
	{
		system("cls");
		cout << "Enter demo number [1, " << exercises.size() << "] to show it, enter any other value to break..." <<
			endl;
		for (int i = 0; i < exercises.size(); ++i)
		{
			auto& description = exercises[i].first;
			cout << i + 1 << ") " << description << endl;
		}
		cin >> demoNumber;
		keepShowingDemos = 1 <= demoNumber && demoNumber <= exercises.size();
		if (!keepShowingDemos)
			break;
		// index passed by the user starts from 1, hence, -1
		exercises[demoNumber - 1].second();
	}
	return 0;
}
