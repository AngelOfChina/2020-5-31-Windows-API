#include<windows.h>
#include<strsafe.h>
#define Line 15
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT("���Ĵ���");
	HWND hwnd;//���ھ��
	MSG msg;	//��Ϣ���
	WNDCLASS wndclass; //������
	wndclass.style = CS_HREDRAW | CS_VREDRAW; //������ʽ
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
		MessageBox(NULL,TEXT("ע��ɹ�"),TEXT("����"),0);
		
	}
	//��������
	hwnd = CreateWindow(szAppName,
		TEXT("�㹤����"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT, 
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);
	ShowWindow(hwnd,iCmdShow);//��ʾ����
	UpdateWindow(hwnd);//ˢ�´���
	while (GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wparam,LPARAM lparam) {
	HDC hdc;//�豸���
	PAINTSTRUCT ps;//�滭�ṹ
	RECT rect;
	TCHAR str[128];
	size_t itarget;
	int i;
	switch (message)
	{
	case WM_PAINT: 
		
		hdc = BeginPaint(hwnd,&ps);//����豸�������
		
		GetClientRect(hwnd,&rect);
		DrawText(hdc,TEXT("��Һã������ҵĵ�һ��windows����"),-1,&rect,DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hwnd, &ps);
		
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_LBUTTONDOWN:
		MessageBox(NULL,TEXT("���ڱ������"),TEXT("����"),0);
		return 0;
	case WM_CLOSE:
		if (MessageBox(NULL,TEXT("��ȷ��Ҫ�ر���"),TEXT("����"),MB_YESNO)==IDYES) {
			PostQuitMessage(0);
		}
		else
		{
			return 0;
		}
	}
	return DefWindowProc(hwnd,message,wparam,lparam);
}