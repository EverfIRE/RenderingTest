#include "GLRenderContext.h"
#include "scene.h"
#include "Utils.h"

#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib")
#pragma comment(lib,"winmm.lib")

POINT originalPos;
bool rotateView = false;

LRESULT CALLBACK RenderTesProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_RBUTTONDOWN:
		GetCursorPos(&originalPos);
		ShowCursor(false);
		rotateView = true;
		return 0;
	case WM_RBUTTONUP:
		SetCursorPos(originalPos.x,originalPos.y);
		ShowCursor(true);
		rotateView = false;
		return 0;
	case WM_LBUTTONDOWN:
		return 0;
	case WM_LBUTTONUP:
		return 0;

	case WM_MOUSEMOVE:
		if (rotateView)
		{
			POINT currentPos;
			GetCursorPos(&currentPos);
			int deltax = currentPos.x - originalPos.x;
			int deltay = currentPos.y - originalPos.y;
			OneMouseMove(deltax, deltay);
			SetCursorPos(originalPos.x,originalPos.y);
		}
		return 0;

	case WM_KEYDOWN:
		OneKeyDown(wParam);
		return 0;
	case WM_KEYUP:
		OneKeyUp(wParam);
		return 0;

	case WM_CLOSE:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}
float GetFrameTime()
{
	static unsigned long lastTime = 0, timeSinceComputerStart = 0;
	timeSinceComputerStart = timeGetTime();
	unsigned long frameTime = lastTime == 0 ? 0 : timeSinceComputerStart - lastTime;
	lastTime = timeSinceComputerStart;
	return float(frameTime)/1000.0f;
}

INT WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//register window
	WNDCLASSEX wndclass;
	wndclass.cbClsExtra = 0;
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.cbWndExtra = 0;
	wndclass.hbrBackground = NULL;
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hIcon = NULL;
	wndclass.hIconSm = NULL;
	wndclass.hInstance = hInstance;
	wndclass.lpfnWndProc = RenderTesProc;
	wndclass.lpszClassName = "RenderTes";
	wndclass.lpszMenuName = NULL;
	wndclass.style = CS_VREDRAW | CS_HREDRAW;
	ATOM atom = RegisterClassEx(&wndclass);
	if (!atom)
	{
		return 0;
	}

	RECT rect;
	rect.left = 0;
	rect.right = 1280;
	rect.top = 0;
	rect.bottom = 720;

	AdjustWindowRect(&rect, ((WS_OVERLAPPEDWINDOW^WS_THICKFRAME) ^ WS_MINIMIZEBOX) ^ WS_MAXIMIZEBOX, NULL);
	int windowWidth = rect.right - rect.left;
	int windowHight = rect.bottom - rect.top;

	//create window
	HWND hwnd = CreateWindowEx(NULL, "RenderTes", "RenderTestWin", ((WS_OVERLAPPEDWINDOW^WS_THICKFRAME) ^ WS_MINIMIZEBOX) ^ WS_MAXIMIZEBOX,
		100, 100, windowWidth, windowHight, NULL, NULL, hInstance, NULL);

	//create opengl render context
	HDC dc = GetDC(hwnd);
	PIXELFORMATDESCRIPTOR pfd;
	memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
	pfd.nVersion = 1;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.cColorBits = 32;
	pfd.cDepthBits = 8;
	pfd.cStencilBits = 8;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	int pixelFormat = ChoosePixelFormat(dc,&pfd);
	SetPixelFormat(dc,pixelFormat,&pfd);
	HGLRC rc = wglCreateContext(dc);
	wglMakeCurrent(dc, rc);
	//opengl init
	Init();
	glClearColor(0.07f, 0.3f, 0.5f, 1.0f);//set "clear color" for background

	//show window
	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);

	MSG msg;
	while (true)
	{
		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		//draw scene
		glClear(GL_COLOR_BUFFER_BIT);
		Draw();

		//present scene
		SwapBuffers(dc);
	}

	return 0;
}