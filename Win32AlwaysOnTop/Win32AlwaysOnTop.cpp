// Win32AlwaysOnTop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <string>


int main()
{
	std::string winName = "";
	const std::string checkUndo = " -undo";
	std::string temp;
	AllocConsole();
	SetConsoleTitle(L"AlwaysOnTop - Pick Window Name");

	std::cout << "Hint: append \" -undo\" to the end of the window name to make it behave normally. \n\n";
	do
	{
		winName = "";
		std::cout << "Window Name (must match exactly): ";
		std::getline(std::cin, winName);
		if (winName == "exit" || winName == "quit") return 0;

		if (winName.size() > checkUndo.size())
			temp = winName.substr(winName.size() - checkUndo.size());


		if (temp == checkUndo)
		{
			std::string windowNameStripped = winName.substr(0, winName.size() - checkUndo.size());
			HWND window = FindWindowA(NULL, windowNameStripped.c_str());
			if (window == NULL)
			{
				std::cerr << "\tError: Window not found." << "\n\n\n";
				continue;
			}
			LockSetForegroundWindow(ASFW_ANY);
			std::cout << "\n\tSetWindowPos() returned: " << std::boolalpha << (bool)SetWindowPos(window, HWND_BOTTOM, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE) << "\n\n\n\n";
		}
		else
		{
			HWND window = FindWindowA(NULL, winName.c_str());
			if (window == NULL)
			{
				std::cerr << "\tError: Window not found." << "\n\n\n";
				continue;
			}
			std::cout << "\twindow: " << window << '\n';
			std::cout << "\tSetForegroundWindow() returned: " << std::boolalpha << (bool)SetForegroundWindow(window);

			std::cout << "\n\tSetWindowPos() returned: " << std::boolalpha << (bool)SetWindowPos(window, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW) << "\n\n\n\n";

		}


	} while (winName != "exit");
	/*std::cout << "Hint: append \" -undo\" to the end of the window name to make it behave normally. \n";
	std::cout << "Window Name (must match exactly): ";
	std::getline(std::cin, winName);

	std::string temp = winName.substr(winName.size() - checkUndo.size());


	if (temp == checkUndo)
	{
		std::string windowNameStripped = winName.substr(0, winName.size() - checkUndo.size());
		HWND window = FindWindowA(NULL, windowNameStripped.c_str());
		if (window == NULL)
		{
			std::cerr << "Error: Window not found." << std::endl;
		}
		LockSetForegroundWindow(ASFW_ANY);
		SetWindowPos(window, HWND_BOTTOM, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
	}
	else
	{
		HWND window = FindWindowA(NULL, winName.c_str());
		std::cout << "window: " << window << '\n';
		std::cout << "ASFW: " << AllowSetForegroundWindow(ASFW_ANY) << '\n';
		std::cout << "setforground(): " << SetForegroundWindow(window) << '\n';

		std::cout << SetWindowPos(window, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW) << '\n';

	}*/


}

