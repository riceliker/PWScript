#include "cli.h"
#include <stddef.h>
#include <stdio.h>

size_t PWS_CLI_input_line_max_words = 2048;

size_t PWS_CLI_CountTokens(const char* str, size_t* max_token_words)
{
    size_t number = 1;
    bool is_space = false;
    size_t this_token_length = 1;
    while (*str != '\0')
    {
        if (*str == ' ')
        {
            if(!is_space)
                is_space = true;
        }
        else 
        {
            if(is_space)
            {
                is_space = false;
                number++;
                if(*max_token_words < this_token_length)
                    *max_token_words = this_token_length;
                this_token_length = 0;
            } 
        }
        str++;
        this_token_length++;
    }
    if(*max_token_words < this_token_length)
        *max_token_words = this_token_length;
    return number;
}

int PWS_CLI_Help()
{
    printf("Welcome to use PWScript Interper CLI.\n");
    printf("PWScript v0.1.0 (c) 2026-present riceliker & Contributors. Open Source License: MIT.\n");
    printf(PWS_CLI_COLOR_RED"Download: https://github.com/riceliker/PWScript\n"PWS_CLI_COLOR_RESET);
    printf("\n");
    printf(PWS_CLI_COLOR_GREEN" _______          _______           _       _    \n"PWS_CLI_COLOR_RESET);
    printf(PWS_CLI_COLOR_GREEN"|  __ \\ \\        / / ____|         (_)     | |  \n"PWS_CLI_COLOR_RESET);
    printf(PWS_CLI_COLOR_GREEN"| |__) \\ \\  /\\  / / (___   ___ _ __ _ _ __ | |_ \n"PWS_CLI_COLOR_RESET);
    printf(PWS_CLI_COLOR_GREEN"|  ___/ \\ \\/  \\/ / \\___ \\ / __| '__| | '_ \\| __|\n"PWS_CLI_COLOR_RESET);
    printf(PWS_CLI_COLOR_GREEN"| |      \\  /\\  /  ____) | (__| |  | | |_) | |_ \n"PWS_CLI_COLOR_RESET);
    printf(PWS_CLI_COLOR_GREEN"|_|       \\/  \\/  |_____/ \\___|_|  |_| .__/ \\__|\n"PWS_CLI_COLOR_RESET);
    printf(PWS_CLI_COLOR_GREEN"                                     | |        \n"PWS_CLI_COLOR_RESET);
    printf(PWS_CLI_COLOR_GREEN"                                     |_|        \n"PWS_CLI_COLOR_RESET);
    printf("Usage:\n");
    printf("\n");
    printf(PWS_CLI_COLOR_BLUE"  (PWS) > [command] [parameter]\n"PWS_CLI_COLOR_RESET);
    printf("\n");
    printf("Info Command:\n");
    printf("\n");
    printf(PWS_CLI_COLOR_YELLOW"    exit"PWS_CLI_COLOR_RESET);
    printf("            Exit CLI application in console.\n");
    printf(PWS_CLI_COLOR_YELLOW"    help"PWS_CLI_COLOR_RESET);
    printf("            Show the command help and about.\n");
    printf(PWS_CLI_COLOR_YELLOW"    version"PWS_CLI_COLOR_RESET);
    printf("         Show the PWS version.\n");
    printf("\n");
    printf("Code Command:\n");
    printf("\n");
    printf(PWS_CLI_COLOR_BLUE"    run"PWS_CLI_COLOR_RESET);
    printf("                 Run the PWS program.\n");
    printf("\n");
    printf(PWS_CLI_COLOR_GREEN"        --debug"PWS_CLI_COLOR_RESET);
    printf("         Allow @debug to make breakpoint.\n");
    printf(PWS_CLI_COLOR_GREEN"        --file"PWS_CLI_COLOR_RESET);
    printf("          Link the code file to build.\n");
    printf(PWS_CLI_COLOR_GREEN"        --lib"PWS_CLI_COLOR_RESET);
    printf("           Link the local PWS library path to build.\n");
    printf(PWS_CLI_COLOR_GREEN"        --bin"PWS_CLI_COLOR_RESET);
    printf("           Link the local C library path to build.\n");
    return 0;
}

int PWS_CLIConsole()
{
    for(;;)
    {
        // Get string for input.
        char input_command[PWS_CLI_input_line_max_words];
        printf("(PWS) > ");
        scanf(" %[^\n]", input_command);
        size_t input_command_length = strlen(input_command);
        if (input_command_length < 2)
            continue;
        if (input_command_length > 0 && input_command[input_command_length-1] == '\n')
            input_command[input_command_length-1] = '\0';
        // count token number.
        size_t max_token_words = 1;
        size_t token_number = PWS_CLI_CountTokens(input_command, &max_token_words);
        // get word on list
        char command_tokens[token_number][max_token_words];
        size_t i = 0;
        char *token = strtok(input_command, " ");
        while (token != NULL && i < token_number)
        {
            strncpy(command_tokens[i], token, max_token_words - 1);
            command_tokens[i][max_token_words - 1] = '\0';
            i++;
            token = strtok(NULL, " ");
        }
        // ### command_token: char[][]
        
        if(strcmp(command_tokens[0], "exit") == 0)
        {
            break;
        }

        if(strcmp(command_tokens[0], "help") == 0)
        {
            PWS_CLI_Help();
            continue;
        }

        if(strcmp(command_tokens[0], "version") == 0)
        {
            printf(PWS_CLI_COLOR_GREEN"0.1.0"PWS_CLI_COLOR_RESET);
            continue;
        }

        printf(PWS_CLI_COLOR_RED"ERROR: Unknown Command: %s.\n"PWS_CLI_COLOR_RESET, command_tokens[0]);

    }
    return 0; 
}