RESULT EQU 30H
ORG 00H
START:MOV  A,#1AH
CALL BINTOHEX
LJMP $
BINTOHEX:
MOV  DPTR,#ASCIITAB
      MOV  B,A                   ;暂存A
SWAP A
      ANL  A,#0FH             	;取高四位
      MOVC  A,@A+DPTR          ;查ASCII表
MOV  RESULT, A
      MOV  A,B                	;恢复A
      ANL  A,#0FH             	;取低四位
      MOVC  A,@A+DPTR        	;查ASCII表
MOV  RESULT+1,A
      RET
ASCIITAB:
DB  48,49,50,51,52,53,54,55
      DB  56,57,65,66,67,68,69,70	    ;定义数字对应的ASCII表
      END
