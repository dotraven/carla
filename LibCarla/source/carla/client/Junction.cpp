// Copyright (c) 2017 Computer Vision Center (CVC) at the Universitat Autonoma
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#include "carla/client/Junction.h"
#include "carla/road/Junction.h"
#include "carla/client/Map.h"
#include "carla/road/element/Waypoint.h"

namespace carla{
namespace client{

Junction::Junction(SharedPtr<const Map> parent, const road::Junction* junction) : _parent(parent){
  _boundingBox = junction->GetBoundingBox();
  _id = junction->GetId();
}

std::vector<std::pair<SharedPtr<Waypoint>, SharedPtr<Waypoint>>> Junction::GetWaypoints() const{
  return _parent->GetJunctionWaypoints(GetId());
}

geom::BoundingBox Junction::GetBoundingBox() const{
  return _boundingBox;
}

} //client
} //carla
