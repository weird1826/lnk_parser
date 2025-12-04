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