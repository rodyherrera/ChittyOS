/***
 * Copyright (C) Rodolfo Herrera Hernandez. All rights reserved.
 * Licensed under the MIT license. See LICENSE file in the project root 
 * for full license information.
 *
 * =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
 *
 * For related information - https://github.com/codewithrodi/ChittyOS/
 * 
 * = This project has been done for no profit and just to test 
 * = my knowledge and skills, no contributions or bug fixes are expected.
 *
 * =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
 ***/

#include "Core.h"

#define FS_SECTOR_DATA_SIZE FS_SECTOR_SIZE - sizeof(struct Sector*)

#define END_SECTOR 0

// ? Defining the structure that allows 
// ? handling the sectors of a file.
typedef struct SectorStruct{
  // * Variable that will store the next sector
  struct Sector* Next;

  // * Variable that stores the sector
  // * information, it is an array of 
  // * characters whose maximum size is 
  // * the value of the macro FS_SECTOR_DATA_SIZE.
  unsigned char Data[FS_SECTOR_DATA_SIZE];
} Sector;

// ? Defining a structure that will 
// ? allow managing the files in the system.
typedef struct{
  // * Defining two character arrays where the first 
  // * one will be the name of the file that will 
  // * have the maximum size of the macro value 
  // * FS_FILE_NAME_BUFFER and the tags of the 
  // * file that will have the maximum size of 
  // * the macro FS_FILE_TAGS_BUFFER.
  char Name[FS_FILE_NAME_BUFFER], Tags[FS_FILE_TAGS_BUFFER];

  // * Variable that will store the sector of the file.
  Sector* FirstSector;
} File;

File* FileIndex[sizeof(File*) * FS_MAX_FILE_COUNT];
int FileIndexEnd = 0;

// ? This function will allow 
// ? you to find a file, it 
// ? receives its name as a 
// ? parameter to be able to be found.
File* FindFile(char* Filename){
  // * A for loop is created which will be executed 
  // * as long as its iterator is less than the 
  // * number of files in the system (Linear Search)
  for(int Iterator = 0; Iterator <= FileIndexEnd; ++Iterator)
    // * The comparison is made between the name of the set of 
    // * files using the iterator with the name of 
    // * the received file, if this is the 
    // * same, the file instance will be returned.
    if(StringCompare(FileIndex[Iterator]->Name, Filename))
      return FileIndex[Iterator];
}

// ? Function that will check if a 
// ? file exists, the function will 
// ? receive the name of the file 
// ? which it will use as an identifier.
bool FileExists(char* Filename){
  // * Like the function of finding a file, this 
  // * function does a linear search in which it 
  // * will compare the name of each file with the 
  // * one it was received, in case a match is
  // * made, it will return a true, otherwise a false.
  for(int Iterator = 0; Iterator <= FileIndexEnd; ++Iterator)
    if(StringCompare(FileIndex[Iterator]->Name, Filename))
      return true;
  return false;
}

// ? Function that will return the 
// ? number of files in the system.
int FilesInSystem(){
  return FileIndexEnd;
}

// ? Function that will return 
// ? the name of a file using its identifier.
char* GetNamePerIdentifier(int Identifier){
  // * If the identifier in the file system is 
  // * not null, its name will be returned, otherwise 
  // * a file status not found will be returned 
  // * that is defined in the macro FILE_NOT_FOUND
  if(FileIndex[Identifier] != 0) 
    return FileIndex[Identifier]->Name;
  return (char*) FILE_NOT_FOUND;
}

// ? Function that will return the 
// ? identifier of a file using its name.
int GetIdentifierPerName(char* Filename){
  // * Like other functions, a linear search is made in the matrix 
  // * that contains the list of files. If the file is found, the 
  // * value of the for loop iterator will be 
  // * returned, representing the file's identifier.
  for(int Iterator = 0; Iterator < FileIndexEnd; ++Iterator)
    if(StringCompare(FileIndex[Iterator]->Name, Filename))
      return Iterator;
}

// ? Function that will allow to initialize a sector.
Sector* InitializeSector(){
  // * We create an institution of the sector and reserve memory.
  Sector* FileSector = KernelMalloc(sizeof(Sector));

  // * We set the following sector equal to the 
  // * value of the macro END_SECTOR
  FileSector->Next = END_SECTOR;
  
  // * We complete sector values ​​in empty memory.
  for(unsigned short int Iterator = 0; Iterator < FS_SECTOR_DATA_SIZE; ++Iterator)
    FileSector->Data[Iterator] = 0;
  
  // * Return the file sector
  return FileSector;
}

// ? Function that will check that the 
// ? file name contains valid 
// ? characters, the function receives the 
// ? file name to check its characters.
bool IsValidFile(char* Filename){
  // * Creating an array of characters 
  // * that will be the valid characters for the file name.
  char Valid[] = FS_FILE_NAME_VALID_CHARS;
  
  for(unsigned short int Iterator = 0; Iterator < StringLength(Filename); ++Iterator){
    bool IsAny = false;
    for(int SubIterator = 0; SubIterator < StringLength(Valid); ++SubIterator)
      if(Filename[Iterator] == Valid[SubIterator]) 
        IsAny = true;
    if(!IsAny) 
      return false;
  }
  
  // * If no problems were found with the 
  // * file name, a true value will be 
  // * returned, indicating that the file is valid.
  return true;
}

// ? Function that allows you to 
// ? create a file, receives as a parameter 
// ? the name that the file to create will have.
int CreateFile(char* Filename){
  // * Before creating the file, a series of 
  // * validations will be made, the first as you can 
  // * see will be that if the number of current files in 
  // * the system is greater than the value contained in 
  // * the macro FS_MAX_FILE_COUNT, a message will be 
  // * returned saying that the limit of files was 
  // * exceeded (value of macro FILE_COUNT_MAX_EXCEED)
  if(FileIndexEnd > FS_MAX_FILE_COUNT)
    return FILE_COUNT_MAX_EXCEEDED;
  
  // * Checking if the file exists, in that case the 
  // * value of the macro FILE_ALREADY_EXISTS will be 
  // * returned, which explicitly means that the 
  // * file already exists XD.
  if(FileExists(Filename))
    return FILE_ALREADY_EXISTS;

  // * We verify that the name of the file is 
  // * valid, that is, that it does not contain 
  // * special characters in its name, if the name 
  // * of the file is not valid, the value of the 
  // * macro FILE_NAME_INVALID will be 
  // * returned, which again is explicit, which 
  // * means that the name of the file is not valid.
  if(!IsValidFile(Filename))
    return FILE_NAME_INVALID;
  
  // * Reserving memory and instantiating the file.
  File* FileToCreate = KernelMalloc(sizeof(File));

  // * Setting the file name in the created instance.
  StringCopy(FileToCreate->Name, Filename);

  // * Initializing the sector for the file.
  FileToCreate->FirstSector = InitializeSector();

  // * Adding the new instance of the file to the file list.
  FileIndex[FileIndexEnd] = FileToCreate;

  // * Increasing the variable that has as value 
  // * the number of files in the system.
  FileIndexEnd += 1;

  return OK;
}

// ? Function that will allow removing a 
// ? file, receives as a parameter the 
// ? name of the file to delete.
int RemoveFile(char* Filename){
  for(unsigned short int Iterator = 0; Iterator < FileIndexEnd; ++Iterator)
    if(StringCompare(FileIndex[Iterator]->Name, Filename)){
      File* FileToRemove = FileIndex[Iterator];
      Sector* FileSector = FileToRemove->FirstSector;
      Sector* LastFileSector;
      do{
        LastFileSector = FileSector;
        KernelFree(LastFileSector);
        FileSector = (Sector*) FileSector->Next;
      }while(FileSector != END_SECTOR);
      KernelFree(FileToRemove);
      FileIndex[Iterator] = 0;
      return OK;
    }
  return FILE_NOT_FOUND;
}

// ? Function that allows to obtain the size of a file.
int FileSize(char* Filename){
  File* FileToGetSize = FindFile(Filename);
  Sector* FileSector = FileToGetSize->FirstSector;
  int Size = sizeof(FileSector->Data);
  while(FileSector->Next != END_SECTOR){
    FileSector = (Sector*) FileSector->Next;
    Size += sizeof(FileSector->Data);
  }
  return Size;
}

// ? Function that allows you to read the content of a file.
int ReadFile(char* Filename, char* Output){
  if(!FileExists(Filename)) 
    return FILE_NOT_FOUND;
  File* FileToRead = FindFile(Filename);
  Sector* FileSector = FileToRead->FirstSector;
  do{
    for(unsigned short int Iterator = 0; Iterator < FS_SECTOR_DATA_SIZE; ++Iterator)
      Output[Iterator] = FileSector->Data[Iterator];
    Output += FS_SECTOR_DATA_SIZE;
    FileSector = (Sector*) FileSector->Next;
  }while(FileSector != 0);
  return OK;
}

// ? This function allows you to write to a file, it receives 
// ? 3 parameters where the first is the name of the file in 
// ? which you want to write, the second is the content 
// ? to write and the third is the Depth.
int WriteFile(char* Filename, char* Data, unsigned long Depth){
  if(!FileExists(Filename)) 
    return FILE_NOT_FOUND;
  File* FileToWrite = FindFile(Filename);
  Sector* FileSector = FileToWrite->FirstSector;
  char* EOF = Depth + Data;
  while(Data < EOF){
    if(EOF - Data <= FS_SECTOR_DATA_SIZE){
      for(int Iterator = 0; Iterator < EOF - Data; ++Iterator)
        FileSector->Data[Iterator] = Data[Iterator];
      Data = EOF;
    }else{
      for(unsigned short int Iterator = 0; Iterator < FS_SECTOR_DATA_SIZE; ++Iterator)
        FileSector->Data[Iterator] = Data[Iterator];
      Data += FS_SECTOR_DATA_SIZE;
      Sector* LastFileSector = FileSector;
      LastFileSector->Next = (struct Sector*)InitializeSector();
      FileSector = (Sector*)LastFileSector->Next;
    }
  }
  return OK;
}

// ? This function allows removing the content of a 
// ? file or cleaning its sectors, it receives the 
// ? file to be cleaned as a parameter.
int ClearFile(char* Filename){
  if (!FileExists(Filename)) 
    return FILE_NOT_FOUND;
  File* FileToClear = FindFile(Filename);
  Sector* FileSector = FileToClear->FirstSector;
  do{
    for(unsigned short int Iterator = 0; Iterator < FS_SECTOR_DATA_SIZE; ++Iterator)
      FileSector->Data[Iterator] = 0;
    FileSector = (Sector*)FileSector->Next;
  }while(FileSector != 0);
  return OK;
}

// ? Write to a file in a more 
// ? friendly way using the previously created function.
int WritesFile(char* Filename, char* Data){
  return WriteFile(Filename, Data, StringLength(Data));
}

// ? Function that will be called when the
// ? kernel is initializing, this will create 
// ? a couple of actions on the filesystem.
void InitializeFileSystem(){
  CreateFile("MyFileOne");
  CreateFile("SomeFile");
  RemoveFile("MyFileOne");
  WritesFile("MySecondFile", "Hello world from ChittyOS\n");
}