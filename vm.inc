[org 0x0]

%define r0 0
%define r1 1
%define r2 2
%define r3 3
%define r4 4
%define r5 5
%define r6 6
%define r7 7

%macro _mov 2
db 0x90, %1, %2
%endmacro

%macro _add 2
db 0x91, %1, %2
%endmacro

%macro _sub 2
db 0x92, %1, %2
%endmacro

%macro _dec 1
db 0x93, %1
%endmacro

%macro _inc 1
db 0x94, %1
%endmacro

%macro _mul 2
db 0x95, %1, %2
%endmacro

%macro _div 2
db 0x96, %1, %2
%endmacro

%macro _push 1
db 0x97, %1
%endmacro

%macro _pop 1
db 0x98, %1
%endmacro

%macro _ptb 1
db 0x99, %1
%endmacro

%macro _xor 2
db 0x9a, %1, %2
%endmacro

%macro _call 1
db 0x9b
dw %1
%endmacro