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
QUE1:  MOV  A,R3          ;ָ����R0
MOV  R0,A
        MOV  R7,#0AH      ;������R7
        CLR  00H           ;���־λ
MOV  A,@R0
QL2 :   INC  R0
        MOV  R2,A          ;����A�е����ݣ��������CJNE���õ�
CLR  C
MOV  22H,@R0
        CJNE  A,22H,QL3    ;�����(A)<(22)ʱCY��1.
SETB  C
QL3:    MOV  A,R2
        JC  QL1            ;<=��תQL1�����ý���
        SETB  00H          ;00HλΪ1ʱ��˵�������ݽ�������Ҫ������һ����ѭ��
XCH  A,@R0
DEC  R0
XCH  A,@R0
        INC  R0            ;���ڽ���
QL1:    MOV  A,@R0       ;A�е��������Ǻ���һ�����ݱȽ�
DJNZ  R7,QL2
        JB  00H,QUE1       ;һ��ѭ�����н�������
        END
