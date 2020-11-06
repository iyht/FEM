 
 #include <mass_matrix_linear_tetrahedron.h>

 void mass_matrix_linear_tetrahedron(Eigen::Matrix1212d &M, Eigen::Ref<const Eigen::VectorXd> qdot, Eigen::Ref<const Eigen::RowVectorXi> element, double density, double volume) {


    M.setZero();
     double mass = density*volume;
     double c0 = (1.0/10.0)*mass;
     double c1 = (1.0/20.0)*mass;

     //m_massMatrix
     //Point Indices
     unsigned int p0 = 0;
     unsigned int p1 = 3;
     unsigned int p2 = 6;
     unsigned int p3 = 9;

     //Assemble these bad boys //really big 4x4 block matrix
     M.block(p0,p0, 3,3) = c0*Eigen::Matrix<double,3,3>::Identity();
     M.block(p0,p1, 3,3) = c1*Eigen::Matrix<double,3,3>::Identity();
     M.block(p0,p2, 3,3) = c1*Eigen::Matrix<double,3,3>::Identity();
     M.block(p0,p3, 3,3) = c1*Eigen::Matrix<double,3,3>::Identity();

     M.block(p1,p0, 3,3) = c1*Eigen::Matrix<double,3,3>::Identity();
     M.block(p1,p1, 3,3) = c0*Eigen::Matrix<double,3,3>::Identity();
     M.block(p1,p2, 3,3) = c1*Eigen::Matrix<double,3,3>::Identity();
     M.block(p1,p3, 3,3) = c1*Eigen::Matrix<double,3,3>::Identity();

     M.block(p2,p0, 3,3) = c1*Eigen::Matrix<double,3,3>::Identity();
     M.block(p2,p1, 3,3) = c1*Eigen::Matrix<double,3,3>::Identity();
     M.block(p2,p2, 3,3) = c0*Eigen::Matrix<double,3,3>::Identity();
     M.block(p2,p3, 3,3) = c1*Eigen::Matrix<double,3,3>::Identity();

     M.block(p3,p0, 3,3) = c1*Eigen::Matrix<double,3,3>::Identity();
     M.block(p3,p1, 3,3) = c1*Eigen::Matrix<double,3,3>::Identity();
     M.block(p3,p2, 3,3) = c1*Eigen::Matrix<double,3,3>::Identity();
     M.block(p3,p3, 3,3) = c0*Eigen::Matrix<double,3,3>::Identity();
 }