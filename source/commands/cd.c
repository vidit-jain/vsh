#include "cd.h"

void changeDirectory(TokenArray *tokens) {
	if (tokens->argCount == 1 ||
		isEqualString(*(tokens->args[1]), *initString("~"))) {
		stringCopy(previousPath, *currentPath);
		stringCopy(currentPath, *homePath);
		goToCurrentPath();
	} else if (isEqualString(*(tokens->args[1]), *initString("-"))) {
		String *temp = newString();
		stringCopy(temp, *currentPath);
		stringCopy(currentPath, *previousPath);
		stringCopy(previousPath, *temp);
		goToCurrentPath();
	} else {
		stringCopy(previousPath, *currentPath);
		chdir(tokens->args[1]->str);
		setCurrentPath();
	}
}

void commandCD(TokenArray *tokens) {
	if (tokens->argCount > 2) {
		printf("cd : Incorrect number of arguments\n");
		return;
	}
	changeDirectory(tokens);
}