#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool numberCheck(string key);
bool sameCharCheck(string key);
string encrypt(string key, string message);

int main(int argc, string argv[])
{
    if (argc != 2) {
        printf("Usage: ./substitution \"key\"\n");
        return 1;
    }
    else {
        if (strlen(argv[1]) != 26) {
            printf("Key must be 26 unique alphabetic characters long.\n");
            return 1;
        }
        else if (numberCheck(argv[1])) {
            printf("Letters only!\n");
            return 1;
        }
        else if (sameCharCheck(argv[1])) {
            printf("Characters can NOT be repeated.\n");
            return 1;
        }
        else {
            string message = get_string("plaintext: ");
            printf("ciphertext: %s\n", encrypt(argv[1], message));
        }
    }
}

bool numberCheck(string key) {
    for (int i = 0, len = strlen(key); i < len; i++) {
        if (!isalpha(key[i])) {
            return true;
        }
    }
    return false;
}

bool sameCharCheck(string key) {
    char first;
    for (int i = 0, len = strlen(key); i < len; i++) {
        first = key[i];
        for (int j = i + 1; j < len; j++) {
            if (first == key[j]) {
                return true;
            }
        }
    }
    return false;
}

string encrypt(string key, string message) {
    for (int i = 0, len = strlen(message); i < len; i++) {
        if (isupper(message[i])) {
            message[i] = toupper(key[(message[i] - 'A')]);
        }
        else if (islower(message[i])) {
            message[i] = tolower(key[(message[i] - 'a')]);
        }
    }
    return message;
}