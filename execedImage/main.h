#pragma once

inline int _tmain(int argc, TCHAR * argv[])
{
	STARTUPINFO si;

	PROCESS_INFORMATION pi; //进程信息： 

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	do {
		// 创建子进程，判断是否执行成功 
		if (!CreateProcess(NULL, R"(cmd /c d:\1.jpg)", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
		{
			cout << "创建进程失败.." << GetLastError() << endl;
			system("pause"); //用于测试 
			return 0;
		}
		//进程执行成功，打印进程信息 
		cout << "以下是子进程的信息：" << endl;
		cout << "进程ID pi.dwProcessID: " << pi.dwProcessId << endl;
		cout << "线程ID pi.dwThreadID : " << pi.dwThreadId << endl;
		// 等待知道子进程退出... 
		WaitForSingleObject(pi.hProcess, INFINITE);//检测进程是否停止 
												   //WaitForSingleObject()函数检查对象的状态，如果是未确定的则等待至超时 
												   //子进程退出 
		cout << "子进程已经退出..." << endl;
		//关闭进程和句柄 
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
		//system("pause");//执行完毕后等待 
	} while (true);//如果进程推出就再次执行方法 
	exit(0);
	return 0;
}
