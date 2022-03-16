@256    //Inizializzo lo stack pointer
D=A
@SP
M=D 

@7      //Push 7
D=A
@SP
A=M
M=D
@SP
M=M+1

@8      //Push 8
D=A
@SP
A=M
M=D
@SP
M=M+1

M=M-1   //Add
A=M
D=M
M=0
@SP
M=M-1
A=M
D=D+M
M=D