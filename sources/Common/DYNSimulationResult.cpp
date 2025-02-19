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
 * @file  SimulationResult.cpp
 *
 * @brief Simulation result: implementation file
 *
 */

#include <iostream>
#include "DYNSimulationResult.h"

namespace DYNAlgorithms {

SimulationResult::SimulationResult():
    success_(false),
    status_(EXECUTION_PROBLEM_STATUS) {
}

SimulationResult::~SimulationResult() {
}

SimulationResult::SimulationResult(const SimulationResult& result):
    scenarioId_(result.scenarioId_),
    variation_(result.variation_),
    success_(result.success_),
    status_(result.status_),
    failingCriteria_(result.failingCriteria_) {
  timelineStream_ << result.timelineStream_.str();
  constraintsStream_ << result.constraintsStream_.str();
}

SimulationResult&
SimulationResult::operator=(const SimulationResult& result) {
  if (this == &result) return *this;
  scenarioId_ = result.scenarioId_;
  variation_ = result.variation_;
  success_ = result.success_;
  status_ = result.status_;
  timelineStream_ << result.timelineStream_.str();
  constraintsStream_ << result.constraintsStream_.str();
  failingCriteria_ = result.failingCriteria_;
  return *this;
}

void
SimulationResult::setScenarioId(const std::string& id) {
  scenarioId_ = id;
}


void
SimulationResult::setVariation(const std::string& variation) {
  variation_ = variation;
}

void
SimulationResult::setSuccess(const bool success) {
  success_ = success;
}

void
SimulationResult::setStatus(status_t status) {
  status_ = status;
}

std::stringstream&
SimulationResult::getTimelineStream() {
  return timelineStream_;
}

std::string
SimulationResult::getTimelineStreamStr() const {
  return timelineStream_.str();
}

std::stringstream&
SimulationResult::getConstraintsStream() {
  return constraintsStream_;
}

std::string
SimulationResult::getConstraintsStreamStr() const {
  return constraintsStream_.str();
}

std::string
SimulationResult::getScenarioId() const {
  return scenarioId_;
}


std::string
SimulationResult::getUniqueScenarioId() const {
  if (!variation_.empty())
    return scenarioId_ + "-"+variation_;
  return scenarioId_;
}

bool
SimulationResult::getSuccess() const {
  return success_;
}

status_t
SimulationResult::getStatus() const {
  return status_;
}

const std::vector<std::pair<double, std::string> >&
SimulationResult::getFailingCriteria() const {
  return failingCriteria_;
}

void
SimulationResult::setFailingCriteria(const std::vector<std::pair<double, std::string> >& failingCriteria) {
  failingCriteria_ = failingCriteria;
}
}  // namespace DYNAlgorithms
