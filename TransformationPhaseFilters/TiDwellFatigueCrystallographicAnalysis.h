/* ============================================================================
 * Copyright (c) 2011 Michael A. Jackson (BlueQuartz Software)
 * Copyright (c) 2011 Dr. Michael A. Groeber (US Air Force Research Laboratories)
 * Copyright (c) 2014 Dr. Joseph C. Tucker (UES, Inc.)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice, this
 * list of conditions and the following disclaimer in the documentation and/or
 * other materials provided with the distribution.
 *
 * Neither the name of Joseph C. Tucker, Michael A. Groeber, Michael A. Jackson,
 * UES, Inc., the US Air Force, BlueQuartz Software nor the names of its contributors
 * may be used to endorse or promote products derived from this software without
 * specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *  This code was written under United States Air Force Contract number
 *                   FA8650-07-D-5800 and FA8650-10-D-5226
 *
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#pragma once

#include <QtCore/QString>

#include "SIMPLib/Common/SIMPLibSetGetMacros.h"
#include "SIMPLib/Common/SIMPLibSetGetMacros.h"
#include "SIMPLib/DataArrays/IDataArray.h"
#include "SIMPLib/DataArrays/IDataArray.h"
#include "SIMPLib/DataArrays/NeighborList.hpp"
#include "SIMPLib/DataContainers/DataContainer.h"
#include "SIMPLib/FilterParameters/FloatVec3FilterParameter.h"
#include "SIMPLib/Filtering/AbstractFilter.h"
#include "SIMPLib/SIMPLib.h"
#include "SIMPLib/SIMPLib.h"

#include "TransformationPhase/TransformationPhaseDLLExport.h"

/**
 * @class TiDwellFatigueCrystallographicAnalysis TiDwellFatigueCrystallographicAnalysis.h /TransformationPhase/TiDwellFatigueCrystallographicAnalysis.h
 * @brief
 * @author Joseph C. Tucker
 * @date Jan 23, 2015
 * @version 5.1
 */
class TransformationPhase_EXPORT TiDwellFatigueCrystallographicAnalysis : public AbstractFilter
{
    Q_OBJECT
  public:
    SIMPL_SHARED_POINTERS(TiDwellFatigueCrystallographicAnalysis)
    SIMPL_FILTER_NEW_MACRO(TiDwellFatigueCrystallographicAnalysis)
    SIMPL_TYPE_MACRO_SUPER_OVERRIDE(TiDwellFatigueCrystallographicAnalysis, AbstractFilter)

    ~TiDwellFatigueCrystallographicAnalysis() override;
    SIMPL_FILTER_PARAMETER(QString, DataContainerName)
    Q_PROPERTY(QString DataContainerName READ getDataContainerName WRITE setDataContainerName)

    /* Place your input parameters here. You can use some of the DREAM3D Macros if you want to */
    SIMPL_FILTER_PARAMETER(bool, AlphaGlobPhasePresent)
    Q_PROPERTY(bool AlphaGlobPhasePresent READ getAlphaGlobPhasePresent WRITE setAlphaGlobPhasePresent)
    SIMPL_FILTER_PARAMETER(int, AlphaGlobPhase)
    Q_PROPERTY(int AlphaGlobPhase READ getAlphaGlobPhase WRITE setAlphaGlobPhase)
    SIMPL_FILTER_PARAMETER(int, MTRPhase)
    Q_PROPERTY(int MTRPhase READ getMTRPhase WRITE setMTRPhase)
    SIMPL_FILTER_PARAMETER(float, LatticeParameterA)
    Q_PROPERTY(float LatticeParameterA READ getLatticeParameterA WRITE setLatticeParameterA)
    SIMPL_FILTER_PARAMETER(float, LatticeParameterC)
    Q_PROPERTY(float LatticeParameterC READ getLatticeParameterC WRITE setLatticeParameterC)
    SIMPL_FILTER_PARAMETER(FloatVec3_t, StressAxis)
    Q_PROPERTY(FloatVec3_t StressAxis READ getStressAxis WRITE setStressAxis)
    SIMPL_FILTER_PARAMETER(int, SubsurfaceDistance)
    Q_PROPERTY(int SubsurfaceDistance READ getSubsurfaceDistance WRITE setSubsurfaceDistance)
    Q_PROPERTY(float ConsiderationFraction READ getConsiderationFraction WRITE setConsiderationFraction)
    SIMPL_FILTER_PARAMETER(float, ConsiderationFraction)

    SIMPL_FILTER_PARAMETER(bool, DoNotAssumeInitiatorPresence)
    Q_PROPERTY(bool DoNotAssumeInitiatorPresence READ getDoNotAssumeInitiatorPresence WRITE setDoNotAssumeInitiatorPresence)
    SIMPL_FILTER_PARAMETER(float, InitiatorLowerThreshold)
    Q_PROPERTY(float InitiatorLowerThreshold READ getInitiatorLowerThreshold WRITE setInitiatorLowerThreshold)
    SIMPL_FILTER_PARAMETER(float, InitiatorUpperThreshold)
    Q_PROPERTY(float InitiatorUpperThreshold READ getInitiatorUpperThreshold WRITE setInitiatorUpperThreshold)
    SIMPL_FILTER_PARAMETER(float, HardFeatureLowerThreshold)
    Q_PROPERTY(float HardFeatureLowerThreshold READ getHardFeatureLowerThreshold WRITE setHardFeatureLowerThreshold)
    SIMPL_FILTER_PARAMETER(float, HardFeatureUpperThreshold)
    Q_PROPERTY(float HardFeatureUpperThreshold READ getHardFeatureUpperThreshold WRITE setHardFeatureUpperThreshold)
    SIMPL_FILTER_PARAMETER(float, SoftFeatureLowerThreshold)
    Q_PROPERTY(float SoftFeatureLowerThreshold READ getSoftFeatureLowerThreshold WRITE setSoftFeatureLowerThreshold)
    SIMPL_FILTER_PARAMETER(float, SoftFeatureUpperThreshold)
    Q_PROPERTY(float SoftFeatureUpperThreshold READ getSoftFeatureUpperThreshold WRITE setSoftFeatureUpperThreshold)


    SIMPL_FILTER_PARAMETER(QString,NewCellFeatureAttributeMatrixName)
    Q_PROPERTY(QString NewCellFeatureAttributeMatrixName READ getNewCellFeatureAttributeMatrixName WRITE setNewCellFeatureAttributeMatrixName)

    SIMPL_FILTER_PARAMETER(QString, SelectedFeaturesArrayName)
    Q_PROPERTY(QString SelectedFeaturesArrayName READ getSelectedFeaturesArrayName WRITE setSelectedFeaturesArrayName)

    SIMPL_FILTER_PARAMETER(QString, InitiatorsArrayName)
    Q_PROPERTY(QString InitiatorsArrayName READ getInitiatorsArrayName WRITE setInitiatorsArrayName)

    SIMPL_FILTER_PARAMETER(QString, HardFeaturesArrayName)
    Q_PROPERTY(QString HardFeaturesArrayName READ getHardFeaturesArrayName WRITE setHardFeaturesArrayName)

    SIMPL_FILTER_PARAMETER(QString, SoftFeaturesArrayName)
    Q_PROPERTY(QString SoftFeaturesArrayName READ getSoftFeaturesArrayName WRITE setSoftFeaturesArrayName)

    SIMPL_FILTER_PARAMETER(QString, HardSoftGroupsArrayName)
    Q_PROPERTY(QString HardSoftGroupsArrayName READ getHardSoftGroupsArrayName WRITE setHardSoftGroupsArrayName)

    SIMPL_FILTER_PARAMETER(QString, CellFeatureAttributeMatrixName)
    Q_PROPERTY(QString CellFeatureAttributeMatrixName READ getCellFeatureAttributeMatrixName WRITE setCellFeatureAttributeMatrixName)

    SIMPL_FILTER_PARAMETER(DataArrayPath, CellFeatureAttributeMatrixPath)
    Q_PROPERTY(DataArrayPath CellFeatureAttributeMatrixPath READ getCellFeatureAttributeMatrixPath WRITE setCellFeatureAttributeMatrixPath)

    SIMPL_FILTER_PARAMETER(DataArrayPath, FeatureIdsArrayPath)
    Q_PROPERTY(DataArrayPath FeatureIdsArrayPath READ getFeatureIdsArrayPath WRITE setFeatureIdsArrayPath)

    SIMPL_FILTER_PARAMETER(QString, CellParentIdsArrayName)
    Q_PROPERTY(QString CellParentIdsArrayName READ getCellParentIdsArrayName WRITE setCellParentIdsArrayName)

    SIMPL_FILTER_PARAMETER(QString, FeatureParentIdsArrayName)
    Q_PROPERTY(QString FeatureParentIdsArrayName READ getFeatureParentIdsArrayName WRITE setFeatureParentIdsArrayName)

    SIMPL_FILTER_PARAMETER(QString, ActiveArrayName)
    Q_PROPERTY(QString ActiveArrayName READ getActiveArrayName WRITE setActiveArrayName)

    SIMPL_FILTER_PARAMETER(DataArrayPath, FeatureEulerAnglesArrayPath)
    Q_PROPERTY(DataArrayPath FeatureEulerAnglesArrayPath READ getFeatureEulerAnglesArrayPath WRITE setFeatureEulerAnglesArrayPath)

    SIMPL_FILTER_PARAMETER(DataArrayPath, FeaturePhasesArrayPath)
    Q_PROPERTY(DataArrayPath FeaturePhasesArrayPath READ getFeaturePhasesArrayPath WRITE setFeaturePhasesArrayPath)

    SIMPL_FILTER_PARAMETER(DataArrayPath, NeighborListArrayPath)
    Q_PROPERTY(DataArrayPath NeighborListArrayPath READ getNeighborListArrayPath WRITE setNeighborListArrayPath)

    SIMPL_FILTER_PARAMETER(DataArrayPath, CentroidsArrayPath)
    Q_PROPERTY(DataArrayPath CentroidsArrayPath READ getCentroidsArrayPath WRITE setCentroidsArrayPath)

    SIMPL_FILTER_PARAMETER(DataArrayPath, CrystalStructuresArrayPath)
    Q_PROPERTY(DataArrayPath CrystalStructuresArrayPath READ getCrystalStructuresArrayPath WRITE setCrystalStructuresArrayPath)

    /**
     * @brief getCompiledLibraryName Reimplemented from @see AbstractFilter class
     */
    const QString getCompiledLibraryName() const override;

    /**
     * @brief getBrandingString Returns the branding string for the filter, which is a tag
     * used to denote the filter's association with specific plugins
     * @return Branding string
    */
    const QString getBrandingString() const override;

    /**
     * @brief getFilterVersion Returns a version string for this filter. Default
     * value is an empty string.
     * @return
     */
    const QString getFilterVersion() const override;

    /**
     * @brief newFilterInstance Reimplemented from @see AbstractFilter class
     */
    AbstractFilter::Pointer newFilterInstance(bool copyFilterParameters) const override;

    /**
     * @brief getGroupName Reimplemented from @see AbstractFilter class
     */
    const QString getGroupName() const override;

    /**
     * @brief getSubGroupName Reimplemented from @see AbstractFilter class
     */
    const QString getSubGroupName() const override;

    /**
     * @brief getUuid Return the unique identifier for this filter.
     * @return A QUuid object.
     */
    const QUuid getUuid() override;

    /**
     * @brief getHumanLabel Reimplemented from @see AbstractFilter class
     */
    const QString getHumanLabel() const override;

    /**
     * @brief setupFilterParameters Reimplemented from @see AbstractFilter class
     */
    void setupFilterParameters() override;

    /**
     * @brief readFilterParameters Reimplemented from @see AbstractFilter class
     */
    void readFilterParameters(AbstractFilterParametersReader* reader, int index) override;

    /**
    * @brief readFilterParametersFromJson Reads the filter parameters from a file
    * @param reader Reader that is used to read the parameters from a file
    */
    void readFilterParameters(QJsonObject &obj) override;

    /**
    * @brief writeFilterParametersToJson Writes the filter parameters to a file
    * @param root The root json object
    */
    void writeFilterParameters(QJsonObject &obj) const override;

    /**
     * @brief execute Reimplemented from @see AbstractFilter class
     */
    void execute() override;

    /**
    * @brief preflight Reimplemented from @see AbstractFilter class
    */
    void preflight() override;

  Q_SIGNALS:
    void updateFilterParameters(AbstractFilter* filter);
    void parametersChanged();
    void preflightAboutToExecute();
    void preflightExecuted();

  protected:
    TiDwellFatigueCrystallographicAnalysis();

    bool determine_subsurfacefeatures(int index);
    bool determine_hardfeatures(int index);
    void determine_initiators(int index);
    void determine_softfeatures(int index);
    void group_flaggedfeatures(int index);
    void assign_HardSoftGroups(int index);
    float find_angle(float g[3][3], float planeNormalU, float planeNormalV, float planeNormalW);

    /**
     * @brief dataCheck Checks for the appropriate parameter values and availability of arrays
     */
    void dataCheck();

    /**
     * @brief Initializes all the private instance variables.
     */
    void initialize();

    void updateFeatureInstancePointers();

  private:
    DEFINE_DATAARRAY_VARIABLE(bool, SelectedFeatures)
    DEFINE_DATAARRAY_VARIABLE(bool, Initiators)
    DEFINE_DATAARRAY_VARIABLE(bool, HardFeatures)
    DEFINE_DATAARRAY_VARIABLE(bool, SoftFeatures)
    DEFINE_DATAARRAY_VARIABLE(bool, HardSoftGroups)

    // Feature Data - make sure these are all initialized to nullptr in the constructor
    DEFINE_DATAARRAY_VARIABLE(int32_t, FeatureIds)
    DEFINE_DATAARRAY_VARIABLE(int32_t, CellParentIds)
    DEFINE_DATAARRAY_VARIABLE(int32_t, FeatureParentIds)
    DEFINE_DATAARRAY_VARIABLE(bool, Active)
    DEFINE_DATAARRAY_VARIABLE(float, FeatureEulerAngles)
    DEFINE_DATAARRAY_VARIABLE(int32_t, FeaturePhases)
    NeighborList<int>::WeakPointer m_NeighborList;
    NeighborList<int>::WeakPointer m_ParentNeighborList;
    DEFINE_DATAARRAY_VARIABLE(float, Centroids)

    // Ensemble Data - make sure these are all initialized to nullptr in the constructor
    DEFINE_DATAARRAY_VARIABLE(uint32_t, CrystalStructures)

  public:
    TiDwellFatigueCrystallographicAnalysis(const TiDwellFatigueCrystallographicAnalysis&) = delete; // Copy Constructor Not Implemented
    TiDwellFatigueCrystallographicAnalysis(TiDwellFatigueCrystallographicAnalysis&&) = delete;      // Move Constructor Not Implemented
    TiDwellFatigueCrystallographicAnalysis& operator=(const TiDwellFatigueCrystallographicAnalysis&) = delete; // Copy Assignment Not Implemented
    TiDwellFatigueCrystallographicAnalysis& operator=(TiDwellFatigueCrystallographicAnalysis&&) = delete;      // Move Assignment Not Implemented
};



