# Chitty Operating System
##### A basic and minimal operating system
###### Just tested in Linux Mint
ChittyOS is an operating system which was written to test my programming skills in the C language, no contributions or solutions to its bugs are expected although it is likely that I will receive a couple of updates when I have time, ChittyOS will just be one of my hobbies and my first step in this world of operating systems development.

You can experiment or learn how this works internally, I have commented most of the operating system code, I hope it is not a problem so that you can do what you want and do black, red and purple magic with this!

## The helper
In the Chitty code, there is a folder called Tools which contains a script written in Python which will allow you to compile the source code, generate an ISO, run the operating system, install the dependencies among other things, you only need to call the script to For the magic to happen, it is IMPORTANT that the script call MUST be from the ROOT folder of the project, you MUST NOT enter the tools folder and call the script or enter the source folder and call the script, the call must be from the folder root.

### Arguments for helper
To install the dependencies that the operating system needs in order to compile.
```bash
python3 Tools/Helper.py Install-Dependencies
```
It allows you to compile the operating system, the output of this will be in the "Production" folder, a folder that will be automatically generated in the ROOT folder.
```bash
python3 Tools/Helper.py Build-Source-Code
```
It allows you to generate the production folder with all its sub folders inside, this can be useful if you want to execute the make command for the Makefile file by yourself, this since if your code contains errors the Helper.py will clean the screen in short periods so that it will not let you see in detail what errors you have.
```bash
python3 Tools/Helper.py Generate-Production-Folder
```
The following command allows you to run the operating system in the QEMU emulator, important to know that to execute this command you MUST have the operating system already compiled in the Production folder.
```bash
python3 Tools/Helper.py Just-Run
```
It allows you to delete all the contents of the Production folder, along with it :)
```bash
python3 Tools/Helper.py Clear-Production-Folder
```
It allows you to generate an ISO image of the operating system, the output of this will be in the Production folder in its ISO subfolder.
```bash
python3 Tools/Helper.py Generate-ISO
```
This command allows you to execute all the aforementioned commands, this is recommended if you are just installing the repository on your computer, since with this command you will install the dependencies, generate the production folder, build the source code, generate the ISO and make it run the operating system in the QEMU emulator, logically the command to delete the production folder will not be executed.
```bash
python3 Tools/Helper.py All-In-One
```
It allows you to compile the source code of the operating system again without having to install the necessary packages and without having to run the operating system in the QEMU emulator.
```bash
python3 Tools/Helper.py Fast-ReBuild
```
This is the command that is recommended when you are developing Chitty, since this command allows you to execute the same instructions as those made by the Fast-ReBuild argument with the difference that it also allows you to run the newly compiled operating system in the QEMU emulator.
```bash
python3 Tools/Helper.py Fast-ReBuild-And-Run
```

### Installation
Then if you execute the following series of commands, whether you are on MacOS or Linux you will already have the operating system running on the virtual machine, remember that this software along with the steps have only been tested in Linux Mint.
```bash
# Clone repository
https://github.com/codewithrodi/ChittyOS/

# Enter to project directory
cd ChittyOS

# To install dependencies compile source code and run the operating system.
python3 Tools/Helper.py All-In-One
```
### Requirements
You only need to have Python installed to run the Helper, and also drink wateeeeeeer :).

```bash
# For MacOS
brew install python

# For Linux
sudo apt install python3
```
### Errors and contributions
This operating system, as I mentioned before, was only created as a hobby, I wanted to do it, it has two bugs, one is that it does not read the content of the files correctly and the second is when it comes to accessing the BIOS information using the neofetch command, If you are an experienced developer and you want to solve it, you have nothing to prevent it, everything is mostly commented, anyway, being a hobby and by way of experiment, this project does not expect contributions, you can use the code to learn and create your own operating system and impress the girls :).

##### Remember drink water =)