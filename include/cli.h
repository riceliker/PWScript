/**
 * @file cli.h
 * @author riceliker
 * @brief 
 * @version 0.1.0
 * @date 2026-06-16
 * 
 * @copyright Copyright (c) 2026
 * 
 * This head file will give the CLI environment to help you to run PWScript program.
 * The grammar like GCC, use `pws` to run it.
 * command list:
 * help (Show this text)
 * version (Show version)
 * exit (Exit the application)
 * set-line-max [number] (Set a line char number)
 * run [PWS File] ... (Add files to run)
 * run ... --debug (Allow use @debug to check)
 */
#pragma once

#include <stdio.h>
#include <string.h>

#define PWS_CLI_INPUT_LINE_MAX_WORDS 256

#define PWS_CLI_COLOR_RED    "\033[1;31m"
#define PWS_CLI_COLOR_GREEN  "\033[1;32m"
#define PWS_CLI_COLOR_YELLOW "\033[1;33m"
#define PWS_CLI_COLOR_BLUE   "\033[1;34m"
#define PWS_CLI_COLOR_RESET  "\033[0m"

/**
 * @brief 
 * When application run, call it. it will listen you code input
 * @return error code: int 
 */
int PWS_CLIConsole();

size_t PWS_CLI_CountTokens(const char *str, size_t* max_token_words);

int PWS_CLI_Help();
