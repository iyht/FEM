 
 #include <mass_matrix_linear_tetrahedron.h>

 void mass_matrix_linear_tetrahedron(Eigen::Matrix1212d &M, Eigen::Ref<const Eigen::VectorXd> qdot, Eigen::Ref<const Eigen::RowVectorXi> element, double density, double volume) {


     M.setZero();
     double mass = density*volume;
     double c = (1.0/10.0)*mass;


     M.block(0,0, 3,3) = c*Eigen::Matrix<double,3,3>::Identity();
     M.block(0,3, 3,3) = c*Eigen::Matrix<double,3,3>::Identity();
     M.block(0,6, 3,3) = c*Eigen::Matrix<double,3,3>::Identity();
     M.block(0,9, 3,3) = c*Eigen::Matrix<double,3,3>::Identity();

     M.block(3,0, 3,3) = c*Eigen::Matrix<double,3,3>::Identity();
     M.block(3,3, 3,3) = c*Eigen::Matrix<double,3,3>::Identity();
     M.block(3,6, 3,3) = c*Eigen::Matrix<double,3,3>::Identity();
     M.block(3,9, 3,3) = c*Eigen::Matrix<double,3,3>::Identity();

     M.block(6,0, 3,3) = c*Eigen::Matrix<double,3,3>::Identity();
     M.block(6,3, 3,3) = c*Eigen::Matrix<double,3,3>::Identity();
     M.block(6,6, 3,3) = c*Eigen::Matrix<double,3,3>::Identity();
     M.block(6,9, 3,3) = c*Eigen::Matrix<double,3,3>::Identity();

     M.block(9,0, 3,3) = c*Eigen::Matrix<double,3,3>::Identity();
     M.block(9,3, 3,3) = c*Eigen::Matrix<double,3,3>::Identity();
     M.block(9,6, 3,3) = c*Eigen::Matrix<double,3,3>::Identity();
     M.block(9,9, 3,3) = c*Eigen::Matrix<double,3,3>::Identity();
 }