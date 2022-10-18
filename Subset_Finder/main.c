/*
 *  Programmer: Emirhan TALA             Date completed: Oct 18, 2022
 *
 *  A recursive subset finder.
 */

#include <stdio.h>
#include <string.h>

void one_ele_subs(char* demo_string, int index);
void two_ele_subs(char* string, int index1, int index2);
void three_ele_subs(char* string, int index1, int index2, int index3);

int main() {
    char* demo_string = "12345";

    printf("one_ele_subs\n");
    one_ele_subs(demo_string, 0);

    printf("two_ele_subs\n");
    two_ele_subs(demo_string, 0, 1);

    printf("three_ele_subs\n");
    three_ele_subs(demo_string, 0, 1, 2);
    return 0;
}

void
one_ele_subs(char* string, int index)
{
    int string_len;

    string_len = strlen(string);
    if (index == string_len - 1){
        printf("{%c}\n", string[index]);
    } else {
        printf("{%c}\n", string[index]);
        one_ele_subs(string, index + 1);
    }
}

void
two_ele_subs(char* string, int index1, int index2)
{
    int string_len;

    string_len = strlen(string);

    if (index2 == string_len - 1) {
        printf("{%c, %c}\n", string[index1], string[index2]);
        two_ele_subs(string, index1 + 1, index1 + 2);
    } else if (index2 == string_len) {
        return;
    } else {
        printf("{%c, %c}\n", string[index1], string[index2]);
        two_ele_subs(string, index1, index2 + 1);
    }
}

void
three_ele_subs(char* string, int index1, int index2, int index3)
{
    int string_len;

    string_len = strlen(string);

    if (index3 == string_len - 1 && index2 != string_len - 2) {
        printf("{%c, %c, %c}\n", string[index1], string[index2], string[index3]);
        three_ele_subs(string, index1, index2 + 1, index2 + 2);
    } else if (index3 == string_len - 1 && index2 == string_len - 2 && index1 != string_len - 2) {
        printf("{%c, %c, %c}\n", string[index1], string[index2], string[index3]);
        three_ele_subs(string, index1 + 1, index1 + 2, index1 + 3);
    } else if (index1 == string_len - 2){
        return;
    } else {
            printf("{%c, %c, %c}\n", string[index1], string[index2], string[index3]);
            three_ele_subs(string, index1, index2, index3 + 1);
    }
}

