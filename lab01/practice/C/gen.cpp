#include<cstdio>
#include<cstdlib>
#include<random>
#include<iostream>
#include<algorithm>
using namespace std;

/*********************************
 * Testdata generating utilities *
 * By bigelephant29              *
 *********************************/

const int PROBLEM_NO = 17020101;
const int TESTDATA_COUNT = 10;

mt19937 rng(0x5EED);
int randint(int lb, int ub) {
    /* randomly generate number in [lb, ub] */
    return uniform_int_distribution<int>(lb, ub)(rng);
}

string intToStr(int num) {
    string ret = "";
    while(num) {
        ret += num % 10 + '0';
        num /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string getFileName(int prob_no, int data_no, bool sample, const string& suffix = "") {
    string ret = "testdata/";
    if(sample) {
        ret += intToStr(prob_no) + ".sample";
        ret += data_no - 1 + 'a';
        ret += suffix;
    } else {
        ret += intToStr(prob_no) + ".";
        ret += intToStr(data_no) + suffix;
    }
    return ret;
}

string getFileInName(int prob_no, int data_no, bool sample) {
    return getFileName(prob_no, data_no, sample, ".in");
}

string getFileOutName(int prob_no, int data_no, bool sample) {
    return getFileName(prob_no, data_no, sample, ".out");
}

void genOut(const string& in, const string& out) {
    char cmd[256];
    sprintf(cmd, "./solve < %s > %s", in.c_str(), out.c_str());
    system(cmd);
}

void writeFileLog(const string& file_name) {
    fprintf(stderr, "Generating [%s] ...", file_name.c_str());
}

void writeFinished() {
    fprintf(stderr, "Finished.\n");
}


int main() {
    
    FILE *fp;
    string fn_in, fn_out;
    
    // sample a
    writeFileLog( getFileName(PROBLEM_NO, 1, true) );
    fn_in = getFileInName(PROBLEM_NO, 1, true);
    fn_out = getFileOutName(PROBLEM_NO, 1, true);
    fp = fopen(fn_in.c_str(), "w");
    fprintf(fp, "1 2\n");
    fclose(fp);
    genOut(fn_in, fn_out);
    writeFinished();

    // sample b
    writeFileLog( getFileName(PROBLEM_NO, 2, true) );
    fn_in = getFileInName(PROBLEM_NO, 2, true);
    fn_out = getFileOutName(PROBLEM_NO, 2, true);
    fp = fopen(fn_in.c_str(), "w");
    fprintf(fp, "12 18\n");
    fclose(fp);
    genOut(fn_in, fn_out);
    writeFinished();

    // sample c
    writeFileLog( getFileName(PROBLEM_NO, 3, true) );
    fn_in = getFileInName(PROBLEM_NO, 3, true);
    fn_out = getFileOutName(PROBLEM_NO, 3, true);
    fp = fopen(fn_in.c_str(), "w");
    fprintf(fp, "12 18\n");
    fclose(fp);
    genOut(fn_in, fn_out);
    writeFinished();
    
    int my_bound = 1;
    const int my_max = 1000000000;
    for(int i = 1 ; i <= TESTDATA_COUNT ; i++) {
        writeFileLog( getFileName(PROBLEM_NO, i, false) );
        fn_in = getFileInName(PROBLEM_NO, i, false);
        fn_out = getFileOutName(PROBLEM_NO, i, false);
        fp = fopen(fn_in.c_str(), "w");
        if(i == 1) {
            fprintf(fp, "1000000000 214748\n");
        } else {
            my_bound *= 10;
            int pick_num = randint(1, my_bound);
            fprintf(fp, "%d %d\n", pick_num * randint(1, my_max / pick_num),
                                   pick_num * randint(1, my_max / pick_num));
        }
        fclose(fp);
        genOut(fn_in, fn_out);
        writeFinished();
    }

    return 0;
}
