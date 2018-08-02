;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;
;  	ProjName   	 Pinboard
;  	MCU Info   	  MC30P6060
;  	   	   	   	|>  No reset volatage
;  	   	   	   	|> 	WDT clock enable 288ms
;  	   	   	   	|> 	Crystal 8M 2T
;  	Date   	   	2017.12.18
;  	Author 	   	DS.Chin
;  	Version	   	0.0
;  	Brief  	   	the initial version
;
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "mc30P6060.inc"


;--------------------------------------------------------------------
; Port Define
#define	   	PORT_KEY_1 	   	   	P1,2
#define	   	PORT_KEY_2 	   	   	P1,4
#define	   	PORT_KEY_3 	   	   	P1,5
#define	   	PORT_DET   	   	   	P1,0
#define	   	PORT_OUT   	   	   	P1,1


;--------------------------------------------------------------------
; Parameters
cblock    0x10
StatusTemp
AccTemp

WorkFlag
KeyTime
KeyNum
SndTime
DetTime
SndCnt1
SndCnt



endc

;--------------------------------------------------------------------
; Flag Define
#define	   	KeyDoneFlag             WorkFlag,0
#define     SndFlag                 WorkFlag,1
#define     SndAllowFlag            WorkFlag,2


;--------------------------------------------------------------------
; Programm & Interrupt Entrance
   	org	   	    0x03ff
   	goto   	    _Start
   	org	   	    0x08
   	goto   	    _Interrupt

;--------------------------------------------------------------------
; Interrupt Code
_Interrupt:
   	movra  	   	AccTemp
    swapar 	   	STATUS
    movra  	   	StatusTemp

   	clrr        DetTime
    bclr        SndAllowFlag

_Interrupt_Exit:   	
   	clrr   	   	INTFLAG
    bclr        KBIF
   	swapar 	   	StatusTemp
    movra  	   	STATUS
    swapr  	   	AccTemp
    swapar 	   	AccTemp
   	RETIE




;--------------------------------------------------------------------
; MCU Config
_Start:
   	clrr   	INTECON             ;interrupt    
   	clrr    MCR    	   	   	   	;watch dog 
   	   	   	
   	movai   0x3D       	   	   	   	
   	movra   DDR1   	   	   	   	;P11 Output,others input
   	clrr    ODCON  	   	   	   	;pull-push
   	movai  	0x0B
   	movra  	PUCON  	   	   	   	;P12 P14 P15 pull-up

   	movai   0x01
   	movra   KBIM   	   	   	   	;p10 key interrupt enable
   	bset   	GIE	   	   	   	   	;Enable all interrupt
    bset    KBIE
   	   	
   	movai  	0x01
   	movra  	T0CR   	   	   	   	;uping edge, Ft0 = Fcpu, Pre for T0, Ft=8/2/4=1M Tt=1us  (2T)
   	movai   56
   	movra   T0CNT               ;time0 - 200  200 * 1 = 200us
   	

   	bset   	WDTEN
   	CLRWDT 	   	   	   	   	   	; Clear the watch dog timer count
   	
   	movai   0x3f
   	movra   FSR
   	goto    _Ram_clear





;--------------------------------------------------------------------
; Parameters Initialize
_Ram_clear:
   	clrr    INDF
   	decr    FSR
   	movai   0xd0
   	rsubar  FSR
   	jbclr   C 
   	goto    _Ram_clear
   	goto    _User_Init
   	



;--------------------------------------------------------------------
; User Data Initialize
_User_Init:
   	bclr   	PORT_OUT
   	goto    Main





;--------------------------------------------------------------------
; Main Code
Main:   
   	jbset   T0IF
   	goto    Main 
   	bclr    T0IF
   	
   	movai   56
   	movra   T0CNT  	   	   	   	; scan each 200us

   	CLRWDT 	   	   	   	   	   	;clear the WDT timer count
   	   	   
;  	jbclr   PORT_OUT
;  	goto    $+3
;  	bset    PORT_OUT
;  	goto    $+2
;  	bclr    PORT_OUT
;  	goto    Main

   	goto   	Key_Scan


;--------------------------------------------------------------------
; Scan the key status
Key_Scan:
   	jbclr  	PORT_KEY_1
   	goto   	Key_Scan_2

   	movai   10
    movra   KeyNum
   	goto   	Key_Deal

Key_Scan_2:
    jbclr   PORT_KEY_2
    goto    Key_Scan_3
    
    movai   20
    movra   KeyNum
    goto    Key_Deal
    
Key_Scan_3:
    jbclr   PORT_KEY_3
    goto    Key_Release
    
    movai   30
    movra   KeyNum
    goto    Key_Deal
    
Key_Release:
    clrr    KeyNum
    clrr    KeyTime
    bclr    KeyDoneFlag
    goto    Key_Scan_Exit
    
Key_Deal:
    jbclr   KeyDoneFlag
    goto    Key_Scan_Exit
    
   	incr   	KeyTime
   	movai  	250    	   	   	   	;50ms
   	rsubar 	KeyTime
   	jbset  	C
   	goto   	Key_Scan_Exit

   	bset   	KeyDoneFlag
    bset    SndFlag
    movar   KeyNum
    movra   SndTime
    goto    Key_Scan_Exit

Key_Scan_Exit:
   	goto   	Det_Scan
    
    
;---------------------------------------------------------------------
Det_Scan:
    jbclr   SndAllowFlag
    goto    Det_Scan_Exit
    
    jbset   PORT_DET
    goto    Det_Release

    incr    DetTime
    movai   10              ;2ms
    rsubar  DetTime
    jbset   C
    goto    Det_Scan_Exit
    
    clrr    DetTime
    bset    SndAllowFlag
    goto    Det_Scan_Exit
    
Det_Release:
    clrr    DetTime
    goto    Det_Scan_Exit
    
Det_Scan_Exit:
    goto    Pulse_Snd
    

;--------------------------------------------------------------------
Pulse_Snd:
    jbset   SndAllowFlag
    goto    Pulse_Release
    
    jbset   SndFlag
    goto    Pulse_Release
    
    bclr    KBIE
    bclr    KBIF
    bset    PORT_OUT
    
    incr    SndCnt
    movai   50              ;10ms
    rsubar  SndCnt
    jbset   C
    goto    Pulse_Snd_Exit
    
    clrr    SndCnt
    incr    SndCnt1
    movar   SndTime
    rsubar  SndCnt1
    jbset   C
    goto    Pulse_Snd_Exit
    
    bclr    SndFlag
    bclr    KBIF
    goto    Pulse_Release  
    
Pulse_Release:
    bclr    PORT_OUT
    bset    KBIE
    clrr    SndCnt
    clrr    SndCnt1
    goto    Pulse_Snd_Exit
    
Pulse_Snd_Exit:
   	goto   	Main







;--------------------------------------------------------------------
   	end
