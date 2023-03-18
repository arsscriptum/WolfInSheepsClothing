# Process Hollowing

Process injection to hide a running process by hiding, or masquarading it to an innocent process.

After launching 2 process, you copy the code portion in the executable image over ot the other processes memory space.

 - [PEB](https://en.wikipedia.org/wiki/Process_Environment_Block#:~:text=In%20computing%20the%20Process%20Environment,other%20than%20the%20operating%20system)

Process hollowing exploits are often initiated through malicious links in phishing emails. For example, a Windows user could select one of the infected links, leading their computer to execute a PowerShell command. That command could then download and install the attacker's malware.

Similar to other types of code injection attacks, process hollowing can be difficult to detect.

How it works
The malware used will typically allow the attacker to do something to a software program that seems real, like "add a pause during the launch process." During the pause, the attacker can remove legitimate code in the program's executable file and replace it with malicious code. This is referred to as hollowing. When the launch process resumes, it will execute the attacker's code before continuing to run normally. Essentially, process hollowing allows the attacker to turn a legitimate executable file into a malicious container that appears to be trustworthy. This strategy means it's highly likely that the target's antimalware software will not be able to detect there was a swap.