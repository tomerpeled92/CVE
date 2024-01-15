# Local Privilege PlEXcalasion -  CVE-2021-42835

Plex Media Server for Windows prior to version 1.25.0.5282, vulnerable to Time Of Check Time Of Use (TOCTOU) that allows low privilege users to gain SYSTEM privileges. 

## Discovered by
Tomer Peled, Netanel Cohen, and Amir Shen a Security Researchers from BugSec.

## Details
Plex for windows uses PlexUpdateService.exe to install new updates. The service is running in the SYSTEM context. When installing an update, the service first verifies file integrity and digital signature, only if the checks were successful the update will be installed.

At this process, After integrity and signature check, There was a design flow that handled the update file improperly. The file was closed and reopened later for installation.

This flaw allows an attacker to swap the update file with a malicious one as soon as the service is finished to verify the integrity and signature, resulting in code execution in the SYSTEM context.
 

This POC use tools developed by James Forshaw with slight modifications. The original can be found here - https://github.com/googleprojectzero/symboliclink-testing-tools

To achieve the above we used a Junction folder that will first point to a folder containing a valid update file and then will swap to a folder containing the malicious file.

We found that the file access order was as follow:
1. Read the update file to check its digital signature
2. Close the update file.
3. Read CACERT.pem
4. verify the signature.
5. Read the update file again
6. Execute the installation

We created a mount point on the junction folder to point to a folder that contains the valid update file.
Set opLock on cacert.pem with a callback function, As soon as it acess we change the mount point to the malicious folder.

In addition, we have created an RPC client that will trigger the update.




## Usage

1. Clone the repository and open PlEXcalasion.sln in Visual Studio.
2. Delete the Delete me.txt file located in TOCTOU\\junction - Its just place holder for git to include the folder , this folder must be empty!
3. Modify Paths:

PlexClient/PlexClient.cpp replace ROOTDIR with your path.
```cpp
const wchar_t* pszString = L"<ROOTDIR>\\PlEXcalaison\\TOCTOU\\junction\\plex.exe"; // Path to the update file. 
```
PlEXcalaison/BaitAndSwitch/BaitAndSwitch.cpp replace ROOTDIR with your path.
```cpp
static LPCWSTR junction = L"<ROOTDIR>\\PlEXcalaison\\TOCTOU\\junction";  // Path to junction folder , MAKE SURE IT IS EMPTY !
static LPCWSTR target1 = L"<ROOTDIR>\\PlEXcalaison\\TOCTOU\\valid"; // Path to folder contains the valid update file.
static LPCWSTR target2 = L"<ROOTDIR>\\PlEXcalaison\\TOCTOU\\malicious"; // Path to folder contains the malicious file - MUST BE THE SAME NAME AS THE UPDATE FILE.
static LPCWSTR cacert = L"C:\\Program Files (x86)\\Plex\\Plex Media Server\\Resources\\cacert.pem"; // Path to cacert.pem - can be found in plex directory.
```

4. Build the solution.
5. Make sure a PlexClient.exe was created and can be found on Rleases dir.
6. Put the desired executeable file you want to execute as system in the malicious folder and rename it to plex.exe (for the poc i used cmd.exe)
7. Execute BiteAndSwitch.exe

## Publications
https://ir-on.io/2021/12/02/local-privilege-plexcalation/

https://forums.plex.tv/t/security-regarding-cve-2021-42835/761510


