# Auto generated configuration file
# using: 
# Revision: 1.19 
# Source: /local/reps/CMSSW/CMSSW/Configuration/Applications/python/ConfigBuilder.py,v 
# with command line options: step3 --conditions auto:phase2_realistic -n 10 --era Phase2C8_timing --eventcontent DQM --runUnscheduled -s RAW2DIGI,RECO,VALIDATION:@trackingValidation,DQM:@trackingOnlyDQM --datatier DQMIO --geometry Extended2023D41 --filein file:step2.root --fileout file:step3_inDQM.root --mc --no_exec
import FWCore.ParameterSet.Config as cms

from Configuration.Eras.Era_Phase2C8_timing_cff import Phase2C8_timing

process = cms.Process('RECO',Phase2C8_timing)
#process = cms.Process('PERFORMANCE',Phase2C8_timing)




# import of standard configurations
process.load('extras')
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('SimGeneral.MixingModule.mixNoPU_cfi')
process.load('Configuration.Geometry.GeometryExtended2023D41Reco_cff')
process.load('Configuration.StandardSequences.MagneticField_cff')
#process.load('Configuration.StandardSequences.RawToDigi_cff')
#process.load('Configuration.StandardSequences.Reconstruction_cff')
#process.load('Configuration.StandardSequences.Validation_cff')
#process.load('DQMServices.Core.DQMStoreNonLegacy_cff')
#process.load('DQMOffline.Configuration.DQMOfflineMC_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(10)
)

"""
# Input source
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring('file:step2.root'),
    secondaryFileNames = cms.untracked.vstring()
)
"""
process.load("input_TTbar_PhaseIITDRSpring19DR-NoPU_106X_upgrade2023_realistic_v3_cff")



process.options = cms.untracked.PSet(

)

# Production Info
process.configurationMetadata = cms.untracked.PSet(
    annotation = cms.untracked.string('step3 nevts:10'),
    name = cms.untracked.string('Applications'),
    version = cms.untracked.string('$Revision: 1.19 $')
)

# Output definition

process.DQMoutput = cms.OutputModule("DQMRootOutputModule",
    dataset = cms.untracked.PSet(
        dataTier = cms.untracked.string('GEN-SIM-DIGI-RAW'), #GEN-SIM-DIGI-RAW
        filterName = cms.untracked.string('')
    ),
    fileName = cms.untracked.string('file:step3_inDQM.root'),
    outputCommands = process.DQMEventContent.outputCommands,
    splitLevel = cms.untracked.int32(0)
)

# Additional output definition

############################ load modules and paths


#process.load("MC_Tracking_v0_cmssw_10_6_cff")
#process.load("MC_prevalidation_v0_cmssw_10_6_cff")

# Other statements
process.mix.playback = True
process.mix.digitizers = cms.PSet()
for a in process.aliases: delattr(process, a)
process.RandomNumberGeneratorService.restoreStateLabel=cms.untracked.string("randomEngineStateProducer")
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, 'auto:phase2_realistic', '')

# Path and EndPath definitions
"""
process.raw2digi_step = cms.Path(process.RawToDigi)
process.prevalidation_step = cms.Path(process.globalPrevalidationTracking)
process.validation_step = cms.EndPath(process.globalValidationTrackingOnly)
process.dqmoffline_step = cms.EndPath(process.DQMOfflineTracking)
process.dqmofflineOnPAT_step = cms.EndPath(process.PostDQMOffline)
"""

process.load('raw2digi_step_cff')
process.load("MC_Tracking_v1_cmssw_10_6_cff")
process.DQMoutput_step = cms.EndPath(process.DQMoutput)
process.load('MC_prevalidation_v1_cmssw_10_6_cff')  
process.load('MC_Dqmoffline_v1_cff') 


# Schedule definition
process.schedule = cms.Schedule(process.raw2digi_step,process.MC_Tracking_v1,process.MC_prevalidation_v1, process.MC_Dqmoffline_v1,process.DQMoutput_step)
from PhysicsTools.PatAlgos.tools.helpers import associatePatAlgosToolsTask
associatePatAlgosToolsTask(process)

# customisation of the process.

# Automatic addition of the customisation function from SimGeneral.MixingModule.fullMixCustomize_cff
from SimGeneral.MixingModule.fullMixCustomize_cff import setCrossingFrameOn 

#call to customisation function setCrossingFrameOn imported from SimGeneral.MixingModule.fullMixCustomize_cff
process = setCrossingFrameOn(process)

# End of customisation functions
#do not add changes to your config after this point (unless you know what you are doing)
#from FWCore.ParameterSet.Utilities import convertToUnscheduled
#process=convertToUnscheduled(process)


# Customisation from command line

#Have logErrorHarvester wait for the same EDProducers to finish as those providing data for the OutputModule
from FWCore.Modules.logErrorHarvester_cff import customiseLogErrorHarvesterUsingOutputCommands
process = customiseLogErrorHarvesterUsingOutputCommands(process)

# Add early deletion of temporary data products to reduce peak memory need
from Configuration.StandardSequences.earlyDeleteSettings_cff import customiseEarlyDelete
process = customiseEarlyDelete(process)

# End adding early deletion
