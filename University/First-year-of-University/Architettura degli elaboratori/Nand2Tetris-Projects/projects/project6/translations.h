#ifndef translations_h
#define translations_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// SV = Stack Value
// in_address contiene già come ultimo carattere '\n'

void modifyLabel(char in_label[]){      // Toglie il carattere '\n' dalla fine della stinga
    int i = 0;
    while (in_label[i] != 0){
        if (in_label[i] == '\n') in_label[i] = '\0';
        i++;
    }

}

void incrementSP(FILE *in_outFile){
    fprintf(in_outFile, "%s", "@SP\n");
    fprintf(in_outFile, "%s", "M=M+1\n");
}
void decrementSP(FILE *in_outFile){
    fprintf(in_outFile, "%s", "@SP\n");
    fprintf(in_outFile, "%s", "M=M-1\n");
}
void takeLastSV(FILE *in_outFile){
    fprintf(in_outFile, "%s", "@SP\n");
    fprintf(in_outFile, "%s", "A=M\n");
    fprintf(in_outFile, "%s", "D=M\n");
}
void takePenultimateSV(FILE *in_outFile){
    fprintf(in_outFile, "%s", "@SP\n");
    fprintf(in_outFile, "%s", "A=M-1\n");
    fprintf(in_outFile, "%s", "D=M\n");
}
void goToNextSV(FILE *in_outFile){
    fprintf(in_outFile, "%s", "@SP\n");
    fprintf(in_outFile, "%s", "AM=M+1\n");
}
void goToPreviousSV(FILE *in_outFile){
    fprintf(in_outFile, "%s", "@SP\n");
    fprintf(in_outFile, "%s", "AM=M-1\n");
}
void takeAddress(FILE *in_outFile, char in_address[]){
    fprintf(in_outFile, "%c", '@');
    fprintf(in_outFile, "%s", in_address);
    fprintf(in_outFile, "%s", "D=A\n");
}
void assignmentToLastSV(FILE *in_outFile){
    fprintf(in_outFile, "%s", "@SP\n");
    fprintf(in_outFile, "%s", "A=M\n");
    fprintf(in_outFile, "%s", "M=D\n");
}
void saveInR13(FILE *in_outFile){
    fprintf(in_outFile, "%s", "@13\n");
    fprintf(in_outFile, "%s", "M=D\n");
}
void addressFromR13(FILE *in_outFile){
    fprintf(in_outFile, "%s", "@13\n");
    fprintf(in_outFile, "%s", "A=M\n");
    fprintf(in_outFile, "%s", "M=D\n");
}

void eq(FILE *in_outFile){
    takeLastSV(in_outFile);
    goToPreviousSV(in_outFile);
    fprintf(in_outFile, "%s", "D=D-M\n");
    fprintf(in_outFile, "%s", "@TRUE\n");
    fprintf(in_outFile, "%s", "D;JEQ\n");
    fprintf(in_outFile, "%s", "M=0\n");
    fprintf(in_outFile, "%s", "@CONTINUE\n");
    fprintf(in_outFile, "%s", "0;JMP\n");
    fprintf(in_outFile, "%s", "(TRUE)\n");
    fprintf(in_outFile, "%s", "M=1\n");
    fprintf(in_outFile, "%s", "(CONTINUE)\n");
    incrementSP(in_outFile);
}

void gt(FILE *in_outFile){
    goToPreviousSV(in_outFile);
    fprintf(in_outFile, "%s", "D=M\n");
    goToNextSV(in_outFile);
    fprintf(in_outFile, "%s", "D=D-M\n");
    goToPreviousSV(in_outFile);
    fprintf(in_outFile, "%s", "@TRUE\n");
    fprintf(in_outFile, "%s", "D;JLT\n");
    fprintf(in_outFile, "%s", "M=0\n");
    fprintf(in_outFile, "%s", "@CONTINUE\n");
    fprintf(in_outFile, "%s", "0;JMP\n");
    fprintf(in_outFile, "%s", "(TRUE)\n");
    fprintf(in_outFile, "%s", "M=1\n");
    fprintf(in_outFile, "%s", "(CONTINUE)\n");
    incrementSP(in_outFile);
}

void lt(FILE *in_outFile){
    goToPreviousSV(in_outFile);
    fprintf(in_outFile, "%s", "D=M\n");
    goToNextSV(in_outFile);
    fprintf(in_outFile, "%s", "D=D-M\n");
    goToPreviousSV(in_outFile);
    fprintf(in_outFile, "%s", "@TRUE\n");
    fprintf(in_outFile, "%s", "D;JgT\n");
    fprintf(in_outFile, "%s", "M=0\n");
    fprintf(in_outFile, "%s", "@CONTINUE\n");
    fprintf(in_outFile, "%s", "0;JMP\n");
    fprintf(in_outFile, "%s", "(TRUE)\n");
    fprintf(in_outFile, "%s", "M=1\n");
    fprintf(in_outFile, "%s", "(CONTINUE)\n");
    incrementSP(in_outFile);
}

void add(FILE *in_outFile){
    takeLastSV(in_outFile);
    goToPreviousSV(in_outFile);
    fprintf(in_outFile, "%s", "D=D+M\n");
    fprintf(in_outFile, "%s", "M=D\n");
    incrementSP(in_outFile);
}
void sub(FILE *in_outFile){
    takeLastSV(in_outFile);
    goToPreviousSV(in_outFile);
    fprintf(in_outFile, "%s", "D=D-M\n");
    fprintf(in_outFile, "%s", "M=D\n");
    incrementSP(in_outFile);
}
void neg(FILE *in_outFile){
    fprintf(in_outFile, "%s", "@SP\n");
    fprintf(in_outFile, "%s", "A=M\n");
    fprintf(in_outFile, "%s", "M=-M\n");
    incrementSP(in_outFile);
}

void or(FILE *in_outFile){
    takeLastSV(in_outFile);
    goToPreviousSV(in_outFile);
    fprintf(in_outFile, "%s", "D=D|M\n");
    fprintf(in_outFile, "%s", "M=D\n");
    incrementSP(in_outFile);
}
void and(FILE *in_outFile){
    takeLastSV(in_outFile);
    goToPreviousSV(in_outFile);
    fprintf(in_outFile, "%s", "D=D&M\n");
    fprintf(in_outFile, "%s", "M=D\n");
    incrementSP(in_outFile);
}
void not(FILE *in_outFile){
    fprintf(in_outFile, "%s", "@SP\n");
    fprintf(in_outFile, "%s", "A=M\n");
    fprintf(in_outFile, "%s", "M=!M\n");
    incrementSP(in_outFile);   
}

void push(FILE *in_outFile, int casistic, char in_address[]){
    takeAddress(in_outFile, in_address);    // D = n
    switch(casistic){
        case 0:     // push constant n
            break;
        case 1:     // push local n
            fprintf(in_outFile, "%s", "@LCL\n");
            fprintf(in_outFile, "%s", "A=M+D\n");     // SP point to: RAM[local n]
            fprintf(in_outFile, "%s", "D=M\n");       // D = RAM[local n]
            break;
        case 2:     // push argument n
            fprintf(in_outFile, "%s", "@ARG\n");
            fprintf(in_outFile, "%s", "A=M+D\n");
            fprintf(in_outFile, "%s", "D=M\n");
            break;
        case 3:     // push static n
            fprintf(in_outFile, "%s", "@16\n");
            fprintf(in_outFile, "%s", "A=D+A\n");
            fprintf(in_outFile, "%s", "D=M\n");
            break;
        case 4:     // push this n
            fprintf(in_outFile, "%s", "@THIS\n");
            fprintf(in_outFile, "%s", "A=M+D\n");
            fprintf(in_outFile, "%s", "D=M\n");
            break;
        case 5:     // push that n
            fprintf(in_outFile, "%s", "@THAT\n");
            fprintf(in_outFile, "%s", "A=M+D\n");
            fprintf(in_outFile, "%s", "D=M\n");
            break;
    }
    assignmentToLastSV(in_outFile);         // STACK| ... n
    incrementSP(in_outFile);
}
void pop(FILE *in_outFile, int casistic, char in_address[]){
    takeAddress(in_outFile, in_address);
    switch(casistic){
        case 0:     // pop local n
            fprintf(in_outFile, "%s", "@LCL\n");
            fprintf(in_outFile, "%s", "D=M+D\n");     // D = @local n
            break;
        case 1:     // pop argument n
            fprintf(in_outFile, "%s", "@ARG\n");
            fprintf(in_outFile, "%s", "D=M+D\n");     // D = @local n
            break;
        case 2:     // pop static n
            fprintf(in_outFile, "%s", "@16\n");
            fprintf(in_outFile, "%s", "D=A+D\n");     // D = @local n
            break;
        case 3:     // pop this n
            fprintf(in_outFile, "%s", "@THIS\n");
            fprintf(in_outFile, "%s", "D=M+D\n");     // D = @local n
            break;
        case 4:     // pop that n
            fprintf(in_outFile, "%s", "@THAT\n");
            fprintf(in_outFile, "%s", "D=M+D\n");     // D = @local n
            break;
    }
    saveInR13(in_outFile);
    takeLastSV(in_outFile);
    addressFromR13(in_outFile);
    incrementSP(in_outFile);
}


void label(FILE *in_outFile, char in_label[]){
    fprintf(in_outFile, "%c", '(');
    printf("%s", "After: "); printf("%s", in_label); printf("%c", '\n');
    modifyLabel(in_label);                  // Rimosso '\n' da in_label
    fprintf(in_outFile, "%s", in_label);
    fprintf(in_outFile, "%s", ")\n");
    incrementSP(in_outFile);
}
void ifgoto(FILE *in_outFile, char in_label[]){
    takeLastSV(in_outFile);
    //goToPreviousSV(in_outFile);           // Ci va o no il decrememento???
    fprintf(in_outFile, "%c", '@');
    fprintf(in_outFile, "%s", in_label);
    fprintf(in_outFile, "%s", "D;JGT\n");
    //incrementSP(in_outFile);              // Ci va l'incremento???
}
void goto_(FILE *in_outFile, char in_label[]){
    fprintf(in_outFile, "%c", '@');
    fprintf(in_outFile, "%s", in_label);
    fprintf(in_outFile, "%s", "0;JMP\n");
    incrementSP(in_outFile);
}

// Forse da aggiungere una cosa analoga al label, per il nome della funzione
void function(FILE *in_outFile){
    
}
void call(FILE *in_outFile){
    
}
void return_(FILE *in_outFile){
    
}

#endif