# Compiler For mC

This is the repository for CS 4318 Compiler Construction
_______________________________________________________________________________________________________________

## **IMPORTANT**

Do not comment any **.json** files. I am pretty sure they will mess up the programs on others computers. I had issues with them in the past. Just discard the changes off of GitHub Desktop while vsCode is closed, that is the only way I could get the files to discard.
_______________________________________________________________________________________________________________

## What you need to download:
This is only if you are changing code or using MakeFile.

    Flex: (In Terminal/Command Line)
                -----------------------------------------------------------------------------
                MAC:        brew install flex
                -----------------------------------------------------------------------------
                Windows:    Install MSYS2 from msys2.org
                            Then run the following command to install Flex: pacman -S flex
                -----------------------------------------------------------------------------
                Linux:      sudo apt update
                            sudo apt install flex
                -----------------------------------------------------------------------------

_______________________________________________________________________________________________________________       
        

## Extensions used in VSCode:
                -----------------------------------------------------------------------------
                Lex: Lex & Flex Syntax Highlighting
                -----------------------------------------------------------------------------
                CMake: CMake langage support for VSCode
                -----------------------------------------------------------------------------
                CMake Tools: Extended CMake support in VSCode
                -----------------------------------------------------------------------------
                Makefile Tools: Provide makefile support in VSCode
                -----------------------------------------------------------------------------
                Txt Syntax: Highlight text files
                -----------------------------------------------------------------------------

_______________________________________________________________________________________________________________


## How to run Flex and MakeFile:
To debug and test your code, you can use MakeFile, use this command:

    flex src/scanner.l
    
This should create a lex.c file and in the terminal there will be debugging error or warnigns if you have any.

After checking for errors and warnings, you can clean the file using this command:

    make clean

Lastly we will make the obj folder, use this command:

    make

Every time you want to update the code and run test you have to use this sequence of commands after you have saved the updated code:

    make clean
    make

_______________________________________________________________________________________________________________ 


## How to run Scanner:
In the folder of Project_Phase_1 run this command:

    ./obj/scanner < path/of/mC/file.mc
    
Example (From Phase 1):

    ./obj/scanner < src/test.mc

_______________________________________________________________________________________________________________ 


## How to run Phase 2
In the Folder of Prohect_Phase_2 run this command:

    ./obj/mcc < TestCases/"FileName".mC

_______________________________________________________________________________________________________________ 

## Dates:
    Repository Last Updated: 3/31/2025
    
    Phase 1 Completion (Scanner): 2/25/2025

    Phase 2 Completion: 3/31/2025
