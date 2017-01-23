//////////////////////////////////////////////////////////////////////////
// This file is part of openPSTD.                                       //
//                                                                      //
// openPSTD is free software: you can redistribute it and/or modify     //
// it under the terms of the GNU General Public License as published by //
// the Free Software Foundation, either version 3 of the License, or    //
// (at your option) any later version.                                  //
//                                                                      //
// openPSTD is distributed in the hope that it will be useful,          //
// but WITHOUT ANY WARRANTY; without even the implied warranty of       //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        //
// GNU General Public License for more details.                         //
//                                                                      //
// You should have received a copy of the GNU General Public License    //
// along with openPSTD.  If not, see <http://www.gnu.org/licenses/>.    //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//
// Date: 15-11-2016
//
//
// Authors: M. R. Fortuin
//
//
// Purpose:
//
//
//////////////////////////////////////////////////////////////////////////

#ifdef STAND_ALONE
#   define BOOST_TEST_MODULE Main
#endif

#include <boost/test/unit_test.hpp>
#include <kernel/DG/DG2D.h>
#include <kernel/DG/RK.h>
#include <kernel/DG/LEE2D.h>
#include <kernel/DG/DG2DBuilders.h>

#include <iostream>

#include "Macros.h"

using namespace OpenPSTD::Kernel;
using namespace OpenPSTD::Kernel::DG;
using namespace std;
using namespace Eigen;

BOOST_AUTO_TEST_SUITE(DG)
    BOOST_AUTO_TEST_SUITE(DG_General_2D)

        struct FixtureMaxwell025 {
            void addVertex(double x, double y)
            {
                VectorX<double> p(2);
                p << x, y;
                builder.Vertices.push_back(p);
            }

            void addTriangle(int i1, int i2, int i3)
            {
                vector<int> t;
                t.push_back(i1);
                t.push_back(i2);
                t.push_back(i3);
                builder.Elements.push_back(t);
            }

            void setupGrid()
            {
                addVertex(-1.0000000000000000e+00,-1.0000000000000000e+00);
                addVertex(+1.0000000000000000e+00,-1.0000000000000000e+00);
                addVertex(-7.5000000000000000e-01,-1.0000000000000000e+00);
                addVertex(-5.0000000000000000e-01,-1.0000000000000000e+00);
                addVertex(-2.5000000000000000e-01,-1.0000000000000000e+00);
                addVertex(+0.0000000000000000e+00,-1.0000000000000000e+00);
                addVertex(+2.5000000000000000e-01,-1.0000000000000000e+00);
                addVertex(+5.0000000000000000e-01,-1.0000000000000000e+00);
                addVertex(+7.5000000000000000e-01,-1.0000000000000000e+00);
                addVertex(+1.0000000000000000e+00,+1.0000000000000000e+00);
                addVertex(+1.0000000000000000e+00,-7.5000000000000000e-01);
                addVertex(+1.0000000000000000e+00,-5.0000000000000000e-01);
                addVertex(+1.0000000000000000e+00,-2.5000000000000000e-01);
                addVertex(+1.0000000000000000e+00,+0.0000000000000000e+00);
                addVertex(+1.0000000000000000e+00,+2.5000000000000000e-01);
                addVertex(+1.0000000000000000e+00,+5.0000000000000000e-01);
                addVertex(+1.0000000000000000e+00,+7.5000000000000000e-01);
                addVertex(-1.0000000000000000e+00,+1.0000000000000000e+00);
                addVertex(+7.5000000000000000e-01,+1.0000000000000000e+00);
                addVertex(+5.0000000000000000e-01,+1.0000000000000000e+00);
                addVertex(+2.5000000000000000e-01,+1.0000000000000000e+00);
                addVertex(+0.0000000000000000e+00,+1.0000000000000000e+00);
                addVertex(-2.5000000000000000e-01,+1.0000000000000000e+00);
                addVertex(-5.0000000000000000e-01,+1.0000000000000000e+00);
                addVertex(-7.5000000000000000e-01,+1.0000000000000000e+00);
                addVertex(-1.0000000000000000e+00,+7.5000000000000000e-01);
                addVertex(-1.0000000000000000e+00,+5.0000000000000000e-01);
                addVertex(-1.0000000000000000e+00,+2.5000000000000000e-01);
                addVertex(-1.0000000000000000e+00,+0.0000000000000000e+00);
                addVertex(-1.0000000000000000e+00,-2.5000000000000000e-01);
                addVertex(-1.0000000000000000e+00,-5.0000000000000000e-01);
                addVertex(-1.0000000000000000e+00,-7.5000000000000000e-01);
                addVertex(-8.2531548167799995e-01,-8.2446481953499995e-01);
                addVertex(-8.1447951081699999e-01,+1.1502662607200000e-01);
                addVertex(+8.2654860994400003e-01,-8.1983996105900003e-01);
                addVertex(+8.2589313229000005e-01,+8.2611230877099995e-01);
                addVertex(-8.2630725286300000e-01,+8.2389454592199995e-01);
                addVertex(-7.9306332741999996e-01,-6.0823468114099999e-01);
                addVertex(+5.9855245943299995e-01,-7.4356818359400001e-01);
                addVertex(+7.5952461963100004e-01,+5.9603174654799995e-01);
                addVertex(+6.1333801634600005e-01,+7.9706726033200004e-01);
                addVertex(+7.9969221256199996e-01,-5.9944637520599997e-01);
                addVertex(-5.9513419637800002e-01,-7.5916940637600006e-01);
                addVertex(-6.1443954120199995e-01,+7.9281284762399995e-01);
                addVertex(-7.6131295249300002e-01,+5.9004990528699996e-01);
                addVertex(-7.8055674341900005e-01,-3.5645935224300002e-01);
                addVertex(+7.9924896945000001e-01,-3.4882895196699998e-01);
                addVertex(-3.7089050838299997e-01,+7.8345848574400001e-01);
                addVertex(-3.3772265498199999e-01,-7.9297336391999995e-01);
                addVertex(-7.8377252335799996e-01,+3.2411914689900001e-01);
                addVertex(+3.6904495185100000e-01,+7.8814486770299996e-01);
                addVertex(+3.3128361313799998e-01,-7.6271989621600000e-01);
                addVertex(+7.7732720021000001e-01,+3.2829692989300002e-01);
                addVertex(-7.7607913687399999e-01,-1.0044416652500000e-01);
                addVertex(+7.8287963411700001e-01,+7.6938956584800003e-02);
                addVertex(-1.2445055920100000e-01,+7.7826995109899999e-01);
                addVertex(+8.3082201148599999e-01,-1.3404130331200001e-01);
                addVertex(-1.2803440484900000e-01,-8.2470739682100003e-01);
                addVertex(+8.2219540805400004e-02,-7.7207215827999998e-01);
                addVertex(-5.7488450159500004e-01,-4.8235063221699997e-01);
                addVertex(+1.2239659923500000e-01,+7.8030692193100004e-01);
                addVertex(+1.5282936973000000e-01,-2.2641695246300000e-01);
                addVertex(-3.9414778921900001e-01,-5.9841136727599997e-01);
                addVertex(-1.3964833580300001e-01,-5.8530495339199995e-01);
                addVertex(-5.4851380959399998e-01,-2.1058478135500000e-01);
                addVertex(-4.9587956062200000e-01,+5.7525454908700002e-01);
                addVertex(-5.9597777552700004e-01,+3.8133142108500001e-01);
                addVertex(-5.5330874878100000e-01,+1.0415222367000000e-01);
                addVertex(-2.4831870220200000e-01,+5.5614850741900002e-01);
                addVertex(+4.9263794124100002e-01,+5.8706863997000003e-01);
                addVertex(+5.8943261731100005e-01,+4.0251047548600000e-01);
                addVertex(+5.3305643659000002e-01,+1.5127166039000001e-01);
                addVertex(+2.4526620062999999e-01,+5.6490848086000001e-01);
                addVertex(+5.9676415496000002e-01,-4.5113805867599999e-01);
                addVertex(+4.0878674626099998e-01,-5.5827400326599996e-01);
                addVertex(+1.5533403415200001e-01,-5.0362095877699997e-01);
                addVertex(+5.9890241417599999e-01,-1.5196249048600000e-01);
                addVertex(-9.8979211988000000e-04,+5.5245514562400000e-01);
                addVertex(-3.3278480978899999e-01,-3.7324508848299998e-01);
                addVertex(-3.8075170451000001e-01,+3.4068750158700001e-01);
                addVertex(+3.7438339773899998e-01,+3.6312343024299998e-01);
                addVertex(+3.7412933369399998e-01,-3.2181545978400000e-01);
                addVertex(+3.2413164531900002e-01,-5.8317127791599997e-02);
                addVertex(+2.6899802038100001e-01,+1.5646683626300001e-01);
                addVertex(+1.2377069554600000e-01,+3.2514610305199998e-01);
                addVertex(-1.2220006077900000e-01,+3.1735857513299998e-01);
                addVertex(-2.9215686292499998e-01,-9.8824644726900002e-02);
                addVertex(-2.6629787903699997e-01,+1.3265220380800000e-01);
                addVertex(-7.3973031986299995e-02,-2.9107090650099998e-01);
                addVertex(+1.1300995058400000e-02,+2.9488117310800002e-02);

                addTriangle(31,0,32);
                addTriangle(32,0,2);
                addTriangle(8,1,34);
                addTriangle(34,1,10);
                addTriangle(16,9,35);
                addTriangle(35,9,18);
                addTriangle(24,17,36);
                addTriangle(36,17,25);
                addTriangle(31,32,37);
                addTriangle(31,37,30);
                addTriangle(8,34,38);
                addTriangle(8,38,7);
                addTriangle(16,35,39);
                addTriangle(16,39,15);
                addTriangle(35,18,40);
                addTriangle(40,18,19);
                addTriangle(34,10,41);
                addTriangle(41,10,11);
                addTriangle(32,2,42);
                addTriangle(42,2,3);
                addTriangle(24,36,43);
                addTriangle(24,43,23);
                addTriangle(36,25,44);
                addTriangle(44,25,26);
                addTriangle(30,37,45);
                addTriangle(30,45,29);
                addTriangle(41,11,46);
                addTriangle(46,11,12);
                addTriangle(23,43,47);
                addTriangle(23,47,22);
                addTriangle(42,3,48);
                addTriangle(48,3,4);
                addTriangle(44,26,49);
                addTriangle(49,26,27);
                addTriangle(40,19,50);
                addTriangle(50,19,20);
                addTriangle(7,38,51);
                addTriangle(7,51,6);
                addTriangle(15,39,52);
                addTriangle(15,52,14);
                addTriangle(29,45,53);
                addTriangle(29,53,28);
                addTriangle(14,52,54);
                addTriangle(14,54,13);
                addTriangle(49,27,33);
                addTriangle(33,27,28);
                addTriangle(46,12,56);
                addTriangle(56,12,13);
                addTriangle(22,47,55);
                addTriangle(22,55,21);
                addTriangle(6,51,58);
                addTriangle(6,58,5);
                addTriangle(48,4,57);
                addTriangle(57,4,5);
                addTriangle(50,20,60);
                addTriangle(60,20,21);
                addTriangle(33,28,53);
                addTriangle(57,5,58);
                addTriangle(60,21,55);
                addTriangle(13,54,56);
                addTriangle(35,40,39);
                addTriangle(34,41,38);
                addTriangle(37,32,42);
                addTriangle(43,36,44);
                addTriangle(45,37,59);
                addTriangle(59,37,42);
                addTriangle(42,48,62);
                addTriangle(42,62,59);
                addTriangle(48,57,63);
                addTriangle(48,63,62);
                addTriangle(53,45,64);
                addTriangle(64,45,59);
                addTriangle(47,43,65);
                addTriangle(65,43,44);
                addTriangle(44,49,66);
                addTriangle(44,66,65);
                addTriangle(49,33,67);
                addTriangle(49,67,66);
                addTriangle(55,47,68);
                addTriangle(68,47,65);
                addTriangle(40,50,69);
                addTriangle(40,69,39);
                addTriangle(52,39,70);
                addTriangle(70,39,69);
                addTriangle(54,52,71);
                addTriangle(71,52,70);
                addTriangle(50,60,72);
                addTriangle(50,72,69);
                addTriangle(41,46,73);
                addTriangle(41,73,38);
                addTriangle(51,38,74);
                addTriangle(74,38,73);
                addTriangle(58,51,75);
                addTriangle(75,51,74);
                addTriangle(46,56,76);
                addTriangle(46,76,73);
                addTriangle(67,33,53);
                addTriangle(53,64,67);
                addTriangle(63,57,58);
                addTriangle(58,75,63);
                addTriangle(76,56,54);
                addTriangle(54,71,76);
                addTriangle(72,60,77);
                addTriangle(77,60,55);
                addTriangle(55,68,77);
                addTriangle(59,62,78);
                addTriangle(59,78,64);
                addTriangle(62,63,78);
                addTriangle(68,65,79);
                addTriangle(79,65,66);
                addTriangle(66,67,79);
                addTriangle(69,72,80);
                addTriangle(69,80,70);
                addTriangle(71,70,80);
                addTriangle(73,76,81);
                addTriangle(73,81,74);
                addTriangle(75,74,81);
                addTriangle(81,76,82);
                addTriangle(82,76,71);
                addTriangle(71,80,83);
                addTriangle(71,83,82);
                addTriangle(72,77,84);
                addTriangle(72,84,80);
                addTriangle(77,68,85);
                addTriangle(77,85,84);
                addTriangle(68,79,85);
                addTriangle(64,78,86);
                addTriangle(64,86,67);
                addTriangle(79,67,87);
                addTriangle(87,67,86);
                addTriangle(78,63,88);
                addTriangle(88,63,75);
                addTriangle(75,81,61);
                addTriangle(75,61,88);
                addTriangle(83,80,84);
                addTriangle(79,87,85);
                addTriangle(78,88,86);
                addTriangle(61,81,82);
                addTriangle(87,86,89);
                addTriangle(89,86,88);
                addTriangle(88,61,89);
                addTriangle(82,83,89);
                addTriangle(82,89,61);
                addTriangle(84,85,89);
                addTriangle(89,85,87);
                addTriangle(84,89,83);
            }

            FixtureMaxwell025(): N(5)
            {
                BOOST_TEST_MESSAGE( "setup Maxwell025" );

                setupGrid();
                de = std::make_shared<LinearizedEulerEquationsDE2D<double>>();
                s = builder.Build(N, de);
            }

            int N;
            SimpleDG2DBuilder<double> builder;
            std::shared_ptr<LinearizedEulerEquationsDE2D<double>> de;
            std::shared_ptr<System2D<double>> s;
        };

        struct FixtureMaxwell025F {
            void addVertex(double x, double y)
            {
                VectorX<float> p(2);
                p << (float)x, (float)y;
                builder.Vertices.push_back(p);
            }

            void addTriangle(int i1, int i2, int i3)
            {
                vector<int> t;
                t.push_back(i1);
                t.push_back(i2);
                t.push_back(i3);
                builder.Elements.push_back(t);
            }

            void setupGrid()
            {
                addVertex(-1.0000000000000000e+00,-1.0000000000000000e+00);
                addVertex(+1.0000000000000000e+00,-1.0000000000000000e+00);
                addVertex(-7.5000000000000000e-01,-1.0000000000000000e+00);
                addVertex(-5.0000000000000000e-01,-1.0000000000000000e+00);
                addVertex(-2.5000000000000000e-01,-1.0000000000000000e+00);
                addVertex(+0.0000000000000000e+00,-1.0000000000000000e+00);
                addVertex(+2.5000000000000000e-01,-1.0000000000000000e+00);
                addVertex(+5.0000000000000000e-01,-1.0000000000000000e+00);
                addVertex(+7.5000000000000000e-01,-1.0000000000000000e+00);
                addVertex(+1.0000000000000000e+00,+1.0000000000000000e+00);
                addVertex(+1.0000000000000000e+00,-7.5000000000000000e-01);
                addVertex(+1.0000000000000000e+00,-5.0000000000000000e-01);
                addVertex(+1.0000000000000000e+00,-2.5000000000000000e-01);
                addVertex(+1.0000000000000000e+00,+0.0000000000000000e+00);
                addVertex(+1.0000000000000000e+00,+2.5000000000000000e-01);
                addVertex(+1.0000000000000000e+00,+5.0000000000000000e-01);
                addVertex(+1.0000000000000000e+00,+7.5000000000000000e-01);
                addVertex(-1.0000000000000000e+00,+1.0000000000000000e+00);
                addVertex(+7.5000000000000000e-01,+1.0000000000000000e+00);
                addVertex(+5.0000000000000000e-01,+1.0000000000000000e+00);
                addVertex(+2.5000000000000000e-01,+1.0000000000000000e+00);
                addVertex(+0.0000000000000000e+00,+1.0000000000000000e+00);
                addVertex(-2.5000000000000000e-01,+1.0000000000000000e+00);
                addVertex(-5.0000000000000000e-01,+1.0000000000000000e+00);
                addVertex(-7.5000000000000000e-01,+1.0000000000000000e+00);
                addVertex(-1.0000000000000000e+00,+7.5000000000000000e-01);
                addVertex(-1.0000000000000000e+00,+5.0000000000000000e-01);
                addVertex(-1.0000000000000000e+00,+2.5000000000000000e-01);
                addVertex(-1.0000000000000000e+00,+0.0000000000000000e+00);
                addVertex(-1.0000000000000000e+00,-2.5000000000000000e-01);
                addVertex(-1.0000000000000000e+00,-5.0000000000000000e-01);
                addVertex(-1.0000000000000000e+00,-7.5000000000000000e-01);
                addVertex(-8.2531548167799995e-01,-8.2446481953499995e-01);
                addVertex(-8.1447951081699999e-01,+1.1502662607200000e-01);
                addVertex(+8.2654860994400003e-01,-8.1983996105900003e-01);
                addVertex(+8.2589313229000005e-01,+8.2611230877099995e-01);
                addVertex(-8.2630725286300000e-01,+8.2389454592199995e-01);
                addVertex(-7.9306332741999996e-01,-6.0823468114099999e-01);
                addVertex(+5.9855245943299995e-01,-7.4356818359400001e-01);
                addVertex(+7.5952461963100004e-01,+5.9603174654799995e-01);
                addVertex(+6.1333801634600005e-01,+7.9706726033200004e-01);
                addVertex(+7.9969221256199996e-01,-5.9944637520599997e-01);
                addVertex(-5.9513419637800002e-01,-7.5916940637600006e-01);
                addVertex(-6.1443954120199995e-01,+7.9281284762399995e-01);
                addVertex(-7.6131295249300002e-01,+5.9004990528699996e-01);
                addVertex(-7.8055674341900005e-01,-3.5645935224300002e-01);
                addVertex(+7.9924896945000001e-01,-3.4882895196699998e-01);
                addVertex(-3.7089050838299997e-01,+7.8345848574400001e-01);
                addVertex(-3.3772265498199999e-01,-7.9297336391999995e-01);
                addVertex(-7.8377252335799996e-01,+3.2411914689900001e-01);
                addVertex(+3.6904495185100000e-01,+7.8814486770299996e-01);
                addVertex(+3.3128361313799998e-01,-7.6271989621600000e-01);
                addVertex(+7.7732720021000001e-01,+3.2829692989300002e-01);
                addVertex(-7.7607913687399999e-01,-1.0044416652500000e-01);
                addVertex(+7.8287963411700001e-01,+7.6938956584800003e-02);
                addVertex(-1.2445055920100000e-01,+7.7826995109899999e-01);
                addVertex(+8.3082201148599999e-01,-1.3404130331200001e-01);
                addVertex(-1.2803440484900000e-01,-8.2470739682100003e-01);
                addVertex(+8.2219540805400004e-02,-7.7207215827999998e-01);
                addVertex(-5.7488450159500004e-01,-4.8235063221699997e-01);
                addVertex(+1.2239659923500000e-01,+7.8030692193100004e-01);
                addVertex(+1.5282936973000000e-01,-2.2641695246300000e-01);
                addVertex(-3.9414778921900001e-01,-5.9841136727599997e-01);
                addVertex(-1.3964833580300001e-01,-5.8530495339199995e-01);
                addVertex(-5.4851380959399998e-01,-2.1058478135500000e-01);
                addVertex(-4.9587956062200000e-01,+5.7525454908700002e-01);
                addVertex(-5.9597777552700004e-01,+3.8133142108500001e-01);
                addVertex(-5.5330874878100000e-01,+1.0415222367000000e-01);
                addVertex(-2.4831870220200000e-01,+5.5614850741900002e-01);
                addVertex(+4.9263794124100002e-01,+5.8706863997000003e-01);
                addVertex(+5.8943261731100005e-01,+4.0251047548600000e-01);
                addVertex(+5.3305643659000002e-01,+1.5127166039000001e-01);
                addVertex(+2.4526620062999999e-01,+5.6490848086000001e-01);
                addVertex(+5.9676415496000002e-01,-4.5113805867599999e-01);
                addVertex(+4.0878674626099998e-01,-5.5827400326599996e-01);
                addVertex(+1.5533403415200001e-01,-5.0362095877699997e-01);
                addVertex(+5.9890241417599999e-01,-1.5196249048600000e-01);
                addVertex(-9.8979211988000000e-04,+5.5245514562400000e-01);
                addVertex(-3.3278480978899999e-01,-3.7324508848299998e-01);
                addVertex(-3.8075170451000001e-01,+3.4068750158700001e-01);
                addVertex(+3.7438339773899998e-01,+3.6312343024299998e-01);
                addVertex(+3.7412933369399998e-01,-3.2181545978400000e-01);
                addVertex(+3.2413164531900002e-01,-5.8317127791599997e-02);
                addVertex(+2.6899802038100001e-01,+1.5646683626300001e-01);
                addVertex(+1.2377069554600000e-01,+3.2514610305199998e-01);
                addVertex(-1.2220006077900000e-01,+3.1735857513299998e-01);
                addVertex(-2.9215686292499998e-01,-9.8824644726900002e-02);
                addVertex(-2.6629787903699997e-01,+1.3265220380800000e-01);
                addVertex(-7.3973031986299995e-02,-2.9107090650099998e-01);
                addVertex(+1.1300995058400000e-02,+2.9488117310800002e-02);

                addTriangle(31,0,32);
                addTriangle(32,0,2);
                addTriangle(8,1,34);
                addTriangle(34,1,10);
                addTriangle(16,9,35);
                addTriangle(35,9,18);
                addTriangle(24,17,36);
                addTriangle(36,17,25);
                addTriangle(31,32,37);
                addTriangle(31,37,30);
                addTriangle(8,34,38);
                addTriangle(8,38,7);
                addTriangle(16,35,39);
                addTriangle(16,39,15);
                addTriangle(35,18,40);
                addTriangle(40,18,19);
                addTriangle(34,10,41);
                addTriangle(41,10,11);
                addTriangle(32,2,42);
                addTriangle(42,2,3);
                addTriangle(24,36,43);
                addTriangle(24,43,23);
                addTriangle(36,25,44);
                addTriangle(44,25,26);
                addTriangle(30,37,45);
                addTriangle(30,45,29);
                addTriangle(41,11,46);
                addTriangle(46,11,12);
                addTriangle(23,43,47);
                addTriangle(23,47,22);
                addTriangle(42,3,48);
                addTriangle(48,3,4);
                addTriangle(44,26,49);
                addTriangle(49,26,27);
                addTriangle(40,19,50);
                addTriangle(50,19,20);
                addTriangle(7,38,51);
                addTriangle(7,51,6);
                addTriangle(15,39,52);
                addTriangle(15,52,14);
                addTriangle(29,45,53);
                addTriangle(29,53,28);
                addTriangle(14,52,54);
                addTriangle(14,54,13);
                addTriangle(49,27,33);
                addTriangle(33,27,28);
                addTriangle(46,12,56);
                addTriangle(56,12,13);
                addTriangle(22,47,55);
                addTriangle(22,55,21);
                addTriangle(6,51,58);
                addTriangle(6,58,5);
                addTriangle(48,4,57);
                addTriangle(57,4,5);
                addTriangle(50,20,60);
                addTriangle(60,20,21);
                addTriangle(33,28,53);
                addTriangle(57,5,58);
                addTriangle(60,21,55);
                addTriangle(13,54,56);
                addTriangle(35,40,39);
                addTriangle(34,41,38);
                addTriangle(37,32,42);
                addTriangle(43,36,44);
                addTriangle(45,37,59);
                addTriangle(59,37,42);
                addTriangle(42,48,62);
                addTriangle(42,62,59);
                addTriangle(48,57,63);
                addTriangle(48,63,62);
                addTriangle(53,45,64);
                addTriangle(64,45,59);
                addTriangle(47,43,65);
                addTriangle(65,43,44);
                addTriangle(44,49,66);
                addTriangle(44,66,65);
                addTriangle(49,33,67);
                addTriangle(49,67,66);
                addTriangle(55,47,68);
                addTriangle(68,47,65);
                addTriangle(40,50,69);
                addTriangle(40,69,39);
                addTriangle(52,39,70);
                addTriangle(70,39,69);
                addTriangle(54,52,71);
                addTriangle(71,52,70);
                addTriangle(50,60,72);
                addTriangle(50,72,69);
                addTriangle(41,46,73);
                addTriangle(41,73,38);
                addTriangle(51,38,74);
                addTriangle(74,38,73);
                addTriangle(58,51,75);
                addTriangle(75,51,74);
                addTriangle(46,56,76);
                addTriangle(46,76,73);
                addTriangle(67,33,53);
                addTriangle(53,64,67);
                addTriangle(63,57,58);
                addTriangle(58,75,63);
                addTriangle(76,56,54);
                addTriangle(54,71,76);
                addTriangle(72,60,77);
                addTriangle(77,60,55);
                addTriangle(55,68,77);
                addTriangle(59,62,78);
                addTriangle(59,78,64);
                addTriangle(62,63,78);
                addTriangle(68,65,79);
                addTriangle(79,65,66);
                addTriangle(66,67,79);
                addTriangle(69,72,80);
                addTriangle(69,80,70);
                addTriangle(71,70,80);
                addTriangle(73,76,81);
                addTriangle(73,81,74);
                addTriangle(75,74,81);
                addTriangle(81,76,82);
                addTriangle(82,76,71);
                addTriangle(71,80,83);
                addTriangle(71,83,82);
                addTriangle(72,77,84);
                addTriangle(72,84,80);
                addTriangle(77,68,85);
                addTriangle(77,85,84);
                addTriangle(68,79,85);
                addTriangle(64,78,86);
                addTriangle(64,86,67);
                addTriangle(79,67,87);
                addTriangle(87,67,86);
                addTriangle(78,63,88);
                addTriangle(88,63,75);
                addTriangle(75,81,61);
                addTriangle(75,61,88);
                addTriangle(83,80,84);
                addTriangle(79,87,85);
                addTriangle(78,88,86);
                addTriangle(61,81,82);
                addTriangle(87,86,89);
                addTriangle(89,86,88);
                addTriangle(88,61,89);
                addTriangle(82,83,89);
                addTriangle(82,89,61);
                addTriangle(84,85,89);
                addTriangle(89,85,87);
                addTriangle(84,89,83);
            }

            FixtureMaxwell025F(): N(5)
            {
                BOOST_TEST_MESSAGE( "setup Maxwell025" );

                setupGrid();
                de = std::make_shared<LinearizedEulerEquationsDE2D<float>>();
                s = builder.Build(N, de);
            }

            int N;
            SimpleDG2DBuilder<float> builder;
            std::shared_ptr<LinearizedEulerEquationsDE2D<float>> de;
            std::shared_ptr<System2D<float>> s;
        };


        BOOST_AUTO_TEST_CASE(DTScale)
        {
            FixtureMaxwell025 f;

            double dtScaleExpected = +6.3518192568559464e-02;
            double dtscale = f.s->Element[0]->GetDTScale();

            BOOST_CHECK(dtscale - dtScaleExpected < 1e-10);
        }


        BOOST_AUTO_TEST_CASE(DTScale2)
        {
            FixtureMaxwell025 f;

            double dtScaleExpected = +6.3724012799132326e-02;
            double dtscale = f.s->Element[1]->GetDTScale();

            BOOST_CHECK(dtscale - dtScaleExpected < 1e-10);
        }

        BOOST_AUTO_TEST_CASE(Normal)
        {
            FixtureMaxwell025 f;

            VectorX<double> nxExpected(18);
            VectorX<double> nyExpected(18);
            VectorX<double> sJExpected(18);
            nxExpected << -1.0000000000000000e+00,-1.0000000000000000e+00,-1.0000000000000000e+00,-1.0000000000000000e+00,-1.0000000000000000e+00,-1.0000000000000000e+00,+7.0882220920667693e-01,+7.0882220920668970e-01,+7.0882220920668726e-01,+7.0882220920668981e-01,+7.0882220920669214e-01,+7.0882220920668348e-01,+3.9213909766951061e-01,+3.9213909766953103e-01,+3.9213909766952243e-01,+3.9213909766952121e-01,+3.9213909766952654e-01,+3.9213909766952315e-01;
            nyExpected << -1.1114919695525362e-14,+1.0501130522289045e-15,+1.4474034688129570e-15,+1.4108530268604642e-15,-1.5339244074193899e-15,+1.3082242099858044e-14,-7.0538718143680923e-01,-7.0538718143679635e-01,-7.0538718143679890e-01,-7.0538718143679624e-01,-7.0538718143679369e-01,-7.0538718143680257e-01,+9.1990593436445545e-01,+9.1990593436444679e-01,+9.1990593436445045e-01,+9.1990593436445101e-01,+9.1990593436444879e-01,+9.1990593436445023e-01;
            sJExpected << +1.2499999999999953e-01,+1.2500000000000003e-01,+1.2499999999999986e-01,+1.2500000000000036e-01,+1.2499999999999985e-01,+1.2500000000000100e-01,+1.2382172721524916e-01,+1.2382172721524777e-01,+1.2382172721524774e-01,+1.2382172721524556e-01,+1.2382172721524719e-01,+1.2382172721524656e-01,+9.4946946093291448e-02,+9.4946946093290324e-02,+9.4946946093291212e-02,+9.4946946093291434e-02,+9.4946946093290990e-02,+9.4946946093291809e-02;

            BOOST_CHECK(f.s->Element[0]->nx.isApprox(nxExpected));
            BOOST_CHECK(f.s->Element[0]->ny.isApprox(nyExpected));
            BOOST_CHECK(f.s->Element[0]->sJ.isApprox(sJExpected));
        }

        BOOST_AUTO_TEST_CASE(Normal2)
        {
            FixtureMaxwell025 f;

            VectorX<double> nxExpected(18);
            VectorX<double> nyExpected(18);
            VectorX<double> sJExpected(18);
            nxExpected << -7.0882220920668548e-01,-7.0882220920668804e-01,-7.0882220920668748e-01,-7.0882220920668626e-01,-7.0882220920668881e-01,-7.0882220920668348e-01,-5.5511151231256634e-16,+7.7715611723761084e-15,-7.5495165674510708e-15,-2.3980817331903987e-14,+0.0000000000000000e+00,-3.5527136788004725e-15,+9.1898170941055235e-01,+9.1898170941055501e-01,+9.1898170941055368e-01,+9.1898170941055335e-01,+9.1898170941055624e-01,+9.1898170941055446e-01;
            nyExpected << +7.0538718143680068e-01,+7.0538718143679802e-01,+7.0538718143679857e-01,+7.0538718143679979e-01,+7.0538718143679724e-01,+7.0538718143680246e-01,-1.0000000000000000e+00,-1.0000000000000000e+00,-1.0000000000000000e+00,-1.0000000000000000e+00,-1.0000000000000000e+00,-1.0000000000000000e+00,+3.9430016201982349e-01,+3.9430016201981744e-01,+3.9430016201982038e-01,+3.9430016201982099e-01,+3.9430016201981460e-01,+3.9430016201981882e-01;
            sJExpected << +1.2382172721524647e-01,+1.2382172721524827e-01,+1.2382172721524853e-01,+1.2382172721524810e-01,+1.2382172721524790e-01,+1.2382172721525096e-01,+1.2500000000000269e-01,+1.2499999999999981e-01,+1.2499999999999989e-01,+1.2499999999999684e-01,+1.2499999999999972e-01,+1.2500000000000100e-01,+9.5505263416824748e-02,+9.5505263416825650e-02,+9.5505263416826414e-02,+9.5505263416826205e-02,+9.5505263416825914e-02,+9.5505263416826580e-02;

            BOOST_CHECK(f.s->Element[1]->nx.isApprox(nxExpected));
            BOOST_CHECK(f.s->Element[1]->ny.isApprox(nyExpected));
            BOOST_CHECK(f.s->Element[1]->sJ.isApprox(sJExpected));
        }

        BOOST_AUTO_TEST_CASE(xy)
        {
            FixtureMaxwell025 f;

            VectorX<double> xExpected(21);
            VectorX<double> yExpected(21);
            xExpected << -1.0000000000000000e+00,-1.0000000000000000e+00,-1.0000000000000000e+00,-1.0000000000000000e+00,-1.0000000000000000e+00,-1.0000000000000000e+00,-9.7947940121415011e-01,-9.7244111658920707e-01,-9.7008606627742555e-01,-9.7244111658920696e-01,-9.7947940121415011e-01,-9.3757050587233759e-01,-9.2761470770028720e-01,-9.2761470770028731e-01,-9.3757050587233759e-01,-8.8774497580566236e-01,-8.8043324849958593e-01,-8.8774497580566236e-01,-8.4583608046384984e-01,-8.4583608046384984e-01,-8.2531548167799995e-01;
            yExpected << -7.5000000000000000e-01,-7.7936808450881689e-01,-8.3934606043991933e-01,-9.1065393956008067e-01,-9.7063191549118311e-01,-1.0000000000000000e+00,-7.5874755645215064e-01,-8.0118878432023521e-01,-8.6634607889920856e-01,-9.3286597725845100e-01,-9.7937947194333386e-01,-7.7661255306728716e-01,-8.2366789731765966e-01,-8.8445084331813173e-01,-9.3726649262736783e-01,-7.9785226646771279e-01,-8.4041005795631374e-01,-8.8719832690763212e-01,-8.1571726308284920e-01,-8.4508534759166620e-01,-8.2446481953499995e-01;

            BOOST_CHECK(f.s->Element[0]->x.isApprox(xExpected, 1e-8));
            BOOST_CHECK(f.s->Element[0]->y.isApprox(yExpected, 1e-8));
        }

        BOOST_AUTO_TEST_CASE(xy2)
        {
            FixtureMaxwell025 f;

            VectorX<double> xExpected(21);
            VectorX<double> yExpected(21);
            xExpected << -8.2531548167799995e-01,-8.4583608046384984e-01,-8.8774497580566236e-01,-9.3757050587233759e-01,-9.7947940121415011e-01,-1.0000000000000000e+00,-8.1646799595503294e-01,-8.4099231281232445e-01,-8.8480333836726854e-01,-9.3300018090194559e-01,-9.7063191549118311e-01,-7.9839891536574303e-01,-8.2402039236679658e-01,-8.6649175094393494e-01,-9.1065393956008067e-01,-7.7691656631225681e-01,-8.0132298796372992e-01,-8.3934606043991933e-01,-7.5884748572296701e-01,-7.7936808450881701e-01,-7.5000000000000000e-01;
            yExpected << -8.2446481953499995e-01,-8.4508534759166609e-01,-8.8719832690763212e-01,-9.3726649262736783e-01,-9.7937947194333375e-01,-1.0000000000000000e+00,-8.4508534759166609e-01,-8.7985099364357511e-01,-9.2726221265115039e-01,-9.7230691294571248e-01,-1.0000000000000000e+00,-8.8719832690763212e-01,-9.2726221265115027e-01,-9.6994039423269929e-01,-1.0000000000000000e+00,-9.3726649262736783e-01,-9.7230691294571248e-01,-1.0000000000000000e+00,-9.7937947194333375e-01,-1.0000000000000000e+00,-1.0000000000000000e+00;

            BOOST_CHECK(f.s->Element[1]->x.isApprox(xExpected, 1e-8));
            BOOST_CHECK(f.s->Element[1]->y.isApprox(yExpected, 1e-8));
        }

        BOOST_AUTO_TEST_CASE(InternalValues)
        {
            FixtureMaxwell025 f;

            VectorX<double> internalExpected(18);
            internalExpected << +2.7821590655702477e-01,+3.5371072095186978e-01,+5.1060010752748775e-01,+5.7147972182225382e-01,+1.9746969836555683e-01,+3.3795203961490709e-04,+3.3795203961490709e-04,+2.1624347545323813e-01,+6.6159284237215088e-01,+3.1425448265309097e-01,+1.8594288263443695e-01,+1.4070469071335678e-01,+2.7821590655702477e-01,+3.4826020217016551e-01,+4.5585363967195319e-01,+3.9607183616119429e-01,+2.1882492618820651e-01,+1.4070469071335678e-01;

            BOOST_CHECK(f.s->Element[121]->GetFaceInternalValues(LinearizedEulerEquationsDE2D<double>::IndexPX).isApprox(internalExpected, 1e-8));
        }

        BOOST_AUTO_TEST_CASE(ExternalValues)
        {
            FixtureMaxwell025 f;

            VectorX<double> externalExpected(18);
            externalExpected << +2.7821590655702477e-01,+3.5371072095186984e-01,+5.1060010752748775e-01,+5.7147972182225382e-01,+1.9746969836555708e-01,+3.3795203961490709e-04,+3.3795203961490709e-04,+2.1624347545323871e-01,+6.6159284237215088e-01,+3.1425448265309097e-01,+1.8594288263443678e-01,+1.4070469071335678e-01,+2.7821590655702477e-01,+3.4826020217016551e-01,+4.5585363967195319e-01,+3.9607183616119429e-01,+2.1882492618820665e-01,+1.4070469071335678e-01;

            BOOST_CHECK(f.s->Element[121]->GetFaceExternalValues(LinearizedEulerEquationsDE2D<double>::IndexPX).isApprox(externalExpected, 1e-8));
        }

        BOOST_AUTO_TEST_CASE(rs)
        {
            FixtureMaxwell025 f;

            int N = 5;
            int Np = (N+1)*(N+2)/2;

            VectorX<double> r(Np);
            VectorX<double> s(Np);
            MatrixX<double> rs(Np, 2);

            r << -1.0000000000000000e+00,-7.6505532392946507e-01,-2.8523151648064521e-01,+2.8523151648064510e-01,+7.6505532392946463e-01,+1.0000000000000000e+00,-1.0000000000000002e+00,-6.8447251450190882e-01,-1.7124547733207449e-01,+3.6894502900381732e-01,+7.6505532392946485e-01,-1.0000000000000000e+00,-6.5750904533585097e-01,-1.7124547733207443e-01,+2.8523151648064521e-01,-1.0000000000000000e+00,-6.8447251450190860e-01,-2.8523151648064510e-01,-9.9999999999999989e-01,-7.6505532392946463e-01,-1.0000000000000000e+00;
            s << -1.0000000000000000e+00,-1.0000000000000000e+00,-1.0000000000000000e+00,-1.0000000000000000e+00,-1.0000000000000000e+00,-1.0000000000000000e+00,-7.6505532392946463e-01,-6.8447251450190860e-01,-6.5750904533585097e-01,-6.8447251450190871e-01,-7.6505532392946485e-01,-2.8523151648064510e-01,-1.7124547733207457e-01,-1.7124547733207446e-01,-2.8523151648064521e-01,+2.8523151648064521e-01,+3.6894502900381743e-01,+2.8523151648064510e-01,+7.6505532392946496e-01,+7.6505532392946474e-01,+1.0000000000000000e+00;
            rs << r, s;

            BOOST_CHECK(f.s->rs.isApprox(rs, 1e-8));
        }


        BOOST_AUTO_TEST_CASE(LIFT)
        {
            FixtureMaxwell025 f;

            MatrixX<double> LIFTExpected(21, 18);
            LIFTExpected <<
                 +1.3499999999999988e+01,+1.0141415936319683e+01,-4.0361872703053345e+00,+2.2446846481761704e+00,-1.3499133141904704e+00,+5.0000000000000133e-01,-6.9999999999999751e-01,-3.9739870411274056e+00,-5.8260129588726155e+00,-5.8260129588726146e+00,-3.9739870411274025e+00,-7.0000000000000018e-01,+1.3499999999999998e+01,+1.0141415936319721e+01,-4.0361872703053443e+00,+2.2446846481761651e+00,-1.3499133141904878e+00,+4.9999999999999828e-01,
                    +1.7863649483390924e+00,+1.6000000000000007e+01,+4.1114464919588549e+00,-1.3371546067814126e+00,+6.7712434446771863e-01,-2.3778117798422960e-01,+2.6582829822671994e-01,+1.7232943582955778e+00,+2.5205261997134532e+00,+7.4910028538255635e-01,-2.0405943815771908e+00,-6.9997315525340364e-01,+6.4030296631248018e-01,-4.2248952816794079e+00,+1.4181365527607135e+00,-4.8669246887376694e-01,+1.9254096562316508e-01,-5.7574338930920135e-02,
                    -4.8495104785356985e-01,+2.8044625363303197e+00,+1.6000000000000014e+01,+3.3228756555323069e+00,-9.1208775484107696e-01,+2.6970061083204033e-01,-1.5324879520891721e-01,-1.5795052507671792e+00,-2.0576995390647932e+00,+1.9094439377067995e+00,+4.9424716102712574e-01,-6.9300386402554348e-01,-2.0050151694931717e-01,+2.5448531593055428e+00,+5.5604572554977438e-01,-1.6581357848539517e+00,+1.4060010281182231e+00,-5.6849626083775251e-01,
                    +2.6970061083204061e-01,-9.1208775484107729e-01,+3.3228756555323069e+00,+1.6000000000000011e+01,+2.8044625363303237e+00,-4.8495104785356757e-01,-2.0050151694931828e-01,+2.5448531593055317e+00,+5.5604572554977572e-01,-1.6581357848539520e+00,+1.4060010281182236e+00,-5.6849626083775073e-01,-1.5324879520891832e-01,-1.5795052507671867e+00,-2.0576995390647923e+00,+1.9094439377068020e+00,+4.9424716102712374e-01,-6.9300386402554448e-01,
                    -2.3778117798422904e-01,+6.7712434446771519e-01,-1.3371546067814117e+00,+4.1114464919588638e+00,+1.6000000000000007e+01,+1.7863649483390933e+00,+6.4030296631247063e-01,-4.2248952816793963e+00,+1.4181365527607201e+00,-4.8669246887377055e-01,+1.9254096562316705e-01,-5.7574338930921141e-02,+2.6582829822671938e-01,+1.7232943582955813e+00,+2.5205261997134571e+00,+7.4910028538256301e-01,-2.0405943815771805e+00,-6.9997315525340276e-01,
                    +5.0000000000000466e-01,-1.3499133141904758e+00,+2.2446846481761762e+00,-4.0361872703053479e+00,+1.0141415936319675e+01,+1.3499999999999996e+01,+1.3499999999999993e+01,+1.0141415936319685e+01,-4.0361872703053461e+00,+2.2446846481761664e+00,-1.3499133141904891e+00,+4.9999999999999806e-01,-6.9999999999999973e-01,-3.9739870411274216e+00,-5.8260129588726191e+00,-5.8260129588726164e+00,-3.9739870411273892e+00,-6.9999999999999696e-01,
                    +6.4030296631247752e-01,-4.2248952816794034e+00,+1.4181365527607279e+00,-4.8669246887377704e-01,+1.9254096562316603e-01,-5.7574338930921454e-02,-6.9997315525340753e-01,-2.0405943815771987e+00,+7.4910028538256768e-01,+2.5205261997134625e+00,+1.7232943582955800e+00,+2.6582829822671744e-01,+1.7863649483391035e+00,+1.6000000000000089e+01,+4.1114464919588736e+00,-1.3371546067814308e+00,+6.7712434446770842e-01,-2.3778117798423373e-01,
                    -3.4405502684415779e-01,-1.2885656531826066e+00,-1.9327190275090023e+00,+3.1248998104726622e-01,+2.4222874465476024e-02,-2.6623468252262431e-02,+8.2318517604749147e-02,+1.5369337345255046e-01,-9.7585195660533863e-01,-9.7585195660533697e-01,+1.5369337345254983e-01,+8.2318517604748564e-02,-3.4405502684415901e-01,-1.2885656531826126e+00,-1.9327190275090018e+00,+3.1248998104726550e-01,+2.4222874465479011e-02,-2.6623468252262410e-02,
                    +1.1931865138044873e-01,-4.6404969366478088e-02,-1.6278995303006953e+00,-1.6278995303006947e+00,-4.6404969366478199e-02,+1.1931865138044867e-01,+9.8702596757501648e-02,+3.7334722764620937e-01,+1.2915165581319552e+00,+3.6970567943580634e-01,-3.0065441988196168e-01,+3.2271106389538305e-02,+9.8702596757501815e-02,+3.7334722764621059e-01,+1.2915165581319552e+00,+3.6970567943580623e-01,-3.0065441988196062e-01,+3.2271106389538617e-02,
                    -2.6623468252262805e-02,+2.4222874465478356e-02,+3.1248998104726378e-01,-1.9327190275090000e+00,-1.2885656531826062e+00,-3.4405502684415828e-01,-3.4405502684415751e-01,-1.2885656531826064e+00,-1.9327190275090014e+00,+3.1248998104726677e-01,+2.4222874465478491e-02,-2.6623468252262410e-02,+8.2318517604748259e-02,+1.5369337345254980e-01,-9.7585195660533763e-01,-9.7585195660533808e-01,+1.5369337345254996e-01,+8.2318517604748773e-02,
                    -5.7574338930921565e-02,+1.9254096562316603e-01,-4.8669246887377327e-01,+1.4181365527607197e+00,-4.2248952816793945e+00,+6.4030296631247552e-01,+1.7863649483390951e+00,+1.6000000000000025e+01,+4.1114464919588602e+00,-1.3371546067814262e+00,+6.7712434446770631e-01,-2.3778117798423187e-01,-6.9997315525340564e-01,-2.0405943815772001e+00,+7.4910028538256435e-01,+2.5205261997134603e+00,+1.7232943582955722e+00,+2.6582829822671666e-01,
                    -2.0050151694931995e-01,+2.5448531593055308e+00,+5.5604572554977549e-01,-1.6581357848539531e+00,+1.4060010281182254e+00,-5.6849626083775018e-01,-6.9300386402554426e-01,+4.9424716102712496e-01,+1.9094439377068007e+00,-2.0576995390647950e+00,-1.5795052507671812e+00,-1.5324879520891829e-01,-4.8495104785356791e-01,+2.8044625363303277e+00,+1.6000000000000018e+01,+3.3228756555323047e+00,-9.1208775484108573e-01,+2.6970061083203961e-01,
                    +9.8702596757501870e-02,+3.7334722764620909e-01,+1.2915165581319554e+00,+3.6970567943580707e-01,-3.0065441988196107e-01,+3.2271106389538513e-02,+3.2271106389538590e-02,-3.0065441988196123e-01,+3.6970567943580629e-01,+1.2915165581319559e+00,+3.7334722764621014e-01,+9.8702596757501843e-02,+1.1931865138044903e-01,-4.6404969366477422e-02,-1.6278995303006967e+00,-1.6278995303006947e+00,-4.6404969366476707e-02,+1.1931865138044856e-01,
                    +3.2271106389539048e-02,-3.0065441988196095e-01,+3.6970567943580684e-01,+1.2915165581319543e+00,+3.7334722764620853e-01,+9.8702596757502301e-02,+1.1931865138044916e-01,-4.6404969366478338e-02,-1.6278995303006947e+00,-1.6278995303006938e+00,-4.6404969366478213e-02,+1.1931865138044881e-01,+3.2271106389538881e-02,-3.0065441988196251e-01,+3.6970567943580712e-01,+1.2915165581319556e+00,+3.7334722764620792e-01,+9.8702596757501815e-02,
                    -5.6849626083775084e-01,+1.4060010281182236e+00,-1.6581357848539504e+00,+5.5604572554977461e-01,+2.5448531593055312e+00,-2.0050151694931834e-01,-4.8495104785356963e-01,+2.8044625363303206e+00,+1.6000000000000014e+01,+3.3228756555323020e+00,-9.1208775484108617e-01,+2.6970061083203933e-01,-6.9300386402554393e-01,+4.9424716102712662e-01,+1.9094439377068007e+00,-2.0576995390647972e+00,-1.5795052507671752e+00,-1.5324879520891729e-01,
                    -1.5324879520891740e-01,-1.5795052507671772e+00,-2.0576995390647914e+00,+1.9094439377068013e+00,+4.9424716102712107e-01,-6.9300386402554459e-01,-5.6849626083775140e-01,+1.4060010281182249e+00,-1.6581357848539564e+00,+5.5604572554977649e-01,+2.5448531593055383e+00,-2.0050151694931809e-01,+2.6970061083203983e-01,-9.1208775484108706e-01,+3.3228756555323056e+00,+1.6000000000000018e+01,+2.8044625363303131e+00,-4.8495104785356985e-01,
                    +8.2318517604749231e-02,+1.5369337345255035e-01,-9.7585195660533919e-01,-9.7585195660533774e-01,+1.5369337345254994e-01,+8.2318517604748481e-02,-2.6623468252262635e-02,+2.4222874465478973e-02,+3.1248998104726555e-01,-1.9327190275090014e+00,-1.2885656531826091e+00,-3.4405502684415867e-01,-2.6623468252262382e-02,+2.4222874465477971e-02,+3.1248998104726766e-01,-1.9327190275090038e+00,-1.2885656531826044e+00,-3.4405502684415723e-01,
                    -6.9300386402554481e-01,+4.9424716102712152e-01,+1.9094439377067991e+00,-2.0576995390647919e+00,-1.5795052507671772e+00,-1.5324879520891774e-01,+2.6970061083203994e-01,-9.1208775484108473e-01,+3.3228756555323016e+00,+1.6000000000000004e+01,+2.8044625363303206e+00,-4.8495104785356752e-01,-5.6849626083775018e-01,+1.4060010281182269e+00,-1.6581357848539546e+00,+5.5604572554977594e-01,+2.5448531593055295e+00,-2.0050151694931953e-01,
                    +2.6582829822671605e-01,+1.7232943582955755e+00,+2.5205261997134540e+00,+7.4910028538256013e-01,-2.0405943815771832e+00,-6.9997315525340187e-01,-5.7574338930918616e-02,+1.9254096562316561e-01,-4.8669246887376644e-01,+1.4181365527607162e+00,-4.2248952816793972e+00,+6.4030296631247774e-01,-2.3778117798423215e-01,+6.7712434446770420e-01,-1.3371546067814255e+00,+4.1114464919588443e+00,+1.5999999999999993e+01,+1.7863649483390913e+00,
                    -6.9997315525340287e-01,-2.0405943815771863e+00,+7.4910028538256790e-01,+2.5205261997134576e+00,+1.7232943582955724e+00,+2.6582829822671683e-01,-2.3778117798423284e-01,+6.7712434446770686e-01,-1.3371546067814277e+00,+4.1114464919588611e+00,+1.6000000000000043e+01,+1.7863649483390975e+00,-5.7574338930919740e-02,+1.9254096562317105e-01,-4.8669246887377265e-01,+1.4181365527607268e+00,-4.2248952816793928e+00,+6.4030296631247396e-01,
                    -6.9999999999999762e-01,-3.9739870411274008e+00,-5.8260129588726226e+00,-5.8260129588726173e+00,-3.9739870411274048e+00,-7.0000000000000084e-01,+4.9999999999999833e-01,-1.3499133141904862e+00,+2.2446846481761642e+00,-4.0361872703053425e+00,+1.0141415936319694e+01,+1.3499999999999986e+01,+4.9999999999999745e-01,-1.3499133141904860e+00,+2.2446846481761611e+00,-4.0361872703053381e+00,+1.0141415936319673e+01,+1.3499999999999979e+01;

            BOOST_CHECK(f.s->LIFT.isApprox(LIFTExpected, 1e-8));
        }

        BOOST_AUTO_TEST_CASE(FScale)
        {
            FixtureMaxwell025 f;

            VectorX<double> FScaleExpected(18);
            FScaleExpected <<
                           +8.5719143133592208e+00,
                    +8.5719143133592528e+00,
                    +8.5719143133592262e+00,
                    +8.5719143133592066e+00,
                    +8.5719143133593008e+00,
                    +8.5719143133590574e+00,
                    +9.0143151890168198e+00,
                    +9.0143151890168287e+00,
                    +9.0143151890168465e+00,
                    +9.0143151890167967e+00,
                    +9.0143151890168642e+00,
                    +9.0143151890168216e+00,
                    +9.3442998772026158e+00,
                    +9.3442998772026371e+00,
                    +9.3442998772025838e+00,
                    +9.3442998772026193e+00,
                    +9.3442998772026478e+00,
                    +9.3442998772026371e+00;

            BOOST_CHECK(f.s->Element[121]->Fscale.isApprox(FScaleExpected, 1e-8));
        }

        BOOST_AUTO_TEST_CASE(GetValuesOfOtherSide)
        {
            FixtureMaxwell025 f;

            VectorX<double> expected(6);
            expected <<
                     +1.4070469071335678e-01,
                    +1.6638299541923232e-01,
                    +1.6556281514007740e-01,
                    +1.1089268457822350e-01,
                    +6.2599273469468628e-02,
                    +4.4310633136691042e-02;

            VectorX<double> result = f.s->Element[122]->Faces[1]->GetValuesOfOtherSide(0);

            BOOST_CHECK(result.isApprox(expected, 1e-8));
        }

        BOOST_AUTO_TEST_CASE(Face1)
        {
            FixtureMaxwell025 f;

            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[0]->NodesOnFace[0], 0);
            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[0]->NodesOnFace[1], 1);
            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[0]->NodesOnFace[2], 2);
            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[0]->NodesOnFace[3], 3);
            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[0]->NodesOnFace[4], 4);
            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[0]->NodesOnFace[5], 5);
        }
        BOOST_AUTO_TEST_CASE(Face2)
        {
            FixtureMaxwell025 f;

            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[1]->NodesOnFace[0], 5);
            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[1]->NodesOnFace[1], 10);
            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[1]->NodesOnFace[2], 14);
            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[1]->NodesOnFace[3], 17);
            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[1]->NodesOnFace[4], 19);
            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[1]->NodesOnFace[5], 20);
        }
        BOOST_AUTO_TEST_CASE(Face3)
        {
            FixtureMaxwell025 f;

            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[2]->NodesOnFace[0], 0);
            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[2]->NodesOnFace[1], 6);
            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[2]->NodesOnFace[2], 11);
            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[2]->NodesOnFace[3], 15);
            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[2]->NodesOnFace[4], 18);
            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[2]->NodesOnFace[5], 20);
        }

        BOOST_AUTO_TEST_CASE(Face1F)
        {
            FixtureMaxwell025F f;

            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[0]->NodesOnFace[0], 0);
            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[0]->NodesOnFace[1], 1);
            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[0]->NodesOnFace[2], 2);
            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[0]->NodesOnFace[3], 3);
            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[0]->NodesOnFace[4], 4);
            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[0]->NodesOnFace[5], 5);
        }
        BOOST_AUTO_TEST_CASE(Face2F)
        {
            FixtureMaxwell025F f;

            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[1]->NodesOnFace[0], 5);
            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[1]->NodesOnFace[1], 10);
            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[1]->NodesOnFace[2], 14);
            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[1]->NodesOnFace[3], 17);
            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[1]->NodesOnFace[4], 19);
            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[1]->NodesOnFace[5], 20);
        }
        BOOST_AUTO_TEST_CASE(Face3F)
        {
            FixtureMaxwell025F f;

            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[2]->NodesOnFace[0], 0);
            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[2]->NodesOnFace[1], 6);
            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[2]->NodesOnFace[2], 11);
            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[2]->NodesOnFace[3], 15);
            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[2]->NodesOnFace[4], 18);
            BOOST_CHECK_EQUAL(f.s->Element[0]->Faces[2]->NodesOnFace[5], 20);
        }

        BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()