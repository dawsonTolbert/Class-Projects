//Dawson Tolbert
//CS 325 - C Translation

#include <stdio.h>
#include <stdlib.h> //for malloc
#include <string.h> //for strlen

char* breakBefore(char[], char);
char* breakAfter(char[], char);
char* dest(char* text);
char* jump(char* text);
char* jumpOrDest(char theArray[], int length);
char* cInst(char* text);
char* comp(char* text);

int main(){
    puts("start");
    char* result = cInst("A=M");
    puts("cInst called");
    puts(result);
    puts("result put");
    free(result);
    return 0;
}

char* dest(char* text){
    puts("starting dest");
    char* toReturn = malloc(sizeof(char)*4);
    if(strcmp(text, "M") == 0){
        strcpy(toReturn,"001");
    }
    else if(strcmp(text, "D") == 0){
        strcpy(toReturn,"010");
    }
    else if(strcmp(text, "DM") == 0){
        strcpy(toReturn,"011");
    }
    else if(strcmp(text, "A") == 0){
        strcpy(toReturn,"100");
    }
    else if(strcmp(text, "AM") == 0){
        strcpy(toReturn,"101");
    }
    else if(strcmp(text, "AD") == 0){
        strcpy(toReturn,"110");
    }
    else if(strcmp(text, "ADM") == 0){
        strcpy(toReturn,"111");
    }
    else{
        strcpy(toReturn,"000");
    }

    return toReturn;
}

char* jump(char* text){
    puts("starting jump");
    char* toReturn = malloc(sizeof(char)*4);
    if(strcmp(text, "JGT") == 0){
        strcpy(toReturn,"001");
    }
    else if(strcmp(text, "JEQ") == 0){
        strcpy(toReturn,"010");
    }
    else if(strcmp(text, "JGE") == 0){
        strcpy(toReturn,"011");
    }
    else if(strcmp(text, "JLT") == 0){
        strcpy(toReturn,"100");
    }
    else if(strcmp(text, "JNE") == 0){
        strcpy(toReturn,"101");
    }
    else if(strcmp(text, "JLE") == 0){
        strcpy(toReturn,"110");
    }
    else if(strcmp(text, "JMP") == 0){
        strcpy(toReturn,"111");
    }
    else{
        strcpy(toReturn,"000");
    }

    return toReturn;
}

char* comp(char* text){
    puts("starting comp");
    char* toReturn = malloc(sizeof(char)*8);
    if(strcmp(text, "0") == 0){
        strcpy(toReturn,"0101010");
    }
    else if(strcmp(text, "1") == 0){
        strcpy(toReturn,"0111111");
    }
    else if(strcmp(text, "-1") == 0){
        strcpy(toReturn,"0111010");
    }
    else if(strcmp(text, "D") == 0){
        strcpy(toReturn,"0001100");
    }
    else if(strcmp(text, "A") == 0){
        strcpy(toReturn,"0110000");
    }
    else if(strcmp(text, "M") == 0){
        strcpy(toReturn,"1110000");
    }
    else if(strcmp(text, "!D") == 0){
        strcpy(toReturn,"0001101");
    }
    else if(strcmp(text, "!A") == 0){
        strcpy(toReturn,"0110001");
    }
    else if(strcmp(text, "!M") == 0){
        strcpy(toReturn,"1110001");
    }
    else if(strcmp(text, "-D") == 0){
        strcpy(toReturn,"0001111");
    }
    else if(strcmp(text, "-A") == 0){
        strcpy(toReturn,"0110011");
    }
    else if(strcmp(text, "-M") == 0){
        strcpy(toReturn,"1110011");
    }
    else if(strcmp(text, "D+1") == 0){
        strcpy(toReturn,"0011111");
    }
    else if(strcmp(text, "A+1") == 0){
        strcpy(toReturn,"0110111");
    }
    else if(strcmp(text, "M+1") == 0){
        strcpy(toReturn,"1110111");
    }
    else if(strcmp(text, "D-1") == 0){
        strcpy(toReturn,"0001110");
    }
    else if(strcmp(text, "A-1") == 0){
        strcpy(toReturn,"0110010");
    }
    else if(strcmp(text, "M-1") == 0){
        strcpy(toReturn,"1110010");
    }
    else if(strcmp(text, "D+A") == 0){
        strcpy(toReturn,"0000010");
    }
    else if(strcmp(text, "D+M") == 0){
        strcpy(toReturn,"1000010");
    }
    else if(strcmp(text, "D-A") == 0){
        strcpy(toReturn,"0010011");
    }
    else if(strcmp(text, "D-M") == 0){
        strcpy(toReturn,"1010011");
    }
    else if(strcmp(text, "A-D") == 0){
        strcpy(toReturn,"0000111");
    }
    else if(strcmp(text, "M-D") == 0){
        strcpy(toReturn,"1000111");
    }
    else if(strcmp(text, "D&A") == 0){
        strcpy(toReturn,"0000000");
    }
    else if(strcmp(text, "D&M") == 0){
        strcpy(toReturn,"1000000");
    }
    else if(strcmp(text, "D|A") == 0){
        strcpy(toReturn,"0010101");
    }
    else if(strcmp(text, "D|M") == 0){
        strcpy(toReturn,"1010101");
    }
    else{
        strcpy(toReturn,"ERROR");

    return toReturn;
    }
}

char* cInst(char* text){
    char* toReturn = malloc(sizeof(char)*17);
    strcpy(toReturn,"111");
    puts("starting cInst");
    puts(text);
    int len = strlen(text);
    printf("%d",len);
    printf("\n");
    char* jod = malloc(sizeof(char)*5);
    jod = jumpOrDest(text, len);
    if(strcmp("Dest", jod) == 0){
        puts("is dest");
        
        char* breakB = malloc(sizeof(char)*3);
        breakB = breakBefore(text,'=');
        puts(breakB);
        char* destStr = malloc(sizeof(char)*4);
        strcpy(destStr,dest(breakB));
        puts(destStr);
        for(int i = 0; i < 3; i++){
            toReturn[i+10] = destStr[i];
        }
        puts("dest added");
        puts(toReturn);

        char* breakA = malloc(sizeof(char)*3);
        breakA = breakAfter(text,'=');
        puts(breakA);
        char* compStr = malloc(sizeof(char)*8);
        strcpy(compStr,comp(breakA));
        for(int i = 0; i < 7; i++){
            toReturn[i+3] = compStr[i];
        }
        puts("comp added");
        puts(toReturn);
        for(int i = 0; i < 3; i++){
            toReturn[i+13] = '0';
        }
        
        puts("nulls added");
        puts(toReturn);
        

        free(compStr);
        free(destStr);

        return toReturn;
    }
    else if(strcmp("Jump", jumpOrDest(text, 16)) == 0){
        puts("is jump");
        
        char* breakA = malloc(sizeof(char)*3);
        breakA = breakAfter(text,';');
        puts(breakA);
        char* jumpStr = malloc(sizeof(char)*4);
        strcpy(jumpStr,jump(breakA));
        for(int i = 0; i < 3; i++){
            toReturn[i+13] = jumpStr[i];
        }
        puts("jump added");
        puts(toReturn);

        char* breakB = malloc(sizeof(char)*3);
        breakB = breakBefore(text,';');
        puts(breakB);
        char* compStr = malloc(sizeof(char)*8);
        strcpy(compStr,comp(breakB));
        for(int i = 0; i < 7; i++){
            toReturn[i+3] = compStr[i];
        }
        puts("comp added");
        puts(toReturn);
        
        for(int i = 0; i < 3; i++){
            toReturn[i+10] = '0';
        }
        puts("nulls added");
        puts(toReturn);

        free(compStr);
        free(jumpStr);

        return toReturn;
    }
    else{
        return "error";
    }
}

//---------------------------------------------------------

char* jumpOrDest(char theArray[], int length){
    puts("starting jumpOrDest");
	char* toReturn = malloc(sizeof(char)*5);
	for(int i = 0; i < length; i++){
	    printf("%c",theArray[i]);
	    printf("\n");
		if(theArray[i] == ';'){
			strcpy(toReturn,"Jump");
			return toReturn;
		}
		else if(theArray[i] == '='){
			strcpy(toReturn,"Dest");
			return toReturn;
		}
		else{
			strcpy(toReturn,"Eror");
			puts("jumpOrDest Error");
		}
	}
	return toReturn;
}

char* breakBefore(char string[], char breakChar){
    puts("starting breakBefore");
    //set position to -1
    int position = -1;

    /*
    find the position of the breakChar -> use a loop
    there might not be a breakChar, but there will be no more than 1
    */
    unsigned int length = strlen(string);
    for(int i = 0; i < length; i++){
        if(string[i] == breakChar){
            position = i;
            break;
        }
    }

    //if the position is greater than -1
    if(position > -1){
        //malloc room for the result and the \0: hint: position + 1
        char *result = (char*)malloc((position + 1)*sizeof(char));
        /*
        use a loop to copy from the original string into
        the new memory up to the break char
        */
        for(int i = 0; i < position; i++){
            result[i] = string[i];
        }

        //set the last position of the new memory to '\0'
        result[position + 1] = '\0';
        //return the new string
        return result;
    }
    //otherwise, return NULL
    else{
        return NULL;
    }
}



char* breakAfter(char string[], char breakChar){
    puts("starting breakAfter");
    //set position to -1
    int position = -1;

    /*
    find the position of the breakChar -> use a loop
    there might not be a breakChar, but there will be no more than 1
    */
    unsigned int length = strlen(string);
    for(int i = 0; i < length; i++){
        if(string[i] == breakChar){
            position = i + 1;
            break;
        }
    }

    //if the position is greater than -1
    if(position > -1){
        /*
            malloc room for the new string.
            this is harder than breakBefore
            you have to calculate from where you found the breakChar
            to the end of the string
            don't forget the \0 needs to have room
        */
        char *result = (char*)malloc(((length - position) + 1)*sizeof(char));

        /*
            copy the result into the new string
            this is also more complicated than breakBefore
            in that one, 0 went to 0, 1 went to 1
            but here, you might be copying position 10 into position 0
            hint: use a second variable to keep track of where you are in the
            original string.
        */
        for(int i = 0; i < (length - position); i++){
            result[i] = string[i + position];
        }

        //set the last position of the new string to \0
        result[(length - position) + 1] = '\0';
        //return the new string
        return result;
    }
  //otherwise, return null
    else{
        return NULL;
    }

}
