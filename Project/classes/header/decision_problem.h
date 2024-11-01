#ifndef DECISION_PROBLEM_H
#define DECISION_PROBLEM_H

#include "free_space.h"

class DecisionProblem {
 public:
  // Constructor to initialize with two polygonal curves and epsilon
  DecisionProblem(const PolygonalCurve& P, const PolygonalCurve& Q,
                  double epsilon);

  // Getter
  bool doesMonotoneCurveExist() const;
  const PolygonalCurve& getCurveP() const;
  const PolygonalCurve& getCurveQ() const;
  double getEpsilon() const;
  // Setter
  void setEpsilon(double newEpsilon);

  // Function to check if a monotone curve exists
  void checkMonotoneCurve();

 private:
  PolygonalCurve P;     // Polygonal curve P
  PolygonalCurve Q;     // Polygonal curve Q
  double epsilon;       // Epsilon value
  FreeSpace freeSpace;  // FreeSpace object
  PointPairVector L_R;  // Reachable L
  PointPairVector B_R;  // Reachable B

  bool monotoneCurveExists;  // True if a monotone curve exists, false otherwise

  // Helper functions for checking the conditions
  bool checkStartAndEndConditions();
  bool checkIfMonotoneCurveExists();
};

#endif  // DECISION_PROBLEM_H
