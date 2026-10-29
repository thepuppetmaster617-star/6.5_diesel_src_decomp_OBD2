; Calibration 09389101  (broadcast code DBRZ)   $2000-$58FF
; groups: TA    generated for asm11 - included by bank0.asm

	org	$2000

k_2000:	; 44 values in 44 cals, differs in: ALT EGR NA TA TCM
	fcb	$00,$8F,$44,$D1                                                 ; 2000

ROM_checksum: ; 44 values in 44 cals, differs in: ALT EGR NA TA TCM (range $00E1-$FDC5)
;   analysis: ROM_checksum: 16-bit sum of bank0 $2006-FFFF + bank1 $8000-FFFF
	fdb	$D7C1

checksum_skip_AA: ; 44 values in 44 cals, differs in: ALT EGR NA TA TCM
;   analysis: checksum_skip_AA: $AA disables ROM check, $A4 = enforced
	fcb	$A4,$44,$42,$52,$5A                                             ; 2006

; b0=torque reduction on slip (OBD1 4009.0 same), b1=turbo enable (OBD1 4009.1 same), b2=TCM / no internal trans control (OBD1 4009.2: 0=auto 1=manual), b3=low-res limp mode (OBD1 4009.3: block backup mode, no pump position sensor), b4=high temp high idle (OBD1 4009.4 hot fuel temp high idle), b5=in-gear idle raise (31F1), b6=P/N idle target (31E7), b7=PTO high idle (OBD1 4009.7 PTO mode)
Configuration_set: ; 5 values in 44 cals, differs in: EGR NA TA TCM (range $B8-$BE)
	fcb	$BA                                                             ; 200B

; b0=delta-fuel limiter enable (OBD1 400A.0), b1=?, b2=EGR-mode delta-fuel limiter 95B5 / normal 95F0 (OBD1 400A.2), b3=not read by this OS (OBD1 400A.3 = SEM torque reduction), b4=trans torque reduction (OBD1 400A.4 was servo/on-off EGR), b5=turbo: baro learned from MAP, b6=NA: baro = MAP, b7=timing adder 28EB axis = boost
Configuration_set_2_200C: ; 5 values in 44 cals, differs in: EGR NA TCM (range $1D-$B0)
	fcb	$B0                                                             ; 200C

; b0=P0602 -> safe shutdown, b1=anti-theft (VATS), b2=diag tests 0B/0C, b3=trans sensors wired to ECM, b4=external module data tests, b5=timing adder 293D enable, b6=?, b7=alt trans / open-loop EGR
Configuration_set_3_200D: ; 7 values in 44 cals, differs in: ALT EGR NA TA TCM (range $00-$88)
	fcb	$06                                                             ; 200D

CAL_CYLBAL_PACETMR: ; same in all 44 cals
;   OBD1 CAL_CYLBAL_PACETMR [A]: cylinder balance
	fcb	$04                                                             ; 200E

CAL_CYLBAL_GAIN: ; same in all 44 cals
;   OBD1 CAL_CYLBAL_GAIN [B]: cylinder balance adjust gain
	fdb	$0003

CAL_CYLBAL_MINADJ: ; same in all 44 cals
;   OBD1 CAL_CYLBAL_MINADJ [A]: max cylinder balance
	fdb	$0060

CAL_CYLBAL_MAXADJ: ; same in all 44 cals
;   OBD1 CAL_CYLBAL_MAXADJ [A]: min cylinder balance
	fdb	$FFE0

CAL_CYLINDER_LIST: ; same in all 44 cals
;   OBD1 CAL_CYLINDER_LIST [A]: cylinder order list
	fcb	$00,$01,$02,$03,$04,$05,$06,$07                                 ; 2015

kw_PID1C_obd_type_201D: ; 3 values in 44 cals, differs in: ALT EGR TA TCM (range $01-$05)
;   analysis: PID $1C OBD requirement ($01 = OBD-II)
	fcb	$01                                                             ; 201D

k_201E:	; same in all 44 cals
	fcb	$56                                                             ; 201E

k_201F:	; same in all 44 cals
	fcb	$1E                                                             ; 201F

k_2020:	; same in all 44 cals
	fcb	$0A                                                             ; 2020

CAL_MIN_GLO_OVERRIDE: ; same in all 44 cals
;   OBD1 CAL_MIN_GLO_OVERRIDE [B]
	fcb	$1E                                                             ; 2021

CAL_MAX_GLO_OVERRIDE: ; same in all 44 cals
;   OBD1 CAL_MAX_GLO_OVERRIDE [B]
	fcb	$78                                                             ; 2022

CAL_CYLSEQ: ; same in all 44 cals
;   OBD1 CAL_CYLSEQ [C]: cylinder sequence
	fcb	$07,$08,$01,$02,$03,$04,$05,$06                                 ; 2023

CAL_TDCLEARN_MINRPM: ; same in all 44 cals
;   OBD1 CAL_TDCLEARN_MINRPM [C]: min RPM to run timing calibration
	fcb	$10                                                             ; 202B

CAL_TDCLEARN_ITSPOS: ; same in all 44 cals
;   OBD1 CAL_TDCLEARN_ITSPOS [B]: tp ITS desired position for timing calibration = 131 steps
	fcb	$83                                                             ; 202C

CAL_TDCLEARN_MAXTM: ; same in all 44 cals
;   OBD1 CAL_TDCLEARN_MAXTM [B]: time to run timing calibration
	fcb	$FF                                                             ; 202D

CAL_TDCLEARN_FILT: ; same in all 44 cals
;   OBD1 CAL_TDCLEARN_FILT [B]: TDC offset filter coefficient
	fcb	$20                                                             ; 202E

kw_TDC_offset_nominal_202F: ; same in all 44 cals
;   analysis: $0124 nominal angle
	fdb	$0124

kw_TDC_offset_min_2031: ; same in all 44 cals
;   analysis: $FFE4 = -28 counts; P1214 limit
	fdb	$FFE4

kw_TDC_offset_max_2033: ; same in all 44 cals
;   analysis: $001C = +28 counts; P1214 limit
	fdb	$001C

kw_2035: ; same in all 44 cals
	fdb	$12C0

k_2037:	; same in all 44 cals
	fcb	$E6                                                             ; 2037

k_2038:	; same in all 44 cals
	fcb	$9D                                                             ; 2038

k_2039:	; same in all 44 cals
	fcb	$35                                                             ; 2039

k_203A:	; same in all 44 cals
	fcb	$18                                                             ; 203A

CAL_SAFE_LIM_TM1: ; same in all 44 cals
;   OBD1 CAL_SAFE_LIM_TM1 [B]: timer for fuel limiter (TTS == $05)
	fcb	$05                                                             ; 203B

CAL_SAFE_LIM_TM2: ; same in all 44 cals
;   OBD1 CAL_SAFE_LIM_TM2 [A]: timer for fuel limiter (TTS == $05)
	fcb	$05                                                             ; 203C

CAL_SAFE_APP_LIM: ; same in all 44 cals
;   OBD1 CAL_SAFE_APP_LIM [B]: % = N / 2.56 ($59 = 35%) APP limit for fuel limit ? (TTS == $00)
	fcb	$00                                                             ; 203D

CAL_SAFE_RPM_LIM: ; 2 values in 44 cals, differs in: NA TCM (range $20-$40)
;   OBD1 CAL_SAFE_RPM_LIM [B]: RPM = N * 18.75, ($20 = 600) 2RPM limit	for fuel limit ? (TTS == $40)
	fcb	$20                                                             ; 203E

tbl2D_RPM_fuel_timed_203F: ; 2D table, 2 values in 44 cals, differs in: EGR TA
;   OBD1 CAL_SAFE_FUEL_LIM [B]: maximum fuel limit - I believe this is safety fuel limiter
	fcb	$08
	fcb	$00,$00,$54,$72,$6D,$64,$60,$60,$60

kw_2049: ; same in all 44 cals
	fdb	$0B0E

kw_204B: ; same in all 44 cals
	fdb	$E664

kw_204D: ; same in all 44 cals
	fdb	$3133

kw_204F: ; same in all 44 cals
	fdb	$4009

kw_2051: ; same in all 44 cals
	fdb	$0064

kw_backup_inj_PW_offset_2053: ; same in all 44 cals
;   analysis: $FF60 = -160 added to COMMAND_FUEL_PW for backup pulse; added to COMMAND_FUEL_PW; backup pulse only if result > 0 (signed)
	fdb	$FF60

CAL_BACKUP_TIMESHIFT: ; same in all 44 cals
;   OBD1 CAL_BACKUP_TIMESHIFT [A]: backup, min delay time = 31.8 microseconds
	fdb	$0064

kw_2057: ; same in all 44 cals
;   analysis: $000A added to backup pulse time
	fdb	$000A

tbl_2059: ; same in all 44 cals
;   analysis: 3 filter coefficients for cruise speed error
	fcb	$21,$30,$40                                                     ; 2059

CAL_CRUISE_DGAIN: ; same in all 44 cals
;   OBD1 CAL_CRUISE_DGAIN [B]: looks like dgain?
	fdb	$0000

tbl_cruise_igain_overspeed_205E: ; same in all 44 cals
;   analysis: 2 words: I gain states 5-6 / states <=4, overspeed (2062 same, underspeed)
	fcb	$04,$00,$05,$00                                                 ; 205E

tbl_2062: ; same in all 44 cals
	fcb	$04,$00,$05,$00                                                 ; 2062

tbl_2066: ; same in all 44 cals
;   analysis: 2 words $1400/$0D00 (state>4 / else)
	fcb	$14,$00,$0D,$00                                                 ; 2066

tbl_206A: ; same in all 44 cals
;   analysis: 2 words $1300/$0D00
	fcb	$13,$00,$0D,$00                                                 ; 206A

kw_206E: ; same in all 44 cals
	fdb	$00C8

CAL_CRUISE_MAXRPM: ; same in all 44 cals
;   OBD1 CAL_CRUISE_MAXRPM [B]: max RPM for cruise, low byte unused
	fcb	$D5,$74                                                         ; 2070

CAL_CRUISE_MINRPM: ; same in all 44 cals
;   OBD1 CAL_CRUISE_MINRPM [B]: min RPM for cruise, low byte unused
	fcb	$10,$02                                                         ; 2072

CAL_CRUISE_MINVSSENA: ; same in all 44 cals
;   OBD1 CAL_CRUISE_MINVSSENA [B]: When speed falls below this value cruise is disabled but set point is kept / 20 mph
	fcb	$28                                                             ; 2074

CAL_CRUISE_MINSETPT: ; same in all 44 cals
;   OBD1 CAL_CRUISE_MINSETPT [B]: Minimum Speed to set cruise setpoint / 25 mph
	fcb	$32                                                             ; 2075

CAL_CRUISE_MAXVSS: ; 2 values in 44 cals, differs in: ALT (range $02-$F0)
;   OBD1 CAL_CRUISE_MAXVSS [B]: speed greater than this disables (and prevents) cruise, 120 mph
	fcb	$F0                                                             ; 2076

kw_2077: ; same in all 44 cals
	fdb	$0117

kw_2079: ; same in all 44 cals
	fdb	$FEE8

kw_cruise_setpoint_snap_207B: ; same in all 44 cals
;   analysis: snap setpoint to target when within this
	fdb	$001D

k_cruise_resume_ramp_window_207D: ; same in all 44 cals
;   analysis: $14 = 10 mph
	fcb	$14,$00,$1C                                                     ; 207D

kw_cruise_accel_ramp_step_2080: ; same in all 44 cals
;   analysis: desired-speed increment per pass while accel held ($001C)
	fdb	$001C

k_cruise_default_ramp_rate_2082: ; same in all 44 cals
;   analysis: ramp step for states other than 3/4
	fcb	$19                                                             ; 2082

k_cruise_sw_held_min_2083: ; same in all 44 cals
;   analysis: =2 ticks; min SET/RESUME press to count; passes switch must be held to count as press (2)
	fcb	$02                                                             ; 2083

k_cruise_sw_long_hold_2084: ; same in all 44 cals
;   analysis: passes held for ramp accel / coast instead of tap (20)
	fcb	$14                                                             ; 2084

kw_cruise_resume_capture_2085: ; same in all 44 cals
;   analysis: $0800 = 4 mph; resume ends (state 6) when within this of desired speed ($0800 = 4 mph)
	fdb	$0800

k_2087:	; same in all 44 cals
	fcb	$0A                                                             ; 2087

k_2088:	; same in all 44 cals
	fcb	$14                                                             ; 2088

k_2089:	; same in all 44 cals
	fcb	$00                                                             ; 2089

k_208A:	; same in all 44 cals
	fcb	$0D                                                             ; 208A

k_208B:	; same in all 44 cals
	fcb	$00                                                             ; 208B

k_208C:	; same in all 44 cals
	fcb	$1E                                                             ; 208C

k_208D:	; same in all 44 cals
	fcb	$14                                                             ; 208D

k_208E:	; same in all 44 cals
	fcb	$14                                                             ; 208E

k_cruise_resume_hold_accel_208F: ; same in all 44 cals
;   analysis: =60 ticks RESUME hold -> accel mode
	fcb	$3C                                                             ; 208F

k_2090:	; same in all 44 cals
	fcb	$00                                                             ; 2090

k_2091:	; same in all 44 cals
	fcb	$00                                                             ; 2091

CAL_VEH_SPEED3_FILT: ; same in all 44 cals
;   OBD1 CAL_VEH_SPEED3_FILT [B]
	fcb	$08                                                             ; 2092

k_cruise_switch_debounce_2093: ; same in all 44 cals
;   analysis: on/off switch debounce passes (15)
	fcb	$0F                                                             ; 2093

k_2094:	; same in all 44 cals
;   analysis: passes after resume before resume/accel counted again (60)
	fcb	$3C                                                             ; 2094

k_2095:	; same in all 44 cals
	fcb	$60                                                             ; 2095

k_cruise_igain_double_err_2096: ; same in all 44 cals
;   analysis: error below which I gain doubled; 0 = disabled
	fcb	$00                                                             ; 2096

tbl2D_CRUISE_RAMP_RATE_UP_2097: ; 2D table, same in all 44 cals
;   OBD1 CAL_CRUISE_RAMP_RATE_UP [B]
	fcb	$10
	fcb	$0E,$0F,$12,$13,$16,$18,$1A,$1C,$1D,$20,$20,$20,$20,$20,$20,$20,$20

tbl2D_CRUISE_RAMP_RATE_DN_20A9: ; 2D table, same in all 44 cals
;   OBD1 CAL_CRUISE_RAMP_RATE_DN [B]
	fcb	$10
	fcb	$21,$21,$21,$21,$1A,$13,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12

tbl2D_MAX_CRUISE_FUEL_20BB: ; 2D table, 2 values in 44 cals, differs in: EGR
;   OBD1 CAL_MAX_CRUISE_FUEL [B]: mod by Dale to use reduced power in cruise mode
	fcb	$10
	fcb	$D2,$D2,$D2,$DC,$E6,$FA,$FF,$FA,$F5,$F5,$F5,$F0,$F0,$F0,$F0,$F0,$F0

CAL_EGR_CALC_RATE: ; same in all 44 cals
;   OBD1 CAL_EGR_CALC_RATE [B]: start EGR / which loop to run at... only to try to cancel out modulation noise of solenoid...
	fcb	$04                                                             ; 20CD

CAL_EGR_MIN_PRESS_FAULT: ; 2 values in 44 cals, differs in: EGR (range $C8-$D2)
;   OBD1 CAL_EGR_MIN_PRESS_FAULT [B]: pick one of...
	fcb	$D2                                                             ; 20CE

CAL_EGR_MIN_PRESS_LOW: ; 2 values in 44 cals, differs in: EGR (range $88-$D2)
;   OBD1 CAL_EGR_MIN_PRESS_LOW [B]
	fcb	$D2                                                             ; 20CF

CAL_EGR_MIN_PRESS_DRIVING: ; 2 values in 44 cals, differs in: EGR (range $5C-$D2)
;   OBD1 CAL_EGR_MIN_PRESS_DRIVING [B]: or ... used above 19 mph
	fcb	$D2                                                             ; 20D0

CAL_EGR_MAX_PRESS: ; same in all 44 cals
;   OBD1 CAL_EGR_MAX_PRESS [A]: egr command limit = 105 kPa absolute
	fcb	$D2                                                             ; 20D1

CAL_EGR_DEADBAND: ; same in all 44 cals
;   OBD1 CAL_EGR_DEADBAND [B]: egr deadband
	fcb	$14                                                             ; 20D2

CAL_EGR_MIN_PRESS: ; same in all 44 cals
;   OBD1 CAL_EGR_MIN_PRESS [B]: egr sensor maximum
	fcb	$80                                                             ; 20D3

CAL_EGR_MIN_RPM: ; 2 values in 44 cals, differs in: NA TCM (range $1C-$FF)
;   OBD1 CAL_EGR_MIN_RPM [B]: min rpm to control egr
	fcb	$1C                                                             ; 20D4

CAL_EGR_VENT_PRESS: ; 2 values in 44 cals, differs in: EGR (range $0E-$70)
;   OBD1 CAL_EGR_VENT_PRESS [B]: max egr error for some wierd function
	fcb	$70                                                             ; 20D5

CAL_EGR_MAX_VSPEED: ; 2 values in 44 cals, differs in: EGR (range $78-$7A)
;   OBD1 CAL_EGR_MAX_VSPEED [B]: VEHICLE_SPEED_3 limit - 60 mph
	fcb	$7A                                                             ; 20D6

CAL_EGR_MIN_DRIVING_VSPD: ; 2 values in 44 cals, differs in: EGR (range $00-$1E)
;   OBD1 CAL_EGR_MIN_DRIVING_VSPD [B]: VEHICLE_SPEED_3 limit - 19 mph
	fcb	$1E                                                             ; 20D7

CAL_EGR_MAX_VSPD_DLY: ; same in all 44 cals
;   OBD1 CAL_EGR_MAX_VSPD_DLY [B]: limit
	fcb	$FF                                                             ; 20D8

CAL_EGR_BARO_DELAY: ; same in all 44 cals
;   OBD1 CAL_EGR_BARO_DELAY [B]: limit
	fcb	$20                                                             ; 20D9

k_20DA:	; 2 values in 44 cals, differs in: EGR (range $00-$73)
	fcb	$00                                                             ; 20DA

tblOfs2D_EGR_BARO_corr_20DB: ; O2 table, 2 values in 44 cals, differs in: EGR
;   OBD1 CAL_EGR_BARO_ADJ [B]
	fcb	$80,$58,$20
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00                 ; 20DE

tbl2D_EGR_INTEGRAL_GAIN_20EA: ; 2D table, 2 values in 44 cals, differs in: EGR
;   OBD1 CAL_EGR_INTEGRAL_GAIN [B]: EGR integral gain
	fcb	$10
	fcb	$07,$08,$09,$0A,$0A,$0A,$06,$06,$05,$05,$05,$05,$05,$05,$05,$05,$05

tbl2D_EGR_duty_20FC: ; 2D table, 2 values in 44 cals, differs in: EGR
;   OBD1 CAL_EGR_PROP_GAIN [B]: EGR proportional gain
	fcb	$10
	fcb	$A0,$A0,$B0,$B0,$D0,$F0,$FF,$F0,$C0,$A0,$A0,$32,$32,$32,$32,$32,$32

tbl3D_EGR_MAIN_RPM_x_Fuel_17x17_210E: ; 3D table, 2 values in 44 cals, differs in: EGR
;   OBD1 CAL_DESIRED_EGR_PRESS_TBL [B]: Desired EGR table / 0   3  6  9 12 15 18 21 24 27 30 33 36 39 42 45 48  x 100 rpm / 0  mm^3 diesel
	fcb	$FF
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF

tbl2D_ECT_17pt_2230: ; 2D table, 2 values in 44 cals, differs in: EGR
	fcb	$10
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00

tblOfs2D_EGR_fuel_thresh_BARO_2242: ; O2 table, 2 values in 44 cals, differs in: EGR NA TCM
	fcb	$80,$58,$20
	fcb	$00,$1A,$27,$46,$5A,$60,$60,$60,$60,$60,$60,$60                 ; 2245

tbl_mode_enable_bits_2251: ; same in all 44 cals
;   analysis: b0 crank, b1 idle, b2 run enable for $5A.0 feature ($19)
	fcb	$19                                                             ; 2251

CAL_CRANK_ITS_HOLD_CTS: ; same in all 44 cals
;   OBD1 CAL_CRANK_ITS_HOLD_CTS [C]: startup counter compare
	fcb	$14                                                             ; 2252

k_2253:	; same in all 44 cals
	fcb	$16                                                             ; 2253

k_2254:	; same in all 44 cals
	fcb	$0B                                                             ; 2254

CAL_REF_TO_ENERGIZE_ANGLE: ; same in all 44 cals
;   OBD1 CAL_REF_TO_ENERGIZE_ANGLE [C]: 78.75 degrees stroke reference to valve energize position	(90 degrees - 12.25 degrees)
	fdb	$0380

kw_2257: ; same in all 44 cals
	fdb	$04B6

CAL_ENG_STOPPED_RPM: ; same in all 44 cals
;   analysis: 2*18.75 rpm; RPM hi byte enabling P0606 test | OBD1 CAL_ENG_STOPPED_RPM [C]: engine RPM for run timer
	fcb	$02                                                             ; 2259

CAL_RPM_HALFRATE_CALC: ; same in all 44 cals
;   analysis: above this RPM fuel calc runs every other cam event | OBD1 CAL_RPM_HALFRATE_CALC [C]: above 2400 RPM, cut fuel calculations run in half for processor performance.
	fcb	$80                                                             ; 225A

CAL_TIMING_ITS_DEADBAND: ; same in all 44 cals
;   analysis: 3 (dead routine 98AC) | OBD1 CAL_TIMING_ITS_DEADBAND [B]: timing error deadband +/- .3 degrees, error to command ITS movement
	fcb	$03,$00                                                         ; 225B

CAL_ITS_POS_RESET_ERR: ; same in all 44 cals
;   OBD1 CAL_ITS_POS_RESET_ERR [B]: timing, if error between its counter and measured inj timing is greater than 3 degrees, just grab timing as its count
	fcb	$1E                                                             ; 225D

CAL_ITS_POS_RESET_TM: ; same in all 44 cals
;   OBD1 CAL_ITS_POS_RESET_TM [B]: time lag for ITS reset
	fcb	$03                                                             ; 225E

CAL_TIMING_ADDERS_OFFSET: ; same in all 44 cals
;   analysis: subtracted from the summed timing adders | OBD1 CAL_TIMING_ADDERS_OFFSET [C]
	fcb	$00                                                             ; 225F

kw_timing_final_offset_2260: ; same in all 44 cals
;   analysis: signed offset added to final desired timing
	fdb	$0000

k_timing_override_2262: ; same in all 44 cals
;   analysis: nonzero = fixed desired timing (overrides map)
	fcb	$00                                                             ; 2262

kw_timing_max_offset_2263: ; same in all 44 cals
;   analysis: signed offset added to max-timing-vs-RPM table
	fdb	$0000

k_timing_max_table_disable_2265: ; same in all 44 cals
;   analysis: nonzero = ignore table 2887, max = kw_2263 only
	fcb	$00                                                             ; 2265

CAL_REF_TO_SOI_1: ; same in all 44 cals
;   OBD1 CAL_REF_TO_SOI_1 [B]: 22.2 degrees, reference to SOI timing. This is valid only at idle speed; pumping is earlier at higher engine speeds.
	fdb	$00DE

CAL_REF_TO_SOI_OFFSET_TO_ITS: ; same in all 44 cals
;   OBD1 CAL_REF_TO_SOI_OFFSET_TO_ITS [C]
	fcb	$00                                                             ; 2268

kw_fuel_offset_2269: ; same in all 44 cals
;   analysis: signed fuel offset (0 in this cal)
	fdb	$0000

k_226B:	; same in all 44 cals
	fcb	$00,$00                                                         ; 226B

k_fuel_offset_max_RPM_226D: ; same in all 44 cals
;   analysis: $D4 = 3975 rpm; kw_2269 fuel offset applied below
	fcb	$D4                                                             ; 226D

k_crank_mode_RPM_226E: ; 2 values in 44 cals, differs in: NA TCM (range $05-$10)
;   analysis: $10 = 300 rpm; below this ENGMODEFLAG = crank
	fcb	$10                                                             ; 226E

k_idle_mid_band_offset_226F: ; same in all 44 cals
;   analysis: added to idle target for IDLE_SPEED_MID_BAND
	fcb	$0E                                                             ; 226F

k_idle_high_band_offset_2270: ; same in all 44 cals
;   analysis: added to idle target for IDLE_SPEED_HIGH_BAND
	fcb	$14                                                             ; 2270

kw_governor_RPM_start: ; 3 values in 44 cals, differs in: ALT TCM (range $95A2-$C01C)
	fdb	$B655

kw_governor_RPM_cutoff: ; 3 values in 44 cals, differs in: ALT TCM (range $9D6D-$D01E)
	fdb	$C655

kw_governor_RPM_start_cold: ; 2 values in 44 cals, differs in: ALT (range $95A2-$A018)
	fdb	$A018

kw_governor_RPM_cutoff_cold: ; 2 values in 44 cals, differs in: ALT (range $9D6D-$B01A)
	fdb	$B01A

k_governor_cold_ECT: ; same in all 44 cals
	fcb	$30                                                             ; 2279

k_governor_warm_ECT: ; same in all 44 cals
	fcb	$32                                                             ; 227A

kw_governor_start_hiVSS: ; 3 values in 44 cals, differs in: ALT TA TCM (range $0000-$B655)
	fdb	$0000

kw_governor_cutoff_hiVSS: ; 4 values in 44 cals, differs in: ALT TA TCM (range $0000-$C655)
	fdb	$0000

k_227F:	; 3 values in 44 cals, differs in: ALT TA TCM (range $00-$32)
	fcb	$00                                                             ; 227F

kw_governor_start_lowVSS: ; 3 values in 44 cals, differs in: ALT TA TCM (range $0000-$B655)
	fdb	$0000

kw_governor_cutoff_lowVSS: ; 4 values in 44 cals, differs in: ALT TA TCM (range $0000-$C655)
	fdb	$0000

k_2284:	; 3 values in 44 cals, differs in: ALT TA TCM (range $00-$3C)
	fcb	$00                                                             ; 2284

kw_speed_limiter_VSS_start: ; 7 values in 44 cals, differs in: ALT NA TA TCM (range $6C00-$C000)
;   OBD1 CAL_GOV_MAX_VSS_FULLTQ [A]: max vehicle speed limiter
	fdb	$C000

kw_speed_limiter_VSS_cutoff: ; 7 values in 44 cals, differs in: ALT NA TA TCM (range $7000-$C400)
;   OBD1 CAL_GOV_MAX_VSS_NOTQ [A]
	fdb	$C400

CAL_CYLBAL_MAX_RPM: ; same in all 44 cals
;   OBD1 CAL_CYLBAL_MAX_RPM [B]: rpm limit
	fcb	$2B                                                             ; 2289

CAL_SOL_RSP_RPM_SPLIT: ; same in all 44 cals
;   OBD1 CAL_SOL_RSP_RPM_SPLIT [C]
	fcb	$18                                                             ; 228A

CAL_CYLBAL_MIN_ECTS: ; same in all 44 cals
;   OBD1 CAL_CYLBAL_MIN_ECTS [B]: ect limit
	fcb	$43                                                             ; 228B

CAL_SAFETY_OVERREV_RPM: ; same in all 44 cals
;   OBD1 CAL_SAFETY_OVERREV_RPM [A]: rpm limit
	fcb	$E7                                                             ; 228C

CAL_SAFETY_OVERREV_RPM_HYST: ; same in all 44 cals
;   OBD1 CAL_SAFETY_OVERREV_RPM_HYST [B]: deadband
	fcb	$08                                                             ; 228D

CAL_MIN_GOVERNED_FUEL: ; same in all 44 cals
;   OBD1 CAL_MIN_GOVERNED_FUEL [B]: Looks like minimum cranking fuel
	fcb	$02                                                             ; 228E

CAL_CRANK_APP_MAX_ADDER: ; same in all 44 cals
;   OBD1 CAL_CRANK_APP_MAX_ADDER [A]: part of pump cal adjustment or something like it...
	fcb	$39                                                             ; 228F

CAL_SOL_RSP_DFLT_RUN: ; same in all 44 cals
;   analysis: fault closure time above CAL_SOL_RSP_RPM_SPLIT | OBD1 CAL_SOL_RSP_DFLT_RUN [C]
	fdb	$0143

CAL_SOL_RSP_DFLT_CRANK: ; same in all 44 cals
;   analysis: fault closure time below split | OBD1 CAL_SOL_RSP_DFLT_CRANK [C]
	fdb	$075B

CAL_PUMP_REF_TO_SOI_2: ; same in all 44 cals
;   OBD1 CAL_PUMP_REF_TO_SOI_2 [B]: 1 5.38 degrees = ref to soi ?
	fdb	$00AF

CAL_PUMP_MEAS_INJTMG_FILT: ; same in all 44 cals
;   OBD1 CAL_PUMP_MEAS_INJTMG_FILT [B]: meas inj tmg filter
	fcb	$20                                                             ; 2296

CAL_SEM_SLIP_FILT: ; same in all 44 cals
;   analysis: lag coef for FILT_TQCVT_SLIP ($80) | OBD1 CAL_SEM_SLIP_FILT [B]: torque converter slip filter ??? for engine power limiter
	fcb	$80,$B0,$01,$A0,$00,$00,$00                                     ; 2297

k_229E:	; same in all 44 cals
;   analysis: RPM hi-byte threshold for $5B.1
	fcb	$36                                                             ; 229E

k_brake_debounce_ticks_229F: ; same in all 44 cals
;   analysis: $28 = 40 x 12.5 ms
	fcb	$28                                                             ; 229F

k_22A0:	; 2 values in 44 cals, differs in: NA TCM (range $08-$24)
;   analysis: PW ramp step divisor ($24)
	fcb	$24                                                             ; 22A0

k_22A1:	; 2 values in 44 cals, differs in: NA TCM (range $08-$20)
;   analysis: alternate divisor ($20) when $1BAF <= k_22A5
	fcb	$20                                                             ; 22A1

kw_fuel_deliv_360_min_22A2: ; same in all 44 cals
;   analysis: $00B5 PW floor for ramp computation; x16 = minimum 360-deg delivery, else zeroed (OBD1: 15.9 deg)
	fdb	$00B5

k_fuel_rampdown_max_fuel_22A4: ; same in all 44 cals
;   analysis: $40 = 20 mm3; PW ramp-down only below this
	fcb	$40                                                             ; 22A4

k_22A5:	; 2 values in 44 cals, differs in: ALT NA TCM (range $26-$FF)
	fcb	$26                                                             ; 22A5

k_fuel_max_crank_22A6: ; same in all 44 cals
;   analysis: $FF max fuel in crank
	fcb	$FF,$00                                                         ; 22A6

CAL_MIN_CRANK_CYLS: ; same in all 44 cals
;   OBD1 CAL_MIN_CRANK_CYLS [A]: cylinders to enable normal control
	fcb	$03                                                             ; 22A8

k_22A9:	; same in all 44 cals
;   analysis: 5 = 94 rpm (dead routine 9842)
	fcb	$05                                                             ; 22A9

k_22AA:	; same in all 44 cals
;   analysis: timing delta from ITS_Cold_Base to latch ITS position
	fcb	$04                                                             ; 22AA

k_22AB:	; same in all 44 cals
	fcb	$03                                                             ; 22AB

k_ITS_crank_settle_ticks_22AC: ; same in all 44 cals
;   analysis: 12.5 ms ticks ITS must sit on crank target ($30 = 0.6 s)
	fcb	$30                                                             ; 22AC

CAL_ITS_RESET_INIT_LIMIT: ; same in all 44 cals
;   OBD1 CAL_ITS_RESET_INIT_LIMIT [B]: in the case of reset of ecm, if its is below this, reset its to crank position
	fcb	$FE                                                             ; 22AD

CAL_MINIDLE_IN_BACKUP: ; same in all 44 cals
;   OBD1 CAL_MINIDLE_IN_BACKUP [C]
	fcb	$28                                                             ; 22AE

CAL_ITS_IN_BACKUP: ; same in all 44 cals
;   OBD1 CAL_ITS_IN_BACKUP [B]: retract in case of pw backup mode - pull its to fixed position so tdc offset can determine pump position
	fcb	$70                                                             ; 22AF

k_APPflt_VSS_band1_22B0: ; same in all 44 cals
;   analysis: VSS threshold for APP-fault fuel limit accel band
	fcb	$14                                                             ; 22B0

k_APPflt_VSS_band2_22B1: ; same in all 44 cals
;   analysis: second VSS threshold
	fcb	$3C                                                             ; 22B1

kw_22B2: ; same in all 44 cals
	fdb	$000E

kw_22B4: ; same in all 44 cals
	fdb	$001C

kw_22B6: ; same in all 44 cals
	fdb	$0038

k_APPflt_fuel_step_22B8: ; same in all 44 cals
;   analysis: fuel step (mm3*0.3125) for limit ramp
	fcb	$01                                                             ; 22B8

k_APPflt_fuel_min_low_speed_22B9: ; same in all 44 cals
;   analysis: minimum limit in lowest speed band
	fcb	$50                                                             ; 22B9

CAL_PUMP_SLOPE: ; same in all 44 cals
;   OBD1 CAL_PUMP_SLOPE [C]: rough degree to mm^3 conversion
	fcb	$40                                                             ; 22BA

CAL_PUMP_MAX_EOI: ; same in all 44 cals
;   OBD1 CAL_PUMP_MAX_EOI [B]: try to be finished fuelling by this time after soi
	fdb	$015E
	fcb	$FF                                                             ; 22BD

k_timing_filter_coef_22BE: ; same in all 44 cals
;   analysis: lag filter coefficient for injection_timing_desired
	fcb	$20                                                             ; 22BE

k_22BF:	; same in all 44 cals
	fcb	$40                                                             ; 22BF

k_22C0:	; same in all 44 cals
	fcb	$30,$00,$00                                                     ; 22C0

kw_22C3: ; same in all 44 cals
;   analysis: split injection gap; 0 disables split
	fdb	$0000

kw_22C5: ; same in all 44 cals
;   analysis: pilot quantity counter
	fdb	$0000

k_RPM_5_filter_coef_22C7: ; 2 values in 44 cals, differs in: NA TCM
;   analysis: lag filter coefficient for RPM_5 ($B0)
	fcb	$B0,$40,$30,$0A,$AB,$FF,$FE                                     ; 22C7

kw_22CE: ; same in all 44 cals
	fdb	$0000

CAL_FUEL_LIM_EGR_MAP: ; 2 values in 44 cals, differs in: EGR (range $00-$B4)
;   OBD1 CAL_FUEL_LIM_EGR_MAP [B]
	fcb	$00                                                             ; 22D0

CAL_FUEL_LIM_EGR_STEP: ; 2 values in 44 cals, differs in: EGR (range $00-$40)
;   OBD1 CAL_FUEL_LIM_EGR_STEP [B]
	fcb	$00                                                             ; 22D1

CAL_FUEL_LIM_EGR_FAST_SLEW: ; 2 values in 44 cals, differs in: EGR (range $00-$04)
;   OBD1 CAL_FUEL_LIM_EGR_FAST_SLEW [B]
	fcb	$00                                                             ; 22D2

CAL_FUEL_LIM_SLOW_SLEW: ; 2 values in 44 cals, differs in: EGR (range $01-$02)
;   OBD1 CAL_FUEL_LIM_SLOW_SLEW [A]
	fcb	$01                                                             ; 22D3

CAL_FUEL_LIM_NOEGR_DELAY: ; 2 values in 44 cals, differs in: EGR
;   OBD1 CAL_FUEL_LIM_NOEGR_DELAY [B]
	fcb	$00,$00,$00                                                     ; 22D4

k_deltafuel_lim_max_RPM_22D7: ; same in all 44 cals
;   analysis: $40 = 1200 rpm
	fcb	$40                                                             ; 22D7

k_22D8:	; same in all 44 cals
;   analysis: startup ECT above -> FLAGS2.1
	fcb	$70                                                             ; 22D8

k_22D9:	; same in all 44 cals
	fcb	$00,$60                                                         ; 22D9

k_22DB:	; same in all 44 cals
	fcb	$68                                                             ; 22DB

k_22DC:	; 3 values in 44 cals, differs in: ALT EGR NA TA TCM (range $40-$80)
;   analysis: scales limit when stationary/neutral
	fcb	$60                                                             ; 22DC

tbl2D_ECT_17pt_22DD: ; 2D table, 2 values in 44 cals, differs in: NA TCM
	fcb	$10
	fcb	$DC,$DC,$DC,$CD,$C2,$A4,$A4,$A4,$A4,$A4,$A4,$A4,$A4,$A4,$A4,$A4,$A4

tbl2D_ECT_9pt_22EF: ; 2D table, same in all 44 cals
	fcb	$08
	fcb	$08,$08,$06,$05,$05,$05,$06,$08,$08

tbl2D_idle_learn_rate_22F9: ; 2D table, same in all 44 cals
;   OBD1 CAL_ENGINE_DRAGFUEL [B]: Engine drag torque fuel - 15 mm3
	fcb	$08
	fcb	$30,$30,$30,$30,$30,$30,$30,$30,$30

tbl2D_idle_fuel_adder_2303: ; 2D table, same in all 44 cals
;   OBD1 CAL_IDLE_ROUGH_ADDER [B]: Idle fuel adder vs. engine roughness / idle speed drop
	fcb	$08
	fcb	$00,$00,$00,$00,$00,$00,$08,$1E,$27
	fcb	$00,$30                                                         ; 230D

CAL_DRAG_ADAPT_MINRUNTM: ; same in all 44 cals
;   OBD1 CAL_DRAG_ADAPT_MINRUNTM [B]: engine run time
	fdb	$0190

CAL_START_ROUGHNESS_FILT: ; same in all 44 cals
;   OBD1 CAL_START_ROUGHNESS_FILT [B]
	fcb	$80                                                             ; 2311

CAL_DRAG_ADAPT_MAXRPMERR: ; same in all 44 cals
;   OBD1 CAL_DRAG_ADAPT_MAXRPMERR [A]
	fcb	$01                                                             ; 2312

CAL_DRAG_ADAPT_FILTER: ; same in all 44 cals
;   OBD1 CAL_DRAG_ADAPT_FILTER [B]
	fcb	$40                                                             ; 2313

CAL_DRAG_ADAPT_RATE: ; same in all 44 cals
;   OBD1 CAL_DRAG_ADAPT_RATE [B]
	fcb	$78                                                             ; 2314

CAL_DRAG_ADAPT_MAX_ADJ: ; same in all 44 cals
;   OBD1 CAL_DRAG_ADAPT_MAX_ADJ [A]
	fcb	$10                                                             ; 2315

CAL_DRAG_ADAPT_MIN_ADJ: ; same in all 44 cals
;   OBD1 CAL_DRAG_ADAPT_MIN_ADJ [A]
	fcb	$01                                                             ; 2316

k_2317:	; same in all 44 cals
	fcb	$25                                                             ; 2317

tbl_2318: ; 2 values in 44 cals, differs in: EGR
	fcb	$7F,$41,$41,$41,$41,$41,$43,$45,$4A,$4D,$54,$5A,$C8,$FF,$FF,$FF ; 2318
	fcb	$FF,$FF,$82,$82,$82,$82,$82,$86,$8A,$93,$9B,$A8,$B4,$DC,$FF,$FF ; 2328
	fcb	$FF,$FF,$FF,$98,$99,$9A,$9B,$9C,$A0,$A3,$AE,$B9,$C3,$FF,$FF,$FF ; 2338
	fcb	$FF,$FF,$FF,$FF,$AA,$AC,$AF,$AF,$B0,$B6,$BC,$CF,$E1,$FF,$FF,$FF ; 2348
	fcb	$FF,$FF,$FF,$FF,$FF,$BE,$C0,$C3,$C5,$C6,$CB,$D0,$E3,$FF,$FF,$FF ; 2358
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$D7,$D8,$DA,$DB,$DC,$E8,$F4,$FF,$FF,$FF ; 2368
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$EC,$EE,$F0,$F2,$F4,$FF,$FF,$FF,$FF ; 2378
; 42 bytes $FF
	org	$23B2

tbl_23B2: ; 2 values in 44 cals, differs in: EGR
	fcb	$7F,$37,$37,$37,$37,$37,$39,$3B,$3F,$43,$4A,$50,$BE,$FF,$FF,$FF ; 23B2
	fcb	$FF,$FF,$6E,$6E,$6E,$6E,$6E,$72,$76,$7F,$87,$94,$A0,$C8,$FF,$FF ; 23C2
	fcb	$FF,$FF,$FF,$84,$85,$86,$87,$88,$8C,$8F,$9A,$A5,$AF,$FF,$FF,$FF ; 23D2
	fcb	$FF,$FF,$FF,$FF,$96,$98,$9B,$9B,$9C,$A2,$A8,$BB,$CD,$FF,$FF,$FF ; 23E2
	fcb	$C6,$FF,$FF,$FF,$FF,$AA,$AC,$AF,$B1,$B2,$B7,$BC,$CF,$FF,$FF,$FF ; 23F2
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$C3,$C4,$C6,$C7,$C8,$D4,$E0,$FF,$FF,$FF ; 2402
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$D8,$DA,$DC,$DE,$E0,$FA,$FF,$FF,$FF ; 2412
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$EC,$EE,$F0,$FF,$FF,$FF,$FF,$FF ; 2422
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF ; 2432
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF                         ; 2442

tbl_244C: ; 2 values in 44 cals, differs in: EGR
	fcb	$7F,$2D,$2D,$2D,$2D,$2D,$2F,$36,$35,$39,$40,$46,$64,$FF,$FF,$FF ; 244C
	fcb	$FF,$FF,$5A,$5A,$5A,$5A,$5A,$5E,$62,$6B,$73,$80,$8C,$B4,$FF,$FF ; 245C
	fcb	$FF,$FF,$FF,$70,$71,$72,$73,$74,$78,$7B,$86,$91,$9B,$FF,$FF,$FF ; 246C
	fcb	$FF,$FF,$FF,$FF,$82,$84,$87,$87,$88,$8E,$94,$A7,$B9,$FF,$FF,$FF ; 247C
	fcb	$FF,$FF,$FF,$FF,$96,$98,$9B,$9D,$9E,$A3,$A8,$BB,$FF,$FF,$FF,$FF ; 248C
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$AF,$B0,$B2,$B3,$B4,$C0,$CC,$FF,$FF,$FF ; 249C
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$C4,$C6,$C8,$CA,$CC,$E6,$FF,$FF,$FF ; 24AC
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$D8,$DA,$DC,$DE,$E0,$EC,$FF,$FF ; 24BC
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$EC,$EE,$F0,$F2,$F4,$FF,$FF ; 24CC
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF                         ; 24DC

tbl_24E6: ; 2 values in 44 cals, differs in: EGR
	fcb	$7F,$23,$23,$23,$23,$23,$25,$27,$2B,$2F,$36,$3C,$B4,$FF,$FF,$FF ; 24E6
	fcb	$FF,$FF,$46,$46,$46,$46,$46,$4A,$4E,$57,$5F,$6C,$78,$A0,$FF,$FF ; 24F6
	fcb	$FF,$FF,$FF,$5C,$5D,$5E,$5F,$60,$64,$67,$72,$7D,$87,$FF,$FF,$FF ; 2506
	fcb	$FF,$FF,$FF,$FF,$6E,$70,$73,$73,$74,$7A,$80,$93,$AF,$FF,$FF,$FF ; 2516
	fcb	$FF,$FF,$FF,$FF,$FF,$82,$84,$87,$89,$8A,$8F,$94,$A7,$FF,$FF,$FF ; 2526
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$9B,$9C,$9E,$9F,$A0,$AC,$B8,$FF,$FF,$FF ; 2536
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$B0,$B2,$B4,$B6,$B8,$D2,$FF,$FF,$FF ; 2546
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$C4,$C6,$C8,$CA,$CC,$E6,$FF,$FF ; 2556
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$D8,$DA,$DC,$DE,$E0,$FA,$FF ; 2566
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF                         ; 2576

tbl_2580: ; 2 values in 44 cals, differs in: EGR
	fcb	$7F,$18,$18,$18,$14,$14,$1A,$1B,$1F,$26,$2A,$37,$4B,$FF,$FF,$FF ; 2580
	fcb	$FF,$FF,$32,$31,$30,$32,$33,$35,$37,$3E,$4B,$55,$6E,$96,$FF,$FF ; 2590
	fcb	$FF,$FF,$FF,$49,$46,$46,$47,$49,$4C,$53,$5A,$69,$87,$FF,$FF,$FF ; 25A0
	fcb	$FF,$FF,$FF,$FF,$6E,$69,$64,$61,$5F,$64,$69,$76,$82,$FF,$FF,$FF ; 25B0
	fcb	$FF,$FF,$FF,$FF,$FF,$7D,$78,$73,$74,$75,$79,$7C,$A7,$D7,$FF,$FF ; 25C0
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$8C,$87,$82,$84,$85,$8D,$94,$FF,$FF,$FF ; 25D0
	fcb	$FF,$FF,$FF,$FF,$A0,$9B,$96,$A0,$AA,$C8,$FF,$FF,$FF,$FF,$FF,$FF ; 25E0
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$B4,$AF,$AA,$B4,$C8,$DC,$FF,$FF ; 25F0
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$C8,$C3,$BE,$C8,$D1,$F0,$F1 ; 2600
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF                         ; 2610

tbl_261A: ; 2 values in 44 cals, differs in: EGR
	fcb	$7F,$18,$18,$18,$14,$14,$1A,$1B,$1F,$26,$2A,$37,$4B,$FF,$FF,$FF ; 261A
	fcb	$FF,$FF,$32,$31,$30,$32,$33,$35,$37,$3E,$4B,$55,$6E,$96,$FF,$FF ; 262A
	fcb	$FF,$FF,$FF,$49,$46,$46,$47,$49,$4C,$53,$5A,$69,$87,$FF,$FF,$FF ; 263A
	fcb	$FF,$FF,$FF,$FF,$6E,$69,$64,$61,$5F,$64,$69,$76,$82,$FF,$FF,$FF ; 264A
	fcb	$FF,$FF,$FF,$FF,$FF,$7D,$78,$73,$74,$75,$79,$7C,$A7,$D7,$FF,$FF ; 265A
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$8C,$87,$82,$84,$85,$8D,$94,$FF,$FF,$FF ; 266A
	fcb	$FF,$FF,$FF,$FF,$A0,$9B,$96,$A0,$AA,$C8,$FF,$FF,$FF,$FF,$FF,$FF ; 267A
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$B4,$AF,$AA,$B4,$C8,$DC,$FF,$FF ; 268A
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$C8,$C3,$BE,$C8,$D1,$F0,$F1 ; 269A
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF                         ; 26AA

tbl_26B4: ; 2 values in 44 cals, differs in: EGR
	fcb	$7F,$18,$18,$18,$14,$14,$1A,$1B,$1F,$26,$2A,$37,$4B,$FF,$FF,$FF ; 26B4
	fcb	$FF,$FF,$32,$31,$30,$32,$33,$35,$37,$3E,$4B,$55,$6E,$96,$FF,$FF ; 26C4
	fcb	$FF,$FF,$FF,$49,$46,$46,$47,$49,$4C,$53,$5A,$69,$87,$FF,$FF,$FF ; 26D4
	fcb	$FF,$FF,$FF,$FF,$6E,$69,$64,$61,$5F,$64,$69,$76,$82,$FF,$FF,$FF ; 26E4
	fcb	$FF,$FF,$FF,$FF,$FF,$7D,$78,$73,$74,$75,$79,$7C,$A7,$D7,$FF,$FF ; 26F4
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$8C,$87,$82,$84,$85,$8D,$94,$FF,$FF,$FF ; 2704
	fcb	$FF,$FF,$FF,$FF,$A0,$9B,$96,$A0,$AA,$C8,$FF,$FF,$FF,$FF,$FF,$FF ; 2714
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$B4,$AF,$AA,$B4,$C8,$DC,$FF,$FF ; 2724
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$C8,$C3,$BE,$C8,$D1,$F0,$F1 ; 2734
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF                         ; 2744

k_274E:	; same in all 44 cals
	fcb	$03                                                             ; 274E

k_274F:	; same in all 44 cals
	fcb	$20                                                             ; 274F

k_2750:	; same in all 44 cals
	fcb	$05                                                             ; 2750

k_2751:	; same in all 44 cals
	fcb	$3C                                                             ; 2751

k_2752:	; same in all 44 cals
	fcb	$28                                                             ; 2752

k_zero_fuel_rise_min_RPM_2753: ; same in all 44 cals
;   analysis: byte (not word): RPM byte $50 = 1500 rpm
	fcb	$50                                                             ; 2753

k_2754:	; same in all 44 cals
	fcb	$0A                                                             ; 2754

k_2755:	; same in all 44 cals
	fcb	$10                                                             ; 2755

k_2756:	; same in all 44 cals
	fcb	$04                                                             ; 2756

kw_2757: ; same in all 44 cals
;   analysis: RPM increase per 50ms counted as a jump ($0050)
	fdb	$0050

kw_2759: ; same in all 44 cals
	fdb	$0064

tbl2D_CRANK_INJ_TIMING_TBL_275B: ; 2D table, 3 values in 44 cals, differs in: ALT NA TCM
;   OBD1 CAL_CRANK_INJ_TIMING_TBL [A]: ECTS -> basic injection timing (cranking???)
	fcb	$10
	fcb	$C8,$C8,$C8,$C8,$AA,$AA,$A5,$A5,$A5,$A5,$A0,$A0,$A0,$A0,$A0,$A0,$A0

kw_cold_start_timing_time_276D: ; 2 values in 44 cals, differs in: EGR (range $0032-$07D0)
;   analysis: run time limit (0.1 s)
	fdb	$0032

k_cold_start_timing_decay_rate_276F: ; 2 values in 44 cals, differs in: EGR (range $01-$22)
;   analysis: passes per decrement
	fcb	$01                                                             ; 276F

k_cold_start_timing_init_2770: ; 2 values in 44 cals, differs in: EGR (range $32-$3C)
;   analysis: initial 19CC
	fcb	$32                                                             ; 2770

k_2771:	; 2 values in 44 cals, differs in: EGR (range $70-$82)
;   analysis: 19CD adder only below this, result clamped to it
	fcb	$82                                                             ; 2771

k_2772:	; same in all 44 cals
	fcb	$10                                                             ; 2772

k_2773:	; same in all 44 cals
	fcb	$50                                                             ; 2773

k_2774:	; same in all 44 cals
	fcb	$64                                                             ; 2774

k_2775:	; same in all 44 cals
	fcb	$78                                                             ; 2775

k_2776:	; 2 values in 44 cals, differs in: EGR (range $80-$FF)
;   analysis: $FF disables 19D3 ramp in this cal
	fcb	$FF                                                             ; 2776

k_2777:	; same in all 44 cals
	fcb	$50                                                             ; 2777

k_2778:	; same in all 44 cals
	fcb	$90                                                             ; 2778

k_2779:	; 2 values in 44 cals, differs in: EGR (range $1E-$28)
;   analysis: max 19D3
	fcb	$28                                                             ; 2779

k_277A:	; same in all 44 cals
	fcb	$28                                                             ; 277A

k_277B:	; same in all 44 cals
	fcb	$1C                                                             ; 277B

k_277C:	; same in all 44 cals
	fcb	$ED                                                             ; 277C

tblOfs2D_fuel_limit_slip_ratio_277D: ; O2 table, 2 values in 44 cals, differs in: TA
	fcb	$00,$80,$10
	fcb	$21,$1B,$16,$10,$0B,$05,$00,$00,$00                             ; 2780

tbl3D_fuel_limit_hotECT_x_RPM_9x9_2789: ; 3D table, 6 values in 44 cals, differs in: ALT EGR NA TA TCM
	fcb	$77
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$2B,$56,$66,$70,$76
	fcb	$00,$00,$00,$00,$2B,$56,$66,$70,$76
	fcb	$00,$00,$00,$00,$3C,$40,$45,$4A,$4D
	fcb	$00,$00,$00,$00,$60,$60,$60,$60,$60
	fcb	$00,$00,$00,$00,$60,$60,$60,$60,$60
	fcb	$00,$00,$00,$00,$60,$60,$60,$60,$60

tbl3D_TIMING_ECT_x_RPM_9x17_27DB: ; 3D table, 7 values in 44 cals, differs in: ALT EGR NA TA TCM
	fcb	$7F
	fcb	$60,$60,$4C,$45,$3E,$32,$28,$1E,$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$60,$60,$4C,$45,$3E,$32,$28,$1E,$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$42,$42,$38,$33,$2E,$28,$1E,$14,$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$24,$24,$1E,$1E,$1E,$1E,$14,$0A,$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$14,$14,$0A,$0A,$0A,$00,$00,$00,$00,$00,$00,$00,$00,$1E,$1E,$1E,$1E
	fcb	$28,$28,$1E,$1E,$1E,$14,$14,$00,$00,$00,$00,$00,$00,$32,$32,$32,$32
	fcb	$1E,$1E,$14,$14,$14,$0A,$0A,$00,$00,$00,$00,$00,$00,$28,$28,$28,$28
	fcb	$1E,$1E,$14,$14,$14,$0A,$0A,$00,$00,$00,$00,$00,$00,$28,$28,$28,$28
	fcb	$1E,$1E,$14,$14,$14,$0A,$0A,$00,$00,$00,$00,$00,$00,$28,$28,$28,$28

tbl2D_TIMING_ECT_adder_2875: ; 2D table, same in all 44 cals
	fcb	$10
	fcb	$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$00,$00,$00,$00,$00,$00,$00

tbl2D_TIMING_max_vs_RPM_2887: ; 2D table, 5 values in 44 cals, differs in: ALT EGR NA TA TCM
	fcb	$10
	fcb	$A2,$A2,$A2,$AF,$AA,$B4,$BE,$C8,$CD,$D2,$D7,$D7,$D7,$D7,$D7,$D7,$D7

tbl3D_timing_min_RPM_x_BARO_9x9_2899: ; 3D table, 9 values in 44 cals, differs in: ALT EGR NA TA TCM
	fcb	$77
	fcb	$63,$6E,$6E,$84,$98,$BE,$C8,$CD,$CD
	fcb	$63,$6E,$6E,$84,$98,$BE,$C8,$CD,$CD
	fcb	$63,$6E,$6E,$84,$98,$B9,$C3,$C8,$C8
	fcb	$63,$64,$6E,$84,$98,$B4,$BE,$C3,$C3
	fcb	$63,$5A,$6E,$84,$98,$AF,$B9,$BE,$BE
	fcb	$63,$46,$50,$84,$98,$87,$A0,$AA,$B4
	fcb	$63,$48,$46,$84,$93,$84,$9D,$A7,$B1
	fcb	$63,$48,$46,$84,$93,$84,$9D,$A7,$B1
	fcb	$63,$48,$46,$84,$93,$84,$9D,$A7,$B1

tbl3D_TIMING_adder_RPM_x_Boost_9x9_28EB: ; 3D table, 6 values in 44 cals, differs in: ALT EGR NA TA TCM
	fcb	$77
	fcb	$3C,$3C,$32,$28,$28,$28,$28,$28,$32
	fcb	$32,$32,$28,$1E,$1E,$1E,$1E,$1E,$28
	fcb	$28,$28,$1E,$14,$14,$14,$14,$14,$1E
	fcb	$1E,$1E,$14,$0A,$0A,$0A,$0A,$0A,$14
	fcb	$0A,$0A,$0A,$00,$00,$00,$00,$00,$0A
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00

tbl3D_timing_adder_RPM_x_Fuel_5x9_293D: ; 3D table, 2 values in 44 cals, differs in: EGR
	fcb	$37
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00

Table_all_0: ; 3D table, same in all 44 cals
	fcb	$7F
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$05,$05,$05,$05,$03,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$0B,$0B,$0B,$0B,$0B,$0D,$0B,$0B,$0B,$0B,$0B,$0B,$0B,$0B,$00,$00,$00
	fcb	$0E,$0E,$0E,$0E,$12,$13,$10,$10,$10,$10,$10,$10,$10,$10,$00,$00,$00
	fcb	$0E,$0E,$0E,$0E,$12,$13,$10,$10,$10,$10,$10,$10,$10,$10,$00,$00,$00

CAL_FUEL_RES_CAL: ; same in all 44 cals
;   analysis: 8 ascending thresholds for battery-normalized pump cal resistor -> band 0..8 | OBD1 CAL_FUEL_RES_CAL [A]: Fuel resistor limits to select pump calibration table / used for 454b... selection
	fcb	$16,$1E,$2A,$3F,$55,$6B,$86,$B2                                 ; 2A05

Fuel_demand_map_0: ; 2D table, 2 values in 44 cals, differs in: EGR
;   OBD1 CAL_CRUISE_MTHR_TBL1 [B]: If CRS <= 2: / SIM_TPS = APP_COND  # Pass on normal accelerator pedal position / ELSE: / IF IDLE_MODE && (IFR > AFR) && (IFR > CFRND): / SIM_TPS = 0 / D = TBL3 + (TBL4-TBL3) * (CRUISE_FU...
	fcb	$10
	fcb	$62,$58,$60,$80,$7F,$7A,$74,$6F,$6B,$67,$74,$6F,$6A,$69,$69,$69,$69

Fuel_demand_map_1: ; 2D table, 2 values in 44 cals, differs in: EGR
;   OBD1 CAL_CRUISE_MTHR_TBL2 [B]
	fcb	$10
	fcb	$90,$7A,$64,$8D,$AB,$AF,$B7,$B1,$AB,$A7,$AB,$A6,$A3,$A2,$A2,$A2,$A2

Fuel_demand_map_2: ; 2D table, same in all 44 cals
;   OBD1 CAL_CRUISE_MTHR_TBL3 [A]
	fcb	$10
	fcb	$20,$20,$30,$40,$40,$40,$40,$40,$40,$40,$50,$50,$50,$50,$50,$50,$50

Fuel_demand_map_3: ; 2D table, same in all 44 cals
;   OBD1 CAL_CRUISE_MTHR_TBL4 [A]
	fcb	$10
	fcb	$50,$50,$50,$50,$70,$70,$80,$80,$80,$80,$90,$90,$90,$90,$90,$90,$90

tbl2D_PUMP_LOW_FUEL_2A55: ; 2D table, same in all 44 cals
;   OBD1 CAL_PUMP_LOW_FUEL [B]
	fcb	$08
	fcb	$64,$6E,$78,$82,$8C,$96,$A0,$AA,$B4

tbl2D_PUMP_HIGH_FUEL_2A5F: ; 2D table, same in all 44 cals
;   OBD1 CAL_PUMP_HIGH_FUEL [B]
	fcb	$08
	fcb	$B4,$B9,$BE,$C3,$C8,$CD,$D2,$D7,$DC

tbl_2A69: ; same in all 44 cals
	fcb	$11,$00,$00,$00,$00,$00,$00,$00,$00,$00                         ; 2A69

tbl_2A73: ; same in all 44 cals
	fcb	$11,$05,$04,$04,$03,$03,$03,$02,$02,$03                         ; 2A73

tbl_2A7D: ; same in all 44 cals
	fcb	$11,$0A,$08,$08,$06,$06,$06,$04,$04,$06                         ; 2A7D

tbl_2A87: ; same in all 44 cals
	fcb	$11,$0F,$0C,$0C,$09,$09,$09,$06,$06,$09                         ; 2A87

tbl_2A91: ; same in all 44 cals
	fcb	$11,$14,$10,$10,$0C,$0C,$0C,$08,$08,$0C                         ; 2A91

tbl_2A9B: ; same in all 44 cals
	fcb	$11,$19,$14,$14,$0F,$0F,$0F,$0A,$0A,$0F                         ; 2A9B

tbl_2AA5: ; same in all 44 cals
	fcb	$11,$1E,$18,$18,$12,$12,$12,$0C,$0C,$12                         ; 2AA5

tbl_2AAF: ; same in all 44 cals
	fcb	$11,$23,$1C,$1C,$15,$15,$15,$0E,$0E,$15                         ; 2AAF

tbl_2AB9: ; same in all 44 cals
	fcb	$11,$28,$20,$20,$18,$18,$18,$10,$10,$18                         ; 2AB9

tbl3D_TIMING_BASE_RPM_x_Fuel_17x17_2AC3: ; 3D table, 9 values in 44 cals, differs in: ALT EGR NA TA TCM
	fcb	$FF
	fcb	$64,$64,$64,$64,$6E,$78,$8A,$98,$AE,$B9,$C3,$CB,$CB,$CB,$CB,$CB,$CB
	fcb	$64,$64,$64,$64,$6E,$78,$8A,$98,$9A,$A5,$AF,$B9,$C3,$CB,$CB,$CB,$CB
	fcb	$64,$64,$64,$64,$6E,$78,$84,$93,$98,$A0,$A9,$B7,$C3,$C5,$C5,$C5,$C5
	fcb	$64,$64,$64,$64,$6E,$78,$84,$93,$98,$9B,$A2,$B2,$C3,$C5,$C5,$C5,$C5
	fcb	$64,$64,$64,$64,$6E,$78,$84,$93,$98,$9B,$96,$A1,$B9,$C5,$C5,$C5,$C5
	fcb	$64,$64,$64,$64,$64,$78,$84,$93,$98,$98,$96,$98,$B2,$B2,$B2,$B7,$BC
	fcb	$63,$5A,$5A,$5A,$64,$78,$84,$93,$98,$98,$96,$98,$9D,$A2,$A7,$AC,$B1
	fcb	$63,$50,$50,$50,$5A,$78,$84,$93,$98,$98,$96,$98,$9D,$A2,$A7,$AC,$B1
	fcb	$63,$48,$46,$46,$5A,$78,$84,$93,$98,$98,$84,$98,$9D,$A2,$A7,$AC,$B1
	fcb	$63,$48,$46,$46,$5A,$78,$84,$93,$98,$98,$84,$98,$9D,$A2,$A7,$AC,$B1
	fcb	$63,$48,$46,$46,$5A,$78,$84,$93,$98,$98,$84,$98,$9D,$A2,$A7,$AC,$B1
	fcb	$63,$48,$46,$46,$5A,$78,$84,$93,$98,$98,$8E,$98,$9D,$A2,$A7,$AC,$B1
	fcb	$63,$48,$46,$46,$5A,$78,$84,$91,$98,$98,$A2,$B9,$C1,$C1,$C1,$C1,$C1
	fcb	$63,$48,$46,$46,$5A,$78,$84,$91,$98,$98,$BA,$CB,$D2,$D7,$C1,$C1,$C1
	fcb	$63,$48,$46,$46,$5A,$78,$84,$91,$98,$A8,$BA,$C8,$D2,$D7,$C1,$C1,$C1
	fcb	$63,$48,$46,$46,$5A,$78,$84,$91,$98,$A8,$BA,$C8,$D2,$D7,$C1,$C1,$C1
	fcb	$63,$48,$46,$46,$5A,$78,$84,$91,$98,$A8,$BA,$C8,$D2,$D7,$C1,$C1,$C1

tbl3D_FUEL_MAIN_RPM_x_Pedal_17x17_2BE5: ; 3D table, 11 values in 44 cals, differs in: ALT EGR NA TA TCM
;   OBD1 CAL_PEDAL_FUEL_COMMAND [A]: APP, RPM -> PEDAL FUEL COMMAND (mm^3 = N * .3125) / 0   3  6  9 12 15 18 21 24 27 30 33 36 39 42 45 48  x 100 rpm
	fcb	$FF
	fcb	$0B,$07,$04,$02,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$40,$38,$20,$1F,$1E,$1D,$1C,$1B,$1A,$19,$18,$17,$16,$16,$00,$00,$00
	fcb	$62,$58,$3F,$3E,$3C,$3A,$38,$36,$34,$32,$30,$2E,$2C,$2C,$00,$00,$00
	fcb	$78,$6C,$60,$5F,$5E,$5D,$58,$54,$51,$4E,$4A,$47,$45,$45,$00,$00,$00
	fcb	$86,$75,$6C,$7B,$7B,$7A,$74,$70,$6B,$67,$62,$60,$5B,$5B,$00,$00,$00
	fcb	$90,$7A,$70,$8F,$8F,$8F,$8E,$8A,$82,$7A,$74,$72,$6D,$6D,$00,$00,$00
	fcb	$96,$7D,$70,$9A,$A0,$A1,$A4,$A0,$96,$8C,$85,$83,$7E,$7E,$00,$00,$00
	fcb	$96,$7D,$70,$A0,$AE,$B0,$B7,$B4,$A8,$9C,$95,$93,$8E,$8E,$00,$00,$00
	fcb	$96,$7D,$70,$A2,$B8,$BD,$C7,$C4,$B8,$AB,$A3,$A1,$9D,$9D,$00,$00,$00
	fcb	$96,$7D,$70,$A2,$BE,$C8,$D4,$D2,$C8,$B8,$AF,$AD,$AA,$AA,$00,$00,$00
	fcb	$96,$7D,$70,$A2,$C0,$D0,$E1,$E1,$D9,$C8,$BA,$B9,$B6,$B6,$00,$00,$00
	fcb	$96,$7D,$70,$A2,$C0,$D6,$ED,$F0,$EA,$D5,$C4,$C3,$C1,$C1,$00,$00,$00
	fcb	$96,$7D,$70,$A2,$C0,$DA,$F5,$F6,$F3,$E1,$CC,$CA,$CA,$CA,$00,$00,$00
	fcb	$96,$7D,$70,$A2,$C0,$DA,$F5,$F6,$F3,$E1,$CC,$CA,$CA,$CA,$00,$00,$00
	fcb	$96,$7D,$70,$A2,$C0,$DA,$F5,$F6,$F3,$E1,$CC,$CA,$CA,$CA,$00,$00,$00
	fcb	$96,$7D,$70,$A2,$C0,$DA,$F5,$F6,$F3,$E1,$CC,$CA,$CA,$CA,$00,$00,$00
	fcb	$96,$7D,$70,$A2,$C0,$DA,$F5,$F6,$F3,$E1,$CC,$CA,$CA,$CA,$00,$00,$00

CAL_CRANKING_FUEL_TBL: ; same in all 44 cals
;   OBD1 CAL_CRANKING_FUEL_TBL [C]: ECTS, RPM * 4 -> cranking fuel for starting. / 37.5 mm^3 = 78 / 18.4 mm^3 = 3b / 12.2 mm^3 = 27 / RPM
	fcb	$F7,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 2D07
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 2D17
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 2D27
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 2D37
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 2D47
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 2D57
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 2D67
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 2D77
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 2D87
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00                         ; 2D97

tbl3D_fuel_temp_comp_RPM_x_FuelTemp_9x17_2DA1: ; 3D table, 2 values in 44 cals, differs in: ALT TA
;   OBD1 CAL_PUMP_FUEL_TEMP_ADJ [C]: 0   3  6  9 12 15 18 21 24 27 30 33 36 39 42 45 48  x 100 rpm
	fcb	$7F
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$03,$03,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$44,$0B,$05,$05,$03,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$78,$17,$0A,$0A,$09,$0B,$09,$06,$04,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$8A,$20,$0B,$0A,$0D,$10,$0D,$08,$06,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$7D,$28,$11,$0B,$0D,$10,$0D,$08,$06,$00,$00,$00,$00,$00,$00,$00,$00

tbl3D_PUMP_RPM_LOW_FUEL_2E3B: ; 3D table, 2 values in 44 cals, differs in: TA
;   OBD1 CAL_PUMP_RPM_LOW_FUEL [B]: 0   3  6  9 12 15 18 21 24 27 30 33 36 39 42 45 48  x 100 rpm
	fcb	$7F
	fcb	$7F,$7D,$79,$70,$5D,$55,$51,$4B,$44,$3E,$3A,$38,$37,$37,$00,$00,$00
	fcb	$AB,$A2,$9B,$95,$7F,$77,$6B,$68,$64,$55,$4D,$4B,$49,$49,$00,$00,$00
	fcb	$CA,$C3,$B9,$B1,$A1,$8E,$80,$79,$74,$70,$66,$5D,$58,$58,$00,$00,$00
	fcb	$E1,$DB,$CF,$C9,$B4,$AA,$99,$8F,$88,$82,$78,$74,$6B,$6B,$00,$00,$00
	fcb	$EE,$EA,$E2,$D6,$C5,$B8,$AD,$A2,$97,$8F,$86,$7C,$77,$77,$00,$00,$00
	fcb	$F5,$F1,$EB,$E1,$D6,$C3,$BB,$B1,$A5,$A0,$93,$8B,$81,$81,$00,$00,$00
	fcb	$F7,$F6,$F4,$EA,$E0,$CD,$C1,$BB,$B2,$AB,$9F,$9A,$96,$96,$00,$00,$00
	fcb	$FA,$FA,$F9,$EF,$E8,$DC,$C9,$C4,$BD,$B5,$AC,$A4,$A0,$A0,$00,$00,$00
	fcb	$FA,$FA,$FB,$F4,$EE,$E7,$D4,$CC,$C7,$C4,$B9,$B6,$B2,$B2,$00,$00,$00

tbl3D_PUMP_RPM_HIGH_FUEL_2ED5: ; 3D table, 2 values in 44 cals, differs in: TA
;   OBD1 CAL_PUMP_RPM_HIGH_FUEL [B]: 0   3  6  9 12 15 18 21 24 27 30 33 36 39 42 45 48  x 100 rpm
	fcb	$7F
	fcb	$FA,$FA,$FB,$F4,$EE,$E7,$D4,$CC,$C7,$C4,$B9,$B6,$B2,$B2,$00,$00,$00
	fcb	$FF,$FF,$FF,$F7,$F5,$EE,$DF,$D3,$CC,$C9,$C0,$BB,$B7,$B7,$00,$00,$00
	fcb	$FF,$FF,$FF,$FA,$F9,$F5,$EC,$DA,$D1,$CE,$C5,$C1,$BD,$BD,$00,$00,$00
	fcb	$FF,$FF,$FF,$FD,$FD,$FB,$F7,$E2,$D9,$D5,$CD,$C8,$C4,$AD,$00,$00,$00
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$EA,$DF,$DB,$D4,$CF,$CB,$CB,$00,$00,$00
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$F2,$E6,$E1,$DB,$D6,$D2,$D2,$00,$00,$00
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FA,$EC,$E7,$E2,$DD,$D9,$D9,$00,$00,$00
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FA,$EC,$E7,$E2,$DD,$D9,$D9,$00,$00,$00
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FA,$EC,$E7,$E2,$DD,$D9,$D9,$00,$00,$00

tbl2D_MIN_PUMPING_ANGLE_ZERO_FUEL_2F6F: ; 2D table, same in all 44 cals
;   OBD1 CAL_MIN_PUMPING_ANGLE_ZERO_FUEL [B]: RPM2 -> / Minimum pulse width in case of decel fuelling / 0   3  6  9 12 15 18 21 24 27 30 33 36 39 42 45 48  x 100 rpm
	fcb	$08
	fcb	$00,$00,$00,$BA,$9E,$92,$85,$78,$14

tbl3D_FUEL_reduction_RPM_x_Boost_7x9_2F79: ; 3D table, 9 values in 44 cals, differs in: ALT EGR NA TA TCM
	fcb	$57
	fcb	$00,$00,$38,$6B,$63,$45,$40,$40,$40
	fcb	$00,$00,$20,$53,$53,$35,$30,$30,$30
	fcb	$00,$00,$00,$33,$33,$15,$10,$10,$10
	fcb	$00,$00,$00,$1B,$13,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$77,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 2FB9
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 2FC9
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 2FD9
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 2FE9
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 2FF9
	fcb	$00,$00,$77,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 3009
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 3019
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 3029
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 3039
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 3049
	fcb	$00,$00,$00,$00                                                 ; 3059

tbl2D_timing_adder_IAT_305D: ; 2D table, 2 values in 44 cals, differs in: EGR
	fcb	$10
	fcb	$14,$14,$14,$10,$0A,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00

CAL_GLO_MIN_TIME: ; same in all 44 cals
;   OBD1 CAL_GLO_MIN_TIME [B]
	fcb	$03                                                             ; 306F

CAL_GLO_MAX_TIME_C: ; same in all 44 cals
;   analysis: preglow cap by temp band (3070-3073 via d_FD1C) | OBD1 CAL_GLO_MAX_TIME_C [C]
	fcb	$DA                                                             ; 3070

CAL_GLO_MAX_TIME_W: ; 3 values in 44 cals, differs in: ALT EGR TA TCM (range $8B-$A2)
;   OBD1 CAL_GLO_MAX_TIME_W [C]
	fcb	$96                                                             ; 3071

CAL_GLO_MAX_TIME_H: ; 2 values in 44 cals, differs in: ALT EGR TA TCM (range $39-$46)
;   OBD1 CAL_GLO_MAX_TIME_H [C]
	fcb	$39                                                             ; 3072

CAL_GLO_MAX_TIME_VH: ; same in all 44 cals
;   OBD1 CAL_GLO_MAX_TIME_VH [C]
	fcb	$28                                                             ; 3073

k_3074:	; same in all 44 cals
	fcb	$F2                                                             ; 3074

CAL_GLO_RPM_LIM_RUN: ; same in all 44 cals
;   analysis: RPM byte above which engine counts as running for glow logic | OBD1 CAL_GLO_RPM_LIM_RUN [A]
	fcb	$13                                                             ; 3075

k_3076:	; same in all 44 cals
	fcb	$00                                                             ; 3076

k_3077:	; same in all 44 cals
	fcb	$F2                                                             ; 3077

k_3078:	; same in all 44 cals
	fcb	$03                                                             ; 3078

k_3079:	; same in all 44 cals
	fcb	$03                                                             ; 3079

k_glow_overvolt_cutoff_307A: ; same in all 44 cals
;   analysis: $A0 = 16.0 V: glow forced to state 4
	fcb	$A0                                                             ; 307A

k_307B:	; same in all 44 cals
	fcb	$40                                                             ; 307B

k_307C:	; same in all 44 cals
	fcb	$C0                                                             ; 307C

k_307D:	; same in all 44 cals
	fcb	$53                                                             ; 307D

k_307E:	; same in all 44 cals
	fcb	$07                                                             ; 307E

k_307F:	; same in all 44 cals
;   analysis: 100 ms ticks
	fcb	$03                                                             ; 307F

k_glow_timer_nv_init_3080: ; same in all 44 cals
;   analysis: cold-start value for GLOW_TIMER_NV
	fcb	$00                                                             ; 3080

k_glow_timer1_init_3081: ; same in all 44 cals
;   analysis: cold-start value for GLOW_TIMER_1
	fcb	$00                                                             ; 3081

k_glow_no_preglow_temp_3082: ; same in all 44 cals
;   analysis: glow_ctrl_temp >= this: no preglow
	fcb	$C0                                                             ; 3082

CAL_GLO_MIN_ECTS_BASE_TBL: ; same in all 44 cals
;   OBD1 CAL_GLO_MIN_ECTS_BASE_TBL [B]
	fcb	$1D                                                             ; 3083

tbl2D_GLOW_3084: ; 2D table, same in all 44 cals
;   analysis: residual plug heat vs GLOW_TIMER_1 (time since glow ended) | OBD1 CAL_GLO_RST_RECOVER [C]: 4dc3 137 -> 1415  - glow amount already done before ECM reset / Result in GLOW_TIME_BEFORE_RESET
	fcb	$08
	fcb	$00,$21,$40,$55,$67,$78,$87,$91,$FF

tbl3D_GLOW_9x9_308E: ; 3D table, 4 values in 44 cals, differs in: ALT EGR NA TA TCM
;   OBD1 CAL_GLO_BASE_TIME [B]: batt volts ->, ects down
	fcb	$77
	fcb	$DA,$DA,$DA,$DA,$C6,$8E,$31,$25,$19
	fcb	$B4,$B4,$B4,$B4,$B4,$8E,$31,$23,$19
	fcb	$8B,$8B,$8B,$8B,$8B,$83,$31,$21,$19
	fcb	$5D,$5D,$6E,$6E,$6E,$66,$31,$18,$0A
	fcb	$37,$37,$64,$64,$64,$57,$2A,$17,$0A
	fcb	$32,$32,$50,$50,$50,$48,$24,$11,$00
	fcb	$2A,$2A,$49,$49,$49,$3E,$1F,$09,$00
	fcb	$20,$20,$40,$40,$40,$2A,$1D,$03,$00
	fcb	$17,$17,$2E,$2E,$2E,$16,$15,$00,$00

tbl3D_GLOW_time_temp_9x9_30E0: ; 3D table, 2 values in 44 cals, differs in: EGR
;   analysis: total afterglow time, batt x temp (code misdisassembled at FB6A) | OBD1 CAL_GLO_POSTGLOW_TIME [C]: batt volts, 1413 ->
	fcb	$77
	fcb	$00,$00,$FF,$FF,$FF,$FF,$C8,$C8,$A8
	fcb	$00,$00,$B4,$B4,$FF,$FF,$C8,$B4,$94
	fcb	$00,$00,$5A,$5A,$C8,$E1,$C3,$5A,$3A
	fcb	$00,$00,$1E,$1E,$3C,$82,$82,$1E,$0E
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00

tbl3D_GLOW_time_temp_9x9_3132: ; 3D table, 2 values in 44 cals, differs in: ALT EGR TA TCM
	fcb	$77
	fcb	$00,$00,$0A,$0A,$0A,$0A,$09,$07,$06
	fcb	$00,$00,$0A,$0A,$0A,$0A,$09,$07,$05
	fcb	$00,$00,$08,$07,$0A,$0A,$09,$06,$03
	fcb	$00,$00,$08,$07,$0A,$0A,$09,$06,$03
	fcb	$00,$00,$08,$07,$06,$06,$06,$06,$03
	fcb	$00,$00,$08,$07,$06,$06,$06,$06,$03
	fcb	$00,$00,$08,$07,$06,$06,$06,$06,$03
	fcb	$00,$00,$00,$07,$06,$06,$06,$06,$03
	fcb	$00,$00,$00,$07,$06,$06,$06,$06,$03

tbl3D_GLOW_BARO_9x9_3184: ; 3D table, same in all 44 cals
;   analysis: preglow extension for battery < 12.0 V (code misdisassembled at F9FB) | OBD1 CAL_GLO_BARO_TIME [B]: batt volts, Baro ->
	fcb	$77
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$10,$10,$10,$0A,$00,$00,$00,$00,$00
	fcb	$33,$33,$33,$1E,$00,$00,$00,$00,$00
	fcb	$41,$41,$3C,$1E,$00,$00,$00,$00,$00
	fcb	$32,$32,$14,$14,$00,$00,$00,$00,$00
	fcb	$28,$14,$0A,$0A,$00,$00,$00,$00,$00
	fcb	$28,$14,$0A,$0A,$00,$00,$00,$00,$00
	fcb	$1E,$14,$0A,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00

tbl_31D6: ; same in all 44 cals
;   analysis: 3 filter coefficients for idle error ($30,$30,$40)
	fcb	$30,$30,$40                                                     ; 31D6

kw_idle_dgain_31D9: ; same in all 44 cals
;   analysis: idle derivative gain
	fdb	$0300

CAL_IDLE_MAX_FUEL_FINAL: ; same in all 44 cals
;   OBD1 CAL_IDLE_MAX_FUEL_FINAL [A]: max idle governor fuel
	fcb	$D0                                                             ; 31DB

kw_idle_igain_overspeed_31DC: ; same in all 44 cals
;   analysis: idle I gain when RPM above target (31DE: below target)
	fdb	$1000

kw_31DE: ; same in all 44 cals
	fdb	$1800

kw_idle_pgain_overspeed_N_31E0: ; 2 values in 44 cals, differs in: NA TCM (range $4000-$6000)
;   analysis: idle P gain, neutral, RPM above target (31E2: below)
	fdb	$4000

kw_31E2: ; 2 values in 44 cals, differs in: NA TCM (range $4800-$C000)
	fdb	$4800

CAL_NEUTRAL_DRAG_TQ: ; same in all 44 cals
;   OBD1 CAL_NEUTRAL_DRAG_TQ [B]
	fcb	$30                                                             ; 31E4

k_AC_idle_ECT_min: ; same in all 44 cals
	fcb	$A0                                                             ; 31E5

k_AC_idle_RPM: ; same in all 44 cals
	fcb	$22                                                             ; 31E6

k_PN_idle_RPM: ; 2 values in 44 cals, differs in: EGR
	fcb	$38,$39,$39                                                     ; 31E7

k_31EA:	; same in all 44 cals
	fcb	$02                                                             ; 31EA

k_31EB:	; same in all 44 cals
;   analysis: idle floor when cold start latched (005D.4)
	fcb	$22                                                             ; 31EB

k_31EC:	; 2 values in 44 cals, differs in: EGR (range $011E-$3B1E)
	fcb	$3B,$1E                                                         ; 31EC

k_PTO_VSS_max: ; same in all 44 cals
	fcb	$10                                                             ; 31EE

k_hot_fuel_temp_threshold: ; same in all 44 cals
	fcb	$C8                                                             ; 31EF

k_hot_fuel_idle_RPM: ; 2 values in 44 cals, differs in: EGR (range $25-$28)
	fcb	$28                                                             ; 31F0

k_in_gear_idle_RPM: ; 2 values in 44 cals, differs in: NA TCM (range $23-$2B)
	fcb	$2B                                                             ; 31F1

k_in_gear_idle_VSS_min: ; 2 values in 44 cals, differs in: NA TCM (range $08-$28)
	fcb	$28                                                             ; 31F2

kw_31F3: ; same in all 44 cals
;   analysis: reference RPM for IDLEDT90 ratio ($1558)
	fdb	$1558

k_baro_learn_loops: ; same in all 44 cals
	fcb	$3C                                                             ; 31F5

k_PTO_idle_RPM_sw2: ; same in all 44 cals
	fcb	$39                                                             ; 31F6

k_PTO_idle_RPM_sw1: ; same in all 44 cals
	fcb	$48                                                             ; 31F7

k_PTO_idle_RPM_none: ; same in all 44 cals
	fcb	$55                                                             ; 31F8

tbl2D_VSS_9pt_31F9: ; 2D table, 2 values in 44 cals, differs in: NA TCM
	fcb	$08
	fcb	$32,$30,$28,$20,$20,$20,$20,$20,$20

tbl2D_r198A_9pt_3203: ; 2D table, 2 values in 44 cals, differs in: NA TCM
	fcb	$08
	fcb	$82,$82,$82,$82,$82,$82,$82,$82,$82

tbl2D_idle_RPM_vs_ECT_320D: ; 2D table, 3 values in 44 cals, differs in: ALT EGR TCM
	fcb	$10
	fcb	$2D,$2D,$2D,$2D,$2D,$2B,$28,$26,$23,$21,$20,$20,$28,$2A,$2A,$2A,$2A
	fcb	$08,$00,$00,$00,$00,$00,$00,$00,$00,$00                         ; 321F

CAL_NUM_CYLS: ; same in all 44 cals
;   OBD1 CAL_NUM_CYLS [A]: Start sensors / CKP fault count
	fcb	$08                                                             ; 3229

CAL_NUM_CYLS_LESS_ONE: ; same in all 44 cals
;   OBD1 CAL_NUM_CYLS_LESS_ONE [A]: used in cylinder balance
	fcb	$07                                                             ; 322A

CAL_RPMSCALE1: ; same in all 44 cals
;   OBD1 CAL_RPMSCALE1 [B]: RPM multiplier... 9837 - RPM uses 196740 clock speed
	fdb	$266D

CAL_CYLSEP: ; same in all 44 cals
;   analysis: $0400 fdiv divisor for backup pulse fraction | OBD1 CAL_CYLSEP [B]: 4f5e 90 degrees = cyl separation
	fdb	$0400

k_322F:	; same in all 44 cals
	fcb	$30,$80                                                         ; 322F

k_3231:	; same in all 44 cals
	fcb	$70                                                             ; 3231

kw_3232: ; same in all 44 cals
	fdb	$0000

k_3234:	; same in all 44 cals
;   analysis: ECT check value at/below which 1807.0 pullup is switched at reset
	fcb	$6B                                                             ; 3234

k_3235:	; same in all 44 cals
	fcb	$78                                                             ; 3235

k_3236:	; same in all 44 cals
	fcb	$6B                                                             ; 3236

k_3237:	; same in all 44 cals
	fcb	$78                                                             ; 3237

k_3238:	; same in all 44 cals
	fcb	$28                                                             ; 3238

k_3239:	; same in all 44 cals
	fcb	$03                                                             ; 3239

k_323A:	; same in all 44 cals
	fcb	$FB                                                             ; 323A

k_323B:	; same in all 44 cals
	fcb	$16                                                             ; 323B

k_323C:	; same in all 44 cals
	fcb	$03                                                             ; 323C

k_323D:	; same in all 44 cals
	fcb	$08                                                             ; 323D

k_EGR_openloop_load_hi: ; same in all 44 cals
	fcb	$DB                                                             ; 323E

k_323F:	; same in all 44 cals
	fcb	$CC                                                             ; 323F

k_EGR_openloop_load_lo: ; same in all 44 cals
	fcb	$A6                                                             ; 3240

k_3241:	; same in all 44 cals
	fcb	$10                                                             ; 3241

tbl2D_ECT_volts_check_3242: ; 2D table, same in all 44 cals
	fcb	$10
	fcb	$FF,$FF,$FB,$E0,$CD,$BE,$B2,$A7,$9C,$93,$89,$7E,$74,$67,$57,$3E,$00

tbl2D_ECT_conv_17pt_3254: ; 2D table, same in all 44 cals
	fcb	$10
	fcb	$FF,$A8,$8B,$7A,$6E,$64,$5B,$54,$4D,$46,$3F,$37,$30,$27,$1C,$0B,$00

tbl_3266: ; same in all 44 cals
	fcb	$10,$FF,$FF,$FB,$E0,$CD,$BE,$B2,$A7,$9C,$93,$89,$7E,$74,$67,$57 ; 3266
	fcb	$3E,$00                                                         ; 3276

tbl2D_IAT_conv_3278: ; 2D table, same in all 44 cals
	fcb	$10
	fcb	$FF,$A8,$8B,$7A,$6E,$64,$5B,$54,$4D,$46,$3F,$37,$30,$27,$1C,$0B,$00

tbl2D_FuelTemp_conv_17pt_328A: ; 2D table, same in all 44 cals
	fcb	$10
	fcb	$FC,$FC,$F8,$F4,$EF,$E8,$DE,$D3,$C7,$B7,$A7,$95,$85,$74,$64,$55,$49

k_J1850_ECM_node_addr_329C: ; same in all 44 cals
;   analysis: $10 = ECM physical address used as source byte; $10: ECM physical address required for mode $36; this ECM's J1850 physical address (source in replies, target filter)
	fcb	$10                                                             ; 329C

k_329D:	; same in all 44 cals
	fcb	$04                                                             ; 329D

k_329E:	; same in all 44 cals
;   analysis: $64 = 100 ticks after IGN off before shutdown allowed
	fcb	$64                                                             ; 329E

k_329F:	; same in all 44 cals
;   analysis: 40 ticks for $8E.5 after DLC reset
	fcb	$28                                                             ; 329F

k_diag_session_timeout_32A0: ; same in all 44 cals
;   analysis: reload for tester-present/session timer $1F7D
	fcb	$C8                                                             ; 32A0

k_security_disable_32A1: ; same in all 44 cals
;   analysis: $FF = no seed/key security (auto unlock); if != $FF and Working_counter==0, clear $1F6F/$1F70/$1F72 on session end (value $00)
	fcb	$00                                                             ; 32A1

k_security_lockout_delay_32A2: ; same in all 44 cals
;   analysis: delay after max bad keys
	fcb	$64,$32                                                         ; 32A2

k_security_max_attempts_32A4: ; same in all 44 cals
;   analysis: bad keys before lockout
	fcb	$02                                                             ; 32A4

k_32A5:	; same in all 44 cals
;   analysis: transmit retries
	fcb	$08                                                             ; 32A5

k_32A6:	; same in all 44 cals
	fcb	$50                                                             ; 32A6

k_32A7:	; same in all 44 cals
	fcb	$05                                                             ; 32A7

k_32A8:	; same in all 44 cals
	fcb	$05,$05                                                         ; 32A8

k_msg_slot_limits_32AA: ; same in all 44 cals
;   analysis: 7-byte records per slot: flags/mode mask, min interval, reload, period, word/byte thresholds
	fcb	$28,$02,$06,$11,$00,$01,$20,$40,$00,$00,$00,$00,$00,$00,$40,$00 ; 32AA
	fcb	$00,$00,$00,$00,$00,$40,$00,$00,$00,$00,$00,$00,$40,$00,$00,$00 ; 32BA
	fcb	$00,$00,$00,$40,$00,$00,$00,$00,$00,$00,$40,$00,$00,$00,$00,$00 ; 32CA
	fcb	$00,$40,$00,$00,$00,$00,$00,$00,$40,$00,$00,$00,$00,$00,$00,$40 ; 32DA
	fcb	$00,$00,$00,$00,$00,$00,$40,$00,$00,$00,$00,$00,$00,$28,$01,$00 ; 32EA
	fcb	$FF,$00,$02,$80,$08,$02,$00,$FF,$00,$00,$E0,$40,$00,$00,$00,$00 ; 32FA
	fcb	$00,$00,$40,$00,$00,$00,$00,$00,$00,$40,$00,$00,$00,$00,$00,$00 ; 330A
	fcb	$40,$00,$00,$00,$00,$00,$00,$40,$00,$00,$00,$00,$00,$00,$40,$00 ; 331A
	fcb	$00,$00,$00,$00,$00,$40,$00,$00,$00,$00,$00,$00,$40,$00,$00,$00 ; 332A
	fcb	$00,$00,$00,$40,$00,$00,$00,$00,$00,$00,$40,$00,$00,$00,$00,$00 ; 333A
	fcb	$00,$40,$00,$00,$00,$00,$00,$00,$40,$00,$00,$00,$00,$00,$00,$40 ; 334A
	fcb	$00,$00,$00,$00,$00,$00,$40,$00,$00,$00,$00,$00,$00,$40,$00,$00 ; 335A
	fcb	$00,$00,$00,$00,$40,$00,$00,$00,$00,$00,$00,$40,$00,$00,$00,$00 ; 336A
	fcb	$00,$00,$40,$00,$00,$00,$00,$00,$00,$40,$00,$00,$00,$00,$00,$00 ; 337A
	fcb	$08,$00                                                         ; 338A

k_338C:	; same in all 44 cals
	fcb	$03,$08,$00,$00,$40,$28,$0A,$00,$FF,$00,$01,$60,$09,$00         ; 338C

k_339A:	; same in all 44 cals
	fcb	$03,$08,$00,$00,$A0,$08,$00,$00,$00,$00,$00,$A0,$28,$04,$0C,$22 ; 339A
	fcb	$00,$01,$60,$08,$00,$00,$00,$00,$00,$C0,$09,$00                 ; 33AA

k_33B6:	; same in all 44 cals
	fcb	$03,$08,$00,$00,$E0,$08,$00,$00,$FF,$00,$00,$80,$28,$14,$06,$11 ; 33B6
	fcb	$00,$01,$A0,$08,$00,$00,$FF,$00,$00,$A0,$08,$00,$00,$FF,$00,$00 ; 33C6
	fcb	$A0                                                             ; 33D6

k_ECT_out_1809_on: ; 2 values in 44 cals, differs in: ALT TA (range $00-$9C)
	fcb	$00                                                             ; 33D7

k_ECT_out_1809_off: ; 2 values in 44 cals, differs in: ALT TA (range $00-$B2)
	fcb	$00                                                             ; 33D8

k_ECT_out_1800_4_off: ; 2 values in 44 cals, differs in: ALT TA (range $00-$C1)
	fcb	$00                                                             ; 33D9

k_ECT_out_1800_4_on: ; 2 values in 44 cals, differs in: ALT TA (range $00-$C8)
	fcb	$00                                                             ; 33DA

k_33DB:	; 2 values in 44 cals, differs in: ALT TA (range $00-$B0)
	fcb	$00                                                             ; 33DB

k_33DC:	; 2 values in 44 cals, differs in: ALT TA (range $00-$BB)
	fcb	$00                                                             ; 33DC

kw_MT_ratio_g3_max_33DD: ; same in all 44 cals
;   analysis: 8.8 engine/OSS ratio, $00BC=0.73: below -> gear 3
	fdb	$00BC

kw_33DF: ; same in all 44 cals
	fdb	$00F3

kw_MT_ratio_g2_min_33E1: ; same in all 44 cals
;   analysis: $010D=1.05 band edges with 33DF ($F3), 33E3 ($140)
	fdb	$010D

kw_33E3: ; same in all 44 cals
	fdb	$0140

kw_MT_ratio_g1_max_33E5: ; same in all 44 cals
;   analysis: $0300=3.0; above 33E7 -> gear 0
	fdb	$0300

kw_33E7: ; same in all 44 cals
	fdb	$0300
	fcb	$50,$00                                                         ; 33E9

kw_pedal_filt_min_OSS_33EB: ; same in all 44 cals
;   analysis: OSS above which gear-dependent pedal filter applies ($50)
	fdb	$0050

kw_33ED: ; same in all 44 cals
;   analysis: integrator floor with Configuration_set.2 when RPM below target ($0500)
	fdb	$0500

tbl_pedal_filt_coef_by_gear_33EF: ; 2 values in 44 cals, differs in: NA TCM
;   analysis: lag coef per gear 0-3 (90,B0,D0,D0)
	fcb	$90,$B0,$D0,$D0                                                 ; 33EF

CAL_AUTODRIVE_DRAG_TQ: ; same in all 44 cals
;   OBD1 CAL_AUTODRIVE_DRAG_TQ [B]
	fcb	$38                                                             ; 33F3

k_pedal_filt_gear3_RPM_33F4: ; same in all 44 cals
;   analysis: RPM byte ($50=1500) above which gear-3 coef is used
	fcb	$50                                                             ; 33F4

k_33F5:	; same in all 44 cals
	fcb	$32                                                             ; 33F5

k_33F6:	; 2 values in 44 cals, differs in: NA TCM (range $05-$FF)
	fcb	$FF                                                             ; 33F6

k_33F7:	; same in all 44 cals
	fcb	$25                                                             ; 33F7

CAL_STALL_SAVE_LOW_RPM: ; same in all 44 cals
;   OBD1 CAL_STALL_SAVE_LOW_RPM [B]: db $15	; stall-saver rpm  (lowered from 15 to 0e in new rom)
	fcb	$15                                                             ; 33F8

CAL_STALL_SAVE_DELTA_RPM: ; same in all 44 cals
;   OBD1 CAL_STALL_SAVE_DELTA_RPM [B]: stall-saver delta-rpm
	fcb	$10                                                             ; 33F9

CAL_STALL_SAVE_MAX_RPM: ; same in all 44 cals
;   OBD1 CAL_STALL_SAVE_MAX_RPM [B]: stall-saver decay rpm
	fcb	$23                                                             ; 33FA

CAL_STALL_SAVE_TIME_DELTATRIG: ; same in all 44 cals
;   OBD1 CAL_STALL_SAVE_TIME_DELTATRIG [B]: stall-saver timer
	fcb	$05                                                             ; 33FB

CAL_STALL_SAVE_TIME_LOWTRIG: ; same in all 44 cals
;   OBD1 CAL_STALL_SAVE_TIME_LOWTRIG [B]: stall-saver timer
	fcb	$05                                                             ; 33FC

kw_33FD: ; same in all 44 cals
	fdb	$00FA

kw_idle_pgain_overspeed_D_33FF: ; same in all 44 cals
;   analysis: idle P gain in gear, RPM above target (3401: below)
	fdb	$6000

kw_3401: ; same in all 44 cals
	fdb	$D000

CAL_STALL_SAVE_FUEL_QTY: ; same in all 44 cals
;   OBD1 CAL_STALL_SAVE_FUEL_QTY [A]: db	$f0 		; stall-saver fuel kick new rom 4fe3 f0 -> a0
	fcb	$F0                                                             ; 3403

CAL_STALL_SAVE_FUEL_DECAY: ; same in all 44 cals
;   OBD1 CAL_STALL_SAVE_FUEL_DECAY [B]: stall-saver fuel kick decay rate
	fcb	$10                                                             ; 3404

k_VSS_timeout_passes_3405: ; same in all 44 cals
;   analysis: passes with no pulses before speed=0 (7)
	fcb	$07                                                             ; 3405

k_3406:	; same in all 44 cals
	fcb	$F0                                                             ; 3406

k_3407:	; same in all 44 cals
	fcb	$F0                                                             ; 3407

k_3408:	; same in all 44 cals
	fcb	$C7                                                             ; 3408

k_APP1_zero_init_3409: ; same in all 44 cals
;   analysis: $F2: default APP1 zero after sensor fault (340A APP2, 340B APP3); initial APP1 zero point ($F2)
	fcb	$F2                                                             ; 3409

k_APP2_zero_init_340A: ; same in all 44 cals
;   analysis: initial APP2 zero point
	fcb	$F2                                                             ; 340A

k_APP3_zero_init_340B: ; same in all 44 cals
;   analysis: initial APP3 zero point
	fcb	$F2                                                             ; 340B

k_340C:	; same in all 44 cals
	fcb	$00                                                             ; 340C

k_340D:	; same in all 44 cals
	fcb	$00                                                             ; 340D

k_340E:	; same in all 44 cals
	fcb	$00,$31,$31,$29,$04,$04,$04                                     ; 340E

k_APP_offset_3415: ; same in all 44 cals
;   analysis: offset subtracted after APP gain
	fcb	$07                                                             ; 3415

k_3416:	; same in all 44 cals
	fcb	$50                                                             ; 3416

k_3417:	; same in all 44 cals
	fcb	$50                                                             ; 3417

k_3418:	; same in all 44 cals
	fcb	$50                                                             ; 3418

k_APP_zero_relearn_max_3419: ; same in all 44 cals
;   analysis: max zeroed APP counts accepted for zero relearn
	fcb	$03                                                             ; 3419

k_pedal_tipin_filt_coef_341A: ; same in all 44 cals
;   analysis: FILT_16A coef ($80)
	fcb	$80                                                             ; 341A

k_341B:	; same in all 44 cals
;   analysis: max load used to seed pedal shaper on release ($59)
	fcb	$59                                                             ; 341B

k_APP_fault_pre_debounce_341C: ; same in all 44 cals
;   analysis: pre-debounce count ($04) for APP disagreement / 5V-ref faults
	fcb	$04                                                             ; 341C

k_341D:	; same in all 44 cals
	fcb	$60                                                             ; 341D

k_341E:	; same in all 44 cals
	fcb	$65                                                             ; 341E

k_341F:	; same in all 44 cals
;   analysis: copied to $1F86 at reset
	fcb	$04                                                             ; 341F

k_3420:	; same in all 44 cals
	fcb	$00                                                             ; 3420

k_3421:	; same in all 44 cals
;   analysis: anti-theft state delay reload ($50 x 50ms)
	fcb	$50                                                             ; 3421

k_3422:	; same in all 44 cals
	fcb	$03                                                             ; 3422

k_3423:	; same in all 44 cals
	fcb	$03                                                             ; 3423

k_3424:	; same in all 44 cals
	fcb	$03                                                             ; 3424

kw_3425: ; same in all 44 cals
	fdb	$2EE0

kw_3427: ; same in all 44 cals
;   analysis: loaded into $33 by device control CPID FE
	fdb	$2EE0

k_3429:	; same in all 44 cals
	fcb	$03                                                             ; 3429

k_342A:	; same in all 44 cals
	fcb	$05                                                             ; 342A

k_342B:	; same in all 44 cals
	fcb	$1E                                                             ; 342B

k_VSS_deriv_filt_coef_342C: ; same in all 44 cals
;   analysis: filter coef for VEH_SPEED_DERIVATIVE ($30)
	fcb	$30                                                             ; 342C

k_boost_ctrl_min_RPM_342D: ; same in all 44 cals
;   analysis: wastegate duty 0 at/below this RPM byte
	fcb	$10                                                             ; 342D

CAL_BOOST_MIN_INT: ; same in all 44 cals
;   OBD1 CAL_BOOST_MIN_INT [A]: minimum boost integrator limit
	fdb	$0000

k_3430:	; same in all 44 cals
	fcb	$30                                                             ; 3430

k_3431:	; same in all 44 cals
	fcb	$40                                                             ; 3431

tbl2D_boost_ctrl_BARO_3432: ; 2D table, same in all 44 cals
;   OBD1 CAL_BOOST_MAX_INT [B]: Boost integrator limit with baro
	fcb	$08
	fcb	$F0,$E0,$D0,$C0,$B0,$98,$80,$80,$80

tbl2D_boost_ctrl_BARO_343C: ; 2D table, same in all 44 cals
;   OBD1 CAL_BOOST_IGAIN [B]: Boost integrator gain with baro
	fcb	$08
	fcb	$14,$14,$14,$14,$14,$14,$14,$14,$14

tbl2D_boost_ctrl_BARO_3446: ; 2D table, same in all 44 cals
;   OBD1 CAL_BOOST_PGAIN [B]: Boost proportional gain with baro
	fcb	$08
	fcb	$80,$80,$80,$70,$60,$50,$40,$40,$40

tbl3D_BOOST_target_RPM_x_Fuel_9x17_3450: ; 3D table, 8 values in 44 cals, differs in: ALT EGR NA TA TCM
	fcb	$7F
	fcb	$8F,$8F,$8F,$8F,$8F,$8F,$8F,$81,$72,$64,$64,$64,$6E,$6E,$6E,$6E,$6E
	fcb	$8F,$8F,$8F,$8F,$8F,$69,$6E,$72,$64,$64,$64,$64,$6E,$6E,$6E,$6E,$6E
	fcb	$8F,$8F,$8F,$8F,$8F,$6E,$74,$7A,$65,$64,$64,$64,$6E,$6E,$6E,$6E,$6E
	fcb	$8F,$8F,$8F,$8F,$8F,$78,$7F,$82,$66,$64,$64,$64,$6E,$6E,$6E,$6E,$6E
	fcb	$8F,$8F,$8F,$8F,$8F,$8F,$8F,$8F,$7C,$72,$6E,$6E,$6E,$6E,$6E,$6E,$6E
	fcb	$8F,$8F,$8F,$8F,$8F,$98,$98,$8F,$85,$7C,$77,$72,$72,$72,$72,$72,$72
	fcb	$8F,$8F,$8F,$8F,$8F,$9F,$9F,$97,$92,$8F,$8A,$81,$81,$7C,$7C,$7C,$7C
	fcb	$8F,$8F,$8F,$8F,$8F,$A7,$A7,$A7,$A5,$98,$95,$94,$94,$8F,$8F,$8F,$8F
	fcb	$8F,$8F,$8F,$8F,$8F,$AF,$AF,$AF,$AA,$9D,$9A,$98,$98,$8F,$8F,$8F,$8F

k_34EA:	; 2 values in 44 cals, differs in: ALT NA TCM (range $00-$08)
	fcb	$08                                                             ; 34EA

k_34EB:	; 2 values in 44 cals, differs in: ALT NA TCM (range $00-$DF)
	fcb	$DF                                                             ; 34EB

k_34EC:	; same in all 44 cals
	fcb	$7F                                                             ; 34EC

k_34ED:	; same in all 44 cals
	fcb	$9A                                                             ; 34ED

k_34EE:	; same in all 44 cals
	fcb	$B3                                                             ; 34EE

k_34EF:	; same in all 44 cals
	fcb	$01                                                             ; 34EF

k_34F0:	; same in all 44 cals
	fcb	$00                                                             ; 34F0

k_34F1:	; same in all 44 cals
	fcb	$2B                                                             ; 34F1

k_34F2:	; same in all 44 cals
	fcb	$FF                                                             ; 34F2

k_34F3:	; same in all 44 cals
	fcb	$02                                                             ; 34F3

k_34F4:	; same in all 44 cals
	fcb	$F3                                                             ; 34F4

k_34F5:	; same in all 44 cals
	fcb	$46                                                             ; 34F5

k_34F6:	; same in all 44 cals
	fcb	$FF                                                             ; 34F6

k_34F7:	; same in all 44 cals
	fcb	$00                                                             ; 34F7

kw_crank_fuel_PW_max_34F8: ; same in all 44 cals
;   analysis: limit for cranking COMMAND_FUEL_PW
	fdb	$036B
	fcb	$FF,$B6                                                         ; 34FA

k_34FC:	; same in all 44 cals
	fcb	$AA                                                             ; 34FC

k_34FD:	; same in all 44 cals
	fcb	$98                                                             ; 34FD

k_34FE:	; same in all 44 cals
	fcb	$6B                                                             ; 34FE

tbl2D_17pt_34FF: ; 2D table, same in all 44 cals
	fcb	$10
	fcb	$00,$00,$00,$00,$01,$03,$04,$03,$03,$04,$04,$05,$06,$06,$06,$07,$07

tbl2D_r0099_17pt_3511: ; 2D table, same in all 44 cals
	fcb	$10
	fcb	$B6,$B6,$B6,$B6,$C0,$C6,$C6,$C6,$C6,$C6,$C6,$C6,$D6,$D6,$D6,$D6,$D6

tbl2D_17pt_3523: ; 2D table, 2 values in 44 cals, differs in: ALT NA TCM
	fcb	$10
	fcb	$00,$00,$00,$27,$39,$37,$33,$2B,$22,$1F,$1F,$1F,$1F,$1F,$1F,$25,$35

t2d_3535: ; 2D table, 3 values in 44 cals, differs in: ALT NA TCM
	fcb	$35
	fcb	$57,$35,$69,$35,$7B,$35,$8D,$35,$9F,$35,$B1,$35,$C3,$35,$D5,$35,$E7,$35,$F9,$36,$0B,$36,$1D,$36,$2F,$36,$41,$36,$53,$36,$65,$36,$77,$10,$99,$99,$99,$99,$99,$89,$7A,$7A,$7D,$7B,$79,$77,$75,$73,$71,$6F,$6D,$10,$99,$99
	fcb	$99,$99,$89,$7A,$7A,$7A,$7D,$7B,$79,$77,$75,$73,$71,$6F,$6D,$10 ; 356C
	fcb	$99,$99,$99,$99,$89,$7A,$7A,$7A,$7D,$7B,$79,$77,$75,$73,$71,$6F ; 357C
	fcb	$6D,$10,$99,$99,$99,$7A,$7A,$7A,$7A,$78,$75,$72,$6F,$6C,$69,$66 ; 358C
	fcb	$63,$60,$5D,$10,$99,$99,$8C,$7A,$6C,$66,$64,$62,$64,$61,$5E,$5B ; 359C
	fcb	$58,$56,$54,$52,$50,$10,$99,$99,$8C,$7A,$6C,$66,$64,$62,$64,$61 ; 35AC
	fcb	$5E,$5B,$58,$56,$54,$52,$50,$10,$99,$99,$86,$72,$69,$60,$60,$5F ; 35BC
	fcb	$64,$61,$5E,$5B,$58,$55,$52,$4F,$4C,$10,$99,$99,$80,$68,$65,$58 ; 35CC
	fcb	$5B,$5B,$62,$5F,$5C,$59,$56,$53,$50,$4D,$4A,$10,$99,$99,$80,$68 ; 35DC
	fcb	$65,$58,$5B,$5B,$62,$5F,$5C,$59,$56,$53,$50,$4D,$4A,$10,$99,$99 ; 35EC
	fcb	$80,$68,$65,$58,$5B,$5B,$62,$5F,$5C,$59,$56,$53,$50,$4D,$4A,$10 ; 35FC
	fcb	$99,$99,$80,$68,$65,$58,$5B,$5B,$62,$5F,$5C,$59,$56,$53,$50,$4D ; 360C
	fcb	$4A,$10,$99,$99,$80,$6A,$67,$5A,$5D,$5D,$64,$61,$5E,$5B,$58,$55 ; 361C
	fcb	$52,$4F,$4C,$10,$99,$99,$80,$6A,$67,$5A,$5D,$5D,$64,$61,$5E,$5B ; 362C
	fcb	$58,$55,$52,$4F,$4C,$10,$99,$99,$80,$6A,$67,$5A,$5D,$5D,$64,$61 ; 363C
	fcb	$5E,$5B,$58,$55,$52,$4F,$4C,$10,$99,$99,$80,$6A,$67,$5A,$5D,$5D ; 364C
	fcb	$64,$61,$5E,$5B,$58,$55,$52,$4F,$4C,$10,$99,$99,$80,$6A,$67,$5A ; 365C
	fcb	$5D,$5D,$64,$61,$5E,$5B,$58,$55,$52,$4F,$4C,$10,$99,$99,$80,$6A ; 366C
	fcb	$67,$5A,$5D,$5D,$64,$61,$5E,$5B,$58,$55,$52,$4F,$4C             ; 367C

k_bulbtest_time_3689: ; same in all 44 cals
;   analysis: BULBTEST_TMR init (1A1F/1A20 from 368A/368B)
	fcb	$04                                                             ; 3689

k_368A:	; 2 values in 44 cals, differs in: ALT (range $00-$14)
	fcb	$00                                                             ; 368A

k_368B:	; same in all 44 cals
	fcb	$02                                                             ; 368B

k_DTC_fail_count_limit_368C: ; same in all 44 cals
;   analysis: $14 = 20 counts, shared by many debounce counters; =20 counts to set P0405/P0406; =20; fail-counter threshold used by most DTCs in this routine
	fcb	$14                                                             ; 368C

k_fuel_sol_diag_fail_count_368D: ; same in all 44 cals
;   analysis: fail count for P1216/P1217/P0606 ($A0)
	fcb	$A0                                                             ; 368D

k_P1656_fail_count_limit_368E: ; same in all 44 cals
;   analysis: =5
	fcb	$05                                                             ; 368E

k_P0126_ECT_warm_threshold_368F: ; same in all 44 cals
;   analysis: =$80 ECT counts; thermostat test ends when ECT reaches it; coolant warm-up target ($80 raw)
	fcb	$80                                                             ; 368F

k_3690:	; same in all 44 cals
	fcb	$2C                                                             ; 3690

k_3691:	; same in all 44 cals
	fcb	$03                                                             ; 3691

kw_3692: ; same in all 44 cals
	fdb	$012C

kw_3694: ; same in all 44 cals
	fdb	$0258

kw_3696: ; same in all 44 cals
	fdb	$00E1

kw_3698: ; same in all 44 cals
	fdb	$01C2

k_369A:	; same in all 44 cals
	fcb	$16                                                             ; 369A

kw_369B: ; same in all 44 cals
	fdb	$DB80

k_369D:	; same in all 44 cals
	fcb	$13                                                             ; 369D

k_369E:	; same in all 44 cals
	fcb	$30                                                             ; 369E

kw_369F: ; same in all 44 cals
	fdb	$D400

tbl2D_ECT_9pt_36A1: ; 2D table, same in all 44 cals
	fcb	$08
	fcb	$FD,$FD,$4B,$34,$24,$24,$24,$24,$24

k_ODM_diag_min_batt_36AB: ; same in all 44 cals
;   analysis: $55 = 8.5 V (N/10); ODM SPI status read skipped below this; battery ADC above which ODM SPI reads are valid; battery gate for ADC filtering
	fcb	$55                                                             ; 36AB

k_36AC:	; same in all 44 cals
	fcb	$05                                                             ; 36AC

k_36AD:	; same in all 44 cals
	fcb	$0C                                                             ; 36AD

k_36AE:	; same in all 44 cals
	fcb	$0C                                                             ; 36AE

k_36AF:	; same in all 44 cals
	fcb	$F3                                                             ; 36AF

k_36B0:	; same in all 44 cals
	fcb	$F3                                                             ; 36B0

kw_P0118_min_run_time_36B1: ; same in all 44 cals
;   analysis: =$12C0 (480 s at 0.1 s)
	fdb	$12C0

k_36B3:	; 2 values in 44 cals, differs in: ALT (range $4D-$BB)
	fcb	$4D                                                             ; 36B3

k_36B4:	; same in all 44 cals
;   analysis: =$28
	fcb	$28                                                             ; 36B4

k_36B5:	; same in all 44 cals
;   analysis: =$28
	fcb	$28                                                             ; 36B5

k_P0370_stall_events_36B6: ; same in all 44 cals
;   analysis: CKP events without high-res change before P0370
	fcb	$08                                                             ; 36B6

k_missed_I4_ref_P0251_limit_36B7: ; 2 values in 44 cals, differs in: NA TCM (range $08-$0A)
;   analysis: miss count (8) to set P0251
	fcb	$08                                                             ; 36B7

k_ref_mismatch_limit_36B8: ; same in all 44 cals
;   analysis: mismatch count limit for P0251/P0335
	fcb	$20                                                             ; 36B8

k_36B9:	; same in all 44 cals
;   analysis: P0251 limit when FLAGS3.0 (short cam period)
	fcb	$60                                                             ; 36B9

k_36BA:	; same in all 44 cals
;   analysis: reload for $1A37
	fcb	$F0                                                             ; 36BA

k_36BB:	; same in all 44 cals
;   analysis: 3: once the other counter is non-zero, stop counting (ambiguous double fault)
	fcb	$03                                                             ; 36BB

kw_ref_period_max_run_36BC: ; same in all 44 cals
;   analysis: $0440 upper plausibility for $1A38 in run; max plausible ref period running
	fdb	$0440

kw_ref_period_min_run_36BE: ; same in all 44 cals
;   analysis: $03C0 lower plausibility in run; min plausible ref period running
	fdb	$03C0

kw_ref_period_max_crank_36C0: ; same in all 44 cals
;   analysis: $0448 in crank; max plausible ref period cranking
	fdb	$0448

kw_ref_period_min_crank_36C2: ; same in all 44 cals
;   analysis: $03B8 in crank; min plausible ref period cranking
	fdb	$03B8

k_missed_IC3_ref_P0335_limit_36C4: ; 2 values in 44 cals, differs in: NA TCM (range $08-$09)
;   analysis: miss count (8) to set P0335
	fcb	$08                                                             ; 36C4

k_36C5:	; same in all 44 cals
	fcb	$04,$00,$00                                                     ; 36C5

k_APP1_high_limit_36C8: ; same in all 44 cals
;   analysis: $F0 raw ADC, P0123
	fcb	$F0                                                             ; 36C8

k_APP2_high_limit_36C9: ; same in all 44 cals
;   analysis: $F0, P0223
	fcb	$F0                                                             ; 36C9

k_APP3_high_limit_36CA: ; same in all 44 cals
;   analysis: $DB, P0228
	fcb	$DB                                                             ; 36CA

k_APP1_low_limit_36CB: ; same in all 44 cals
;   analysis: $0C, P0122
	fcb	$0C                                                             ; 36CB

k_APP2_low_limit_36CC: ; same in all 44 cals
;   analysis: $0C, P0222
	fcb	$0C                                                             ; 36CC

k_APP3_low_limit_36CD: ; same in all 44 cals
;   analysis: $47, P0227
	fcb	$47                                                             ; 36CD

k_APP1_APP2_max_diff_36CE: ; same in all 44 cals
;   analysis: $0F, on filtered values
	fcb	$0F                                                             ; 36CE

k_APP1_APP3_max_diff_36CF: ; same in all 44 cals
;   analysis: $1A
	fcb	$1A                                                             ; 36CF

k_APP2_APP3_max_diff_36D0: ; same in all 44 cals
;   analysis: $1A
	fcb	$1A                                                             ; 36D0

k_APP_5Vref_low_limit_36D1: ; same in all 44 cals
;   analysis: $30 MUX14 counts; at or below -> P0220/P0225
	fcb	$30                                                             ; 36D1

k_P0380_glowV_vs_batt_tol_36D2: ; same in all 44 cals
;   analysis: =$14
	fcb	$14                                                             ; 36D2

k_36D3:	; same in all 44 cals
	fcb	$28                                                             ; 36D3

k_36D4:	; same in all 44 cals
	fcb	$0C                                                             ; 36D4

k_36D5:	; same in all 44 cals
	fcb	$7C                                                             ; 36D5

k_36D6:	; same in all 44 cals
	fcb	$00                                                             ; 36D6

k_36D7:	; same in all 44 cals
	fcb	$CA                                                             ; 36D7

k_36D8:	; same in all 44 cals
	fcb	$78                                                             ; 36D8

k_36D9:	; same in all 44 cals
	fcb	$CA                                                             ; 36D9

k_36DA:	; same in all 44 cals
	fcb	$C6                                                             ; 36DA

k_36DB:	; 2 values in 44 cals, differs in: EGR (range $19-$FF)
	fcb	$FF                                                             ; 36DB

k_36DC:	; same in all 44 cals
	fcb	$1B                                                             ; 36DC

k_P0216_timing_error_limit_36DD: ; same in all 44 cals
;   analysis: =$32 |desired-measured| injection timing
	fcb	$32                                                             ; 36DD

k_rpm_steady_delta_36DE: ; same in all 44 cals
;   analysis: =3 RPM counts (56 rpm)
	fcb	$03                                                             ; 36DE

k_rpm_steady_count_36DF: ; same in all 44 cals
;   analysis: =$32 passes
	fcb	$32                                                             ; 36DF

CAL_diag_MINRSP: ; same in all 44 cals
;   OBD1 CAL_diag_MINRSP [B]
	fdb	$00A7

CAL_diag_MAXRSP: ; same in all 44 cals
;   OBD1 CAL_diag_MAXRSP [B]
	fdb	$0242

CAL_diag_MINBATT: ; same in all 44 cals
;   OBD1 CAL_diag_MINBATT [C]
	fcb	$78                                                             ; 36E4

CAL_diag_MAXBATT: ; same in all 44 cals
;   OBD1 CAL_diag_MAXBATT [C]
	fcb	$96                                                             ; 36E5

CAL_diag_MINECTS: ; same in all 44 cals
;   OBD1 CAL_diag_MINECTS [C]
	fcb	$78                                                             ; 36E6

CAL_diag_MINRPM: ; same in all 44 cals
;   OBD1 CAL_diag_MINRPM [C]
	fcb	$6E                                                             ; 36E7

CAL_diag_MINRPM_36E8: ; same in all 44 cals
;   OBD1 CAL_diag_MINRPM [C]
	fcb	$48                                                             ; 36E8

CAL_diag_STOPPEDRPM: ; same in all 44 cals
;   OBD1 CAL_diag_STOPPEDRPM [C]
	fcb	$01                                                             ; 36E9

CAL_diag_LUGRPM: ; same in all 44 cals
;   OBD1 CAL_diag_LUGRPM [C]
	fcb	$18                                                             ; 36EA

CAL_diag_BRAKETIME: ; same in all 44 cals
;   OBD1 CAL_diag_BRAKETIME [C]
	fdb	$1770

CAL_diag_DELTAVSS: ; same in all 44 cals
;   OBD1 CAL_diag_DELTAVSS [C]
	fdb	$0200

CAL_diag_DECELTIME: ; same in all 44 cals
;   OBD1 CAL_diag_DECELTIME [C]
	fcb	$1E                                                             ; 36EF

CAL_diag_FAULTCOUNTS: ; same in all 44 cals
;   OBD1 CAL_diag_FAULTCOUNTS [C]
	fcb	$05                                                             ; 36F0

CAL_diag_MINV: ; same in all 44 cals
;   OBD1 CAL_diag_MINV [C]
	fcb	$0C                                                             ; 36F1

CAL_diag_MAXV: ; same in all 44 cals
;   OBD1 CAL_diag_MAXV [C]
	fcb	$FD                                                             ; 36F2

CAL_diag_MINRUNTM: ; same in all 44 cals
;   OBD1 CAL_diag_MINRUNTM [C]: min run time for fts
	fdb	$12C0

k_fuel_temp_default_on_fault: ; same in all 44 cals
;   OBD1 CAL_diag_FTSSUB [B]: default fts temperature
	fcb	$74                                                             ; 36F5

k_36F6:	; same in all 44 cals
	fcb	$0C                                                             ; 36F6

k_36F7:	; same in all 44 cals
	fcb	$F8                                                             ; 36F7

k_IAT_default_on_fault: ; same in all 44 cals
	fcb	$7F                                                             ; 36F8

k_P0601_fail_count: ; same in all 44 cals
	fcb	$03                                                             ; 36F9

kw_P0606_max_pump_timing_36FA: ; same in all 44 cals
;   analysis: max plausible MEASURED_INJ_TMG_8192
	fdb	$044E

kw_36FC: ; same in all 44 cals
;   analysis: max plausible TIO $146A reading
	fdb	$0006

k_P0606_persist_36FE: ; same in all 44 cals
;   analysis: passes before P0606 counter starts
	fcb	$06                                                             ; 36FE

CAL_diag_MIN_VOLTS: ; same in all 44 cals
;   analysis: min valid MUX5 pump cal reading (P1218) | OBD1 CAL_diag_MIN_VOLTS [B]: min volt range limit for fuel trim resistor
	fcb	$0E                                                             ; 36FF

CAL_diag_MAX_VOLTS: ; same in all 44 cals
;   analysis: max valid MUX5 pump cal reading (P1218) | OBD1 CAL_diag_MAX_VOLTS [B]: max volt range limit
	fcb	$DB                                                             ; 3700

CAL_diag_SUB_MAP: ; same in all 44 cals
;   analysis: default Pump_Cal_Ptr when resistor invalid | OBD1 CAL_diag_SUB_MAP [B]: fuel cal pointer for min fuel in case of resistor fault
	fdb	$2A57

CAL_diag_MINV_3703: ; same in all 44 cals
;   analysis: =$30 | OBD1 CAL_diag_MINV [C]
	fcb	$30                                                             ; 3703

CAL_diag_MAX_BOOSTV: ; 2 values in 44 cals, differs in: EGR (range $F7-$F8)
;   analysis: =$F7 AN5 counts (P0238/P0108) | OBD1 CAL_diag_MAX_BOOSTV [C]
	fcb	$F7                                                             ; 3704

CAL_diag_MAX_RPM: ; same in all 44 cals
;   analysis: =$BB | OBD1 CAL_diag_MAX_RPM [C]
	fcb	$BB                                                             ; 3705

CAL_diag_MIN_BOOSTV: ; same in all 44 cals
;   analysis: =$28 AN5 counts (P0237/P0107) | OBD1 CAL_diag_MIN_BOOSTV [C]
	fcb	$28                                                             ; 3706

k_MAP_default_on_fault: ; same in all 44 cals
;   OBD1 CAL_diag_BOOSTSUB [C]
	fcb	$57                                                             ; 3707

CAL_diag_SC_TIME: ; same in all 44 cals
;   OBD1 CAL_diag_SC_TIME [C]
	fcb	$FF                                                             ; 3708

CAL_diag_RA_TIME: ; same in all 44 cals
;   OBD1 CAL_diag_RA_TIME [C]
	fcb	$FF                                                             ; 3709

CAL_diag_TIMEOVER: ; same in all 44 cals
;   analysis: =100 | OBD1 CAL_diag_TIMEOVER [C]
	fcb	$64                                                             ; 370A

CAL_diag_TIMEUNDERFAST: ; same in all 44 cals
;   OBD1 CAL_diag_TIMEUNDERFAST [C]
	fcb	$64                                                             ; 370B

CAL_diag_TIMEUNDERSLOW: ; same in all 44 cals
;   OBD1 CAL_diag_TIMEUNDERSLOW [C]: same but boost needs to be higher
	fcb	$80                                                             ; 370C

CAL_diag_OVERBOOSTBAND: ; same in all 44 cals
;   analysis: =$14 above boost target | OBD1 CAL_diag_OVERBOOSTBAND [C]: boost upper error band (should be lower than this)
	fcb	$14                                                             ; 370D

CAL_diag_MINBSTFAST: ; same in all 44 cals
;   OBD1 CAL_diag_MINBSTFAST [C]
	fcb	$14                                                             ; 370E

CAL_diag_MINBSTSLOW: ; same in all 44 cals
;   OBD1 CAL_diag_MINBSTSLOW [C]
	fcb	$14                                                             ; 370F

CAL_diag_MINBOOSTABSSLOW: ; same in all 44 cals
;   OBD1 CAL_diag_MINBOOSTABSSLOW [C]
	fcb	$6E                                                             ; 3710

CAL_diag_MINCMDPWRFAST: ; same in all 44 cals
;   OBD1 CAL_diag_MINCMDPWRFAST [C]: min commanded fuel to engine, 20mm3
	fcb	$40                                                             ; 3711

CAL_diag_MINCMDPWRSLOW: ; same in all 44 cals
;   OBD1 CAL_diag_MINCMDPWRSLOW [C]: min commanded fuel to engine, 20mm3
	fcb	$40                                                             ; 3712

CAL_diag_MINRPMOVER: ; same in all 44 cals
;   OBD1 CAL_diag_MINRPMOVER [C]: min engine speed 2400 rpm	for overboost mode
	fcb	$80                                                             ; 3713

CAL_diag_RPMSPLIT: ; same in all 44 cals
;   OBD1 CAL_diag_RPMSPLIT [C]: min engine speed 2400 rpm
	fcb	$80                                                             ; 3714

CAL_diag_MINRPMUNDER: ; same in all 44 cals
;   OBD1 CAL_diag_MINRPMUNDER [C]: min engine speed 1800 rpm
	fcb	$60                                                             ; 3715

CAL_DIAG_WGT_SAFE1: ; same in all 44 cals
;   OBD1 CAL_DIAG_WGT_SAFE1 [C]: wastegate ???
	fcb	$00                                                             ; 3716

tbl2D_fuel_limit_boostsensor_fault_RPM_3717: ; 2D table, same in all 44 cals
;   OBD1 CAL_DIAG_BOOST_DERATE [B]: tp fuel subtract vs rpm for failed boost diag (prevents overboost) / 0  3  6   9    12 15 18 21 24 27 30 33 36 39 42 45 48  x 100 rpm
	fcb	$10
	fcb	$00,$00,$00,$00,$15,$2D,$30,$30,$40,$50,$50,$50,$50,$50,$50,$50,$50
	fcb	$3C                                                             ; 3729

CAL_diagX_FAILCOUNTS: ; same in all 44 cals
;   analysis: balance fail count to set P0263-P0284 (10) | OBD1 CAL_diagX_FAILCOUNTS [C]: fuel balance limit?
	fcb	$0A,$FF,$FF,$FF                                                 ; 372A

OVERRIDE_CAP_APP: ; same in all 44 cals
;   OBD1 OVERRIDE_CAP_APP [B]
	fcb	$00                                                             ; 372E

CAL_SOL_TMG_INIT: ; same in all 44 cals
;   analysis: timing used when timing DTCs active | OBD1 CAL_SOL_TMG_INIT [C]: default (initial)	injector timing
	fdb	$0017

CAL_SOL_MAX_PUMP_TIMING: ; same in all 44 cals
;   OBD1 CAL_SOL_MAX_PUMP_TIMING [A]: max inj angle delay
	fdb	$03FF

kw_3733: ; same in all 44 cals
;   analysis: substitute closure time
	fdb	$0188

kw_3735: ; same in all 44 cals
;   analysis: above -> FLAGS2.4, use kw_3733
	fdb	$01EC
	fcb	$32                                                             ; 3737

k_3738:	; same in all 44 cals
	fcb	$05                                                             ; 3738

k_3739:	; same in all 44 cals
	fcb	$28,$0A,$4B                                                     ; 3739

k_373C:	; 2 values in 44 cals, differs in: EGR (range $00-$C0)
	fcb	$00                                                             ; 373C

k_373D:	; 2 values in 44 cals, differs in: EGR (range $00-$40)
	fcb	$00                                                             ; 373D

k_373E:	; 2 values in 44 cals, differs in: EGR (range $00-$04)
	fcb	$00                                                             ; 373E

k_373F:	; 2 values in 44 cals, differs in: EGR (range $00-$04)
	fcb	$00                                                             ; 373F

k_3740:	; 2 values in 44 cals, differs in: EGR (range $00-$06)
	fcb	$00                                                             ; 3740

k_3741:	; 2 values in 44 cals, differs in: EGR (range $00-$1E)
	fcb	$00                                                             ; 3741

k_3742:	; same in all 44 cals
	fcb	$00                                                             ; 3742

k_3743:	; same in all 44 cals
	fcb	$00                                                             ; 3743

k_EGR_flowtest_max_rpm_3744: ; 2 values in 44 cals, differs in: EGR (range $00-$2B)
;   analysis: 0 in this bin -> flow test disabled
	fcb	$00                                                             ; 3744

k_3745:	; 2 values in 44 cals, differs in: EGR (range $0000-$1B50)
	fcb	$00,$00                                                         ; 3745

k_3747:	; 2 values in 44 cals, differs in: EGR (range $00-$E9)
	fcb	$00                                                             ; 3747

k_3748:	; 2 values in 44 cals, differs in: EGR (range $00-$50)
	fcb	$00                                                             ; 3748

k_3749:	; 2 values in 44 cals, differs in: EGR (range $00-$8C)
	fcb	$00                                                             ; 3749

k_374A:	; 2 values in 44 cals, differs in: EGR (range $00-$1E)
	fcb	$00                                                             ; 374A

k_374B:	; 2 values in 44 cals, differs in: EGR (range $00-$05)
	fcb	$00                                                             ; 374B

k_374C:	; 2 values in 44 cals, differs in: EGR (range $00-$26)
	fcb	$00                                                             ; 374C

k_374D:	; 2 values in 44 cals, differs in: EGR (range $96-$FF)
	fcb	$FF                                                             ; 374D

k_374E:	; 2 values in 44 cals, differs in: EGR (range $00-$15)
	fcb	$00                                                             ; 374E

k_374F:	; 2 values in 44 cals, differs in: EGR (range $00-$16)
	fcb	$00                                                             ; 374F

k_3750:	; 2 values in 44 cals, differs in: EGR (range $00-$50)
	fcb	$00                                                             ; 3750

k_3751:	; 2 values in 44 cals, differs in: EGR (range $00-$50)
	fcb	$00                                                             ; 3751

k_3752:	; 2 values in 44 cals, differs in: EGR (range $00-$70)
	fcb	$00                                                             ; 3752

k_3753:	; 2 values in 44 cals, differs in: EGR (range $00-$1C)
	fcb	$00                                                             ; 3753

k_3754:	; 2 values in 44 cals, differs in: EGR (range $00-$1E)
	fcb	$00                                                             ; 3754

k_3755:	; 2 values in 44 cals, differs in: EGR (range $00-$14)
	fcb	$00                                                             ; 3755

k_3756:	; 2 values in 44 cals, differs in: EGR (range $00-$6E)
	fcb	$00                                                             ; 3756

k_3757:	; 2 values in 44 cals, differs in: EGR (range $00-$05)
	fcb	$00                                                             ; 3757

k_3758:	; 2 values in 44 cals, differs in: EGR (range $00-$29)
	fcb	$00                                                             ; 3758

k_3759:	; 2 values in 44 cals, differs in: EGR (range $00-$03)
	fcb	$00                                                             ; 3759

k_375A:	; 2 values in 44 cals, differs in: EGR (range $00-$5D)
	fcb	$00                                                             ; 375A

k_375B:	; 2 values in 44 cals, differs in: EGR (range $00-$0E)
	fcb	$00                                                             ; 375B

kw_375C: ; 2 values in 44 cals, differs in: EGR (range $01-$FF)
	fcb	$FF                                                             ; 375C

k_375D:	; 2 values in 44 cals, differs in: EGR (range $00-$FF)
	fcb	$FF                                                             ; 375D

kw_375E: ; 2 values in 44 cals, differs in: EGR (range $00-$FF)
	fcb	$FF                                                             ; 375E

k_375F:	; 2 values in 44 cals, differs in: EGR (range $00-$FF)
	fcb	$FF                                                             ; 375F

k_3760:	; 2 values in 44 cals, differs in: EGR (range $E0-$FF)
	fcb	$FF                                                             ; 3760

k_3761:	; 2 values in 44 cals, differs in: EGR (range $01-$FF)
	fcb	$FF                                                             ; 3761

kw_3762: ; 2 values in 44 cals, differs in: EGR (range $11-$FF)
	fcb	$FF                                                             ; 3762

k_3763:	; 2 values in 44 cals, differs in: EGR (range $00-$FF)
	fcb	$FF                                                             ; 3763

kw_3764: ; 2 values in 44 cals, differs in: EGR (range $08-$FF)
	fcb	$FF                                                             ; 3764

k_3765:	; 2 values in 44 cals, differs in: EGR (range $00-$FF)
	fcb	$FF                                                             ; 3765

kw_3766: ; 2 values in 44 cals, differs in: EGR (range $00-$FF)
	fcb	$FF                                                             ; 3766

k_3767:	; 2 values in 44 cals, differs in: EGR (range $02-$FF)
	fcb	$FF                                                             ; 3767

kw_3768: ; 2 values in 44 cals, differs in: EGR (range $00-$FF)
	fcb	$FF                                                             ; 3768

k_3769:	; 2 values in 44 cals, differs in: EGR (range $00-$FF)
	fcb	$FF                                                             ; 3769

kw_376A: ; 2 values in 44 cals, differs in: EGR (range $00-$FF)
	fcb	$FF                                                             ; 376A

k_376B:	; 2 values in 44 cals, differs in: EGR (range $04-$FF)
	fcb	$FF                                                             ; 376B

kw_376C: ; 2 values in 44 cals, differs in: EGR (range $00-$FF)
	fcb	$FF                                                             ; 376C

k_376D:	; 2 values in 44 cals, differs in: EGR (range $00-$FF)
	fcb	$FF                                                             ; 376D

kw_376E: ; 2 values in 44 cals, differs in: EGR (range $40-$FF)
	fcb	$FF                                                             ; 376E

k_376F:	; 2 values in 44 cals, differs in: EGR (range $41-$FF)
	fcb	$FF                                                             ; 376F

kw_3770: ; 2 values in 44 cals, differs in: EGR (range $A8-$FF)
	fcb	$FF                                                             ; 3770

k_3771:	; 2 values in 44 cals, differs in: EGR (range $00-$FF)
	fcb	$FF                                                             ; 3771

kw_3772: ; 2 values in 44 cals, differs in: EGR (range $41-$FF)
	fcb	$FF                                                             ; 3772

k_3773:	; 2 values in 44 cals, differs in: EGR (range $01-$FF)
	fcb	$FF                                                             ; 3773

kw_3774: ; 2 values in 44 cals, differs in: EGR (range $A8-$FF)
	fcb	$FF                                                             ; 3774

k_3775:	; 2 values in 44 cals, differs in: EGR (range $00-$FF)
	fcb	$FF                                                             ; 3775

kw_3776: ; same in all 44 cals
	fcb	$FF                                                             ; 3776

k_3777:	; same in all 44 cals
	fcb	$FF                                                             ; 3777

kw_3778: ; same in all 44 cals
	fcb	$FF                                                             ; 3778

k_3779:	; same in all 44 cals
	fcb	$FF                                                             ; 3779

kw_377A: ; 2 values in 44 cals, differs in: EGR (range $19-$FF)
	fcb	$FF                                                             ; 377A

k_377B:	; 2 values in 44 cals, differs in: EGR (range $00-$FF)
	fcb	$FF                                                             ; 377B

kw_377C: ; 2 values in 44 cals, differs in: EGR (range $E0-$FF)
	fcb	$FF                                                             ; 377C

k_377D:	; 2 values in 44 cals, differs in: EGR (range $01-$FF)
	fcb	$FF                                                             ; 377D

kw_377E: ; 3 values in 44 cals, differs in: EGR NA TCM (range $0000-$FFFF)
	fdb	$0000

kw_3780: ; 2 values in 44 cals, differs in: EGR (range $00-$FF)
	fcb	$FF                                                             ; 3780

k_3781:	; 2 values in 44 cals, differs in: EGR (range $10-$FF)
	fcb	$FF                                                             ; 3781

kw_3782: ; 2 values in 44 cals, differs in: EGR (range $01-$FF)
	fcb	$FF                                                             ; 3782

k_3783:	; 2 values in 44 cals, differs in: EGR (range $00-$FF)
	fcb	$FF                                                             ; 3783

k_3784:	; 3 values in 44 cals, differs in: EGR NA TCM (range $00-$FF)
	fcb	$00                                                             ; 3784

k_3785:	; same in all 44 cals
	fcb	$FF                                                             ; 3785

k_3786:	; same in all 44 cals
	fcb	$01                                                             ; 3786

tbl2D_EGR_BARO_3787: ; 2D table, 2 values in 44 cals, differs in: EGR
	fcb	$08
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00

tbl2D_MAFdiag_thresh_BARO_3791: ; 2D table, 2 values in 44 cals, differs in: EGR
	fcb	$08
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00

tbl2D_MAFdiag_thresh_BARO_379B: ; 2D table, 2 values in 44 cals, differs in: EGR
	fcb	$08
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00

tbl2D_MAFdiag_thresh_BARO_37A5: ; 2D table, 2 values in 44 cals, differs in: EGR
	fcb	$08
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00

tbl2D_MAFdiag_thresh_BARO_37AF: ; 2D table, 2 values in 44 cals, differs in: EGR
	fcb	$08
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00

tbl2D_MAFdiag_thresh_BARO_37B9: ; 2D table, 2 values in 44 cals, differs in: EGR
	fcb	$08
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00

tbl2D_MAFdiag_thresh_BARO_37C3: ; 2D table, 2 values in 44 cals, differs in: EGR
	fcb	$08
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00

k_cylbal_diag_ECT_min_37CD: ; same in all 44 cals
;   analysis: ECT must be above this for P030x cyl-balance diag
	fcb	$80                                                             ; 37CD

k_cylbal_diag_ECT_max_37CE: ; same in all 44 cals
;   analysis: ECT must be below this
	fcb	$C1                                                             ; 37CE

k_cylbal_diag_delay_37CF: ; same in all 44 cals
;   analysis: delay count (calls) before evaluating pinned cylinders
	fcb	$5A                                                             ; 37CF

DTC_cal_mask_37D0: ; 5 values in 44 cals, differs in: ALT NA TA TCM
;   analysis: 15 bytes (37D0-37DE), bit per DTC: emission/MIL-type code; label tbl_37DE starts one byte early
	fcb	$FF,$71,$01,$F8,$00,$FF,$FF,$83,$89,$CD,$DE,$FC,$C2,$EE         ; 37D0

tbl_DTC_MIL_count_mask_37DE: ; 7 values in 44 cals, differs in: ALT NA TA TCM
;   analysis: 15-byte mask of DTCs counted for PID $01 DTC count
	fcb	$00,$FF,$7F,$F9,$7F,$00,$FF,$F9,$03,$80,$CD,$E2,$FC,$C2,$CE,$00 ; 37DE

DTC_disable_mask: ; same in all 44 cals
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00         ; 37EE

tbl_37FC: ; same in all 44 cals
	fcb	$00                                                             ; 37FC

tbl_37FD: ; 6 values in 44 cals, differs in: ALT NA TA TCM
;   analysis: 15 bytes: bits allowed into MIL request 02A5
	fcb	$E7,$7F,$F9,$FF,$00,$FF,$FF,$83,$89,$CD,$FE,$FC,$C2,$EE,$00     ; 37FD

DTC_diag_enable_mask: ; 3 values in 44 cals, differs in: EGR NA TCM (range $E0-$F8)
;   OBD1 CAL_ENG_diag_ENAMASKS [A]
	fcb	$E0                                                             ; 380C

k_380D:	; same in all 44 cals
	fcb	$FF                                                             ; 380D

k_380E:	; 2 values in 44 cals, differs in: ALT NA TCM (range $FD-$FF)
	fcb	$FF                                                             ; 380E

k_380F:	; 2 values in 44 cals, differs in: NA TCM (range $8F-$FF)
	fcb	$FF                                                             ; 380F

k_3810:	; same in all 44 cals
	fcb	$FF                                                             ; 3810

k_3811:	; same in all 44 cals
	fcb	$FF                                                             ; 3811

k_3812:	; 2 values in 44 cals, differs in: EGR (range $0F-$FF)
	fcb	$0F                                                             ; 3812

k_3813:	; 3 values in 44 cals, differs in: EGR NA TCM (range $F8-$FF)
	fcb	$FC                                                             ; 3813

k_3814:	; 2 values in 44 cals, differs in: ALT NA TCM (range $0D-$FD)
	fcb	$FD                                                             ; 3814

k_3815:	; 2 values in 44 cals, differs in: ALT NA TCM (range $00-$FF)
	fcb	$FF                                                             ; 3815

k_3816:	; 3 values in 44 cals, differs in: ALT EGR NA TCM (range $A0-$FF)
	fcb	$BF                                                             ; 3816

k_3817:	; 2 values in 44 cals, differs in: EGR (range $87-$AF)
	fcb	$87                                                             ; 3817

k_3818:	; 4 values in 44 cals, differs in: ALT EGR NA TA TCM (range $32-$FB)
	fcb	$7B                                                             ; 3818

k_3819:	; 5 values in 44 cals, differs in: ALT EGR NA TCM (range $01-$FF)
	fcb	$FD                                                             ; 3819

k_381A:	; 3 values in 44 cals, differs in: ALT EGR NA TA TCM (range $00-$03)
	fcb	$02                                                             ; 381A

tbl_381B: ; 2 values in 44 cals, differs in: EGR
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00     ; 381B

k_PID01_cont_mon_supported_382A: ; 2 values in 44 cals, differs in: ALT (range $04-$05)
;   analysis: PID $01 byte B supported bits ($05); x16 -> RAM 0276 at code clear (5 -> 80)
	fcb	$05                                                             ; 382A

k_OBD_mode6_enable_382B: ; 2 values in 44 cals, differs in: EGR
;   analysis: -> RAM 0277 at code clear; PID $01 byte C; nonzero also adds PID $10 to PID $00 map; non-zero = answer OBD2 mode $06 requests
	fcb	$00,$00,$00                                                     ; 382B

k_382E:	; same in all 44 cals
;   analysis: APP1 ADC max (0x0A) for key-on-engine-off start detection
	fcb	$0A                                                             ; 382E

k_382F:	; same in all 44 cals
;   analysis: ECT voltage min for key-on-engine-off start detection
	fcb	$F5,$32                                                         ; 382F

k_ECT_default_trans_3831: ; same in all 44 cals
;   analysis: coolant default for trans logic
	fcb	$AD                                                             ; 3831

k_trans_load_limp_3832: ; 3 values in 44 cals, differs in: ALT NA TCM
;   analysis: fixed trans load in limp mode ($4F)
	fcb	$4F,$00,$10,$40,$F0                                             ; 3832

k_trans_load_filter_coef_3837: ; same in all 44 cals
;   analysis: FILTER1 coefficient
	fcb	$FF,$00,$0A,$F0                                                 ; 3837

kw_baro_default_383B: ; 10 values in 44 cals, differs in: NA TA TCM
;   analysis: $7530
	fdb	$7530
	fcb	$51,$B2                                                         ; 383D

tbl_383F: ; same in all 44 cals
	fcb	$13                                                             ; 383F

k_ECT_hot_set_3840: ; 2 values in 44 cals, differs in: ALT NA TCM (range $CC-$E3)
	fcb	$CC                                                             ; 3840

k_ECT_hot_clear_3841: ; 2 values in 44 cals, differs in: ALT NA TCM (range $B5-$DC)
	fcb	$B5                                                             ; 3841

k_brake_debounce_cnt_3842: ; same in all 44 cals
;   analysis: =4 samples
	fcb	$04                                                             ; 3842

k_baro_gain_3843: ; same in all 44 cals
	fcb	$79                                                             ; 3843

kw_baro_offset_3844: ; same in all 44 cals
	fdb	$0D3F
	fcb	$67                                                             ; 3846

tbl_3847: ; same in all 44 cals
	fcb	$A2                                                             ; 3847

k_motion_stop_debounce_3848: ; same in all 44 cals
;   analysis: 3 calls
	fcb	$03                                                             ; 3848

k_3849:	; same in all 44 cals
	fcb	$01                                                             ; 3849

k_384A:	; same in all 44 cals
	fcb	$50                                                             ; 384A

kw_384B: ; same in all 44 cals
	fdb	$4222

tbl_input_speed_filter_384D: ; same in all 44 cals
;   analysis: Sensor_smoothing params
	fcb	$FC,$AA,$AB                                                     ; 384D

CAL_TRANS_OSS_DT_SCALAR: ; same in all 44 cals
;   OBD1 CAL_TRANS_OSS_DT_SCALAR [A]: OSS scalar for OSS DT
	fcb	$02                                                             ; 3850

kw_3851: ; same in all 44 cals
	fdb	$AAAB

CAL_OSS_FILTER: ; same in all 44 cals
;   OBD1 CAL_OSS_FILTER [A]
	fcb	$FF                                                             ; 3853

CAL_OSS_SCALAR: ; same in all 44 cals
;   OBD1 CAL_OSS_SCALAR [A]: output shaft speed conversion
	fdb	$ACCC

CAL_VEH_GEAR_RATIO: ; same in all 44 cals
;   OBD1 CAL_VEH_GEAR_RATIO [A]: vehicle's gear ratio (or scalar)
	fdb	$BA00

CAL_TRANS_VSPD_FILT: ; same in all 44 cals
;   OBD1 CAL_TRANS_VSPD_FILT [A]
	fcb	$FC                                                             ; 3858

k_kickdown_enter_load_4WD_3859: ; 2 values in 44 cals, differs in: ALT TCM (range $00-$66)
;   analysis: $66
	fcb	$66                                                             ; 3859

k_kickdown_exit_load_4WD_385A: ; 2 values in 44 cals, differs in: ALT TCM (range $00-$64)
;   analysis: $64
	fcb	$64                                                             ; 385A

k_kickdown_enter_load_385B: ; 2 values in 44 cals, differs in: ALT TCM (range $00-$DF)
;   analysis: 2WD ($DF)
	fcb	$DF                                                             ; 385B

k_kickdown_exit_load_385C: ; 2 values in 44 cals, differs in: ALT TCM (range $00-$DC)
;   analysis: 2WD ($DC)
	fcb	$DC                                                             ; 385C

kw_motion_engine_speed_385D: ; 3 values in 44 cals, differs in: ALT NA TA TCM (range $0190-$0ED8)
	fdb	$0960

kw_motion_output_speed_385F: ; 2 values in 44 cals, differs in: ALT NA TCM (range $0050-$FFFF)
;   analysis: $FFFF (disabled)
	fdb	$FFFF

kw_motion_turbine_speed_3861: ; 2 values in 44 cals, differs in: ALT NA TCM
;   analysis: $FFFF (disabled)
	fdb	$FFFF
	fcb	$78                                                             ; 3863

k_trans_type_flags_3864: ; 2 values in 44 cals, differs in: TCM (range $80-$A0)
;   analysis: b7 = trans with ISS/4L80E-style solenoid pattern + extra diags; b5 D2 forces manual pattern
	fcb	$80                                                             ; 3864

tbl_3865: ; 2 values in 44 cals, differs in: TCM (range $82-$83)
	fcb	$83                                                             ; 3865

k_3866:	; 2 values in 44 cals, differs in: ALT TCM (range $00-$07)
	fcb	$07                                                             ; 3866

tbl_3867: ; 2 values in 44 cals, differs in: ALT TCM (range $00-$01)
	fcb	$01                                                             ; 3867

k_3868:	; 2 values in 44 cals, differs in: ALT NA TCM (range $00-$01)
	fcb	$01                                                             ; 3868

kw_reverse_gear_ratio_3869: ; same in all 44 cals
;   analysis: $423E = 2.07 reverse ratio x8192; N/8192 = 2.07
	fdb	$423E

tbl_gear_ratios_386B: ; same in all 44 cals
;   analysis: 4 words N/8192: 2.48,1.48,1.00,0.75; 4 words: 2.48,1.48,1.00,0.75 (4L80E); labels 386D/386F split it
	fcb	$4F,$5C                                                         ; 386B

tbl_386D: ; same in all 44 cals
	fcb	$2F,$5C                                                         ; 386D

tbl_386F: ; same in all 44 cals
	fdb	$2000
	fcb	$18,$00                                                         ; 3871

tbl_ratio_ramp_delay_3873: ; 2 values in 44 cals, differs in: TA
;   analysis: per gear, 10
	fcb	$0A,$0A,$0A                                                     ; 3873

tbl_ratio_ramp_ticks_3876: ; same in all 44 cals
;   analysis: per gear, 30
	fcb	$1E,$1E,$1E                                                     ; 3876

k_limp_gear_index_3879: ; same in all 44 cals
;   analysis: 1 = 2nd gear (FMEM forced gear); gear used for ratio when range switch fault (1 = 2nd)
	fcb	$01                                                             ; 3879

k_387A:	; 2 values in 44 cals, differs in: TCM (range $00-$01)
	fcb	$01                                                             ; 387A

k_TCC_top_gear_index_387B: ; same in all 44 cals
;   analysis: 3 = 4th gear; =3, gear index limit used for top-gear tests
	fcb	$03                                                             ; 387B

tcurve_387C: ; CV table, 2 values in 44 cals, differs in: ALT
;   analysis: 17-pt vs TC speed ratio
	fcb	$A4,$A0,$97,$92,$8C,$83,$78,$70,$66,$60,$59,$52,$4B,$43,$40,$40 ; 387C
	fcb	$40                                                             ; 388C

tbl_388D: ; same in all 44 cals
	fcb	$F0                                                             ; 388D

kw_388E: ; same in all 44 cals
	fdb	$8000

k_num_shift_adapt_tables_3890: ; same in all 44 cals
;   analysis: 3; 3 = 4 forward gears (0-based max); 3 = 4th; 3 = 4th gear; highest commandable gear (3); upper limit of CPID 01 value stored in $1C5E
	fcb	$03                                                             ; 3890

k_TC_slip_filter_3891: ; 2 values in 44 cals, differs in: ALT NA TCM (range $20-$FC)
;   analysis: FILTER2 coefficient
	fcb	$20                                                             ; 3891

tbl_3892: ; same in all 44 cals
	fcb	$FC                                                             ; 3892

tbl_turbine_speed_filter_3893: ; same in all 44 cals
;   analysis: Sensor_smoothing params
	fcb	$FC                                                             ; 3893

k_VSS_hi_set_3894: ; same in all 44 cals
;   analysis: $3E = 31 mph
	fcb	$3E                                                             ; 3894

k_VSS_hi_clear_3895: ; same in all 44 cals
;   analysis: $3A = 29 mph
	fcb	$3A                                                             ; 3895

k_3896:	; same in all 44 cals
	fcb	$02                                                             ; 3896

k_3897:	; same in all 44 cals
	fcb	$04                                                             ; 3897

k_3898:	; 2 values in 44 cals, differs in: ALT NA TA TCM (range $05-$0D)
	fcb	$0D                                                             ; 3898

k_3899:	; 2 values in 44 cals, differs in: ALT NA TA TCM (range $07-$11)
	fcb	$11                                                             ; 3899

k_tipout_rate_389A: ; same in all 44 cals
;   analysis: signed load rate threshold (-38)
	fcb	$DA                                                             ; 389A

k_389B:	; same in all 44 cals
	fcb	$28                                                             ; 389B

k_389C:	; same in all 44 cals
	fcb	$00                                                             ; 389C

k_389D:	; same in all 44 cals
	fcb	$00                                                             ; 389D

t17_altitude_weight_389E: ; 17 table, same in all 44 cals
;   analysis: weight vs altitude factor (all FF)
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF

tbl_38AF: ; same in all 44 cals
	fcb	$10,$FF,$FF,$FB,$E0,$CD,$BE,$B2,$A7,$9C,$93,$89,$7E,$74,$67,$57 ; 38AF
	fcb	$3E,$00                                                         ; 38BF

tbl2D_trans_temp_conv_38C1: ; 2D table, same in all 44 cals
	fcb	$10
	fcb	$FF,$A8,$8B,$7A,$6E,$64,$5B,$54,$4D,$46,$3F,$37,$30,$27,$1C,$0B,$00

k_38D3:	; same in all 44 cals
	fcb	$6B                                                             ; 38D3

k_38D4:	; same in all 44 cals
	fcb	$78                                                             ; 38D4

tbl_38D5: ; same in all 44 cals
	fcb	$A2                                                             ; 38D5

kw_TFT_start_capture_time_38D6: ; 2 values in 44 cals, differs in: NA TCM (range $0000-$0096)
;   analysis: run time before capturing start trans temp
	fdb	$0096

k_TFT_default_38D8: ; 2 values in 44 cals, differs in: NA TCM (range $00-$F0)
;   analysis: $F0
	fcb	$F0                                                             ; 38D8

tbl_TFT_substitute_38D9: ; 4 values in 44 cals, differs in: ALT NA TCM
;   analysis: 13 bytes: defaults/offsets/ECT windows/run-time for failed trans temp sensor
	fcb	$F0,$F0,$F0,$F0,$02,$0D,$0D,$35,$35,$0D,$C8,$00,$01             ; 38D9

tbl_engspd_tracking_gains_38E6: ; same in all 44 cals
;   analysis: 4 words gains for engine speed tracking filter
	fcb	$00,$FD,$04,$74,$03,$74,$00,$28,$01,$35,$06,$75,$03,$F8,$00,$28 ; 38E6

k_38F6:	; 2 values in 44 cals, differs in: TA (range $28-$50)
	fcb	$28                                                             ; 38F6

k_38F7:	; 2 values in 44 cals, differs in: TA (range $00-$30)
	fcb	$00                                                             ; 38F7

k_38F8:	; 4 values in 44 cals, differs in: TA (range $00-$50)
	fcb	$00                                                             ; 38F8

k_38F9:	; 2 values in 44 cals, differs in: TA (range $00-$6F)
	fcb	$00                                                             ; 38F9

k_38FA:	; 2 values in 44 cals, differs in: TA (range $00-$93)
	fcb	$00                                                             ; 38FA

k_38FB:	; 2 values in 44 cals, differs in: TA (range $00-$03)
	fcb	$00                                                             ; 38FB

k_38FC:	; 2 values in 44 cals, differs in: TA (range $00-$01)
	fcb	$00                                                             ; 38FC

k_38FD:	; 2 values in 44 cals, differs in: TA (range $00-$23)
	fcb	$00                                                             ; 38FD

k_38FE:	; same in all 44 cals
	fcb	$00                                                             ; 38FE

k_38FF:	; same in all 44 cals
	fcb	$00                                                             ; 38FF

k_3900:	; same in all 44 cals
	fcb	$00                                                             ; 3900

k_3901:	; same in all 44 cals
	fcb	$00                                                             ; 3901

k_3902:	; same in all 44 cals
	fcb	$00                                                             ; 3902

k_3903:	; same in all 44 cals
	fcb	$28                                                             ; 3903

k_3904:	; same in all 44 cals
	fcb	$28                                                             ; 3904

k_3905:	; same in all 44 cals
	fcb	$28                                                             ; 3905

k_3906:	; same in all 44 cals
	fcb	$28,$80                                                         ; 3906

k_3908:	; 2 values in 44 cals, differs in: TCM (range $0C-$14)
	fcb	$14                                                             ; 3908

kw_3909: ; same in all 44 cals
	fdb	$0320

k_390B:	; same in all 44 cals
	fcb	$50                                                             ; 390B

k_390C:	; same in all 44 cals
	fcb	$82                                                             ; 390C

k_390D:	; same in all 44 cals
	fcb	$82                                                             ; 390D

k_390E:	; 2 values in 44 cals, differs in: ALT NA TCM (range $5A-$A0)
	fcb	$5A                                                             ; 390E

k_390F:	; 3 values in 44 cals, differs in: ALT NA TCM (range $00-$6E)
	fcb	$32                                                             ; 390F

kw_3910: ; 2 values in 44 cals, differs in: NA TCM
	fdb	$5DC0
	fcb	$00                                                             ; 3912

tbl_3913: ; same in all 44 cals
	fcb	$FF                                                             ; 3913

tbl_3914: ; same in all 44 cals
	fcb	$5A                                                             ; 3914

tbl_3915: ; same in all 44 cals
	fcb	$46                                                             ; 3915

tbl_3916: ; same in all 44 cals
	fcb	$FF                                                             ; 3916

tbl_3917: ; 2 values in 44 cals, differs in: TCM (range $78-$FF)
	fcb	$78                                                             ; 3917

tbl_3918: ; same in all 44 cals
	fcb	$FF                                                             ; 3918

tbl_3919: ; 2 values in 44 cals, differs in: TCM (range $78-$FF)
	fcb	$78                                                             ; 3919

tbl_391A: ; same in all 44 cals
	fcb	$80                                                             ; 391A

tbl_391B: ; same in all 44 cals
	fcb	$80                                                             ; 391B

tbl_391C: ; same in all 44 cals
	fcb	$80                                                             ; 391C

tbl_391D: ; same in all 44 cals
	fcb	$80                                                             ; 391D

tbl_391E: ; same in all 44 cals
	fcb	$80                                                             ; 391E

tbl_391F: ; same in all 44 cals
	fcb	$80                                                             ; 391F

tbl_3920: ; 5 values in 44 cals, differs in: ALT EGR NA TA TCM (range $2A-$32)
	fcb	$32                                                             ; 3920

tbl_3921: ; 3 values in 44 cals, differs in: NA TA TCM (range $4C-$5A)
	fcb	$5A                                                             ; 3921

tbl_3922: ; 2 values in 44 cals, differs in: NA TCM (range $78-$8C)
	fcb	$8C                                                             ; 3922

tbl_3923: ; 4 values in 44 cals, differs in: ALT EGR TA (range $22-$2A)
	fcb	$2A                                                             ; 3923

tbl_3924: ; 3 values in 44 cals, differs in: NA TA TCM (range $48-$52)
	fcb	$50                                                             ; 3924

tbl_3925: ; 2 values in 44 cals, differs in: NA TCM (range $6E-$80)
	fcb	$80                                                             ; 3925

tbl_3926: ; 2 values in 44 cals, differs in: ALT TA (range $2A-$32)
	fcb	$32                                                             ; 3926

tbl_3927: ; 2 values in 44 cals, differs in: ALT NA TA TCM (range $5A-$5E)
	fcb	$5A                                                             ; 3927

tbl_3928: ; 2 values in 44 cals, differs in: ALT NA TA TCM (range $8C-$91)
	fcb	$8C                                                             ; 3928

tbl_3929: ; 3 values in 44 cals, differs in: ALT NA TA TCM (range $26-$2E)
	fcb	$2E                                                             ; 3929

tbl_392A: ; 2 values in 44 cals, differs in: ALT NA TA TCM (range $50-$59)
	fcb	$50                                                             ; 392A

tbl_392B: ; 2 values in 44 cals, differs in: ALT NA TA TCM (range $80-$87)
	fcb	$80                                                             ; 392B

tbl_392C: ; 2 values in 44 cals, differs in: NA TA TCM (range $2A-$32)
	fcb	$2A                                                             ; 392C

tbl_392D: ; 2 values in 44 cals, differs in: TA (range $5A-$62)
	fcb	$62                                                             ; 392D

tbl_392E: ; 2 values in 44 cals, differs in: TA (range $8C-$97)
	fcb	$97                                                             ; 392E

tbl_392F: ; 3 values in 44 cals, differs in: NA TA TCM (range $26-$2E)
	fcb	$26                                                             ; 392F

tbl_3930: ; 2 values in 44 cals, differs in: TA (range $50-$5E)
	fcb	$5E                                                             ; 3930

tbl_3931: ; 2 values in 44 cals, differs in: TA (range $89-$8D)
	fcb	$8D                                                             ; 3931

tbl_3932: ; 2 values in 44 cals, differs in: ALT TCM (range $00-$0C)
	fcb	$0C                                                             ; 3932

tbl_3933: ; 2 values in 44 cals, differs in: ALT TCM (range $00-$40)
	fcb	$40                                                             ; 3933

tbl_3934: ; 2 values in 44 cals, differs in: ALT TCM (range $00-$6E)
	fcb	$6E                                                             ; 3934

tbl_3935: ; 3 values in 44 cals, differs in: ALT TA TCM (range $00-$29)
	fcb	$0A                                                             ; 3935

tbl_3936: ; 2 values in 44 cals, differs in: ALT TCM (range $00-$3C)
	fcb	$3C                                                             ; 3936

tbl_3937: ; 2 values in 44 cals, differs in: ALT TCM (range $00-$69)
	fcb	$69                                                             ; 3937

tbl_3938: ; same in all 44 cals
	fcb	$80                                                             ; 3938

tbl_3939: ; same in all 44 cals
	fcb	$80                                                             ; 3939

tbl_393A: ; same in all 44 cals
	fcb	$80                                                             ; 393A

tbl_393B: ; same in all 44 cals
	fcb	$80                                                             ; 393B

tbl_393C: ; same in all 44 cals
	fcb	$80                                                             ; 393C

tbl_393D: ; same in all 44 cals
	fcb	$80                                                             ; 393D

tbl_393E: ; 5 values in 44 cals, differs in: ALT EGR NA TA TCM (range $0000-$6A40)
	fcb	$67,$20                                                         ; 393E

tbl_3940: ; 2 values in 44 cals, differs in: NA TCM (range $55F0-$6A40)
	fcb	$6A,$40                                                         ; 3940

tbl_3942: ; 2 values in 44 cals, differs in: NA TCM (range $55F0-$6A40)
	fcb	$6A,$40                                                         ; 3942

tbl_3944: ; 2 values in 44 cals, differs in: ALT TCM (range $0000-$6400)
	fcb	$64,$00                                                         ; 3944

tbl_3946: ; 3 values in 44 cals, differs in: ALT NA TCM (range $0000-$6400)
	fcb	$64,$00                                                         ; 3946

tbl_3948: ; 3 values in 44 cals, differs in: ALT NA TCM (range $0000-$6590)
	fcb	$65,$90                                                         ; 3948

tbl_394A: ; 3 values in 44 cals, differs in: NA TA TCM (range $6590-$6A40)
	fcb	$65,$90                                                         ; 394A

tbl_394C: ; same in all 44 cals
	fcb	$6A,$40                                                         ; 394C

tbl_394E: ; same in all 44 cals
	fcb	$6A,$40                                                         ; 394E

tbl_3950: ; 3 values in 44 cals, differs in: ALT NA TA TCM (range $6590-$6A40)
	fcb	$67,$20                                                         ; 3950

tbl_3952: ; same in all 44 cals
	fcb	$6A,$40                                                         ; 3952

tbl_3954: ; same in all 44 cals
	fcb	$6A,$40                                                         ; 3954

tbl_3956: ; 2 values in 44 cals, differs in: NA TA TCM (range $6590-$6A40)
	fcb	$65,$90                                                         ; 3956

tbl_3958: ; same in all 44 cals
	fcb	$6A,$40                                                         ; 3958

tbl_395A: ; same in all 44 cals
	fcb	$6A,$40                                                         ; 395A

tbl_395C: ; 2 values in 44 cals, differs in: NA TCM (range $55F0-$8000)
	fcb	$80,$00                                                         ; 395C

tbl_395E: ; same in all 44 cals
	fcb	$80,$00                                                         ; 395E

tbl_3960: ; same in all 44 cals
	fcb	$80,$00                                                         ; 3960

tbl_3962: ; same in all 44 cals
	fcb	$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80 ; 3962
	fcb	$80                                                             ; 3972

tbl_3973: ; same in all 44 cals
	fcb	$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80 ; 3973
	fcb	$80                                                             ; 3983

tbl_3984: ; same in all 44 cals
	fcb	$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80 ; 3984
	fcb	$80                                                             ; 3994

tbl_3995: ; same in all 44 cals
	fcb	$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80 ; 3995
	fcb	$80                                                             ; 39A5

tbl_39A6: ; same in all 44 cals
	fcb	$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80 ; 39A6
	fcb	$80                                                             ; 39B6

tbl_39B7: ; same in all 44 cals
	fcb	$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80 ; 39B7
	fcb	$80                                                             ; 39C7

tbl_39C8: ; same in all 44 cals
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 39C8
	fcb	$00                                                             ; 39D8

tbl_39D9: ; same in all 44 cals
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 39D9
	fcb	$00                                                             ; 39E9

tbl_39EA: ; 5 values in 44 cals, differs in: EGR NA TA TCM
	fcb	$13,$13,$14,$15,$1B,$20,$24,$29,$2C,$2E,$30,$30,$30,$30,$30,$30 ; 39EA
	fcb	$30                                                             ; 39FA

tbl_39FB: ; 5 values in 44 cals, differs in: ALT EGR NA TA TCM
	fcb	$1E,$1E,$20,$26,$35,$3F,$42,$48,$4D,$56,$58,$59,$5A,$5A,$5A,$5A ; 39FB
	fcb	$5A                                                             ; 3A0B

tbl_3A0C: ; 5 values in 44 cals, differs in: NA TCM
	fcb	$37,$37,$37,$37,$4A,$50,$58,$66,$7C,$8C,$8E,$8E,$8E,$8E,$8E,$8E ; 3A0C
	fcb	$8E                                                             ; 3A1C

tbl_3A1D: ; 3 values in 44 cals, differs in: NA TA TCM
	fcb	$11,$11,$11,$11,$11,$11,$11,$11,$11,$11,$14,$1A,$21,$24,$24,$24 ; 3A1D
	fcb	$24                                                             ; 3A2D

tbl_3A2E: ; 4 values in 44 cals, differs in: NA TA TCM
	fcb	$1C,$1C,$1C,$1C,$1C,$1C,$1C,$22,$2B,$36,$40,$48,$50,$50,$50,$50 ; 3A2E
	fcb	$50                                                             ; 3A3E

tbl_3A3F: ; 4 values in 44 cals, differs in: ALT NA TA TCM
	fcb	$32,$32,$32,$32,$32,$32,$38,$42,$50,$5E,$69,$72,$7A,$80,$80,$80 ; 3A3F
	fcb	$80                                                             ; 3A4F

tbl_3A50: ; 5 values in 44 cals, differs in: EGR NA TA TCM
	fcb	$13,$13,$14,$15,$1B,$20,$24,$29,$2C,$2E,$30,$30,$30,$30,$30,$30 ; 3A50
	fcb	$30                                                             ; 3A60

tbl_3A61: ; 5 values in 44 cals, differs in: ALT EGR NA TA TCM
	fcb	$1E,$1E,$20,$26,$35,$3F,$42,$48,$4D,$56,$58,$59,$5A,$5A,$5A,$5A ; 3A61
	fcb	$5A                                                             ; 3A71

tbl_3A72: ; 5 values in 44 cals, differs in: EGR NA
	fcb	$37,$37,$37,$37,$4A,$50,$58,$66,$7C,$8C,$8E,$8E,$8E,$8E,$8E,$8E ; 3A72
	fcb	$8E                                                             ; 3A82

tbl_3A83: ; 3 values in 44 cals, differs in: EGR NA
	fcb	$11,$11,$11,$11,$11,$11,$11,$11,$11,$11,$14,$1A,$21,$24,$24,$24 ; 3A83
	fcb	$24                                                             ; 3A93

tbl_3A94: ; 5 values in 44 cals, differs in: EGR NA TA
	fcb	$1C,$1C,$1C,$1C,$1C,$1C,$1C,$22,$2B,$36,$40,$48,$50,$50,$50,$50 ; 3A94
	fcb	$50                                                             ; 3AA4

tbl_3AA5: ; 5 values in 44 cals, differs in: ALT EGR NA TA TCM
	fcb	$32,$32,$32,$32,$32,$32,$38,$38,$42,$5E,$69,$72,$7A,$7A,$80,$80 ; 3AA5
	fcb	$80                                                             ; 3AB5

tbl_3AB6: ; same in all 44 cals
	fcb	$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80 ; 3AB6
	fcb	$80                                                             ; 3AC6

tbl_3AC7: ; same in all 44 cals
	fcb	$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80 ; 3AC7
	fcb	$80                                                             ; 3AD7

tbl_3AD8: ; same in all 44 cals
	fcb	$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80 ; 3AD8
	fcb	$80                                                             ; 3AE8

tbl_3AE9: ; same in all 44 cals
	fcb	$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80 ; 3AE9
	fcb	$80                                                             ; 3AF9

tbl_3AFA: ; same in all 44 cals
	fcb	$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80 ; 3AFA
	fcb	$80                                                             ; 3B0A

tbl_3B0B: ; same in all 44 cals
	fcb	$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80 ; 3B0B
	fcb	$80                                                             ; 3B1B

k_3B1C:	; same in all 44 cals
	fcb	$14                                                             ; 3B1C

k_3B1D:	; same in all 44 cals
	fcb	$14                                                             ; 3B1D

k_3B1E:	; same in all 44 cals
	fcb	$14                                                             ; 3B1E

tbl_3B1F: ; same in all 44 cals
;   analysis: per shift ticks before adapt
	fcb	$28,$28,$28                                                     ; 3B1F

tbl_3B22: ; same in all 44 cals
;   analysis: per shift word, 20 ticks
	fcb	$00,$14,$00,$14,$00,$14                                         ; 3B22

tbl_shift_adapt_deadband_3B28: ; same in all 44 cals
;   analysis: per shift |error| deadband
	fcb	$02,$02,$02                                                     ; 3B28

tbl_shift_adapt_min_3B2B: ; 2 values in 44 cals, differs in: TA
;   analysis: signed cell lower limit ($80 = -128)
	fcb	$80,$80,$80                                                     ; 3B2B

tbl_shift_adapt_max_3B2E: ; 2 values in 44 cals, differs in: TA (range $0000-$7F7F)
;   analysis: signed cell upper limit
	fcb	$7F,$7F                                                         ; 3B2E

tbl_kickdown_hold_time_3B30: ; 2 values in 44 cals, differs in: TA
;   analysis: per gear
	fcb	$7F,$F0,$F0,$F0                                                 ; 3B30

tbl_3B34: ; 5 values in 44 cals, differs in: ALT EGR NA TA TCM
	fcb	$A0,$A0,$A0,$80,$70,$60,$60,$60,$60,$60,$60,$60,$60,$60,$60,$60 ; 3B34
	fcb	$60                                                             ; 3B44

tbl_3B45: ; 4 values in 44 cals, differs in: ALT NA TA TCM
	fcb	$70,$70,$64,$64,$64,$64,$64,$64,$64,$64,$64,$64,$64,$64,$64,$64 ; 3B45
	fcb	$64                                                             ; 3B55

tbl_3B56: ; same in all 44 cals
	fcb	$30,$30,$30,$30,$30,$30,$30,$30,$30,$30,$30,$30,$30,$30,$30,$30 ; 3B56
	fcb	$30                                                             ; 3B66

tcurve_3B67: ; CV table, 4 values in 44 cals, differs in: ALT NA TA TCM
;   analysis: 16-pt delay adder vs time in 1st (80 ticks/pt)
	fcb	$00,$00,$00,$10,$14,$16,$18,$1C,$20,$24,$2A,$32,$39,$40,$46,$50 ; 3B67
	fcb	$50                                                             ; 3B77

tbl_max_gear_by_range_3B78: ; 2 values in 44 cals, differs in: TCM
;   analysis: max desired gear per manual range
	fcb	$02,$02,$02,$03                                                 ; 3B78

k_line_press_floor_gear_mask_3B7C: ; 2 values in 44 cals, differs in: ALT NA TCM (range $03-$0E)
;   analysis: per-gear enable bits (b0..b3) for the speed floor
	fcb	$0E                                                             ; 3B7C

tbl17_TRANS_temp_3B7D: ; 17 table, same in all 44 cals
	fcb	$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80

tbl_3B8E: ; same in all 44 cals
;   analysis: per-state base pressure gains (pointed to by d_C2EE)
	fcb	$74                                                             ; 3B8E

tbl_3B8F: ; 4 values in 44 cals, differs in: ALT NA TA TCM (range $3B-$5A)
	fcb	$4D                                                             ; 3B8F

tbl_3B90: ; 3 values in 44 cals, differs in: ALT NA TA TCM (range $31-$48)
	fcb	$38                                                             ; 3B90

tbl_3B91: ; 2 values in 44 cals, differs in: ALT NA TA TCM (range $4D-$51)
	fcb	$4D                                                             ; 3B91

tbl_3B92: ; 3 values in 44 cals, differs in: ALT NA TA TCM (range $21-$34)
	fcb	$34                                                             ; 3B92

tbl_3B93: ; 2 values in 44 cals, differs in: ALT NA TA TCM (range $4D-$51)
	fcb	$4D                                                             ; 3B93

tbl_3B94: ; 3 values in 44 cals, differs in: ALT NA TA TCM (range $1E-$34)
	fcb	$34                                                             ; 3B94

tbl_3B95: ; 2 values in 44 cals, differs in: ALT NA TA TCM (range $4D-$51)
	fcb	$4D                                                             ; 3B95

tbl_3B96: ; 4 values in 44 cals, differs in: ALT NA TA TCM (range $00-$45)
;   analysis: per-state signed offsets (d_C2FE)
	fcb	$00                                                             ; 3B96

tbl_3B97: ; 4 values in 44 cals, differs in: ALT NA TA TCM (range $00-$53)
	fcb	$00                                                             ; 3B97

tbl_3B98: ; 2 values in 44 cals, differs in: ALT NA TCM (range $12-$42)
	fcb	$42                                                             ; 3B98

tbl_3B99: ; 3 values in 44 cals, differs in: ALT NA TA TCM (range $12-$32)
	fcb	$32                                                             ; 3B99

tbl_3B9A: ; 2 values in 44 cals, differs in: ALT NA TA TCM (range $2A-$32)
	fcb	$32                                                             ; 3B9A

tbl_3B9B: ; 2 values in 44 cals, differs in: ALT NA TA TCM (range $2A-$32)
	fcb	$32                                                             ; 3B9B

tbl_3B9C: ; 2 values in 44 cals, differs in: ALT NA TA TCM (range $2A-$32)
	fcb	$32                                                             ; 3B9C

tbl_3B9D: ; 2 values in 44 cals, differs in: ALT NA TA TCM (range $2A-$32)
	fcb	$32                                                             ; 3B9D

tbl_3B9E: ; 3 values in 44 cals, differs in: ALT NA TA TCM
	fcb	$40,$40,$40,$40,$40,$40,$3E,$3C,$3A,$3A,$3A,$3A,$3A,$3A,$3A,$3A ; 3B9E
	fcb	$3A                                                             ; 3BAE

tbl_3BAF: ; 2 values in 44 cals, differs in: ALT NA TA TCM
	fcb	$2C,$2C,$2C,$2C,$2C,$2C,$2C,$2C,$2C,$2C,$2C,$28,$28,$28,$28,$28 ; 3BAF
	fcb	$28                                                             ; 3BBF

k_3BC0:	; same in all 44 cals
;   analysis: divisor for $1B25 conversion (forward)
	fcb	$5A                                                             ; 3BC0

k_3BC1:	; same in all 44 cals
;   analysis: divisor, Reverse
	fcb	$8D                                                             ; 3BC1

k_3BC2:	; same in all 44 cals
;   analysis: offset subtracted before conversion (forward)
	fcb	$28                                                             ; 3BC2

k_3BC3:	; same in all 44 cals
;   analysis: offset, Reverse
	fcb	$3F                                                             ; 3BC3

k_line_press_max_3BC4: ; same in all 44 cals
;   analysis: $5A: max/failsafe line_pressure_desired
	fcb	$5A,$0F,$A0,$00,$50                                             ; 3BC4

k_3BC9:	; same in all 44 cals
	fcb	$14                                                             ; 3BC9

kw_3BCA: ; 3 values in 44 cals, differs in: NA TA TCM (range $0000-$0060)
	fdb	$0050

kw_3BCC: ; 3 values in 44 cals, differs in: ALT NA TA TCM (range $0000-$0FA0)
	fdb	$0050

tbl_3BCE: ; same in all 44 cals
;   analysis: slip limit vs trans temp (offset binary)
	fcb	$8F,$A0,$8F,$A0,$8F,$A0,$8F,$A0,$8F,$A0,$8F,$A0,$8F,$A0,$8F,$A0 ; 3BCE
	fcb	$8F,$A0,$8F,$A0,$8F,$A0,$8F,$A0,$8F,$A0,$8F,$A0                 ; 3BDE

kw_3BEA: ; same in all 44 cals
	fcb	$8F,$A0,$FE,$70                                                 ; 3BEA

k_3BEE:	; same in all 44 cals
;   analysis: limit for garage measured value / target+cell
	fcb	$1E,$00,$00,$00,$00,$14,$14,$28,$28,$28,$50,$50,$50,$50,$50,$50 ; 3BEE
	fcb	$00,$00,$00,$00,$0A,$14,$28,$28,$50,$96,$96,$96,$96,$96,$96,$28 ; 3BFE
	fcb	$28,$28,$28,$00,$00,$00,$00,$00,$00,$00,$00,$00                 ; 3C0E

k_3C1A:	; same in all 44 cals
	fcb	$12                                                             ; 3C1A

kw_3C1B: ; 2 values in 44 cals, differs in: ALT (range $0000-$0028)
	fdb	$0000

tblOfs3D_TRANS_load_3C1D: ; O3 table, 2 values in 44 cals, differs in: ALT NA TCM
	fcb	$00,$00,$05,$00,$05,$07,$0A,$0F,$28,$28,$28,$28,$28,$5A,$5A,$5A ; 3C1D
	fcb	$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A ; 3C2D
	fcb	$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A ; 3C3D
	fcb	$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A ; 3C4D
	fcb	$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$00,$00 ; 3C5D
	fcb	$00,$00,$00,$00,$00,$00,$00,$00                                 ; 3C6D

tbl_3C75: ; 3 values in 44 cals, differs in: ALT NA TA TCM
	fcb	$00,$00,$0F,$19,$19,$19,$19,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A ; 3C75
	fcb	$0A,$0A,$19,$19,$19,$19,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A ; 3C85
	fcb	$0A,$19,$19,$19,$19,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A ; 3C95
	fcb	$19,$19,$19,$19,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$19 ; 3CA5
	fcb	$19,$19,$19,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$19,$19 ; 3CB5
	fcb	$19,$19,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$19,$19,$19 ; 3CC5
	fcb	$19,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$1E,$1E,$1E,$1E ; 3CD5
	fcb	$1E,$1E,$1E,$1E,$1E,$1E,$1E,$1E,$1E,$1E,$1E,$41,$41,$41,$41,$41 ; 3CE5
	fcb	$41,$41,$41,$41,$41,$41,$41,$41,$41,$41,$44,$44,$44,$44,$44,$44 ; 3CF5
	fcb	$44,$44,$44,$44,$44,$44,$44,$44,$44,$48,$48,$48,$48,$48,$48,$48 ; 3D05
	fcb	$48,$48,$48,$48,$48,$48,$48,$48,$4B,$4B,$4B,$4B,$4B,$4B,$4B,$4B ; 3D15
	fcb	$4B,$4B,$4B,$4B,$4B,$4B,$4B,$4E,$4E,$4E,$4E,$4E,$4E,$4E,$4E,$4E ; 3D25
	fcb	$4E,$4E,$4E,$4E,$4E,$4E,$51,$51,$51,$51,$51,$51,$51,$51,$51,$51 ; 3D35
	fcb	$51,$51,$51,$51,$51,$54,$54,$54,$54,$54,$54,$54,$54,$54,$54,$54 ; 3D45
	fcb	$54,$54,$54,$54,$57,$57,$57,$57,$57,$57,$57,$57,$57,$57,$57,$57 ; 3D55
	fcb	$57,$57,$57,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A ; 3D65
	fcb	$5A,$5A                                                         ; 3D75

tbl_3D77: ; 2 values in 44 cals, differs in: TCM
	fcb	$00,$00,$0F,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01 ; 3D77
	fcb	$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01 ; 3D87
	fcb	$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01 ; 3D97
	fcb	$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01 ; 3DA7
	fcb	$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01 ; 3DB7
	fcb	$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01 ; 3DC7
	fcb	$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$1E,$1E,$1E,$1E ; 3DD7
	fcb	$1E,$1E,$1E,$1E,$1E,$1E,$1E,$1E,$1E,$1E,$1E,$41,$41,$41,$41,$41 ; 3DE7
	fcb	$41,$41,$41,$41,$41,$41,$41,$41,$41,$41,$44,$44,$44,$44,$44,$44 ; 3DF7
	fcb	$44,$44,$44,$44,$44,$44,$44,$44,$44,$48,$48,$48,$48,$48,$48,$48 ; 3E07
	fcb	$48,$48,$48,$48,$48,$48,$48,$48,$4B,$4B,$4B,$4B,$4B,$4B,$4B,$4B ; 3E17
	fcb	$4B,$4B,$4B,$4B,$4B,$4B,$4B,$4E,$4E,$4E,$4E,$4E,$4E,$4E,$4E,$4E ; 3E27
	fcb	$4E,$4E,$4E,$4E,$4E,$4E,$51,$51,$51,$51,$51,$51,$51,$51,$51,$51 ; 3E37
	fcb	$51,$51,$51,$51,$51,$54,$54,$54,$54,$54,$54,$54,$54,$54,$54,$54 ; 3E47
	fcb	$54,$54,$54,$54,$57,$57,$57,$57,$57,$57,$57,$57,$57,$57,$57,$57 ; 3E57
	fcb	$57,$57,$57,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A ; 3E67
	fcb	$5A,$5A                                                         ; 3E77

k_garage_adapt_temp_min_3E79: ; same in all 44 cals
;   analysis: trans temp window for garage adapt
	fcb	$0A                                                             ; 3E79

k_garage_adapt_temp_max_3E7A: ; same in all 44 cals
	fcb	$FD                                                             ; 3E7A

kw_garage_adapt_rpm_min_3E7B: ; same in all 44 cals
;   analysis: engine_speed_filtered window
	fdb	$0C80

kw_garage_adapt_rpm_max_3E7D: ; same in all 44 cals
	fdb	$2260

k_3E7F:	; same in all 44 cals
	fcb	$A6                                                             ; 3E7F

tbl_3E80: ; same in all 44 cals
	fcb	$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80 ; 3E80
	fcb	$80                                                             ; 3E90

tbl_3E91: ; same in all 44 cals
	fcb	$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80 ; 3E91
	fcb	$80                                                             ; 3EA1

tbl_garage_adapt_nbr_weights_3EA2: ; same in all 44 cals
;   analysis: 5 neighbour weights (/256)
	fcb	$80,$80,$80,$80,$80                                             ; 3EA2

k_line_adapt_min_gear_time_3EA7: ; 3 values in 44 cals, differs in: ALT NA TCM (range $05-$A0)
;   analysis: gear must be held this long before adapting
	fcb	$50                                                             ; 3EA7

k_3EA8:	; 3 values in 44 cals, differs in: ALT TA TCM (range $08-$FF)
;   analysis: VSS must exceed (N*0.5 mph?)
	fcb	$08                                                             ; 3EA8

k_line_adapt_min_load_3EA9: ; 4 values in 44 cals, differs in: ALT NA TA TCM (range $0F-$FF)
;   analysis: trans load must exceed
	fcb	$10                                                             ; 3EA9

k_line_adapt_hold_time_3EAA: ; 2 values in 44 cals, differs in: ALT TCM (range $14-$28)
;   analysis: passes between adapt steps
	fcb	$14                                                             ; 3EAA

kw_line_adapt_slip_high_3EAB: ; same in all 44 cals
;   analysis: slip rpm above which pressure is raised (400)
	fdb	$0190

kw_line_adapt_slip_low_3EAD: ; same in all 44 cals
;   analysis: slip rpm below which pressure is lowered (160)
	fdb	$00A0

kw_3EAF: ; 2 values in 44 cals, differs in: ALT TCM (range $0960-$7FFF)
	fdb	$7FFF

kw_3EB1: ; 2 values in 44 cals, differs in: ALT TCM (range $0140-$7FFF)
	fdb	$7FFF

k_3EB3:	; same in all 44 cals
	fcb	$00                                                             ; 3EB3

k_3EB4:	; same in all 44 cals
	fcb	$40                                                             ; 3EB4

tbl_line_adapt_dec_rate_3EB5: ; 2 values in 44 cals, differs in: ALT TCM
;   analysis: per-cell integrator decrement
	fcb	$05,$05,$03,$01,$01,$01,$01,$01                                 ; 3EB5

tcurve_line_adapt_inc_vs_slip_3EBD: ; CV table, 2 values in 44 cals, differs in: ALT TCM
;   analysis: integrator increment vs slip
	fcb	$00,$00,$01,$02,$03,$04,$05,$06,$07,$08,$09,$0A,$0B,$0C,$0C,$0C ; 3EBD

k_3ECD:	; 2 values in 44 cals, differs in: ALT TCM (range $0C-$40)
	fcb	$0C                                                             ; 3ECD

k_3ECE:	; same in all 44 cals
	fcb	$7F                                                             ; 3ECE

k_3ECF:	; same in all 44 cals
	fcb	$81                                                             ; 3ECF

tbl_line_adapt_step_up_3ED0: ; 3 values in 44 cals, differs in: ALT NA TA TCM
;   analysis: per-cell learned increase step
	fcb	$0A,$0A,$0A,$0A,$0A,$0A,$00,$00                                 ; 3ED0

tbl_line_adapt_step_down_3ED8: ; same in all 44 cals
;   analysis: per-cell learned decrease step
	fcb	$01,$01,$01,$01,$01,$01,$01,$01                                 ; 3ED8

k_3EE0:	; 2 values in 44 cals, differs in: ALT NA TCM (range $0A-$26)
	fcb	$26                                                             ; 3EE0

k_3EE1:	; 3 values in 44 cals, differs in: ALT NA TCM (range $08-$26)
	fcb	$08                                                             ; 3EE1

k_3EE2:	; 3 values in 44 cals, differs in: ALT NA TCM (range $08-$26)
	fcb	$08                                                             ; 3EE2

k_3EE3:	; 2 values in 44 cals, differs in: ALT NA TCM (range $00-$40)
	fcb	$00                                                             ; 3EE3

tbl_3EE4: ; 7 values in 44 cals, differs in: ALT EGR NA TA TCM
	fcb	$00,$00,$11,$88,$83,$7D,$7B,$7C,$7D,$7E,$7F,$80,$80,$80,$80,$80 ; 3EE4
	fcb	$80,$80,$80,$8A,$87,$83,$7D,$7B,$7C,$7D,$7E,$7F,$80,$80,$80,$80 ; 3EF4
	fcb	$80,$80,$80,$80,$8A,$86,$80,$7B,$79,$7A,$7C,$7D,$7F,$80,$80,$80 ; 3F04
	fcb	$80,$80,$80,$80,$80,$8A,$85,$7F,$79,$79,$7A,$7C,$7D,$7F,$80,$80 ; 3F14
	fcb	$80,$80,$80,$80,$80,$80,$8A,$84,$7E,$79,$79,$7A,$7C,$7D,$7F,$80 ; 3F24
	fcb	$80,$80,$80,$80,$80,$80,$80,$8A,$84,$7E,$79,$79,$7A,$7C,$7D,$7F ; 3F34
	fcb	$80,$80,$80,$80,$80,$80,$80,$80,$8A                             ; 3F44

tbl_3F4D: ; 6 values in 44 cals, differs in: ALT NA TA TCM
	fcb	$00,$00,$11,$9E,$8E,$88,$87,$86,$85,$83,$81,$80,$80,$80,$80,$80 ; 3F4D
	fcb	$80,$80,$80,$8A,$9E,$8E,$8A,$88,$86,$85,$83,$80,$80,$80,$80,$80 ; 3F5D
	fcb	$80,$80,$80,$80,$8A,$9A,$8C,$8A,$88,$86,$85,$83,$81,$80,$80,$80 ; 3F6D
	fcb	$80,$80,$80,$80,$80,$8A,$96,$8A,$88,$87,$86,$85,$83,$81,$80,$80 ; 3F7D
	fcb	$80,$80,$80,$80,$80,$80,$8A,$96,$89,$88,$86,$85,$83,$81,$80,$80 ; 3F8D
	fcb	$80,$80,$80,$80,$80,$80,$80,$8A,$96,$89,$88,$86,$85,$83,$81,$80 ; 3F9D
	fcb	$80,$80,$80,$80,$80,$80,$80,$80,$8A                             ; 3FAD

tbl_3FB6: ; 6 values in 44 cals, differs in: ALT NA TA TCM
	fcb	$00,$00,$11,$96,$8E,$86,$85,$84,$83,$81,$80,$80,$80,$80,$80,$80 ; 3FB6
	fcb	$80,$80,$80,$8A,$96,$8E,$86,$85,$84,$83,$81,$80,$80,$80,$80,$80 ; 3FC6
	fcb	$80,$80,$80,$80,$8A,$96,$8E,$86,$85,$84,$83,$81,$80,$80,$80,$80 ; 3FD6
	fcb	$80,$80,$80,$80,$80,$8A,$96,$8E,$86,$85,$84,$83,$81,$80,$80,$80 ; 3FE6
	fcb	$80,$80,$80,$80,$80,$80,$8A,$96,$8E,$86                         ; 3FF6

tbl_4000: ; 5 values in 44 cals, differs in: ALT NA TA TCM
	fcb	$85,$84,$83,$81,$80,$80,$80,$80,$80,$80,$80,$80,$80,$8A,$96,$8E ; 4000
	fcb	$86,$80,$7D,$7E,$7F,$80,$80,$80,$80,$80,$80,$80,$80,$80,$8A     ; 4010

tbl_401F: ; 9 values in 44 cals, differs in: ALT NA TA TCM
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$06,$08,$0A,$0B,$0B,$0D ; 401F
	fcb	$0F,$11,$13,$15,$17,$19,$1B,$1D,$1F,$21,$23,$27,$27,$29,$2B,$2D ; 402F
	fcb	$41                                                             ; 403F

tbl_4040: ; 10 values in 44 cals, differs in: ALT NA TA TCM
	fcb	$00,$00,$00,$00,$00,$00,$01,$04,$06,$07,$0A,$0D,$10,$12,$14,$15 ; 4040
	fcb	$16,$18,$1A,$1C,$1D,$1E,$20,$22,$24,$26,$28,$2A,$2C,$41,$39,$45 ; 4050
	fcb	$50                                                             ; 4060

tbl_4061: ; 6 values in 44 cals, differs in: ALT NA TA TCM
	fcb	$00,$03,$05,$06,$07,$09,$0B,$0D,$0F,$10,$11,$12,$14,$16,$18,$1A ; 4061
	fcb	$1D,$20,$21,$22,$24,$25,$27,$29,$2B,$2D,$2F,$32,$34,$36,$38,$3A ; 4071
	fcb	$3C                                                             ; 4081

tbl_4082: ; same in all 44 cals
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 4082
	fcb	$00                                                             ; 4092

tbl_4093: ; same in all 44 cals
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 4093
	fcb	$00                                                             ; 40A3

tbl_40A4: ; same in all 44 cals
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 40A4
	fcb	$00                                                             ; 40B4

tbl_40B5: ; same in all 44 cals
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 40B5
	fcb	$00                                                             ; 40C5

tbl_40C6: ; same in all 44 cals
	fcb	$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80 ; 40C6
	fcb	$80                                                             ; 40D6

tbl_40D7: ; same in all 44 cals
	fcb	$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80 ; 40D7
	fcb	$80                                                             ; 40E7

tbl_40E8: ; same in all 44 cals
	fcb	$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80 ; 40E8
	fcb	$80                                                             ; 40F8

tbl_40F9: ; same in all 44 cals
	fcb	$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80 ; 40F9
	fcb	$80                                                             ; 4109

tbl_410A: ; 2 values in 44 cals, differs in: ALT NA TCM
	fcb	$80,$80,$80,$AC,$A1,$9A,$96,$96,$96,$96,$96,$96,$96,$96,$96,$96 ; 410A
	fcb	$96                                                             ; 411A

tbl_411B: ; 2 values in 44 cals, differs in: ALT NA TCM
	fcb	$80,$80,$80,$CD,$C2,$B7,$A1,$9F,$9C,$9C,$96,$96,$96,$96,$96,$96 ; 411B
	fcb	$96                                                             ; 412B

tbl_412C: ; 2 values in 44 cals, differs in: ALT NA TCM
	fcb	$80,$80,$80,$AC,$AC,$AC,$AC,$AC,$AC,$AC,$AC,$AC,$AC,$AC,$AC,$AC ; 412C
	fcb	$AC                                                             ; 413C

tbl_413D: ; 2 values in 44 cals, differs in: ALT
	fcb	$00,$18,$31,$49,$61,$74,$84,$97,$A4,$AD,$B9,$C4,$CA,$CF,$D8,$E7 ; 413D
	fcb	$FF                                                             ; 414D

tbl_414E: ; 2 values in 44 cals, differs in: ALT
	fcb	$00,$11,$23,$34,$45,$52,$5E,$6B,$75,$7C,$84,$8B,$90,$93,$9A,$A5 ; 414E
	fcb	$B0                                                             ; 415E

tbl_415F: ; 2 values in 44 cals, differs in: ALT
	fcb	$00,$11,$22,$32,$43,$50,$5B,$68,$71,$77,$7F,$87,$8B,$8F,$95,$9F ; 415F
	fcb	$AA                                                             ; 416F

tbl_4170: ; 2 values in 44 cals, differs in: ALT
	fcb	$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80 ; 4170
	fcb	$80                                                             ; 4180

tbl_4181: ; 2 values in 44 cals, differs in: ALT NA TA TCM
	fcb	$80,$80,$80,$80,$82,$83,$83,$83,$83,$83,$83,$83,$83,$80,$80,$80 ; 4181
	fcb	$80                                                             ; 4191

tbl_4192: ; 3 values in 44 cals, differs in: ALT NA TA TCM
	fcb	$80,$80,$80,$7E,$7C,$7B,$7A,$7A,$7A,$7A,$7A,$7D,$7A,$80,$80,$80 ; 4192
	fcb	$80                                                             ; 41A2

tbl_41A3: ; 3 values in 44 cals, differs in: ALT NA TA TCM
	fcb	$80,$80,$80,$80,$80,$80,$80,$80,$7A,$7A,$80,$80,$80,$80,$80     ; 41A3

tbl_41B2: ; same in all 44 cals
	fcb	$80,$80                                                         ; 41B2

tbl_41B4: ; same in all 44 cals
	fcb	$4C,$7B,$2D,$C2                                                 ; 41B4

tbl_41B8: ; same in all 44 cals
	fcb	$1F,$5C                                                         ; 41B8

tbl_41BA: ; same in all 44 cals
	fcb	$32,$90,$21,$9A                                                 ; 41BA

tbl_41BE: ; 2 values in 44 cals, differs in: ALT
	fcb	$18,$A4,$30,$F6,$20,$F6                                         ; 41BE

tbl_41C4: ; same in all 44 cals
	fcb	$19,$9A,$F2,$B8,$F8,$30                                         ; 41C4

tbl_41CA: ; same in all 44 cals
	fcb	$FE,$F8,$F2,$B8,$F8,$30,$FF                                     ; 41CA

tbl_41D1: ; 4 values in 44 cals, differs in: ALT NA TCM
	fcb	$D4,$08,$08,$28                                                 ; 41D1

tbl_downshift_timeout_41D5: ; 2 values in 44 cals, differs in: ALT NA TCM
;   analysis: max downshift monitor time per gear
	fcb	$38,$28,$28                                                     ; 41D5

tbl_41D8: ; same in all 44 cals
	fcb	$F2,$B8,$F8,$30,$04,$B0                                         ; 41D8

k_41DE:	; 3 values in 44 cals, differs in: TA TCM (range $00-$E0)
;   analysis: b5 use shift-time case, b6 learn in perf pattern, b7 disable hot case
	fcb	$60                                                             ; 41DE

tbl_41DF: ; 7 values in 44 cals, differs in: ALT NA TA TCM
	fcb	$10,$10,$10,$10,$10,$10,$10,$10,$10,$10,$0F,$0F,$0F,$0F,$0F,$0F ; 41DF
	fcb	$0F                                                             ; 41EF

tbl_41F0: ; 6 values in 44 cals, differs in: ALT NA TA TCM
	fcb	$0F,$0F,$0E,$0E,$0E,$0E,$0E,$0E,$0E,$0E,$0E,$0E,$0E,$0E,$0E,$0E ; 41F0
	fcb	$0E                                                             ; 4200

tbl_4201: ; 4 values in 44 cals, differs in: ALT NA TA TCM
	fcb	$08,$08,$08,$08,$08,$08,$08,$08,$08,$08,$08,$08,$08,$08,$08,$08 ; 4201
	fcb	$08                                                             ; 4211

tbl_4212: ; same in all 44 cals
	fcb	$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80 ; 4212
	fcb	$80                                                             ; 4222

tbl_4223: ; same in all 44 cals
	fcb	$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80 ; 4223
	fcb	$80                                                             ; 4233

tbl17_SHIFTADAPT_trigger_4234: ; same in all 44 cals
	fcb	$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80 ; 4234
	fcb	$80                                                             ; 4244

tbl17_SHIFTADAPT_trigger_4245: ; same in all 44 cals
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF ; 4245
	fcb	$FF                                                             ; 4255

tbl17_SHIFTADAPT_4256: ; same in all 44 cals
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF ; 4256
	fcb	$FF                                                             ; 4266

tbl17_SHIFTADAPT_step_4267: ; 4 values in 44 cals, differs in: ALT NA TCM
	fcb	$98,$94,$90,$8C,$88,$86,$84,$81,$80,$7F,$7C,$7A,$78,$78,$78,$78 ; 4267
	fcb	$78                                                             ; 4277

tbl17_SHIFTADAPT_step_4278: ; 4 values in 44 cals, differs in: ALT NA TCM
	fcb	$98,$94,$90,$8C,$88,$86,$84,$81,$80,$7F,$7C,$7A,$78,$78,$78,$78 ; 4278
	fcb	$78                                                             ; 4288

tbl17_SHIFTADAPT_max_4289: ; 2 values in 44 cals, differs in: ALT TCM
	fcb	$84,$83,$83,$83,$83,$83,$83,$80,$80,$80,$7D,$7D,$7D,$7D,$7D,$7D ; 4289
	fcb	$7C                                                             ; 4299

tbl17_SHIFTADAPT_max_429A: ; 2 values in 44 cals, differs in: TCM
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF ; 429A
	fcb	$FF                                                             ; 42AA

tbl17_SHIFTADAPT_max_42AB: ; 2 values in 44 cals, differs in: TCM
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF ; 42AB
	fcb	$FF                                                             ; 42BB

tbl17_SHIFTADAPT_min_42BC: ; 2 values in 44 cals, differs in: TCM
	fcb	$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80 ; 42BC
	fcb	$80                                                             ; 42CC

tbl17_SHIFTADAPT_min_42CD: ; 2 values in 44 cals, differs in: TCM
	fcb	$30,$30,$30,$30,$30,$30,$30,$30,$30,$30,$30,$30,$30,$30,$30,$30 ; 42CD
	fcb	$30                                                             ; 42DD

tbl17_SHIFTADAPT_min_42DE: ; 2 values in 44 cals, differs in: TCM
	fcb	$30,$30,$30,$30,$30,$30,$30,$30,$30,$30,$30,$30,$30,$30,$30,$30 ; 42DE
	fcb	$30                                                             ; 42EE

tbl_42EF: ; 2 values in 44 cals, differs in: TCM
	fcb	$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80 ; 42EF
	fcb	$80                                                             ; 42FF

k_4300:	; 4 values in 44 cals, differs in: ALT NA TCM (range $6B-$FF)
	fcb	$6B                                                             ; 4300

tbl_4301: ; 4 values in 44 cals, differs in: ALT NA TCM
	fcb	$D5,$50,$50,$50,$50,$50,$50,$26,$26,$64,$FF,$FF                 ; 4301

tbl_430D: ; 2 values in 44 cals, differs in: TCM
	fcb	$AF,$14,$14,$14                                                 ; 430D

tbl_4311: ; 4 values in 44 cals, differs in: ALT NA TA TCM
	fcb	$0A,$44,$44,$44,$06,$06,$06                                     ; 4311

tbl17_TRANS_speed_by_gear_4318: ; 17 table, 7 values in 44 cals, differs in: ALT NA TA TCM
;   analysis: line pressure floor vs output speed
	fcb	$07,$0B,$0B,$0B,$0B,$0B,$0B,$0B,$0B,$31,$3C,$3C,$3C,$3C,$3C,$3C ; 4318

tbl_upshift_timeout_4328: ; 3 values in 44 cals, differs in: ALT TCM
;   analysis: max upshift monitor time per gear
	fcb	$3C,$78,$78,$78,$1C,$1C,$1C,$88,$88,$88,$F4,$F4,$F4,$88,$88,$88 ; 4328

k_4338:	; 2 values in 44 cals, differs in: TCM (range $04-$0C)
	fcb	$0C                                                             ; 4338

k_4339:	; 3 values in 44 cals, differs in: ALT TCM (range $7E-$A7)
	fcb	$92                                                             ; 4339

k_433A:	; same in all 44 cals
	fcb	$2D                                                             ; 433A

tbl_shift_adapt_nbr_weights_433B: ; 2 values in 44 cals, differs in: TCM
;   analysis: 5 triangular weights for cells -2..+2
	fcb	$57,$AB,$FF,$AB                                                 ; 433B

tbl_433F: ; 2 values in 44 cals, differs in: TCM
	fcb	$57,$80,$80,$80                                                 ; 433F

k_4343:	; 2 values in 44 cals, differs in: NA TCM (range $00-$19)
	fcb	$00                                                             ; 4343

tcurve_4344: ; CV table, same in all 44 cals
	fcb	$40,$40,$40,$40,$40,$40,$40,$40,$40,$40,$40,$40,$40,$40,$40,$40 ; 4344
	fcb	$40                                                             ; 4354

k_4355:	; 3 values in 44 cals, differs in: ALT NA TA TCM (range $0A-$5A)
;   analysis: offset for engagement type 1B3F b4/b5
	fcb	$2D                                                             ; 4355

k_4356:	; 2 values in 44 cals, differs in: ALT NA TCM (range $0A-$2D)
	fcb	$2D                                                             ; 4356

k_4357:	; 2 values in 44 cals, differs in: ALT NA TCM (range $0A-$2D)
	fcb	$2D                                                             ; 4357

k_4358:	; 3 values in 44 cals, differs in: ALT NA TCM (range $00-$19)
;   analysis: added when $8A b3
	fcb	$14                                                             ; 4358

k_4359:	; 3 values in 44 cals, differs in: ALT NA TCM (range $00-$EA)
	fcb	$EA                                                             ; 4359

k_435A:	; 4 values in 44 cals, differs in: ALT NA TA TCM (range $00-$2C)
	fcb	$22                                                             ; 435A

k_435B:	; 3 values in 44 cals, differs in: ALT TCM (range $00-$5A)
	fcb	$5A                                                             ; 435B

k_435C:	; 2 values in 44 cals, differs in: ALT NA TCM (range $00-$05)
	fcb	$00                                                             ; 435C

tbl17_TRANS_load_435D: ; 17 table, 2 values in 44 cals, differs in: NA
;   analysis: line pressure vs trans load when $8A b2
	fcb	$46,$47,$48,$49,$4A,$4B,$4E,$50,$51,$52,$53,$54,$55,$56,$57,$58,$5A

kw_436E: ; 2 values in 44 cals, differs in: ALT TCM (range $FF88-$FFB1)
	fdb	$FFB1

k_4370:	; 2 values in 44 cals, differs in: ALT NA TCM (range $00-$0A)
;   analysis: followed by 3 17-pt curves at 4371/4382/4393 used by trans_task_C39E
	fcb	$0A                                                             ; 4370

tbl_4371: ; 3 values in 44 cals, differs in: ALT NA TA TCM
	fcb	$07,$41,$46,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A ; 4371
	fcb	$5A                                                             ; 4381

tbl_4382: ; 2 values in 44 cals, differs in: ALT NA TA TCM
	fcb	$07,$1E,$1E,$1E,$2D,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A ; 4382
	fcb	$5A                                                             ; 4392

tbl_4393: ; 2 values in 44 cals, differs in: ALT NA TA TCM
	fcb	$07,$28,$1E,$19,$19,$19,$19,$19,$19,$19,$1E,$1E,$28,$55,$5A,$5A ; 4393
	fcb	$5A                                                             ; 43A3

TCC_option_bits_43A4: ; 3 values in 44 cals, differs in: TA TCM (range $2B-$EB)
;   analysis: enable bits for TCC inhibit/release reasons
	fcb	$EB                                                             ; 43A4

TCC_option_bits2_43A5: ; 4 values in 44 cals, differs in: ALT TA TCM (range $0C-$1F)
;   analysis: more enable bits (A/C release, $77 timed release, etc.)
	fcb	$1E                                                             ; 43A5

k_TCC_apply_VSS_min_hot_43A6: ; same in all 44 cals
;   analysis: min TCC apply VSS when trans hot ($28 = 20 mph)
	fcb	$28                                                             ; 43A6

k_TCC_release_VSS_hot_43A7: ; same in all 44 cals
;   analysis: hot trans release below this VSS ($28 = 20 mph)
	fcb	$28                                                             ; 43A7

kw_43A8: ; 4 values in 44 cals, differs in: ALT EGR TA TCM (range $8080-$FE70)
;   analysis: signed slip set threshold (-640)
	fdb	$FD80

kw_43AA: ; 3 values in 44 cals, differs in: ALT TA TCM
;   analysis: signed slip clear threshold (+1)
	fdb	$0001
	fcb	$00,$00,$7F,$7C                                                 ; 43AC

k_trans_hot_set_43B0: ; same in all 44 cals
;   analysis: $E5
	fcb	$E5                                                             ; 43B0

k_trans_hot_clear_43B1: ; same in all 44 cals
;   analysis: $DC (hysteresis low point)
	fcb	$DC                                                             ; 43B1

tbl_43B2: ; 3 values in 44 cals, differs in: ALT EGR TCM (range $00-$FF)
	fcb	$FF                                                             ; 43B2

tbl_43B3: ; 2 values in 44 cals, differs in: ALT TCM (range $00-$68)
	fcb	$68                                                             ; 43B3

tbl_43B4: ; 2 values in 44 cals, differs in: ALT TCM (range $00-$68)
	fcb	$68                                                             ; 43B4

tbl_43B5: ; same in all 44 cals
	fcb	$FF                                                             ; 43B5

tbl_43B6: ; 2 values in 44 cals, differs in: NA TCM (range $64-$68)
	fcb	$68                                                             ; 43B6

tbl_43B7: ; 2 values in 44 cals, differs in: NA TCM (range $64-$68)
	fcb	$68                                                             ; 43B7

tbl_43B8: ; 2 values in 44 cals, differs in: EGR NA TCM (range $28-$32)
	fcb	$28                                                             ; 43B8

tbl_43B9: ; 2 values in 44 cals, differs in: EGR NA TCM (range $32-$3C)
	fcb	$32                                                             ; 43B9

tbl_43BA: ; same in all 44 cals
	fcb	$46                                                             ; 43BA

tbl_43BB: ; 2 values in 44 cals, differs in: ALT TA TCM (range $32-$50)
	fcb	$32                                                             ; 43BB

tbl_43BC: ; 2 values in 44 cals, differs in: ALT TA TCM (range $64-$78)
	fcb	$64                                                             ; 43BC

tbl_43BD: ; 2 values in 44 cals, differs in: ALT TA TCM (range $96-$A0)
	fcb	$96                                                             ; 43BD

tbl_43BE: ; same in all 44 cals
	fcb	$80                                                             ; 43BE

tbl_43BF: ; same in all 44 cals
	fcb	$80                                                             ; 43BF

tbl_43C0: ; same in all 44 cals
	fcb	$80                                                             ; 43C0

tbl_43C1: ; same in all 44 cals
	fcb	$80                                                             ; 43C1

tbl_43C2: ; same in all 44 cals
	fcb	$80                                                             ; 43C2

tbl_43C3: ; same in all 44 cals
	fcb	$80                                                             ; 43C3

tbl_43C4: ; 3 values in 44 cals, differs in: ALT EGR TCM (range $00-$FF)
	fcb	$FF                                                             ; 43C4

tbl_43C5: ; 2 values in 44 cals, differs in: ALT TCM (range $00-$5A)
	fcb	$5A                                                             ; 43C5

tbl_43C6: ; 2 values in 44 cals, differs in: ALT TCM (range $00-$5A)
	fcb	$5A                                                             ; 43C6

tbl_43C7: ; 4 values in 44 cals, differs in: ALT EGR TA TCM (range $38-$FF)
	fcb	$FF                                                             ; 43C7

tbl_43C8: ; 3 values in 44 cals, differs in: NA TCM (range $58-$63)
	fcb	$5A                                                             ; 43C8

tbl_43C9: ; 3 values in 44 cals, differs in: NA TCM (range $58-$63)
	fcb	$5A                                                             ; 43C9

tbl_43CA: ; 3 values in 44 cals, differs in: ALT NA TA TCM (range $1E-$2E)
	fcb	$2E                                                             ; 43CA

tbl_43CB: ; 2 values in 44 cals, differs in: ALT NA TA TCM (range $28-$2E)
	fcb	$2E                                                             ; 43CB

tbl_43CC: ; 3 values in 44 cals, differs in: ALT NA TA TCM (range $28-$3C)
	fcb	$2E                                                             ; 43CC

tbl_43CD: ; 3 values in 44 cals, differs in: ALT NA TA TCM (range $28-$46)
	fcb	$2E                                                             ; 43CD

tbl_43CE: ; 3 values in 44 cals, differs in: ALT NA TA TCM (range $28-$6E)
	fcb	$2E                                                             ; 43CE

tbl_TCC_release_VSS_AC_43CF: ; 3 values in 44 cals, differs in: ALT NA TA TCM
;   analysis: per-gear A/C release VSS
	fcb	$2E,$00,$00                                                     ; 43CF

tbl_TCC_apply_VSS_min_AC_43D2: ; same in all 44 cals
;   analysis: per-gear min TCC apply speed with A/C on (all 0)
	fcb	$00,$00,$00,$00                                                 ; 43D2

tbl_TCC_post_shift_delay_43D6: ; same in all 44 cals
;   analysis: post-shift TCC inhibit time per gear (shift event $77.3)
	fcb	$05,$05                                                         ; 43D6

tbl_TCC_post_shift_delay2_43D8: ; 5 values in 44 cals, differs in: ALT NA TA TCM
;   analysis: post-shift TCC inhibit/timed release per gear ($77.0 event)
	fcb	$05,$00,$00,$00                                                 ; 43D8

k_trans_hot_set_43DC: ; 2 values in 44 cals, differs in: TA (range $0F-$FF)
;   analysis: trans temp set threshold for $80.7 ($FF = never)
	fcb	$FF                                                             ; 43DC

k_43DD:	; same in all 44 cals
;   analysis: clear threshold
	fcb	$80,$00                                                         ; 43DD

tbl_43DF: ; same in all 44 cals
	fcb	$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80 ; 43DF
	fcb	$80                                                             ; 43EF

tbl_43F0: ; same in all 44 cals
	fcb	$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80 ; 43F0
	fcb	$80                                                             ; 4400

tbl_4401: ; 2 values in 44 cals, differs in: NA TCM
	fcb	$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80 ; 4401
	fcb	$80                                                             ; 4411

tbl_4412: ; 3 values in 44 cals, differs in: ALT NA TA TCM
	fcb	$2E,$2E,$2E,$2E,$2E,$2E,$2E,$2E,$2E,$2E,$2E,$2E,$2E,$2E,$2E,$2E ; 4412
	fcb	$2E                                                             ; 4422

tbl_4423: ; 3 values in 44 cals, differs in: EGR NA TCM
	fcb	$54,$54,$54,$54,$55,$58,$5B,$61,$63,$63,$63,$63,$63,$63,$63,$63 ; 4423
	fcb	$63                                                             ; 4433

tbl_4434: ; 3 values in 44 cals, differs in: EGR NA TCM
	fcb	$54,$54,$54,$54,$55,$58,$5B,$61,$63,$63,$63,$63,$63,$63,$63,$63 ; 4434
	fcb	$63                                                             ; 4444

tbl_4445: ; 2 values in 44 cals, differs in: NA TCM
	fcb	$2E,$2E,$2E,$2E,$2E,$2E,$2E,$2E,$2E,$2E,$2E,$2E,$2E,$2E,$2E,$2E ; 4445
	fcb	$2E                                                             ; 4455

tbl_4456: ; 3 values in 44 cals, differs in: NA TCM
	fcb	$44,$44,$44,$44,$44,$44,$44,$44,$44,$44,$44,$44,$44,$44,$44,$44 ; 4456
	fcb	$44                                                             ; 4466

tbl_4467: ; 2 values in 44 cals, differs in: NA TCM
	fcb	$54,$54,$54,$54,$54,$54,$54,$54,$54,$54,$54,$54,$54,$54,$54,$54 ; 4467
	fcb	$54                                                             ; 4477

tbl_4478: ; 3 values in 44 cals, differs in: EGR NA TCM
	fcb	$54,$54,$54,$54,$55,$58,$5B,$61,$63,$63,$63,$63,$63,$63,$63,$63 ; 4478
	fcb	$63                                                             ; 4488

tbl_4489: ; 3 values in 44 cals, differs in: EGR NA TCM
	fcb	$54,$54,$54,$54,$55,$58,$5B,$61,$63,$63,$63,$63,$63,$63,$63,$63 ; 4489
	fcb	$63                                                             ; 4499

tbl_449A: ; same in all 44 cals
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF ; 449A
	fcb	$FF                                                             ; 44AA

tbl_44AB: ; 4 values in 44 cals, differs in: EGR NA TA TCM
	fcb	$58,$58,$58,$58,$5B,$5D,$60,$66,$68,$68,$68,$68,$68,$68,$68,$68 ; 44AB
	fcb	$68                                                             ; 44BB

tbl_44BC: ; 3 values in 44 cals, differs in: EGR NA TCM
	fcb	$58,$58,$58,$58,$5B,$5D,$60,$66,$68,$68,$68,$68,$68,$68,$68,$68 ; 44BC
	fcb	$68                                                             ; 44CC

tbl_44CD: ; 2 values in 44 cals, differs in: NA TCM
	fcb	$32,$32,$32,$32,$32,$32,$32,$32,$32,$32,$32,$32,$32,$32,$32,$32 ; 44CD
	fcb	$32                                                             ; 44DD

tbl_44DE: ; 2 values in 44 cals, differs in: NA TCM
	fcb	$46,$46,$46,$46,$46,$46,$46,$46,$46,$46,$46,$46,$46,$46,$46,$46 ; 44DE
	fcb	$46                                                             ; 44EE

tbl_44EF: ; 2 values in 44 cals, differs in: NA TCM
	fcb	$58,$58,$58,$58,$58,$58,$58,$58,$58,$58,$58,$58,$58,$58,$58,$58 ; 44EF
	fcb	$58                                                             ; 44FF

tbl_4500: ; 3 values in 44 cals, differs in: EGR NA TCM
	fcb	$58,$58,$58,$58,$5B,$5D,$60,$66,$68,$68,$68,$68,$68,$68,$68,$68 ; 4500
	fcb	$68                                                             ; 4510

tbl_4511: ; 4 values in 44 cals, differs in: EGR NA TA TCM
	fcb	$58,$58,$58,$58,$5B,$5D,$60,$66,$68,$68,$68,$68,$68,$68,$68,$68 ; 4511
	fcb	$68                                                             ; 4521

tbl_4522: ; same in all 44 cals
	fcb	$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80 ; 4522
	fcb	$80                                                             ; 4532

tbl_4533: ; same in all 44 cals
	fcb	$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80 ; 4533
	fcb	$80                                                             ; 4543

tbl_4544: ; same in all 44 cals
	fcb	$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80 ; 4544
	fcb	$80                                                             ; 4554

k_4555:	; same in all 44 cals
;   analysis: $FF disables the VSS-based max select
	fcb	$FF                                                             ; 4555

k_4556:	; same in all 44 cals
	fcb	$00                                                             ; 4556

tbl_4557: ; 4 values in 44 cals, differs in: ALT TA TCM (range $2806-$50F6)
	fcb	$28,$FA                                                         ; 4557

tbl_4559: ; 5 values in 44 cals, differs in: ALT EGR TA TCM (range $3200-$6D00)
	fcb	$32,$FD                                                         ; 4559

kw_455B: ; 3 values in 44 cals, differs in: ALT NA TCM (range $0019-$0C30)
	fdb	$03C0

k_455D:	; 2 values in 44 cals, differs in: ALT TCM (range $0000-$0014)
	fcb	$00,$00                                                         ; 455D

k_455F:	; 2 values in 44 cals, differs in: ALT TCM (range $0000-$0014)
	fcb	$00,$00                                                         ; 455F

kw_4561: ; 2 values in 44 cals, differs in: ALT TCM (range $0028-$0030)
	fdb	$0030

kw_4563: ; 2 values in 44 cals, differs in: ALT TCM (range $0014-$0080)
	fdb	$0014

k_4565:	; 4 values in 44 cals, differs in: ALT EGR TA TCM (range $10-$42)
	fcb	$42                                                             ; 4565

k_4566:	; 3 values in 44 cals, differs in: ALT TCM (range $10-$80)
	fcb	$10                                                             ; 4566

kw_4567: ; same in all 44 cals
	fdb	$0190

kw_4569: ; same in all 44 cals
	fdb	$0000

kw_456B: ; same in all 44 cals
	fdb	$0000

tbl17_TRANS_pressure_ramp_456D: ; 17 table, 2 values in 44 cals, differs in: TCM
	fcb	$20,$20,$20,$20,$20,$20,$20,$20,$20,$20,$20,$20,$20,$20,$20,$20,$20

tbl_TCC_cold_trans_temp_hyst_457E: ; same in all 44 cals
;   analysis: 2 bytes: cold-trans TCC inhibit thresholds (hysteresis)
	fcb	$E2,$FE                                                         ; 457E

k_4580:	; 2 values in 44 cals, differs in: ALT TA TCM (range $00-$10)
;   analysis: apply delay preload
	fcb	$10                                                             ; 4580

k_4581:	; same in all 44 cals
	fcb	$14                                                             ; 4581

k_4582:	; same in all 44 cals
;   analysis: added to the delay on a re-request
	fcb	$14                                                             ; 4582

k_press_cmd_min_4583: ; same in all 44 cals
;   analysis: minimum command $1AF8
	fcb	$00                                                             ; 4583

k_4584:	; same in all 44 cals
	fcb	$FD                                                             ; 4584

tbl_TRANS_PCS_duty_curve_4585: ; CV table, 3 values in 44 cals, differs in: ALT TA TCM
	fcb	$B8,$9A,$90,$80,$6E,$5F,$57,$52,$4D,$45,$43,$40,$3B,$3B,$3B,$3B ; 4585
	fcb	$3B                                                             ; 4595

tbl17_TRANS_line_pressure_max_vs_RPM_4596: ; 17 table, same in all 44 cals
	fcb	$78,$78,$78,$78,$78,$78,$78,$78,$78,$78,$78,$78,$78,$78,$78,$78,$78

tbl_TRANS_PCS_duty_curve_45A7: ; CV table, 4 values in 44 cals, differs in: ALT TA TCM
	fcb	$00,$16,$21,$26,$2C,$35,$3C,$43,$4C,$54,$5D,$65,$6D,$6B,$67,$64 ; 45A7
	fcb	$64,$2F,$F7                                                     ; 45B7

tblOfs3D_TRANS_line_pressure_base_45BA: ; 3 values in 44 cals, differs in: ALT NA TCM
;   analysis: TCC slip target vs trans load x turbine speed (*8). NOT line pressure
	fcb	$00,$00,$11,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14 ; 45BA
	fcb	$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14 ; 45CA
	fcb	$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14 ; 45DA
	fcb	$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14 ; 45EA
	fcb	$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14 ; 45FA
	fcb	$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14 ; 460A
	fcb	$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14 ; 461A
	fcb	$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14 ; 462A
	fcb	$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14 ; 463A
	fcb	$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14 ; 464A
	fcb	$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14 ; 465A
	fcb	$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14 ; 466A
	fcb	$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14 ; 467A
	fcb	$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14 ; 468A
	fcb	$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14 ; 469A
	fcb	$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14 ; 46AA
	fcb	$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14 ; 46BA
	fcb	$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14 ; 46CA
	fcb	$14,$14,$14,$14                                                 ; 46DA

t17_TCC_slip_integ_gain_46DE: ; 17 table, 3 values in 44 cals, differs in: ALT TA TCM
;   analysis: integrator step vs slip error
	fcb	$16,$05,$05,$05,$01,$03,$05,$07,$09,$0B,$0D,$0F,$12,$15,$18,$1A,$1D

k_46EF:	; 2 values in 44 cals, differs in: ALT TCM (range $00-$10)
	fcb	$10                                                             ; 46EF

kw_46F0: ; 2 values in 44 cals, differs in: ALT TCM
;   analysis: slip >= this clears the negative-slip flag ($320)
	fdb	$0320
	fcb	$05                                                             ; 46F2

k_46F3:	; 2 values in 44 cals, differs in: ALT TCM (range $00-$14)
	fcb	$14                                                             ; 46F3

k_46F4:	; 3 values in 44 cals, differs in: ALT EGR TCM (range $00-$68)
;   analysis: $68 = 52 mph
	fcb	$68                                                             ; 46F4

k_46F5:	; 3 values in 44 cals, differs in: ALT EGR TCM (range $00-$6E)
;   analysis: $6E = 55 mph
	fcb	$6E                                                             ; 46F5

kw_46F6: ; 2 values in 44 cals, differs in: ALT TCM (range $0000-$03C0)
;   analysis: added to slip target for the latch test ($3C0)
	fdb	$03C0

k_46F8:	; same in all 44 cals
	fcb	$00                                                             ; 46F8

kw_46F9: ; 2 values in 44 cals, differs in: ALT TCM (range $0000-$FFD8)
;   analysis: signed (-40) offset for the slip-too-low abort
	fdb	$FFD8

k_46FB:	; 3 values in 44 cals, differs in: ALT TA TCM (range $0000-$0405)
	fcb	$02,$05                                                         ; 46FB

k_46FD:	; 2 values in 44 cals, differs in: ALT TCM (range $00-$01)
	fcb	$01                                                             ; 46FD

k_46FE:	; 4 values in 44 cals, differs in: ALT EGR TA TCM (range $0000-$1300)
	fcb	$13,$00                                                         ; 46FE

k_4700:	; 2 values in 44 cals, differs in: ALT TCM (range $00-$40)
	fcb	$40                                                             ; 4700

kw_4701: ; 2 values in 44 cals, differs in: ALT TCM (range $0000-$0060)
	fdb	$0060

k_4703:	; 2 values in 44 cals, differs in: ALT TCM (range $00-$0E)
	fcb	$0E                                                             ; 4703

k_4704:	; same in all 44 cals
	fcb	$00,$00                                                         ; 4704

kw_4706: ; same in all 44 cals
	fdb	$0000
	fcb	$00                                                             ; 4708

kw_4709: ; 2 values in 44 cals, differs in: ALT TCM (range $0000-$00A0)
	fdb	$00A0

k_470B:	; 2 values in 44 cals, differs in: ALT TCM (range $0000-$0505)
	fcb	$05,$05                                                         ; 470B

k_470D:	; 2 values in 44 cals, differs in: ALT TCM (range $00-$1C)
	fcb	$1C                                                             ; 470D

kw_470E: ; 3 values in 44 cals, differs in: ALT EGR TCM (range $0000-$0127)
	fdb	$0127

kw_4710: ; 3 values in 44 cals, differs in: ALT EGR TCM (range $0000-$012C)
	fdb	$012C

t17_TCC_base_duty_vs_turbine_4712: ; 3 values in 44 cals, differs in: ALT TA TCM
;   analysis: TCC PWM feedforward duty vs turbine speed; 4722 = last point
	fcb	$32,$38,$11,$11,$00,$19,$19,$19,$1A,$1A,$1B,$1B,$1B,$1B,$1C,$1D ; 4712

k_4722:	; 3 values in 44 cals, differs in: ALT TA TCM (range $00-$41)
	fcb	$1D                                                             ; 4722

tbl17_TRANS_pressure_adapt_4723: ; 17 table, 3 values in 44 cals, differs in: ALT NA TCM
	fcb	$80,$80,$80,$7F,$7F,$7F,$7F,$80,$80,$7E,$7C,$7A,$7A,$80,$80,$80,$80

k_4734:	; 2 values in 44 cals, differs in: ALT TCM (range $00-$01)
	fcb	$01                                                             ; 4734

k_4735:	; same in all 44 cals
	fcb	$00                                                             ; 4735

k_4736:	; same in all 44 cals
	fcb	$00                                                             ; 4736

tbl_4737: ; same in all 44 cals
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 4737
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 4747
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 4757
	fcb	$00,$00,$00                                                     ; 4767

tcurve_476A: ; CV table, 6 values in 44 cals, differs in: ALT NA TA TCM
	fcb	$00,$00,$00,$00,$00,$00,$00,$05,$0F,$19,$23,$2D,$37,$3C,$46,$4D ; 476A
	fcb	$00,$00,$00,$00,$00,$00,$00,$05,$0F,$19,$23,$2D,$37,$3C,$40,$44 ; 477A
	fcb	$44,$44,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$11,$22,$33,$33 ; 478A
	fcb	$33,$33,$33                                                     ; 479A

tbl_479D: ; 3 values in 44 cals, differs in: ALT NA TA TCM
	fcb	$00,$00,$02,$00,$00,$22,$00,$00,$88,$00,$00,$CC                 ; 479D

tbl_47A9: ; 3 values in 44 cals, differs in: ALT NA TA TCM
	fcb	$49,$9A,$2B,$85,$00,$00                                         ; 47A9

tbl_47AF: ; 4 values in 44 cals, differs in: ALT NA TA TCM
	fcb	$3E,$00,$26,$00,$00,$00                                         ; 47AF

tbl_47B5: ; 2 values in 44 cals, differs in: TCM
	fcb	$FF,$FF,$FF,$FF                                                 ; 47B5

tbl_47B9: ; 2 values in 44 cals, differs in: TCM
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$28,$28,$28,$3A,$98,$27,$10,$00 ; 47B9
	fcb	$00,$48,$00,$2B,$33,$00,$00                                     ; 47C9

tbl_47D0: ; 2 values in 44 cals, differs in: TCM
	fcb	$FF,$FF,$FF                                                     ; 47D0

tbl_47D3: ; 2 values in 44 cals, differs in: TCM
	fcb	$FF,$FF,$FF                                                     ; 47D3

tbl_47D6: ; 2 values in 44 cals, differs in: TCM
	fcb	$FF,$FF,$FF                                                     ; 47D6

tbl_47D9: ; 2 values in 44 cals, differs in: TCM
	fcb	$FF,$FF,$FF                                                     ; 47D9

tbl_47DC: ; same in all 44 cals
	fcb	$31,$31,$32                                                     ; 47DC

k_47DF:	; same in all 44 cals
	fcb	$00                                                             ; 47DF

kw_shift_press_adder_min_47E0: ; same in all 44 cals
;   analysis: floor 0
	fdb	$0000

k_47E2:	; 2 values in 44 cals, differs in: TA
	fcb	$28,$64,$1F,$40,$26,$2E,$E0,$4E,$4E,$4E,$4E,$4E,$4E,$4E,$00,$00 ; 47E2
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 47F2
	fcb	$00,$00,$00,$FF,$00,$03,$75,$03,$75,$03,$75,$03,$75,$03,$75,$08 ; 4802
	fcb	$85                                                             ; 4812

tbl_4813: ; same in all 44 cals
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00                         ; 4813

tbl_481D: ; same in all 44 cals
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00                         ; 481D

tbl_4827: ; same in all 44 cals
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 4827
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00                             ; 4837

tbl_FORCE_MTR_IGAIN_by_temp_4840: ; 2 values in 44 cals, differs in: TCM
;   analysis: 8 entries indexed by trans temp/32
	fcb	$50,$49,$44,$42,$3D,$3B,$3B,$3B                                 ; 4840

tbl_FORCE_MTR_PGAIN_by_temp_4848: ; 2 values in 44 cals, differs in: TCM
;   analysis: 8 entries indexed by trans temp/32
	fcb	$2F,$28,$23,$20,$1B,$18,$16,$13                                 ; 4848

tofs3d_PCS_setpt_A_4850: ; same in all 44 cals
;   analysis: PCS setpoint vs trans temp x desired pressure (identical to 4974)
	fcb	$00,$00,$11,$CD,$C0,$A8,$A4,$9C,$9C,$94,$94,$90,$88,$84,$74,$58 ; 4850
	fcb	$60,$48,$28,$00,$E0,$BC,$B4,$A4,$9C,$98,$94,$90,$8C,$88,$7C,$70 ; 4860
	fcb	$64,$5C,$48,$38,$00,$E0,$C0,$B0,$AC,$A8,$A0,$9C,$98,$90,$88,$7C ; 4870
	fcb	$74,$68,$54,$38,$24,$00,$E0,$C0,$B8,$B0,$A8,$A4,$9C,$94,$8C,$84 ; 4880
	fcb	$78,$70,$64,$54,$44,$2C,$00,$E0,$BC,$B8,$B4,$AC,$A4,$9C,$94,$8C ; 4890
	fcb	$84,$78,$70,$60,$50,$40,$28,$00,$E0,$C0,$B8,$B0,$A8,$A4,$9C,$94 ; 48A0
	fcb	$88,$84,$78,$6C,$60,$50,$40,$24,$00,$E0,$C0,$B8,$B0,$A8,$A4,$9C ; 48B0
	fcb	$94,$88,$84,$78,$6C,$60,$50,$3C,$20,$00,$E0,$C0,$B8,$B0,$AC,$A0 ; 48C0
	fcb	$9C,$90,$88,$84,$78,$6C,$60,$50,$3C,$1C,$00,$E0,$C0,$B8,$B0,$A8 ; 48D0
	fcb	$A4,$98,$90,$88,$80,$74,$6C,$5C,$4C,$38,$18,$00,$E0,$C0,$B4,$B0 ; 48E0
	fcb	$A8,$A0,$98,$90,$88,$80,$78,$68,$5C,$4C,$38,$14,$00,$E0,$C0,$B8 ; 48F0
	fcb	$B0,$A8,$A0,$9C,$90,$88,$80,$74,$68,$5C,$4C,$38,$14,$00,$E0,$BC ; 4900
	fcb	$B4,$B0,$A8,$A0,$98,$90,$88,$80,$74,$68,$5C,$48,$34,$0C,$00,$E0 ; 4910
	fcb	$BC,$B4,$AC,$A4,$A0,$98,$90,$84,$80,$74,$64,$58,$48,$2C,$08,$00 ; 4920
	fcb	$E0,$BC,$B4,$AC,$A4,$9C,$94,$8C,$84,$7C,$70,$64,$54,$40,$28,$04 ; 4930
	fcb	$00,$E0,$BC,$B4,$AC,$A4,$9C,$98,$8C,$84,$7C,$70,$64,$54,$40,$28 ; 4940
	fcb	$04,$00,$E0,$BC,$B4,$AC,$A4,$9C,$94,$8C,$84,$78,$70,$64,$54,$3C ; 4950
	fcb	$20,$04,$00,$E0,$BC,$B4,$AC,$A4,$9C,$94,$8C,$84,$78,$70,$6C,$60 ; 4960
	fcb	$50,$44,$28,$00                                                 ; 4970

tblOfs3D_TRANS_temp_4974: ; same in all 44 cals
	fcb	$00,$00,$11,$CD,$C0,$A8,$A4,$9C,$9C,$94,$94,$90,$88,$84,$74,$58 ; 4974
	fcb	$60,$48,$28,$00,$E0,$BC,$B4,$A4,$9C,$98,$94,$90,$8C,$88,$7C,$70 ; 4984
	fcb	$64,$5C,$48,$38,$00,$E0,$C0,$B0,$AC,$A8,$A0,$9C,$98,$90,$88,$7C ; 4994
	fcb	$74,$68,$54,$38,$24,$00,$E0,$C0,$B8,$B0,$A8,$A4,$9C,$94,$8C,$84 ; 49A4
	fcb	$78,$70,$64,$54,$44,$2C,$00,$E0,$BC,$B8,$B4,$AC,$A4,$9C,$94,$8C ; 49B4
	fcb	$84,$78,$70,$60,$50,$40,$28,$00,$E0,$C0,$B8,$B0,$A8,$A4,$9C,$94 ; 49C4
	fcb	$88,$84,$78,$6C,$60,$50,$40,$24,$00,$E0,$C0,$B8,$B0,$A8,$A4,$9C ; 49D4
	fcb	$94,$88,$84,$78,$6C,$60,$50,$3C,$20,$00,$E0,$C0,$B8,$B0,$AC,$A0 ; 49E4
	fcb	$9C,$90,$88,$84,$78,$6C,$60,$50,$3C,$1C,$00,$E0,$C0,$B8,$B0,$A8 ; 49F4
	fcb	$A4,$98,$90,$88,$80,$74,$6C,$5C,$4C,$38,$18,$00,$E0,$C0,$B4,$B0 ; 4A04
	fcb	$A8,$A0,$98,$90,$88,$80,$78,$68,$5C,$4C,$38,$14,$00,$E0,$C0,$B8 ; 4A14
	fcb	$B0,$A8,$A0,$9C,$90,$88,$80,$74,$68,$5C,$4C,$38,$14,$00,$E0,$BC ; 4A24
	fcb	$B4,$B0,$A8,$A0,$98,$90,$88,$80,$74,$68,$5C,$48,$34,$0C,$00,$E0 ; 4A34
	fcb	$BC,$B4,$AC,$A4,$A0,$98,$90,$84,$80,$74,$64,$58,$48,$2C,$08,$00 ; 4A44
	fcb	$E0,$BC,$B4,$AC,$A4,$9C,$94,$8C,$84,$7C,$70,$64,$54,$40,$28,$04 ; 4A54
	fcb	$00,$E0,$BC,$B4,$AC,$A4,$9C,$98,$8C,$84,$7C,$70,$64,$54,$40,$28 ; 4A64
	fcb	$04,$00,$E0,$BC,$B4,$AC,$A4,$9C,$94,$8C,$84,$78,$70,$64,$54,$3C ; 4A74
	fcb	$20,$04,$00,$E0,$BC,$B4,$AC,$A4,$9C,$94,$8C,$84,$78,$70,$6C,$60 ; 4A84
	fcb	$50,$44,$28,$00                                                 ; 4A94

t17_4A98: ; 17 table, 2 values in 44 cals, differs in: TCM
;   analysis: hysteresis band vs trans temp*3; all $FF here
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF

k_4AA9:	; 2 values in 44 cals, differs in: TCM (range $00-$E0)
;   analysis: $E0
	fcb	$E0                                                             ; 4AA9

k_4AAA:	; 2 values in 44 cals, differs in: TCM (range $00-$04)
	fcb	$04                                                             ; 4AAA

k_4AAB:	; 2 values in 44 cals, differs in: TCM (range $00-$04)
	fcb	$04                                                             ; 4AAB

kw_4AAC: ; 2 values in 44 cals, differs in: TCM (range $0000-$F333)
	fdb	$F333

kw_4AAE: ; 2 values in 44 cals, differs in: TCM (range $0000-$0099)
	fdb	$0099

k_4AB0:	; same in all 44 cals
	fcb	$64                                                             ; 4AB0

k_4AB1:	; 2 values in 44 cals, differs in: ALT NA TA TCM (range $3C-$55)
	fcb	$55                                                             ; 4AB1

k_4AB2:	; same in all 44 cals
	fcb	$6E                                                             ; 4AB2

k_4AB3:	; 2 values in 44 cals, differs in: ALT NA TA TCM (range $46-$5A)
	fcb	$5A                                                             ; 4AB3

k_4AB4:	; same in all 44 cals
	fcb	$50                                                             ; 4AB4

kw_TIO_15A0_init_4AB5: ; same in all 44 cals
;   analysis: $0316 multiplier/max for PCS duty; TIO register $15A0 config
	fdb	$0316

k_PCS_clean_cycles_4AB7: ; same in all 44 cals
;   analysis: max force-motor cleaning cycles ($FE)
	fcb	$FE                                                             ; 4AB7

kw_PCS_clean_low_ticks_4AB8: ; 2 values in 44 cals, differs in: ALT NA TCM (range $0280-$0370)
;   analysis: duty-0 phase length ($0280)
	fdb	$0280

kw_PCS_clean_high_ticks_4ABA: ; 2 values in 44 cals, differs in: TA TCM (range $0010-$0014)
;   analysis: duty-FF phase length ($0010)
	fdb	$0010

TRANS_shift_solenoid_pattern_alt: ; 2 values in 44 cals, differs in: TCM
	fcb	$10,$00,$20,$30                                                 ; 4ABC

TRANS_shift_solenoid_pattern_by_gear: ; 2 values in 44 cals, differs in: TCM
	fcb	$30,$20,$00,$10                                                 ; 4AC0

tbl_4AC4: ; 2 values in 44 cals, differs in: TCM (range $00-$03)
	fcb	$03                                                             ; 4AC4

tbl_4AC5: ; 2 values in 44 cals, differs in: ALT TCM (range $12-$1A)
	fcb	$1A                                                             ; 4AC5

tbl_dtc_mask_use_current_4AC6: ; same in all 44 cals
;   analysis: 15 bytes: bits test current DTC flags instead of failed-this-ignition (all 0)
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00     ; 4AC6

tbl_dtcmask_fmem_b4_4AD5: ; 4 values in 44 cals, differs in: ALT NA TCM
;   analysis: 15-byte DTC mask -> TRANS_FMEM_ENA_FLAGS.4
	fcb	$F8,$61,$07,$F8,$00,$FF,$77,$8D,$F8,$ED,$9F,$84,$92,$FE,$00     ; 4AD5

tbl_4AE4: ; 4 values in 44 cals, differs in: ALT NA TCM
	fcb	$00,$00,$00,$00,$00,$00,$00,$08,$80,$AD,$1F,$00,$00,$58,$00     ; 4AE4

tbl_4AF3: ; 4 values in 44 cals, differs in: ALT NA TCM
	fcb	$00,$00,$00,$00,$00,$00,$00,$08,$00,$40,$00,$00,$00,$60,$00     ; 4AF3

tbl_dtcmask_fmem_b7_4B02: ; 4 values in 44 cals, differs in: ALT NA TCM
;   analysis: 15-byte DTC mask -> TRANS_FMEM_ENA_FLAGS.7 (above k_4B6C temp)
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$40,$00,$00,$00,$60,$00     ; 4B02

tbl_4B11: ; same in all 44 cals
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00     ; 4B11

tbl_4B20: ; 4 values in 44 cals, differs in: ALT NA TCM
	fcb	$00,$00,$00,$00,$00,$00,$00,$08,$00,$00,$18,$00,$00,$00,$00     ; 4B20

tbl_4B2F: ; same in all 44 cals
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00     ; 4B2F

tbl_4B3E: ; same in all 44 cals
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00     ; 4B3E

tbl_4B4D: ; 3 values in 44 cals, differs in: ALT NA TCM
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$70,$40,$00,$00,$00,$20,$00     ; 4B4D

tbl_4B5C: ; same in all 44 cals
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00     ; 4B5C

k_4B6B:	; same in all 44 cals
	fcb	$00                                                             ; 4B6B

k_4B6C:	; same in all 44 cals
	fcb	$00                                                             ; 4B6C

k_4B6D:	; 3 values in 44 cals, differs in: ALT TCM (range $01-$20)
	fcb	$01                                                             ; 4B6D

k_4B6E:	; 3 values in 44 cals, differs in: ALT TCM (range $32-$50)
	fcb	$32                                                             ; 4B6E

kw_engine_running_RPM_4B6F: ; 2 values in 44 cals, differs in: TCM (range $0E10-$0ED8)
;   analysis: RPM*8; $0ED8 = 475 rpm
	fdb	$0ED8

kw_engine_running_ticks_4B71: ; 2 values in 44 cals, differs in: TCM (range $00C8-$0118)
;   analysis: $0118
	fdb	$0118

kw_4B73: ; 2 values in 44 cals, differs in: ALT TCM (range $0000-$0050)
	fdb	$0050

k_4B75:	; same in all 44 cals
	fcb	$28                                                             ; 4B75

k_4B76:	; 4 values in 44 cals, differs in: ALT NA TA TCM (range $70-$A0)
	fcb	$8C                                                             ; 4B76

kw_P0722_outspd_fail_max_4B77: ; 2 values in 44 cals, differs in: ALT TCM (range $00C8-$0640)
;   analysis: 200
	fdb	$00C8

kw_P0722_outspd_pass_min_4B79: ; 2 values in 44 cals, differs in: TCM (range $0641-$0FA0)
;   analysis: 4000
	fdb	$0FA0

kw_4B7B: ; 2 values in 44 cals, differs in: TCM (range $7210-$76C0)
	fdb	$76C0

k_4B7D:	; same in all 44 cals
	fcb	$00                                                             ; 4B7D

k_4B7E:	; same in all 44 cals
	fcb	$FF                                                             ; 4B7E

kw_4B7F: ; 3 values in 44 cals, differs in: ALT NA TCM (range $2580-$3E80)
	fdb	$2EE0

k_4B81:	; 3 values in 44 cals, differs in: ALT NA TCM (range $19-$33)
	fcb	$19                                                             ; 4B81

kw_4B82: ; same in all 44 cals
	fdb	$0050

kw_4B84: ; 4 values in 44 cals, differs in: ALT NA TCM (range $015E-$01DB)
	fdb	$01DB

k_4B86:	; 2 values in 44 cals, differs in: TCM (range $50-$FF)
	fcb	$FF                                                             ; 4B86

kw_4B87: ; 2 values in 44 cals, differs in: TCM (range $4000-$7FFF)
	fdb	$7FFF

kw_4B89: ; same in all 44 cals
	fdb	$1F40

kw_4B8B: ; 2 values in 44 cals, differs in: ALT TCM (range $0640-$0FA0)
	fdb	$0FA0

kw_4B8D: ; 2 values in 44 cals, differs in: ALT TCM (range $0E10-$1F40)
	fdb	$0E10

k_4B8F:	; same in all 44 cals
	fcb	$28                                                             ; 4B8F

k_4B90:	; 2 values in 44 cals, differs in: TCM (range $50-$FF)
	fcb	$FF                                                             ; 4B90

k_4B91:	; 3 values in 44 cals, differs in: ALT NA TCM (range $50-$A0)
	fcb	$8C                                                             ; 4B91

k_4B92:	; 2 values in 44 cals, differs in: ALT TCM (range $00-$50)
	fcb	$50                                                             ; 4B92

k_4B93:	; 2 values in 44 cals, differs in: ALT TCM (range $00-$50)
	fcb	$50                                                             ; 4B93

kw_4B94: ; 2 values in 44 cals, differs in: ALT TCM (range $0000-$07D0)
	fdb	$07D0

kw_4B96: ; 2 values in 44 cals, differs in: ALT TCM (range $0000-$07D0)
	fdb	$07D0

k_P0560_low_V_cold_hot_4B98: ; same in all 44 cals
;   analysis: byte pair $69/$43: low-V threshold interp end/start (0.1 V)
	fcb	$69                                                             ; 4B98

k_4B99:	; same in all 44 cals
	fcb	$43                                                             ; 4B99

k_P0560_ok_V_cold_hot_4B9A: ; same in all 44 cals
;   analysis: byte pair $78/$53: voltage-good threshold interp (0.1 V)
	fcb	$78                                                             ; 4B9A

k_4B9B:	; same in all 44 cals
	fcb	$53                                                             ; 4B9B

kw_P0560_min_RPM_4B9C: ; 2 values in 44 cals, differs in: TCM (range $2710-$2EE0)
;   analysis: RPM*8; $2EE0 = 1500 rpm
	fdb	$2EE0

k_4B9E:	; same in all 44 cals
	fcb	$0A                                                             ; 4B9E

k_P0560_low_fail_ticks_4B9F: ; 2 values in 44 cals, differs in: TCM (range $28-$96)
;   analysis: $96
	fcb	$96                                                             ; 4B9F

k_P0560_high_V_fail_4BA0: ; same in all 44 cals
;   analysis: $BE = 19.0 V
	fcb	$BE                                                             ; 4BA0

k_P0560_high_V_ok_4BA1: ; same in all 44 cals
;   analysis: $A5 = 16.5 V
	fcb	$A5                                                             ; 4BA1

k_4BA2:	; same in all 44 cals
	fcb	$0A                                                             ; 4BA2

k_4BA3:	; 2 values in 44 cals, differs in: TCM (range $28-$64)
	fcb	$64                                                             ; 4BA3

k_sol_diag_min_V_4BA4: ; 3 values in 44 cals, differs in: ALT NA TCM (range $00-$5A)
;   analysis: $5A = 9.0 V
	fcb	$5A                                                             ; 4BA4

k_sol_diag_max_V_4BA5: ; 3 values in 44 cals, differs in: ALT NA TCM (range $00-$B4)
;   analysis: $A0 = 16.0 V
	fcb	$A0                                                             ; 4BA5

k_4BA6:	; 2 values in 44 cals, differs in: TCM (range $00-$06)
	fcb	$06                                                             ; 4BA6

kw_4BA7: ; 2 values in 44 cals, differs in: TCM (range $0000-$1194)
	fdb	$1194

k_4BA9:	; same in all 44 cals
	fcb	$00                                                             ; 4BA9

k_4BAA:	; 2 values in 44 cals, differs in: TCM (range $00-$51)
	fcb	$51                                                             ; 4BAA

k_4BAB:	; 2 values in 44 cals, differs in: TCM (range $00-$0A)
	fcb	$0A                                                             ; 4BAB

k_4BAC:	; 2 values in 44 cals, differs in: TCM (range $00-$FB)
	fcb	$FB                                                             ; 4BAC

k_4BAD:	; 2 values in 44 cals, differs in: TCM (range $00-$A0)
	fcb	$A0                                                             ; 4BAD

k_4BAE:	; 3 values in 44 cals, differs in: ALT TCM (range $00-$7E)
	fcb	$49                                                             ; 4BAE

kw_4BAF: ; 2 values in 44 cals, differs in: TCM (range $0000-$01E0)
	fdb	$01E0

kw_4BB1: ; 3 values in 44 cals, differs in: ALT TCM (range $0000-$109A)
	fdb	$0DAC

k_4BB3:	; 2 values in 44 cals, differs in: TCM (range $00-$02)
	fcb	$02                                                             ; 4BB3

kw_4BB4: ; 2 values in 44 cals, differs in: TCM (range $0000-$0190)
	fdb	$0190

k_4BB6:	; 2 values in 44 cals, differs in: TCM (range $00-$1A)
	fcb	$1A                                                             ; 4BB6

k_4BB7:	; 2 values in 44 cals, differs in: TCM (range $00-$23)
	fcb	$23                                                             ; 4BB7

k_4BB8:	; 2 values in 44 cals, differs in: TCM (range $00-$0E)
	fcb	$0E                                                             ; 4BB8

k_4BB9:	; 2 values in 44 cals, differs in: TCM (range $00-$03)
	fcb	$03                                                             ; 4BB9

kw_4BBA: ; 2 values in 44 cals, differs in: TCM (range $0000-$0019)
	fdb	$0019

k_4BBC:	; 2 values in 44 cals, differs in: ALT TCM (range $0A-$32)
	fcb	$32                                                             ; 4BBC

k_4BBD:	; 2 values in 44 cals, differs in: NA TCM (range $32-$4B)
	fcb	$4B                                                             ; 4BBD

k_P0712_raw_pass_4BBE: ; 2 values in 44 cals, differs in: TCM (range $08-$0B)
;   analysis: 8 raw counts
	fcb	$08                                                             ; 4BBE

k_P0712_raw_low_4BBF: ; 2 values in 44 cals, differs in: TCM (range $07-$0A)
;   analysis: 7 raw counts
	fcb	$07                                                             ; 4BBF

k_4BC0:	; 2 values in 44 cals, differs in: ALT TCM (range $0A-$32)
	fcb	$32                                                             ; 4BC0

kw_4BC1: ; 3 values in 44 cals, differs in: ALT TCM (range $0096-$07D0)
	fdb	$07D0

k_4BC3:	; same in all 44 cals
	fcb	$FB                                                             ; 4BC3

k_P0713_raw_high_4BC4: ; same in all 44 cals
;   analysis: $FC raw counts
	fcb	$FC                                                             ; 4BC4

kw_P0717_inspd_fail_max_4BC5: ; same in all 44 cals
;   analysis: input speed below this = no signal (400)
	fdb	$0190

kw_P0717_inspd_pass_min_4BC7: ; 2 values in 44 cals, differs in: TCM (range $0191-$0FA0)
;   analysis: 4000
	fdb	$0FA0

k_P0717_min_VSS_4BC9: ; same in all 44 cals
;   analysis: $28 = 20 mph
	fcb	$28                                                             ; 4BC9

k_4BCA:	; same in all 44 cals
	fcb	$0A                                                             ; 4BCA

k_4BCB:	; 3 values in 44 cals, differs in: ALT TCM (range $14-$32)
	fcb	$32                                                             ; 4BCB

kw_4BCC: ; same in all 44 cals
	fdb	$0028

kw_4BCE: ; 2 values in 44 cals, differs in: TCM (range $0028-$00A0)
	fdb	$00A0

kw_4BD0: ; 3 values in 44 cals, differs in: ALT NA TCM (range $0640-$1900)
	fdb	$0FA0

kw_P0716_drop_fail_4BD2: ; 2 values in 44 cals, differs in: TCM (range $1F40-$2580)
;   analysis: input speed drop limit
	fdb	$2580

kw_4BD4: ; 4 values in 44 cals, differs in: ALT NA TCM (range $0190-$1900)
	fdb	$0FA0

k_4BD6:	; same in all 44 cals
	fcb	$26                                                             ; 4BD6

k_4BD7:	; same in all 44 cals
	fcb	$28                                                             ; 4BD7

k_4BD8:	; same in all 44 cals
	fcb	$0A                                                             ; 4BD8

k_P0719_stops_to_fail_4BD9: ; 2 values in 44 cals, differs in: TCM (range $07-$0A)
;   analysis: 10 stops without brake
	fcb	$0A                                                             ; 4BD9

k_4BDA:	; same in all 44 cals
	fcb	$0A                                                             ; 4BDA

k_P0719_arm_VSS_4BDB: ; same in all 44 cals
;   analysis: $28 = 20 mph
	fcb	$28                                                             ; 4BDB

k_4BDC:	; 2 values in 44 cals, differs in: TCM (range $0F-$14)
	fcb	$0F                                                             ; 4BDC

k_4BDD:	; same in all 44 cals
	fcb	$1E                                                             ; 4BDD

kw_P0724_brake_on_time_4BDE: ; same in all 44 cals
;   analysis: $1194 ticks
	fdb	$1194

k_4BE0:	; same in all 44 cals
	fcb	$FF                                                             ; 4BE0

k_P0724_launches_to_fail_4BE1: ; 2 values in 44 cals, differs in: TCM (range $07-$08)
;   analysis: 8
	fcb	$08                                                             ; 4BE1

k_4BE2:	; same in all 44 cals
	fcb	$0A                                                             ; 4BE2

k_4BE3:	; same in all 44 cals
	fcb	$28                                                             ; 4BE3

k_4BE4:	; 2 values in 44 cals, differs in: TCM (range $0F-$14)
	fcb	$0F                                                             ; 4BE4

k_4BE5:	; 2 values in 44 cals, differs in: TCM (range $1E-$23)
	fcb	$23                                                             ; 4BE5

k_4BE6:	; 3 values in 44 cals, differs in: ALT NA TCM (range $05-$14)
	fcb	$0F                                                             ; 4BE6

k_4BE7:	; 4 values in 44 cals, differs in: ALT NA TCM (range $0F-$19)
	fcb	$0F                                                             ; 4BE7

k_P0741_events_4BE8: ; 2 values in 44 cals, differs in: ALT TCM (range $02-$04)
;   analysis: failed apply events to set
	fcb	$04                                                             ; 4BE8

kw_P0741_slip_fail_4BE9: ; 2 values in 44 cals, differs in: ALT TCM (range $0208-$0578)
;   analysis: TCC slip above this while applied = stuck off
	fdb	$0578

k_4BEB:	; same in all 44 cals
	fcb	$26                                                             ; 4BEB

k_4BEC:	; 2 values in 44 cals, differs in: TCM (range $EB-$FF)
	fcb	$FF                                                             ; 4BEC

k_4BED:	; 2 values in 44 cals, differs in: ALT (range $28-$50)
	fcb	$50                                                             ; 4BED

k_4BEE:	; same in all 44 cals
	fcb	$FE                                                             ; 4BEE

k_4BEF:	; 3 values in 44 cals, differs in: ALT NA TCM (range $02-$0F)
	fcb	$02                                                             ; 4BEF

k_4BF0:	; 3 values in 44 cals, differs in: ALT TCM (range $00-$14)
	fcb	$14                                                             ; 4BF0

k_4BF1:	; 3 values in 44 cals, differs in: ALT NA TCM (range $00-$B3)
	fcb	$B3                                                             ; 4BF1

k_4BF2:	; 3 values in 44 cals, differs in: ALT NA TCM (range $05-$14)
	fcb	$0F                                                             ; 4BF2

k_4BF3:	; 4 values in 44 cals, differs in: ALT NA TCM (range $0D-$19)
	fcb	$0F                                                             ; 4BF3

k_4BF4:	; 3 values in 44 cals, differs in: ALT TCM (range $26-$40)
	fcb	$26                                                             ; 4BF4

kw_P0742_slip_lo_4BF5: ; 2 values in 44 cals, differs in: ALT TCM (range $FF88-$FFB0)
;   analysis: -80; slip window for 'locked' detection
	fdb	$FFB0

kw_P0742_slip_hi_4BF7: ; 3 values in 44 cals, differs in: ALT TCM (range $0050-$00A0)
;   analysis: +80
	fdb	$0050

kw_4BF9: ; 3 values in 44 cals, differs in: ALT TCM (range $0079-$0578)
	fdb	$0578

kw_4BFB: ; 3 values in 44 cals, differs in: ALT NA TCM (range $2580-$4E20)
	fdb	$2EE0

kw_4BFD: ; 2 values in 44 cals, differs in: ALT TCM (range $0050-$0082)
	fdb	$0082

kw_4BFF: ; 4 values in 44 cals, differs in: ALT NA TCM (range $015E-$01DB)
	fdb	$01DB

kw_4C01: ; 3 values in 44 cals, differs in: ALT NA TCM (range $6720-$7530)
	fdb	$6720

k_4C03:	; same in all 44 cals
	fcb	$00                                                             ; 4C03

k_4C04:	; same in all 44 cals
	fcb	$FF                                                             ; 4C04

k_P0742_events_4C05: ; 3 values in 44 cals, differs in: ALT NA TCM (range $02-$05)
	fcb	$04                                                             ; 4C05

k_4C06:	; 2 values in 44 cals, differs in: ALT TCM (range $04-$08)
	fcb	$04                                                             ; 4C06

k_4C07:	; 2 values in 44 cals, differs in: ALT
	fcb	$50,$E2,$14                                                     ; 4C07

k_4C0A:	; 2 values in 44 cals, differs in: TCM (range $04-$05)
	fcb	$05                                                             ; 4C0A

k_4C0B:	; 2 values in 44 cals, differs in: TCM (range $02-$04)
	fcb	$02                                                             ; 4C0B

k_4C0C:	; 2 values in 44 cals, differs in: ALT TCM (range $1C-$28)
	fcb	$1C                                                             ; 4C0C

tbl_P0751_wrong_gear_cnt_4C0D: ; 5 values in 44 cals, differs in: ALT NA TCM
;   analysis: per-gear count limit
	fcb	$3C,$58,$FF,$78                                                 ; 4C0D

k_4C11:	; same in all 44 cals
	fcb	$00                                                             ; 4C11

k_4C12:	; same in all 44 cals
	fcb	$FF                                                             ; 4C12

kw_4C13: ; 2 values in 44 cals, differs in: ALT TCM (range $003C-$0050)
	fdb	$0050

kw_4C15: ; 4 values in 44 cals, differs in: ALT NA TCM (range $015E-$01DB)
	fdb	$01DB

k_4C17:	; 3 values in 44 cals, differs in: ALT TCM (range $19-$2E)
	fcb	$19                                                             ; 4C17

kw_4C18: ; 2 values in 44 cals, differs in: ALT TCM (range $7210-$7530)
	fdb	$7530

k_4C1A:	; same in all 44 cals
	fcb	$2B                                                             ; 4C1A

k_4C1B:	; same in all 44 cals
	fcb	$2B                                                             ; 4C1B

k_4C1C:	; same in all 44 cals
	fcb	$32                                                             ; 4C1C

k_4C1D:	; 2 values in 44 cals, differs in: ALT TCM (range $04-$08)
	fcb	$04                                                             ; 4C1D

k_4C1E:	; same in all 44 cals
	fcb	$50,$E2                                                         ; 4C1E

k_4C20:	; same in all 44 cals
	fcb	$00                                                             ; 4C20

k_4C21:	; same in all 44 cals
	fcb	$FF                                                             ; 4C21

kw_4C22: ; 2 values in 44 cals, differs in: TCM (range $003C-$0050)
	fdb	$0050

kw_4C24: ; 4 values in 44 cals, differs in: ALT NA TCM (range $015E-$01DB)
	fdb	$01DB

kw_4C26: ; 2 values in 44 cals, differs in: TCM (range $7210-$7530)
	fdb	$7530

k_P0756_fail_events_12_4C28: ; 2 values in 44 cals, differs in: TCM (range $02-$04)
;   analysis: 2
	fcb	$02                                                             ; 4C28

k_P0756_fail_events_34_4C29: ; 2 values in 44 cals, differs in: TCM (range $04-$07)
;   analysis: 7
	fcb	$07                                                             ; 4C29

k_4C2A:	; same in all 44 cals
	fcb	$28                                                             ; 4C2A

tbl_P0756_wrong_gear_cnt_4C2B: ; 5 values in 44 cals, differs in: ALT NA TCM
;   analysis: per gear dwell in fault window, $6E,$6E,$6E,$FF; per-gear count limit
	fcb	$6E,$6E,$6E,$FF                                                 ; 4C2B

k_4C2F:	; 3 values in 44 cals, differs in: ALT TCM (range $19-$2E)
	fcb	$19                                                             ; 4C2F

k_4C30:	; same in all 44 cals
	fcb	$2B                                                             ; 4C30

k_4C31:	; same in all 44 cals
	fcb	$2B                                                             ; 4C31

k_4C32:	; same in all 44 cals
	fcb	$32,$FF                                                         ; 4C32

k_4C34:	; same in all 44 cals
	fcb	$0A                                                             ; 4C34

k_4C35:	; 2 values in 44 cals, differs in: TCM (range $32-$FF)
	fcb	$FF                                                             ; 4C35

k_4C36:	; same in all 44 cals
	fcb	$01                                                             ; 4C36

k_4C37:	; 3 values in 44 cals, differs in: ALT TCM (range $4B-$C8)
	fcb	$4B                                                             ; 4C37

k_4C38:	; same in all 44 cals
	fcb	$0A                                                             ; 4C38

k_4C39:	; 2 values in 44 cals, differs in: TCM (range $96-$FA)
	fcb	$96                                                             ; 4C39

k_4C3A:	; same in all 44 cals
	fcb	$0A                                                             ; 4C3A

k_4C3B:	; same in all 44 cals
	fcb	$96                                                             ; 4C3B

k_4C3C:	; same in all 44 cals
	fcb	$0A                                                             ; 4C3C

k_4C3D:	; 3 values in 44 cals, differs in: ALT TCM
	fcb	$32,$4D,$C2,$50,$A3,$2E,$66,$30,$00,$1F,$5C,$20,$A3,$1F,$5C,$20 ; 4C3D
	fcb	$A3                                                             ; 4C4D

k_4C4E:	; 2 values in 44 cals, differs in: ALT TCM (range $04-$05)
	fcb	$05                                                             ; 4C4E

k_4C4F:	; same in all 44 cals
	fcb	$0A                                                             ; 4C4F

k_4C50:	; 2 values in 44 cals, differs in: TCM (range $1E-$26)
	fcb	$1E                                                             ; 4C50

kw_4C51: ; 3 values in 44 cals, differs in: ALT TCM (range $18A3-$24CC)
	fdb	$2199

kw_4C53: ; same in all 44 cals
	fdb	$0190

kw_4C55: ; 3 values in 44 cals, differs in: ALT TCM (range $0FA0-$11F8)
	fdb	$11F8

k_4C57:	; 3 values in 44 cals, differs in: ALT TCM (range $03-$3C)
	fcb	$3C                                                             ; 4C57

k_4C58:	; 3 values in 44 cals, differs in: ALT TCM
	fcb	$03,$00,$00,$41,$99,$43,$85                                     ; 4C58

k_4C5F:	; same in all 44 cals
	fcb	$00                                                             ; 4C5F

k_4C60:	; same in all 44 cals
	fcb	$FF                                                             ; 4C60

kw_4C61: ; 2 values in 44 cals, differs in: TCM (range $003C-$0050)
	fdb	$0050

kw_4C63: ; 4 values in 44 cals, differs in: ALT NA TCM (range $015E-$01DB)
	fdb	$01DB

kw_4C65: ; 2 values in 44 cals, differs in: TCM (range $72-$75)
	fcb	$75                                                             ; 4C65

tbl_P1811_count_4C66: ; 2 values in 44 cals, differs in: TCM
;   analysis: per gear
	fcb	$30,$05,$05                                                     ; 4C66

tbl_P1811_long_shift_time_4C69: ; same in all 44 cals
;   analysis: per gear
	fcb	$05,$32,$32,$FF                                                 ; 4C69

k_4C6D:	; 2 values in 44 cals, differs in: ALT NA TCM (range $19-$32)
	fcb	$19                                                             ; 4C6D

kw_P0218_fail_time_4C6E: ; 3 values in 44 cals, differs in: ALT TCM (range $07FD-$1194)
	fdb	$0BB8

k_P0218_overtemp_fail_4C70: ; 3 values in 44 cals, differs in: ALT NA TCM (range $E2-$E9)
;   analysis: $E3 trans temp
	fcb	$E3                                                             ; 4C70

k_P0218_overtemp_pass_4C71: ; 2 values in 44 cals, differs in: ALT NA TCM (range $DC-$E1)
;   analysis: $E1
	fcb	$E1                                                             ; 4C71

k_4C72:	; same in all 44 cals
	fcb	$2B                                                             ; 4C72

k_4C73:	; same in all 44 cals
	fcb	$2B                                                             ; 4C73

k_4C74:	; 2 values in 44 cals, differs in: ALT TCM
	fcb	$32,$FF,$FF,$FF                                                 ; 4C74

k_4C78:	; 3 values in 44 cals, differs in: ALT TCM (range $05-$23)
	fcb	$23                                                             ; 4C78

k_4C79:	; 2 values in 44 cals, differs in: TCM (range $1E-$3C)
	fcb	$1E                                                             ; 4C79

k_4C7A:	; 2 values in 44 cals, differs in: TCM (range $1E-$26)
	fcb	$1E                                                             ; 4C7A

k_4C7B:	; 3 values in 44 cals, differs in: ALT TCM (range $B3-$E6)
	fcb	$CC                                                             ; 4C7B

k_4C7C:	; 3 values in 44 cals, differs in: ALT NA TCM (range $00-$1E)
	fcb	$19                                                             ; 4C7C

k_4C7D:	; 2 values in 44 cals, differs in: ALT TCM (range $00-$FF)
	fcb	$FF                                                             ; 4C7D

k_4C7E:	; 2 values in 44 cals, differs in: ALT (range $28-$50)
	fcb	$50                                                             ; 4C7E

k_4C7F:	; 2 values in 44 cals, differs in: TCM (range $E2-$F1)
	fcb	$E2                                                             ; 4C7F

kw_4C80: ; 4 values in 44 cals, differs in: ALT NA TCM (range $FDA8-$FFB0)
	fdb	$FF60

kw_4C82: ; 3 values in 44 cals, differs in: ALT TCM (range $00A0-$0320)
	fdb	$00A0

kw_4C84: ; 2 values in 44 cals, differs in: ALT TCM (range $003C-$0046)
	fdb	$0046

kw_4C86: ; 4 values in 44 cals, differs in: ALT NA TCM (range $0118-$01DB)
	fdb	$01DB

k_4C88:	; same in all 44 cals
	fcb	$00                                                             ; 4C88

k_4C89:	; same in all 44 cals
	fcb	$FF                                                             ; 4C89

k_P1870_slip_events_4C8A: ; 2 values in 44 cals, differs in: TCM (range $01-$03)
;   analysis: 3
	fcb	$03                                                             ; 4C8A

k_4C8B:	; 3 values in 44 cals, differs in: ALT TCM (range $00-$19)
	fcb	$19                                                             ; 4C8B

kw_4C8C: ; 2 values in 44 cals, differs in: ALT TCM (range $0000-$003C)
;   analysis: TCC hold-off ticks during force motor adapt
	fdb	$003C

kw_4C8E: ; 3 values in 44 cals, differs in: ALT TCM (range $0000-$0460)
	fdb	$03C0

kw_4C90: ; 3 values in 44 cals, differs in: ALT TCM (range $0000-$1068)
	fdb	$1068

kw_4C92: ; 2 values in 44 cals, differs in: TCM (range $0000-$2580)
	fdb	$2580

kw_4C94: ; 2 values in 44 cals, differs in: TCM (range $0000-$7530)
	fdb	$7530

kw_4C96: ; 2 values in 44 cals, differs in: ALT TCM (range $0000-$1666)
	fdb	$1666

kw_4C98: ; 3 values in 44 cals, differs in: ALT TCM (range $0000-$FFFF)
	fdb	$3CCC

k_4C9A:	; 3 values in 44 cals, differs in: ALT TCM (range $00-$3C)
	fcb	$3C                                                             ; 4C9A

k_4C9B:	; 3 values in 44 cals, differs in: ALT TCM (range $00-$FF)
	fcb	$DC                                                             ; 4C9B

kw_4C9C: ; 2 values in 44 cals, differs in: ALT TCM (range $0000-$0370)
	fdb	$0370

kw_4C9E: ; 2 values in 44 cals, differs in: ALT TCM (range $0000-$0FA0)
	fdb	$0FA0

kw_4CA0: ; 2 values in 44 cals, differs in: ALT TCM (range $0000-$0370)
	fdb	$0370

kw_4CA2: ; 2 values in 44 cals, differs in: ALT TCM (range $0000-$0FA0)
	fdb	$0FA0

kw_4CA4: ; 2 values in 44 cals, differs in: ALT TCM (range $0000-$0370)
	fdb	$0370

kw_4CA6: ; 2 values in 44 cals, differs in: ALT TCM
	fdb	$0FA0
	fcb	$CC,$CC                                                         ; 4CA8

k_4CAA:	; 3 values in 44 cals, differs in: ALT NA TCM (range $00-$32)
	fcb	$32                                                             ; 4CAA

k_4CAB:	; 3 values in 44 cals, differs in: ALT NA TCM (range $00-$32)
	fcb	$32                                                             ; 4CAB

k_4CAC:	; 2 values in 44 cals, differs in: ALT TCM (range $00-$32)
	fcb	$32                                                             ; 4CAC

k_4CAD:	; 3 values in 44 cals, differs in: ALT NA TCM (range $00-$C0)
	fcb	$C0                                                             ; 4CAD

k_P0730_count_4CAE: ; 2 values in 44 cals, differs in: ALT NA TCM (range $23-$32)
;   analysis: pass/fail sample count $23
	fcb	$23                                                             ; 4CAE

k_4CAF:	; 4 values in 44 cals, differs in: ALT NA TCM (range $23-$40)
	fcb	$26                                                             ; 4CAF

k_4CB0:	; 3 values in 44 cals, differs in: ALT NA TCM (range $08-$0E)
	fcb	$08                                                             ; 4CB0

k_4CB1:	; 2 values in 44 cals, differs in: TCM (range $35-$50)
	fcb	$50                                                             ; 4CB1

k_4CB2:	; 2 values in 44 cals, differs in: TCM (range $0A-$C8)
	fcb	$C8                                                             ; 4CB2

k_4CB3:	; same in all 44 cals
	fcb	$00                                                             ; 4CB3

k_4CB4:	; same in all 44 cals
	fcb	$FF                                                             ; 4CB4

kw_4CB5: ; 2 values in 44 cals, differs in: ALT TCM (range $7210-$7530)
	fdb	$7530

kw_4CB7: ; 2 values in 44 cals, differs in: TCM (range $003C-$0050)
	fdb	$0050

kw_4CB9: ; 4 values in 44 cals, differs in: ALT NA TCM (range $015E-$01DB)
	fdb	$01DB

tbl_gear_ratio_windows_4CBB: ; 3 values in 44 cals, differs in: ALT NA TCM
;   analysis: 6 lo/hi word pairs, 3.13: 1st 2.42-2.52, 2nd 1.45-1.50, 3rd 0.98-1.02, 4th 0.73-0.77, 2.67-2.72, R 2.04-2.12; per gear min/max ratio words for shift-sol perf diags
	fcb	$4D,$70,$50,$A3                                                 ; 4CBB

kw_4CBF: ; 2 values in 44 cals, differs in: ALT NA TCM (range $2DC2-$2E66)
	fdb	$2E66

kw_4CC1: ; 3 values in 44 cals, differs in: ALT NA TCM (range $3000-$328F)
	fdb	$3000

kw_4CC3: ; 3 values in 44 cals, differs in: ALT NA TCM (range $1E66-$1F5C)
	fdb	$1F5C

kw_4CC5: ; 3 values in 44 cals, differs in: ALT NA TCM (range $20A3-$2199)
	fdb	$20A3

kw_4CC7: ; 2 values in 44 cals, differs in: ALT TCM (range $1666-$175C)
	fdb	$175C

kw_4CC9: ; 3 values in 44 cals, differs in: ALT NA TCM
	fdb	$18A3
	fcb	$55,$70,$57,$0A                                                 ; 4CCB

kw_4CCF: ; 2 values in 44 cals, differs in: ALT TCM (range $3F0A-$4147)
	fdb	$4147

kw_4CD1: ; 3 values in 44 cals, differs in: ALT TCM (range $43D7-$4614)
	fdb	$43D7

kw_4CD3: ; 2 values in 44 cals, differs in: ALT TCM (range $0000-$1614)
	fdb	$1614

kw_4CD5: ; 2 values in 44 cals, differs in: ALT TCM (range $0000-$6333)
	fdb	$6333

k_4CD7:	; 2 values in 44 cals, differs in: TCM (range $17-$26)
	fcb	$17                                                             ; 4CD7

k_4CD8:	; 2 values in 44 cals, differs in: TCM (range $E6-$FF)
	fcb	$FF                                                             ; 4CD8

k_4CD9:	; 2 values in 44 cals, differs in: ALT (range $35-$50)
	fcb	$50                                                             ; 4CD9

k_4CDA:	; same in all 44 cals
	fcb	$E2                                                             ; 4CDA

k_4CDB:	; 3 values in 44 cals, differs in: ALT TCM (range $04-$0A)
	fcb	$04                                                             ; 4CDB

kw_4CDC: ; 2 values in 44 cals, differs in: TCM (range $1E66-$3CCC)
	fdb	$3CCC

kw_4CDE: ; 2 values in 44 cals, differs in: TCM (range $2199-$4333)
	fdb	$4333

kw_4CE0: ; 2 values in 44 cals, differs in: TCM (range $54CC-$A999)
	fdb	$A999

kw_4CE2: ; 2 values in 44 cals, differs in: TCM
	fdb	$B000
	fcb	$00,$00,$00,$00,$00,$00,$00,$00                                 ; 4CE4

k_4CEC:	; 3 values in 44 cals, differs in: ALT TCM (range $14-$32)
	fcb	$32                                                             ; 4CEC

k_4CED:	; 2 values in 44 cals, differs in: TCM (range $0F-$32)
	fcb	$0F                                                             ; 4CED

k_4CEE:	; 2 values in 44 cals, differs in: ALT TCM (range $05-$0A)
	fcb	$05                                                             ; 4CEE

k_4CEF:	; 2 values in 44 cals, differs in: ALT TCM (range $05-$0A)
	fcb	$05                                                             ; 4CEF

k_4CF0:	; 6 values in 44 cals, differs in: ALT NA TA TCM
	fcb	$02,$00,$08,$04,$19,$97,$29,$00,$89,$8F,$00,$04,$C8,$00,$00,$00 ; 4CF0
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00                             ; 4D00

kw_devctl_gear_max_RPM_4D09: ; 2 values in 44 cals, differs in: TCM (range $0000-$7530)
;   analysis: engine speed limit for tester gear command
	fdb	$7530

k_devctl_gear_max_VSS_4D0B: ; 2 values in 44 cals, differs in: TCM (range $00-$FE)
;   analysis: vehicle speed limit for tester gear command
	fcb	$FE                                                             ; 4D0B

k_4D0C:	; 2 values in 44 cals, differs in: TCM (range $00-$C8)
;   analysis: speed limit for commanding gear 1->0
	fcb	$C8                                                             ; 4D0C

k_4D0D:	; 2 values in 44 cals, differs in: TCM (range $00-$FF)
;   analysis: speed limit for commanding gear 2->1
	fcb	$FF                                                             ; 4D0D

kw_tester_PCS_PN_max_rpm_4D0E: ; 2 values in 44 cals, differs in: TCM (range $0000-$4E20)
;   analysis: in P/N, PCS override only allowed below this engine speed
	fdb	$4E20

k_tester_PCS_cmd_max_4D10: ; 3 values in 44 cals, differs in: ALT NA TCM (range $00-$F3)
;   analysis: upper limit of tester PCS command
	fcb	$E1                                                             ; 4D10

k_tester_PCS_cmd_min_4D11: ; 3 values in 44 cals, differs in: ALT NA TCM (range $00-$0F)
;   analysis: lower limit of tester PCS command
	fcb	$0F                                                             ; 4D11

kw_torque_est_hi_offset_4D12: ; 2 values in 44 cals, differs in: TCM (range $0096-$00AE)
;   analysis: added to upper-range table 4DB5 ($AE); offset added to upper load reference table ($00AE)
	fdb	$00AE

k_torque_est_fuel_split_4D14: ; same in all 44 cals
;   analysis: $80: fuel index where table 4D1B switches to 4DB5; fuel_max_final split point between the two load reference tables ($80)
	fcb	$80                                                             ; 4D14

k_trans_torque_red_max_4D15: ; same in all 44 cals
;   analysis: $B3 cap on the trans torque-reduction request
	fcb	$B3                                                             ; 4D15

k_trans_torque_red_max_time_4D16: ; same in all 44 cals
;   analysis: $28 calls of the 50 ms task, about 2 s
	fcb	$28                                                             ; 4D16

k_4D17:	; same in all 44 cals
;   analysis: $04 calls
	fcb	$04                                                             ; 4D17

k_4D18:	; same in all 44 cals
;   analysis: $0A extra A/C load at engagement
	fcb	$0A                                                             ; 4D18

k_4D19:	; 2 values in 44 cals, differs in: NA TCM (range $00-$80)
	fcb	$00                                                             ; 4D19

k_4D1A:	; 2 values in 44 cals, differs in: NA TCM (range $00-$A0)
	fcb	$00                                                             ; 4D1A

tbl3D_RPM_x_r1CBD_9x17_4D1B: ; 3D table, 5 values in 44 cals, differs in: ALT EGR NA TCM
;   analysis: torque estimate vs RPM (columns) x fuel index (rows), lower fuel half
	fcb	$7F
	fcb	$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03
	fcb	$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03
	fcb	$03,$03,$0A,$17,$13,$17,$07,$07,$03,$03,$03,$03,$03,$03,$03,$03,$03
	fcb	$03,$03,$41,$40,$3F,$3F,$38,$2E,$26,$1D,$0E,$05,$03,$03,$03,$03,$03
	fcb	$03,$03,$62,$64,$67,$67,$63,$5A,$52,$48,$3B,$29,$1E,$0A,$03,$03,$03
	fcb	$03,$03,$83,$88,$8A,$8D,$88,$81,$7A,$6E,$62,$50,$46,$3C,$14,$14,$14
	fcb	$03,$A0,$A4,$A9,$AE,$B1,$AD,$A5,$9D,$91,$87,$74,$69,$51,$38,$38,$38
	fcb	$03,$BE,$C2,$C9,$CC,$D0,$CF,$C6,$BF,$B4,$A8,$96,$8C,$7A,$57,$57,$57
	fcb	$03,$D5,$D9,$E2,$E7,$F0,$EE,$E8,$DD,$D1,$C5,$B4,$AA,$8A,$6D,$6D,$6D

tbl3D_torque_est_RPM_fuel_hi_4DB5: ; 3D table, 5 values in 44 cals, differs in: ALT EGR NA TCM
;   analysis: upper fuel half, + kw_4D12
	fcb	$7F
	fcb	$00,$2B,$2B,$34,$39,$42,$40,$3A,$2F,$23,$17,$06,$01,$00,$00,$00,$00
	fcb	$00,$3E,$3E,$49,$52,$61,$5F,$57,$4C,$3F,$31,$20,$17,$11,$11,$11,$11
	fcb	$00,$50,$50,$5C,$6C,$7A,$7D,$72,$65,$58,$4A,$37,$32,$2D,$2D,$2D,$2D
	fcb	$00,$5C,$5C,$6D,$7F,$97,$97,$8C,$7F,$72,$62,$4B,$47,$42,$42,$42,$42
	fcb	$00,$6A,$6A,$7C,$92,$A9,$B1,$A4,$98,$8C,$7E,$69,$62,$5D,$5D,$5D,$5D
	fcb	$00,$51,$51,$8B,$A4,$C1,$C9,$BC,$AD,$A3,$96,$85,$80,$7B,$7B,$7B,$7B
	fcb	$00,$47,$47,$8B,$B6,$D6,$DE,$D2,$C4,$B5,$AE,$A1,$80,$7B,$7B,$7B,$7B
	fcb	$00,$42,$42,$8B,$A4,$EC,$F4,$E6,$D9,$D5,$AE,$A1,$80,$7B,$7B,$7B,$7B
	fcb	$00,$38,$38,$8B,$A4,$EC,$FF,$F8,$EC,$E8,$AE,$A1,$80,$7B,$7B,$7B,$7B

tbl2D_AC_load_vs_ambient_4E4F: ; 2D table, same in all 44 cals
;   analysis: A/C compressor torque vs ambient (min-IAT) temp
	fcb	$10
	fcb	$00,$00,$00,$00,$00,$05,$08,$0C,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F

tbl2D_NA_fuel_derate_BARO_4E61: ; 2D table, 3 values in 44 cals, differs in: EGR NA TA TCM
	fcb	$08
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00

tbl2D_NA_fuel_derate_IAT_4E6B: ; 2D table, 2 values in 44 cals, differs in: NA TCM
	fcb	$08
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00

tbl2D_GLOW_temp_4E75: ; 2D table, same in all 44 cals
	fcb	$10
	fcb	$05,$05,$05,$05,$0A,$14,$12,$0C,$00,$00,$00,$00,$00,$00,$00,$00,$00

tbl3D_EGR_MAF_RPM_x_Fuel_17x17_4E87: ; 3D table, 2 values in 44 cals, differs in: EGR
;   analysis: desired air per rev 17x17 (RPM x load); all zero in this cal
	fcb	$FF
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00

tbl3D_EGR_air_baro_RPM_corr_4FA9: ; 3D table, 3 values in 44 cals, differs in: ALT EGR TCM
;   analysis: baro x RPM multiplier, $80 = 1.0
	fcb	$17
	fcb	$80,$80,$73,$66,$6E,$76,$7E,$87,$8E
	fcb	$80,$80,$71,$64,$6D,$76,$7E,$87,$90
	fcb	$80,$80,$7A,$6C,$72,$78,$7F,$85,$8B

t2d_EGR_air_IAT_corr_4FC5: ; 2D table, 2 values in 44 cals, differs in: EGR
;   analysis: IAT multiplier for desired air
	fcb	$00
	fcb	$00
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 4FC7

tbl_MAF_transfer_curve_4FD7: ; 2 values in 44 cals, differs in: EGR (range $0000-$05D0)
;   analysis: word offset, word max (4FD9), then word points
	fcb	$00,$00                                                         ; 4FD7

kw_4FD9: ; 2 values in 44 cals, differs in: EGR
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 4FD9
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 4FE9
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 4FF9
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 5009
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 5019
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 5029
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 5039
	fcb	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; 5049
	fcb	$00,$00                                                         ; 5059

k_505B:	; 2 values in 44 cals, differs in: EGR (range $00-$14)
	fcb	$00                                                             ; 505B

k_505C:	; 2 values in 44 cals, differs in: EGR (range $00-$96)
	fcb	$00                                                             ; 505C

k_505D:	; 2 values in 44 cals, differs in: EGR
	fcb	$00,$00,$00                                                     ; 505D

k_5060:	; 2 values in 44 cals, differs in: EGR
	fcb	$00,$00,$00                                                     ; 5060

k_EGR_desired_air_max_5063: ; 2 values in 44 cals, differs in: EGR (range $00-$FF)
	fcb	$00                                                             ; 5063

k_5064:	; same in all 44 cals
	fcb	$00                                                             ; 5064

k_5065:	; same in all 44 cals
	fcb	$00                                                             ; 5065

k_5066:	; same in all 44 cals
	fcb	$00                                                             ; 5066

k_5067:	; 2 values in 44 cals, differs in: EGR (range $00-$FF)
	fcb	$00                                                             ; 5067

k_5068:	; 2 values in 44 cals, differs in: EGR (range $00-$DC)
	fcb	$00                                                             ; 5068

kw_EGR_air_per_rev_scale_5069: ; 2 values in 44 cals, differs in: EGR
	fdb	$0000
	fcb	$00,$00                                                         ; 506B

k_506D:	; same in all 44 cals
	fcb	$00                                                             ; 506D

k_506E:	; same in all 44 cals
	fcb	$00                                                             ; 506E

k_EGR_P_gain_506F: ; 2 values in 44 cals, differs in: EGR (range $00-$C8)
	fcb	$00                                                             ; 506F

k_EGR_P_trim_max_5070: ; 2 values in 44 cals, differs in: EGR (range $00-$04)
	fcb	$00                                                             ; 5070

kw_5071: ; 2 values in 44 cals, differs in: EGR (range $0000-$0001)
	fdb	$0000

k_EGR_vac_target_max_5073: ; 2 values in 44 cals, differs in: EGR (range $00-$FF)
;   analysis: before trim
	fcb	$00                                                             ; 5073

k_EGR_vac_target_min_5074: ; same in all 44 cals
;   analysis: before trim
	fcb	$00                                                             ; 5074

k_EGR_vac_final_max_5075: ; 2 values in 44 cals, differs in: EGR (range $00-$FF)
	fcb	$00                                                             ; 5075

k_EGR_vac_final_min_5076: ; 2 values in 44 cals, differs in: EGR (range $0000-$3240)
	fcb	$00,$00                                                         ; 5076

tbl_5078: ; 2 values in 44 cals, differs in: EGR (range $00-$1E)
	fcb	$00                                                             ; 5078

k_5079:	; 2 values in 44 cals, differs in: EGR (range $00-$40)
	fcb	$00                                                             ; 5079

k_507A:	; 2 values in 44 cals, differs in: EGR (range $00-$80)
	fcb	$00                                                             ; 507A

tbl_507B: ; 2 values in 44 cals, differs in: EGR (range $00-$C0)
	fcb	$00                                                             ; 507B

k_507C:	; 2 values in 44 cals, differs in: EGR (range $00-$68)
	fcb	$00                                                             ; 507C

k_507D:	; 2 values in 44 cals, differs in: EGR (range $00-$90)
	fcb	$00                                                             ; 507D

k_507E:	; 2 values in 44 cals, differs in: EGR (range $00-$B8)
	fcb	$00                                                             ; 507E

k_EGR_learn_rpm_hyst_507F: ; 2 values in 44 cals, differs in: EGR (range $00-$03)
	fcb	$00                                                             ; 507F

k_EGR_learn_load_hyst_5080: ; 2 values in 44 cals, differs in: EGR (range $00-$08)
	fcb	$00                                                             ; 5080

MAF_cal_constants: ; 2 values in 44 cals, differs in: EGR (range $00-$CD)
;   analysis: MAF_cal_constants: actually EGR learn cell max
	fcb	$00                                                             ; 5081

k_EGR_learn_cell_min_5082: ; 2 values in 44 cals, differs in: EGR (range $00-$33)
	fcb	$00                                                             ; 5082

kw_MAF_freq_scale_5083: ; 2 values in 44 cals, differs in: EGR (range $0000-$9697)
	fdb	$0000

tbl_5085: ; 2 values in 44 cals, differs in: EGR (range $00-$FF)
	fcb	$00                                                             ; 5085

tbl_5086: ; 2 values in 44 cals, differs in: EGR (range $00-$FF)
	fcb	$00                                                             ; 5086

kw_MAF_freq_valid_max_5087: ; 2 values in 44 cals, differs in: EGR (range $0000-$FFFF)
	fdb	$0000

kw_MAF_freq_valid_min_5089: ; same in all 44 cals
	fdb	$0000

k_508B:	; 2 values in 44 cals, differs in: EGR (range $00-$D2)
	fcb	$00                                                             ; 508B

k_508C:	; 2 values in 44 cals, differs in: EGR (range $00-$82)
	fcb	$00                                                             ; 508C

k_508D:	; 2 values in 44 cals, differs in: EGR (range $00-$66)
	fcb	$00                                                             ; 508D

k_508E:	; 2 values in 44 cals, differs in: EGR (range $00-$60)
	fcb	$00                                                             ; 508E

k_508F:	; 2 values in 44 cals, differs in: EGR (range $00-$20)
	fcb	$00                                                             ; 508F

k_5090:	; 2 values in 44 cals, differs in: EGR (range $00-$FF)
	fcb	$00                                                             ; 5090

k_EGR_meas_air_filter_5091: ; 2 values in 44 cals, differs in: EGR (range $00-$FF)
	fcb	$00                                                             ; 5091

k_EGR_error_filter_5092: ; 2 values in 44 cals, differs in: EGR
	fcb	$00,$00,$00,$00                                                 ; 5092

k_5096:	; 2 values in 44 cals, differs in: EGR (range $00-$80)
	fcb	$00                                                             ; 5096

k_5097:	; 2 values in 44 cals, differs in: EGR (range $0000-$6033)
	fcb	$00,$00                                                         ; 5097

tbl_IOR_init_5099: ; same in all 44 cals
;   analysis: (offset,value) pairs for IOR $1800 at reset
	fcb	$00,$02,$01,$FF,$02,$00,$03,$10,$04,$00,$05,$00,$06,$00,$07     ; 5099

k_50A8:	; same in all 44 cals
;   analysis: initial value for $50/$51
	fcb	$0C,$08,$BF,$09,$00,$0A,$BF,$0B,$00,$0C,$00,$0D,$00,$00         ; 50A8

tbl_HC11_reg_init_50B6: ; same in all 44 cals
;   analysis: (offset,value) pairs for HC11 $1000 registers at reset
	fcb	$01,$70,$02,$08,$03,$EF,$08,$22,$09,$3A,$0B,$00,$0D,$00,$20,$00 ; 50B6
	fcb	$21,$96,$22,$2F,$23,$FF,$24,$D0,$25,$FF,$26,$46,$28,$50,$2B,$13 ; 50C6
	fcb	$2C,$00,$30,$30,$38,$00,$3A,$AA,$3B,$00,$3C,$2E,$5C,$00,$5D,$AC ; 50D6
	fcb	$5E,$0C,$5F,$DE,$00                                             ; 50E6

; DTC table: 114 records [mask][status byte][code BCD]; flags live at
;   DTC_current_flags+byte, DTC_history_flags+byte; DTC_disable_mask+byte blocks a code
DTC_table_114x4_mask_byte_code:
DTC_P0101:   fcb	$01,$00,$01,$01		; P0101  status byte 0 bit $01
DTC_P0102:   fcb	$02,$00,$01,$02		; P0102  status byte 0 bit $02
DTC_P0103:   fcb	$04,$00,$01,$03		; P0103  status byte 0 bit $04
DTC_P0107:   fcb	$08,$00,$01,$07		; P0107  status byte 0 bit $08
DTC_P0108:   fcb	$10,$00,$01,$08		; P0108  status byte 0 bit $10
DTC_P0112:   fcb	$20,$00,$01,$12		; P0112  status byte 0 bit $20
DTC_P0113:   fcb	$40,$00,$01,$13		; P0113  status byte 0 bit $40
DTC_P0117:   fcb	$80,$00,$01,$17		; P0117  status byte 0 bit $80
DTC_P0118:   fcb	$01,$01,$01,$18		; P0118  status byte 1 bit $01
DTC_P0121:   fcb	$02,$01,$01,$21		; P0121  status byte 1 bit $02
DTC_P0122:   fcb	$04,$01,$01,$22		; P0122  status byte 1 bit $04
DTC_P0123:   fcb	$08,$01,$01,$23		; P0123  status byte 1 bit $08
DTC_P0126:   fcb	$10,$01,$01,$26		; P0126  status byte 1 bit $10
DTC_P0182:   fcb	$20,$01,$01,$82		; P0182  status byte 1 bit $20
DTC_P0183:   fcb	$40,$01,$01,$83		; P0183  status byte 1 bit $40
DTC_P0215:   fcb	$80,$01,$02,$15		; P0215  status byte 1 bit $80
DTC_P0216:   fcb	$01,$02,$02,$16		; P0216  status byte 2 bit $01
DTC_P0218:   fcb	$02,$02,$02,$18		; P0218  status byte 2 bit $02
DTC_P0219:   fcb	$04,$02,$02,$19		; P0219  status byte 2 bit $04
DTC_P0220:   fcb	$08,$02,$02,$20		; P0220  status byte 2 bit $08
DTC_P0221:   fcb	$10,$02,$02,$21		; P0221  status byte 2 bit $10
DTC_P0222:   fcb	$20,$02,$02,$22		; P0222  status byte 2 bit $20
DTC_P0223:   fcb	$40,$02,$02,$23		; P0223  status byte 2 bit $40
DTC_P0225:   fcb	$80,$02,$02,$25		; P0225  status byte 2 bit $80
DTC_P0226:   fcb	$01,$03,$02,$26		; P0226  status byte 3 bit $01
DTC_P0227:   fcb	$02,$03,$02,$27		; P0227  status byte 3 bit $02
DTC_P0228:   fcb	$04,$03,$02,$28		; P0228  status byte 3 bit $04
DTC_P0231:   fcb	$08,$03,$02,$31		; P0231  status byte 3 bit $08
DTC_P0236:   fcb	$10,$03,$02,$36		; P0236  status byte 3 bit $10
DTC_P0237:   fcb	$20,$03,$02,$37		; P0237  status byte 3 bit $20
DTC_P0238:   fcb	$40,$03,$02,$38		; P0238  status byte 3 bit $40
DTC_P0251:   fcb	$80,$03,$02,$51		; P0251  status byte 3 bit $80
DTC_P0263:   fcb	$01,$04,$02,$63		; P0263  status byte 4 bit $01
DTC_P0266:   fcb	$02,$04,$02,$66		; P0266  status byte 4 bit $02
DTC_P0269:   fcb	$04,$04,$02,$69		; P0269  status byte 4 bit $04
DTC_P0272:   fcb	$08,$04,$02,$72		; P0272  status byte 4 bit $08
DTC_P0275:   fcb	$10,$04,$02,$75		; P0275  status byte 4 bit $10
DTC_P0278:   fcb	$20,$04,$02,$78		; P0278  status byte 4 bit $20
DTC_P0281:   fcb	$40,$04,$02,$81		; P0281  status byte 4 bit $40
DTC_P0284:   fcb	$80,$04,$02,$84		; P0284  status byte 4 bit $80
DTC_P0300:   fcb	$01,$05,$03,$00		; P0300  status byte 5 bit $01
DTC_P0301:   fcb	$02,$05,$03,$01		; P0301  status byte 5 bit $02
DTC_P0302:   fcb	$04,$05,$03,$02		; P0302  status byte 5 bit $04
DTC_P0303:   fcb	$08,$05,$03,$03		; P0303  status byte 5 bit $08
DTC_P0304:   fcb	$10,$05,$03,$04		; P0304  status byte 5 bit $10
DTC_P0305:   fcb	$20,$05,$03,$05		; P0305  status byte 5 bit $20
DTC_P0306:   fcb	$40,$05,$03,$06		; P0306  status byte 5 bit $40
DTC_P0307:   fcb	$80,$05,$03,$07		; P0307  status byte 5 bit $80
DTC_P0308:   fcb	$01,$06,$03,$08		; P0308  status byte 6 bit $01
DTC_P0335:   fcb	$02,$06,$03,$35		; P0335  status byte 6 bit $02
DTC_P0370:   fcb	$04,$06,$03,$70		; P0370  status byte 6 bit $04
DTC_P0380:   fcb	$08,$06,$03,$80		; P0380  status byte 6 bit $08
DTC_P0400:   fcb	$10,$06,$04,$00		; P0400  status byte 6 bit $10
DTC_P0401:   fcb	$20,$06,$04,$01		; P0401  status byte 6 bit $20
DTC_P0402:   fcb	$40,$06,$04,$02		; P0402  status byte 6 bit $40
DTC_P0404:   fcb	$80,$06,$04,$04		; P0404  status byte 6 bit $80
DTC_P0405:   fcb	$01,$07,$04,$05		; P0405  status byte 7 bit $01
DTC_P0406:   fcb	$02,$07,$04,$06		; P0406  status byte 7 bit $02
DTC_P0501:   fcb	$04,$07,$05,$01		; P0501  status byte 7 bit $04
DTC_P0560:   fcb	$08,$07,$05,$60		; P0560  status byte 7 bit $08
DTC_P0567:   fcb	$10,$07,$05,$67		; P0567  status byte 7 bit $10
DTC_P0568:   fcb	$20,$07,$05,$68		; P0568  status byte 7 bit $20
DTC_P0571:   fcb	$40,$07,$05,$71		; P0571  status byte 7 bit $40
DTC_P0601:   fcb	$80,$07,$06,$01		; P0601  status byte 7 bit $80
DTC_P0602:   fcb	$01,$08,$06,$02		; P0602  status byte 8 bit $01
DTC_P0603:   fcb	$02,$08,$06,$03		; P0603  status byte 8 bit $02
DTC_P0604:   fcb	$04,$08,$06,$04		; P0604  status byte 8 bit $04
DTC_P0606:   fcb	$08,$08,$06,$06		; P0606  status byte 8 bit $08
DTC_P0711:   fcb	$10,$08,$07,$11		; P0711  status byte 8 bit $10
DTC_P0712:   fcb	$20,$08,$07,$12		; P0712  status byte 8 bit $20
DTC_P0713:   fcb	$40,$08,$07,$13		; P0713  status byte 8 bit $40
DTC_P0716:   fcb	$80,$08,$07,$16		; P0716  status byte 8 bit $80
DTC_P0717:   fcb	$01,$09,$07,$17		; P0717  status byte 9 bit $01
DTC_P0719:   fcb	$02,$09,$07,$19		; P0719  status byte 9 bit $02
DTC_P0722:   fcb	$04,$09,$07,$22		; P0722  status byte 9 bit $04
DTC_P0723:   fcb	$08,$09,$07,$23		; P0723  status byte 9 bit $08
DTC_P0724:   fcb	$10,$09,$07,$24		; P0724  status byte 9 bit $10
DTC_P0730:   fcb	$20,$09,$07,$30		; P0730  status byte 9 bit $20
DTC_P0741:   fcb	$40,$09,$07,$41		; P0741  status byte 9 bit $40
DTC_P0742:   fcb	$80,$09,$07,$42		; P0742  status byte 9 bit $80
DTC_P0748:   fcb	$01,$0A,$07,$48		; P0748  status byte 10 bit $01
DTC_P0751:   fcb	$02,$0A,$07,$51		; P0751  status byte 10 bit $02
DTC_P0753:   fcb	$04,$0A,$07,$53		; P0753  status byte 10 bit $04
DTC_P0756:   fcb	$08,$0A,$07,$56		; P0756  status byte 10 bit $08
DTC_P0758:   fcb	$10,$0A,$07,$58		; P0758  status byte 10 bit $10
DTC_P1125:   fcb	$20,$0A,$11,$25		; P1125  status byte 10 bit $20
DTC_P1191:   fcb	$40,$0A,$11,$91		; P1191  status byte 10 bit $40
DTC_P1214:   fcb	$80,$0A,$12,$14		; P1214  status byte 10 bit $80
DTC_P1216:   fcb	$01,$0B,$12,$16		; P1216  status byte 11 bit $01
DTC_P1217:   fcb	$02,$0B,$12,$17		; P1217  status byte 11 bit $02
DTC_P1218:   fcb	$04,$0B,$12,$18		; P1218  status byte 11 bit $04
DTC_P1406:   fcb	$08,$0B,$14,$06		; P1406  status byte 11 bit $08
DTC_P1408:   fcb	$10,$0B,$14,$08		; P1408  status byte 11 bit $10
DTC_P1409:   fcb	$20,$0B,$14,$09		; P1409  status byte 11 bit $20
DTC_P1410:   fcb	$40,$0B,$14,$10		; P1410  status byte 11 bit $40
DTC_P1621:   fcb	$80,$0B,$16,$21		; P1621  status byte 11 bit $80
DTC_P1626:   fcb	$01,$0C,$16,$26		; P1626  status byte 12 bit $01
DTC_P1627:   fcb	$02,$0C,$16,$27		; P1627  status byte 12 bit $02
DTC_P1630:   fcb	$04,$0C,$16,$30		; P1630  status byte 12 bit $04
DTC_P1631:   fcb	$08,$0C,$16,$31		; P1631  status byte 12 bit $08
DTC_P1635:   fcb	$10,$0C,$16,$35		; P1635  status byte 12 bit $10
DTC_P1641:   fcb	$20,$0C,$16,$41		; P1641  status byte 12 bit $20
DTC_P1643:   fcb	$40,$0C,$16,$43		; P1643  status byte 12 bit $40
DTC_P1653:   fcb	$80,$0C,$16,$53		; P1653  status byte 12 bit $80
DTC_P1654:   fcb	$01,$0D,$16,$54		; P1654  status byte 13 bit $01
DTC_P1655:   fcb	$02,$0D,$16,$55		; P1655  status byte 13 bit $02
DTC_P1656:   fcb	$04,$0D,$16,$56		; P1656  status byte 13 bit $04
DTC_P1810:   fcb	$08,$0D,$18,$10		; P1810  status byte 13 bit $08
DTC_P1811:   fcb	$10,$0D,$18,$11		; P1811  status byte 13 bit $10
DTC_P1860:   fcb	$20,$0D,$18,$60		; P1860  status byte 13 bit $20
DTC_P1870:   fcb	$40,$0D,$18,$70		; P1870  status byte 13 bit $40
DTC_P1875:   fcb	$80,$0D,$18,$75		; P1875  status byte 13 bit $80
DTC_P3A05:   fcb	$01,$0E,$3A,$05		; P3A05  status byte 14 bit $01
DTC_P9201:   fcb	$02,$0E,$92,$01		; P9201  status byte 14 bit $02

tbl_52B3: ; same in all 44 cals
;   analysis: index by frame-id bits -> offset into tbl_53B3
	fcb	$00,$00,$00,$00,$01,$04,$04,$07,$08,$08,$08,$0B,$0F,$0F,$0F,$0F ; 52B3
	fcb	$16,$16,$19,$19,$1A,$1D,$1D,$1D,$1E,$1E,$1E,$1E,$1F,$1F,$1F,$1F ; 52C3
	fcb	$20,$20,$20,$20,$21,$21,$21,$21,$22,$22,$22,$22,$23,$23,$23,$23 ; 52D3
	fcb	$24,$24,$24,$24,$25,$25,$25,$25,$26,$26,$26,$26,$27,$27,$27,$27 ; 52E3
	fcb	$28,$28,$28,$28,$29,$2C,$2C,$2C,$2D,$2D,$2D,$2D,$2E,$2E,$2E,$2E ; 52F3
	fcb	$2F,$2F,$2F,$2F,$30,$30,$30,$30,$31,$31,$31,$31,$32,$32,$32,$32 ; 5303
	fcb	$33,$33,$33,$33,$34,$34,$34,$34,$35,$35,$35,$35,$36,$36,$36,$36 ; 5313
	fcb	$37,$37,$37,$37,$38,$38,$38,$38,$39,$39,$39,$39,$3A,$3A,$3A,$3A ; 5323
	fcb	$3B,$3E,$3E,$3E,$3F,$3F,$3F,$3F,$40,$43,$43,$43,$44,$44,$44,$44 ; 5333
	fcb	$45,$45,$45,$45,$46,$46,$46,$46,$47,$47,$47,$47,$48,$48,$48,$48 ; 5343
	fcb	$49,$49,$49,$49,$4A,$4A,$4A,$4A,$4B,$4B,$4B,$4B,$4C,$4C,$4C,$4C ; 5353
	fcb	$4D,$4D,$4D,$4D,$4E,$4E,$4E,$4E,$4F,$4F,$4F,$4F,$50,$50,$50,$50 ; 5363
	fcb	$51,$51,$51,$51,$52,$52,$52,$52,$53,$53,$53,$53,$54,$54,$54,$54 ; 5373
	fcb	$55,$55,$55,$55,$56,$56,$56,$56,$57,$57,$57,$57,$58,$58,$58,$58 ; 5383
	fcb	$59,$59,$59,$59,$5A,$5A,$5A,$5A,$5B,$5B,$5B,$5B,$5C,$5C,$5C,$5C ; 5393
	fcb	$5D,$60,$60,$60,$61,$61,$61,$61,$62,$62,$62,$62,$63,$63,$63,$63 ; 53A3

tbl_53B3: ; same in all 44 cals
;   analysis: 3-byte entries {msg id, handler table ptr}
	fcb	$FF,$28,$54,$50,$92,$54,$86,$FF,$92,$54,$8F,$FA,$54,$98,$FF,$FA ; 53B3
	fcb	$54,$A1,$FE,$54,$AA,$FF,$52,$54,$7D,$FF,$3A,$54,$59,$FF,$FF,$FF ; 53C3
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$12,$54,$47,$FF,$FF,$FF,$FF ; 53D3
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$3A,$54,$62,$FF,$FF ; 53E3
	fcb	$3A,$54,$6B,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF ; 53F3
	fcb	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$3A,$54,$74 ; 5403
	fcb	$FF,$FF,$FF,$FF,$7E,$CF,$7B,$7E,$CF,$F1,$7E,$D0,$2F,$7E,$D0,$35 ; 5413
	fcb	$7E,$D0,$41,$7E,$D0,$BF,$7E,$D1,$3B,$7E,$D1,$47,$7E,$CE,$33,$7E ; 5423
	fcb	$CE,$75,$7E,$CE,$B7,$7E,$CE,$C3,$7E,$CE,$CF,$7E,$CF,$31,$7E,$CF ; 5433
	fcb	$75,$7E,$CF,$75,$01,$54,$2F,$1D,$AF,$1D,$B0,$D1,$53,$01,$54,$2F ; 5443
	fcb	$1D,$B1,$1D,$B2,$D1,$7E,$01,$54,$17,$1D,$B3,$1D,$B4,$D1,$B0,$00 ; 5453
	fcb	$54,$2F,$1D,$B5,$1D,$B6,$D1,$FB,$04,$54,$17,$1D,$B7,$1D,$BC,$D2 ; 5463
	fcb	$35,$01,$54,$2F,$1D,$C0,$1D,$C1,$D2,$8A,$00,$54,$2F,$1D,$C2,$1D ; 5473
	fcb	$C3,$D2,$B2,$02,$54,$17,$1D,$C4,$1D,$C5,$D2,$E2,$01,$54,$2F,$1D ; 5483
	fcb	$C7,$1D,$C8,$D3,$75,$04,$54,$2F,$1D,$C9,$1D,$CA,$D3,$9C,$04,$54 ; 5493
	fcb	$2F,$1D,$CE,$1D,$CF,$D3,$CC,$00,$54,$2F,$1D,$D3,$1D,$D4,$D3,$FC ; 54A3

diag_test_descriptors: ; same in all 44 cals
;   analysis: diag_test_descriptors: 12-byte J1850 msg slot records (+4 status ptr, +6 age ctr ptr, +A limits ptr)
	fcb	$08,$93,$02,$01,$1D,$C7,$1D,$E3,$EA,$25,$32,$AA,$27,$00,$00,$00 ; 54B3
	fcb	$00,$00,$00,$00,$00,$00,$32,$B1,$28,$00,$00,$00,$00,$00,$00,$00 ; 54C3
	fcb	$00,$00,$32,$B8,$01,$00,$00,$00,$00,$00,$00,$00,$00,$00,$32,$BF ; 54D3
	fcb	$02,$00,$00,$00,$00,$00,$00,$00,$00,$00,$32,$C6,$03,$00,$00,$00 ; 54E3
	fcb	$00,$00,$00,$00,$00,$00,$32,$CD,$04,$00,$00,$00,$00,$00,$00,$00 ; 54F3
	fcb	$00,$00,$32,$D4,$06,$00,$00,$00,$00,$00,$00,$00,$00,$00,$32,$DB ; 5503
	fcb	$07,$00,$00,$00,$00,$00,$00,$00,$00,$00,$32,$E2,$AE,$00,$00,$00 ; 5513
	fcb	$00,$00,$00,$00,$00,$00,$32,$E9,$2A,$00,$00,$00,$00,$00,$00,$00 ; 5523
	fcb	$00,$00,$32,$F0,$08,$29,$01,$01,$1D,$B1,$1D,$D5,$E9,$D2,$32,$F7 ; 5533
	fcb	$08,$FF,$03,$00,$1D,$D3,$1D,$E8,$EA,$4A,$32,$FE,$14,$00,$00,$00 ; 5543
	fcb	$00,$00,$00,$00,$00,$00,$33,$05,$10,$00,$00,$00,$00,$00,$00,$00 ; 5553
	fcb	$00,$00,$33,$0C,$20,$00,$00,$00,$00,$00,$00,$00,$00,$00,$33,$13 ; 5563
	fcb	$22,$00,$00,$00,$00,$00,$00,$00,$00,$00,$33,$1A,$23,$00,$00,$00 ; 5573
	fcb	$00,$00,$00,$00,$00,$00,$33,$21,$2C,$00,$00,$00,$00,$00,$00,$00 ; 5583
	fcb	$00,$00,$33,$28,$60,$00,$00,$00,$00,$00,$00,$00,$00,$00,$33,$2F ; 5593
	fcb	$7F,$00,$00,$00,$00,$00,$00,$00,$00,$00,$33,$36,$12,$00,$00,$00 ; 55A3
	fcb	$00,$00,$00,$00,$00,$00,$33,$3D,$17,$00,$00,$00,$00,$00,$00,$00 ; 55B3
	fcb	$00,$00,$33,$44,$19,$00,$00,$00,$00,$00,$00,$00,$00,$00,$33,$4B ; 55C3
	fcb	$29,$00,$00,$00,$00,$00,$00,$00,$00,$00,$33,$52,$34,$00,$00,$00 ; 55D3
	fcb	$00,$00,$00,$00,$00,$00,$33,$59,$36,$00,$00,$00,$00,$00,$00,$00 ; 55E3
	fcb	$00,$00,$33,$60,$3B,$00,$00,$00,$00,$00,$00,$00,$00,$00,$33,$67 ; 55F3
	fcb	$3C,$00,$00,$00,$00,$00,$00,$00,$00,$00,$33,$6E,$3F,$00,$00,$00 ; 5603
	fcb	$00,$00,$00,$00,$00,$00,$33,$75,$A0,$00,$00,$00,$00,$00,$00,$00 ; 5613
	fcb	$00,$00,$33,$7C,$A1,$00,$00,$00,$00,$00,$00,$00,$00,$00,$33,$83 ; 5623
	fcb	$09,$92,$01,$00,$1D,$C4,$1D,$E1,$EA,$24,$33,$8A,$08,$13,$11,$01 ; 5633
	fcb	$1D,$AF,$1D,$D4,$E9,$BC,$33,$91,$09,$3A,$05,$00,$1D,$B3,$1D,$D6 ; 5643
	fcb	$E9,$E6,$33,$98,$09,$3A,$45,$00,$1D,$B3,$1D,$D8,$E9,$E7,$33,$9F ; 5653
	fcb	$08,$3B,$20,$00,$1D,$B5,$1D,$D9,$E9,$E8,$33,$A6,$08,$3B,$22,$04 ; 5663
	fcb	$1D,$B7,$1D,$DB,$E9,$FD,$33,$AD,$09,$3B,$22,$00,$1D,$B7,$1D,$DC ; 5673
	fcb	$EA,$0C,$33,$B4,$08,$3B,$3C,$01,$1D,$C0,$1D,$DE,$EA,$0D,$33,$BB ; 5683
	fcb	$08,$53,$04,$00,$1D,$C2,$1D,$DF,$EA,$1C,$33,$C2,$08,$FB,$02,$04 ; 5693
	fcb	$1D,$C9,$1D,$E6,$EA,$2C,$33,$C9,$08,$FB,$03,$04,$1D,$CE,$1D,$E7 ; 56A3
	fcb	$EA,$3B,$33,$D0                                                 ; 56B3

; PID record table (mode $22 read by PID, mode $01, freeze frame): 5-byte records
;   [PID hi][PID lo][pointer hi][pointer lo][length]. Pointer <= $5099: data address, read directly;
;   pointer above $5099: routine called with bank 1 selected (b1:DC87), returns X -> data. Binary searched
;   by b1:EC6C, table end $5905 (the last record is at bank0 5900).
tbl_56B7:
	fcb	$00,$00                       ; 56B7  PID $0000 not supported, 4 bytes
kw_56B9:
	fcb	$FF,$FF                       ; 56B9
k_56BB:
	fcb	$04                           ; 56BB
	fcb	$00,$01,$FF,$FF,$04           ; 56BC  PID $0001 not supported, 4 bytes
	fcb	$00,$02,$FF,$FF,$02           ; 56C1  PID $0002 not supported, 2 bytes
	fcb	$00,$04,$F0,$69,$01           ; 56C6  PID $0004 -> PID_0004_fmt_F069, 1 byte
	fcb	$00,$05,$F0,$9E,$01           ; 56CB  PID $0005 -> PID_05_coolant_temp_F09E, 1 byte
	fcb	$00,$0C,$F0,$AD,$02           ; 56D0  PID $000C -> PID_0C_engine_rpm_F0AD, 2 bytes
	fcb	$00,$0D,$F0,$C0,$01           ; 56D5  PID $000D -> PID_0D_vehicle_speed_kph_F0C0, 1 byte
	fcb	$00,$0F,$F0,$D2,$01           ; 56DA  PID $000F -> PID_0F_intake_air_temp_F0D2, 1 byte
	fcb	$00,$10,$F0,$E1,$02           ; 56DF  PID $0010 -> PID_0010_fmt_F0E1, 2 bytes
	fcb	$00,$1C,$FF,$FF,$01           ; 56E4  PID $001C not supported, 1 byte
tbl_56E9:
	fcb	$11,$00,$F1,$0E,$01           ; 56E9  PID $1100 -> PID_1100_fmt_F10E, 1 byte
	fcb	$11,$01,$F1,$48,$01           ; 56EE  PID $1101 -> PID_output_status_bits_F148, 1 byte
	fcb	$11,$02,$00,$C5,$01           ; 56F3  PID $1102 -> EGR_flow_test_progress, 1 byte
	fcb	$11,$03,$00,$C6,$01           ; 56F8  PID $1103 -> egr_v00C6, 1 byte
	fcb	$11,$04,$00,$C3,$01           ; 56FD  PID $1104 -> EGR_fault_status_word, 1 byte
	fcb	$11,$05,$00,$C4,$01           ; 5702  PID $1105 -> egr_v00C4, 1 byte
	fcb	$11,$06,$F1,$91,$01           ; 5707  PID $1106 -> PID_1106_fmt_F191, 1 byte
	fcb	$11,$41,$19,$21,$01           ; 570C  PID $1141 -> battery_voltage, 1 byte
	fcb	$11,$4B,$19,$25,$01           ; 5711  PID $114B -> EGR_VAC_VOLTS_FILT, 1 byte
	fcb	$11,$4C,$F1,$CF,$01           ; 5716  PID $114C -> PID_fuel_temp_F1CF, 1 byte
	fcb	$11,$51,$19,$1D,$01           ; 571B  PID $1151 -> APP_COND_2, 1 byte
	fcb	$11,$68,$19,$4D,$01           ; 5720  PID $1168 -> MUX12_B5_unused, 1 byte
	fcb	$11,$69,$F1,$DE,$01           ; 5725  PID $1169 -> PID_APP2_filtered_F1DE, 1 byte
	fcb	$11,$6A,$F1,$EB,$01           ; 572A  PID $116A -> PID_APP3_filtered_F1EB, 1 byte
	fcb	$11,$6B,$19,$36,$01           ; 572F  PID $116B -> glow_plug_voltage, 1 byte
	fcb	$11,$6C,$1A,$35,$01           ; 5734  PID $116C -> missed_I4_ref_count, 1 byte
	fcb	$11,$6D,$19,$24,$01           ; 5739  PID $116D -> MAP_scaled_unchecked, 1 byte
	fcb	$11,$6F,$F1,$F8,$01           ; 573E  PID $116F -> PID_116F_fmt_F1F8, 1 byte
	fcb	$11,$71,$18,$0F,$01           ; 5743  PID $1171 -> EGR_PWM_duty, 1 byte
	fcb	$11,$74,$18,$0B,$01           ; 5748  PID $1174 -> $180B, 1 byte
	fcb	$11,$92,$F2,$07,$01           ; 574D  PID $1192 -> PID_1192_fmt_F207, 1 byte
	fcb	$11,$9B,$19,$6F,$01           ; 5752  PID $119B -> egr_v196F, 1 byte
	fcb	$11,$9D,$F2,$1B,$01           ; 5757  PID $119D -> PID_119D_fmt_F21B, 1 byte
	fcb	$11,$A1,$18,$EB,$02           ; 575C  PID $11A1 -> ram_v18EB, 2 bytes
	fcb	$11,$A2,$F2,$37,$01           ; 5761  PID $11A2 -> PID_current_DTC_count_F237, 1 byte
	fcb	$11,$A4,$1C,$BA,$01           ; 5766  PID $11A4 -> AC_load_torque, 1 byte
	fcb	$11,$AD,$02,$6F,$01           ; 576B  PID $11AD -> warmups_no_MIL_fault, 1 byte
	fcb	$11,$C6,$19,$AF,$02           ; 5770  PID $11C6 -> COMMAND_FUEL_PW, 2 bytes
	fcb	$11,$D0,$19,$BC,$01           ; 5775  PID $11D0 -> injection_timing_desired, 1 byte
	fcb	$11,$D3,$01,$18,$01           ; 577A  PID $11D3 -> MEASURED_INJ_TIMING, 1 byte
	fcb	$11,$E1,$F2,$56,$01           ; 577F  PID $11E1 -> PID_pump_cal_index_F256, 1 byte
	fcb	$11,$E2,$01,$1E,$02           ; 5784  PID $11E2 -> rpm_v011E, 2 bytes
	fcb	$12,$21,$F2,$7D,$02           ; 5789  PID $1221 -> PID_1221_fmt_F27D, 2 bytes
	fcb	$12,$22,$19,$A4,$01           ; 578E  PID $1222 -> fuel_quantity, 1 byte
	fcb	$12,$23,$18,$58,$02           ; 5793  PID $1223 -> TDC_REF_OFFSET, 2 bytes
	fcb	$12,$24,$1A,$3C,$01           ; 5798  PID $1224 -> rpm_v1A3C, 1 byte
	fcb	$12,$34,$F2,$8B,$02           ; 579D  PID $1234 -> PID_1234_fmt_F28B, 2 bytes
	fcb	$12,$35,$FF,$FF,$02           ; 57A2  PID $1235 not supported, 2 bytes
	fcb	$12,$36,$FF,$FF,$02           ; 57A7  PID $1236 not supported, 2 bytes
	fcb	$12,$37,$FF,$FF,$01           ; 57AC  PID $1237 not supported, 1 byte
	fcb	$12,$38,$FF,$FF,$01           ; 57B1  PID $1238 not supported, 1 byte
	fcb	$12,$39,$FF,$FF,$01           ; 57B6  PID $1239 not supported, 1 byte
	fcb	$12,$DA,$1F,$B4,$02           ; 57BB  PID $12DA -> MAF_freq_filtered, 2 bytes
	fcb	$12,$E0,$1F,$B6,$02           ; 57C0  PID $12E0 -> egr_measured_air_filt, 2 bytes
	fcb	$12,$EA,$F3,$04,$01           ; 57C5  PID $12EA -> PID_12EA_fmt_F304, 1 byte
	fcb	$12,$EB,$F3,$16,$01           ; 57CA  PID $12EB -> PID_12EB_fmt_F316, 1 byte
	fcb	$12,$EC,$F3,$37,$01           ; 57CF  PID $12EC -> PID_12EC_fmt_F337, 1 byte
	fcb	$12,$EE,$1F,$89,$01           ; 57D4  PID $12EE -> antitheft_status, 1 byte
	fcb	$13,$02,$00,$D2,$01           ; 57D9  PID $1302 -> egr_learn_cells_low, 1 byte
	fcb	$13,$03,$1F,$9C,$01           ; 57DE  PID $1303 -> egr_desired_air, 1 byte
	fcb	$13,$04,$00,$CD,$01           ; 57E3  PID $1304 -> egr_v00CD, 1 byte
	fcb	$13,$05,$00,$CE,$01           ; 57E8  PID $1305 -> egr_v00CE, 1 byte
	fcb	$13,$06,$00,$D0,$01           ; 57ED  PID $1306 -> egr_v00D0, 1 byte
	fcb	$13,$07,$00,$CC,$01           ; 57F2  PID $1307 -> egr_v00CC, 1 byte
	fcb	$13,$08,$1F,$BA,$01           ; 57F7  PID $1308 -> egr_v1FBA, 1 byte
	fcb	$13,$09,$00,$D1,$01           ; 57FC  PID $1309 -> egr_learn_cells_high, 1 byte
	fcb	$13,$0C,$18,$60,$01           ; 5801  PID $130C -> EGR_learn_cell_idx, 1 byte
	fcb	$13,$A3,$F3,$58,$02           ; 5806  PID $13A3 -> PID_13A3_fmt_F358, 2 bytes
	fcb	$16,$00,$19,$0C,$01           ; 580B  PID $1600 -> APP1_FILT, 1 byte
	fcb	$19,$00,$F3,$6A,$01           ; 5810  PID $1900 -> PID_1900_fmt_F36A, 1 byte
	fcb	$19,$01,$F3,$A1,$01           ; 5815  PID $1901 -> ff_pack_status_byte_F3A1, 1 byte
	fcb	$19,$02,$F3,$DC,$01           ; 581A  PID $1902 -> PID_1902_fmt_F3DC, 1 byte
	fcb	$19,$03,$F4,$07,$01           ; 581F  PID $1903 -> PID_1903_fmt_F407, 1 byte
	fcb	$19,$04,$F4,$44,$01           ; 5824  PID $1904 -> PID_1904_fmt_F444, 1 byte
	fcb	$19,$05,$F4,$87,$01           ; 5829  PID $1905 -> ff_pack_range_bits_F487, 1 byte
	fcb	$19,$06,$F4,$BD,$01           ; 582E  PID $1906 -> PID_1906_fmt_F4BD, 1 byte
	fcb	$19,$07,$F4,$D6,$01           ; 5833  PID $1907 -> PID_1907_fmt_F4D6, 1 byte
	fcb	$19,$08,$F5,$19,$01           ; 5838  PID $1908 -> PID_1908_fmt_F519, 1 byte
	fcb	$19,$09,$F5,$26,$01           ; 583D  PID $1909 -> PID_1909_fmt_F526, 1 byte
	fcb	$19,$0A,$F5,$33,$01           ; 5842  PID $190A -> PID_190A_fmt_F533, 1 byte
	fcb	$19,$0B,$F5,$48,$01           ; 5847  PID $190B -> PID_190B_fmt_F548, 1 byte
	fcb	$19,$0C,$F5,$5D,$01           ; 584C  PID $190C -> PID_190C_fmt_F55D, 1 byte
	fcb	$19,$0D,$F5,$7C,$01           ; 5851  PID $190D -> PID_190D_fmt_F57C, 1 byte
	fcb	$19,$40,$F5,$9B,$01           ; 5856  PID $1940 -> fmt_trans_temp_x075_F59B, 1 byte
	fcb	$19,$41,$18,$9D,$02           ; 585B  PID $1941 -> trans_input_speed_raw, 2 bytes
	fcb	$19,$42,$18,$B0,$02           ; 5860  PID $1942 -> TRANS_OUTPUT_SPEED_RAW, 2 bytes
	fcb	$19,$48,$19,$44,$01           ; 5865  PID $1948 -> MUX3_ECT_voltage, 1 byte
	fcb	$19,$70,$1B,$AF,$01           ; 586A  PID $1970 -> PCS_duty_out, 1 byte
	fcb	$19,$91,$1B,$01,$02           ; 586F  PID $1991 -> TCC_slip_speed, 2 bytes
	fcb	$19,$92,$1B,$52,$01           ; 5874  PID $1992 -> shift_inertia_time, 1 byte
	fcb	$19,$93,$1B,$65,$01           ; 5879  PID $1993 -> $1B65, 1 byte
	fcb	$19,$94,$1B,$66,$01           ; 587E  PID $1994 -> $1B66, 1 byte
	fcb	$19,$95,$1B,$67,$01           ; 5883  PID $1995 -> $1B67, 1 byte
	fcb	$19,$96,$1B,$60,$01           ; 5888  PID $1996 -> shift_time_error, 1 byte
	fcb	$19,$97,$1B,$61,$01           ; 588D  PID $1997 -> $1B61, 1 byte
	fcb	$19,$98,$1B,$62,$01           ; 5892  PID $1998 -> $1B62, 1 byte
	fcb	$19,$99,$1B,$63,$01           ; 5897  PID $1999 -> $1B63, 1 byte
	fcb	$19,$9B,$1B,$69,$01           ; 589C  PID $199B -> shift_adapt_value, 1 byte
	fcb	$19,$9C,$1B,$6A,$01           ; 58A1  PID $199C -> shift_adapt_cell_idx, 1 byte
	fcb	$19,$9D,$1B,$88,$01           ; 58A6  PID $199D -> line_pressure_desired, 1 byte
	fcb	$19,$A0,$18,$8F,$01           ; 58AB  PID $19A0 -> shift_ratio_ramp_delay, 1 byte
	fcb	$19,$A3,$F5,$AA,$01           ; 58B0  PID $19A3 -> PID_19A3_fmt_F5AA, 1 byte
	fcb	$19,$AD,$19,$4E,$01           ; 58B5  PID $19AD -> MUX13_trans_temp, 1 byte
	fcb	$19,$B7,$1B,$11,$02           ; 58BA  PID $19B7 -> TCC_slip_target, 2 bytes
	fcb	$19,$D4,$18,$A8,$02           ; 58BF  PID $19D4 -> trans_v18A8, 2 bytes
	fcb	$19,$F5,$1A,$C0,$01           ; 58C4  PID $19F5 -> trans_gear_AT, 1 byte
	fcb	$19,$F9,$00,$63,$01           ; 58C9  PID $19F9 -> SHIFTPAT_SELECT, 1 byte
	fcb	$19,$FA,$1B,$B1,$01           ; 58CE  PID $19FA -> PCS_current_meas, 1 byte
	fcb	$19,$FB,$1B,$AD,$02           ; 58D3  PID $19FB -> FORCE_MTR_ITERM, 2 bytes
	fcb	$19,$FC,$1C,$B3,$02           ; 58D8  PID $19FC -> engine_torque_net, 2 bytes
	fcb	$19,$FD,$18,$77,$02           ; 58DD  PID $19FD -> trans_ratio_measured, 2 bytes
	fcb	$19,$FE,$F5,$BF,$01           ; 58E2  PID $19FE -> PID_19FE_fmt_F5BF, 1 byte
	fcb	$19,$FF,$1A,$E7,$01           ; 58E7  PID $19FF -> tcc_v1AE7, 1 byte
	fcb	$1A,$00,$1B,$B0,$01           ; 58EC  PID $1A00 -> IREF, 1 byte
	fcb	$1A,$01,$18,$C3,$02           ; 58F1  PID $1A01 -> engine_output_ratio, 2 bytes
	fcb	$1A,$13,$00,$7A,$01           ; 58F6  PID $1A13 -> DS_TCCMODE, 1 byte
	fcb	$1A,$18,$1A,$F5,$01           ; 58FB  PID $1A18 -> TCC_PWM_duty_cmd, 1 byte
