#include<windows.h>
#include<strsafe.h>
#define Line 15
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT("马静的窗口");
	HWND hwnd;//窗口句柄
	MSG msg;	//消息句柄
	WNDCLASS wndclass; //窗口类
	wndclass.style = CS_HREDRAW | CS_VREDRAW; //窗口样式
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL,IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL,IDC_ARROW);
	wndclass.hbrBackground = GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;

	if (RegisterClass(&wndclass)) 
	{
		MessageBox(NULL,TEXT("注册成功"),TEXT("窗口"),0);
		
	}
	//创建窗口
	hwnd = CreateWindow(szAppName,
		TEXT("鱼工作室"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT, 
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);
	ShowWindow(hwnd,iCmdShow);//显示窗口
	UpdateWindow(hwnd);//刷新窗口
	while (GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wparam,LPARAM lparam) {
	HDC hdc;//设备句柄
	PAINTSTRUCT ps;//绘画结构
	RECT rect;
	TCHAR str[128];
	size_t itarget;
	int i;
	switch (message)
	{
	case WM_PAINT: 
		
		hdc = BeginPaint(hwnd,&ps);//获得设备环境句柄
		
		GetClientRect(hwnd,&rect);
		DrawText(hdc,TEXT("大家好，这是我的第一个windows程序"),-1,&rect,DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hwnd, &ps);
		
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_LBUTTONDOWN:
		MessageBox(NULL,TEXT("窗口被点击了"),TEXT("标题"),0);
		return 0;
	case WM_CLOSE:
		if (MessageBox(NULL,TEXT("你确定要关闭吗？"),TEXT("标题"),MB_YESNO)==IDYES) {
			PostQuitMessage(0);
		}
		else
		{
			return 0;
		}
	}
	return DefWindowProc(hwnd,message,wparam,lparam);
}