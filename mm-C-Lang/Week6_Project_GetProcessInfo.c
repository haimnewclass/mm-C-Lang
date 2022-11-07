#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <windows.h>
#include <psapi.h>
#pragma warning(disable:4996)

struct ProcessDetails
{
	char DLLName[MAX_PATH];
	PROCESS_MEMORY_COUNTERS pmc;
	// Dynamic DLL List
	
};

struct ProcessDetails PrintMemoryInfo(DWORD processID)
{

	struct ProcessDetails ret;

	HANDLE hProcess;
	PROCESS_MEMORY_COUNTERS pmc;
	
	// Open process in order to receive information
	hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
		PROCESS_VM_READ,
		FALSE, processID);
	if (NULL == hProcess)
	{
		// Write to log a warning
		return;
	}



	HMODULE hMods[1024];
	DWORD cbNeeded;
	TCHAR FoundProcessName[MAX_PATH];
	TCHAR wDllName[MAX_PATH];
	char regularCharArr[MAX_PATH];

	// Get Process Name
	if (GetModuleFileNameEx(hProcess, 0, FoundProcessName, MAX_PATH))
	{
		// At this point, buffer contains the full path to the executable
	}
	else
	{
		// You better call GetLastError() here
		// Write To log
	}


	if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))
	{
		printf("\tPageFaultCount: 0x%08X\n", pmc.PageFaultCount);
		printf("\tPeakWorkingSetSize: 0x%08X\n",
			pmc.PeakWorkingSetSize);
		printf("\tWorkingSetSize: 0x%08X\n", pmc.WorkingSetSize);
		printf("\tQuotaPeakPagedPoolUsage: 0x%08X\n",
			pmc.QuotaPeakPagedPoolUsage);
		printf("\tQuotaPagedPoolUsage: 0x%08X\n",
			pmc.QuotaPagedPoolUsage);
		printf("\tQuotaPeakNonPagedPoolUsage: 0x%08X\n",
			pmc.QuotaPeakNonPagedPoolUsage);
		printf("\tQuotaNonPagedPoolUsage: 0x%08X\n",
			pmc.QuotaNonPagedPoolUsage);
		printf("\tPagefileUsage: 0x%08X\n", pmc.PagefileUsage);
		printf("\tPeakPagefileUsage: 0x%08X\n",
			pmc.PeakPagefileUsage);
	}

 

	// Get Dlls List

	if (EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded))
	{
		for (int i = 0; i < (cbNeeded / sizeof(HMODULE)); i++)
		{		
			// Get the full path to the module's file.

			if (GetModuleFileNameEx(hProcess, hMods[i], wDllName, MAX_PATH))
			{
				// * Get the module name and handle value.
				printf("%s", wDllName);

				// Convert wChar to regular char array (string)
				char dllName[MAX_PATH];
				size_t numConverted;
				wcstombs_s(&numConverted, dllName, MAX_PATH, wDllName, MAX_PATH);

				int tmp = 0;
				tmp++;
			}
		}
	}

	CloseHandle(hProcess);

}
void GetProcessesInfo()
{
	// Get Processes
	

	DWORD aProcesses[1024], cbNeeded, cProcesses;
	unsigned int i;

	// * Receive all process ID and put in aProcesses Array
	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
	{
		// Error. Write to log
		return 1;
	}

	// Calculate how many process identifiers were returned.
	cProcesses = cbNeeded / sizeof(DWORD);

	// Print the memory usage for each process
	// *Loop of all processes
	for (i = 0; i < cProcesses; i++)
	{
		PrintMemoryInfo(aProcesses[i]);
	}



	// For each Process to get its Memory Information

}
#undef PROCESS_MAIN
#ifdef PROCESS_MAIN
main()
{
	GetProcessesInfo();
	return 0;
}
#endif