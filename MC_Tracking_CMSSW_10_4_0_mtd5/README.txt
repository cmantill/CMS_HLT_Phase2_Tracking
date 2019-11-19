

Version 1) Cleaned up from the release generated script
###########
step3_performance_modular.py 			#performance studies
needs:

- input_TTbar_PhaseIIMTDTDRAutumn18DR-noPU_103X_upgrade2023_realistic_v2-v1_cff.py
- input_TTbar_PhaseIIMTDTDRAutumn18DR-PU200_103X_upgrade2023_realistic_v2-v1_cff.py
- raw2digi_step_cff.py
- MC_Tracking_v0_cff.py / MC_Tracking_v1_cff.py / MC_Tracking_v2_cff.py
- MC_prevalidation_v0_cff.py / MC_prevalidation_v1_cff.py / MC_prevalidation_v2_cff.py (all cleaned)
- MC_Dqmoffline_step_v0_cff.py / MC_Dqmoffline_step_v1_cff.py / MC_Dqmoffline_step_v2_cff.py

############
step3_timing_modular.py 			#timing studies

needs:
- input_TTbar_PhaseIIMTDTDRAutumn18DR-noPU_103X_upgrade2023_realistic_v2-v1_cff.py (input sample list)
- input_TTbar_PhaseIIMTDTDRAutumn18DR-PU200_103X_upgrade2023_realistic_v2-v1_cff.py
- raw2digi_step_cff.py
- MC_Tracking_v0_cff.py / MC_Tracking_v1_cff.py / MC_Tracking_v2_cff.py





Version 2) Release generated script with new paths plugged in
############
step3_RAW2DIGI_RECO_VALIDATION_DQM.py

needs:
- input_TTbar_PhaseIIMTDTDRAutumn18DR-noPU_103X_upgrade2023_realistic_v2-v1_cff.py (input sample list) or step2.root
- input_TTbar_PhaseIIMTDTDRAutumn18DR-PU200_103X_upgrade2023_realistic_v2-v1_cff.py
- extras.py (extra modules from step3_performance_modular.py)
- raw2digi_step_cff.py
- MC_Tracking_v0_cff.py / MC_Tracking_v1_cff.py / MC_Tracking_v2_cff.py
- MC_prevalidation_v0_cff.py / MC_prevalidation_v1_cff.py / MC_prevalidation_v2_cff.py (all cleaned)
- MC_Dqmoffline_step_v0_cff.py / MC_Dqmoffline_step_v1_cff.py / MC_Dqmoffline_step_v2_cff.py
