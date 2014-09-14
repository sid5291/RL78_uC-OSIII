;********************************************************************************************************
;                                               uC/OS-III
;                                         The Real-Time Kernel
;
;                        (c) Copyright 1992-2011, Jean J. Labrosse, Plantation, FL
;                                          All Rights Reserved
;
;
;                                        NEC 78K0R Specific code
;                                IAR C/C++ Compiler for NEC 78K0R 4.60A
;
;
;
; File : OS_CPU_A.S26
;********************************************************************************************************

;********************************************************************************************************
;                                  PUBLIC AND EXTERNAL DECLARATIONS
;********************************************************************************************************

        PUBLIC  OSStartHighRdy
        PUBLIC  OSCtxSw
        PUBLIC  OSIntCtxSw
        PUBLIC  OSTickISR
        EXTERN  OSTaskSwHook
        EXTERN  OSTCBHighRdyPtr
        EXTERN  OSTCBCurPtr
        EXTERN  OSPrioCur
        EXTERN  OSPrioHighRdy
        EXTERN  OSIntEnter
        EXTERN  OSTimeTick
        EXTERN  OSIntExit
        EXTERN  OSIntNestingCtr
        EXTERN  Tmr_TickISR_Handler         ; implement function to clear the OS tick source

;********************************************************************************************************
;                                           MACRO DEFINITIONS
;********************************************************************************************************

PUSHALL  MACRO
         PUSH   RP0
         PUSH   RP1
         PUSH   RP2
         PUSH   RP3
         ENDM

POPALL   MACRO
         POP    RP3
         POP    RP2
         POP    RP1
         POP    RP0
         ENDM

; AGD 1/29/2014 Patch to support different interrupt vectors
        COMMON  INTVEC:CODE:ROOT(1)

        ORG     0x002C
        DW      OSTickISR                   ; Time tick vector

        ORG     0x007E
        DW      OSCtxSw                     ; Context Switch vector

        RSEG    CODE                        ; Switch to program code segment

;********************************************************************************************************
;                                  START HIGHEST PRIORITY READY TASK
;
; Description: This function is called by OSStart() to start the highest priority task that is ready to run.
;
; Note       : OSStartHighRdy() MUST:
;                 a) Call OSTaskSwHook() then,
;                 b) Set OSRunning to TRUE,
;                 c) Switch to the highest priority task.
;********************************************************************************************************

OSStartHighRdy:

        CALL    OSTaskSwHook                ; call OSTaskSwHook()
        MOVW    RP1, OSTCBHighRdyPtr        ; address of OSTCBHighRdyPtr in RP1
        MOVW    RP0, 0x0000[RP1]            ; RP0 = OSTCBHighRdyPtr->OSTCBStkPtr
        MOVW    SP, RP0                     ; stack pointer = RP0

        POPALL                              ; restore all processor registers from new task's stack

        RETI                                ; return from interrupt

;********************************************************************************************************
;                                     TASK LEVEL CONTEXT SWITCH
;
; Description: This function is called by OS_Sched() to perform a task level context switch.
;
; Note       : OSCtxSw() MUST:
;                 a) Save the current task's registers onto the current task stack
;                 b) Save the SP into the current task's OS_TCB
;                 c) Call OSTaskSwHook()
;                 d) Copy OSPrioHighRdy to OSPrioCur
;                 e) Copy OSTCBHighRdyPtr to OSTCBCurPtr
;                 f) Load the SP with OSTCBHighRdyPtr->OSTCBStkPtr
;                 g) Restore all the registers from the high priority task stack
;                 h) Perform a return from interrupt
;********************************************************************************************************
OSCtxSw:

        PUSHALL                             ; save processor registers on the stack

                                            ; save current task's stack pointer into current task's OS_TCB
        MOVW    RP2, OSTCBCurPtr            ; OSTCBCurPtr in RP2
        MOVW    RP0, SP
        MOVW    [RP2], RP0                  ; OSTCBCurPtr->OSTCBStkPtr = SP

        CALL    OSTaskSwHook                ; call OSTaskSwHook

        MOVW    RP0, OSTCBHighRdyPtr        ; get address of OSTCBHighRdyPtr
        MOVW    OSTCBCurPtr, RP0            ; OSTCBCurPtr = OSTCBHighRdyPtr

        MOV     R1, OSPrioHighRdy
        MOV     OSPrioCur, R1               ; OSPrioCur = OSPrioHighRdy

        MOVW    RP1, OSTCBHighRdyPtr        ; get address of OSTCBHighRdyPtr
        MOVW    RP0, 0x0000[RP1]            ; RP0 = OSTCBHighRdyPtr->OSTCBStkPtr
        MOVW    SP, RP0                     ; stack pointer = RP0

        POPALL                              ; restore all processor registers from new task's stack

        RETI                                ; return from interrupt

;********************************************************************************************************
;                                       ISR LEVEL CONTEXT SWITCH
;
; Description: This function is called by OSIntExit() to perform an ISR level context switch.
;
; Note       : OSIntCtxSw() MUST:
;                 a) Call OSTaskSwHook()
;                 b) Copy OSPrioHighRdy to OSPrioCur
;                 c) Copy OSTCBHighRdyPtr to OSTCBCurPtr
;                 d) Load the SP with OSTCBHighRdyPtr->OSTCBStkPtr
;                 e) Restore all the registers from the high priority task stack
;                 f) Perform a return from interrupt
;********************************************************************************************************

OSIntCtxSw:
        CALL    OSTaskSwHook                ; call OSTaskSwHook

        MOVW    RP0, OSTCBHighRdyPtr        ; get address of OSTCBHighRdyPtr
        MOVW    OSTCBCurPtr, RP0            ; OSTCBCurPtr = OSTCBHighRdyPtr

        MOV     R1, OSPrioHighRdy
        MOV     OSPrioCur, R1               ; OSPrioCur = OSPrioHighRdy

        MOVW    RP1, OSTCBHighRdyPtr        ; get address of OSTCBHighRdyPtr
        MOVW    RP0, 0x0000[RP1]            ; RP0 = OSTCBHighRdyPtr->OSTCBStkPtr
        MOVW    SP, RP0                     ; stack pointer = RP0

        POPALL                              ; restore all processor registers from new task's stack

        RETI                                ; return from interrupt

;********************************************************************************************************
;                                             OSTickISR()
;********************************************************************************************************


OSTickISR:

        PUSHALL                             ; Save processor registers on the stack

        INC     OSIntNestingCtr             ; increment OSIntNestingCtr
        CMP     OSIntNestingCtr, #1         ; if OSIntNestingCtr != 1
        BNZ     OSTickISR1                  ; jump to OSTickISR1

                                            ; else

        MOVW    RP2, OSTCBCurPtr            ; OSTCBCurPtr in RP2
        MOVW    RP0, SP
        MOVW    [RP2], RP0                  ; OSTCBCurPtr->OSTCBStkPtr = SP

OSTickISR1:

        CALL    Tmr_TickISR_Handler         ; clear timer interrupt source

        CALL    OSTimeTick                  ; call OSTimeTick()

        CALL    OSIntExit                   ; call OSIntExit()

        POPALL                              ; restore all processor registers from stack

        RETI                                ; return from interrupt

        END
