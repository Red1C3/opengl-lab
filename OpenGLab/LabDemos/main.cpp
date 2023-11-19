import Sample;

#include <iostream>
#include <functional>

using namespace std;

vector<std::pair<string, function<int()>>> demos = {
	{
		"Show empty Glfw window (minimal code)", []()-> int
		{
			return JustGlfwWindow::main();
		},
	},
	{
		"Glfw Window with button", []()-> int
		{
			return GlfwWindowWithButton::main();
		},
	},
	{
		"File Picker (A.K.A OpenFileDialog)", []()-> int
		{
			return OpenFileDialog::main();
		},
	},
	{
		"Show triangle (minimal code)", []()-> int
		{
			return HelloTriangle::main();
		},
	},
	{
		"Show triangle (OOP code)", []()-> int
		{
			return HelloOopTriangle::main();
		},
	},
	{
		"Primitives", []()-> int
		{
			return HelloPrimitives::main();
		},
	},
	{
		"Circle vs. Disk", []()-> int
		{
			return CircleVsDisk::main();
		},
	},
	// TODO
	// {
	// 	"Choose Texture With File Picker", []()-> int
	// 	{
	// 		throw NotImplementedException();
	// 	},
	// },
	// TODO: Analogue Clock
	// - might add one of these to LabDemos.Exercises/Readme.md
	// - https://github.com/kfoozminus/Analog-Wall-Clock-Graphics-Project-/blob/master/wallClock.cpp
	// - https://github.com/sprintr/opengl-examples/blob/master/OpenGL-Clock-Animated.cpp
	// - https://github.com/ebraminio/ShaderAnalogClock
	// - https://github.com/siyamulislam/DynamicVillage/blob/main/main.cpp
	// {
	// 	"Show triangle (OOP code)", []()-> int
	// 	{
	// 		return HelloOopTriangle::main();
	// 	},
	// },
	// TODO:with minimum code
	{
		"Hello texture", []()-> int
		{
			return HelloTexture::main();
		},
	},
	// TODO
	// {
	// 	"Combine Textures", []()-> int
	// 	{
	// 		throw NotImplementedException();
	// 	},
	// },
	// TODO
	// {
	// 	"Combine Textures", []()-> int
	// 	{
	// 		throw NotImplementedException();
	// 	},
	// },
	// TODO: run camera sample with minimum code
	{
		"Free Camera Demo", []()-> int
		{
			return FreeCamera::main();
		},
	},
	// TODO
	// {
	// 	"Browse/Play audio file", []()-> int
	// 	{
	// 		throw NotImplementedException();
	// 	},
	// },
	// TODO: Draw Text
	// {
	// 	"Draw Text", []()-> int
	// 	{
	// 		throw NotImplementedException();
	// 	},
	// },

};

int main()
{
	auto keepShowingDemos = true;
	auto demoNumber = -1;

	while (keepShowingDemos)
	{
		system("cls");
		cout << "Enter demo number [1, " << demos.size() << "] to show it, enter any other value to break..." << endl;
		for (int i = 0; i < demos.size(); ++i)
		{
			auto& description = demos[i].first;
			cout << i + 1 << ") " << description << endl;
		}
		cin >> demoNumber;
		keepShowingDemos = 1 <= demoNumber && demoNumber <= demos.size();
		if (!keepShowingDemos)
			break;
		// index passed by the user starts from 1, hence, -1
		demos[demoNumber - 1].second();
	}
	return 0;
}