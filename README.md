<h1 align="center"> CVE's Table</h1>

|CVE Number|Type|Company/Product|Description|Article Link|POC Link|
|---|---|---|---|---|---|
|CVE-2022-24562|RCE||Not available publicly yet
|CVE-2022-24141|LPE||Not available publicly yet
|CVE-2022-24140|LPE||Not available publicly yet
|CVE-2022-24139|LPE||Not available publicly yet
|CVE-2022-24138|LPE||Not available publicly yet
|CVE-2021-44596|RCE|Wondershare/Dr. Fone|Due to software design flaws an unauthenticated user can communicate over UDP with the "InstallAssistService.exe" service(the service is running under SYSTEM privileges) and manipulate it to execute malicious executable without any validation from a remote location and gain SYSTEM privileges|https://ir-on.io/2021/12/02/local-privilege-plexcalation/|https://github.com/netanelc305/WonderShell
|CVE-2021-44595|RCE|Wondershare/Dr. Fone|Wondershare Dr. Fone Latest version as of 2021-12-06 is vulnerable to Incorrect Access Control. A normal user can send manually crafted packets to the ElevationService.exe and execute arbitrary code without any validation with SYSTEM privileges.|https://ir-on.io/2021/12/02/local-privilege-plexcalation/|https://github.com/netanelc305/WonderShell
|CVE-2021-42835|LPE|Plex/Plex Media Server|An attacker (with a foothold in a endpoint via a low-privileged user account) can access the exposed RPC service of the update service component. This RPC functionality allows the attacker to interact with the RPC functionality and execute code from a path of his choice (local, or remote via SMB) because of a TOCTOU race condition. This code execution is in the context of the Plex update service (which runs as SYSTEM).|https://ir-on.io/2021/12/02/local-privilege-plexcalation/|https://github.com/netanelc305/PlEXcalaison|
|CVE-2021–41067|LPE|Bopsoft/Listary|Improper implementation of the update process leads to the download of software updates with a /check-update HTTP-based connection. This can be exploited with MITM techniques. Together with the lack of package validation, it can lead to manipulation of update packages that can cause an installation of malicious content.|https://medium.com/@tomerp_77017/exploiting-listary-searching-your-way-to-system-privileges-8175af676c3e|N/A|
|CVE-2021–41066|LPE|Bopsoft/Listary|When Listary is configured as admin, Listary will not ask for permissions again if a user tries to access files on the system from Listary itself (it will bypass UAC protection; there is no privilege validation of the current user that runs via Listary).|https://medium.com/@tomerp_77017/exploiting-listary-searching-your-way-to-system-privileges-8175af676c3e|N/A|
|CVE-2021–41065|LPE|Bopsoft/Listary|An attacker can create a \\.\pipe\Listary.listaryService named pipe and wait for a privileged user to open a session on the Listary installed host. Listary will automatically access the named pipe and the attacker will be able to duplicate the victim's token to impersonate him. This exploit is valid in certain Windows versions (Microsoft has patched the issue in later Windows 10 builds).|https://medium.com/@tomerp_77017/exploiting-listary-searching-your-way-to-system-privileges-8175af676c3e|N/A|

