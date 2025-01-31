WordSearchGenerator: WordSearchGenerator.c
	gcc WordSearchGenerator.c -o WordSearchGenerator -Wall -Werror

	
clean:
	rm -f WordSearchGenerator *~