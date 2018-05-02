ORG  0000H
LJMP  START
ORG  0100H
START:  MOV  50H,#30H
MOV  51H,#11H
MOV  52H,#18H
MOV  53H,#09H
MOV  54H,#01H
MOV  55H,#2AH
MOV  56H,#36H
MOV  57H,#17H
MOV  58H,#28H
MOV  59H,#79H
MOV  5AH,#0A9H
MOV  R3,#50H
QUE1:  MOV  A,R3          ;指针送R0
MOV  R0,A
        MOV  R7,#0AH      ;长度送R7
        CLR  00H           ;清标志位
MOV  A,@R0
QL2 :   INC  R0
        MOV  R2,A          ;备份A中的内容，因下面的CJNE中用到
CLR  C
MOV  22H,@R0
        CJNE  A,22H,QL3    ;相等吗？(A)<(22)时CY置1.
SETB  C
QL3:    MOV  A,R2
        JC  QL1            ;<=则转QL1，不用交换
        SETB  00H          ;00H位为1时，说明有数据交换，仍要进行下一整体循环
XCH  A,@R0
DEC  R0
XCH  A,@R0
        INC  R0            ;大于交换
QL1:    MOV  A,@R0       ;A中的内容总是和下一个数据比较
DJNZ  R7,QL2
        JB  00H,QUE1       ;一次循环中有交换继续
        END
