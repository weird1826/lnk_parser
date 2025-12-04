// Goal: Read a .lnk file and print the creation time

/**
 *  STEP-1
 *  I need a struct that matches the LNK header format (76 bytes)
 *      - It needs a size, a GUID, flags, and file attribute.
 * 
 *  STEP-2
 *  Main Function:
 *      - Check if the user provided a filename argument. If not, error.
 *      - Open the file.
 *      - If file fails to open, print error and exit.
 * 
 *  STEP-3
 *  Read the header:
 *      - Create a variable of my struct type.
 *      - Read 76 bytes from the file into that variable.
 * 
 *  STEP-4
 *  Verify it is actually an LNK file:
 *      - Check if the HeaderSize is 76
 *      - Check if the Magic Number (GUID) is correct.
 * 
 *  STEP-5
 *  Print the info:
 *      - Print the CreationTime
 * 
 *  STEP-6
 *  Cleanup:
 *      - Close the file.
 */

#include <stdio.h>
#include <stdint.h> // To use unsigned int 32 bit

/**
 * According to Microsoft Spec, LNK header looks like:
 * 1. Header Size (4 bytes)
 * 2. LinkCLSID (16 bytes) - Unique GUID, usually specific to the version of windows
 * 3. Link Flags (4 bytes) - Tells if the target is on a network drive, a local drive, etc.
 */
struct LnkHeader {
    uint32_t HeaderSize;
    uint8_t LinkCLSID[16];
    uint32_t LinkFlags;
} LnkHeader;

int main(int argc, char *argv[]){
    FILE* fptr;

    fptr = fopen("./test_folder.lnk", "rb");
    if(fptr == NULL) {
        printf("[ERROR] Program is experiencing difficulties opening the file. Try again later.\n");
        return 1;
    }

    /**
     * 1 - Where to put Data -> &myHeader (struct's addr)
     * 2 - How big is one item -> size of LnkHeader -> 4 bytes
     * 3 - How many items -> 1 item
     * 4 - From where - fptr
     */
    fread(&LnkHeader, sizeof(LnkHeader), 1, fptr);

    printf("Value of Header Size: %d\n", LnkHeader.HeaderSize);
    printf("GUID: ");
    for(int i = 0; i < 16; i++) printf("%02X ", LnkHeader.LinkCLSID);
    printf("\n");
    printf("Value of Header LinkFlags: %x\n", LnkHeader.LinkFlags);
    
    fclose(fptr);
    return 0;
}