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

// ? Macros that will be used in the anatomy 
// ? of the FileSystem folder and in the files 
// ? that include this header.
#define FS_SECTOR_SIZE 512
#define FS_MAX_FILE_COUNT 1000
#define FS_FILE_NAME_BUFFER 512
#define FS_FILE_TAGS_BUFFER 512
#define FS_FILE_NAME_VALID_CHARS "qwertyuiiopasdfghjklzxcvbnm1234567890QWERTYUIOPASDFGHJKLZXCVBNM"