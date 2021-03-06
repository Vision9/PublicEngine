/*
 * Segment.h
 *
 *  Created on: 11/03/2011
 *      Author: victor
 */

#ifndef SEGMENT_H_
#define SEGMENT_H_

#include "Vector3.h"

namespace engine {
 namespace util {
  namespace u3d {

  class Segment : public Variable {
  protected:
	  Vector3 pointA, pointB;

  public:

	  Segment();
	  Segment(const Vector3& pointA, const Vector3& pointB);
	  Segment(const Segment& s);

	  Segment& operator=(const Segment& s);

	  bool toBinaryStream(ObjectOutputStream* stream) {
		  pointA.toBinaryStream(stream);
		  pointB.toBinaryStream(stream);

		  return true;
	  }

	  bool parseFromBinaryStream(ObjectInputStream* stream) {
		  pointA.parseFromBinaryStream(stream);
		  pointB.parseFromBinaryStream(stream);

		  return true;
	  }

	  /**
	   * returns closest point on the segment to point
	   */
	  Vector3 getClosestPointTo(const Vector3& point) const;

	  static Vector3 getClosestPoint(const Vector3& segmentA, const Vector3& segmentB, const Vector3& point);
  };

  }
 }
}

using namespace engine::util::u3d;


#endif /* SEGMENT_H_ */
