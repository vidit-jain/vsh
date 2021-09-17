#include "cd.h"

void changeDirectory(TokenArray *tokens) {
	if (tokens->argCount == 1 ||
		isEqualString(*tokens->args[1], *initString("~"))) {
		stringCopy(previousPath, *currentPath);
		stringCopy(currentPath, *homePath);
		goToCurrentPath();
	} else if (isEqualString(*tokens->args[1], *initString("-"))) {
		String *temp = newString();
		stringCopy(temp, *currentPath);
		stringCopy(currentPath, *previousPath);
		stringCopy(previousPath, *temp);
		goToCurrentPath();
	} else {
		stringCopy(previousPath, *currentPath);
		if (chdir(tokens->args[1]->str) == -1) {
			errorHandler(GENERAL_NONFATAL);
		}
		setCurrentPath();
	}
}

void commandCD(TokenArray *tokens) {
	if (tokens->argCount > 2) {
		errorHandler(INCORRECT_ARGC);
		return;
	}
	changeDirectory(tokens);
}