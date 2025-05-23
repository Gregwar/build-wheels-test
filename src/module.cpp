#include <pinocchio/fwd.hpp>

#include <Eigen/Dense>
#include <boost/python.hpp>
#include <boost/python/implicit.hpp>
#include <boost/python/numpy.hpp>
#include <eigenpy/eigen-to-python.hpp>
#include <eigenpy/eigenpy.hpp>
#include <ostream>
#include <pinocchio/bindings/python/spatial/se3.hpp>

Eigen::Matrix3d invert_matrix(const Eigen::Matrix3d &m) { return m.inverse(); }

using namespace boost::python;

BOOST_PYTHON_MODULE(build_wheel_test) {
  using namespace boost::python;

  eigenpy::enableEigenPy();

  def("invert_matrix", &invert_matrix, "Invert a 3x3 matrix");
}