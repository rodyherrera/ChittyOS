# ***
# * Copyright (C) Rodolfo Herrera Hernandez. All rights reserved.
# * Licensed under the MIT license. See LICENSE file in the project root 
# * for full license information.
# *
# * =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
# *
# * For related information - https://github.com/rodiihernandezz/ChittyOS/
# *
# * = This project has been done for no profit and just to test
# * = my knowledge and skills, no contributions or bug fixes are expected.
# *
# * =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
# ***

from os import system
import sys, platform

# Just tested in Linux Mint
kSupportedOperativeSystems = ['Darwin', 'Linux']

# The operating system is saved to later execute 
# different instructions depending 
# on the operating system the user has.
kOperativeSystem = platform.system()

# The arguments with which the 
# file was executed are saved.
kCallArguments = sys.argv

# Generating a dictionary which will contain a set of 
# commands that will be executed in each compatible 
# perating system, this when required by the program.
kListOfCommands = {
    'Linux': [
        'sudo apt install make',
        'sudo apt install gcc',
        'sudo apt install nasm',
        'sudo apt install aqemu'
    ],

    'MacOS': {
        'brew install make',
        'brew install gcc',
        'brew install nasm',
        'brew install aqemu'
    },

    'Both': {
        'set -x',
        'mkdir -p Production/',
        'mkdir -p Production/Distribution/',
        'mkdir -p Production/Binary/',
        'mkdir -p Production/Kernel/',
        'mkdir -p Production/Kernel/IO/',
        'mkdir -p Production/Kernel/Memory/',
        'mkdir -p Production/Kernel/Message/',
        'mkdir -p Production/Drivers/',
        'mkdir -p Production/Drivers/Cursor/',
        'mkdir -p Production/Drivers/Display/',
        'mkdir -p Production/Drivers/Keyboard/',
        'mkdir -p Production/Firmware/',
        'mkdir -p Production/Firmware/IDT/',
        'mkdir -p Production/Firmware/ISR/',
        'mkdir -p Production/Firmware/Port/',
        'mkdir -p Production/Firmware/SMBios/',
        'mkdir -p Production/Library',
        'mkdir -p Production/Library/Conv/',
        'mkdir -p Production/Library/Math/',
        'mkdir -p Production/Library/Rand/',
        'mkdir -p Production/Library/String/',
        'mkdir -p Production/FileSystem/',
        'mkdir -p Production/FileSystem/Core/',
        'mkdir -p Production/ISO/'
    }
}

# Function that allows ending the script.
def FinishScript() -> None:
    print('\n\n * Remember drink water bby <3. \n\n')

# Function that allows cleaning the 
# screen according to the operating system.
def ClearScreen() -> None:
    if kOperativeSystem == 'Windows':
        system('cls')
    else:
        system('clear')

# Function that allows to generate the 
# production folder where the output 
# of the source code compilation will be.
def GenerateProductionFolder() -> None:
    for kCommand in kListOfCommands['Both']:
        print(f'\n * Running <{kCommand}>\n')
        system(kCommand)
        ClearScreen()

# Function that allows you to build the source code.
def BuildSourceCode() -> None:
    ClearScreen()
    GenerateProductionFolder()
    system('make')

# Function that allows to generate the 
# ISO of the operating system
def GenerateISO() -> None:
    ClearScreen()
    print('\n * Generating ISO of Operating System...\n')
    system('make ISO')

# Function that allows to clean the production 
# folder, this to avoid errors when compiling.
def ClearProductionFolder() -> None:
    ClearScreen()
    print('\n * Cleaning production folder...\n')
    system('make Clear')

# Function that allows running the 
# operating system in the QEMU software.
def RunChittyOS() -> None:
    ClearScreen()
    print('\n * Executing ChittyOS in QEMU...\n')
    system('make Run')

# Function that allows you to install 
# the necessary packages to compile.
def InstallRequiredPackages() -> None:
    ClearScreen()
    for kCommand in kListOfCommands[kOperativeSystem]:
        print(f'\n * Installing <{kCommand}>\n')
        system(kCommand)
        ClearScreen()
try:
    # When the script starts the 
    # console will be cleaned up.
    ClearScreen()

    print('''
 * Chitty - A Basic Operative System
    ''')

    # We check if the operating system is compatible, in case 
    # it is not, we will inform the user that their 
    # operating system is not compatible and then we 
    # will finish the script.
    if not kOperativeSystem in kSupportedOperativeSystems:
        print(f' * Error, not supported OS <{kOperativeSystem}>.\n')
        FinishScript()
    else:
        # If the user's operating system is 
        # compatible, we will inform you that it is 
        # compatible to continue executing 
        # the instructions.
        print(f' * Compatible operative system <{kOperativeSystem}>')

    # According to the argument that the user gave at the time of 
    # making the call to the script, a series of instructions will 
    # be executed, for example if the user wants to install the 
    # dependencies to run ChittyOS he should enter the following 
    # command in the ROOT folder, 
    # 'python3 Tools/Helper.py Install-Dependencies', where 
    # 'Install-Dependencies' is the argument that is being 
    # given to the program.
    if 'Install-Dependencies' in kCallArguments:
        InstallRequiredPackages()
    
    elif 'Build-Source-Code' in kCallArguments:
        ClearProductionFolder()
        BuildSourceCode()

    elif 'Just-Run' in kCallArguments:
        RunChittyOS()

    elif 'Clear-Production-Folder' in kCallArguments:
        ClearProductionFolder()
    
    elif 'Generate-ISO' in kCallArguments:
        GenerateISO()

    elif 'All-In-One' in kCallArguments:
        InstallRequiredPackages()
        ClearProductionFolder()
        BuildSourceCode()
        GenerateISO()
        RunChittyOS()

    elif 'Fast-ReBuild' in kCallArguments:
        ClearProductionFolder()
        BuildSourceCode()
        GenerateISO()
    
    elif 'Generate-Production-Folder' in kCallArguments:
        GenerateProductionFolder()

    elif 'Fast-ReBuild-And-Run' in kCallArguments:
        ClearProductionFolder()
        BuildSourceCode()
        GenerateISO()
        RunChittyOS()

    else:
        # In case the user has not given any argument at the time of executing 
        # the script or if the user gave an argument but this is not valid, the 
        # following message will be displayed in which the available commands 
        # that exist for the script can be seen with a short description.
        print('''
 * You need enter a valid argument for Helper.
   
   > Arguments:
     - Install-Dependencies 
     ? To install the necessary dependencies 
     ? to compile the source code.
    
     - Build-Source-Code
     ? Compile the source code of the 
     ? operating system, output in the 
     ? production folder.

     - Generate-Production-Folder
     ? For create a production folder

     - Just-Run
     ? Run an instance of the QEMU software
     ? with the operating system on it.
    
     - Clear-Production-Folder
     ? Delete the production folder.

     - Generate-ISO
     ? Generate an operating system ISO.

     - All-In-One
     ? It allows executing all the commands from 
     ? installing the dependencies to running 
     ? the operating system in QEMU.

     - Fast-ReBuild
     ? Build the source code of the operating 
     ? system again without having to install the 
     ? necessary packages to compile and without 
     ? running the compiled operating system in QEMU.

     - Fast-ReBuild-And-Run
     ? Same instructions as "Fast-ReBuild" with the 
     ? difference that the operating system 
     ? compiled to QEMU is made.
''')

    FinishScript()

# If the interruption of the script is detected by means of 
# the combination of CTRL C keys or others, two instructions 
# will be executed where the first will be to clear the screen 
# and the second will be to complete the script.
except KeyboardInterrupt:
    ClearScreen(), FinishScript()

# If an unknown error occurs while the script 
# is running it will be displayed in a friendly way.
except Exception as Error:
    print(f'''\
 * Chitty Tools -> An error ocurred when the Helper was running :(.
   > {Error}''')