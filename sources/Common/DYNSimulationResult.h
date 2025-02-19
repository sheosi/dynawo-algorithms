//
// Copyright (c) 2015-2021, RTE (http://www.rte-france.com)
// See AUTHORS.txt
// All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, you can obtain one at http://mozilla.org/MPL/2.0/.
// SPDX-License-Identifier: MPL-2.0
//
// This file is part of Dynawo, an hybrid C++/Modelica open source suite
// of simulation tools for power systems.
//

/**
 * @file  DYNSimulationResult.h
 *
 * @brief Simulation result : header file
 *
 */
#ifndef COMMON_DYNSIMULATIONRESULT_H_
#define COMMON_DYNSIMULATIONRESULT_H_

#include <string>
#include <sstream>
#include <vector>
#include <boost/shared_ptr.hpp>

#include "DYNResultCommon.h"

namespace DYNAlgorithms {

/**
 * @brief Simulation result class
 *
 * Class for the description of a simulation result
 */
class SimulationResult {
 public:
  /**
   * @brief default constructor
   */
  SimulationResult();

  /**
   * @brief default destructor
   */
  ~SimulationResult();

  /**
   * @brief copy constructor
   * @param result : result to copy
   */
  SimulationResult(const SimulationResult& result);

  /**
   * @brief copy operator
   * @param result result to copy
   * @return new instance of simulationResult
   */
  SimulationResult& operator=(const SimulationResult& result);

  /**
   * @brief set the id of the scenario
   * @param id id of the scenario
   */
  void setScenarioId(const std::string& id);

  /**
   * @brief set the variation of the scenario
   * @param variation variation of the scenario
   */
  void setVariation(const std::string& variation);

  /**
   * @brief set whether the simulation succeed or not
   * @param success @b true if the simulation succeed, @b false otherwise
   */
  void setSuccess(const bool success);

  /**
   * @brief set the detailed output status of the simulation
   * @param status detailed output status of the simulation
   */
  void setStatus(status_t status);

  /**
   * @brief getter of the timeline stream associated to the scenario
   * @return timeline stream associated to the scenario
   */
  std::stringstream& getTimelineStream();

  /**
   * @brief getter of the timeline associated to the scenario
   * @return timeline associated to the scenario
   */
  std::string getTimelineStreamStr() const;

  /**
   * @brief getter of the constraints stream associated to the scenario
   * @return constraints stream associated to the scenario
   */
  std::stringstream& getConstraintsStream();

  /**
   * @brief getter of the constraints associated to the scenario
   * @return constraints associated to the scenario
   */
  std::string getConstraintsStreamStr() const;

  /**
   * @brief getter of the scenario id associated to the simulation
   * @return the scenario id associated to the simulation
   */
  std::string getScenarioId() const;

  /**
   * @brief generate a unique scenario id associating the scenario id and the variation
   * @return unique scenario id associated to the simulation
   */
  std::string getUniqueScenarioId() const;

  /**
   * @brief getter of the indicator of success of the simulation
   * @return indicator of success of the simulation
   */
  bool getSuccess() const;

  /**
   * @brief getter of the detailed output status of the simulation
   * @return detailed output status of the simulation
   */
  status_t getStatus() const;

  /**
   * @brief getter of the failing criteria ids
   * @return failing criteria ids
   */
  const std::vector<std::pair<double, std::string> >& getFailingCriteria() const;

  /**
   * @brief setter of the failing criteria ids
   * @param failingCriteria new failing criteria ids
   */
  void setFailingCriteria(const std::vector<std::pair<double, std::string> >& failingCriteria);

 private:
  std::stringstream timelineStream_;  ///< stream for the timeline associated to the scenario
  std::stringstream constraintsStream_;  ///< stream for the constraints associated to the scenario
  std::string scenarioId_;  ///< id of the scenario
  std::string variation_;  ///< variation of the scenario (used when associated to a load increase)
  bool success_;  ///< @b true if the simulation reached its end, @b false otherwise
  status_t status_;  ///< detailed output status of the simulation
  std::vector<std::pair<double, std::string> > failingCriteria_;  ///< failing criteria ids
};

}  // namespace DYNAlgorithms

#endif  // COMMON_DYNSIMULATIONRESULT_H_
