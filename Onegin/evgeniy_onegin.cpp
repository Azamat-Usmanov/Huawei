#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "evgeniy_onegin.h"
#include <sys/stat.h>
#include <ctype.h>
#include <assert.h>


int counting_number_of_symbols(const char * file_name)
{
    assert(file_name);

    struct stat buff;
    stat(file_name, &buff); // TODO: Check errno (see create_buffer for similar problem)
    int symbols = buff.st_size;
    return symbols;
}

int create_buffer(FILE *f, char ** text, int number_of_symbols)
{
    assert(text);

    *text = (char*)calloc((number_of_symbols + 2), sizeof(char));
    
    assert(*text); // TODO: use perror, to explain what exactly went wrong
                   //       I will comment about such mistakes later with simple:
                   //       "Check errno"

    fread(*text, sizeof(char), number_of_symbols, f);

    int number_of_lines = 0;

    for (int i = 0; i < number_of_symbols; i++) // TODO: extract this in function
    {
        while((*text)[i] != '\n' && (*text)[i] != '\0') 
            i++;
        number_of_lines++;
    }
    (*text)[number_of_symbols] = '\n';

    return number_of_lines;
}

// TODO: Name is waaay to generic, doesn't tell anything
//
//       Naming function:   fill_array_of_structures
//       Is like naming it: function_that_does_stuff
//                      Or: take_arguments_and_compute_result
//
// Somehow this names doesn't really mean anything at all.
//
// And don't forget, it's already obvious that your function
// fills array of structures from its signature. No need to remind!
//
// ==> See:
// filling_array_of_structures(LINE_OF_TEXT **buffStruct, ...);
// Look, it right here:        ^~~~~~~~~~~~ ^^ it fills array
//                             |            |
//                             |            even more, allocates it
//                             |
//                             and it's an array of structures
//
// Think of a better name!

void filling_array_of_structures(LINE_OF_TEXT ** buffStruct, char * text, int number_of_symbols, int number_of_lines)
{// TODO:                                        ^~~~~~~~~~ fix naming
    assert(buffStruct);
    *buffStruct = (LINE_OF_TEXT*)calloc(number_of_lines, sizeof(LINE_OF_TEXT));

    assert(text);
    assert(*buffStruct); // TODO: Check errno

    number_of_lines = 0; // TODO: Why do you reuse this variable,
                         //       don't do this, create a new one
    int count = 0; // TODO: Count? Think of a better name
    for (int i = 0; i < number_of_symbols; i++)
    {
        (*buffStruct)[number_of_lines].str_pointer = text + i;
        // TODO: Looks like you are counting lines second time,
        //       extract this in function and use it in both places.
        while (text[i] != '\n' && text[i] != '\0')
            i++;
        (*buffStruct)[number_of_lines].len = i - count;
        number_of_lines++;
        count = i;
    }
}

void write_in_file(LINE_OF_TEXT * buffStruct, int number_of_lines, const char * name_file)
{ //                              ^~~~~~~~~~ TODO: What does buffStruct mean?
  //                              Is it buffer of structures? If so, the name
  //                              is useless, since it's already obvious that
  //                              this is a buffer of structures.
  //
  //                              Use names that actually mean something!
    assert(buffStruct);
    assert(name_file);

    FILE *f; // TODO: Pleeeeassse, stop splitting declaration and initialization
    f = fopen(name_file, "a"); // TODO: Check errno
    // TODO: and don't you single character names, i'm talking about your "f"

    for (int i = 0; i < number_of_lines; i++) 
    {
        fwrite(buffStruct[i].str_pointer, sizeof(char), buffStruct[i].len, f);
    }
    fputc('\n', f);
    fputc('\n', f);

    fclose(f); // Check errno
}

void write_original_text_in_text(int number_of_symbols, char * text, const char * name_file)
{ // TODO: Why have you called this function "write_*original*_text_in_text"?
  //
  //       First of all, why is it "original", seems to me that this function
  //       just writes whatever you give it in text, and it doesn't care at all
  //       about this text's "originality", one could even you it as "fprint":
  //        
  //       const char* message = "Hello, world!";
  //       write_original_text_in_text(strlen(message), message, "my-file.txt");
  //
  //       => A good generic function is named as it was the most specific thing.
  //
  //       Second of all, why "text_in_text", this tautology is hella confusing,
  //       and I still don't get it.
  //
  // In other words, this is "print_to_file" or "write_to_file" if you perfer,
  // but not "this" thing.
    assert(text);
    assert(name_file);
    FILE *f; // TODO: Stop doing this. Why?
    f = fopen(name_file, "a"); // TODO: Check errno 
    fwrite(text, sizeof(char), number_of_symbols, f);
    // TODO: Check return value for error
    fclose(f); // TODO: Check errno
}
