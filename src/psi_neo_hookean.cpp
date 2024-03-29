#include <psi_neo_hookean.h>
#include <dphi_linear_tetrahedron_dX.h>
#include <iostream>
void psi_neo_hookean(double &psi, 
                     Eigen::Ref<const Eigen::Matrix3d> F,
                     double C, double D) {

    //double J = F.determinant();
    //psi = C * (pow(J, -2.0/3.0) * ((F.transpose()*F).trace()) - 3.0) + D * (J - 1.0)*(J - 1.0);

    double F1_1, F1_2, F1_3, F2_1, F2_2, F2_3,F3_1, F3_2, F3_3;
    F1_1 = F(0,0);
    F1_2 = F(0,1);
    F1_3 = F(0,2);
    F2_1 = F(1,0);
    F2_2 = F(1,1);
    F2_3 = F(1,2);
    F3_1 = F(2,0);
    F3_2 = F(2,1);
    F3_3 = F(2,2);

    psi = C*(1.0/pow(F1_1*F2_2*F3_3-F1_1*F2_3*F3_2-F1_2*F2_1*F3_3+F1_2*F2_3*F3_1+F1_3*F2_1*F3_2-F1_3*F2_2*F3_1,2.0/3.0)*(F1_1*F1_1+F1_2*F1_2+F1_3*F1_3+F2_1*F2_1+F2_2*F2_2+F2_3*F2_3+F3_1*F3_1+F3_2*F3_2+F3_3*F3_3)-3.0)+D*pow(-F1_1*F2_2*F3_3+F1_1*F2_3*F3_2+F1_2*F2_1*F3_3-F1_2*F2_3*F3_1-F1_3*F2_1*F3_2+F1_3*F2_2*F3_1+1.0,2.0);
}