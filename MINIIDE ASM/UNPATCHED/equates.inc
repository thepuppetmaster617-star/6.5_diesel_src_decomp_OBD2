; RAM / I/O / register equates (shared by both banks)
ram_v0000                                equ $0000	; inferred name; written by: COP_clock_fail_entry_6119, RESET_entry; read by: COP_clock_fail_entry_6119, RESET_entry
DTC_current_flags                        equ $0001
DTC_passed_this_trip                     equ $0011	; analysis: 0011-001F bit per DTC: test passed this trip (set by DTC_set_clear A=0)
DTC_first_set_flags                      equ $0021
EEPROM_shadow                            equ $0036	; analysis: 0036-0038 RAM shadow of EEPROM 0EE0-0EE2 (stored inverted); $36=0, $37-38=$FFFF on bad EEPROM sum
MEAS_INJ_RSP_196740_RAW                  equ $003A	; OBD1 MEAS_INJ_RSP_196740_RAW [A] | = 0122 = 1.47 ms
MEASURED_INJ_TMG_8192                    equ $003C	; OBD1 MEASURED_INJ_TMG_8192 [B] | = 013f @ idle	 , 016e driving | A225 list1 word50 FUVPDEG+1: Fuel Pump (Lsb) (DEG = N * .088)
egr_v0041                                equ $0041	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, set_EGR_flow_test_progress_F685; read by: -
egr_v0042                                equ $0042	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, set_EGR_flow_test_progress_F685; read by: -
egr_v0043                                equ $0043	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, set_EGR_flow_test_progress_F685; read by: -
egr_v0044                                equ $0044	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, set_EGR_flow_test_progress_F685; read by: -
TDC_TEST_RUNNING                         equ $0045	; OBD1 TDC_TEST_RUNNING [A]
PUMP_BACKUPFLAGS                         equ $0046	; OBD1 PUMP_BACKUPFLAGS [A]
CRUISE_FLAGS_1                           equ $0047	; OBD1 CRUISE_FLAGS_1 [A] | b0 - Cruise Enabled?? | b0 - Cruise Enabled?? | b1 - Set if SWITCH2_INPUTS.b0 SET for *4162 * 25ms | b1 - Set if SWITCH2_INPUTS.b0 SET for *4162 * 25ms | b2 - S
FLAGS0                                   equ $0048	; OBD1 FLAGS0 [A]
FLAGS1                                   equ $0049	; OBD1 FLAGS1 [A]
FLAGS2                                   equ $004A	; OBD1 FLAGS2 [A]
cylbal_diag_flags                        equ $004B	; analysis: b0 = no cylinder at min adjust, b1 = test armed/counting
ENGMODEFLAG                              equ $004C	; OBD1 ENGMODEFLAG [A]
FLAGS3                                   equ $004D	; OBD1 FLAGS3 [C]
RAM_status_resistor                      equ $004E	; OBD1 SWITCH_INPUTS [A] | A225 list1 word16 IDSPC: Iod Port B Input Debounced Status Register bits: b0 ENGINE CRANK 1 = ACTIVE 0 = INACTIVE; b1 BRAKE SWITCH 1 = CLOSED 0 = OPEN; b2 BRAKE SWITCH 1 = ...
IN_1802_debounced                        equ $004F	; OBD1 SWITCH2_INPUTS [A] | A225 list1 word15 IDSPB: Iod Port B Input Debounced Status Register bits: b0 CRUISE ON/OFF SWITCH 1 = ON 0 = OFF; b1 MAN/NORM/PERF SWITCH 1 1 = CLOSED 0 = OPEN; b2 MAN/NOR...
sensor_pullup_range                      equ $0050	; analysis: b0 ECT range, b1 trans temp range; low nibble written to IOR 1807; shadow of IOR 1807 outputs (low nibble written), init from k_50A8
ram_v0051                                equ $0051	; inferred name; written by: COP_clock_fail_entry_6119, RESET_entry, read_sensors_linearize_EEDD; read by: read_sensors_linearize_EEDD
DERATE_LIMP_ENA_FLAGS1                   equ $0052	; OBD1 DERATE_LIMP_ENA_FLAGS1 [A]
DERATE_LIMP_ENA_FLAGS2                   equ $0053	; OBD1 DERATE_LIMP_ENA_FLAGS2 [A]
rpm_v0054                                equ $0054	; analysis: b2 = engine speed rising with zero fuel detected | inferred name; written by: _run_25ms_job, calc_OLD_RPM2_4_8B43, DO_ENG_STOP_SOL, calc_sensor_pullup_range_F827; read by: _run_25ms_job, ...
TASKFLAGS1                               equ $0055	; OBD1 TASKFLAGS1 [A]
task_overrun_flags                       equ $0056	; analysis: b6 160Hz, b3 12.5ms, b4 25ms, b2 50ms, b5 100ms, b1 1s job overrun
sys_state_flags                          equ $0057	; analysis: b0 ?, b1 EEPROM write pending, b2 init done, b3 background tick request (set at EE40), b6 set in bank0 F70F, b7 set at end of reset; b1 = background EEPROM byte write request (serviced by...
EEPROM_write_offset                      equ $0058	; analysis: low byte of EEPROM address ($0E00+n) to rewrite; offset into EEPROM $0E00 for pending RTI write
EEPROM_write_value                       equ $0059	; analysis: byte to write for pending RTI EEPROM write; byte value to program into EEPROM
crank_ITS_flags                          equ $005A	; analysis: b0 crank init, b1 ITS settled at crank position, b3 ITS target computed, b4 ITS error reached 0, b7 set by bank1 87FF (engine running?); b7 backup inj mode active; b1-b3 crank ITS learn s...
brake_rpm_flags                          equ $005B	; analysis: b0 brake applied (debounced), b1 RPM below k_229E; b7 = RPM low for crank split fueling (hyst k_2253/k_2254)
shutdown_flags                           equ $005C	; analysis: b1 = safe shutdown active (set by safe_shutdown_outputs); b1 safe_shutdown_outputs executed
idle_v005D                               equ $005D	; inferred name; written by: idle_fuel_learn, idle_RPM_target_task_F716, calc_idle_RPM_target, calc_RPM_and_engine_mode_9098 +1; read by: baro_from_MAP, idle_RPM_target_task_F716, calc_idle_RPM_target
ram_v005E                                equ $005E	; inferred name; written by: _run_6ms_job; read by: _run_6ms_job
Cal_bit_6_store                          equ $005F	; OBD1 TRANS_PRNDL_POS [A] | b0 - Low | b0 - Low | b1 - Drive 2 | b1 - Drive 2 | b2 - Drive 3 | b2 - Drive 3 | b3 - Drive 4 | b3 - Drive 4 | b4 - Neutral | b4 - Neutral | b5 - Reverse | b5  | A225 li...
PRNDL_prev                               equ $0060	; analysis: previous Cal_bit_6_store
shift_v0061                              equ $0061	; inferred name; written by: calc_upshift_RPM_projection_adapt_E8C2; read by: calc_upshift_RPM_projection_adapt_E8C2
garage_shift_code                        equ $0062	; analysis: 1/2 N->D, 4/8 N->R, $10 D->N, $20 R->N
SHIFTPAT_SELECT                          equ $0063	; OBD1 SHIFTPAT_SELECT [A] | bit 3 = illegal | bit 2 = manual | bit 1 = performance | bit 0 = normal
LAST_SHIFTPAT_SEL                        equ $0064	; OBD1 LAST_SHIFTPAT_SEL [B]
DS_DISCOLD                               equ $0065	; OBD1 DS_DISCOLD [A] | A225 list1 word5 DISCOLD: Previous Diflags bits: b0 1 = ALLOWED UPDATE OF TPS HISTORY BUFFER; b5 1 = FORCE SECOND GEAR WHEN IN D2 AND NOT MAN.
DS_DIFLAGS                               equ $0066	; OBD1 DS_DIFLAGS [A] | A225 list1 word43 DIFLAGS: Discrete Status Flags bits: b0 1 = BRAKE ON 0 = OFF; b1 1 = A/C COMPRESSOR ENGAGED 0 = DISENGAGED; b2 1 = POWER ENRICHMENT ACTIVE 0 = INACTIVE; b4 1...
DS_DIFLAGS_prev                          equ $0067	; analysis: copy of DS_DIFLAGS before update
shift_v0068                              equ $0068	; inferred name; written by: limit_desired_gear_E676; read by: limit_desired_gear_E676
shift_v0069                              equ $0069	; inferred name; written by: INIT_SENSOR_FILTERS_5A15, TOC3_scheduler_ISR_8000, update_trans_diag_enable_fault_summary_A181, calc_powertrain_in_motion_B489 +5; read by: sub_8525, calc_antitheft_delay...
tcc_v006A                                equ $006A	; analysis: b5 = TC slip negative (coast) with hysteresis | inferred name; written by: calc_kickdown_and_load_rate_B3C2, calc_trans_ECT_filtered_B4D4, calc_trans_temp_filtered_B50A, calc_TCC_slip_spe...
trans_v006B                              equ $006B	; inferred name; written by: calc_kickdown_and_load_rate_B3C2, calc_trans_temp_filtered_B50A; read by: diag_P0711_TFT_range_perf_B184, calc_trans_temp_filtered_B50A, calc_TCC_inhibit_flags_E09D
shift_ratio_state1                       equ $006C	; analysis: shift-ratio state bits (with $6D/$6E)
shift_v006D                              equ $006D	; inferred name; written by: calc_shift_ratio_profile_BA38, clear_shift_ratio_states_BD07; read by: calc_shift_ratio_profile_BA38
shift_v006E                              equ $006E	; inferred name; written by: calc_shift_ratio_profile_BA38, clear_shift_ratio_states_BD07; read by: calc_shift_ratio_profile_BA38
pto_v006F                                equ $006F	; analysis: 1 override, 2 PTO, 4 normal, $0C 4WD | inferred name; written by: calc_4WD_and_PTO_flags_B8A4; read by: CALC_OSS_SPEED, calc_output_and_vehicle_speed_982B, Central_Scheduler_part_BDC4, ca...
trans_switch_flags                       equ $0071	; analysis: b0 perf sw, b1 manual sw, b7 cruise not engaged (state<=2)
trans_switch_flags_prev                  equ $0072	; analysis: previous $71 for change detect
trans_v0073                              equ $0073	; inferred name; written by: calc_trans_state_index_B635; read by: calc_TCC_apply_speed_DBC6, calc_TCC_release_request_E20A
trans_v0074                              equ $0074	; inferred name; written by: calc_trans_state_index_B635; read by: calc_shift_speed_load_based_EAF1
trans_v0075                              equ $0075	; inferred name; written by: calc_trans_state_index_B635; read by: calc_TCC_apply_speed_DBC6, calc_TCC_release_request_E20A, calc_shift_speed_fixed_EB47, calc_shift_RPM_target_EB8E
shift_v0076                              equ $0076	; inferred name; written by: calc_trans_state_index_B635; read by: calc_TCC_apply_speed_DBC6, calc_TCC_release_request_E20A, calc_shift_speed_load_based_EAF1, calc_shift_speed_fixed_EB47 +1
shift_event_flags                        equ $0077	; analysis: b0 upshift this pass, b3 downshift this pass
shift_request_reason                     equ $0078	; analysis: b0 normal up, b1 kickdown up, b2 PRNDL up, b3 forced up ($1ABA); b4-b7 same for downshift
shift_v0079                              equ $0079	; inferred name; written by: limit_desired_gear_E676; read by: limit_desired_gear_E676
DS_TCCMODE                               equ $007A	; OBD1 DS_TCCMODE [A] | A225 list1 word25 TCCMODE: Tcc Mode Word Flags bits: b0 1 = TCC IS BEING FORCED OFF; b1 1 = TCC ENABLE SOLENOID VALID; b2 1 = LOW THRESHOLD FOR COPETCC SELECTED; b3 1 = USE HY...
DS_TCCMODE_prev                          equ $007B	; analysis: previous DS_TCCMODE value saved by the state machine
TCC_cond_flags                           equ $007C	; analysis: b0 any inhibit, b2 trans warm (hyst), b4 apply allowed, b5 release, b6 apply speed met, b7 release request
tcc_v007D                                equ $007D	; analysis: b0-b2 $1B06 bands, b4 cleared in D69C, b5 FMEM/cold inhibit, b6 FMEM gear flag, b7 light-load flag | inferred name; written by: calc_press_cmd_min_D69C, calc_TCC_cond_flags_D70C, trans_li...
TCC_inhibit_reasons                      equ $007E	; analysis: b0 range/gear, b1 trans temp, b2 coolant temp, b3 brake, b4 $6B.0, b5 post-shift timer, b7 $6A.5
TCC_inhibit_reasons2                     equ $007F	; analysis: b0 post-shift timer (alt), b1 $6A.7, b2 cold trans, b3 FMEM gear, b6 d_7F11.0, b7 in 1st gear
TCC_status_flags                         equ $0080	; analysis: b4 timed release done, b5 apply-delay preload request, b6 A/C on, b7 trans hot
TCC_release_reasons                      equ $0081	; analysis: b0 A/C low speed, b1 $6A.3 event, b2 below release VSS, b3 timed release, b4 hot low speed, b5 negative slip
TCC_mode_request                         equ $0082	; analysis: one-hot requested TCC mode (row index into d_DDFA)
tcc_v0083                                equ $0083	; analysis: b0 slip mode allowed (timer), b2 cleared on reset, b3 slip mode latched, b7 set in D69C | inferred name; written by: calc_TCC_cond_flags_D5CF, calc_press_cmd_min_D69C, trans_line_pressure...
tcc_v0084                                equ $0084	; inferred name; written by: trans_line_pressure_calc, tcc_task_D96A, calc_TCC_slip_target_DE32; read by: trans_line_pressure_calc, tcc_task_D96A
shift_v0085                              equ $0085	; analysis: b1 RPM-based shift active, b2 adapt measurement pending | inferred name; written by: calc_engine_speed_tracking_B6CF, downshift_timing_monitor_D1E6, upshift_timing_monitor_D382, calc_shif...
PCS_ctrl_flags                           equ $0086	; analysis: b4 loop enable, b5 saturated with low battery, b7 saturated with good battery (fault); b6 PCS table select (hysteresis), b4/b3 PCS low-drive shutoff delay
fuel_v0087                               equ $0087	; inferred name; written by: calc_engine_torque_est_from_NA_fuel_derate_BARO_C586; read by: calc_fuel_quantity
TRANS_FMEM_ENA_FLAGS                     equ $0088	; OBD1 TRANS_FMEM_ENA_FLAGS [A]
TRANS_FMEM_ENA2_FLAGS                    equ $0089	; OBD1 TRANS_FMEM_ENA2_FLAGS [B] | b4 - Use Torque Reduction when ??? | b4 - Use Torque Reduction when ???
shift_v008A                              equ $008A	; inferred name; written by: calc_SHIFTPAT_SELECT_part_A416, run_trans_diags_and_tasks_part_A458, set_fmem_P0751_A477, clear_flag_8A_bit5_A491 +4; read by: shift_solenoid_output, P1810_enable_conditi...
pto_v008B                                equ $008B	; inferred name; written by: set_fmem_P1875_A484; read by: calc_4WD_and_PTO_flags_B8A4
trans_v008C                              equ $008C	; inferred name; written by: trans_load_filter, set_EGR_flow_test_progress_F685; read by: trans_load_filter
serial_v008D                             equ $008D	; inferred name; written by: msg_request_set_irqsafe_6EDE, calc_J1850_DLC_cmd_C82A, b1_sub_C892, J1850_rx_message_process_CBFD +6; read by: J1850_rx_message_process_CBFD, calc_J1850_rx_len_err_count_...
serial_v008E                             equ $008E	; inferred name; written by: sub_F40E, calc_J1850_DLC_cmd_C8DD, calc_J1850_rx_len_err_count_CD34, J1850_mode28_disable_normal_comm_DE85 +6; read by: msg_request_set_6EBA, msg_request_set_irqsafe_6EDE...
task_toggle_25ms                         equ $008F	; analysis: b0 toggled each 12.5 ms pass to run some jobs every other pass
serial_v0091                             equ $0091	; inferred name; written by: sub_F40E, ignition_off_powerdown_F615, b1_sub_C892, J1850_rx_message_process_CBFD +4; read by: b1_sub_C892, J1850_mode36_download_execute_CA64, J1850_rx_message_process_C...
serial_v0092                             equ $0092	; inferred name; written by: J1850_diag_service_dispatch_D449, calc_diag_handler_desc_ptr_D556, J1850_diag_session_timer_EE4C; read by: DTC_set_clear, b1_sub_F902, b1_sub_F926
egr_v0093                                equ $0093	; inferred name; written by: diag_EGR_MAF_and_misc_DTCs_7672, set_EGR_flow_test_progress_F685; read by: -
vss_v0094                                equ $0094	; inferred name; written by: -; read by: sub_8525, run_VSS_and_battery_diag_tests_C7E0
KAM_lost_flags                           equ $0095	; analysis: b0 KAM cleared at this reset (drives P0603)
idle_v0096                               equ $0096	; inferred name; written by: idle_RPM_target_task_F716, calc_idle_RPM_target; read by: idle_fuel_learn, set_idle_RPM_target, PID_01_monitor_status_F013
rpm_v0097                                equ $0097	; analysis: time from cam edge to CKP edge (cranking) | inferred name; written by: CKP_4X_input_capture_isr_81ED; read by: CKP_4X_input_capture_isr_81ED
rpm_v0099                                equ $0099	; inferred name; written by: CKP_4X_input_capture_isr_81ED; read by: CKP_4X_input_capture_isr_81ED, CKP_isr_load_TIO_fuel_counters_8680, diag_P0251_P0335_890E
rpm_v009B                                equ $009B	; inferred name; written by: CKP_4X_input_capture_isr_81ED; read by: -
rpm_v009D                                equ $009D	; inferred name; written by: CKP_4X_input_capture_isr_81ED; read by: CKP_4X_input_capture_isr_81ED
rpm_v009E                                equ $009E	; inferred name; written by: CKP_4X_input_capture_isr_81ED; read by: CKP_4X_input_capture_isr_81ED
rpm_v009F                                equ $009F	; inferred name; written by: diag_P0251_P0335_890E; read by: CKP_4X_input_capture_isr_81ED
rpm_v00A0                                equ $00A0	; analysis: cranking delay counter, kept >= $22 above crank PW | inferred name; written by: CKP_4X_input_capture_isr_81ED; read by: CKP_4X_input_capture_isr_81ED, CKP_isr_load_TIO_fuel_counters_8680
rpm_v00A2                                equ $00A2	; analysis: extended time of last CKP edge | inferred name; written by: CKP_4X_input_capture_isr_81ED; read by: CKP_4X_input_capture_isr_81ED, diag_P0251_P0335_890E
rpm_v00A4                                equ $00A4	; analysis: extended time of last cam edge | inferred name; written by: diag_P0251_P0335_890E; read by: CKP_4X_input_capture_isr_81ED
rpm_v00A6                                equ $00A6	; inferred name; written by: CKP_4X_input_capture_isr_81ED; read by: CKP_4X_input_capture_isr_81ED
ram_v00A8                                equ $00A8	; inferred name; written by: diag_P0251_P0335_890E; read by: diag_P0251_P0335_890E
rpm_v00AA                                equ $00AA	; inferred name; written by: CKP_4X_input_capture_isr_81ED; read by: CKP_4X_input_capture_isr_81ED
rpm_v00AC                                equ $00AC	; inferred name; written by: CKP_4X_input_capture_isr_81ED; read by: CKP_4X_input_capture_isr_81ED
PUMP_CAL_ADJ_CRANKING                    equ $00AE	; OBD1 PUMP_CAL_ADJ_CRANKING [A]
COMMAND_PW_CRANKING                      equ $00AF	; OBD1 COMMAND_PW_CRANKING [C]
ram_v00B1                                equ $00B1	; inferred name; written by: _run_25ms_job, DO_ENG_STOP_SOL; read by: _run_25ms_job, DO_ENG_STOP_SOL, diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A +7
closure_stale_ctr                        equ $00B2	; analysis: consecutive invalid/repeated closure-time reads
TCC_mode_stable_count                    equ $00B3	; analysis: 25 ms ticks since DS_TCCMODE changed, saturates 255
gear_stable_count                        equ $00B4	; analysis: 25 ms ticks since gear changed, saturates 255
last_TCC_mode                            equ $00B5	; analysis: DS_TCCMODE previous pass
OLD_RPM2_4                               equ $00B6	; OBD1 OLD_RPM2_4 [A]
DELTA_RPM_COUNT                          equ $00B8	; OBD1 DELTA_RPM_COUNT [A]
rpm_v00B9                                equ $00B9	; analysis: auto trans slip events during zero-fuel RPM rise check | inferred name; written by: calc_OLD_RPM2_4_8B43, DO_ENG_STOP_SOL; read by: calc_OLD_RPM2_4_8B43
last_gear                                equ $00BA	; analysis: gear from previous 25 ms pass (AT gear or calc MT gear)
LAST_MEASURED_CLOSURE                    equ $00BB	; OBD1 LAST_MEASURED_CLOSURE [A] | 1.47 ms
rpm_v00BD                                equ $00BD	; analysis: count of RPM jumps >= kw_2757 during zero fuel | inferred name; written by: calc_OLD_RPM2_4_8B43; read by: calc_OLD_RPM2_4_8B43
ext_latch_0C04_shadow                    equ $00BE	; analysis: shadow of output latch $0C04: b7-4 AMUX channel select, b2/b1 other outputs; shadow of output latch $0C04: hi nibble AMUX select; .0 A/C clutch relay; .1 lift pump? ; .2 temp-based output
eeprom_v00BF                             equ $00BF	; analysis: b0 idle/fail?, b4/b5 result bits, b6 module present, b7 request | inferred name; written by: calc_antitheft_delay_tmr_8DA8, calc_antitheft_delay_tmr_8E14, calc_EEPROM_shadow_8E44, calc_an...
EGR_cl_flags                             equ $00C0	; analysis: see bits
EGR_inhibit_flags                        equ $00C1	; analysis: see bits
EGR_fault_status_word                    equ $00C3	; analysis: b0-b4,b6 per-check fail bits; b4,b5,b6,b7 flow-test result faults; cleared together with C4-C6; word C3/C4 decoded against cal masks 375C.. for EGR/MAF DTCs
egr_v00C4                                equ $00C4	; inferred name; written by: diag_EGR_MAF_and_misc_DTCs_7672, diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, diag_P0107_P0108_P0112_etc_B3BD +1; read by: diag_P0102_P0103_P0107_etc...
EGR_flow_test_progress                   equ $00C5	; analysis: b0 stage1 done, b1 stage2 done, b2/b3 result latched; b0 test active, b1/b2 steps, b3,b4,b5 step done, b6 baro sample done
egr_v00C6                                equ $00C6	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, set_EGR_flow_test_progress_F685; read by: diag_EGR_MAF_and_misc_DTCs_7672, diag_P0102_P0103_P0107_etc_AE...
diag_misc_flags                          equ $00C7	; analysis: b0 flow-test conditions met, b3 RPM steady, b5 flow-test reset latch, b6 P0126 test done/aborted; b0 force EGR off, b1 force EGR on, b2 baro sampled, b4 test enabled
egr_v00C8                                equ $00C8	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A; read by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A
egr_v00C9                                equ $00C9	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A; read by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A
egr_v00CA                                equ $00CA	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A; read by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A
egr_v00CB                                equ $00CB	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, set_EGR_flow_test_progress_F685; read by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A
egr_v00CC                                equ $00CC	; inferred name; written by: EGR_learn_init_at_reset_750F, diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, set_EGR_flow_test_progress_F685; read by: diag_P0102_P0103_P0107_etc_AE76,...
egr_v00CD                                equ $00CD	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A; read by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A
egr_v00CE                                equ $00CE	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A; read by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A
egr_v00CF                                equ $00CF	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A; read by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A
egr_v00D0                                equ $00D0	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, set_EGR_flow_test_progress_F685; read by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A
egr_learn_cells_high                     equ $00D1
egr_learn_cells_low                      equ $00D2
egr_v00D3                                equ $00D3	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A; read by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A
egr_v00D4                                equ $00D4	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A; read by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A
warmup_energy_acc                        equ $00D5	; analysis: word accumulator of (RPM/8)*fuel_qty for P0126; carried into $1A2C/$1A2D in bank0 7801
egr_v00D7                                equ $00D7	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A; read by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A
CYL_BAL_ADAPT                            equ $0100	; OBD1 CYL_BAL_ADAPT [A] | fffe ffff 0002 0000 0002 0000 ffff | Inj pump timing around 25 deg, inj resp 1.7ms, des timing around 6deg, des fuel about 10mm3
BKUP_MEAS_INJ_TIMING                     equ $0110	; OBD1 BKUP_MEAS_INJ_TIMING [A]
IC4_LATENCY                              equ $0112	; OBD1 IC4_LATENCY [C]
IC3_LATENCY                              equ $0114	; OBD1 IC3_LATENCY [C]
PUMP_TO_TDC_TIME_BKUP                    equ $0116	; OBD1 PUMP_TO_TDC_TIME_BKUP [A] | = 64e3
MEASURED_INJ_TIMING                      equ $0118	; OBD1 MEASURED_INJ_TIMING [A] | = 3e (=6.2 crank degrees)	    5a,5a,59 driving | A225 list1 word48 FUVTM: Measured Injection Timing (DEG = N * .1)
ITS_TIMING_POSITION                      equ $0119	; OBD1 ITS_TIMING_POSITION [A] | = 3e
MEAS_INJ_TMG_FILT                        equ $011A	; OBD1 MEAS_INJ_TMG_FILT [A] | = 3f
INJ_RESPONSE_230556                      equ $011C	; OBD1 INJ_RESPONSE_230556 [A] | = 0156,  015a driving | A225 list1 word53 CLVTME+1: Closure Time (Lsb) (MILLI SECS = N * .005)
rpm_v011E                                equ $011E	; inferred name; written by: read_sensors_linearize_EEDD; read by: read_sensors_linearize_EEDD, CKP_4X_input_capture_isr_81ED, calc_ff_next_slot_FA02
idle_learn_PN_AC_on                      equ $0120
idle_learn_PN_AC_off                     equ $0121
idle_learn_drive_AC_on                   equ $0122	; OBD1 DRAGTQ_ACOFF_DRIVE [A] | = fd
idle_learn_drive_AC_off                  equ $0123	; OBD1 DRAGTQ_ACON_DRIVE [A] | = 09 (new rom)
DRAGTQ_ADJUST                            equ $0124	; OBD1 DRAGTQ_ADJUST [A] | = 09 (new rom)
DRAGTQ_LEARN_TMR                         equ $0131	; OBD1 DRAGTQ_LEARN_TMR [A]
ENGINE_DRAGTQ                            equ $0132	; OBD1 ENGINE_DRAGTQ [A]
GLOW_TIMER_NV                            equ $0133	; OBD1 GLOW_TIMER_NV [B]
GLOW_TIMER_1                             equ $0134	; OBD1 GLOW_TIMER_1 [A]
freeze_frame_slots                       equ $0135	; analysis: 4 slots x 62 bytes (0135-022C): +0 P-code, +35 dist first, +37 dist last, +39/3A/3B trip counters, +3C DTC record
ff_slot_type                             equ $022D	; analysis: 022D-0230: 0 free, 1 MIL-class code, 2 non-MIL code
mode2_freeze_frame                       equ $0231	; analysis: 0231-026E copy of the first confirmed MIL-class freeze frame (OBD mode $02)
warmups_no_MIL_fault                     equ $026F	; analysis: warm-up cycles without MIL-class failure; 40 -> erase
warmups_no_nonMIL_fault                  equ $0270	; analysis: warm-up cycles without non-MIL failure; 40 -> erase
ff_next_slot                             equ $0271	; analysis: round-robin freeze-frame slot index 0..3
VSS_pulse_total_hi                       equ $0272	; analysis: 32-bit accumulator 0272-0275 of VSS increments, zeroed on code clear; high word of 32-bit VSS pulse accumulator
ram_v0273                                equ $0273	; inferred name; written by: -; read by: calc_distance_since_DTC_clear_F28B, calc_PID_data_buf_F2BD
VSS_pulse_total_lo                       equ $0274	; analysis: low word of 32-bit VSS pulse accumulator
egr_v0276                                equ $0276	; analysis: init k_382A*16 at clear/reset; used at C79C | inferred name; written by: calc_TASKFLAGS1_part_C77E, set_EGR_flow_test_progress_F685, b1_sub_F802; read by: calc_TASKFLAGS1_part_C77E, PID_0...
egr_v0277                                equ $0277	; analysis: init k_382B at clear/reset; used at C7D6 | inferred name; written by: calc_TASKFLAGS1_part_C77E, set_EGR_flow_test_progress_F685, b1_sub_F802; read by: calc_TASKFLAGS1_part_C77E, PID_01_m...
DTC_confirmed_flags                      equ $0278	; analysis: 0278-0286 bit per DTC: confirmed/MIL-qualified code
DTC_history_flags                        equ $0287
DTC_test_incomplete                      equ $0296	; analysis: 0296-02A4 readiness: set to ~DTC_disable_mask on clear, bit cleared when test passes
DTC_MIL_request                          equ $02A5	; analysis: 02A5-02B3 bit per DTC: MIL requested
DTC_failed_last_trip                     equ $02B4	; analysis: 02B4-02C2 pending flags, updated at end of trip (FBDD)
startup_coolant_temp                     equ $02E1	; analysis: ECT latched at start (bank0 EDA3); P0126 enable window; coolant temp at start (compared with $18DB); start value compared with [18DA] for warm-up cycle
ram_v02E2                                equ $02E2	; analysis: copy of word 18EB at lamp update; nonzero sets $10.5 (trip qualifier for MIL-off counting) | inferred name; written by: calc_sensor_pullup_range_F827; read by: -
trans_v02E6                              equ $02E6	; inferred name; written by: convert_trans_temp_EFE8; read by: -
keepalive_RAM_checksum                   equ $02E9	; analysis: CHECKSUM_ADAPT result stored at power-down, compared at reset
shift_delay_adapt_12                     equ $02EB	; analysis: 4 cells (by trans temp band) per shift: 02EB 1-2, 02EF 2-3, 02F3 3-4; $80 = 0
shift_adapt_checksum                     equ $02F7	; analysis: kept consistent when cells change; checked at 91AD
KAM_garage_adapt_chksum                  equ $0316	; analysis: checksum byte kept with each cell write
line_press_adapt_cells                   equ $0317	; analysis: 8 learned NV cells (0317-031E), index $1876/2; checksum at 031F
line_press_adapt_chksum                  equ $031F	; analysis: checksum byte for adapt cells, kept by sum-preserving update
TRANS_shift_adapt_cells_g1               equ $0320	; analysis: 17 cells by torque axis; also 0331 (2-3), 0342 (3-4)
TRANS_shift_adapt_cells_g2               equ $0331
TRANS_shift_adapt_cells_g3               equ $0342
KAM_shift_adapt_chksum                   equ $0353	; analysis: minus the sum of the shift adapt cells
ROM_sum_accum                            equ $0354	; analysis: running 16-bit ROM checksum in background
ROM_sum_ptr                              equ $0356	; analysis: next ROM address to sum; 0 = bank complete
ram_v0358                                equ $0358	; inferred name; written by: -; read by: run_100ms_engine_tasks_EC95
cylbal_v0416                             equ $0416	; analysis: last cylinder speed difference stored when [$57].0 set (test/debug) | inferred name; written by: CYLBAL_ADJUST_AND_DIAG, cylbal_adapt_sat_tail_9B2A; read by: -
fuel_v048F                               equ $048F	; inferred name; written by: CKP_isr_load_TIO_fuel_counters_8680; read by: -
fuel_v0491                               equ $0491	; inferred name; written by: CKP_isr_load_TIO_fuel_counters_8680; read by: -
ram_v0493                                equ $0493	; inferred name; written by: _run_12ms_job; read by: -
ram_v0494                                equ $0494	; inferred name; written by: run_100ms_engine_tasks_EC95; read by: -
dev_hook_0600                            equ $0600	; factory development hook area $0600-$07FF (not fitted in production). Signature $7E06 (reset 620F) / $0AED (TOC3 8041) or sys_state_flags.0 (never set) enable calls into it | inferred name; written...
J1850_DLC_cmd                            equ $0C02	; analysis: J1850 controller command/status: writes $E000 reset, $8000, $1003 4x mode; bit3 tx status; J1850 interface chip command register ($14 start frame, $0C last byte); external J1850 controlle...
J1850_DLC_data                           equ $0C03	; analysis: J1850 interface chip transmit data register
ext_output_latch_AMUX                    equ $0C04	; analysis: external write-only latch; high nibble = AMUX channel
eeprom_security_seed                     equ $0E00	; analysis: HC11F1 EEPROM; word sent as seed
eeprom_security_key                      equ $0E02	; analysis: HC11F1 EEPROM; expected key
tdc_v0EE3                                equ $0EE3	; inferred name; written by: -; read by: check_EEPROM_sum_TDC_offset_5974
PORTA                                    equ $1000	; OBD1 PORTA [A] | A225 list1 word13 IOSPA: Gmp6 Port A bits: b0 ENGINE SPEED; b1 INPUT SPEED; b2 OUT SPEED; b3 OPTICAL SENSOR; b4 GMP6 FUEL 1 = ON O = OFF; b5 TIO FUEL 1 = ON O = OFF; b6 TCC PWM 1 =...
PORTG_PG3_bank_select                    equ $1002	; OBD1 PORTG [A] | A225 list1 word14 IOSPG: Gmp6 Port G bits: b0 ENGINE SHUT OFF RELAY 1 = ON O = OFF; b1 STEPPER MOTOR CONTROL W1; b2 STEPPER MOTOR CONTROL W2; b3 SXR ENABLE STATUS; b7 IOR A10 ADDRE...
DDRG                                     equ $1003
PORTB                                    equ $1004
PORTF                                    equ $1005
PORTC                                    equ $1006
DDRC                                     equ $1007
PORTD_PD5_powerdown                      equ $1008
DDRD                                     equ $1009
PORTE                                    equ $100A
CFORC                                    equ $100B
OC1M                                     equ $100C
OC1D                                     equ $100D
TCNT                                     equ $100E	; OBD1 TCNT [A]
TIC1_VSS_C15                             equ $1010
TIC2_trans_input_shaft_C12               equ $1012
TIC3_CMP_8X_lowres                       equ $1014
TOC1                                     equ $1016
TOC2_TCC_PWM                             equ $1018	; TOC2 is NOT used by this OS (never written, OC2 vector = rti, TCTL1 OM2/OL2 = 0). OBD1 made the TCC PWM here in software (OC2 ISR on PA6, pin C215-C11); OBD2 moved the TCC PWM to the IOR PWM at 180...
TOC3_sched_160Hz_inj_disable             equ $101A
TOC4_backup_injector_PW                  equ $101C	; OBD1 TOC4 [A]
TIC4_CKP_4X                              equ $101E
TCTL1                                    equ $1020
TCTL2                                    equ $1021
TMSK1                                    equ $1022	; OBD1 TMSK1 [A]
TFLG1                                    equ $1023
TMSK2                                    equ $1024	; OBD1 TMSK2 [A]
TFLG2                                    equ $1025	; OBD1 TFLG2 [A]
PACTL                                    equ $1026
PACNT_VSS_4004ppm                        equ $1027
SPCR                                     equ $1028
SPSR                                     equ $1029	; OBD1 SPSR [A]
SPDR                                     equ $102A	; OBD1 SPDR [A]
BAUD                                     equ $102B
SCCR1                                    equ $102C
SCCR2                                    equ $102D
SCSR                                     equ $102E
SCDR                                     equ $102F
ADCTL                                    equ $1030	; OBD1 ADCTL [A]
ADR1                                     equ $1031	; OBD1 ADR1 [A]
ADR2                                     equ $1032	; OBD1 ADR2 [A]
ADR3                                     equ $1033	; OBD1 ADR3 [A]
ADR4                                     equ $1034	; OBD1 ADR4 [A]
OPTION_REG                               equ $1039
COPRST                                   equ $103A	; OBD1 COPRST [A]
PPROG                                    equ $103B
HPRIO                                    equ $103C
INIT_REG                                 equ $103D
TEST1                                    equ $103E
CONFIG_REG                               equ $103F
MAF_pulse_counter                        equ $140A
MAF_time_last_pulse                      equ $140C
closure_time_response                    equ $1472
timing_delay_counter                     equ $147C
Fuel_quantity_counter                    equ $147E
split_pulse_delay_counter                equ $1480
pilot_quantity_counter                   equ $1482
TIO_handshake                            equ $14DC	; analysis: TIO coprocessor alive word, expected $00A5 (P0606 check)
ODM_chip_select                          equ $16F8
ODM_chip_select_16FA                     equ $16FA
IOR_1800                                 equ $1800
IOR_1802_AMUX                            equ $1802
IOR_1804                                 equ $1804
IOR_COP                                  equ $1806	; OBD1 IOR_COP [A] | watchdog
IOR_1807_MIL_RES_TRANSPU_IATPU           equ $1807
PWM_PCS_control                          equ $1808	; IOR PWM pair 1808 freq / 1809 duty. Behaves as the 4L80E TCC PWM solenoid: 1809 = 0 on brake and when the TCC command is 0, duty via the duty-vs-pressure curves 4585/45A7. The PCS force-motor curre...
PWM_boost_modulator                      equ $180A
PWM_4l60e                                equ $180C	; IOR PWM pair 180C freq / 180D duty: the 4L60E 3-2 shift solenoid channel on the OBD1 board (pin C217A-A2, init freq $7A ~50 Hz). This OS only zeroes it at reset (cal tbl_IOR_init_5099: $50B2 freq, ...
EGR_frequency                            equ $180E
EGR_PWM_duty                             equ $180F	; OBD1 EGR_DUTY_CYCLE [A] | A225 list1 word51 EGWPWP: Egr Duty Cycle  (L49,L56) (%DC = N/2.56)
RAM_valid_signature                      equ $1810	; analysis: word $AA55 when RAM survived (no power loss)
GLOW_PLUG_STATE                          equ $1812	; OBD1 GLOW_PLUG_STATE [A]
glow_ctrl_temp                           equ $1813	; OBD1 STARTUP_ECTS [B]
GLOW_TIME_NEEDED                         equ $1814	; analysis: ~GLOW_TIMER_NV minus residual heat; scales preglow/afterglow | OBD1 GLOW_TIME_NEEDED [A] | A225 list2 word17 GPVDELH: Glow Plug Net Heat Gain (% GAIN = N/2.56)
glow_residual_heat                       equ $1815	; analysis: from tbl2D_GLOW_3084 vs GLOW_TIMER_1 (time since glow ended)
GLOW_TIMER_3_LIM                         equ $1816	; analysis: preglow time target (ticks, 10 Hz) | OBD1 GLOW_TIMER_3_LIM [A]
GLOW_TIMER_3                             equ $1817	; analysis: preglow elapsed ticks | OBD1 GLOW_TIMER_3 [A]
GLOW_BASE_TIME                           equ $1818	; analysis: uncapped preglow time from 3D tables | OBD1 GLOW_BASE_TIME [A]
GLOW_TIMER_4                             equ $1819	; OBD1 GLOW_TIMER_4 [A]
glow_v181A                               equ $181A	; inferred name; written by: glow_state1_preglow_FA6F; read by: glow_state1_preglow_FA6F
afterglow_on_time                        equ $181B	; analysis: relay on-time per 30-tick afterglow cycle, decays while running
afterglow_on_time_min                    equ $181C	; analysis: decay floor = on-time*k_3074/256
GLOW_TIMER_5                             equ $181D	; OBD1 GLOW_TIMER_5 [A]
GLOW_TIMER_2                             equ $181E	; OBD1 GLOW_TIMER_2 [A]
glow_v181F                               equ $181F	; inferred name; written by: run_100ms_engine_tasks_EC95; read by: run_100ms_engine_tasks_EC95
eeprom_v1844                             equ $1844	; inferred name; written by: EEPROM_program_byte; read by: -
eeprom_v1846                             equ $1846	; inferred name; written by: EEPROM_program_byte; read by: -
eeprom_v1848                             equ $1848	; inferred name; written by: EEPROM_program_byte; read by: -
eeprom_v184A                             equ $184A	; inferred name; written by: EEPROM_program_byte; read by: -
eeprom_v184C                             equ $184C	; inferred name; written by: EEPROM_program_byte; read by: -
eeprom_v184E                             equ $184E	; inferred name; written by: EEPROM_program_byte; read by: -
eeprom_v1850                             equ $1850	; inferred name; written by: EEPROM_program_byte; read by: -
eeprom_v1852                             equ $1852	; inferred name; written by: EEPROM_program_byte; read by: -
eeprom_v1854                             equ $1854	; inferred name; written by: EEPROM_program_byte; read by: -
Working_counter                          equ $1856
serial_v1857                             equ $1857	; analysis: cleared when P0601 is set; nonzero allows P0601 clear at startup | inferred name; written by: Main_task_scheduler, diag_ROM_checksum_P0601_6398; read by: diag_ROM_checksum_P0601_6398, J18...
TDC_REF_OFFSET                           equ $1858	; OBD1 TDC_REF_OFFSET [B] | A225 list1 word55 TMVADVAR: Advance (Cam Crank) Variability (Lsb) (DEG = N * .088 (N IS SIGNED))
TDC_offset_valid_marker                  equ $185A	; analysis: $AC = learned offset valid, $BD = defaulted (EEPROM 0E62 inverted); $AC learned OK, $BD not learned / learned with P1214
PUMP_CAL_FLAG                            equ $185B	; analysis: $AC = Pump_Cal_Ptr already selected/validated | OBD1 PUMP_CAL_FLAG [A]
Pump_Cal_Ptr                             equ $185C	; OBD1 Pump_Cal_Ptr [A]
EGR_learn_active                         equ $185E	; analysis: active learn multiplier ($80=1.0); 185E-1871 keep-alive block
EGR_learn_cell_idx                       equ $1860	; analysis: b0-1 RPM band, b2-3 load band
EGR_learn_cells                          equ $1862	; analysis: 16 cells 1862-1871, $80 = 1.0
EGR_learn_checksum                       equ $1872	; analysis: 1 + sum(185E..1871)
safe_limit_timer1                        equ $1873	; analysis: countdown, then 1874; loaded from CAL_SAFE_LIM_TM1 on high-power garage shift; non-zero -> timed safety fuel limit applied fully
safe_limit_timer2                        equ $1874	; analysis: blend timer for the safety fuel limiter, scaled by CAL_SAFE_LIM_TM2; loaded from CAL_SAFE_LIM_TM2 on high-power garage shift
fuel_v1875                               equ $1875	; analysis: last max fuel while limiter inactive; base for the limited max | inferred name; written by: fuel_max_governor_speedlimit, fuel_max_governor_ramp_frag_94FC; read by: fuel_max_governor_ramp...
trans_state_index                        equ $1876	; analysis: gear*4 (+2 TCC/mode), 0 in Reverse; word index for per-state tables; gear*4 (+2 when released/slipping), 0 in reverse
trans_ratio_measured                     equ $1877	; analysis: 16-bit ratio-like value from input speed; compared per gear to detect shift phases; gear ratio used by diags, 3.13 fixed ($2000 = 1.0), written by trans_task_B835; gear ratio x8192 (2.48 ...
trans_ratio_measured_1879                equ $1879	; analysis: input speed / output speed ratio; input speed / output speed, 3.13 fixed
pcs_v187B                                equ $187B	; inferred name; written by: calc_trans_speed_ratios_B94A; read by: pcs_task_BDF4, pcs_task_C046, pcs_task_C18B, calc_shift_start_load_CDEF +1
trans_v187D                              equ $187D	; inferred name; written by: calc_trans_speed_ratios_B94A; read by: -
turbine_speed_expected                   equ $187E	; analysis: output speed x gear ratio
trans_v1880                              equ $1880	; inferred name; written by: calc_trans_speed_ratios_B94A; read by: calc_trans_speed_ratios_B94A
turbine_speed_error                      equ $1882	; analysis: turbine - expected turbine, >=0; turbine speed minus expected speed from output*gear ratio
egr_v1883                                equ $1883	; inferred name; written by: -; read by: line_press_adapt_slip_integrator_D0AD
output_speed_filtered                    equ $1884	; analysis: 16-bit filtered vehicle speed (hi=1884, lo=1885); filtered output shaft speed (from $1CB3), max $3FF; filtered vehicle speed from VSS period (hi-res), used in diag windows; filtered word ...
ram_v1885                                equ $1885	; inferred name; written by: -; read by: sub_D91D
PRNDL_stable_timer                       equ $1886	; analysis: counts since PRNDL range last changed (saturating); counts since last PRNDL change (cleared on change at 95D1); saturating counter, reset on PRNDL change; ticks since range (Cal_bit_6_sto...
TC_speed_ratio                           equ $1887	; analysis: turbine/engine x256
trans_v1888                              equ $1888	; analysis: tcurve_387C[TC speed ratio] | inferred name; written by: calc_trans_speed_ratios_B94A; read by: -
trans_ratio_commanded                    equ $1889	; analysis: commanded/ramped gear ratio x8192 during shift
shift_ratio_ramp_len                     equ $188B	; analysis: ramp length ticks
shift_ratio_timer                        equ $188C	; analysis: ticks since state change, saturating
shift_v188D                              equ $188D	; inferred name; written by: calc_shift_ratio_profile_BA38; read by: calc_shift_ratio_profile_BA38
shift_v188E                              equ $188E	; inferred name; written by: calc_shift_ratio_profile_BA38; read by: calc_shift_ratio_profile_BA38
shift_ratio_ramp_delay                   equ $188F	; analysis: delay ticks before ramp
shift_ratio_ramp_left                    equ $1890	; analysis: remaining ramp ticks
trans_v1891                              equ $1891	; inferred name; written by: trans_init_at_reset_9114; read by: -
shift_ratio_target                       equ $1892	; analysis: target ratio x8192
shift_ratio_start                        equ $1894	; analysis: start ratio x8192
trans_v1896                              equ $1896	; analysis: signed adder applied to high byte of RAW_VEHICLE_SPEED | inferred name; written by: -; read by: calculate_st_trans_shaft_speeds, calc_output_and_vehicle_speed_982B
engine_speed_raw_trans                   equ $1897	; analysis: engine_RPM * 150 scaled; measurement for speed tracking filter; engine_RPM * 150/256; unfiltered engine speed word fed to engine_speed_filtered
ISS_period_struct                        equ $1899	; analysis: 9-byte pulse-period struct for input shaft (sub_96F9)
trans_input_speed_raw                    equ $189D	; analysis: input shaft speed used by P0716/P0717 (Y+4 of block $1899)
input_shaft_speed_raw                    equ $18A2	; analysis: measured or estimated input shaft speed
trans_input_speed_filtered               equ $18A4
trans_input_speed_held                   equ $18A6	; analysis: last good input speed, frozen while P0716 fail counter $1BFC != 0
trans_v18A8                              equ $18A8	; analysis: input speed, ratio-scaled in top gear | inferred name; written by: trans_task_9676; read by: filter_turbine_speed_B6AD, calc_TCC_slip_speed_B7F8
TRANS_TURBINE_SPEED                      equ $18AA	; OBD1 TRANS_TURBINE_SPEED [B]
TRANS_OUTPUT_SPEED_RAW                   equ $18B0	; OBD1 TRANS_OUTPUT_SPEED_RAW [A]
OSS_period                               equ $18B5	; analysis: output shaft pulse period
output_speed_unfiltered                  equ $18B7	; analysis: output speed before filter (OSS or backup estimate)
TRANS_OUTPUT_SPEED                       equ $18B9	; OBD1 TRANS_OUTPUT_SPEED [A] | A225 list2 word22 NO+1: Transmission Output Speed (Lsb) (RPM = N/8)
trans_output_speed_prev                  equ $18BB	; analysis: held output speed during dropout; previous output speed sample used for change detection
VEHICLE_SPEED_0                          equ $18BD	; OBD1 VEHICLE_SPEED_0 [A]
vss_v18BF                                equ $18BF	; inferred name; written by: calc_output_and_vehicle_speed_982B; read by: -
RAW_VEHICLE_SPEED                        equ $18C1	; OBD1 RAW_VEHICLE_SPEED [A] | part of structure
engine_output_ratio                      equ $18C3	; analysis: engine speed / trans output speed, 3.13 fixed (equates show RAW_VEHICLE_SPEED+2)
trans_v18C5                              equ $18C5	; analysis: measured ratio / nominal gear ratio, shifted left 1 (saturating) | inferred name; written by: calc_trans_speed_ratios_A328; read by: diag_P1875_9975
engine_speed_filtered                    equ $18C7	; OBD1 TRANS_ENG_SPEED [A]
engine_speed_rate                        equ $18C9	; analysis: signed engine speed change rate; tracking filter rate state
engine_speed_accel                       equ $18CB	; analysis: tracking filter 2nd-derivative state
engine_speed_rate_prev                   equ $18CD
trans_load_rate                          equ $18D5	; analysis: signed load change per call
tipin_tipout_timer                       equ $18D6	; analysis: hold timer for $6B.0/$6A.3
trans_v18DA                              equ $18DA	; analysis: coolant temp input to trans filter | inferred name; written by: read_sensors_linearize_EEDD; read by: calc_trans_ECT_filtered_B4D4, check_warmup_cycle_FC0E
ECT_filtered_trans                       equ $18DB	; analysis: filtered coolant temp (16-bit filter state, high byte used); filtered coolant temp used by trans/TCC logic
cold_ECT_weight                          equ $18DD	; analysis: $FF cold .. 0 warm; 0..FF weight from 18DB vs k_3905/3906, scales per-gear offsets
altitude_factor                          equ $18DE	; analysis: baro pressure for trans logic; baro voltage*k_3843+kw_3844 (B4BF); weight for altitude tables; baro-based shift pattern blend factor (B4D0); used by EC22
trans_load_filter_state                  equ $18E2	; analysis: 16-bit filter state; high byte = trans_load_filtered
trans_load_filtered                      equ $18E4
trans_load_prev                          equ $18E5	; analysis: previous trans load for rate
trans_temp                               equ $18E6
trans_temp_filtered                      equ $18E7	; OBD1 TTEMP [A] | Trans Temp
trans_temp_at_start                      equ $18E9	; analysis: trans temp captured once after run time kw_38D6 ($6B.4 = captured)
brake_debounce_ctr                       equ $18EA	; analysis: brake switch debounce counter (not trans temp)
ram_v18EB                                equ $18EB	; inferred name; written by: run_100ms_engine_tasks_EC95, calc_TASKFLAGS1_C701; read by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, diag_P0107_P0108_P0112_etc_B3BD, diag_P0126_...
motion_stop_debounce                     equ $18ED	; analysis: counts calls with all speeds below motion thresholds
CYLBAL_PACETMR                           equ $18EE	; OBD1 CYLBAL_PACETMR [A] | End of transmission stuff | Cyl balancer
CYLBAL_CYL_COUNTER                       equ $18EF	; OBD1 CYLBAL_CYL_COUNTER [A]
CYLBAL_LAST_CYLC7                        equ $18F0	; OBD1 CYLBAL_LAST_CYLC7 [A]
CYLBAL_ADJUST                            equ $18F1	; OBD1 CYLBAL_ADJUST [A]
CYLBAL_RPM_SUM_ARRAY                     equ $18F3	; OBD1 CYLBAL_RPM_SUM_ARRAY [A] | summation of RPM's for cylinder balancing
ADC_AN0_APP1                             equ $1903	; OBD1 APP_1 [A] | 1f 8 direct input channels on HC11 | Analogue inputs
ADC_AN1_APP2                             equ $1904	; OBD1 APP_2 [A]
ADC_AN2_trans_force_current              equ $1905	; OBD1 IACT_RAW [A]
ADC_AN3_APP3                             equ $1906	; OBD1 APP_3 [A]
ADC_AN4_battery_volts                    equ $1907	; OBD1 VOLT [A] | A225 list1 word2 ADVVIGRW: Raw Ignition Voltage A/D Counts (VOLTS = N/10)
ADC_AN5_boost_pressure                   equ $1908	; OBD1 MAP1_V_RAW [B] | A225 list1 word3 ADVCPRW: Raw Compressor Pressure Voltage (Non-Defaulted)(Turbo Only) (VOLTS = (N * 5/255); KPA = (N * 1.360))
ADC_AN6_AMUX_raw                         equ $1909
ADC_AN7_EGR_baro_pressure                equ $190A	; OBD1 MAP2_V_RAW [A]
ADC_timeout_count                        equ $190B	; OBD1 ADC_TIMEOUT_CTR [A]
APP1_FILT                                equ $190C	; OBD1 APP1_FILT [A] | A225 list1 word26 ADVPP1F: Pedal Position 1 Sensor (Filtered Value) (VOLTS = N * 5/255)
APP1_zeroed                              equ $190D	; analysis: APP1 zero-corrected, scaled 0..255
APP1_disagree_timer                      equ $190E	; analysis: pre-debounce up to k_341C for APP1 pair-difference faults (auto-named APP1_FILT+2)
APP2_FILT                                equ $190F	; OBD1 APP2_FILT [A] | A225 list1 word27 ADVPP1F: Pedal Position 2 Sensor (Filtered Value) (VOLTS = (256 - N)5/255)
APP2_zeroed                              equ $1910	; analysis: APP2 zero-corrected, scaled 0..255
APP2_disagree_timer                      equ $1911	; analysis: same for APP2
APP_5Vref_low_timer                      equ $1912	; analysis: pre-debounce up to k_341C for the 5V reference fault
APP3_FILT                                equ $1913	; OBD1 APP3_FILT [A] | A225 list1 word28 ADVPP1F: Pedal Position 3 Sensor (Filtered Value) (VOLTS = (256 - N)5/255)
APP3_zeroed                              equ $1914	; analysis: APP3 zero-corrected, scaled 0..255
APP3_disagree_timer                      equ $1915	; analysis: same for APP3
pedal_position_filtered                  equ $1916	; OBD1 APP_COND [A] | tp sensor .39215
app_v1918                                equ $1918	; analysis: min of (255-APP) tracked during tip-in shaping | inferred name; written by: pedal_select_filter; read by: pedal_select_filter
app_v1919                                equ $1919	; analysis: offset added to APP target for FILT_16A shaping | inferred name; written by: pedal_select_filter; read by: pedal_select_filter
app_v191A                                equ $191A	; analysis: filtered pedal high byte at last increase; used to scale offset on release | inferred name; written by: pedal_select_filter; read by: pedal_select_filter
LAST_APP_COND                            equ $191B	; OBD1 LAST_APP_COND [A]
APP_COND_2                               equ $191D	; OBD1 APP_COND_2 [A] | A225 list1 word29 ADVTHROT: Throttle Position Sensor (Final Scaled Value) (%TPS = N/2.56)
EGR_SIMPLE_MODE_TMR                      equ $191F	; OBD1 EGR_SIMPLE_MODE_TMR [A]
ram_v1920                                equ $1920	; inferred name; written by: INIT_SENSOR_FILTERS_5A15; read by: -
battery_voltage                          equ $1921	; OBD1 BATT_VOLT_FILT [A]
MAP_raw_AN5_copy                         equ $1922	; OBD1 BOOST_V_FILT [B]
Turbo_ram_address                        equ $1923
MAP_scaled_unchecked                     equ $1924	; OBD1 MEASURED_BOOST [C] | A225 list1 word30 ADVCPRSP: Compressor Pressure (Turbo Boost) (Defaulted) (Turbo Only) (VOLTS = N * 5/255; KPA = N * 1)
EGR_VAC_VOLTS_FILT                       equ $1925	; OBD1 EGR_VAC_VOLTS_FILT [A]
MEASURED_EGR_VAC                         equ $1926	; OBD1 MEASURED_EGR_VAC [A] | A225 list1 word31 ADVEGR: Egr Pressure (KPA = N * .5)
ram_v1927                                equ $1927	; inferred name; written by: INIT_SENSOR_FILTERS_5A15; read by: -
ram_v1928                                equ $1928	; inferred name; written by: -; read by: read_sensors_linearize_EEDD
coolant_temp                             equ $1929	; OBD1 ECTS_UNFILT [A]
ECT_filtered                             equ $192A	; analysis: 2-pt average before fault default
trans_temp_raw                           equ $192B
BARO_VOLTAGE                             equ $192D	; OBD1 BARO_VOLTAGE [A]
trans_v192E                              equ $192E	; inferred name; written by: INIT_SENSOR_FILTERS_5A15; read by: calc_trans_baro_B4BF, run_100ms_engine_tasks_EC95
NA_ram_address                           equ $192F	; OBD1 BARO_PRESS [A] | * .5 | A225 list2 word2 ADVBARO: Barometor Sensor (KPA = N * .5)
ram_v1930                                equ $1930	; inferred name; written by: INIT_SENSOR_FILTERS_5A15; read by: -
fuel_temp_raw                            equ $1932
fuel_temp                                equ $1933
fuel_v1934                               equ $1934	; inferred name; written by: read_sensors_linearize_EEDD; read by: PID_fuel_temp_F1CF
ram_v1935                                equ $1935	; inferred name; written by: INIT_SENSOR_FILTERS_5A15; read by: -
glow_plug_voltage                        equ $1936	; analysis: copy of MUX0 glow plug voltage (bank0 5A43); compared with battery for P0380
ram_v1937                                equ $1937	; inferred name; written by: INIT_SENSOR_FILTERS_5A15; read by: -
IAT_raw                                  equ $1938
IAT_temp                                 equ $1939
IAT_filtered                             equ $193A	; analysis: 2-pt average before fault default
ram_v193B                                equ $193B	; inferred name; written by: INIT_SENSOR_FILTERS_5A15; read by: -
AMUX_channel_select                      equ $193C	; OBD1 MUX_CHANNEL_COUNTER [A]
MEAS_INJ_TMG_SAFE                        equ $193D	; analysis: pump timing value used (measured / backup / kw_372F default) | OBD1 MEAS_INJ_TMG_SAFE [A] | 28.56 crank degrees
inj_response_filtered                    equ $193F	; analysis: 16-bit filtered measured injector response
MUX0_glow_plug_voltage                   equ $1941
MUX1_fuel_temp                           equ $1942
MUX2_diag_switch                         equ $1943
MUX3_ECT_voltage                         equ $1944
MUX4_spare_B9                            equ $1945
MUX5_pump_calibration                    equ $1946
MUX6_QDM1_fault                          equ $1947
MUX7_glow_relay_supply                   equ $1948
MUX8_QDM2_fault                          equ $1949
MUX9_AC_request                          equ $194A	; OBD1 AC_REQ_VOLTS [A]
MUX10_IAT                                equ $194B
MUX11_optical_5V_supply                  equ $194C
MUX12_B5_unused                          equ $194D
MUX13_trans_temp                         equ $194E
MUX14_APP2_5V_supply                     equ $194F
MUX15_flash_Vpp                          equ $1950
LAST_APP1                                equ $1951	; OBD1 LAST_APP1 [B]
LAST_APP2                                equ $1952	; OBD1 LAST_APP2 [B]
LAST_APP3                                equ $1953	; OBD1 LAST_APP3 [B] | ce  - is at 286 in older file
ref_period_filtered                      equ $1954	; analysis: filtered reference period (avg of new and old), 16us ticks; named LAST_APP3+1
TIME_OF_LAST_TOC1_TRANS                  equ $1956	; OBD1 TIME_OF_LAST_TOC1_TRANS [C]
LAST_TOC1                                equ $1958	; OBD1 LAST_TOC1 [C] | from toc1, ???
BACKUP_LAST_CMP_TCNT                     equ $195A	; OBD1 BACKUP_LAST_CMP_TCNT [C]
BACKUP_TCNT_EXTENSION                    equ $195C	; OBD1 BACKUP_TCNT_EXTENSION [B]
BACKUP_DELTA_CKP_DT                      equ $195E	; OBD1 BACKUP_DELTA_CKP_DT [B]
BACKUP_DELAY_TIMER                       equ $1960	; OBD1 BACKUP_DELAY_TIMER [C]
backup_delay_lo                          equ $1961	; analysis: low 16 bits of backup TOC1 delay; BACKUP_DELAY_TIMER is the overflow byte; low word of the 24-bit backup reference delay (high byte BACKUP_DELAY_TIMER = overflow count)
rpm_v1962                                equ $1962	; inferred name; written by: CKP_isr_backup_ref_min_delay_840F, CKP_isr_arm_backup_ref_TOC1_8420, diag_P0251_P0335_P0370_8BF9; read by: -
BACKUP_MAX_INT_LATENCY                   equ $1963	; OBD1 BACKUP_MAX_INT_LATENCY [A] | 0e25 = maximum time to calculate fuel quantity. about 1ms
backup_inj_delay_hi                      equ $1965	; analysis: TOC4 backup pulse: remaining timer overflows; overflow byte of backup injection delay ($1966 = low word)
backup_inj_delay_lo                      equ $1966	; analysis: TOC4 backup pulse: remaining time (TCNT ticks); low word of backup injection delay
ram_v1967                                equ $1967	; inferred name; written by: FIRE_BACKUP_INJ_OUTPUT, TOC4_BKUP_INJ_INT, TOC4_backup_inj_frag2_8F86; read by: -
Cyl_Count_7                              equ $1968	; OBD1 Cyl_Count_7 [A]
Cyl_Count_8                              equ $1969	; OBD1 Cyl_Count_8 [A]
CYLBAL_STOR_CYL                          equ $196A	; OBD1 CYLBAL_STOR_CYL [B]
ref_edge_time                            equ $196B	; analysis: time of current reference edge (TIC4 or LAST_TOC1)
fuel_v196D                               equ $196D	; analysis: previous $1462 value (named CYLBAL_STOR_CYL+3) | inferred name; written by: CKP_isr_crank_fuel_and_P0370_847E; read by: CKP_isr_crank_fuel_and_P0370_847E
egr_v196F                                equ $196F	; inferred name; written by: EGR_control; read by: calc_EGR_desired_vac_MAF_70DF
EGR_ERROR                                equ $1970	; OBD1 EGR_ERROR [A]
EGR_ERROR_SIGN                           equ $1971	; OBD1 EGR_ERROR_SIGN [A]
EGR_INTEG                                equ $1972	; OBD1 EGR_INTEG [A]
COUNTER_32HZ                             equ $1974	; OBD1 COUNTER_32HZ [A] | egr/baro robin counter
EGR_PRESS_FILTER_ROBIN                   equ $1975	; OBD1 EGR_PRESS_FILTER_ROBIN [A] | 5 bytes | egr/baro robin buffer
egr_v1976                                equ $1976	; inferred name; written by: -; read by: _run_egr_press_filter
egr_v1977                                equ $1977	; inferred name; written by: -; read by: _run_egr_press_filter
egr_v1978                                equ $1978	; inferred name; written by: -; read by: _run_egr_press_filter
egr_v1979                                equ $1979	; inferred name; written by: -; read by: _run_egr_press_filter
VSS_FAST_EGR_STOP_TIMER                  equ $197A	; OBD1 VSS_FAST_EGR_STOP_TIMER [A] | timer in egr
EGR_BARO_SAMPLE_TIMER                    equ $197B	; OBD1 EGR_BARO_SAMPLE_TIMER [A] | timer to sample EGR MAP sensor line
EGR_ECTS_ADJ                             equ $197C	; OBD1 EGR_ECTS_ADJ [B] | 3c (cold)
EGR_BARO_CORR                            equ $197D	; OBD1 EGR_BARO_CORR [A]
RPM_RAW                                  equ $1982	; OBD1 RPM_RAW [A] | raw RPM
RPM_1                                    equ $1984	; OBD1 RPM_1 [B] | filtered RPM #1
engine_RPM                               equ $1986	; OBD1 RPM_2 [A] | vRPM #2 | A225 list1 word38 ESVRPM: Engine Speed (Final) (RPM = N * 18.75)
LAST_RPM_2                               equ $1988	; OBD1 LAST_RPM_2 [A] | last RPM #2 | SCALING FACTOR FOR RPM == 4800 RPM maximum (18.75 RPM per bit 8 bits)
RPM_2_DBL                                equ $198A	; OBD1 RPM_2_DBL [A] | 5a RPM #2 * 2
TOVFL_CNT                                equ $198B	; OBD1 TOVFL_CNT [A] | TOVFL count | SCALING FACTOR == 2400 RPM maximum (9.375 RPM per bit 8 bits)
TOVFL_CAP_RPM                            equ $198C	; OBD1 TOVFL_CAP_RPM [B] | captured TOVFL for RPM calculation
TIC_CAP_RPM                              equ $198D	; OBD1 TIC_CAP_RPM [A] | capture TIC for RPM calculation
TIC_POLL_RPM                             equ $198F	; OBD1 TIC_POLL_RPM [A] | captured TIC polled
LTIC_POLL_RPM                            equ $1991	; OBD1 LTIC_POLL_RPM [A] | previous TIC for delta time calc
TOVFL_POLL_RPM                           equ $1993	; OBD1 TOVFL_POLL_RPM [A] | captured TOVFL polled
DELTA_T_RPM                              equ $1994	; OBD1 DELTA_T_RPM [B] | delta time for RPM calc. Not fetched
RPM_SCALE_CNT                            equ $1996	; OBD1 RPM_SCALE_CNT [A] | shift counter in RPM scaling
rpm_v1997                                equ $1997	; analysis: counts while in 1st gear above RPM k_323A, compared with k_3238 | inferred name; written by: DO_ENG_STOP_SOL; read by: DO_ENG_STOP_SOL
rpm_v1998                                equ $1998	; analysis: counts while not in 1st gear, compared with k_3239 | inferred name; written by: DO_ENG_STOP_SOL; read by: DO_ENG_STOP_SOL
rpm_v1999                                equ $1999	; analysis: bit0 = run latch used by DO_ENG_STOP_SOL | inferred name; written by: _run_25ms_job, DO_ENG_STOP_SOL; read by: _run_25ms_job, DO_ENG_STOP_SOL
stall_timer                              equ $199A	; analysis: 25 ms ticks since last reference (sat 255); >=13 = engine stopped
RPM_5                                    equ $199B	; OBD1 RPM_5 [C]
RPM_6                                    equ $199D	; OBD1 RPM_6 [A]
FILTERED_ROUGHNESS                       equ $19A1	; OBD1 FILTERED_ROUGHNESS [A] | ;0000
sched_overrun_count                      equ $19A3	; analysis: reloaded to 17; counts down on TOC3 ticks with a job overrun; at 0 the ISR hangs (COP reset)
fuel_quantity                            equ $19A4	; OBD1 CMD_POWER_TO_ENG [A] | 22  = *.3125 mm^3 diesel | A225 list1 word19 FUVRATE: Fuel Rate (mm FUEL RATE = N * .3125)
torque_reduction_mult                    equ $19A6	; analysis: fuel multiplier /256 (255 = none) applied when $87.0 is set; fuel multiplier /256 applied when $87.0 set
FUEL_CMD_TMP                             equ $19A7	; OBD1 FUEL_CMD_TMP [A]
FTS_FUEL_PW_ADJ                          equ $19A8	; OBD1 FTS_FUEL_PW_ADJ [A]
fuel_reduction_hotECT                    equ $19A9	; OBD1 ECTS_PWR_REDUCTION [B]
fuel_reduction_boost                     equ $19AA	; OBD1 BOOST_PWR_REDUCTION [B]
APP_FUEL_REQ                             equ $19AB	; OBD1 APP_FUEL_REQ [A] | A225 list2 word15 FUVTHREQ: Throttle Requested Fuel Rate (mm FUEL RATE = N * .375)
fuel_max_final                           equ $19AC	; OBD1 MAX_FUEL_LIMIT [A] | A225 list2 word14 FUVMXTFR: Maximum Transient Fuel Rate (mm FUEL RATE = N * .3125)
fuel_max_full_pedal                      equ $19AD	; OBD1 MAX_POWER_FROM_TQ_CURVE [B] | 93 (at idle)
fuel_max_minus_reduction                 equ $19AE	; OBD1 MAX_PWR_DERATED_FR_TQ_CURVE [B]
COMMAND_FUEL_PW                          equ $19AF	; OBD1 COMMAND_FUEL_PW [A] | 0125  << 25.75 crank degrees???
APP_FAULT_PWR_LIMIT                      equ $19B1	; OBD1 APP_FAULT_PWR_LIMIT [A] | 00				;
fuel_v19B2                               equ $19B2	; inferred name; written by: -; read by: calc_fuel_quantity_tail_92CC
fuel_reduction_max                       equ $19B3	; OBD1 TQ_DERATE_REDUCTION_REQ [A]
NOEGR_FUEL_INC_DELAY_TMR                 equ $19B4	; OBD1 NOEGR_FUEL_INC_DELAY_TMR [A] | 25 (was 0 when driving) - transient fuel limiter?
CMD_PWR_FROM_APP                         equ $19B5	; OBD1 CMD_PWR_FROM_APP [A]
fuel_v19B8                               equ $19B8	; analysis: last read of TIO $158A | inferred name; written by: CKP_isr_load_TIO_fuel_counters_8680; read by: CKP_isr_load_TIO_fuel_counters_8680
fuel_v19BA                               equ $19BA	; analysis: COMMAND_FUEL_PW at previous event | inferred name; written by: CKP_isr_load_TIO_fuel_counters_8680; read by: CKP_isr_load_TIO_fuel_counters_8680
injection_timing_desired                 equ $19BC	; OBD1 DESIRED_INJ_TIMING [A] | 3f30 = 6.3 crank degrees | A225 list1 word47 FUVTMD: Desired Injection Timing (DEG = N * .1)
ITS_Counts_1                             equ $19BE	; OBD1 ITS_Counts_1 [A]
MEAS_INJ_TIMING_FILT                     equ $19BF	; OBD1 MEAS_INJ_TIMING_FILT [A] | 28.47 crank degrees
REF_TO_SOI_DESIRED                       equ $19C1	; OBD1 REF_TO_SOI_DESIRED [A] | 008b =	12.21 crank degrees?
ITS_ERROR                                equ $19C3	; OBD1 ITS_ERROR [A]
ITS_POS_RESET_TIMER                      equ $19C4	; OBD1 ITS_POS_RESET_TIMER [A]
ITS_Phase_Count                          equ $19C5	; OBD1 ITS_Phase_Count [A]
ITS_Cold_Base                            equ $19C6	; OBD1 ITS_Cold_Base [A]
ITS_settle_ctr                           equ $19C7	; analysis: 12.5 ms ticks with ITS on crank target
baro_v19C8                               equ $19C8	; inferred name; written by: -; read by: dead_pump_map_interp_frag_967E
cold_start_timing_adder                  equ $19CC	; analysis: init k_2770 at start, decays
cold_timing_adder_total                  equ $19CD	; analysis: 19CC + 19D3
ram_v19CE                                equ $19CE	; inferred name; written by: run_100ms_engine_tasks_EC95; read by: run_100ms_engine_tasks_EC95
timing_min_baro                          equ $19CF	; analysis: lower limit applied to desired timing before max clamp; tbl3D_timing_min_RPM_x_BARO
fuel_temp_timing_adder                   equ $19D0	; analysis: Table_all_0[RPM, fuel temp]
its_v19D1                                equ $19D1	; inferred name; written by: calc_fuel_timing_modifiers; read by: calc_fuel_timing_modifiers
its_v19D2                                equ $19D2	; inferred name; written by: calc_fuel_timing_modifiers; read by: calc_fuel_timing_modifiers
its_v19D3                                equ $19D3	; analysis: ramps up to k_2779 at low fuel | inferred name; written by: calc_fuel_timing_modifiers; read by: calc_fuel_timing_modifiers
TCNT_EXTENSION                           equ $19D4	; OBD1 TCNT_EXTENSION [A]
LAST_CKP_TMR                             equ $19D5	; OBD1 LAST_CKP_TMR [C]
LAST_CKP_DELTAT                          equ $19D7	; OBD1 LAST_CKP_DELTAT [C]
FILT_TQCVT_SLIP                          equ $19D9	; OBD1 FILT_TQCVT_SLIP [A]
ECTS_DIR_FILTERED                        equ $19DB	; OBD1 ECTS_DIR_FILTERED [C]
idle_pid_unclamped_flag                  equ $19DC	; analysis: set when idle PID sum within 0..max; gates commit of ITERM->ITERM_LAST at b1:920E
egr_v19DD                                equ $19DD	; inferred name; written by: EGR_map_lookup; read by: EGR_map_lookup
COMMAND_FUEL_DELIV_360FS                 equ $19DE	; OBD1 COMMAND_FUEL_DELIV_360FS [A] | 25.77 crank degrees
brake_debounce_ctr_19E0                  equ $19E0	; analysis: counts to k_229F
fuel_PW_ramp_step                        equ $19E1	; analysis: COMMAND_FUEL_PW ramp-down step per event, (PW-kw_22A2)*16/k_22A0 (min 1); word subtracted from COMMAND_FUEL_DELIV_360FS; written in bank1 9389-9409
fuel_v19E2                               equ $19E2	; inferred name; written by: calc_fuel_quantity, calc_fuel_quantity_tail_92CC; read by: -
STARTUP_CTR                              equ $19E3	; OBD1 STARTUP_CTR [A] | ff counts revs ?
fuel_delay_counter_shadow                equ $19E4	; analysis: copied to timing_delay_counter $147C (named STARTUP_CTR+1)
Fuel_quantity_counter_read               equ $19E6
split_delay_counter_shadow               equ $19E8	; analysis: copied to split_pulse_delay_counter $1480
pilot_qty_counter_shadow                 equ $19EA	; analysis: copied to pilot_quantity_counter $1482
governor_RPM_start                       equ $19EC	; OBD1 CAL_GOV_FULL_PWR_RPM [A]
governor_RPM_cutoff                      equ $19EE	; OBD1 CAL_GOV_NO_PWR_RPM [A]
CRUISE_STATE                             equ $19F0	; OBD1 CRUISE_STATE [A] | A225 list1 word36 CRVMODE: Cruise Control Mode bits: b0 CRUISE OFF CONDITION; b1 DISENGAGE CONDITION; b2 CRUISE STANDBY MODE; b3 CRUISE ACCELERATED MODE; b4 CRUISE RESUME MO...
vehicle_speed                            equ $19F1	; OBD1 VEHICLE_SPEED_3 [A] | A225 list1 word21 CRVVEHSP: Vehicle Speed (MPH = N * .5)
VEHICLE_SPEED_3_LAST                     equ $19F3	; OBD1 VEHICLE_SPEED_3_LAST [A]
cruise_desired_speed                     equ $19F5	; analysis: 16-bit stored/desired cruise speed (hi byte mph*2, $0200 = 1 mph); CRUISE_SETPOINT ramps toward it; remembered/target cruise speed word (0.5 mph/high byte); setpoint ramps toward it
CRUISE_SETPOINT                          equ $19F7	; OBD1 CRUISE_SETPOINT [A] | A225 list1 word39 CRVTGTSP: Cruise Target Speed (MPH = N * .5)
cruise_setcoast_held_ctr                 equ $19F9	; analysis: passes set/coast switch held (19FA = passes released); ticks SET/COAST switch held (sat FF)
cruise_set_sw_released_ctr               equ $19FA	; analysis: ticks SET/COAST switch released
cruise_resacc_held_ctr                   equ $19FB	; analysis: passes resume/accel switch held (19FC = passes released); ticks RESUME/ACCEL held
cruise_resume_sw_released_ctr            equ $19FC	; analysis: ticks RESUME/ACCEL released
cruise_v19FD                             equ $19FD	; inferred name; written by: cruise_engage_at_current_speed_A076, cruise_fuel_PID_A224, reset_cruise; read by: cruise_fuel_PID_A224, cruise_PID_clamp_tail_A2C1
cruise_v19FF                             equ $19FF	; inferred name; written by: cruise_engage_at_current_speed_A076, cruise_fuel_PID_A224, reset_cruise; read by: cruise_fuel_PID_A224, cruise_PID_clamp_tail_A2C1
cruise_v1A00                             equ $1A00	; inferred name; written by: cruise_engage_at_current_speed_A076, cruise_fuel_PID_A224, cruise_PID_clamp_tail_A2C1, reset_cruise; read by: cruise_fuel_PID_A224
cruise_v1A02                             equ $1A02	; inferred name; written by: cruise_engage_at_current_speed_A076, cruise_fuel_PID_A224, cruise_PID_clamp_tail_A2C1, reset_cruise; read by: cruise_fuel_PID_A224
cruise_error_filtered                    equ $1A03	; analysis: filtered speed error (Scaling_and_clamping_fixed output); 1A05 committed copy
cruise_v1A05                             equ $1A05	; inferred name; written by: cruise_fuel_PID_A224, cruise_PID_clamp_tail_A2C1; read by: -
CRUISE_ERROR                             equ $1A07	; OBD1 CRUISE_ERROR [A] | A225 list1 word40 CRVERROR: Cruise Error Mph (MPH = N * .5)
cruise_iterm                             equ $1A09	; analysis: 3 bytes: cruise integral term; 1A0C-0E committed integrator (preloaded with fuel_quantity on engage)
cruise_v1A0A                             equ $1A0A	; inferred name; written by: -; read by: cruise_fuel_PID_A224
cruise_v1A0B                             equ $1A0B	; inferred name; written by: cruise_engage_at_current_speed_A076, cruise_calc_iterm_A30D, reset_cruise; read by: cruise_fuel_PID_A224, cruise_PID_clamp_tail_A2C1
cruise_fuel_at_engage                    equ $1A0C	; analysis: fuel_quantity captured at set/resume
cruise_v1A0D                             equ $1A0D	; inferred name; written by: -; read by: cruise_calc_iterm_A30D
cruise_v1A0E                             equ $1A0E	; inferred name; written by: cruise_engage_at_current_speed_A076, cruise_fuel_PID_A224, cruise_PID_clamp_tail_A2C1, reset_cruise; read by: cruise_calc_iterm_A30D
cruise_gain_term                         equ $1A0F	; analysis: 24-bit signed gain*error result (1A0F-1A11)
cruise_v1A10                             equ $1A10	; inferred name; written by: calc_cruise_gain_term_A46F; read by: -
cruise_v1A11                             equ $1A11	; inferred name; written by: reset_cruise; read by: cruise_fuel_PID_A224
CRUISE_DTERM                             equ $1A12	; OBD1 CRUISE_DTERM [A]
cruise_v1A13                             equ $1A13	; inferred name; written by: calc_CRUISE_DTERM_A20B; read by: cruise_fuel_PID_A224
cruise_v1A14                             equ $1A14	; inferred name; written by: reset_cruise; read by: cruise_fuel_PID_A224
CRUISE_FUEL_REQ                          equ $1A15	; OBD1 CRUISE_FUEL_REQ [A] | A225 list2 word13 CRVFUEL: Cruse Fuel Rate (mm FUEL RATE = N * .3125)
cruise_error_direction                   equ $1A16	; OBD1 cruise_error_direction [A]
cruise_v1A17                             equ $1A17	; inferred name; written by: cruise_fuel_PID_A224, cruise_calc_iterm_A30D; read by: cruise_fuel_PID_A224, cruise_calc_iterm_A30D
cruise_v1A18                             equ $1A18	; inferred name; written by: cruise_fuel_PID_A224; read by: cruise_fuel_PID_A224, cruise_PID_clamp_tail_A2C1
CRUISE_RPM_CAP                           equ $1A19	; OBD1 CRUISE_RPM_CAP [A]
CRUISE_FUEL_REQ_NO_DERATE                equ $1A1A	; OBD1 CRUISE_FUEL_REQ_NO_DERATE [A]
MAX_CRUISE_FUEL_LIM                      equ $1A1B	; OBD1 MAX_CRUISE_FUEL_LIM [A]
cruise_onoff_debounce_ctr                equ $1A1C	; analysis: counts to k_2093 while cruise on/off switch on -> CRUISE_FLAGS_1.1
cruise_v1A1D                             equ $1A1D	; analysis: cleared on resume, counts to k_2094 -> CRUISE_FLAGS_1.2 | inferred name; written by: run_cruise_setpoint, cruise_standby_switch_handler_A52A; read by: run_cruise_setpoint
BULBTEST_TMR                             equ $1A1E	; OBD1 BULBTEST_TMR [B]
rpm_v1A1F                                equ $1A1F	; inferred name; written by: INIT_SENSOR_FILTERS_5A15, calc_sensor_pullup_range_F827; read by: calc_CKP_edges_per_cam_cycle_8141, calc_sensor_pullup_range_F827
rpm_v1A20                                equ $1A20	; inferred name; written by: INIT_SENSOR_FILTERS_5A15, calc_sensor_pullup_range_F827; read by: calc_sensor_pullup_range_F827
ENGINE_RUN_TIME                          equ $1A21	; OBD1 ENGINE_RUN_TIME [A] | A225 list1 word57 DGVRUNTM+1: Engine Run Time (Lsb) (SECS = N * .1)
rpm_v1A23                                equ $1A23	; inferred name; written by: diag_P0126_P0219_BDA5, diag_P0126_P0219_BDEA; read by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, diag_P0107_P0108_P0112_etc_B3BD, diag_P0126_P0219...
rpm_v1A25                                equ $1A25	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, diag_P0107_P0108_P0112_etc_B3BD; read by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF...
rpm_v1A27                                equ $1A27	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, diag_P0107_P0108_P0112_etc_B3BD; read by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF...
rpm_v1A28                                equ $1A28	; inferred name; written by: diag_P0126_P0219_BDA5; read by: diag_P0126_P0219_BDA5, diag_P0126_P0219_BDEA
rpm_v1A2A                                equ $1A2A	; analysis: tbl2D_ECT_9pt_36A1[startup ECT] | inferred name; written by: run_100ms_engine_tasks_EC95; read by: diag_P0126_P0219_BDA5
startup_ECT                              equ $1A2B	; analysis: ECT captured at power-up (also 02E1 NV copy)
egr_v1A2C                                equ $1A2C	; inferred name; written by: diag_EGR_MAF_and_misc_DTCs_7672; read by: diag_EGR_MAF_and_misc_DTCs_7672, diag_P0126_P0219_BDA5, diag_P0126_P0219_BDEA
egr_v1A2D                                equ $1A2D	; inferred name; written by: diag_EGR_MAF_and_misc_DTCs_7672; read by: diag_EGR_MAF_and_misc_DTCs_7672, diag_P0126_P0219_BDA5, diag_P0126_P0219_BDEA
rpm_v1A2F                                equ $1A2F	; inferred name; written by: diag_P0126_P0219_BDA5; read by: diag_P0126_P0219_BDA5, diag_P0126_P0219_BDEA
rpm_v1A30                                equ $1A30	; inferred name; written by: diag_P0126_P0219_BDA5, diag_P0126_P0219_BDEA; read by: diag_P0126_P0219_BDA5, diag_P0126_P0219_BDEA
engine_RPM_sample                        equ $1A32	; analysis: byte RPM sampled at bank0 ED45; $1A33 = previous sample
engine_RPM_sample_prev                   equ $1A33	; analysis: previous $1A32
hires_stall_ctr                          equ $1A34	; analysis: CKP events with no high-res encoder change; P0370 at k_36B6
missed_I4_ref_count                      equ $1A35	; analysis: !=0 -> use LAST_TOC1 instead of TIC4 as reference; consecutive I4 edges replaced by the backup TOC1; >= k_36B7 -> P0251
rpm_v1A36                                equ $1A36	; analysis: ++ in cam ISR, -- in CKP ISR; plausibility tested when <=0 | inferred name; written by: CKP_4X_input_capture_isr_81ED, diag_P0251_P0335_890E; read by: -
rpm_v1A37                                equ $1A37	; analysis: reloaded with k_36BA | inferred name; written by: CKP_4X_input_capture_isr_81ED; read by: CKP_4X_input_capture_isr_81ED
CKP_ref_period_copy                      equ $1A38	; analysis: TIO $14A4 count latched in the I4 ISR; ~$0400 nominal, plausibility window for miss counting; copy of $14A4 for plausibility tests
rpm_v1A3C                                equ $1A3C	; inferred name; written by: calc_CKP_edges_per_cam_cycle_8141, run_100ms_engine_tasks_EC95, ignition_off_powerdown_F615, diag_P0251_P0335_890E +2; read by: run_100ms_engine_tasks_EC95, diag_P0251_P0...
rpm_v1A3D                                equ $1A3D	; inferred name; written by: run_100ms_engine_tasks_EC95; read by: run_100ms_engine_tasks_EC95
rpm_v1A3E                                equ $1A3E	; inferred name; written by: run_100ms_engine_tasks_EC95; read by: run_100ms_engine_tasks_EC95
CKP_edges_per_cam_cycle                  equ $1A3F	; analysis: counted in CKP ISR, compared to CAL_NUM_CYLS at cyl 0 in cam ISR
cam_pulses_since_sync                    equ $1A40	; analysis: counted in cam ISR, compared to CAL_NUM_CYLS at sync
P0251_mismatch_ctr                       equ $1A41	; analysis: up/down counter, sets P0251 at k_36B8/k_36B9
P0335_mismatch_ctr                       equ $1A42	; analysis: up/down counter, sets P0335 at k_36B8
ram_v1A43                                equ $1A43	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, diag_P0107_P0108_P0112_etc_B3BD; read by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF...
baro_v1A44                               equ $1A44	; analysis: 1A44-1A4B: baro-dependent MAF/EGR diagnostic thresholds | inferred name; written by: calc_MAF_diag_thresholds_baro_C722; read by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_e...
baro_v1A45                               equ $1A45	; inferred name; written by: calc_MAF_diag_thresholds_baro_C722; read by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A
baro_v1A46                               equ $1A46	; inferred name; written by: calc_MAF_diag_thresholds_baro_C722; read by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A
baro_v1A47                               equ $1A47	; inferred name; written by: calc_MAF_diag_thresholds_baro_C722; read by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A
baro_v1A48                               equ $1A48	; inferred name; written by: calc_MAF_diag_thresholds_baro_C722; read by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A
baro_v1A49                               equ $1A49	; inferred name; written by: calc_MAF_diag_thresholds_baro_C722; read by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A
baro_v1A4A                               equ $1A4A	; inferred name; written by: calc_MAF_diag_thresholds_baro_C722; read by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A
baro_v1A4B                               equ $1A4B	; inferred name; written by: calc_MAF_diag_thresholds_baro_C722; read by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A
ram_v1A4C                                equ $1A4C	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A; read by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A
ram_v1A4D                                equ $1A4D	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A; read by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A
rpm_steady_counter                       equ $1A4E	; analysis: counts passes with |dRPM|<=k_36DE; >=k_36DF sets C7.3
brake_diag_timer                         equ $1A4F	; analysis: word, time in decel-without-brake state (P0571), limit CAL_diag_BRAKETIME
brake_diag_decel_time                    equ $1A51	; analysis: decel duration counter; $FF = event already counted (P0571)
brake_diag_event_count                   equ $1A52	; analysis: decel events without brake (P0571), vs CAL_diag_FAULTCOUNTS
diag_DELTAVSS                            equ $1A53	; OBD1 diag_DELTAVSS [B]
P0606_persist_ctr                        equ $1A55	; analysis: consecutive implausible-timing passes, limit k_36FE
ram_v1A56                                equ $1A56	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, diag_P0107_P0108_P0112_etc_B3BD, diag_P0107_P0108_P0112_etc_B619 +3; read by: diag_P0102_P0103_P0107_etc...
ram_v1A57                                equ $1A57	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, diag_P0107_P0108_P0112_etc_B3BD, diag_P0107_P0108_P0112_etc_B619 +3; read by: diag_P0102_P0103_P0107_etc...
ram_v1A58                                equ $1A58	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, diag_P0107_P0108_P0112_etc_B3BD, diag_P0107_P0108_P0112_etc_B619 +3; read by: diag_P0102_P0103_P0107_etc...
ram_v1A59                                equ $1A59	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, diag_P0107_P0108_P0112_etc_B3BD, diag_P0107_P0108_P0112_etc_B619 +3; read by: diag_P0102_P0103_P0107_etc...
ram_v1A5A                                equ $1A5A	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, diag_P0107_P0108_P0112_etc_B3BD, diag_P0107_P0108_P0112_etc_B619 +3; read by: diag_P0102_P0103_P0107_etc...
BALANCE_FAIL_CT_ARRAY                    equ $1A5B	; OBD1 BALANCE_FAIL_CT_ARRAY [A]
app_v1A63                                equ $1A63	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, diag_P0107_P0108_P0112_etc_B3BD, diag_P0107_P0108_P0112_etc_B619 +3; read by: diag_P0102_P0103_P0107_etc...
cylbal_diag_delay                        equ $1A66	; analysis: countdown loaded from k_37CF; per-cylinder P030x check runs when it hits 0
app_v1A68                                equ $1A68	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A; read by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A
app_v1A69                                equ $1A69	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A; read by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A
app_v1A6A                                equ $1A6A	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, diag_P0107_P0108_P0112_etc_B3BD, diag_P0107_P0108_P0112_etc_B619 +2; read by: diag_P0102_P0103_P0107_etc...
app_v1A6B                                equ $1A6B	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, diag_P0107_P0108_P0112_etc_B3BD, diag_P0107_P0108_P0112_etc_B619 +3; read by: diag_P0102_P0103_P0107_etc...
app_v1A6C                                equ $1A6C	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A; read by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A
app_v1A6D                                equ $1A6D	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A; read by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A
P0121_debounce_ctr                       equ $1A6E	; analysis: APP1 disagreement code debounce
APP1_low_debounce_ctr                    equ $1A6F	; analysis: P0122 debounce
APP1_high_debounce_ctr                   equ $1A70	; analysis: P0123 debounce, limit k_368C
P0126_debounce_ctr                       equ $1A71	; analysis: counts up to k_368C before P0126 is set; cleared when coolant reaches k_368F
app_v1A72                                equ $1A72	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, diag_P0107_P0108_P0112_etc_B3BD, diag_P0107_P0108_P0112_etc_B619 +1; read by: diag_P0102_P0103_P0107_etc...
app_v1A73                                equ $1A73	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, diag_P0107_P0108_P0112_etc_B3BD, diag_P0107_P0108_P0112_etc_B619 +1; read by: diag_P0102_P0103_P0107_etc...
app_v1A74                                equ $1A74	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A; read by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A
app_v1A75                                equ $1A75	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, diag_P0107_P0108_P0112_etc_B3BD; read by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF...
P0219_debounce_ctr                       equ $1A76	; analysis: up/down counter vs k_368C
APP_5Vref_debounce_ctr                   equ $1A77	; analysis: P0220/P0225 debounce
P0221_debounce_ctr                       equ $1A78	; analysis: APP2 disagreement code debounce
APP2_low_debounce_ctr                    equ $1A79	; analysis: P0222 debounce
APP2_high_debounce_ctr                   equ $1A7A	; analysis: P0223 debounce
P0226_debounce_ctr                       equ $1A7C	; analysis: APP3 disagreement code debounce
APP3_low_debounce_ctr                    equ $1A7D	; analysis: P0227 debounce
APP3_high_debounce_ctr                   equ $1A7E	; analysis: P0228 debounce
app_v1A7F                                equ $1A7F	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, diag_P0107_P0108_P0112_etc_B3BD, diag_P0107_P0108_P0112_etc_B619 +3; read by: diag_P0102_P0103_P0107_etc...
ram_v1A80                                equ $1A80	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, diag_P0107_P0108_P0112_etc_B3BD, diag_P0107_P0108_P0112_etc_B619 +3; read by: diag_P0102_P0103_P0107_etc...
ram_v1A81                                equ $1A81	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, diag_P0107_P0108_P0112_etc_B3BD, diag_P0107_P0108_P0112_etc_B619 +3; read by: diag_P0102_P0103_P0107_etc...
ram_v1A82                                equ $1A82	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, diag_P0107_P0108_P0112_etc_B3BD, diag_P0107_P0108_P0112_etc_B619 +3; read by: diag_P0102_P0103_P0107_etc...
ram_v1A83                                equ $1A83	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, diag_P0107_P0108_P0112_etc_B3BD; read by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF...
EGR_sensor_fail_ctr_P0405                equ $1A88	; analysis: fail counter for DTC P0405
EGR_sensor_fail_ctr_P0406                equ $1A89	; analysis: fail counter for DTC P0406
ram_v1A8A                                equ $1A8A	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, diag_P0107_P0108_P0112_etc_B3BD; read by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF...
ram_v1A8B                                equ $1A8B	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, diag_P0107_P0108_P0112_etc_B3BD, diag_P0107_P0108_P0112_etc_B619 +3; read by: diag_P0102_P0103_P0107_etc...
ram_v1A8C                                equ $1A8C	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, diag_P0107_P0108_P0112_etc_B3BD, diag_P0107_P0108_P0112_etc_B619 +3; read by: diag_P0102_P0103_P0107_etc...
ROM_sum_fail_ctr                         equ $1A8F	; analysis: background checksum failures, limit k_P0601_fail_count
P0606_fail_ctr                           equ $1A90	; analysis: up/down counter vs k_368D
P1216_fail_ctr                           equ $1A92	; analysis: response too short counter vs k_368D
P1217_fail_ctr                           equ $1A93	; analysis: response too long counter vs k_368D
ram_v1A99                                equ $1A99	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, diag_P0107_P0108_P0112_etc_B3BD, diag_P0107_P0108_P0112_etc_B619 +3; read by: diag_P0102_P0103_P0107_etc...
ram_v1A9A                                equ $1A9A	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, diag_P0107_P0108_P0112_etc_B3BD, diag_P0107_P0108_P0112_etc_B619 +3; read by: diag_P0102_P0103_P0107_etc...
ram_v1A9B                                equ $1A9B	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, diag_P0107_P0108_P0112_etc_B3BD, diag_P0107_P0108_P0112_etc_B619 +2; read by: diag_P0102_P0103_P0107_etc...
ram_v1A9C                                equ $1A9C	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, diag_P0107_P0108_P0112_etc_B3BD, diag_P0107_P0108_P0112_etc_B619 +2; read by: diag_P0102_P0103_P0107_etc...
ram_v1A9D                                equ $1A9D	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, diag_P0107_P0108_P0112_etc_B3BD, diag_P0107_P0108_P0112_etc_B619 +2; read by: diag_P0102_P0103_P0107_etc...
ram_v1A9E                                equ $1A9E	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, diag_P0107_P0108_P0112_etc_B3BD, diag_P0107_P0108_P0112_etc_B619 +3; read by: diag_P0102_P0103_P0107_etc...
ram_v1A9F                                equ $1A9F	; inferred name; written by: diag_P0107_P0108_P0112_etc_B720; read by: diag_P0107_P0108_P0112_etc_B720
ram_v1AA0                                equ $1AA0	; inferred name; written by: diag_P0102_P0103_P0107_etc_AE76, diag_P0102_P0103_P0107_etc_AF2A, diag_P0107_P0108_P0112_etc_B3BD, diag_P0107_P0108_P0112_etc_B619 +2; read by: diag_P0102_P0103_P0107_etc...
TRANSMISSION_RATIO                       equ $1AA1	; OBD1 TRANSMISSION_RATIO [B]
gear_calc_MT                             equ $1AA3	; OBD1 TRANSMISSION_GEAR_FROM_SPD_RATIO [A]
idle_v1AA4                               equ $1AA4	; analysis: tip-out dashpot hold timer (init k_33F7) | inferred name; written by: idle_RPM_target_task_F716, calc_idle_RPM_target, set_idle_RPM_target_F8EB; read by: idle_RPM_target_task_F716, calc_i...
idle_v1AA5                               equ $1AA5	; analysis: dashpot idle target, ramps toward 1AA8 | inferred name; written by: idle_RPM_target_task_F716, calc_idle_RPM_target; read by: idle_RPM_target_task_F716, calc_idle_RPM_target
ANTISTALL_DASHPOT_DRPM                   equ $1AA6	; OBD1 ANTISTALL_DASHPOT_DRPM [B]
ANTISTALL_DASHPOT_TMR                    equ $1AA7	; OBD1 ANTISTALL_DASHPOT_TMR [A]
idle_v1AA8                               equ $1AA8	; inferred name; written by: idle_RPM_target_task_F716, calc_idle_RPM_target; read by: idle_RPM_target_task_F716, calc_idle_RPM_target
ANTISTALL_DASHPOT                        equ $1AA9	; OBD1 ANTISTALL_DASHPOT [A]
timing_adder_ECT                         equ $1AAA	; analysis: 27DB[ECT,RPM] + 2875 adder if warm start
timing_adder_boost                       equ $1AAB
timing_adder_IAT                         equ $1AAC	; analysis: tbl2D_timing_adder_IAT_305D
ITS_STEPPER_TIMER                        equ $1AAD	; analysis: 6.25 ms tick counter, incremented in b1 160 Hz task; low 4 bits divide jobs | OBD1 ITS_STEPPER_TIMER [A]
sched_100ms_count                        equ $1AAE	; analysis: 0..9 counter, BULBTEST at 5 and 10; 0..9, incremented in the 100 ms job; 1 s job runs at 0
tdc_v1AAF                                equ $1AAF	; analysis: word timer of pedal >= k_2037; invalidates learn at kw_2035 | inferred name; written by: calc_TDC_learn_test_result_A98C; read by: calc_TDC_learn_test_result_A98C
boost_target                             equ $1AB1	; analysis: desired boost (same units as Turbo_ram_address), written bank0 FED3; used by P0236; desired boost after IAT adder
BOOST_ERROR                              equ $1AB2	; OBD1 BOOST_ERROR [A]
BOOST_ERROR_SIGN                         equ $1AB3	; OBD1 BOOST_ERROR_SIGN [B]
BOOST_INTEG                              equ $1AB4	; OBD1 BOOST_INTEG [A]
BOOST_INTEG_LIMIT                        equ $1AB6	; OBD1 BOOST_INTEG_LIMIT [A]
baro_scaled_axis                         equ $1AB8	; OBD1 BARO_SENSOR_SCALED_1 [A] | also OVERRIDE_EGR_DUTY
shift_v1AB9                              equ $1AB9	; analysis: non-zero = forced gear (1-based), clamped to max gear | inferred name; written by: update_current_gear_E88E; read by: update_current_gear_E88E
trans_gear_AT                            equ $1AC0	; OBD1 GEAR [A] | A225 list1 word20 GEAR: Current Gear Of Transmission (GEAR = N + 1)
trans_gear_desired                       equ $1AC1	; analysis: commanded gear (0-based), copied to trans_gear_AT; commanded/desired gear (0=1st..3=4th), written by shift logic
shift_v1AC2                              equ $1AC2	; inferred name; written by: limit_desired_gear_E676; read by: limit_desired_gear_E676
shift_v1AC3                              equ $1AC3	; inferred name; written by: limit_desired_gear_E676; read by: limit_desired_gear_E676
shift_v1AC5                              equ $1AC5	; inferred name; written by: limit_desired_gear_E676; read by: limit_desired_gear_E676
shift_v1AC8                              equ $1AC8	; analysis: VSS threshold of the last shift decision | inferred name; written by: calc_shift_request_E4B2, update_current_gear_E88E; read by: calc_shift_adapt_inhibit_2_CA67
shift_v1AC9                              equ $1AC9	; inferred name; written by: -; read by: limit_desired_gear_E676
time_since_downshift                     equ $1ACC	; analysis: 50 ms ticks, saturating
shift_v1ACE                              equ $1ACE	; analysis: 50 ms ticks, saturating; axis for tcurve_3B67 | inferred name; written by: calc_upshift_RPM_projection_adapt_E8C2; read by: calc_upshift_RPM_projection_adapt_E8C2
kickdown_timer                           equ $1AD0	; analysis: cleared at upshift start; must reach tbl_3B1F before adapt; counts while kickdown pattern active; compared to tbl_3B30[gear]
projected_shift_RPM                      equ $1AD1	; analysis: engine speed projected to end of shift delay; vs 1ADA in scheduler
shift_peak_RPM                           equ $1AD3	; analysis: peak engine speed during upshift
shift_v1AD5                              equ $1AD5	; analysis: engine speed rate (18C9) at shift start | inferred name; written by: calc_upshift_RPM_projection_adapt_E8C2; read by: calc_upshift_RPM_projection_adapt_E8C2
shift_target_saved                       equ $1AD7	; analysis: copy of 1ADA at shift start
shift_delay_error                        equ $1AD9	; analysis: signed adapt error, +-127
upshift_RPM_target                       equ $1ADA	; analysis: RPM-based upshift target from EB8E
time_out_of_1st                          equ $1ADC	; analysis: saturating counter, cleared in 1st gear
time_in_3rd_4th                          equ $1ADD	; analysis: saturating counter, cleared in 1st/2nd
shift_v1ADE                              equ $1ADE	; analysis: counter used by manual-range overspeed protection | inferred name; written by: limit_desired_gear_E676; read by: limit_desired_gear_E676
gear_hold_timer                          equ $1ADF	; analysis: counts since commanded gear last changed, saturating; counts since the shift request; reset after a PRNDL change
tcc_v1AE0                                equ $1AE0	; inferred name; written by: -; read by: calc_TCC_slip_integ_step_E351
tcc_v1AE1                                equ $1AE1	; inferred name; written by: calc_TCC_PWM_duty_cmd_DA80; read by: calc_TCC_PWM_duty_cmd_DA80, limit_desired_gear_E676
TCC_post_shift_timer                     equ $1AE2	; analysis: TCC inhibit countdown after a shift, from tbl_43D6/43D8
tcc_v1AE3                                equ $1AE3	; analysis: 16-bit base of the pressure command ($1AF5 = base + ramp) | inferred name; written by: calc_TCC_cond_flags_D5CF; read by: trans_line_pressure_calc, tcc_task_D96A
tcc_v1AE5                                equ $1AE5	; analysis: 16-bit signed ramp/closed-loop part of the command | inferred name; written by: calc_TCC_cond_flags_D5CF, trans_line_pressure_calc, tcc_task_D96A; read by: trans_line_pressure_calc
tcc_v1AE7                                equ $1AE7	; inferred name; written by: calc_TCC_PWM_duty_cmd_DA36; read by: -
tcc_v1AE9                                equ $1AE9	; inferred name; written by: calc_TCC_PWM_duty_cmd_DAE1; read by: calc_TCC_PWM_duty_cmd_DAE1
tcc_v1AEB                                equ $1AEB	; inferred name; written by: calc_TCC_PWM_duty_cmd_DAE1; read by: -
tcc_v1AED                                equ $1AED	; inferred name; written by: calc_TCC_PWM_duty_cmd_DAE1; read by: calc_TCC_PWM_duty_cmd_DAE1
tcc_v1AEE                                equ $1AEE	; inferred name; written by: calc_TCC_PWM_duty_cmd_DAE1; read by: calc_TCC_PWM_duty_cmd_D67F, calc_TCC_cond_flags_D70C
tcc_v1AF0                                equ $1AF0	; analysis: 16-bit phase timer for mode handlers, saturating | inferred name; written by: tcc_task_D597, tcc_task_DAB0; read by: tcc_task_D597, calc_TCC_cond_flags_D5CF, calc_TCC_PWM_duty_cmd_D67F, c...
tcc_v1AF2                                equ $1AF2	; inferred name; written by: -; read by: calc_TCC_cond_flags_D5CF
tcc_v1AF3                                equ $1AF3	; inferred name; written by: -; read by: calc_TCC_PWM_duty_cmd_DAE1
tcc_v1AF4                                equ $1AF4	; inferred name; written by: -; read by: calc_TCC_PWM_duty_cmd_DAE1
TCC_PWM_duty_cmd                         equ $1AF5	; analysis: 16-bit TCC duty (hi byte used), output of slip PI; 16-bit command (hi byte, same units as line_pressure_max) clamped [$1AF8, line_pressure_max]
PCS_duty_cmd                             equ $1AF7	; drives IOR 1809 = TCC PWM solenoid duty (4L80E), so "PCS" in this name is probably wrong; the PCS force motor is commanded through TIO $1400
press_cmd_min                            equ $1AF8	; analysis: = k_4583, lower clamp of TCC duty; minimum command = k_4583
line_pressure_max                        equ $1AF9
pcs_v1AFA                                equ $1AFA	; inferred name; written by: PCS_duty_from_pressure; read by: PCS_duty_from_pressure
pcs_v1AFB                                equ $1AFB	; inferred name; written by: PCS_duty_from_pressure; read by: -
TCC_timed_release_ctr                    equ $1AFC	; analysis: countdown from tbl_43D8[gear]
TCC_slip_abs                             equ $1AFD	; analysis: absolute value of filtered TCC slip (from B81C); |$1B01|
TCC_slip_speed                           equ $1B01	; analysis: signed TCC slip (engine - turbine) used by P0741/P0742/P0711; signed filtered slip = engine speed - turbine speed (B7F8); signed slip used by P1870 windows (equates show line_pressure_max...
tcc_v1B03                                equ $1B03	; inferred name; written by: calc_TCC_cond_flags_D5CF; read by: -
tcc_v1B05                                equ $1B05	; inferred name; written by: -; read by: trans_line_pressure_calc, calc_TCC_slip_target_DE32, calc_TCC_PWM_slip_control_DFEA
tcc_v1B06                                equ $1B06	; inferred name; written by: -; read by: calc_TCC_PWM_duty_cmd_DB8E, tcc_task_E396
tcc_v1B07                                equ $1B07	; analysis: window after an apply request; extends the next delay | inferred name; written by: calc_TCC_apply_release_bits_DC9A; read by: calc_TCC_apply_release_bits_DC9A
TCC_apply_delay_tmr                      equ $1B08	; analysis: TCC apply delay countdown (k_4580/k_4582)
tcc_v1B09                                equ $1B09	; analysis: counter for clearing the negative-slip flag | inferred name; written by: tcc_task_DF62, calc_TCC_release_request_E20A; read by: tcc_task_DF62
TCC_slip_integrator                      equ $1B0C	; analysis: signed integrator of slip PI
tcc_v1B0E                                equ $1B0E	; analysis: counts toward latching slip mode | inferred name; written by: calc_TCC_slip_target_DE32; read by: calc_TCC_slip_target_DE32
tcc_v1B0F                                equ $1B0F	; analysis: counts slip-too-low before abort | inferred name; written by: calc_TCC_slip_target_DE32; read by: calc_TCC_slip_target_DE32
tcc_v1B10                                equ $1B10	; analysis: time since slip mode cleared | inferred name; written by: calc_TCC_slip_target_DE32; read by: calc_TCC_slip_target_DE32
TCC_slip_target                          equ $1B11	; analysis: base from tblOfs3D_TRANS_line_pressure_base_45BA * 8; slip target = 3D table *8
TCC_slip_integ_step                      equ $1B14	; analysis: integrator step from t17_46DE
pcs_v1B18                                equ $1B18	; inferred name; written by: trans_line_pressure_calc; read by: trans_line_pressure_calc
pcs_v1B19                                equ $1B19	; inferred name; written by: trans_line_pressure_calc; read by: tcc_task_D96A
TCC_PWM_base_duty                        equ $1B1B	; analysis: feedforward duty from tbl_4712 vs turbine speed
pcs_v1B1F                                equ $1B1F	; inferred name; written by: trans_line_pressure_calc; read by: trans_line_pressure_calc
TCC_slip_error_q4                        equ $1B21	; analysis: (|slip| - target)/4, signed
tcc_v1B23                                equ $1B23	; inferred name; written by: tcc_task_D96A; read by: tcc_task_D96A
tcc_v1B24                                equ $1B24	; inferred name; written by: tcc_task_D96A; read by: tcc_task_D96A
line_press_adapt_floor                   equ $1B25	; analysis: adaptive minimum pressure, used as floor for line_pressure_desired; steady-state line pressure request (written at D0A9)
line_press_adapt_raw                     equ $1B26	; analysis: per-cell pressure incl. temp corr + learned cell, 0..255
eeprom_v1B28                             equ $1B28	; analysis: target engagement value for garage adapt | inferred name; written by: -; read by: calc_garage_adapt_loop_idx_C445
eeprom_v1B29                             equ $1B29	; inferred name; written by: calc_garage_adapt_loop_idx_C445; read by: -
eeprom_v1B2A                             equ $1B2A	; analysis: measured engagement value (probably time) used by garage adapt | inferred name; written by: -; read by: calc_garage_adapt_loop_idx_C445, calc_garage_adapt_inhibit_flags_C68F
ram_v1B2D                                equ $1B2D	; inferred name; written by: -; read by: sub_C678
trans_v1B2E                              equ $1B2E	; inferred name; written by: -; read by: lookup_TRANS_load_C5B2
trans_v1B31                              equ $1B31	; analysis: engagement pressure request | inferred name; written by: lookup_TRANS_load_C5B2, sub_C678; read by: calc_line_pressure_desired_C6D5
trans_v1B32                              equ $1B32	; analysis: from tbl_3C75 / tbl_3D77 | inferred name; written by: lookup_TRANS_load_C5B2; read by: sub_C678
trans_v1B33                              equ $1B33	; analysis: from tblOfs3D_TRANS_load_3C1D | inferred name; written by: lookup_TRANS_load_C5B2; read by: sub_C678
trans_v1B34                              equ $1B34	; analysis: word: input/engine speed reference during engagement | inferred name; written by: lookup_TRANS_load_C5B2; read by: lookup_TRANS_load_C5B2
trans_v1B35                              equ $1B35	; inferred name; written by: lookup_TRANS_load_C5B2; read by: -
garage_adapt_loop_idx                    equ $1B36	; analysis: neighbour offset 0..4 in garage adapt loop
garage_adapt_temp_cell                   equ $1B37	; analysis: trans temp cell index 0..14
eeprom_v1B38                             equ $1B38	; inferred name; written by: calc_garage_adapt_loop_idx_C445; read by: -
eeprom_v1B39                             equ $1B39	; inferred name; written by: calc_garage_adapt_loop_idx_C445; read by: calc_garage_adapt_loop_idx_C445
line_adapt_hold_timer                    equ $1B3D	; analysis: hold-off after an adapt step (k_3EAA)
line_adapt_slip_integ                    equ $1B3E	; analysis: signed slip-error integrator, +/-127 saturating
shift_v1B3F                              equ $1B3F	; analysis: latched engagement type from $62 (b0/b1 reverse-type use tbl_3C75; b2/b3 drive-type use tbl_3D77; b4/b5) | inferred name; written by: shift_task_C55D; read by: calc_garage_adapt_loop_idx_...
garage_adapt_inhibit                     equ $1B40	; analysis: b0 temp, b1 type, b2 rpm, b3 time too long, b4 FMEM
line_adapt_inhibit                       equ $1B41	; analysis: b0 upshift b1 downshift b2 gear not settled b3 low VSS b4 low load b5 P/N b6 FM fault
pcs_v1B42                                equ $1B42	; analysis: b0/b1 line pressure mode flags, b2 floor 0 | inferred name; written by: line_press_adapt_inhibit_flags_CFC9; read by: line_press_adapt_slip_integrator_D0AD
egr_v1B43                                equ $1B43	; analysis: TCC/gear state flags selecting slip test path | inferred name; written by: Central_Scheduler_part_D190; read by: line_press_adapt_slip_integrator_D0AD
trans_KAM_reset_flags                    equ $1B44	; analysis: b0/b1/b3/b4 = adapt block at 031F/0316/0353/02F7 reinitialized at reset
line_adapt_status                        equ $1B45	; analysis: b0 decreased, b1 increased, b2 step done (clear integrator)
shift_monitor_flags                      equ $1B46	; analysis: b0 shift monitored, b1 upshift, b2 downshift, b3 not top gear, b4 init done, b5 adapt done
shift_monitor_gear                       equ $1B47	; analysis: gear latched at shift start
shift_start_load                         equ $1B48	; analysis: trans_load_filtered at upshift start
shift_timer                              equ $1B49	; analysis: counts per pass since shift command, sat 255
shift_v1B4A                              equ $1B4A	; analysis: final $1B49 of previous shift | inferred name; written by: upshift_timing_monitor_D382; read by: calc_shift_adapt_inhibit_2_CA67
shift_delay_time                         equ $1B4B	; analysis: time from command to ratio-change start; per gear copies follow
shift_inertia_time                       equ $1B52	; analysis: duration of ratio change ($1B49-$1B4B)
shift_v1B53                              equ $1B53	; analysis: 16-bit accumulator then average ratio over inertia phase | inferred name; written by: upshift_timing_monitor_D382; read by: calc_shift_adapt_qualifier_3_CADB, upshift_timing_monitor_D382
shift_v1B54                              equ $1B54	; inferred name; written by: upshift_timing_monitor_D382; read by: -
shift_adapt_inhibit_1                    equ $1B5B	; analysis: see calc_shift_adapt_inhibit_1B5B
shift_adapt_inhibit_2                    equ $1B5C	; analysis: see calc_shift_adapt_inhibit_1B5C
shift_adapt_qualifier_3                  equ $1B5D	; analysis: see calc_shift_adapt_inhibit_1B5D
shift_adapt_status                       equ $1B5E	; analysis: b7 = no target curve for this gear; b7 learning disabled, b0 learn this shift, b1 clamped at min, b2..b5 correction case
trans_v1B5F                              equ $1B5F	; analysis: b0 garage pressure active, b1 new engagement, b2 engagement inhibited, b3 speed-drop flag, b4 adapt ready, b5 no boost, b6 adapt done | inferred name; written by: trans_init_at_reset_9114...
shift_time_error                         equ $1B60	; analysis: signed error that indexes the adapt correction curve; signed target - measured shift time
shift_time_target                        equ $1B64	; analysis: target shift time from per-gear curve vs $1B7F
shift_adapt_correction                   equ $1B68	; analysis: signed correction for this shift
shift_adapt_value                        equ $1B69	; analysis: signed learned adapt at current axis point
shift_adapt_cell_idx                     equ $1B6A	; analysis: 0..16 = torque axis/32
shift_v1B6B                              equ $1B6B	; inferred name; written by: reset_shift_adapt_cells_CA24; read by: reset_shift_adapt_cells_CA24
pcs_v1B6D                                equ $1B6D	; analysis: non-zero value used directly as line_pressure_desired | inferred name; written by: -; read by: calc_line_pressure_desired_C6D5
line_press_trim                          equ $1B6E	; analysis: signed trim added to line_pressure_desired
shift_v1B6F                              equ $1B6F	; inferred name; written by: -; read by: upshift_adapt_sequencer_D301
shift_adapt_flags                        equ $1B70	; analysis: b7 = reload shift adapt tables from ROM (consumed in CA24); b7 reset adapt cells to defaults, b0 inhibit learning
shift_v1B71                              equ $1B71	; analysis: signed, 3-D table torque x temp | inferred name; written by: calc_shift_press_temp_corr_CD4C; read by: calc_shift_pressure_cmd_CC0B
shift_press_axis_crv                     equ $1B72	; analysis: curve axis pair (1B72 fraction, 1B73 cell) of 1B74/6
shift_v1B73                              equ $1B73	; inferred name; written by: calc_shift_press_axis_crv_CBA1; read by: -
shift_v1B74                              equ $1B74	; analysis: base shift pressure incl. adapt | inferred name; written by: calc_shift_press_axis_crv_CBA1; read by: calc_shift_pressure_cmd_CC0B
shift_v1B75                              equ $1B75	; analysis: signed, per-gear curve vs $187E | inferred name; written by: shift_task_CC46; read by: calc_shift_pressure_cmd_CC0B
shift_v1B76                              equ $1B76	; analysis: turbine-speed-based offset to the torque axis | inferred name; written by: calc_shift_start_load_CE30; read by: calc_shift_start_load_CDEF, calc_shift_start_load_CE30
shift_v1B77                              equ $1B77	; analysis: signed 16-bit ramp during shift (hi byte used) | inferred name; written by: shift_task_CC6C, shift_task_CC9F, shift_task_CD8A; read by: calc_shift_pressure_cmd_CC0B, shift_task_CD8A
shift_pressure_cmd                       equ $1B79	; analysis: final shift pressure request
shift_start_load_1B7A                    equ $1B7A	; analysis: trans_load_filtered when the axis was latched
shift_v1B7B                              equ $1B7B	; analysis: latched load/torque axis (0..512) for shift tables | inferred name; written by: calc_shift_start_load_CDEF, calc_shift_start_load_CE30; read by: lookup_shift_adapt_cell_C9EC, calc_shift_a...
shift_v1B7D                              equ $1B7D	; inferred name; written by: calc_shift_start_load_CDEF, calc_shift_start_load_CE30; read by: -
shift_torque_axis_crv                    equ $1B7F	; analysis: curve axis pair: 1B7F fraction, 1B80 cell (1B7B/32)
shift_v1B80                              equ $1B80	; inferred name; written by: calc_shift_start_load_CDEF, calc_shift_start_load_CE30; read by: -
shift_v1B81                              equ $1B81	; inferred name; written by: calc_shift_start_load_CDEF, calc_shift_start_load_CE30; read by: pcs_task_C2C5, pcs_task_C2CF
shift_v1B82                              equ $1B82	; inferred name; written by: calc_shift_start_load_CDEF, calc_shift_start_load_CE30; read by: -
shift_v1B83                              equ $1B83	; analysis: unlatched value of the same quantity | inferred name; written by: calc_shift_start_load_CDEF, calc_shift_start_load_CE30; read by: calc_shift_start_load_CDEF, calc_shift_start_load_CE30
shift_v1B85                              equ $1B85	; analysis: b0 cleared by CC0B, b1 torque axis re-latched, b2 used in pressure arbitration | inferred name; written by: Central_Scheduler_part_C39E, calc_shift_pressure_cmd_CC0B, calc_shift_start_loa...
line_press_source_flags                  equ $1B86	; analysis: winning source of line_pressure_desired: b0 base/1B89, b1 garage 1B31, b2 override 1B6D, b3 failsafe max, b4/b5 shift 1B79, b6 1B25, b7 load curve
line_press_source_flags2                 equ $1B87	; analysis: b0 = speed floor 1B8A used
line_pressure_desired                    equ $1B88
pcs_v1B89                                equ $1B89	; analysis: candidate base line pressure compared with 1B25 in calc_line_pressure_desired (writer outside chunk) | inferred name; written by: Central_Scheduler_part_C39E; read by: calc_line_pressure_...
line_press_floor_by_speed                equ $1B8A	; analysis: min line pressure from output speed (C41B); 0 when shifting
trans_v1B8D                              equ $1B8D	; inferred name; written by: -; read by: calc_trans_torque_red_request_BFE2
trans_v1B8F                              equ $1B8F	; inferred name; written by: -; read by: calc_trans_torque_red_request_BFE2
pcs_v1B92                                equ $1B92	; inferred name; written by: pcs_task_C046, pcs_task_C18B; read by: calc_trans_torque_red_request_BFE2, pcs_task_C046, pcs_task_C18B
pcs_v1B93                                equ $1B93	; inferred name; written by: pcs_task_BDF4, pcs_task_C046, pcs_task_C18B; read by: pcs_task_BDF4, pcs_task_C046, pcs_task_C18B
pcs_v1B94                                equ $1B94	; inferred name; written by: pcs_task_BDF4, pcs_task_C18B; read by: pcs_task_BDF4, pcs_task_C18B
trans_v1B95                              equ $1B95	; analysis: source code bits, see BFE2 | inferred name; written by: calc_trans_torque_red_request_BFE2; read by: -
pcs_v1B96                                equ $1B96	; inferred name; written by: -; read by: pcs_task_C046
pcs_v1B97                                equ $1B97	; inferred name; written by: -; read by: pcs_task_C046
pcs_v1B98                                equ $1B98	; inferred name; written by: -; read by: pcs_task_C046
pcs_v1B99                                equ $1B99	; inferred name; written by: -; read by: pcs_task_C046
pcs_v1B9A                                equ $1B9A	; analysis: from sub_C2CF | inferred name; written by: pcs_task_C2C5, pcs_task_C2CF; read by: pcs_task_BDF4, pcs_task_C046, pcs_task_C18B
pcs_v1B9D                                equ $1B9D	; inferred name; written by: pcs_task_BDF4, pcs_task_C046, pcs_task_C18B; read by: pcs_task_C2C5, pcs_task_C2CF
pcs_v1B9F                                equ $1B9F	; inferred name; written by: pcs_task_BDF4; read by: pcs_task_BDF4
pcs_v1BA0                                equ $1BA0	; inferred name; written by: pcs_task_BDF4; read by: -
pcs_v1BA1                                equ $1BA1	; inferred name; written by: pcs_task_BDF4; read by: pcs_task_BDF4
pcs_v1BA2                                equ $1BA2	; analysis: profile tick timer | inferred name; written by: pcs_task_BDF4, pcs_task_C046; read by: pcs_task_BDF4, pcs_task_C046
pcs_v1BA3                                equ $1BA3	; analysis: pressure adder from pcs_task_BDF4 | inferred name; written by: pcs_task_BDF4; read by: pcs_task_BDF4, calc_trans_torque_red_request_BFE2
pcs_v1BA5                                equ $1BA5	; analysis: pressure adder from sub_C046/sub_C18B | inferred name; written by: pcs_task_C046, pcs_task_C18B; read by: calc_trans_torque_red_request_BFE2, pcs_task_C046, pcs_task_C18B
trans_torque_red_request                 equ $1BA7	; analysis: requested fuel reduction from the trans code (written at bank0 9130/C03F); selected adder byte
trans_v1BA8                              equ $1BA8	; inferred name; written by: -; read by: calc_trans_torque_red_request_BFE2
pcs_v1BA9                                equ $1BA9	; inferred name; written by: Central_Scheduler_part_BDC4; read by: -
pcs_v1BAA                                equ $1BAA	; analysis: tracked peak/valley of line_pressure_desired for PCS table hysteresis | inferred name; written by: calc_pcs_sol_setpt; read by: calc_pcs_sol_setpt
FORCE_MTR_ITERM                          equ $1BAD	; analysis: PI integrator/output word, clamped kw_4AAE..kw_4AAC | OBD1 FORCE_MTR_ITERM [A]
PCS_duty_out                             equ $1BAF	; last value written to IOR 1809 (TCC PWM duty, see PCS_duty_cmd note) | analysis: copy of duty written to 1809 in ECT-output mode; copy of duty written to PWM 1809
IREF                                     equ $1BB0	; analysis: commanded force motor current; force-motor setpoint output of calc_pcs_sol_setpt | OBD1 IREF [A]
PCS_current_meas                         equ $1BB1	; analysis: AN2 force-motor current, 4-sample average
FORCE_MTR_ERR                            equ $1BB2	; analysis: signed error cmd-meas after deadband | OBD1 FORCE_MTR_ERR [A]
FORCE_MTR_GAIN_IDX                       equ $1BB3	; OBD1 FORCE_MTR_GAIN_IDX [A]
FORCE_MTR_IGAIN                          equ $1BB4	; OBD1 FORCE_MTR_IGAIN [A]
FORCE_MTR_PGAIN                          equ $1BB5	; OBD1 FORCE_MTR_PGAIN [A]
ODM_shiftA_diag_status                   equ $1BB6	; analysis: b0 fault sample, b1 OK sample (equates show FORCE_MTR_PGAIN+1); sub_5E1E state; b0 fault, b1 pass-ish; used by diag_P0753
ODM_shiftB_diag_status                   equ $1BB7	; analysis: b0 fault sample, b1 OK sample; sub_5E1E state for shift sol B
trans_v1BB8                              equ $1BB8	; inferred name; written by: trans_KAM_adapt_init_check_913B; read by: -
ODM_TCC_PWM_diag_status                  equ $1BB9	; analysis: b0 fault sample, b1 OK sample; state byte of test state machine in diag_shift_sol_ODM_status
trans_v1BBA                              equ $1BBA	; inferred name; written by: trans_KAM_adapt_init_check_913B; read by: -
PCS_clean_pulse_state                    equ $1BBB	; analysis: b0 = low phase, b1 = high (FF) phase of force-motor cleaning pulse
PCS_clean_pulse_count                    equ $1BBC	; analysis: cleaning pulse cycles done, stops at k_4AB7
PCS_clean_pulse_timer                    equ $1BBD	; analysis: word tick counter for current pulse phase
pcs_v1BBE                                equ $1BBE	; inferred name; written by: PCS_PWM_output; read by: -
PCS_saturation_ctr                       equ $1BBF	; analysis: passes with PI output pinned at a limit
trans_diag_status                        equ $1BC1	; analysis: b2 slip event latched, b4 high-voltage latch, b5/b6/b7 P1870 confirmation stages; base of status block: +0 event latches (.0 P0741, .1 P0742), +1/+2 fault masks, +12 P0711 state
trans_fault_summary1                     equ $1BC2	; analysis: b0 input spd P0716/17, b1 output spd P0722/23, b3 P1810, b4 DERATE_LIMP_ENA_FLAGS2.7, b6 voltage out of range, b7 brake sw P0719/P0724
trans_fault_summary2                     equ $1BC3	; analysis: b0 P0751/P0756, b1 P0753/P0758, b2 P1860, b3 P0741/P0742, b4 ECT P0117/P0118, b6/b7 P1870 stage
P0756_gear_result_bits                   equ $1BC4	; analysis: low nibble: fault ratio seen in gear 1..4; high nibble: correct ratio seen in gear 1..4; per-gear fault/pass bits for sol B test
shift_v1BC6                              equ $1BC6	; analysis: per-gear fault/pass bits for sol A test | inferred name; written by: diag_P0751_shift_sol_A_perf_9D5A; read by: diag_P0751_shift_sol_A_perf_9D5A
shift_v1BCA                              equ $1BCA	; analysis: b0-2 fail, b5 last 4WD state, b6/b7 gear seen | inferred name; written by: -; read by: diag_P0730_incorrect_gear_ratio_A9A1, calc_4WD_and_PTO_flags_B8A4
brake_switch_diag_state                  equ $1BCB	; analysis: b0-b2 P0724 launch state, b3 P0719 armed, b4 brake seen
system_voltage_state                     equ $1BCC	; analysis: b0 not low, b1 low, b2 not high, b3 high (P0560)
P0711_state                              equ $1BCD	; analysis: b0 no-warmup fail, b1 erratic fail, b2 pass, b3 pass pending, b4 VSS enable met, b5 slip enable met, b6 inhibit
trans_temp_diag                          equ $1BCE	; analysis: byte copy of filtered trans temp; trans temp copy (or substitute) used by diags; trans temp copy used by diags (default value on sensor fault)
trans_v1BCF                              equ $1BCF	; analysis: stage dwell timer for detect_engine_start_range | inferred name; written by: RUN_DIAGS_AUTO_TRANS_part_A282; read by: RUN_DIAGS_AUTO_TRANS_part_A282
engine_running_timer                     equ $1BD0	; analysis: 16-bit ticks with RPM > kw_4B6F; sets DS_STATUS.6; counts while engine speed > kw_4B6F; sets DS_STATUS.6
TCC_mode_timer                           equ $1BD3	; analysis: ticks with DS_TCCMODE bit2/bit4 set
last_gear_1BD4                           equ $1BD4	; analysis: trans_gear_AT from previous pass
gear_dwell_timer                         equ $1BD5	; analysis: ticks in current gear, saturating
trans_v1BD6                              equ $1BD6	; inferred name; written by: calc_trans_speed_ratios_A328; read by: -
trans_v1BD8                              equ $1BD8	; inferred name; written by: calc_trans_speed_ratios_A328; read by: -
ODM_status_hi                            equ $1BDA	; analysis: ODM SPI status byte (1BDB = low)
ram_v1BDB                                equ $1BDB	; inferred name; written by: calc_ODM_status_hi_5CF7; read by: -
P0722_pass_cnt                           equ $1BDC	; analysis: byte; $1BDD fail
P0722_fail_cnt                           equ $1BDD	; analysis: byte
P0723_pass_cnt                           equ $1BDE	; analysis: byte; $1BDF fail
P0723_fail_cnt                           equ $1BDF	; analysis: byte
outspd_above_min_cnt                     equ $1BE0	; analysis: time output speed > kw_4B94, saturating; P0723 enable
outspd_stable_cnt                        equ $1BE1	; analysis: time with no large output-speed rise; P0723 enable
time_since_4WD_change                    equ $1BE2	; analysis: saturating counter
volt_ok_low_counters                     equ $1BE4	; analysis: 1BE4 not-low count, 1BE5 low count (P0560)
pcs_v1BE5                                equ $1BE5	; inferred name; written by: -; read by: diag_P0560_system_voltage_A096, diag_P0748_PCS_circuit_AE5D
volt_ok_high_counters                    equ $1BE6	; analysis: 1BE6 not-high count, 1BE7 high count (P0560)
ram_v1BE7                                equ $1BE7	; inferred name; written by: -; read by: diag_P0560_system_voltage_A096
P0711_pass_cnt                           equ $1BE8	; analysis: word
ram_v1BE9                                equ $1BE9	; inferred name; written by: diag_P0711_TFT_range_perf_B184; read by: -
P0711_nowarm_cnt                         equ $1BEA	; analysis: word fail counter (no warm-up)
P0711_sample_cnt                         equ $1BEC	; analysis: erratic-test window sample counter
P0711_jump_cnt                           equ $1BED	; analysis: erratic jumps in window
P0711_vss_time                           equ $1BEE	; analysis: word enable timer
P0711_slip_time                          equ $1BF0	; analysis: word enable timer
trans_temp_prev_sample                   equ $1BF2	; analysis: previous trans_temp_filtered for erratic test
P0712_pass_cnt                           equ $1BF3	; analysis: $1BF4 fail
P0712_fail_cnt                           equ $1BF4
P0713_pass_cnt                           equ $1BF5	; analysis: byte
P0713_fail_cnt                           equ $1BF6	; analysis: word
P0717_pass_cnt                           equ $1BF8	; analysis: byte pass counter; $1BF9 = fail counter
P0717_fail_cnt                           equ $1BF9	; analysis: byte fail counter
P0716_pass_cnt                           equ $1BFA	; analysis: word
ram_v1BFB                                equ $1BFB	; inferred name; written by: diag_P0716_input_speed_perf_AC1C; read by: -
P0716_fail_cnt                           equ $1BFC	; analysis: word; nonzero freezes input speed
brake_on_timer_P0719                     equ $1BFE	; analysis: brake-on ticks to pass P0719
stops_without_brake                      equ $1BFF	; analysis: P0719 fail counter
P0719_mid_speed_timer                    equ $1C00	; analysis: time between 5 and 20 mph
P0719_high_speed_timer                   equ $1C01	; analysis: time above 20 mph
brake_on_time_P0724                      equ $1C02	; analysis: 16-bit brake-on time
ram_v1C03                                equ $1C03	; inferred name; written by: diag_P0724_brake_switch_high_A634; read by: -
brake_off_timer_P0724                    equ $1C04	; analysis: brake-off ticks to pass P0724
launches_with_brake                      equ $1C05	; analysis: P0724 launch counter
ram_v1C06                                equ $1C06	; inferred name; written by: diag_P0724_brake_switch_high_A634; read by: diag_P0724_brake_switch_high_A634
ram_v1C07                                equ $1C07	; inferred name; written by: diag_P0724_brake_switch_high_A634; read by: diag_P0724_brake_switch_high_A634
P0741_pass_cnt                           equ $1C08	; analysis: $1C09 fail, $1C0A event count
P0741_fail_cnt                           equ $1C09
P0741_event_cnt                          equ $1C0A	; analysis: failed apply events
P0742_pass_cnt                           equ $1C0B	; analysis: $1C0C fail, $1C0D events
P0742_fail_cnt                           equ $1C0C
P0742_event_cnt                          equ $1C0D
shift_v1C0E                              equ $1C0E	; analysis: 1C0E own-window fault count, 1C0F wrong-gear count | inferred name; written by: diag_P0751_shift_sol_A_perf_9D5A; read by: diag_P0751_shift_sol_A_perf_9D5A
shift_v1C0F                              equ $1C0F	; inferred name; written by: diag_P0751_shift_sol_A_perf_9D5A; read by: diag_P0751_shift_sol_A_perf_9D5A
shift_v1C10                              equ $1C10	; analysis: followed by 1C11 pass count | inferred name; written by: diag_P0751_shift_sol_A_perf_9D5A; read by: diag_P1875_9975, diag_P0751_shift_sol_A_perf_9D5A, diag_P1870_TCC_slip_A764
shift_v1C11                              equ $1C11	; inferred name; written by: -; read by: diag_P1875_9975, diag_P0751_shift_sol_A_perf_9D5A, diag_P1870_TCC_slip_A764
trans_ratio_for_diag                     equ $1C12	; analysis: engine/output ratio in top gear with TCC, else $1877; ratio used by shift-sol performance diags
shift_v1C1B                              equ $1C1B	; inferred name; written by: diag_P0753_shift_sol_A_electrical_AA73; read by: diag_P0753_shift_sol_A_electrical_AA73
shift_v1C1C                              equ $1C1C	; inferred name; written by: diag_P0753_shift_sol_A_electrical_AA73; read by: diag_P0753_shift_sol_A_electrical_AA73
shift_v1C1D                              equ $1C1D	; inferred name; written by: diag_P0753_shift_sol_A_electrical_AA73; read by: diag_P0753_shift_sol_A_electrical_AA73
P0756_pass_dwell                         equ $1C1E	; analysis: dwell in correct ratio window; 1C1F = dwell in fault window
shift_v1C1F                              equ $1C1F	; inferred name; written by: diag_P0756_gear_change_reset_9F80; read by: diag_P0756_shift_sol_B_perf_9F04, diag_P0756_gear_change_reset_9F80
P0756_fail_count_lo                      equ $1C20	; analysis: gears 1/2 fail events; 1C21 = gear 3/4 events
shift_v1C21                              equ $1C21	; inferred name; written by: -; read by: diag_P1875_9975, diag_P0756_shift_sol_B_perf_9F04, diag_P0756_gear_change_reset_9F80, diag_P1870_TCC_slip_A764
shift_v1C22                              equ $1C22	; inferred name; written by: diag_P0758_shift_sol_B_electrical_AADA; read by: diag_P0758_shift_sol_B_electrical_AADA
shift_v1C23                              equ $1C23	; inferred name; written by: diag_P0758_shift_sol_B_electrical_AADA; read by: diag_P0758_shift_sol_B_electrical_AADA
shift_v1C24                              equ $1C24	; inferred name; written by: diag_P0758_shift_sol_B_electrical_AADA; read by: diag_P0758_shift_sol_B_electrical_AADA
ram_v1C26                                equ $1C26	; inferred name; written by: diag_P1810_9AFB; read by: diag_P1810_9AFB
ram_v1C27                                equ $1C27	; inferred name; written by: diag_P1810_9AFB; read by: diag_P1810_9AFB
ram_v1C28                                equ $1C28	; inferred name; written by: diag_P1810_9AFB; read by: diag_P1810_9AFB
ram_v1C29                                equ $1C29	; inferred name; written by: diag_P1810_9AFB; read by: diag_P1810_9AFB
ram_v1C2D                                equ $1C2D	; inferred name; written by: diag_P1810_9AFB; read by: diag_P1810_9AFB
ram_v1C2E                                equ $1C2E	; inferred name; written by: diag_P1810_9AFB; read by: diag_P1810_9AFB
ram_v1C2F                                equ $1C2F	; inferred name; written by: diag_P1810_9AFB; read by: diag_P1810_9AFB
ram_v1C30                                equ $1C30	; inferred name; written by: diag_P1810_9AFB; read by: diag_P1810_9AFB
ram_v1C31                                equ $1C31	; inferred name; written by: diag_P1810_9AFB; read by: diag_P1810_9AFB
P1811_long_shift_count                   equ $1C32	; analysis: per gear [trans_gear_AT]
P0218_pass_cnt                           equ $1C36	; analysis: byte
P0218_fail_cnt                           equ $1C37	; analysis: word
tcc_v1C39                                equ $1C39	; inferred name; written by: diag_P1860_TCC_PWM_sol_electrical_AB41; read by: diag_P1860_TCC_PWM_sol_electrical_AB41
tcc_v1C3A                                equ $1C3A	; inferred name; written by: diag_P1860_TCC_PWM_sol_electrical_AB41; read by: diag_P1860_TCC_PWM_sol_electrical_AB41
tcc_v1C3B                                equ $1C3B	; inferred name; written by: diag_P1860_TCC_PWM_sol_electrical_AB41; read by: diag_P1860_TCC_PWM_sol_electrical_AB41
tcc_v1C3F                                equ $1C3F	; inferred name; written by: diag_P1870_TCC_slip_A764; read by: diag_P1870_TCC_slip_A764
tcc_v1C40                                equ $1C40	; inferred name; written by: diag_P1870_TCC_slip_A764; read by: diag_P1870_TCC_slip_A764
P1870_slip_events                        equ $1C41	; analysis: slip event count; 1C40 slip dwell, 1C3F no-slip dwell
tcc_v1C42                                equ $1C42	; analysis: counts while force-motor adapt request $1BC3.6 holds TCC off | inferred name; written by: calc_TCC_inhibit_flags_E09D; read by: calc_TCC_inhibit_flags_E09D
tcc_v1C44                                equ $1C44	; inferred name; written by: diag_P1870_TCC_slip_A764; read by: diag_P1870_TCC_slip_A764
tcc_v1C45                                equ $1C45	; inferred name; written by: diag_P1870_TCC_slip_A764; read by: diag_P1870_TCC_slip_A764
tcc_v1C46                                equ $1C46	; inferred name; written by: diag_P1870_TCC_slip_A764; read by: diag_P1870_TCC_slip_A764
P0730_pass_count                         equ $1C47	; analysis: 1C48 = fail count
shift_v1C48                              equ $1C48	; inferred name; written by: -; read by: diag_P0730_incorrect_gear_ratio_A9A1
ram_v1C49                                equ $1C49	; analysis: 1C49/1C4A mismatch counters, 1C4B confirm count | inferred name; written by: diag_P1875_9975; read by: diag_P1875_9975
ram_v1C4A                                equ $1C4A	; inferred name; written by: -; read by: diag_P1875_9975
ram_v1C4B                                equ $1C4B	; inferred name; written by: diag_P1875_9975; read by: diag_P1875_9975
ram_v1C4E                                equ $1C4E	; inferred name; written by: diag_P1875_9975; read by: diag_P1875_9975
ram_v1C4F                                equ $1C4F	; inferred name; written by: diag_P1875_9975; read by: diag_P1875_9975
trans_load_limp_latch                    equ $1C58	; analysis: b0 = limp load substitute active
devctl_status                            equ $1C59	; analysis: J1850 device control block: b1/b2 pending, b2 gear?, b3 PCS-forced, b4 pending; 1C5A request mask, 1C5B accepted, 1C5C requested states, 1C5D rejected, 1C5E gea; J1850 device-control tran...
devctl_request_mask                      equ $1C5A	; analysis: b0 gear, b1/b2 PCS/other output, b4 PCS pressure, b5 [$1B70].7 output; written by bank-1 J1850 handler; b0 gear, b2 TCC, b4 PCS pressure, b5 adapt reset
devctl_accepted_mask                     equ $1C5B	; analysis: same bit layout as 1C5A; nonzero sets DS_STATUS.5; same bit layout as 1C5A; set when accepted
tester_override_values                   equ $1C5C	; analysis: b2 TCC command, b5 adapt reset command; requested on/off state per bit
devctl_rejected_mask                     equ $1C5D	; analysis: b0/b2/b4 request refused (bank 1 then returns error 0B0x); same bit layout as 1C5A
devctl_gear_cmd                          equ $1C5E	; analysis: commanded gear 0..k_3890; tester commanded gear (0..k_3890)
tester_PCS_cmd                           equ $1C5F	; analysis: commanded PCS setpoint
idle_RPM_target                          equ $1C60	; OBD1 DES_IDLE_SPEED [A] | A225 list1 word37 ILVRPMD: Desired Idle Speed (RPM = N * 18.75)
baro_learn_counter                       equ $1C61	; analysis: counts passes with $5D.6 for MAP->baro relearn
LAST_DES_IDLE_SPEED                      equ $1C62	; OBD1 LAST_DES_IDLE_SPEED [A]
IDLE_SPEED_MID_BAND                      equ $1C63	; OBD1 IDLE_SPEED_MID_BAND [B]
IDLE_SPEED_HIGH_BAND                     equ $1C64	; OBD1 IDLE_SPEED_HIGH_BAND [A]
idle_err_filt_state_new                  equ $1C65	; analysis: 3 bytes 1C65-67: updated idle error filter state
idle_v1C67                               equ $1C67	; inferred name; written by: IDLE_MODE_GOVERNOR, idle_gov_cylbal_entry_9923; read by: calc_fuel_quantity
idle_err_filt_state                      equ $1C68	; analysis: 3 bytes 1C68-6A: committed idle error filter state
idle_v1C6A                               equ $1C6A	; inferred name; written by: calc_fuel_quantity, IDLE_MODE_GOVERNOR; read by: IDLE_MODE_GOVERNOR, idle_gov_cylbal_entry_9923
idle_error_filtered                      equ $1C6B	; analysis: lead-lag filtered idle RPM error (signed word), input to P and I
idle_v1C6D                               equ $1C6D	; analysis: copy of filtered error taken on first idle pass | inferred name; written by: calc_fuel_quantity, IDLE_MODE_GOVERNOR, idle_gov_cylbal_entry_9923; read by: -
IDLEDT90                                 equ $1C6F	; OBD1 IDLEDT90 [A]
IDLE_ERROR                               equ $1C71	; OBD1 IDLE_ERROR [B]
IDLE_FUEL_ITERM                          equ $1C73	; OBD1 IDLE_FUEL_ITERM [A] | idle fuel integrator
idle_v1C74                               equ $1C74	; inferred name; written by: -; read by: IDLE_MODE_GOVERNOR, idle_gov_cylbal_entry_9923
idle_v1C75                               equ $1C75	; inferred name; written by: idle_iterm_accum_clamp_9E85; read by: calc_fuel_quantity, IDLE_MODE_GOVERNOR, idle_gov_cylbal_entry_9923
IDLE_FUEL_ITERM_LAST                     equ $1C76	; OBD1 IDLE_FUEL_ITERM_LAST [A]
idle_v1C77                               equ $1C77	; inferred name; written by: IDLE_MODE_GOVERNOR; read by: idle_iterm_accum_clamp_9E85
fuel_v1C78                               equ $1C78	; inferred name; written by: calc_fuel_quantity; read by: idle_iterm_accum_clamp_9E85
IDLE_FUEL_PTERM                          equ $1C79	; OBD1 IDLE_FUEL_PTERM [A] | idle fuel proportional
idle_v1C7B                               equ $1C7B	; inferred name; written by: DO_IDLE_PGAIN; read by: IDLE_MODE_GOVERNOR, idle_gov_cylbal_entry_9923
IDLE_FUEL_DTERM                          equ $1C7C	; OBD1 IDLE_FUEL_DTERM [A] | 001a1e	= idle fuel derivative
idle_v1C7D                               equ $1C7D	; inferred name; written by: -; read by: IDLE_MODE_GOVERNOR, idle_gov_cylbal_entry_9923
idle_v1C7E                               equ $1C7E	; inferred name; written by: DO_IDLE_DGAIN; read by: IDLE_MODE_GOVERNOR, idle_gov_cylbal_entry_9923
IDLE_FUEL_REQ                            equ $1C7F	; OBD1 IDLE_FUEL_REQ [A] | A225 list2 word16 ILVFUEL: Idle Fuel Rate (FUEL RATE = N * .3125)
IDLE_ERROR_DIR                           equ $1C80	; OBD1 IDLE_ERROR_DIR [A]
IDLE_INT_DIRECTION                       equ $1C81	; OBD1 IDLE_INT_DIRECTION [A]
IDLE_MAXINT                              equ $1C82	; OBD1 IDLE_MAXINT [A]
ENGINE_ROUGH_TQBOOST                     equ $1C83	; OBD1 ENGINE_ROUGH_TQBOOST [A]
IN_1802_sample0                          equ $1C84	; OBD1 SWITCH2_DEBOUNCE_SR [A]
IN_1802_sample1                          equ $1C85	; analysis: previous 1802 sample; 1C86 = s2
IN_1802_sample2                          equ $1C86	; analysis: oldest 1802 sample
IN_1804_sample0                          equ $1C87	; OBD1 SWITCH_DEBOUNCE_SR [A]
IN_1804_sample1                          equ $1C88	; analysis: previous 1804 sample (s1); 1C89 = s2
IN_1804_sample2                          equ $1C89	; analysis: oldest 1804 sample for 3-sample debounce
APP1_ZERO_A                              equ $1C8A	; OBD1 APP1_ZERO_A [A] | also APP_1_KAM
APP2_ZERO_A                              equ $1C8C	; OBD1 APP2_ZERO_A [A]
APP3_ZERO_A                              equ $1C8E	; OBD1 APP3_ZERO_A [A] | also APP_2_KAM
APP_fault_bits_A                         equ $1C90	; analysis: b2 APP1 hi, b1 APP1 lo, b0 APP1 disagree, b6 APP2 hi, b5 APP2 lo, b4 APP2 disagree, b7/b3 5V ref low
APP_fault_bits_B                         equ $1C91	; analysis: b2 APP3 hi, b1 APP3 lo, b0 APP3 disagree
input_shaft_pulse_count                  equ $1C92
input_shaft_last_capture                 equ $1C93
VSS_pulse_count                          equ $1C95
VSS_last_capture                         equ $1C96
TRANS_SHAFT_CTR_EXTENSION                equ $1C99	; OBD1 TRANS_SHAFT_CTR_EXTENSION [A] | part of structure
NEXT_OC2_OFF                             equ $1C9A	; OBD1 NEXT_OC2_OFF [C]
NEXT_OC2_ON                              equ $1C9C	; OBD1 NEXT_OC2_ON [C]
engine_load_est_filtered                 equ $1C9E	; OBD1 SIM_TPS [A] | 000f  'ST' * .39215
LAST_VSPD_FOR_DERIV                      equ $1CA0	; OBD1 LAST_VSPD_FOR_DERIV [A]
VEH_SPEED_DERIVATIVE                     equ $1CA2	; OBD1 VEH_SPEED_DERIVATIVE [A]
VEH_SPD_INPUT_STRUCT                     equ $1CA4	; OBD1 VEH_SPD_INPUT_STRUCT [B] | equ	0357h		; 9 bytes...
VEH_SPD_4K_PAICT                         equ $1CAD	; OBD1 VEH_SPD_4K_PAICT [A]
VEH_SPD_4K_CT                            equ $1CAE	; OBD1 VEH_SPD_4K_CT [A]
VEH_SPD_4K_TCNT                          equ $1CB0	; OBD1 VEH_SPD_4K_TCNT [A]
VSS_pulse_delta                          equ $1CB1	; analysis: VSS pulses counted since last 12.5ms-ish pass; summed into 0272/0274
AC_load_torque_clamped                   equ $1CB2	; analysis: $1CBA limited to 0..127
engine_torque_net                        equ $1CB3	; analysis: 16-bit: $1CB6 minus A/C load, floored at 0; read by bank0 B95B (trans)
ambient_temp_est                         equ $1CB5	; analysis: IAT tracked downward only (min-tracking filter); axis for the A/C load table
engine_torque_est                        equ $1CB6	; analysis: 16-bit, from RPM x fuel tables 4D1B/4DB5 (+kw_4D12), NA-derated
vss_v1CB8                                equ $1CB8	; analysis: extra A/C load during compressor engagement, rises then decays | inferred name; written by: calc_AC_load_torque_C687; read by: calc_AC_load_torque_C687
vss_v1CB9                                equ $1CB9	; analysis: reloaded with k_4D17 while A/C is off | inferred name; written by: calc_AC_load_torque_C687; read by: calc_AC_load_torque_C687
AC_load_torque                           equ $1CBA	; analysis: tbl 4E4F[ambient] + kick; 0 when A/C off
torque_task_div4_ctr                     equ $1CBB	; analysis: runs the ambient/NA-derate refresh every 4th call
torque_reduction_timer                   equ $1CBC	; analysis: loaded with k_4D16; counts calls during which a trans torque reduction is honoured
torque_est_fuel_index                    equ $1CBD	; analysis: FUEL_CMD_TMP raised to fuel_quantity if larger
NA_baro_torque_factor                    equ $1CBE	; analysis: x/128 multiplier, NA engines only
fuel_v1CBF                               equ $1CBF	; analysis: subtracted from $80 to give the IAT multiplier, NA only | inferred name; written by: calc_engine_torque_est_from_NA_fuel_derate_BARO_C586; read by: calc_engine_torque_est_from_NA_fuel_der...
SERIAL_TEST_MODE                         equ $1CC0	; OBD1 SERIAL_TEST_MODE [A]
tdc_v1CC1                                equ $1CC1	; inferred name; written by: TDC_learn_finish_P1214_AA95, set_test_cyl_cut_number_E7A1, J1850_diag_session_timer_EE4C; read by: calc_fuel_quantity, calc_fuel_quantity_tail_92CC, calc_TDC_learn_test_r...
idle_v1CC2                               equ $1CC2	; inferred name; written by: set_test_cyl_cut_number_E7A1; read by: idle_RPM_target_task_F716
serial_v1CC3                             equ $1CC3	; inferred name; written by: set_test_cyl_cut_number_E7A1, J1850_diag_session_timer_EE4C; read by: calc_TDC_learn_test_result_84BD
serial_v1CC5                             equ $1CC5	; inferred name; written by: set_diag_tx_data_len_E7F2, J1850_diag_session_timer_EE4C; read by: DO_ENG_STOP_SOL, EGR_vent_and_baro_sample_AE0A, calc_sensor_pullup_range_F827
glow_v1CC6                               equ $1CC6	; inferred name; written by: set_diag_tx_data_len_E7F2; read by: DO_MANUAL_GLOWPLUG_CTL, DO_ENG_STOP_SOL, EGR_vent_and_baro_sample_AE0A, calc_sensor_pullup_range_F827
serial_v1CC7                             equ $1CC7	; inferred name; written by: set_diag_tx_data_len_E7F2, J1850_diag_session_timer_EE4C; read by: -
ram_v1CC8                                equ $1CC8	; inferred name; written by: set_diag_tx_data_len_E7F2; read by: -
serial_v1CC9                             equ $1CC9	; inferred name; written by: calc_EEPROM_shadow_8FC0, J1850_diag_session_timer_EE4C; read by: calc_antitheft_delay_tmr_8DA8, J1850_mode3B_write_data_by_id_E34E, J1850_mode3C_read_data_by_id_E5CD
serial_v1CCA                             equ $1CCA	; inferred name; written by: J1850_diag_session_timer_EE4C; read by: calc_CKP_edges_per_cam_cycle_8141, calc_TDC_learn_test_result_84BD, boost_control, EGR_control
tdc_v1CCB                                equ $1CCB	; inferred name; written by: -; read by: calc_TDC_learn_test_result_84BD
boost_v1CCC                              equ $1CCC	; inferred name; written by: set_diag_tx_data_len_E7F2; read by: boost_control
egr_v1CCD                                equ $1CCD	; inferred name; written by: set_diag_tx_data_len_E7F2; read by: EGR_control
rpm_v1CCE                                equ $1CCE	; inferred name; written by: set_diag_tx_data_len_E7F2; read by: calc_CKP_edges_per_cam_cycle_8141
test_cyl_cut_number                      equ $1CCF	; analysis: serial test mode: cylinder (firing order index 1..8) whose fuel is cut
OVERRIDE_GLOWPLUG                        equ $1CD0	; OBD1 OVERRIDE_GLOWPLUG [A]
glow_v1CD1                               equ $1CD1	; inferred name; written by: DO_MANUAL_GLOWPLUG_CTL; read by: DO_MANUAL_GLOWPLUG_CTL
TDC_LEARN_STATE                          equ $1CD2	; OBD1 TDC_LEARN_STATE [A]
TDC_LEARN_TIMER                          equ $1CD3	; OBD1 TDC_LEARN_TIMER [A]
TDC_LEARN_VALUE                          equ $1CD4	; OBD1 TDC_LEARN_VALUE [A]
j1850_msg_request_bits                   equ $1CD6	; analysis: 6 bytes 1CD6-1CDB, one bit per message slot (48); bank1 E99D picks lowest set bit; 6 bytes, one bit per queued J1850 message (set by sub_6EDE)
J1850_rx_ring                            equ $1CE2	; analysis: 5 x 16-byte receive slots up to 1D31; byte 15 = $AA when consumed; read ptr $1D32, $1D38
serial_v1D32                             equ $1D32	; inferred name; written by: calc_J1850_DLC_cmd_C82A, calc_J1850_DLC_cmd_C8DD, J1850_mode36_download_execute_CA64; read by: calc_J1850_DLC_cmd_C8DD, J1850_mode36_download_execute_CA64
J1850_rx_ring_rd_ptr                     equ $1D34	; analysis: ptr into 5x16-byte rx ring $1CE2-$1D31
serial_v1D36                             equ $1D36	; inferred name; written by: calc_J1850_DLC_cmd_C8DD; read by: calc_J1850_DLC_cmd_C8DD
serial_v1D38                             equ $1D38	; inferred name; written by: calc_J1850_DLC_cmd_C82A, calc_J1850_DLC_cmd_C8DD, J1850_mode36_download_execute_CA64; read by: calc_J1850_DLC_cmd_C8DD
diag_req_queue_wr_ptr                    equ $1D75	; analysis: write ptr into 3x16-byte diag request queue $1D45-$1D74
diag_req_queue_rd_ptr                    equ $1D77	; analysis: read ptr of diag request queue
diag_tx_buffer                           equ $1D79	; analysis: J1850 reply frame: 1D79/1D7A header, 1D7B source, 1D7C mode|$40 (or $7F neg), 1D7D.. data; response frame: +0 priority, +1 target, +2 source, +3 mode|$40 (or $7F), +4.. data; response fra...
serial_v1D7D                             equ $1D7D	; inferred name; written by: J1850_mode3B_write_data_by_id_E34E, J1850_mode3C_read_data_by_id_E5CD; read by: -
diag_tx_data_len                         equ $1D84	; analysis: number of bytes from $1D7C to transmit; number of reply data bytes; number of response data bytes passed to sub_6EDE
diag_handler_desc_ptr                    equ $1D85	; analysis: current service descriptor {min,max,cont ptr,code}; pointer to header of current mode handler (min,max len,completion ptr,code)
diag_req_len                             equ $1D87	; analysis: request length (mode + data bytes); request length computed from frame end
PID_data_buf                             equ $1D88	; analysis: 4-byte scratch where PID handlers return data (X=$1D88); scratch output of data-list/freeze-frame formatters (returned in X); 1D88-1D8B also math temp
ram_v1D89                                equ $1D89	; inferred name; written by: calc_distance_since_DTC_clear_F28B, calc_PID_data_buf_F2BD; read by: calc_PID_data_buf_F2BD
ram_v1D8A                                equ $1D8A	; inferred name; written by: PID_00_supported_pids_EFDB, PID_01_monitor_status_F013, calc_distance_since_DTC_clear_F28B, calc_PID_data_buf_F2BD; read by: calc_distance_since_DTC_clear_F28B, calc_PID_...
ram_v1D8B                                equ $1D8B	; inferred name; written by: calc_distance_since_DTC_clear_F28B; read by: -
ram_v1D8E                                equ $1D8E	; analysis: source address latched from a broadcast msg; used to map record IDs $9201 | inferred name; written by: -; read by: sub_F40E, calc_DPID_record_ptr_D9B3
ram_v1D8F                                equ $1D8F	; analysis: as 1D8E, paired with ID $3A05 | inferred name; written by: -; read by: sub_F40E, calc_DPID_record_ptr_D9B3, calc_diag_tx_data_len_DB18
egr_v1D90                                equ $1D90	; inferred name; written by: diag_EGR_MAF_and_misc_DTCs_7672, ignition_off_powerdown_F615, set_EGR_flow_test_progress_F685; read by: diag_EGR_MAF_and_misc_DTCs_7672, calc_antitheft_state_8F66
egr_v1D91                                equ $1D91	; inferred name; written by: diag_EGR_MAF_and_misc_DTCs_7672, set_EGR_flow_test_progress_F685; read by: diag_EGR_MAF_and_misc_DTCs_7672
serial_v1D92                             equ $1D92	; analysis: b3 = diag request queue overflow | inferred name; written by: calc_J1850_DLC_cmd_C8DD, J1850_rx_message_process_CBFD; read by: calc_J1850_DLC_cmd_C8DD, J1850_rx_message_process_CBFD
serial_v1D93                             equ $1D93	; inferred name; written by: calc_J1850_DLC_cmd_E8B5; read by: calc_J1850_DLC_cmd_E8B5
serial_v1D94                             equ $1D94	; inferred name; written by: calc_J1850_DLC_cmd_C8DD; read by: calc_J1850_DLC_cmd_C8DD
serial_v1D95                             equ $1D95	; inferred name; written by: calc_J1850_DLC_cmd_C8DD, calc_J1850_DLC_cmd_E8B5; read by: calc_J1850_DLC_cmd_E8B5
serial_v1D96                             equ $1D96	; inferred name; written by: calc_J1850_DLC_cmd_E8B5; read by: calc_J1850_DLC_cmd_E8B5
serial_v1D97                             equ $1D97	; inferred name; written by: b1_sub_C892, calc_J1850_DLC_cmd_E8B5; read by: b1_sub_C892, calc_J1850_DLC_cmd_E8B5
serial_v1D98                             equ $1D98	; inferred name; written by: calc_J1850_DLC_cmd_C82A, calc_J1850_DLC_cmd_E8B5; read by: calc_J1850_DLC_cmd_E8B5
serial_v1D9A                             equ $1D9A	; inferred name; written by: calc_J1850_DLC_cmd_C82A; read by: -
serial_v1D9B                             equ $1D9B	; inferred name; written by: calc_J1850_DLC_cmd_C82A, calc_J1850_DLC_cmd_E8B5; read by: calc_J1850_DLC_cmd_E8B5
serial_v1D9C                             equ $1D9C	; analysis: bit mask of current tx request in $1CD6 table (byte index $1D9D) | inferred name; written by: calc_J1850_DLC_cmd_C82A, calc_J1850_DLC_cmd_E8B5; read by: calc_J1850_DLC_cmd_C8DD, calc_J185...
serial_v1D9D                             equ $1D9D	; inferred name; written by: calc_J1850_DLC_cmd_C82A, calc_J1850_DLC_cmd_E8B5; read by: calc_J1850_DLC_cmd_C8DD, calc_J1850_DLC_cmd_E8B5, J1850_tx_response_buffer_EAAF
serial_v1D9E                             equ $1D9E	; inferred name; written by: calc_J1850_DLC_cmd_C82A, calc_J1850_DLC_cmd_E8B5; read by: calc_J1850_DLC_cmd_E8B5
serial_v1D9F                             equ $1D9F	; analysis: 0-7 classification from b1:CD34; handlers act on 2,3,4,5,0,6 | inferred name; written by: calc_J1850_rx_len_err_count_CD34; read by: -
serial_v1DA0                             equ $1DA0	; inferred name; written by: calc_J1850_DLC_cmd_C8DD; read by: -
tx_next_msg_num                          equ $1DA2	; analysis: number of next pending message, $FF none
serial_v1DA4                             equ $1DA4	; analysis: countdown clearing $8E.0 | inferred name; written by: b1_sub_C892, J1850_diag_session_timer_EE4C; read by: sub_F40E, J1850_diag_session_timer_EE4C
serial_v1DA5                             equ $1DA5	; inferred name; written by: calc_J1850_DLC_cmd_C82A; read by: -
J1850_tx_loop_cnt                        equ $1DA6	; analysis: byte counter for transmit loops
J1850_tx_busy_timer                      equ $1DA8	; analysis: timeout for $8E.7 tx busy, reload 19
powerdown_ctr                            equ $1DA9	; analysis: ticks since IGN dropped below 4.9 V, up to k_329E
ram_v1DAA                                equ $1DAA	; inferred name; written by: -; read by: sub_8525
ram_v1DAC                                equ $1DAC	; inferred name; written by: -; read by: sub_8525
ram_v1DAD                                equ $1DAD	; inferred name; written by: -; read by: sub_8525
ram_v1DAE                                equ $1DAE	; inferred name; written by: sub_8525; read by: -
ram_v1DB0                                equ $1DB0	; inferred name; written by: -; read by: sub_8525
vss_v1DB2                                equ $1DB2	; inferred name; written by: -; read by: run_VSS_and_battery_diag_tests_C7E0
ram_v1DB3                                equ $1DB3	; inferred name; written by: -; read by: sub_F40E
ram_v1DB6                                equ $1DB6	; inferred name; written by: -; read by: sub_8525
ram_v1DB7                                equ $1DB7	; inferred name; written by: -; read by: sub_F40E
ram_v1DC3                                equ $1DC3	; inferred name; written by: -; read by: run_50ms_job_part_903B
ram_v1DC5                                equ $1DC5	; inferred name; written by: -; read by: calc_antitheft_state_8E71
ram_v1DC8                                equ $1DC8	; inferred name; written by: -; read by: run_50ms_job_part_903B
ram_v1DD4                                equ $1DD4	; inferred name; written by: sub_8525; read by: -
vss_v1DD5                                equ $1DD5	; inferred name; written by: run_VSS_and_battery_diag_tests_C7E0; read by: -
ram_v1DD6                                equ $1DD6	; analysis: message slot $22 status; $FF = lost | inferred name; written by: sub_F40E; read by: sub_F40E
ram_v1DD7                                equ $1DD7	; inferred name; written by: sub_F40E; read by: sub_F40E
ram_v1DD9                                equ $1DD9	; inferred name; written by: sub_8525; read by: sub_8525
ram_v1DDA                                equ $1DDA	; inferred name; written by: sub_8525; read by: sub_8525
ram_v1DDB                                equ $1DDB	; inferred name; written by: b1_sub_C892; read by: -
ram_v1DDC                                equ $1DDC	; analysis: message slot $26 status; $FF = lost | inferred name; written by: sub_F40E; read by: sub_F40E
ram_v1DDD                                equ $1DDD	; inferred name; written by: sub_F40E; read by: sub_F40E
ram_v1DDF                                equ $1DDF	; inferred name; written by: run_50ms_job_part_903B; read by: run_50ms_job_part_903B
ram_v1DE0                                equ $1DE0	; analysis: retry counter for test $28, gives up at 100 | inferred name; written by: run_50ms_job_part_903B; read by: run_50ms_job_part_903B
ram_v1DE1                                equ $1DE1	; analysis: J1850 anti-theft message slot $20 status; $FF = message lost | inferred name; written by: sub_F40E; read by: sub_F40E
ram_v1DE2                                equ $1DE2	; analysis: ticks since anti-theft message, limit 50 | inferred name; written by: sub_F40E; read by: sub_F40E
ram_v1DE3                                equ $1DE3	; inferred name; written by: run_50ms_job_part_903B; read by: run_50ms_job_part_903B
ram_v1DE4                                equ $1DE4	; analysis: retry counter, gives up at 100 (status 1DE3=FF) | inferred name; written by: run_50ms_job_part_903B; read by: run_50ms_job_part_903B
serial_v1DE9                             equ $1DE9	; inferred name; written by: calc_J1850_DLC_cmd_C8DD; read by: -
serial_v1DEA                             equ $1DEA	; inferred name; written by: calc_J1850_DLC_cmd_C8DD; read by: -
serial_v1DEB                             equ $1DEB	; inferred name; written by: calc_J1850_DLC_cmd_C8DD; read by: -
serial_v1DEC                             equ $1DEC	; inferred name; written by: calc_J1850_DLC_cmd_C8DD; read by: -
serial_v1DED                             equ $1DED	; inferred name; written by: calc_J1850_DLC_cmd_C8DD; read by: -
serial_v1DEE                             equ $1DEE	; inferred name; written by: calc_J1850_DLC_cmd_C8DD; read by: -
serial_v1DEF                             equ $1DEF	; inferred name; written by: calc_J1850_DLC_cmd_C8DD; read by: -
J1850_rx_len_err_count                   equ $1DF0	; analysis: incremented when a frame length mismatches
serial_v1DF1                             equ $1DF1	; analysis: b4 = device control (mode $AE) active | inferred name; written by: J1850_modeAE_device_control_E6BD, J1850_diag_session_timer_EE4C; read by: TOC3_scheduler_ISR_8000, calc_CKP_edges_per_ca...
DTC_select_byte_idx                      equ $1DF2	; analysis: current byte index in DTC selection bitmap ($FF = done); loop index / element offset in DPID record
ram_v1DF3                                equ $1DF3	; inferred name; written by: calc_DPID_record_ptr_D9B3; read by: -
DTC_select_bit_mask                      equ $1DF4	; analysis: current DTC bit mask / temp ($FF = done); record/frame index used by service $12 multi-frame reply
DPID_record_ptr                          equ $1DF5	; analysis: pointer to DPID record in $1E20 area
serial_v1DF7                             equ $1DF7	; inferred name; written by: calc_DPID_record_ptr_D9B3, J1850_mode2C_define_DPID_E06C; read by: J1850_mode2C_define_DPID_E06C
serial_v1DF9                             equ $1DF9	; inferred name; written by: calc_DPID_record_ptr_D9B3, b1_sub_DA56, J1850_mode2C_define_DPID_E06C; read by: J1850_mode2C_define_DPID_E06C
ram_v1DFB                                equ $1DFB	; inferred name; written by: calc_DPID_record_ptr_D9B3; read by: calc_DPID_record_ptr_D9B3
search_key_PID                           equ $1DFD	; analysis: 16-bit key (requested PID) for binary_search_records; scratch word for current service (PID / record id)
search_result_ptr                        equ $1DFF	; analysis: address of record found by binary search
search_lo                                equ $1E01	; analysis: binary search low index
search_hi                                equ $1E03	; analysis: binary search high index
search_mid                               equ $1E05	; analysis: binary search mid index (result index)
DTC_select_bitmap                        equ $1E07	; analysis: 15 bytes $1E07-$1E15, DTCs selected for read-by-status
DTC_status_req_mask                      equ $1E16	; analysis: requested status mask, shifted bit by bit
DPID_definitions                         equ $1E20	; analysis: 14 x 19-byte dynamic PID definitions for DPID $F0-$FD; high nibble of byte 0 = schedule; 15 x 19-byte DPID records for DPID F0-FE
DPID_work_record                         equ $1F3D	; analysis: 19-byte work copy of a DPID definition ($1F3D-$1F4F); byte0.b0 = defined
DPID_schedule_list                       equ $1F50	; analysis: 8 bytes, 2 groups of 4 scheduled DPIDs
DPID_group_offset                        equ $1F58	; analysis: 0 or 4; index into 1F50 list; 1F59 period reload, 1F5A countdown, 1F6C count
DPID_rate_divider                        equ $1F59	; analysis: 8/4/2 for rate 2/3/4, 0 = stopped
serial_v1F5A                             equ $1F5A	; analysis: set 2 when scheduling starts, 0 when stopped | inferred name; written by: J1850_mode2A_request_DPID_DED0, calc_DPID_rate_divider_DF56, J1850_diag_session_timer_EE4C, b1_sub_F5CE +1; read ...
ram_v1F60                                equ $1F60	; inferred name; written by: DPID_build_response_ED3F; read by: -
DPID_entry_ptr                           equ $1F61	; analysis: pointer to current 3-byte DPID entry
DPID_bytes_filled                        equ $1F65	; analysis: data bytes placed in DPID response (max 6)
ram_v1F66                                equ $1F66	; inferred name; written by: DPID_build_response_ED3F, calc_DPID_bytes_filled_EDBD; read by: -
ram_v1F67                                equ $1F67	; inferred name; written by: DPID_build_response_ED3F, calc_DPID_bytes_filled_EDBD; read by: -
serial_v1F68                             equ $1F68	; analysis: 1F68/1F69 copy of reply header bytes for periodic packets | inferred name; written by: J1850_mode2A_request_DPID_DED0, calc_DPID_rate_divider_DF56; read by: b1_sub_F5FC
serial_v1F69                             equ $1F69	; inferred name; written by: J1850_mode2A_request_DPID_DED0, calc_DPID_rate_divider_DF56; read by: b1_sub_F5FC
serial_v1F6A                             equ $1F6A	; analysis: DPID being processed / offending DPID in error reply | inferred name; written by: J1850_mode2A_request_DPID_DED0, calc_DPID_rate_divider_DF56; read by: -
serial_v1F6C                             equ $1F6C	; analysis: set to 8, or (rate&F)+7 for rate > F0 | inferred name; written by: J1850_mode2A_request_DPID_DED0, calc_DPID_rate_divider_DF56, J1850_diag_session_timer_EE4C; read by: calc_DPID_rate_divi...
security_flags                           equ $1F6F	; analysis: b0 = seed sent awaiting key, b7 = security unlocked; b7 = unlocked/programming allowed ($34/$36)
security_lockout_timer                   equ $1F70	; analysis: loaded with k_32A2 after too many bad keys
security_bad_key_count                   equ $1F72	; analysis: wrong key attempts
serial_v1F75                             equ $1F75	; analysis: loaded with k_329F after DLC reset, clears $8E.5 on expiry | inferred name; written by: calc_J1850_DLC_cmd_C8DD, J1850_diag_session_timer_EE4C; read by: J1850_diag_session_timer_EE4C
download_checksum                        equ $1F76	; analysis: 16-bit checksum for the mode $36 download; $1F78 = remaining length, $1F7A = target address
ram_v1F77                                equ $1F77	; inferred name; written by: add_A_to_download_checksum_CBA1; read by: add_A_to_download_checksum_CBA1
serial_v1F78                             equ $1F78	; inferred name; written by: J1850_mode36_download_execute_CA64; read by: J1850_mode36_download_execute_CA64
serial_v1F7A                             equ $1F7A	; inferred name; written by: J1850_mode36_download_execute_CA64; read by: J1850_mode36_download_execute_CA64
serial_v1F7C                             equ $1F7C	; analysis: snapshot of $0C02 status in b1:CBB0 | inferred name; written by: J1850_mode36_download_execute_part_CBB0; read by: J1850_mode36_download_execute_part_CBB0
diag_session_timer                       equ $1F7D	; analysis: tester-present timeout counter; 0 -> return to normal mode; tester-present/diagnostic session timeout, loaded with k_32A0
TDC_learn_test_result                    equ $1F7E	; analysis: mode $AE result/failure code (word); nonzero while device control active; $FFFF = none to report; scan-tool reply code $3F01/$3F02/$3F03; word reply/rejection code for serial device contr...
diag_tester_addr                         equ $1F81	; analysis: source address ($F0-$FD) of the last accepted diag request
antitheft_delay_tmr                      equ $1F82	; analysis: 50ms countdown, loaded from k_3421
eeprom_v1F83                             equ $1F83	; inferred name; written by: calc_EEPROM_shadow_8EF6, ignition_off_powerdown_F615; read by: calc_EEPROM_shadow_8EC1, calc_EEPROM_shadow_8EF6
fuel_v1F84                               equ $1F84	; inferred name; written by: ignition_off_powerdown_F615; read by: calc_EEPROM_shadow_8E44
fuel_v1F85                               equ $1F85	; inferred name; written by: ignition_off_powerdown_F615; read by: calc_antitheft_state_8E71
fuel_v1F86                               equ $1F86	; inferred name; written by: COP_clock_fail_entry_6119, RESET_entry, calc_antitheft_delay_tmr_8DA8, ignition_off_powerdown_F615; read by: calc_antitheft_delay_tmr_8DA8
fuel_v1F87                               equ $1F87	; inferred name; written by: calc_antitheft_delay_tmr_8DA8, ignition_off_powerdown_F615; read by: calc_antitheft_delay_tmr_8DA8
antitheft_state                          equ $1F88	; analysis: state index 0-14 for ptrtab_901D
antitheft_status                         equ $1F89	; analysis: packed status bits sent via diag_test_run
egr_scratch_debug                        equ $1F8F	; analysis: scratch: intermediate results written repeatedly (debug/watch byte/word)
egr_v1F91                                equ $1F91	; inferred name; written by: calc_EGR_desired_vac_MAF_70DF; read by: calc_EGR_desired_vac_MAF_70DF
egr_v1F93                                equ $1F93	; inferred name; written by: calc_EGR_desired_vac_MAF_70DF; read by: calc_EGR_desired_vac_MAF_70DF
egr_rpm_axis                             equ $1F95	; analysis: RPM column index 0..255 for 17x17 desired-air table
egr_v1F96                                equ $1F96	; analysis: row index for 17x17 table and learn load bands, written in bank1 AD18 (EGR map area) | inferred name; written by: EGR_map_lookup; read by: calc_EGR_desired_vac_MAF_70DF
egr_baro_rpm_mult                        equ $1F99	; analysis: from 3x9 table 4FA9, $80=1.0
egr_IAT_mult                             equ $1F9A	; analysis: from t2d_4FC5
egr_over_vss_timer                       equ $1F9B	; analysis: counts calls above CAL_EGR_MAX_VSPEED
egr_desired_air                          equ $1F9C	; analysis: desired air per rev
MAF_flow_filtered                        equ $1F9D	; analysis: word, final filtered MAF flow
egr_air_error                            equ $1F9F	; analysis: signed desired - measured air
egr_air_trim                             equ $1FA0	; analysis: signed P trim added to EGR vac target
EGR_desired_vac_final                    equ $1FA1	; analysis: final desired EGR vacuum (0.5 kPa), compared with MEASURED_EGR_VAC by EGR_control
egr_corr_rpm_axis                        equ $1FA4	; analysis: row axis for 4FA9
egr_corr_baro_axis                       equ $1FA5	; analysis: column axis for 4FA9
MAF_time_latch                           equ $1FA6	; analysis: last MAF pulse time; 1FA8 previous
egr_v1FA8                                equ $1FA8	; inferred name; written by: MAF_read_counters; read by: MAF_read_counters
MAF_delta_time                           equ $1FAA
MAF_count_latch                          equ $1FAC	; analysis: pulse counter; 1FAE previous
egr_v1FAE                                equ $1FAE	; inferred name; written by: MAF_read_counters; read by: MAF_read_counters
MAF_delta_pulses                         equ $1FB0
MAF_freq_raw                             equ $1FB2
MAF_freq_filtered                        equ $1FB4
egr_measured_air_filt                    equ $1FB6	; analysis: word lag filter, high byte = measured air per rev
egr_abs_error_filt                       equ $1FB8
egr_v1FBA                                equ $1FBA	; inferred name; written by: EGR_control; read by: calc_ff_next_slot_FA02
