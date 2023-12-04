// Saves names and numbers to a CSV file (work with files)

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Open CSV file
    // (fopen(<filename>, <open mod>)) this function used to open files from hard disc and work with its content, it save the file data in the memory and return its address, if the file not open or there aren’t enough space in memory the fun. return (NULL).
    //”a” is the beast file mode to work with it because when we run the programme more times don’t lose the data saved.
    //”FILE*” it’s the data type for open files and it create pointer only refer to the file in the memory (not variable).
    //”file” is the name of the pointer of the file to use it in the code.
    FILE *file = fopen("phonebook.csv", "a");

    if (!file) // check if the file open correctly. (!file) = (file == NULL)
    {
	    return 1;
    }
    // Get name and number
    char *name = get_string("Name: ");
    char *number = get_string("Number: ");

    // Print to file
    //(fprintf(<file name>, <data>)) function used to take data from memory and write it to the file in the hard disc.
    fprintf(file, "%s,%s\n", name, number);

    // Close file
    //we must close file after end the work with it to free the memory and avoid memory crash.
    //all operation on the file save in the memory until we close it the data save in the source file on the disc, so that when we edit or add data to a file and want to make operation on it we must close it first to save this data on disc, then read the data to work with it.
    fclose(file);
}
