//char *AUTHOR_NAME        = (char *) "Your Name";
//char *AUTHOR_AUTHORSHIP  = (char *) "I acknowledge that I have worked on this
// assignment independently, except where explicitly noted and referenced.
// Any collaboration or use of external resources has been properly cited.
// I am fully aware of the consequences of academic dishonesty and agree to
// abide by the university's academic integrity policy.";

// code.c — student implementation only
/* * code.c - Implementation file for Lab 8  */


#include "code.h"
#include <stdio.h>

/*
 * code.c - Assignment 8: File Access and Math Functions
 *
 * TODO: Include <stdio.h> (file functions), <stdlib.h> (abs),
 *       <math.h> (all other math functions) and your own "code.h".
 *
 * GENERAL RULES (apply to EVERY function below):
 *   - Check the arguments FIRST. If they are invalid, return false
 *     immediately, BEFORE calling fopen(), so the file is never touched.
 *   - Always check whether fopen() succeeded. If it did not, return false
 *     (or -1 for the functions that return int / long).
 *   - Always close every file you open, including on error paths
 *     that happen AFTER a successful fopen().
 *   - Text files: doubles are written as "%.2f\n", integers as "%d\n",
 *     one value per line.
 *   - Binary files: raw bytes only, no separators, no extra data.
 *   - Return true only if the write/read AND the close succeeded.
 *
 * OPTIONAL TIP: Many functions differ only in the math function and the
 * file mode. You may write small `static` helper functions (for example
 * "write one double as a text line using a given mode" and
 * "write an array of doubles as raw bytes using a given mode")
 * and reuse them. Helpers are not tested, and they do not go into code.h.
 */


/* ========================= PART A: Text mode ========================= */

/*
 * 1. create_abs_txt (returns bool; parameters: filename, int value)
 *    - Open the file for writing (it is created or overwritten).
 *    - Compute the absolute value of the integer with abs().
 *    - Write it as an integer followed by a newline.
 *    - Close the file and report success only if writing and closing worked.
 */
// TODO
bool create_abs_txt(const char *filename, int value) {
    FILE *file = fopen(filename, "w");

    if (file == NULL)
    {
        return false;
    }

    int abs_value = abs(value);
    fprintf(file, "%d\n", abs_value);

    if (fclose(file) != 0)
    {
        return false;
    }

    return true;
}
/*
 * 2. create_fabs_txt (returns bool; parameters: filename, double value)
 *    - Same idea as the previous function, but for a double:
 *      use fabs() and write with exactly two digits after the decimal point.
 *    - Open mode: write (create / overwrite).
 *      Bool create_fabs_txt(const char *filename, double value) {
 */
// TODO
bool create_fabs_txt(const char *filename, double value) {
    FILE *file = fopen(filename, "w");

    if (file == NULL)
    {
        return false;
    }
    double fabs_value = fabs(value);
    fprintf(file, "%.2f\n", fabs_value);

    if (fclose(file) != 0)
    {
        return false;
    }

    return true;
}b
/*
 * 3. append_sqrt_txt (returns bool; parameters: filename, double value)
 *    - Invalid input: negative value -> return false, do not touch the file.
 *    - Open the file in APPEND mode, so older content stays.
 *    - Write sqrt(value) as a new line with two decimal digits.
 *    - Close and report success.
 */
// TODO
bool append_sqrt_txt(const char *filename, double value) {
    if (value < 0)
    {
        return false;
    }

    FILE *file = fopen(filename, "a");

    if (file == NULL)
    {
        return false;
    }

    double sqrt_value = sqrt(value);
    fprintf(file, "%.2f\n", sqrt_value);

    if (fclose(file) != 0)
    {
        return false;
    }

    return true;
}
/*
 * 4. append_pow_txt (returns bool; parameters: filename, double base, double exponent)
 *    - Invalid input: base equal to zero AND exponent negative
 *      (division by zero) -> return false, do not touch the file.
 *    - Open in APPEND mode, write pow(base, exponent) as a new line
 *      with two decimal digits, close, report success.
 */
// TODO
bool append_pow_txt(const char *filename, double base, double exponent) {
    if (base == 0 && exponent < 0)
    {
        return false;
    }

    FILE *file = fopen(filename, "a");

    if (file == NULL)
    {
        return false;
    }
    double pow_value = pow(base, exponent);
    fprintf(file, "%.2f\n", pow_value);

    if (fclose(file) != 0)
    {
        return false;
    }

    return true;
}
/*
 * 5. create_ceil_floor_txt (returns bool; parameters: filename, double value)
 *    - Open in WRITE mode (create / overwrite).
 *    - Write TWO lines: first ceil(value), then floor(value),
 *      both with two decimal digits.
 *    - Success requires that both writes AND the close worked.
 */
// TODO
    bool create_ceil_floor_txt(const char *filename, double value) {
    FILE *file = fopen(filename, "w");

    if (file == NULL)
    {
        return false;
    }
    double ceil_value = ceil(value);
    double floor_value = floor(value);

    if (fprintf(file, "%.2f\n", ceil_value) < 0)
    {
        fclose(file);
        return false;
    }
    if (fprintf(file, "%.2f\n", floor_value) < 0)
    {
        fclose(file);
        return false;
    }
    return true;
}

/*
 * 6. append_round_txt (returns bool; parameters: filename, double value)
 *    - Open in APPEND mode, write round(value) as a new line
 *      with two decimal digits, close, report success.
 *    - No invalid input exists for this function.
 */
// TODO
bool append_round_txt(const char *filename, double value) {
    FILE *file = fopen(filename, "a");

    if (file == NULL)
    {
        return false;
    }
    double round_value = round(value);
    fprintf(file, "%.2f\n", round_value);

    if (fclose(file) != 0)
    {
        return false;
    }

    return true;
}
/*
 * 7. append_fmod_txt (returns bool; parameters: filename, double x, double y)
 *    - Invalid input: y equal to zero -> return false, do not touch the file.
 *    - Open in APPEND mode, write fmod(x, y) as a new line
 *      with two decimal digits, close, report success.
 */
// TODO
bool append_fmod_txt(const char *filename, double x, double y) {
    if (y == 0)
    {
        return false;
    }

    FILE *file = fopen(filename, "a");

    if (file == NULL)
    {
        return false;
    }
    double fmod_value = fmod(x, y);
    fprintf(file, "%.2f\n", fmod_value);

    if (fclose(file) != 0)
    {
        return false;
    }

    return true;
}
/*
 * 8. load_txt_values (returns int; parameters: filename, double array, int max_count)
 *    - Open the file for reading. If it cannot be opened, return -1.
 *    - Keep a counter of values read, starting at 0.
 *    - Repeat while the counter is below max_count: read one number
 *      with the formatted-input function. Remember that a double needs
 *      the "long float" conversion specifier. The input function returns
 *      the number of items it successfully read; stop the loop when
 *      that is not exactly 1 (end of file or bad data).
 *    - Store each value into the next slot of the array and increase the counter.
 *    - Close the file and return the counter.
 */
// TODO
int load_txt_values(const char *filename, double *values, int max_count) {
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        return -1;
    }   

    int count = 0;
    while (count < max_count) {
        if (fscanf(file, "%lf", &values[count]) != 1) {
            break;
        }
        count++;
    }
    fclose(file);
    return count;
}
/*
 * 9. clear_file (returns bool; parameters: filename)
 *    - Think: which open mode removes all existing content
 *      and creates the file when it does not exist?
 *    - You do not need to write anything. Just open and close.
 *    - Report success only if both the open and the close worked.
 */
// TODO
bool clear_file(const char *filename) {
    FILE *file = fopen(filename, "w");

    if (file == NULL)
    {
        return false;
    }

    if (fclose(file) != 0)
    {
        return false;
    }

    return true;
}

/* ========================= PART B: Binary mode ========================= */

/*
 * 10. create_abs_bin (returns bool; parameters: filename, int value)
 *     - Open in BINARY WRITE mode (create / overwrite).
 *     - Compute abs(value) and keep it in an int variable
 *       (you need its address to write it).
 *     - Write exactly ONE element whose size is the size of an int.
 *     - Success: fwrite reported 1 element written AND the close worked.
 */
// TODO
bool create_abs_bin(const char *filename, int value) {
    FILE *file = fopen(filename, "wb");

    if (file == NULL)
    {
        return false;
    }

    int result = abs(value);
    size_t written = fwrite(&result, sizeof(int), 1, file);
    if (written != 1)
    {
        fclose(file);
        return false;
    }

    if (fclose(file) != 0)
    {
        return false;
    }

    return true;
}
/*
 * 11. create_fabs_bin (returns bool; parameters: filename, double value)
 *     - Same idea as above, but the stored value is a double (fabs of the input).
 *     - Open in BINARY WRITE mode.
 *     - Keep the result in a double variable and write ONE element
 *       of size sizeof(double).
 */
// TODO
bool create_fabs_bin(const char *filename, double value) {
    FILE *file = fopen(filename, "wb");

    if (file == NULL)
    {
        return false;
    }   

    double result = fabs(value);
    size_t written = fwrite(&result, sizeof(double), 1, file);
    if (written != 1)
    {
        fclose(file);
        return false;
    }

    if (fclose(file) != 0)
    {
        return false;
    }

    return true;
}
/*
 * 12. append_sqrt_bin (returns bool; parameters: filename, double value)
 *     - Invalid input: negative value -> return false BEFORE opening the file.
 *     - Open in BINARY APPEND mode, so older content stays.
 *     - Store sqrt(value) in a double variable and write ONE double.
 *     - Close and report success.
 */
// TODO
bool append_sqrt_bin(const char *filename, double value) {
    if (value < 0)
    {
        return false;
    }

    FILE *file = fopen(filename, "ab");

    if (file == NULL)
    {
        return false;
    }

    double result = sqrt(value);
    size_t written = fwrite(&result, sizeof(double), 1, file);
    if (written != 1)
    {
        fclose(file);
        return false;
    }

    if (fclose(file) != 0)
    {
        return false;
    }

    return true;
}
/*
 * 13. append_pow_bin (returns bool; parameters: filename, double base, double exponent)
 *     - Invalid input: base equal to zero AND exponent negative
 *       -> return false, do not touch the file.
 *     - Open in BINARY APPEND mode, write pow(base, exponent) as ONE double,
 *       close, report success.
 */
// TODO
bool append_pow_bin(const char *filename, double base, double exponent) {
    if (base == 0 && exponent < 0)
    {
        return false;
    }

    FILE *file = fopen(filename, "ab");

    if (file == NULL)
    {
        return false;
    }

    double result = pow(base, exponent);
    size_t written = fwrite(&result, sizeof(double), 1, file);
    if (written != 1)
    {
        fclose(file);
        return false;
    }

    if (fclose(file) != 0)
    {
        return false;
    }

    return true;
}
/*
 * 14. create_ceil_floor_bin (returns bool; parameters: filename, double value)
 *     - Open in BINARY WRITE mode (create / overwrite).
 *     - Write TWO doubles: first ceil(value), then floor(value).
 *     - Hint: put both results in a small double array of size 2
 *       and write both elements with a SINGLE write call
 *       (count = 2), or use two separate calls.
 *     - Success requires that all writes AND the close worked.
 */
// TODO
bool create_ceil_floor_bin(const char *filename, double value) {
    FILE *file = fopen(filename, "wb");

    if (file == NULL)
    {
        return false;
    }
    double results[2] = {ceil(value), floor(value)};
    size_t written = fwrite(results, sizeof(double), 2, file);
    if (written != 2)
    {
        fclose(file);
        return false;
    }
    if (fclose(file) != 0)
    {
        return false;
    }
    return true;
}
/*
 * 15. append_round_bin (returns bool; parameters: filename, double value)
 *     - Open in BINARY APPEND mode, write round(value) as ONE double,
 *       close, report success.
 *     - No invalid input exists for this function.
 */
// TODO
bool append_round_bin(const char *filename, double value) {
    FILE *file = fopen(filename, "ab");

    if (file == NULL)
    {
        return false;
    }
    double result = round(value);
    size_t written = fwrite(&result, sizeof(double), 1, file);
    if (written != 1)
    {
        fclose(file);
        return false;
    }
    if (fclose(file) != 0)
    {
        return false;
    }
    return true;
}
/*
 * 16. append_fmod_bin (returns bool; parameters: filename, double x, double y)
 *     - Invalid input: y equal to zero -> return false, do not touch the file.
 *     - Open in BINARY APPEND mode, write fmod(x, y) as ONE double,
 *       close, report success.
 */
// TODO
bool append_fmod_bin(const char *filename, double x, double y) {
    if (y == 0)
    {
        return false;
    }

    FILE *file = fopen(filename, "ab");

    if (file == NULL)
    {
        return false;
    }
    double result = fmod(x, y);
    size_t written = fwrite(&result, sizeof(double), 1, file);
    if (written != 1)
    {
        fclose(file);
        return false;
    }
    if (fclose(file) != 0)
    {
        return false;
    }
    return true;
}
/*
 * 17. load_abs_bin (returns bool; parameters: filename, int pointer out)
 *     - Open in BINARY READ mode. If it cannot be opened, return false.
 *     - Read ONE element of size sizeof(int) directly into *out
 *       (the pointer already holds the address, so do not use & here).
 *     - Close the file (always, also when the read failed).
 *     - Return true only if exactly 1 element was read.
 *       A file that is too short makes the read function return 0.
 */
// TODO
bool load_abs_bin(const char *filename, int *out) {
    FILE *file = fopen(filename, "rb");

    if (file == NULL)
    {
        return false;
    }

    size_t read = fread(out, sizeof(int), 1, file);
    if (fclose(file) != 0)
    {
        return false;
    }

    return read == 1;
}
/*
 * 18. load_bin_values (returns int; parameters: filename, double array, int max_count)
 *     - Open in BINARY READ mode. If it cannot be opened, return -1.
 *     - Keep a counter starting at 0.
 *     - Repeat while the counter is below max_count: read ONE double
 *       into the next array slot. Stop the loop when the read function
 *       does not return 1 (end of file).
 *     - Increase the counter after every successful read.
 *     - Close the file and return the counter.
 */
// TODO
int load_bin_values(const char *filename, double *values, int max_count) {
    FILE *file = fopen(filename, "rb");

    if (file == NULL)
    {
        return -1;
    }

    int count = 0;
    while (count < max_count) {
        size_t read = fread(&values[count], sizeof(double), 1, file);
        if (read != 1) {
            break;
        }
        count++;
    }
    fclose(file);
    return count;
}
/*
 * 19. load_bin_value_at (returns bool; parameters: filename, int index, double pointer out)
 *     - Invalid input: negative index -> return false BEFORE opening the file.
 *     - Open in BINARY READ mode. If it cannot be opened, return false.
 *     - Calculate the byte offset: index multiplied by the size of a double.
 *       Convert it to long to match the type expected by the seek function.
 *     - Jump there from the BEGINNING of the file.
 *       If the seek fails, close the file and return false.
 *     - Read ONE double into *out. Close the file.
 *     - Return true only if exactly 1 element was read
 *       (a file that is too short gives 0).
 */
// TODO
bool load_bin_value_at(const char *filename, int index, double *out) {
    if (index < 0)
    {
        return false;
    }

    FILE *file = fopen(filename, "rb");

    if (file == NULL)
    {
        return false;
    }

    long offset = (long)index * sizeof(double);
    if (fseek(file, offset, SEEK_SET) != 0)
    {
        fclose(file);
        return false;
    }

    size_t read = fread(out, sizeof(double), 1, file);
    if (fclose(file) != 0)
    {
        return false;
    }

    return read == 1;
}
/*
 * 20. get_file_size (returns long; parameters: filename)
 *     - Open in BINARY READ mode. If it cannot be opened, return -1.
 *     - Jump to the END of the file (offset 0, origin = end).
 *       If the seek fails, close the file and return -1.
 *     - Ask for the current position: at the end of the file it equals
 *       the size in bytes. Store it in a long variable.
 *     - Close the file and return the stored size.
 */
// TODO
bool get_file_size(const char *filename, long *file_size) {
    FILE *file = fopen(filename, "rb");

    if (file == NULL)
    {
        return false;
    }

    if (fseek(file, 0, SEEK_END) != 0)
    {
        fclose(file);
        return false;
    }

    long size = ftell(file);
    if (size == -1L)
    {
        fclose(file);
        return false;
    }

    if (fclose(file) != 0)
    {
        return false;
    }

    *file_size = size;
    return true;
}