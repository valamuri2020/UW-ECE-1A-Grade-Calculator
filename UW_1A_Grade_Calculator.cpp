#include <iostream>
class Course{
public:
    void ascending_sort_(double arr[], std::size_t capacity);
    void summing_marks_(double arr[], double &sum, std::size_t min_bound, std::size_t capacity);
};
void Course::summing_marks_(double arr[], double &sum, std::size_t min_bound, std::size_t capacity){
    for (std::size_t i{min_bound}; i < capacity; i++){
        sum += arr[i];
    }
    sum = sum / (capacity-min_bound);
}
void Course::ascending_sort_(double arr[], std::size_t capacity){
    double temp{999};
    for(std::size_t i{0}; i < capacity-1; i++){
         for (std::size_t j{0}; j < capacity-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
         }
        }
    }
}


class Math: public Course{
public:
    double mark_;

    double written_assignments_[10];
    double online_assignments_[10];

};

class Calc: public Math { ///// ?????????? is it public or private after the colon?????????
public:
    Calc();
    double midterm_;
    double midterm_weight_;
    double final_exam_;
    double final_weight_;

    double calculate_mark();
    double calculate_assignment_mark();
private:
// calculate average of each assignment into a new array
};
Calc::Calc(){
    midterm_ = 0;
    midterm_weight_ = .2;
    final_exam_ = 0;
    final_weight_ = .3;
}
double Calc::calculate_assignment_mark(){
    double final_assignment_mark = 0;
    double assignment_marks[10] = {0};
    for (std::size_t i{0}; i < 10; i++){
        assignment_marks[i] = (.3*written_assignments_[i] + .2*online_assignments_[i]);
    }
//sort by ascending order
    Math::ascending_sort_(assignment_marks, 10);

    // now the lowest two are entries 0 and 1, so calculate avg using entries 2-9

    Course::summing_marks_(assignment_marks, final_assignment_mark, 2, 10);
//    for (std::size_t i{2}; i < 10; i++){
//        final_assignment_mark += assignment_marks[i];
//    }

   // final_assignment_mark /= 8;
    return final_assignment_mark;
}

double Calc::calculate_mark(){
    double a_mark = calculate_assignment_mark();
    mark_ = a_mark + midterm_* midterm_weight_ + final_exam_ * final_weight_;
    return mark_;
}

class LiAlg : public Math{
public:
    LiAlg();
    double term_tests_[3];
    double term_test_weight_;

    double calculate_assigment_mark_();
    double calculate_mark_();
};
LiAlg::LiAlg(){
    for (std::size_t i = 0; i < 3; i++){
            term_tests_[i] = 0;
    }
    term_test_weight_ = .5/3;
}
double LiAlg::calculate_assigment_mark_(){

    Math::ascending_sort_(written_assignments_, 10);
    Math::ascending_sort_(online_assignments_, 9);

    double wa_mark = 0;
    double mobius = 0;

    Course::summing_marks_(written_assignments_, wa_mark, 2, 10);
    Course::summing_marks_(online_assignments_, mobius, 2, 9);

    double a_grade = .3*wa_mark + .2*mobius;
    return a_grade;
}

double LiAlg::calculate_mark_(){
    double tt_mark = 0;
    for (std::size_t i{0}; i < 3; i++){
        tt_mark += term_test_weight_* term_tests_[i];
    }
    double a_mark = calculate_assigment_mark_();
    return a_mark + tt_mark;
}

class Phys : public Course{
public:
    Phys();

    double mark_;
    double mobius_[11];
    double quizzes_[10];
    double term_tests_[3];
    double term_tests_weights_[3];

    double calculate_quiz_mark_();
    double calculate_mark_();
};
Phys::Phys(){
    mark_ = 0;
    for(std::size_t i{0}; i < 11; i++){
        if (i < 3){
          term_tests_[i] = 0;
        }
        if (i < 10){
            quizzes_[i] = 0;
        }
        mobius_[i] = 0;
    }
    term_tests_weights_[0] = .15;
    term_tests_weights_[1] = .20;
    term_tests_weights_[2] = .25;

}

double Phys::calculate_quiz_mark_(){
    double quiz_grade = 0;
    double quiz7 = quizzes_[6];
    double updated_quizzes [9] = {0};
    for (std::size_t i{0}; i < 10; i++){
        if(i < 6){
            updated_quizzes[i] = quizzes_[i];
        }
        else if (i >= 6){
            updated_quizzes[i] = quizzes_[i+1];
        }
    }
    Course::ascending_sort_(updated_quizzes, 9);

    for (std::size_t i{2}; i < 9; i++){
        quiz_grade += updated_quizzes[i];
    }
    quiz_grade /= 7;

    quiz_grade *= .2;

    quiz_grade += quiz7 * 20/800;

    return quiz_grade;
}
double Phys::calculate_mark_(){
    double a_grade = 0;
    double q_grade = calculate_quiz_mark_();
    double tt_grade = 0;
    Course::summing_marks_(mobius_, a_grade, 0, 11);

    a_grade *= .2;
    for (std::size_t i{0}; i < 3; i++){
        tt_grade += term_tests_[i] * term_tests_weights_[i];
    }
    mark_ = a_grade + q_grade + tt_grade;

    return mark_;
}

class CSP : public Course {
public:
    CSP();
    double mark_;

    double quizzes_[5] = {0};
    double projects_[4] = {0};

    double midterm_;
    double midterm_weight_;
    double final_exam_;
    double final_weight_;

    double calculate_mark_();
    double calculate_quiz_mark();
};
CSP::CSP(){
    mark_ = 0;
    midterm_ = 0;
    midterm_weight_ = .2;
    final_exam_ = 0;
    final_weight_ = .3;
}
double CSP::calculate_quiz_mark(){
    double q_grade = 0;

    Course::summing_marks_(quizzes_, q_grade, 0, 5);
    q_grade *= .1;

    return q_grade;
}
double CSP::calculate_mark_(){
    double proj_grade = 0;
    for (std::size_t i{1}; i < 4; i++){
        proj_grade += projects_[i];
    }
    proj_grade *= .12;
    proj_grade += projects_[0] * .04;

    mark_ = calculate_quiz_mark() + proj_grade + midterm_ * midterm_weight_;
    std::cout << "Mark before final: " << mark_ << "\n" ;

    mark_+= final_exam_ * final_weight_;

    return mark_;
}

void main_display();
void disp_Calc();
void disp_LiAlg();
void disp_Phys();
void disp_CSP();
void input_loop(Calc &calc_obj, std::size_t capacity);
void input_loop(LiAlg &lialg_obj, std::size_t capacity);
void input_loop(Phys &phys_obj, std::size_t capacity);
void input_loop(CSP &csp_obj, std::size_t capacity);

int main()
{
    main_display();
    unsigned int course {0};
    std::cin >> course;

    switch (course){
        case 1: disp_Calc();
        break;
        case 2: disp_LiAlg();
        break;
        case 3: disp_Phys();
        break;
        case 4: disp_CSP();
        break;
        default: std::cout << "Course does not exist";
    }
    return 0;
}

void main_display(){
    std::cout << "\t\t\t\tUW ECE 1A Grades Calculator" << std::endl;
    std::cout << "MATH 117 [1]" << std::endl;
    std::cout << "MATH 115 [2]" << std::endl;
    std::cout << "ECE 105  [3]" << std::endl;
    std::cout << "ECE 150  [4]" << std::endl;
    std::cout << "Choose a course: " << std::endl;
}

void disp_Calc(){
    system("cls");
    std::cout << "MATH 117" << std::endl;

    Calc calc_inst_1;
    input_loop(calc_inst_1, 10);
// ====================== ENTER GRADES HERE ======================
//    double w_asgn_mark_input[10] = {96, 93, 90, 99, 90, 93, 94, 98, 109, 99};
//    double o_asgn_mark_input[10] = {100, 100, 100, 95.7, 100, 93.3, 100, 98.4, 95, 100};
//     BE SURE TO ENTER THE VALUES FOR MIDTERM AND FINAL ON THE LINES BELOW
    double mid = 0;
    double fin = 0;
    std::cout << "Enter Midterm Grade (%)" << std::endl;
    std::cin >> mid;
    calc_inst_1.midterm_ = mid;

    std::cout << "Enter Final Grade (%)" << std::endl;
    std::cin >> fin;
    calc_inst_1.final_exam_ = fin;
    std::cout << "You MATH 117 Mark: " << calc_inst_1.calculate_mark() << "%" << std::endl;
}
void input_loop(Calc &calc_obj, std::size_t capacity){
    double w_asgn_mark_input = 0;
    std::cout << "Enter Written Assignment Grades (%)" << std::endl;

    for (std::size_t i{0}; i < 10; i++){
        std::cout << "WA " << i+1 << ": ";
        std::cin >> w_asgn_mark_input;
        calc_obj.written_assignments_[i] = w_asgn_mark_input;
    }
    std::cout << std::endl;

    std::cout << "Enter Sapling Assignment Grades (%)" << std::endl;

    double o_asgn_mark_input = 0;
    for (std::size_t i{0}; i < 10; i++){
        std::cout << "Sapling " << i+1 << ": ";
        std::cin >> o_asgn_mark_input;
        calc_obj.online_assignments_[i] = o_asgn_mark_input;
    }
    std::cout << std::endl;
}

void disp_LiAlg(){
    system("cls");
    std::cout << "MATH 115" << std::endl;
    LiAlg linalg_inst_1;

    input_loop(linalg_inst_1, 10);

// ====================== ENTER GRADES HERE ======================
//    double w_asgnments[10] = {100,89,94,80,88,94,100,88,94,91};
//    double o_asgnments[9] = {67.65, 92.3, 88.92, 100, 100, 92.3, 95.83, 100, 88.89};
//    double tts[3] = {75.8, 85.7, 84.8};

//    for (int i = 0; i < 10; i++){
//        linalg_inst_1.written_assignments_[i] = w_asgnments[i];
//        if (i < 9)
//            linalg_inst_1.online_assignments_[i] = o_asgnments[i];
//
//    }
//    for (int i = 0; i < 3; i++){
//        linalg_inst_1.term_tests_[i] = tts[i];
//    }
    std::cout << "You MATH 115 Mark: " << linalg_inst_1.calculate_mark_() << "%" << std::endl;

}
void input_loop(LiAlg &linalg_obj, std::size_t capacity){
    double w_asgn_mark_input = 0;
    std::cout << "Enter Written Assignment Grades (%)" << std::endl;
    for (std::size_t i{0}; i < 10; i++){
        std::cout << "WA " << i << ": ";
        std::cin >> w_asgn_mark_input;
        linalg_obj.written_assignments_[i] = w_asgn_mark_input;
    }
    std::cout << std::endl;

    std::cout << "Enter Mobius Assignment Grades (%)" << std::endl;
    double o_asgn_mark_input = 0;
    for (std::size_t i{0}; i < 9; i++){
        std::cout << "Mobius " << i+1 << ": ";
        std::cin >> o_asgn_mark_input;
        linalg_obj.online_assignments_[i] = o_asgn_mark_input;
    }

    std::cout << std::endl;

    std::cout << "Enter Term Test Grades (%)" << std::endl;
    double tt_input = 0;
    for (std::size_t i{0}; i < 3; i++){
        std::cout << "TT " << i+1 << ": ";
        std::cin >> tt_input;
        linalg_obj.term_tests_[i] = tt_input;
    }
}

void disp_Phys(){

system("cls");
    std::cout << "ECE 105 \n" << std::endl;
    std::cout << "The marking scheme and this class are so confusing that even I don't get it. Just go with what it says on Quest I guess.\nGood luck in 1B!\n\n";
//    Phys phys_inst_1;
//    double test[3] = {94, 94.58, 92};
//    double mob[11] = {0};
//    double q[10] = {0};
////    for (int i = 0; i < 11; i++){
////        if (i <10){
////            if (i==6){
////                q[i] = 0;
////            }
////            else{
////                q[i] = 100;
////            }
////        }
////        mob[i] = 100;
////    }
//
//    for (int i = 0; i < 11; i++){
//        if(i < 3){
//            phys_inst_1.term_tests_[i] = test[i];
//        }
//        if (i < 10){
//            phys_inst_1.quizzes_[i] = q[i];
//        }
//        phys_inst_1.mobius_[i] = 100;
//    }
//   // input_loop(phys_inst_1, 10);
//
//    std::cout << "Your ECE 105 Mark: " << phys_inst_1.calculate_mark_() << "%" << std::endl;
//}
//void input_loop(Phys &phys_obj, std::size_t capacity){
//    std::cout << "Enter Mobius Assignment Grades (%)" << std::endl;
//    double mobius_input = 0;
//    for (std::size_t i{0}; i < 11; i++){
//        std::cout << "Mobius " << i+1 << ": ";
//        std::cin >> mobius_input;
//        phys_obj.mobius_[i] = mobius_input;
//    }
//
//    std::cout << "Enter Quiz Grades (%)" << std::endl;
//    double quiz_input = 0;
//    for (std::size_t i{0}; i < 10; i++){
//        std::cout << "Quiz " << i+1 << ": ";
//        std::cin >> quiz_input;
//        phys_obj.quizzes_[i] = quiz_input;
//    }
//    char tt_weight_choice = 'o';
//
////    std::cout << "Would you like to enter your own weights for term tests or use the default 15%, 20%, 25%? [Y/N]" << std::endl;
////    std::cin >> tt_weight_choice;
////    if (tt_weight_choice == 'Y' || tt_weight_choice == 'y'){
////        double tt_weight_input = 0;
////        std::cout << "Enter Term Test Weights (as a decimal)" << std::endl;
////        for (std::size_t i{0}; i < 3; i++){
////            std::cout << "Term Test " << i+1 << " Weight: ";
////            std::cin >> tt_weight_input;
////            phys_obj.term_tests_weights_[i] = tt_weight_input;
////        }
////    }
//    std::cout << "Enter Term Test Grades (%)" << std::endl;
//    double test_input = 0;
//    for (std::size_t i{0}; i < 3; i++){
//        std::cout << "Term Test " << i+1 << ": ";
//        std::cin >> test_input;
//        phys_obj.term_tests_[i] = test_input;
//    }
//}
}
void disp_CSP(){
    system("cls");
    std::cout << "ECE 150" << std::endl;
    CSP csp_inst_1;
    input_loop(csp_inst_1, 5);

// ====================== ENTER GRADES HERE ======================
//    double quizzes[5] = {80, 120, 100, 50, 100};
//    double projects[4] = {100, 100, 98, 100};
//    for (int i = 0; i < 5; i++){
//        if(i < 4){
//            csp_inst_1.projects_[i] = projects[i];
//        }
//        csp_inst_1.quizzes_[i] = quizzes[i];
//    }
//
// BE SURE TO ENTER THE VALUES FOR MIDTERM AND FINAL ON THE LINES BELOW

    double mid = 0;
    double fin = 0;
    std::cout << "Enter Midterm Grade (%)" << std::endl;
    std::cin >> mid;
    csp_inst_1.midterm_ = mid;

    std::cout << "Enter Final Grade (%)" << std::endl;
    std::cin >> fin;
    csp_inst_1.final_exam_ = fin;

    csp_inst_1.midterm_= mid;
    csp_inst_1.final_exam_ = fin;

    std::cout << "Your ECE 150 Mark: " << csp_inst_1.calculate_mark_() << "%" << std::endl;
}
void input_loop(CSP &csp_obj, std::size_t capacity){
    std::cout << "Enter Quiz Grades (%)" << std::endl;
    double q_input = 0;
    for (std::size_t i{0}; i < 5; i++){
        std::cout << "Quiz " << i+1 << ": ";
        std::cin >> q_input;
        csp_obj.quizzes_[i] = q_input;
    }
    std::cout << "Enter Project Grades (%)" << std::endl;
    double proj_input = 0;
    for (std::size_t i{0}; i < 4; i++){
        std::cout << "Project " << i+1 << ": ";
        std::cin >> proj_input;
        csp_obj.projects_[i] = proj_input;
    }
}
