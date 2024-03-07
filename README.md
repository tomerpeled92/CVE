<h1 align="center"> CVE's Table</h1>

|CVE Number|Type|Company/Product|Description|Article Link|Repository Link|
|---|---|---|---|---|---|
|CVE-2024-21320|Spoofing|Microsoft Themes|Specially crafted themes file allows attackers to spoof their identity, more details soon.|https://www.akamai.com/blog/security-research/2024/mar/leaking-ntlm-credentials-through-windows-themes|https://github.com/tomerpeled92/CVE/blob/main/CVE-2024-21320/|
|CVE-2023-5528|RCE|Kubernetes < 1.28.4|Unsanitized input in kuberentes in-tree plugin allows for a command injection and RCE over all windows nodes in a cluster with SYSTEM privileges|TBA|TBA|
|CVE-2023-3676|RCE|Kubernetes < 1.28|Unsanitized input in kuberentes subPath feature allows for a command injection and RCE over all windows nodes in a cluster with SYSTEM privileges|https://www.akamai.com/blog/security-research/kubernetes-critical-vulnerability-command-injection|https://github.com/tomerpeled92/CVE/blob/main/CVE-2023-3676/|
|CVE-2023-31462|LPE|SteelSeriesGG < 39|Attackers can modify SteelSeriesGG database to execute malicious code in admin context|https://www.akamai.com/blog/security-research/exploit-steelseries-subapp-privilege-escalation|
|CVE-2023-31461|LPE|SteelSeriesGG < 39|Attackers can send packets to SteelSeriesGG API that will lead to malicious code execution in admin context|https://www.akamai.com/blog/security-research/exploit-steelseries-subapp-privilege-escalation|
|CVE-2022-34689|Spoofing|Windows/Chrome|This vulnerability was discovered by the NSA and NCSC, Me and my coleague analyzed this vulnerability and exploited it|https://www.akamai.com/blog/security-research/exploiting-critical-spoofing-vulnerability-microsoft-cryptoapi|https://github.com/tomerpeled92/CVE/tree/main/CVE-2022-34689|
|CVE-2022-35200|DoS||not published|||
|CVE-2022-35199|DoS||not published|||
|CVE-2022-24562|RCE|IObit/IOTransfer|an unauthenticated attacker can send GET and POST requests to Airserv and gain arbitrary read/write access to the entire file-system (with admin privileges) on the victim's endpoint, which can result in data theft and remote code execution|https://medium.com/@tomerp_77017/exploiting-iotransfer-insecure-api-cve-2022-24562-a2c4a3f9149d|https://github.com/tomerpeled92/CVE/tree/main/CVE-2022%E2%80%9324562
|CVE-2022-24141|LM|IObit/Itop VPN|Lateral Movment with named pipes|N/A|https://github.com/tomerpeled92/CVE/tree/main/CVE-2022-24141
|CVE-2022-24140|MITM|IObit/Various|MITM attack can lead to code execution|N/A|https://github.com/tomerpeled92/CVE/tree/main/CVE-2022-24140
|CVE-2022-24139|LM|IObit/Advanced System Care|Lateral Movment with named pipes|N/A|https://github.com/tomerpeled92/CVE/tree/main/CVE-2022-24139
|CVE-2022-24138|LPE|IObit/Advanced System Care|writing update files to insecure location on PC can lead to LPE|N/A|https://github.com/tomerpeled92/CVE/tree/main/CVE-2022-24138
|CVE-2021-44596|RCE|Wondershare/Dr. Fone|Due to software design flaws an unauthenticated user can communicate over UDP with the "InstallAssistService.exe" service(the service is running under SYSTEM privileges) and manipulate it to execute malicious executable without any validation from a remote location and gain SYSTEM privileges|https://medium.com/@tomerp_77017/wondershell-a82372914f26|https://github.com/netanelc305/WonderShell
|CVE-2021-44595|RCE|Wondershare/Dr. Fone|Wondershare Dr. Fone Latest version as of 2021-12-06 is vulnerable to Incorrect Access Control. A normal user can send manually crafted packets to the ElevationService.exe and execute arbitrary code without any validation with SYSTEM privileges.|https://medium.com/@tomerp_77017/wondershell-a82372914f26|https://github.com/netanelc305/WonderShell
|CVE-2021-42835|LPE|Plex/Plex Media Server|An attacker (with a foothold in a endpoint via a low-privileged user account) can access the exposed RPC service of the update service component. This RPC functionality allows the attacker to interact with the RPC functionality and execute code from a path of his choice (local, or remote via SMB) because of a TOCTOU race condition. This code execution is in the context of the Plex update service (which runs as SYSTEM).|https://ir-on.io/2021/12/02/local-privilege-plexcalation/|https://github.com/netanelc305/PlEXcalaison|
|CVE-2021–41067|LPE|Bopsoft/Listary|Improper implementation of the update process leads to the download of software updates with a /check-update HTTP-based connection. This can be exploited with MITM techniques. Together with the lack of package validation, it can lead to manipulation of update packages that can cause an installation of malicious content.|https://medium.com/@tomerp_77017/exploiting-listary-searching-your-way-to-system-privileges-8175af676c3e|N/A|
|CVE-2021–41066|LPE|Bopsoft/Listary|When Listary is configured as admin, Listary will not ask for permissions again if a user tries to access files on the system from Listary itself (it will bypass UAC protection; there is no privilege validation of the current user that runs via Listary).|https://medium.com/@tomerp_77017/exploiting-listary-searching-your-way-to-system-privileges-8175af676c3e|N/A|
|CVE-2021–41065|LPE|Bopsoft/Listary|An attacker can create a \\.\pipe\Listary.listaryService named pipe and wait for a privileged user to open a session on the Listary installed host. Listary will automatically access the named pipe and the attacker will be able to duplicate the victim's token to impersonate him. This exploit is valid in certain Windows versions (Microsoft has patched the issue in later Windows 10 builds).|https://medium.com/@tomerp_77017/exploiting-listary-searching-your-way-to-system-privileges-8175af676c3e|N/A|

