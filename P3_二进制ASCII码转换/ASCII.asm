RESULT EQU 30H
ORG 00H
START:MOV  A,#1AH
CALL BINTOHEX
LJMP $
BINTOHEX:
MOV  DPTR,#ASCIITAB
      MOV  B,A                   ;�ݴ�A
SWAP A
      ANL  A,#0FH             	;ȡ����λ
      MOVC  A,@A+DPTR          ;��ASCII��
MOV  RESULT, A
      MOV  A,B                	;�ָ�A
      ANL  A,#0FH             	;ȡ����λ
      MOVC  A,@A+DPTR        	;��ASCII��
MOV  RESULT+1,A
      RET
ASCIITAB:
DB  48,49,50,51,52,53,54,55
      DB  56,57,65,66,67,68,69,70	    ;�������ֶ�Ӧ��ASCII��
      END
