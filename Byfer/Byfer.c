#define CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <strsafe.h>

LPWSTR ClipboardOutputText();

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{	
	while (TRUE)
	{
		LPWSTR Data = ClipboardOutputText();
		TCHAR Alert[] = L"Нарушены авторские права за СКОПИРОВАННЫЙ текст: ";
		TCHAR third[512];
		swprintf(third, sizeof third, L"%s%s", Alert, Data);
		if (*Data != 0)
		{
			MessageBoxW(NULL, &third, L"Нарушение", MB_OK | MB_ICONWARNING);
			ClipboardInputText("");
		}
		Sleep(1000);
	}
	return 0;
}

int ClipboardInputText(LPWSTR buffer)
{
	DWORD len;
	HANDLE hMem;

	len = wcslen(buffer) + 1;

	hMem = GlobalAlloc(GMEM_MOVEABLE, len * sizeof(LPWSTR));
	memcpy(GlobalLock(hMem), buffer, len * sizeof(LPWSTR));
	GlobalUnlock(hMem);
	OpenClipboard(0);
	EmptyClipboard();
	SetClipboardData(CF_UNICODETEXT, hMem);
	CloseClipboard();
	return 0;
}

TCHAR* ClipboardOutputText()
{
	TCHAR* Mess = NULL;
	OpenClipboard(NULL);
	HANDLE hClipboardData = GetClipboardData(CF_UNICODETEXT); // ЗАПИСАТЬ В БУФЕР ОБМЕНА ДАННЫЕ СООТВЕТСТВУЮЩЕГО ТИПА
	Mess = (TCHAR*)GlobalLock(hClipboardData); // Считать из глобального участка памяти , привести это всё к строке
	GlobalUnlock(hClipboardData);// закрыть буфер обмена, сделать его доступным для других приложений
	CloseClipboard(); // очистить буфер обмена
	EmptyClipboard();
	return Mess;
}

TCHAR* Text(LPSTR Data)
{
	// Массив со строкой для поиска
	char str = Data[512];
	// Набор символов, которые должны входить в искомый сегмент
	char sep[512] = " ";
	// Переменная, в которую будут заноситься начальные адреса частей
	// строки str
	char* istr;

	// Выделение первой части строки
	istr = strtok_s(str, sep, NULL);

	// Выделение последующих частей
	while (istr != NULL)
	{
		char stri = istr[512];
		// Набор символов, которые должны входить в искомый сегмент
		char sepi[512] = "/0";
		DWORD istri;
		istri = strtok_s(stri, sepi, NULL);
		while (istri != NULL)
		{
			if (istri == "0")
			{

			}
			else if (istri == "1")
			{
				CloseClipboard();
				OpenClipboard(0);
				TCHAR* Mess = istri;
				Mess = "one";
				HANDLE hClipboardData = GetClipboardData(CF_UNICODETEXT); 
			
				CloseClipboard();
				EmptyClipboard();
			}
			else if (istri == "2")
			{

			}
			else if (istri == "3")
			{

			}
			else if (istri == "4")
			{

			}
			else if (istri == "5")
			{

			}
			else if (istri == "6")
			{

			}
			else if (istri == "7")
			{

			}
			else if (istri == "8")
			{

			}
			else if (istri == "9")
			{

			}

		}


		// Выделение очередной части строки
		istr = strtok_s(NULL, sep, NULL);
	}
}