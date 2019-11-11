// Copyright 2018-2019 Delft University of Technology
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "dag/dag.h"

#pragma once

namespace dag {

/// @brief Cumulatively count the number of elements passed through.
Graph IndexOf(const ListRef& list_type, const PrimRef &index_type = idx32());

/// @brief Transform a list of booleans into a list of indices for which the booleans are true.
Graph IndexIfTrue(const PrimRef &index_type = idx32());

/// @brief Select elements from a list of t's by index.
Graph SelectByIndex(const TypeRef &t, const PrimRef &index_type = idx32());

}  // namespace dag